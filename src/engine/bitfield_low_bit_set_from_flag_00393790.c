#include <stdint.h>
__attribute__((noinline)) void Bitfield_LowBitSetFromFlag_00393790(uint32_t *object, uint32_t enabled)
{
    uint32_t value = object[0x28 / sizeof(uint32_t)];
    if (enabled != 0u)
        value |= 1u;
    else
        value &= ~1u;
    object[0x28 / sizeof(uint32_t)] = value;
}
