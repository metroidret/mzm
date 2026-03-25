import argparse
import re
import bisect

"""
Takes in a C file and charmap file as input.
Converts INCBIN, INCTEXT and SHIFT_JIS macro calls to immediate array inits.
Outputs processed C file to stdout.
"""

SHIFT_JIS_FULL_TO_HALF_DICT = {
    '。': '｡',
    '「': '｢',
    '、': '､',
    '・': '･',
    'ヲ': 'ｦ',
    'ァ': 'ｧ',
    'ィ': 'ｨ',
    'ゥ': 'ｩ',
    'ェ': 'ｪ',
    'ォ': 'ｫ',
    'ャ': 'ｬ',
    'ュ': 'ｭ',
    'ョ': 'ｮ',
    'ッ': 'ｯ',
    'ー': 'ｰ',
    'ア': 'ｱ',
    'イ': 'ｲ',
    'ウ': 'ｳ',
    'エ': 'ｴ',
    'オ': 'ｵ',
    'カ': 'ｶ',
    'キ': 'ｷ',
    'ク': 'ｸ',
    'ケ': 'ｹ',
    'コ': 'ｺ',
    'サ': 'ｻ',
    'シ': 'ｼ',
    'ス': 'ｽ',
    'セ': 'ｾ',
    'ソ': 'ｿ',
    'タ': 'ﾀ',
    'チ': 'ﾁ',
    'ツ': 'ﾂ',
    'テ': 'ﾃ',
    'ト': 'ﾄ',
    'ナ': 'ﾅ',
    'ニ': 'ﾆ',
    'ヌ': 'ﾇ',
    'ネ': 'ﾈ',
    'ノ': 'ﾉ',
    'ハ': 'ﾊ',
    'ヒ': 'ﾋ',
    'フ': 'ﾌ',
    'ヘ': 'ﾍ',
    'ホ': 'ﾎ',
    'マ': 'ﾏ',
    'ミ': 'ﾐ',
    'ム': 'ﾑ',
    'メ': 'ﾒ',
    'モ': 'ﾓ',
    'ヤ': 'ﾔ',
    'ユ': 'ﾕ',
    'ヨ': 'ﾖ',
    'ラ': 'ﾗ',
    'リ': 'ﾘ',
    'ル': 'ﾙ',
    'レ': 'ﾚ',
    'ロ': 'ﾛ',
    'ワ': 'ﾜ',
    'ン': 'ﾝ',
    # Katakana with dakuten and handakuten
    "ガ": "ｶﾞ",
    "ギ": "ｷﾞ",
    "グ": "ｸﾞ",
    "ゲ": "ｹﾞ",
    "ゴ": "ｺﾞ",
    "ザ": "ｻﾞ",
    "ジ": "ｼﾞ",
    "ズ": "ｽﾞ",
    "ゼ": "ｾﾞ",
    "ゾ": "ｿﾞ",
    "ダ": "ﾀﾞ",
    "ヂ": "ﾁﾞ",
    "ヅ": "ﾂﾞ",
    "デ": "ﾃﾞ",
    "ド": "ﾄﾞ",
    "バ": "ﾊﾞ",
    "ビ": "ﾋﾞ",
    "ブ": "ﾌﾞ",
    "ベ": "ﾍﾞ",
    "ボ": "ﾎﾞ",
    "パ": "ﾊﾟ",
    "ピ": "ﾋﾟ",
    "プ": "ﾌﾟ",
    "ペ": "ﾍﾟ",
    "ポ": "ﾎﾟ",
}


class CharMap:
    def __init__(self, charmapfile_content):
        self.symbol_dict = {}
        self.symbol_dict_keys = []
        for line in charmapfile_content.split("\n"):
            line = line.split("@")[0].strip()
            if line == "":
                continue
            line = line.split("=")
            charmap_ids = ["0x"+s for s in line[-1].strip().split(" ")]
            charmap_symbol = "=".join(line[:-1]).strip()
            if len(charmap_symbol) > 1 and charmap_symbol.startswith("'") and charmap_symbol.endswith("'"):
                charmap_symbol = charmap_symbol[1:-1]
                if charmap_symbol == "\\'":
                    charmap_symbol = "'"
            else:
                charmap_symbol = "{" + charmap_symbol + "}"
            self.symbol_dict[charmap_symbol] = charmap_ids
            bisect.insort(self.symbol_dict_keys, charmap_symbol)
    
    def get_entry(self, text):
        b = bisect.bisect(self.symbol_dict_keys, text)
        key = self.symbol_dict_keys[b-1]
        if not text.startswith(key):
            key = self.symbol_dict_keys[b]
            if text[0] == "{" and text.startswith(key[:-1] + "("):
                param = int(text[len(key):].split(")}", 1)[0])
                return ([f"0x{int(v[2:], 16) + param:04X}" for v in self.symbol_dict[key]], text.find(")}")+2)
            raise IndexError("cannot find symbol in charmap for text " + text)
        return (self.symbol_dict[key], len(key))
    
    def convert_string(self, text):
        out = []
        while len(text) > 0:
            charmap_ids, symbol_length = self.get_entry(text)
            out += charmap_ids
            text = text[symbol_length:]
        return out


