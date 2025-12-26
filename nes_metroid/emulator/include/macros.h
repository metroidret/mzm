#include "io.h"

/**
 * @brief Fetches the low byte from an @c u16
 * 
 * @param value Value
 * @return Low byte
 */
#define LOW_BYTE(value) ((value) & 0xFF)

/**
 * @brief Fetches the high byte from an @c u16
 * 
 * @param value Value
 * @return High byte
 */
#define HIGH_BYTE(value) (((value) & 0xFF << 8) >> 8)

/**
 * @brief Fetches the low short from an @c u32
 * 
 * @param value Value
 * @return Low short
 */
#define LOW_SHORT(value) ((value) & 0xFFFF)

/**
 * @brief Fetches the high short from an @c u16
 * 
 * @param value Value
 * @return High short
 */
#define HIGH_SHORT(value) ((value) >> 16)

/**
 * @brief Constructs an @c u32 from 2 @c u32
 * 
 * @param high High
 * @param low Low
 * @return Value (high << 16 | low)
 */
#define C_32_2_16(high, low) ((high) << 16 | (low))

/**
 * @brief Constructs an @c u16 from 2 @c u8
 * 
 * @param high High
 * @param low Low
 * @return Value (high << 8 | low)
 */
#define C_16_2_8(high, low) ((s32)(high) << 8 | (s32)(low))

/**
 * @brief Constructs an @c u16 from 2 @c u8
 * 
 * @param high High
 * @param low Low
 * @return Value (low | high << 8)
 */
#define C_16_2_8_(high, low) ((low) | (high) << 8)

/**
 * @brief Creates a signed 8-bit value from an @c s16
 * 
 * @param value Value
 * @return Result
 */
#define C_S8_2_S16(value) ((value) & 0x80 ? 0x100 + (value) : (value))

/**
 * @brief Creates a signed 9-bit value from an @c s16
 * 
 * @param value Value
 * @return Result
 */
#define C_S9_2_S16(value) ((value) & 0x100 ? 0x200 + (value) : (value))

/**
 * @brief Creates an array at the specified memory location, used to create symbols for Ewram arrays
 * e.g. :
 * `#define gSomeSymbol CAST_TO_ARRAY(u8, [8], EWRAM_BASE + 0x1000)`
 * Will create a symbol bound to address EWRAM_BASE + 0x1000 of type u8 [8]
 * In normal C code, that would be :
 * `extern u8 gSomeSymbol[8];`
 * 
 * @param type Array element type
 * @param sizes Array sizes
 * @param ptr Address
 */
#define CAST_TO_ARRAY(type, sizes, ptr) (*((type (*)sizes)((ptr))))

/**
 * @brief Gets the offset, in bytes, of an element in a struct
 * 
 * @param type Base type
 * @param element Element name
 * @return Offset of the element, in byes
 */
#define OFFSET_OF(type, element) ((s32)&(((type*)0)->element))

/**
 * @brief Gets the number of elements in an array
 * 
 * @param a Array
 * @return Number of elements in the array
 */
#define ARRAY_SIZE(a) ((s32)(sizeof((a)) / sizeof((a)[0])))

/**
 * @brief Accesses an array in a safe way, preventing overflow
 * 
 * @param a Array
 * @param o Index
 * @return Array value 
 */
#define ARRAY_ACCESS(a, i) (a[(u32)(i) % ARRAY_SIZE(a)])

/**
 * @brief Ceils a value
 * 
 * @param v Value
 * @return Ceiled value
 */
#define CEIL(v) ((int)(((float)v) + .5) == (int)(v) ? ((int)(v)) : (int)(((float)v) + .5))

/**
 * @brief Clamps a value (checks for max first)
 * 
 * @param value Value
 * @param min Minimum
 * @param max Maximum
 */
#define CLAMP(value, min, max)\
{                             \
    if (value > (max))        \
        value = (max);        \
    else if (value < (min))   \
        value = (min);        \
}

/**
 * @brief Clamps a value (checks for min first)
 * 
 * @param value Value
 * @param min Minimum
 * @param max Maximum
 */
