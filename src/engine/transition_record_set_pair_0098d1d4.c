#include <stdint.h>
__attribute__((noinline)) void TransitionRecord_SetPairFloats_0098D1D4(
    void *base, uint32_t row, uint32_t slot, float value)
{
    uint8_t *record = (uint8_t *)base + row * 0x48u + slot * 4u;
    *(float *)(record + 0x2c) = value;
    *(float *)(record + 0x3c) = value;
}
