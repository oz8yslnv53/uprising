#include <stdint.h>
__attribute__((noinline)) void RenderState_PropagateFieldC4_00A21140(uint8_t *state)
{
    uint8_t *first = *(uint8_t **)(state + 0x30);
    uint32_t value = *(uint32_t *)(state + 0xc4);
    *(uint32_t *)(first + 0x60) = value;
    first = *(uint8_t **)(state + 0x38);
    first = *(uint8_t **)(first + 0x34);
    if (first != 0)
        *(uint32_t *)(first + 0x2c) = value;
}