#define CLAMP2(value, min, max)\
{                              \
    if (value < (min))         \
        value = (min);         \
    else if (value > (max))    \
        value = (max);         \
}

/**
 * @brief Computes the absolute distance between 2 points on the same axis
 * 
 * @param a A
 * @param b B
 * @return Absolute distance
 */
#define ABS_DIFF(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

#ifdef MODERN
/**
 * @brief Performs a static assertion
 * 
 * @param expr Expression to assert
 * @param id Error message
 */
#define STATIC_ASSERT(expr, id) static_assert(expr, "Assert failed : " #id)
#else
/**
 * @brief Performs a static assertion
 * 
 * @param expr Expression to assert
 * @param id Struct name, this will be printed in the error message
 */
#define STATIC_ASSERT(expr, id) typedef char id[(expr) ? 1 : -1];
#endif

/**
 * @brief Empty `do while(0)` statement
 * 
 */
#define EMPTY_DO_WHILE {do {} while(0);}

#define OPPOSITE_DIRECTION(dir) ((dir) ^ (KEY_RIGHT | KEY_LEFT))

/**
 * @brief Max color value that can be represented using 5-bit depth
 * 
 */
#define COLOR_MAX 0x1F

/**
 * @brief Extracts the red component from a color
 * 
 * @param c Color
 * @return Red component
 */
#define RED(c) ((c) & COLOR_MAX)

/**
 * @brief Extracts the green component from a color
 * 
 * @param c Color
 * @return Green component
 */
#define GREEN(c) (((c) & (COLOR_MAX << 5)) >> 5)

/**
 * @brief Extracts the blue component from a color
 * 
 * @param c Color
 * @return Blue component
 */
#define BLUE(c) (((c) & (COLOR_MAX << 10)) >> 10)

/**
 * @brief Creates a color with the 3 specified components
 * 
 * @param r Red
 * @param g Green
 * @param b Blue
 * @return Color
 */
#define COLOR(r, g, b) (((b) << 10) | ((g) << 5) | (r))

/**
 * @brief Creates a color with the 3 specified components (same as @c COLOR)
 * 
 * @param r Red
 * @param g Green
 * @param b Blue
 * @return Color
 */
#define COLOR_GRAD(r, g, b) ((r) | ((g) << 5) | ((b) << 10))

/**
 * @brief White color constant
 * 
 */
#define COLOR_WHITE COLOR(COLOR_MAX, COLOR_MAX, COLOR_MAX)

/**
 * @brief Black color constant
 * 
 */
#define COLOR_BLACK COLOR(0, 0, 0)

/**
 * @brief Red color constant
 * 
 */
#define COLOR_RED COLOR(COLOR_MAX, 0, 0)

/**
 * @brief Green color constant
 * 
 */
#define COLOR_GREEN COLOR(0, COLOR_MAX, 0)

/**
 * @brief Blue color constant
 * 
 */
#define COLOR_BLUE COLOR(0, 0, COLOR_MAX)

/**
 * @brief Yellow color constant
 * 
 */
#define COLOR_YELLOW COLOR(COLOR_MAX, COLOR_MAX, 0)

/**
 * @brief Magenta color constant
 * 
 */
#define COLOR_MAGENTA COLOR(COLOR_MAX, 0, COLOR_MAX)

/**
 * @brief Cyan color constant
 * 
 */
#define COLOR_CYAN COLOR(0, COLOR_MAX, COLOR_MAX)

/**
 * @brief Sets the backdrop color
 * 
 * @param color Color
 */
#define SET_BACKDROP_COLOR(color) (WRITE_16(PALRAM_BASE, (color)))

/**
 * @brief Generic Dma transfer to send palette to pal
 * 
 * @param pal Palette data
 * @param dst Destination address in palram
 */
#define SEND_TO_PALRAM(pal, dst) (DmaTransfer(3, pal, dst, sizeof(pal), 16))

/**
 * @brief Converts a number to Q8.8 fixed-point format
 * 
 * @param n Value
 * @return Q8.8 value
 */
