#include <stdint.h>
__attribute__((noinline)) void ConfigTriple_Copy_0060B0DC(void *target,
                                                           const uint32_t *source)
{
    uint32_t *destination = (uint32_t *)((uint8_t *)target + 0xa8);
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
}
