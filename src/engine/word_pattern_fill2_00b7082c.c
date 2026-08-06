#include <stdint.h>
__attribute__((noinline)) void WordPattern_Fill2_00B7082C(uint32_t *destination, uint32_t value)
{
    uint32_t pattern = value & 0xFFu;
    pattern |= pattern << 8;
    pattern |= pattern << 16;
    destination[0] = pattern;
    destination[1] = pattern;
}