#define Q_8_8(n) ((s16)((n) * 256))

/**
 * @brief Converts a Q8.8 fixed-point format number to a regular @c s16
 * 
 * @param n Value
 * @return @c s16 Regular value
 */
#define Q_8_8_TO_S16(n) ((s16)((n) >> 8))

/**
 * @brief Converts a Q8.8 fixed-point format number to a regular @c s16
 * 
 * @param n Value
 * @return @c s16 Regular value
 */
#define Q_8_8_TO_S16_DIV(n) (((n) / 256))

/**
 * @brief Converts a number to Q16.16 fixed-point format
 * 
 * @param n Value
 * @return Q16.16 value
 */
#define Q_16_16(n) ((s32)((n) * 65536))

/**
 * @brief Converts a number to Q24.8 fixed-point format
 * 
 * @param n Value
 * @return Q24.8 value
 */
#define Q_24_8(n) ((s32)((n) << 8))

/**
 * @brief Converts a Q8.8 fixed-point format number to a regular integer
 * 
 * @param n Q8.8 value
 * @return @c s32 Value
 */
#define Q_8_8_TO_S32(n) ((s32)((n) / 256))

/**
 * @brief Converts a Q24.8 fixed-point format number to a regular integer
 * 
 * @param n Q24.8 value
 * @return @c s32 Value
 */
#define Q_24_8_TO_S32(n) ((s32)((n) >> 8))

/**
 * @brief Performs a modulo (value % mod) operation on a value using the and operation (WARNING only use a value for mod that is a power of 2)
 * 
 * @param value Value
 * @param mod Modulo
 * @return Result (value % mod)
 */
#define MOD_AND(value, mod) ((value) & ((mod) - 1))

/**
 * @brief Performs a division (value / div) operation on a value using the right shift operation (WARNING only use a value for div that is a power of 2 and <= 1024)
 * 
 * @param value Value
 * @param div Divisor
 * @return Result (value / div)
 */
#define DIV_SHIFT(value, div) ((value) >> ((div) == 2 ? 1 : ((div) == 4 ? 2 : ((div) == 8 ? 3 : ((div) == 16 ? 4 : ((div) == 32 ? 5 : ((div) == 64 ? 6 : ((div) == 128 ? 7 : ((div) == 256 ? 8 : ((div) == 512 ? 9 : ((div) == 1024 ? 10 : 0)))))))))))

/**
 * @brief Performs a multiplaction (value * mul) operation on a value using the left shift operation (WARNING only use a value for div that is a power of 2 and <= 256)
 * 
 * @param value Value
 * @param mul Multiplier
 * @return Result (value * mul)
 */
#define MUL_SHIFT(value, mul) ((value) << ((mul) == 2 ? 1 : ((mul) == 4 ? 2 : ((mul) == 8 ? 3 : ((mul) == 16 ? 4 : ((mul) == 32 ? 5 : ((mul) == 64 ? 6 : ((mul) == 128 ? 7 : ((mul) == 256 ? 8 : ((mul) == 512 ? 9 : ((mul) == 1024 ? 10 : 0)))))))))))

/**
 * @brief Multiplies a number by a fraction (num/den)
 * 
 * @param value Value
 * @param num Numerator
 * @param den Denominator
 * @return Result (value * num / den)
 */
#define FRACT_MUL(value, num, den) ((value) * (num) / (den))

/**
 * @brief Multiplies a number by a floating point using a fraction. The float value must only have one floating digit.
 * 
 * @param value Value
 * @param f Floating point value
 * @return Result (value * f)
 */
#define FLOAT_MUL(value, f) ((value) * ((s32)((f) * 10)) / 10)

/**
 * @brief Performs a semi-modulo (value & mod) operation on a value using the and operation (WARNING only use a value for mod that is a power of 2)
 * This creates a cyclic value of the modulo, that swaps every "mod" times.
 * e.g., with mod = 4, and value starting from 0 and incremeting, the macro will yield 0, 4 times, then 4, 4 times, then 0 again 4 times...
 * 
 * @param value Value
 * @param mod Modulo
 */
