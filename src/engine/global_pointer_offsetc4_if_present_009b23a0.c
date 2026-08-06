#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_GlobalPointerOffsetC4IfPresent_009B23A0(void)
{
    uint32_t value = 0x00d4a7e4u;
    value = *(uint32_t *)value;
    if (value != 0)
        value += 0xc4u;
    return value;
}
