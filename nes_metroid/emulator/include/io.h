#ifndef IO_H
#define IO_H

#include "types.h"

#define WRITE_64(addr, val) (*(vu64 *)(addr)) = (val)
#define WRITE_32(addr, val) (*(vu32 *)(addr)) = (val)
#define WRITE_16(addr, val) (*(vu16 *)(addr)) = (val)
#define WRITE_8(addr, val) (*(vu8 *)(addr)) = (val)

#define READ_64(addr) (*(vu64 *)(addr))
#define READ_32(addr) (*(vu32 *)(addr))
#define READ_16(addr) (*(vu16 *)(addr))
#define READ_8(addr) (*(vu8 *)(addr))

#endif /* IO_H */