#define MOD_BLOCK_AND(value, mod) ((value) & (mod))

/**
 * @brief PI is half a rotation on the unit circle, a full rotation is Q_8_8(1.f)
 * 
 */
#define PI Q_8_8(.5f)

/**
 * @brief Shorthand for PI / 2
 * 
 */
#define PI_2 (PI / 2)

/**
 * @brief Shorthand for PI / 4
 * 
 */
#define PI_4 (PI / 4)

/**
 * @brief Shorthand for PI * 3 / 4
 * 
 */
#define PI_3_4 (PI * 3 / 4)

/**
 * @brief Computes the sine of a value
 * 
 * @param value Q8.8 Value
 * @return Q8.8 sin value
 */
#define SIN(value) (sSineTable[(value)])

/**
 * @brief Computes the cosine of a value
 * 
 * @param value Q8.8 Value
 * @return Q8.8 cos value
 */
#define COS(value) (sSineTable[(value) + PI_2])

/**
 * @brief Converts from sub-pixel to pixel coordinates
 * 
 * @param subPixel Sub pixel coordinates
 * @return Pixel coordinates
 */
#define SUB_PIXEL_TO_PIXEL(subPixel) ((subPixel) / SUB_PIXEL_RATIO)

/**
 * @brief !!NOT RECOMMENDED!! Converts from sub-pixel to pixel coordinates.
 * This version of the macro uses a shift instead of a division and should only be used for matching purposes.
 * 
 * @param subPixel Sub pixel coordinates
 * @return Pixel coordinates
 */
#define SUB_PIXEL_TO_PIXEL_(subPixel) (DIV_SHIFT(subPixel, SUB_PIXEL_RATIO))

/**
 * @brief Converts from pixel to sub pixel coordinates
 * 
 * @param pixel Pixel coordinates
 * @return Sub pixel coordinates
 */
#define PIXEL_TO_SUB_PIXEL(pixel) ((pixel) * SUB_PIXEL_RATIO)

/**
 * @brief Converts from sub pixel to block coordinates
 * 
 * @param subPixel Sub pixel coordinates
 * @return Block coordinates
 */
#define SUB_PIXEL_TO_BLOCK(subPixel) ((subPixel) / BLOCK_SIZE)

/**
 * @brief !!NOT RECOMMENDED!! Converts from sub pixel to block coordinates
 * This version of the macro uses a shift instead of a division and should only be used for matching purposes.
 * 
 * @param subPixel Sub pixel coordinates
 * @return Block coordinates
 */
#define SUB_PIXEL_TO_BLOCK_(pixel) (DIV_SHIFT((pixel), BLOCK_SIZE))

/**
 * @brief Converts from block to sub pixel coordinates
 * 
 * @param block Block coordinates
 * @return Sub pixel coordinates
 */
#define BLOCK_TO_SUB_PIXEL(block) ((block) * BLOCK_SIZE)

/**
 * @brief Screen size X, in sub pixel coordinates
 * 
 */
#define SCREEN_SIZE_X_SUB_PIXEL (PIXEL_TO_SUB_PIXEL(SCREEN_SIZE_X))

/**
 * @brief Screen size Y, in sub pixel coordinates
 * 
 */
#define SCREEN_SIZE_Y_SUB_PIXEL (PIXEL_TO_SUB_PIXEL(SCREEN_SIZE_Y))

/**
 * @brief Screen size X, in block coordinates
 * 
 */
#define SCREEN_SIZE_X_BLOCKS (SUB_PIXEL_TO_BLOCK(SCREEN_SIZE_X_SUB_PIXEL))

/**
 * @brief Screen size Y, in block coordinates
 * 
 */
#define SCREEN_SIZE_Y_BLOCKS (SUB_PIXEL_TO_BLOCK(SCREEN_SIZE_Y_SUB_PIXEL))

/**
 * @brief How many blocks of padding there is on each X edge of a room
 * 
 */
