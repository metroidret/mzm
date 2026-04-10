from romExtractor import *
from gfxExtractor import *
from lz import *


ZM_PATH = "mzm_us_baserom.gba"


if __name__ == "__main__":
    error_qty = 0

    nes_metroid_data = get_nes_metroid_data(ZM_PATH)

    # TEST NESTROID ROM RECOMPRESS
    nesrom_decomp_bytes, nesrom_comp_bytes = extract_rom(nes_metroid_data)
    nesrom_recomp_bytes = comp_lz_nesrom(nesrom_decomp_bytes)
    try:
        for i, (bc, br) in enumerate(zip(nesrom_comp_bytes, nesrom_recomp_bytes)):
            if bc == br:
                continue
            raise Exception(f"nesrom byte 0x{i:X}: {bc:02X} != {br:02X}")
        print(f"nesrom success")
    except Exception as e:
        print(e)
        error_qty += 1

    # TEST NESTROID GFX RECOMPRESS
    gfx_entry_decomp_bytes_list, gfx_entry_comp_bytes_list = extract_gfx(nes_metroid_data)
    
    for name, decomp_bytes, comp_bytes in zip(GFX_ENTRY_NAMES, gfx_entry_decomp_bytes_list, gfx_entry_comp_bytes_list):
        recomp_bytes = comp_lz_bios(decomp_bytes)
        try:
            for i, (bc, br) in enumerate(zip(comp_bytes, recomp_bytes)):
                if bc == br:
                    continue
                raise Exception(f"gfx_entry {name} byte 0x{i:X}: {bc:02X} != {br:02X}")
            print(f"gfx_entry {name} success")
        except Exception as e:
            print(e)
            error_qty += 1
    
    print(f"test complete, {error_qty} error(s)")
