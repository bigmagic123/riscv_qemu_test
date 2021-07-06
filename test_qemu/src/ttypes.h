#ifndef __TYPES_H__
#define __TYPES_H__

typedef unsigned long  uint64_t;
typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;

static inline void write32(uint32_t addr, uint32_t value)
{
    *((volatile uint32_t *)(addr)) = value;
}

static inline uint32_t read32(uint32_t addr)
{
    return( *((volatile uint32_t *)(addr)));
}

#endif