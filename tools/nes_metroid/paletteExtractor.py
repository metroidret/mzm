import argparse
from pathlib import Path

from lz import *


# decompress 087F7558-087F7731 to 0600B800-0600B9FF


NES_METROID_BIN_ADDR = 0x7D80B2
NES_METROID_BIN_SIZE = 0x1F682
NESTROID_PALETTE_ADDR = 0x7F7558


def get_nes_metroid_data(zm_path):
    with open(zm_path, "rb") as f:
        f.seek(NES_METROID_BIN_ADDR)
        nes_metroid_data = f.read(NES_METROID_BIN_SIZE)
    return nes_metroid_data


def extract_palette(nes_metroid_data):
    nestroid_palette_addr_rel = NESTROID_PALETTE_ADDR - NES_METROID_BIN_ADDR
    
    decomp_bytes, comp_size = decomp_lz_bios(nes_metroid_data, nestroid_palette_addr_rel)
    comp_bytes = nes_metroid_data[nestroid_palette_addr_rel:nestroid_palette_addr_rel+comp_size]
    
    return decomp_bytes, comp_bytes


def save_palette(output_path, comp_bytes):
    with open(output_path, "wb") as f:
        f.write(comp_bytes)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("zm_path", type=str, help="Path to a Zero Mission ROM")
    parser.add_argument("output_path", type=str, help="Folder where output LZ-compressed palette should be written")
    
    args = parser.parse_args()
    
    nes_metroid_data = get_nes_metroid_data(args.zm_path)
    _, comp_bytes = extract_palette(nes_metroid_data)
    save_palette(args.output_path, comp_bytes)
    
