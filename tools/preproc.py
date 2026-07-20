"""
Takes in a C file and charmap file as input.
Converts INCTEXT and SHIFT_JIS macro calls to immediate array inits.
Outputs processed C file to stdout.
"""

import argparse
import re
from typing import Optional

REGEX_INCTEXT = re.compile(r"INCTEXT\(\"(.+?)\"\)")
REGEX_SHIFT_JIS = re.compile(r"SHIFT_JIS\(\"(.+?)\"\)")

SHIFT_JIS_FULL_TO_HALF_DICT = {
    "。": "｡",
    "「": "｢",
    "、": "､",
    "・": "･",
    "ヲ": "ｦ",
    "ァ": "ｧ",
    "ィ": "ｨ",
    "ゥ": "ｩ",
    "ェ": "ｪ",
    "ォ": "ｫ",
    "ャ": "ｬ",
    "ュ": "ｭ",
    "ョ": "ｮ",
    "ッ": "ｯ",
    "ー": "ｰ",
    "ア": "ｱ",
    "イ": "ｲ",
    "ウ": "ｳ",
    "エ": "ｴ",
    "オ": "ｵ",
    "カ": "ｶ",
    "キ": "ｷ",
    "ク": "ｸ",
    "ケ": "ｹ",
    "コ": "ｺ",
    "サ": "ｻ",
    "シ": "ｼ",
    "ス": "ｽ",
    "セ": "ｾ",
    "ソ": "ｿ",
    "タ": "ﾀ",
    "チ": "ﾁ",
    "ツ": "ﾂ",
    "テ": "ﾃ",
    "ト": "ﾄ",
    "ナ": "ﾅ",
    "ニ": "ﾆ",
    "ヌ": "ﾇ",
    "ネ": "ﾈ",
    "ノ": "ﾉ",
    "ハ": "ﾊ",
    "ヒ": "ﾋ",
    "フ": "ﾌ",
    "ヘ": "ﾍ",
    "ホ": "ﾎ",
    "マ": "ﾏ",
    "ミ": "ﾐ",
    "ム": "ﾑ",
    "メ": "ﾒ",
    "モ": "ﾓ",
    "ヤ": "ﾔ",
    "ユ": "ﾕ",
    "ヨ": "ﾖ",
    "ラ": "ﾗ",
    "リ": "ﾘ",
    "ル": "ﾙ",
    "レ": "ﾚ",
    "ロ": "ﾛ",
    "ワ": "ﾜ",
    "ン": "ﾝ",
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
    def __init__(self, char_dict: dict[str, list[int]], named_char_dict: dict[str, list[int]]):
        self.char_dict = char_dict
        self.named_char_dict = named_char_dict

    def parse_named_char_value(self, text: str) -> Optional[list[int]]:
        m = re.search(r"\((\d+)\)", text)
        if not m:
            return None
        name = text[:m.start()]
        char_vals = self.named_char_dict.get(name)
        if char_vals is None:
            raise KeyError(f"Invalid named character: '{name}'")
        if len(char_vals) > 1:
            raise ValueError(f"Character '{name}' cannot take a value")
        return [char_vals[0] + int(m.group(1))]

    def convert_string(self, text: str) -> list[int]:
        values: list[int] = []
        escaped = False
        named_char: Optional[list[str]] = None

        for c in text:
            if not escaped:
                if c == "\\":
                    if named_char is not None:
                        raise ValueError(f"Escaped character within named character: '{text}'")
                    escaped = True
                    continue
                if named_char is None:
                    # Check for start of named character
                    if c == "{":
                        named_char = []
                        continue
                else:
                    # Check for end of named character
                    if c == "}":
                        name = "".join(named_char)
                        # Check if named character with assignable value
                        char_vals = self.parse_named_char_value(name)
                        if char_vals is None:
                            # Check if normal named character
                            char_vals = self.named_char_dict.get(name)
                            if char_vals is None:
                                raise KeyError(f"Invalid named character: '{name}'")
                        values += char_vals
                        named_char = None
                    else:
                        # Still parsing named character
                        named_char.append(c)
                    continue
            else:
                escape_seq = "\\" + c
                char_vals = self.char_dict.get(escape_seq)
                if char_vals is None:
                    raise KeyError(f"Unrecognized escape sequence: '{escape_seq}'")
                values += char_vals
                escaped = False
                continue
            
            values += self.char_dict[c]

        if named_char is not None:
            raise ValueError(f"Unclosed named character: '{text}'")
        if escaped:
            raise ValueError(f"Trailing backslash: '{text}'")

        return values
    
    @classmethod
    def parse_charmap(cls, charmap_file: str) -> "CharMap":
        char_dict: dict[str, list[int]] = {}
        named_char_dict: dict[str, list[int]] = {}
        with open(charmap_file, "r") as f:
            for line in f:
                line = line.split("@")[0].strip()
                if line == "":
                    continue
                left, right = line.rsplit("=", 1)
                char_symbol = left.strip()
                char_ids = [int(v, 16) for v in right.strip().split(" ")]
                if len(char_symbol) > 1 and char_symbol.startswith("'") and char_symbol.endswith("'"):
                    # Normal character
                    char_symbol = char_symbol[1:-1]
                    if char_symbol == "\\'":
                        char_symbol = "'"
                    char_dict[char_symbol] = char_ids
                else:
                    # Named character
                    named_char_dict[char_symbol] = char_ids
        return CharMap(char_dict, named_char_dict)


def convert_inctext(ic: str, charmap: CharMap) -> str:
    """
    Converts macros with the following format into an array of 16-bit integers:
        INCTEXT("some text")
    """
    def convert_text(m: re.Match[str]) -> str:
        text = m.group(1)
        text_vals = charmap.convert_string(text)
        text_strs = [f"0x{v:04X}" for v in text_vals]
        return "{" + ",".join(text_strs) + ",CHAR_TERMINATOR}"

    return REGEX_INCTEXT.sub(convert_text, ic)


def convert_shift_jis(content: str) -> str:
    """
    Converts macros with the following format into an array of 8-bit integers:
        SHIFT_JIS("some text")
    """
    def convert_text(m: re.Match[str]) -> str:
        text = m.group(1)
        text_half = "".join(SHIFT_JIS_FULL_TO_HALF_DICT.get(c, c) for c in text)
        text_vals = text_half.encode("shift_jis")
        text_strs = [f"0x{b:02X}" for b in text_vals]
        return "{" + ",".join(text_strs) + "}"

    return REGEX_SHIFT_JIS.sub(convert_text, content)


def preproc(in_file: str, charmap_file: str) -> None:
    with open(in_file, "r") as f:
        file_content = f.read()

    if REGEX_INCTEXT.search(file_content):
        charmap = CharMap.parse_charmap(charmap_file)
        file_content = convert_inctext(file_content, charmap)

    file_content = convert_shift_jis(file_content)
    
    print(file_content, end="")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("in_file", help="Input C file")
    parser.add_argument("charmap_file", help="Input charmap file")
    args = parser.parse_args()

    preproc(args.in_file, args.charmap_file)
