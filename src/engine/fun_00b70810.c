#include <stdint.h>
__attribute__((noinline)) void FUN_00B70810(uint32_t *target, uint32_t value)
{
    uint32_t repeated = value & 0xff;
    repeated |= repeated << 8;
    repeated |= repeated << 16;
    target[0] = repeated;
    target[1] = repeated;
    target[2] = repeated;
}
