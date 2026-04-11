import argparse
from pathlib import Path

from lz import *


NES_METROID_BIN_ADDR = 0x7D80B2
NES_METROID_BIN_SIZE = 0x1F682
NESTROID_ROM_ADDR = 0x7DCF60
"""Address of the LZ compressed nestroid ROM data."""
# Comp end: 0x7F3397
# Comp size: 0x16437
NESTROID_ROM_DECOMP_SIZE = 0x20000
"""Decompressed size of the nestroid ROM."""
NESTROID_ROM_INES_HEADER = bytes([int(b, 16) for b in "4E 45 53 1A 08 00 11 00 00 00 4E 49 20 31 2E 33".split()])


def get_nes_metroid_data(zm_path):
    with open(zm_path, "rb") as f:
        f.seek(NES_METROID_BIN_ADDR)
        nes_metroid_data = f.read(NES_METROID_BIN_SIZE)
    return nes_metroid_data


def extract_rom(nes_metroid_data):
    nestroid_rom_addr_rel = NESTROID_ROM_ADDR - NES_METROID_BIN_ADDR
    
    decomp_bytes, comp_size = decomp_lz_custom(nes_metroid_data, nestroid_rom_addr_rel, NESTROID_ROM_DECOMP_SIZE)
    comp_bytes = nes_metroid_data[nestroid_rom_addr_rel:nestroid_rom_addr_rel+comp_size]
    
    return decomp_bytes, comp_bytes


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("zm_path", type=str, help="Path to a Zero Mission ROM")
    parser.add_argument("output_path", type=str, help="Folder where output ROM should be written")
    
    args = parser.parse_args()
    
    nes_metroid_data = get_nes_metroid_data(args.zm_path)
    decomp_bytes, comp_bytes = extract_rom(nes_metroid_data)
    decomp_bytes_headered = NESTROID_ROM_INES_HEADER + decomp_bytes
    
    output_path_obj = Path(args.output_path)
    output_path_obj.mkdir(parents=True, exist_ok=True)
    with open(Path(args.output_path, "M1_NES_MZMUS.nes"), "wb") as f:
        f.write(decomp_bytes_headered)
    