#define SCREEN_X_PADDING 2

/**
 * @brief How many blocks of padding there is on each X edge of a room, in sub-pixel
 * 
 */
#define SCREEN_X_BLOCK_PADDING (BLOCK_TO_SUB_PIXEL(SCREEN_X_PADDING))

/**
 * @brief How many blocks of padding there is on each Y edge of a room
 * 
 */
#define SCREEN_Y_PADDING 2

/**
 * @brief How many blocks of padding there is on each Y edge of a room, in sub-pixel
 * 
 */
#define SCREEN_Y_BLOCK_PADDING (BLOCK_TO_SUB_PIXEL(SCREEN_Y_PADDING))

/**
 * @brief Allows, via preproc, to convert a string to the custom encoding used in the engine
 * 
 * @param x Text
 */
#define INCTEXT(x)  {0}

/**
 * @brief Allows, via preproc, to convert a string to shift-jis encoding
 * 
 * @param x Text
 */
#define SHIFT_JIS(x) {0}

/**
 * @private
 * @brief Dummy macro for preproc, do not use
 * 
 */
#define INCBIN(...) {0}

/**
 * @brief Includes a binary file as an array of @c u8
 * 
 * @param path File path
 */
#define INCBIN_U8(path)   INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c u16
 * 
 * @param path File path
 */
#define INCBIN_U16(path)  INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c u32
 * 
 * @param path File path
 */
#define INCBIN_U32(path)  INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c s8
 * 
 * @param path File path
 */
#define INCBIN_S8(path)   INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c s8
 * 
 * @param path File path
 */
#define INCBIN_S16(path)  INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c s32
 * 
 * @param path File path
 */
#define INCBIN_S32(path)  INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c u8
 * 
 * Does not add curly braces
 * 
 * @param path File path
 */
#define _INCBIN_U8(path)  INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c u16
 * 
 * Does not add curly braces
 * 
 * @param path File path
 */
#define _INCBIN_U16(path) INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c u32
 * 
 * Does not add curly braces
 * 
 * @param path File path
 */
#define _INCBIN_U32(path) INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c s8
 * 
 * Does not add curly braces
 * 
 * @param path File path
 */
#define _INCBIN_S8(path)  INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c s16
 * 
 * Does not add curly braces
 * 
 * @param path File path
 */
#define _INCBIN_S16(path) INCBIN(path)

/**
 * @brief Includes a binary file as an array of @c s32
 * 
 * Does not add curly braces
 * 
 * @param path File path
 */
#define _INCBIN_S32(path) INCBIN(path)

/**
 * @brief Shorthand to specify that something should be in the .rodata section
 * 
 */
#ifndef MODERN
#define FORCE_RODATA __attribute__((section(".rodata")))
#else
#define FORCE_RODATA
#endif

/**
 * @brief Shorthand to specify that something should be in the section allocated to IWRAM
 * 
 */
#ifndef MODERN
#define IWRAM_DATA __attribute__((section("iwram_data")))
#else
#define IWRAM_DATA
#endif

/**
 * @brief Shorthand to specify that a function is naked (no prologue and no epilogue)
 * 
 */
#define NAKED_FUNCTION __attribute__((naked))

/**
 * @brief Shorthand to specify that something should be packed
 * 
 */
#define PACKED __attribute__((packed))

/**
 * @brief Creates an enum and its underlying type
 * 
 * The underlying type will have the enum name, and the provided type.
 * 
 * The enum will have the name provided followed by an underscore (_).
 * 
 * e.g. Using the macro like this :
 * 
 * `MAKE_ENUM(u8, Event)`
 * 
 * will create this :
 * 
 * `typedef u8 Event;`
 * 
 * `enum Event_`
 * 
 * @param type Underlying enum type
 * @param name Enum name
 * 
 */
#define MAKE_ENUM(type, name)   \
typedef type name;              \
enum name ##_

/**
 * @brief Indicates that an enum is a list of flags.
 * 
 */
#define ENUM_FLAG
