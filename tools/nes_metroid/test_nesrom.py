from pathlib import Path

from romExtractor import *
from gfxExtractor import *
from lz import *


ZM_PATH = "mzm_us_baserom.gba"


def decomp_lz_nesromtest(src: bytes, idx: int, decomp_size: int) -> Tuple[bytes, int]:
    output = bytearray(decomp_size)

    start = idx
    dst = 0

    str_out = []

    while (True):
        cflag = src[idx]
        idx += 1

        for _ in range(8):
            if (cflag & 0x80) != 0:
                # Uncompressed
                output[dst] = src[idx]
                str_out.append(["u", [f"{output[dst]:02X}"]])
                idx += 1
                dst += 1
            else:
                # Compressed
                amount_to_copy = (src[idx] >> 4)
                window = ((src[idx] & 0xF) << 8) + src[idx + 1] + 1
                idx += 2
                if amount_to_copy == 0:
                    amount_to_copy = 0x10 + src[idx]
                    idx += 1
                amount_to_copy += MIN_MATCH_SIZE

                str_out.append([f"c({amount_to_copy},-0x{window:X})", [f"{b:02X}" for b in output[dst - window:dst - window + amount_to_copy]]])
                for _ in range(amount_to_copy):
                    output[dst] = output[dst - window]
                    dst += 1

            if dst >= decomp_size:
                if dst > decomp_size:
                    raise ValueError("Too many bytes copied at end")
                comp_size = idx - start
                return bytes(output), comp_size, str_out
            cflag <<= 1


def comp_lz_nesromtest(decomp_bytes: bytes) -> bytes:
    # Assumes input stream starts at 0
    decomp_size = len(decomp_bytes)
    idx = 0
    triplets: dict[int, list[int]] = {}

    output = bytearray()

    str_out = []

    while idx < decomp_size:
        # Get index of new compression flag
        flag = len(output)
        output.append(0)

        for i in range(8):
            # Find longest match at current position
            _match = find_longest_match_nesrom(decomp_bytes, idx, triplets)
            if _match is not None:
                # Compressed
                match_len, match_idx = _match
                match_offset = idx - match_idx - MIN_WINDOW_SIZE
                if match_len - MIN_MATCH_SIZE < 0x10:
                    output.append(((match_len - MIN_MATCH_SIZE) << 4) | (match_offset >> 8))
                    output.append(match_offset & 0xFF)
                else:
                    output.append(match_offset >> 8)
                    output.append(match_offset & 0xFF)
                    output.append(match_len - 0x10 - MIN_MATCH_SIZE)
                str_out.append([f"c({match_len},-0x{match_offset + MIN_WINDOW_SIZE:X})", [f"{b:02X}" for b in decomp_bytes[idx:idx + match_len]]])
                idx += match_len
            else:
                # Uncompressed
                output.append(decomp_bytes[idx])
                str_out.append(["u", [f"{decomp_bytes[idx]:02X}"]])
                idx += 1
                output[flag] |= 0x80 >> i

            # Check if at end
            if idx >= decomp_size:
                return bytes(output), str_out
    
    raise Exception("LZ77 compression error")


if __name__ == "__main__":
    nes_metroid_data = get_nes_metroid_data(ZM_PATH)

    nestroid_rom_addr_rel = NESTROID_ROM_ADDR - NES_METROID_BIN_ADDR
    
    decomp_bytes, comp_size, decomp_str = decomp_lz_nesromtest(nes_metroid_data, nestroid_rom_addr_rel, NESTROID_ROM_DECOMP_SIZE)
    comp_bytes = nes_metroid_data[nestroid_rom_addr_rel:nestroid_rom_addr_rel+comp_size]

    recomp_bytes, recomp_str = comp_lz_nesromtest(decomp_bytes)

    byte_qty = 0
    for i, (cd, cr) in enumerate(zip(decomp_str, recomp_str)):
        if cd[0] != cr[0]:
            raise Exception(f"command {i} (off 0x{byte_qty:X}): \ndecomp: {cd}\nrecomp: {cr}")
        byte_qty += len(cd[1])
    print("ok")
