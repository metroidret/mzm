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


def find_longest_match_nesromtest(decomp_bytes: bytes, i: int, triplets: dict[int, list[int]]) -> Optional[tuple[int, int]]:
    decomp_size = len(decomp_bytes)
    if i > decomp_size - 3:
        return None

    # Get triplet at current position
    triplet = decomp_bytes[i] | (decomp_bytes[i + 1] << 8) | (decomp_bytes[i + 2] << 16)

    # Check if triplet has no match
    indexes = triplets.get(triplet)
    if indexes is None:
        return None

    window_start = max(i - MAX_WINDOW_SIZE, 0)
    max_size = min(MAX_MATCH_SIZE, decomp_size - i)
    longest_len = 0
    longest_idx = -1

    j = 0
    # Try each index to find the longest match
    while j < len(indexes):
        idx = indexes[j]
        # remove if past window
        if idx < window_start:
            indexes.pop(j)
            # dont inc j
            continue

        # Find length of match
        match_len = 3
        while match_len < max_size:
            if decomp_bytes[idx + match_len] != decomp_bytes[i + match_len]:
                break
            match_len += 1
        
        # Update longest match
        if match_len > longest_len:
            longest_len = match_len
            longest_idx = idx

            # Stop looking if max size
            if longest_len == max_size:
                break
        
        j += 1

    if longest_len >= 3:
        return (longest_len, longest_idx)

    return None

def commit_match_to_triplets(i: int, triplets: dict[int, list[int]], _match, decomp_bytes):
    decomp_size = len(decomp_bytes)
    if i > decomp_size - 3:
        return
    
    # Get triplet at current position
    triplet = decomp_bytes[i] | (decomp_bytes[i + 1] << 8) | (decomp_bytes[i + 2] << 16)

    # Check if triplet has no match
    indexes = triplets.get(triplet)
    if indexes is None:
        triplets[triplet] = [i]
    else:
        indexes.append(i)

    if _match is not None:
        longest_len, longest_idx = _match
        for j in range(i+1, min(i+longest_len, decomp_size-3+1)):
            # Get triplet at current position
            triplet = decomp_bytes[j] | (decomp_bytes[j + 1] << 8) | (decomp_bytes[j + 2] << 16)

            # Check if triplet has no match
            indexes = triplets.get(triplet)
            if indexes is None:
                triplets[triplet] = [j]
            else:
                indexes.append(j)


def comp_lz_nesromtest(decomp_bytes: bytes, decomp_str) -> bytes:
    # Assumes input stream starts at 0
    decomp_size = len(decomp_bytes)
    idx = 0
    triplets: dict[int, list[int]] = {}

    output = bytearray()

    match_next_optimise = True

    str_out = []
    modlist_u = []

    while idx < decomp_size:
        # Get index of new compression flag
        flag = len(output)
        output.append(0)

        for i in range(8):
            # Find longest match at current position
            _match = find_longest_match_nesromtest(decomp_bytes, idx, triplets)

            if len(str_out) == 572:
                print(match_next_optimise)
                print(_match)

            if _match is not None and match_next_optimise:
                match_len, match_idx = _match

                # triplets assume uncompressed for match_next
                commit_match_to_triplets(idx, triplets, None, decomp_bytes)
                
                _match_next = find_longest_match_nesromtest(decomp_bytes, idx+1, triplets)

                if len(str_out) == 572:
                    print(_match_next)

                if _match_next is not None:
                    match_next_len, match_next_idx = _match_next
                    # for match_next to be better than match, its length must be better 
                    # even while compensating for the uncompressed byte instruction before it
                    if match_next_len - (1 + 1/8) > match_len:
                        _match = None
                        match_next_optimise = False

            # debug hardcoding
            """try:
                if decomp_str[len(str_out)][0].startswith("u") and _match is not None:
                    modlist_u.append([len(str_out), idx, _match])
                    _match = None
            except IndexError:
                pass"""

            commit_match_to_triplets(idx, triplets, _match, decomp_bytes)

            if _match is not None:
                # Compressed
                match_next_optimise = True
                match_len, match_idx = _match
                match_offset = idx - match_idx - MIN_WINDOW_SIZE
                str_out.append([f"c({match_len},-0x{match_offset + MIN_WINDOW_SIZE:X})", [f"{b:02X}" for b in decomp_bytes[idx:idx + match_len]]])
                if match_len - MIN_MATCH_SIZE < 0x10:
                    output.append(((match_len - MIN_MATCH_SIZE) << 4) | (match_offset >> 8))
                    output.append(match_offset & 0xFF)
                else:
                    if (match_offset >> 8) < 0 or (match_offset >> 8) >= 256:
                        print(f"0x{idx:X}")
                        print(str_out[len(str_out)-1])
                    output.append(match_offset >> 8)
                    output.append(match_offset & 0xFF)
                    output.append(match_len - 0x10 - MIN_MATCH_SIZE)
                idx += match_len
            else:
                # Uncompressed
                output.append(decomp_bytes[idx])
                str_out.append(["u", [f"{decomp_bytes[idx]:02X}"]])
                idx += 1
                output[flag] |= 0x80 >> i

            # Check if at end
            if idx >= decomp_size:
                return bytes(output), str_out, modlist_u
    
    raise Exception("LZ77 compression error")


if __name__ == "__main__":
    nes_metroid_data = get_nes_metroid_data(ZM_PATH)

    nestroid_rom_addr_rel = NESTROID_ROM_ADDR - NES_METROID_BIN_ADDR
    
    decomp_bytes, comp_size, decomp_str = decomp_lz_nesromtest(nes_metroid_data, nestroid_rom_addr_rel, NESTROID_ROM_DECOMP_SIZE)
    comp_bytes = nes_metroid_data[nestroid_rom_addr_rel:nestroid_rom_addr_rel+comp_size]

    recomp_bytes, recomp_str, modlist_u = comp_lz_nesromtest(decomp_bytes, decomp_str)

    byte_qty = 0
    for i, (cd, cr) in enumerate(zip(decomp_str, recomp_str)):
        if cd[0] != cr[0]:
            raise Exception(f"command {i} (off 0x{byte_qty:X}): \ndecomp: {cd}\nrecomp: {cr}")
        byte_qty += len(cd[1])
    print("ok")
    for i, idx, _match_bad in modlist_u:
        match_bad_len, match_bad_idx = _match_bad
        match_bad_offset = idx - match_bad_idx - MIN_WINDOW_SIZE
        match_bad_str = f"c({match_bad_len},-0x{match_bad_offset + MIN_WINDOW_SIZE:X})"
        matches_good_str = decomp_str[i][0] + " " + decomp_str[i+1][0]
        bytesstr = " ".join([f"{b:02X}" for b in decomp_bytes[max(idx, 0):min(idx+4, len(decomp_bytes))]])
        print(f"cmd {i} (0x{idx:X}): repl {match_bad_str} by {matches_good_str}")

