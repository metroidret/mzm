import argparse
from typing import BinaryIO


DIMS = [
    "OAM_DIMS_8x8",
    "OAM_DIMS_16x16",
    "OAM_DIMS_32x32",
    "OAM_DIMS_64x64",

    "OAM_DIMS_16x8",
    "OAM_DIMS_32x8",
    "OAM_DIMS_32x16",
    "OAM_DIMS_64x32",

    "OAM_DIMS_8x16",
    "OAM_DIMS_8x32",
    "OAM_DIMS_16x32",
    "OAM_DIMS_32x64",
]

FLIPS = [
    "OAM_NO_FLIP",
    "OAM_X_FLIP",
    "OAM_Y_FLIP",
    "OAM_XY_FLIP"
]

MODES = [
    "OAM_OBJ_MODE_SEMI_TRANSPARENT",
    "OAM_OBJ_MODE_WINDOW"
]


def dump_oam_frame(rom: BinaryIO, addr: int, name: str = None) -> None:
    INDENT = " " * 4
    if name is None:
        name = f"sOamFrame_{addr:x}"
    rom.seek(addr)
    # Get count
    count_val = _read_16(rom)
    count = count_val & 0xFFF
    lines = [f"const u16 {name}[OAM_DATA_SIZE({count})] = {{"]
    lines.append(INDENT + _count_str(count_val) + ",")
    # Get each entry
    for _ in range(count):
        attrs = [_read_16(rom) for _ in range(3)]
        es = _single_entry(attrs)
        lines.append(INDENT + es + ",")
    lines.append("};")
    print("\n".join(lines))


def _read_16(rom: BinaryIO) -> int:
    b = rom.read(2)
    return b[0] | (b[1] << 8)


def _count_str(count: int) -> str:
    cs = str(count & 0xFFF)
    if count & (1 << 12):
        cs += " | ARM_CANNON_OAM_ORDER_IN_FRONT"
    elif count & (1 << 13):
        cs += " | ARM_CANNON_OAM_ORDER_BEHIND"
    return cs


def _single_entry(attrs: list[int]) -> str:
    # Get macro parameters
    param_strs = _get_param_strs(attrs)
    ps = ", ".join(param_strs)
    mode = "" if len(param_strs) == 7 else "_MODE"
    return f"OAM_ENTRY{mode}({ps})"


def _get_param_strs(attrs: list[int]) -> list[str]:
    assert len(attrs) == 3
    attr0, attr1, attr2 = attrs
    x = attr1 & 0x1FF
    if x >= 0x100:
        x -= 0x200
    y = attr0 & 0xFF
    if y >= 0x80:
        y -= 0x100
    obj_shape = attr0 >> 14
    obj_size = attr1 >> 14
    dims = DIMS[(obj_shape << 2) | obj_size]
    flip = FLIPS[(attr1 >> 12) & 3]
    pal = attr2 >> 12
    prio = (attr2 >> 10) & 3
    tile = attr2 & 0x3FF
    mode = (attr0 >> 10) & 3
    param_strs = [str(x), str(y), dims, flip, f"0x{tile:x}", str(pal), str(prio)]
    if mode > 0:
        param_strs.append(MODES[mode - 1])
    return param_strs


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("rom_path", type=str)
    parser.add_argument("addrs", type=str,
        help="One or more addresses, comma separated (use 0x for hex)")

    args = parser.parse_args()

    addr_strs = args.addrs.split(",")
    addrs = [int(a, 0) for a in addr_strs]

    with open(args.rom_path, "rb") as f:
        for addr in addrs:
            dump_oam_frame(f, addr)