"""
"INCBIN_S8", "INCBIN_U8", "_INCBIN_S8", "_INCBIN_U8", 
"INCBIN_S16", "INCBIN_U16", "_INCBIN_S16", "_INCBIN_U16", 
"INCBIN_S32", "INCBIN_U32", "_INCBIN_S32", "_INCBIN_U32"

INCBIN = curly brackets, _INCBIN = no curly brackets
U = unsigned (signed is never used, so not implemented)
8, 16 or 32 bits integer
"""
def convert_incbin(ic):
    REGEX_INCBIN = re.compile(r'_?INCBIN_U(8|16|32)+\(\".+\"\)')
    out = ""
    while True:
        m = REGEX_INCBIN.search(ic)
        if m is None:
            break
        mstr = m[0]
        is_brackets = mstr[0] != '_'
        size = int(m[1]) // 8
        
        incbinfile = mstr.removeprefix("_")[10+len(m[1]):-2]
        
        try:
            with open(incbinfile, "rb") as f:
                incbinfile_bytes = f.read()
        except FileNotFoundError:
            incbinfile_bytes = bytes()
        filesize = len(incbinfile_bytes)
        if filesize % size != 0:
            raise Exception(f"Size {size} doesn't evenly divide file size {filesize}.")
        
        incbinfile_values = []
        for i in range(0, len(incbinfile_bytes), size):
            value = 0
            for j in range(size):
                value += incbinfile_bytes[i+j] << (j*8)
            incbinfile_values.append(str(value) + "u")
        incbin_converted = ",".join(incbinfile_values)
        if is_brackets:
            incbin_converted = "{" + incbin_converted + "}"
        
        out += ic[:m.start()] + incbin_converted
        ic = ic[m.end():]
    return out + ic


"""
"INCTEXT"

curly brackets
text
"""
def convert_inctext(ic, charmap):
    REGEX_INCTEXT = re.compile(r'INCTEXT\(\".+\"\)')
    out = ""
    while True:
        m = REGEX_INCTEXT.search(ic)
        if m is None:
            break
        mstr = m[0]
        
        inctext = mstr[9:-2]
        
        inctext_ids = charmap.convert_string(inctext)
        inctext_converted = "{" + ",".join(inctext_ids) + ",CHAR_TERMINATOR}"
        
        out += ic[:m.start()] + inctext_converted
        ic = ic[m.end():]
    return out + ic


"""
"SHIFT_JIS"

curly brackets
text
"""
def convert_shift_jis(ic):
    REGEX_SHIFT_JIS = re.compile(r'SHIFT_JIS\(\".+\"\)')
    out = ""
    while True:
        m = REGEX_SHIFT_JIS.search(ic)
        if m is None:
            break
        mstr = m[0]
        
        inctext = mstr[11:-2]
        
        # turn full width combined characters into half width decomposed characters
        inctext_half = ""
        for c in inctext:
            if c in SHIFT_JIS_FULL_TO_HALF_DICT:
                c = SHIFT_JIS_FULL_TO_HALF_DICT[c]
            inctext_half += c
        
        inctext_ids = [f"0x{b:04X}" for b in inctext_half.encode('shift_jis')]
        inctext_converted = "{" + ",".join(inctext_ids) + "}"
        
        out += ic[:m.start()] + inctext_converted
        ic = ic[m.end():]
    return out + ic


def preproc(infile, charmapfile):
    with open(infile, "r") as f:
        infile_content = f.read()
    
    with open(charmapfile, "r") as f:
        charmapfile_content = f.read()
    charmap = CharMap(charmapfile_content)
    
    infile_content = convert_incbin(infile_content)
    infile_content = convert_inctext(infile_content, charmap)
    infile_content = convert_shift_jis(infile_content)
    
    print(infile_content, end="")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('infile', help='Input C file')
    ap.add_argument('charmapfile', help='Input charmap file')
    args = ap.parse_args()

    preproc(args.infile, args.charmapfile)


if __name__ == "__main__":
    main()
