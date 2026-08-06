#include <stdint.h>
__attribute__((noinline)) void Engine_RecordFlagValueSet_00463FAC(
    uint8_t *object, uint32_t value)
{
    *(uint32_t *)(object + 0x32c4) = 1;
    *(uint32_t *)(object + 0x32c8) = value;
}
