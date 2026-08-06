#include <stdint.h>
__attribute__((noinline)) void Engine_SetIndexedStrideWordIfBelow100_007F2680(uint32_t *base,
                                                     uint32_t index,
                                                     uint32_t value)
{
    if (index < 100)
        *(uint32_t *)((unsigned char *)base + index * 0x4c8u) = value;
}
