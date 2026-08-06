#include <stdint.h>
__attribute__((noinline)) void Engine_ClearWordSetFlags3_001E20B0(uint32_t *record)
{
    record[0] = 0;
    ((uint8_t *)record)[4] |= 3u;
}
