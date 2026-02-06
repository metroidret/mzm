import argparse
from io import BufferedReader
import json
from pathlib import Path


DATA_PATH = "data"
DATABASE_PATH = "database.json"
DATABASE_DEBUG_PATH = "database_debug.json"
REGIONS = ["us", "eu", "jp", "us_beta", "eu_beta"]


def extract_data(region: str, debug: bool, quiet: bool = False) -> None:
    if debug:
        region = "us_beta"
    rom: BufferedReader = open(f"mzm_{region}_baserom.gba", "rb")
    db_path = DATABASE_DEBUG_PATH if debug else DATABASE_PATH
    with open(db_path, "r") as f:
        db = json.load(f)

    for entry in db:
        path: str = entry["path"]
        if not quiet:
            print(f"Extracting {path}")

        # Create directories if they don't exist
        root_dir = entry.get("dir", DATA_PATH)
        path_obj = Path(root_dir, path)
        path_obj.parent.mkdir(parents=True, exist_ok=True)

        addr = entry["addr"].get(region)
        if addr is not None:
            count = entry["count"]
            if isinstance(count, dict):
                count = count[region]
            size: int = int(count, 16) * entry["size"]
            rom.seek(int(addr, 16))
            with open(path_obj, "wb") as f:
                f.write(rom.read(size))

    rom.close()


def sort_by_address(debug: bool, quiet: bool = False) -> None:
    db_path = DATABASE_DEBUG_PATH if debug else DATABASE_PATH
    with open(db_path, "r") as f:
        db = json.load(f)

    # Sort by first region
    region = REGIONS[0]
    entries = [e for e in db if region in e["addr"]]
    entries.sort(key=lambda e: int(e["addr"][region], 16))
    remaining = [e for e in db if region not in e["addr"]]

    # Sort remaining regions
    for region in REGIONS[1:]:
        next_remaining = []
        for entry in remaining:
            addr = entry["addr"].get(region)
            if addr is not None:
                # Find index to insert entry
                addr = int(addr, 16)
                idx = len(entries)
                for i, cmp_entry in enumerate(entries):
                    cmp_addr = cmp_entry["addr"].get(region)
                    if cmp_addr is not None and addr < int(cmp_addr, 16):
                        idx = i
                        break
                entries.insert(idx, entry)
            else:
                next_remaining.append(entry)
        remaining = next_remaining

    if len(remaining) > 0:
        raise ValueError(f"{len(remaining)} entries were not sorted")
    
    # Write sorted entries
    with open(db_path, "w") as f:
        json.dump(entries, f, indent=2)
    if not quiet:
        print(f"Sorted entries in {db_path} by address")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    group = parser.add_mutually_exclusive_group()
    # TODO: add "cn"
    group.add_argument("-r", "--region", type=str, choices=REGIONS,
        default="us", help="The region of the rom to extract from")
    group.add_argument("-d", "--debug", action="store_true",
        help="Extract debug data from the US beta rom")
    parser.add_argument("-q", "--quiet", action="store_true", help="Suppress output")
    parser.add_argument("--sort", action="store_true",
        help="Sort database entries by address")
    
    args = parser.parse_args()
    if not args.region and not args.debug:
        args.region = "us"

    if (args.sort):
        sort_by_address(args.debug, args.quiet)
    else:
        extract_data(args.region, args.debug, args.quiet)
