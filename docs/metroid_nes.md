# Metroid NES Emulator

This document goes into a high level overview of the emulator used to run Metroid NES.

## Loading the Emulator

The boot code for the emulator is fairly small. The emulator is called in [file_select.c](../src/file_select.c) by `OptionsNesMetroidMainLoop`.
In the boot code, located in [loader.s](../nes_metroid/asm/loader.s), the program decompresses the payload program, which is responsible for loading the emulator and rom.
The payload program, located in [code.s](../nes_metroid/payload/asm/code.s), decompresses the emulator and rom, and puts them into specific regions of memory.

## Emulator


The emulator is split into 6 main components across various regions of memory, and is a mix of handwritten assembly and compiled C code.

### Part 1
Part 1 of the emulator is loaded into 0x06006000, and is handwritten.
This file is largely responsible for setting up the emulator, and notably contains `sub_06006558`, which is the entry point for the emulator.
It also contains the code responsible for drawing text from the emulator (such as menus) to the screen.

### Part 2
Part 2 of the emulator is loaded into 0x03000000, and is a mix of handwritten and compiled code. Part 2 is largely divided into 2 parts.
The first part is the audio engine, which includes the NES audio emulation and the emulator output, and is compiled.
The second part is the main emulation core, which is reponsible for the actual NES emulation, and is handwritten. This includes:
- Code that handles the opcode logic
- Code that handles the NES register logic
- Reads/Writes to the specific memory regions of the NES, including ROM, RAM, PPU, and I/O.
- Interrupt code

### Part 3
Part 3 of the emulator is loaded into 0x0600B000, and is handwritten.
This part is fairly small, consisting of just a handful of functions to write to specific registers, and some data that likely goes unused.

### Part 4
Part 4 of the emulator is loaded into 0x0600C000, and is handwritten.
This part is fairly small, consisting of just a couple of functions. It's currently unknown what exactly the purpose of this is, but it's only called during initialization.

### Part 5
Part 5 of the emulator is loaded into 0x0600E000. The first function is compiled, while the rest of the file is handwritten.
This file mostly handles the emulator backend, which includes:
- Code that handles the Main Menu (accessible by pressing L+R)
- Code that handles the Game Over Menu
- Code that calls many of the utilities in Part 6

### Part 6
Part 6 of the emulator is loaded into 0x0203E000, and is compiled.
This file has a few main utilities, including:
- Saving the password from the game over menu
- Loading the saved password to the password screen
- Replacing the copyright years on the title screen and credits
- Saving/loading saved data to/from SRAM
