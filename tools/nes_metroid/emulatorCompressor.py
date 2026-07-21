import argparse
from pathlib import Path

from lz import *


# decompress 087D8360-087DCDAF to 06000000-06008524
# decompress 087DCDB0-087DCEE0 to nothing


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("emulator_path", type=str, help="Path to emulator binary")
    
    args = parser.parse_args()
    emulator_path = args.emulator_path
    
    with open(emulator_path, "rb") as f:
        decomp_bytes = f.read()
    
    comp_bytes = comp_lz_custom(decomp_bytes)
    
    with open(emulator_path + ".lz", "wb") as f:
        f.write(comp_bytes)
    
