#include <stdint.h>
__attribute__((noinline)) uint32_t BitMask_OrIndexed_00518E34(uint32_t index, uint32_t mask)
{
    return mask | (1u << (index & 0xFFu));
}
