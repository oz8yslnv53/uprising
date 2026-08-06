#include <stdint.h>
__attribute__((noinline)) void Record_StoreMixedFields_006E43AC(
    void *record, uint32_t word, float value, uint8_t flag_a, uint8_t flag_b,
    uint32_t tail)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)(bytes + 0xf0) = word;
    *(float *)(bytes + 0xf4) = value;
    bytes[0x12a] = flag_a;
    bytes[0xfc] = flag_b;
    *(uint32_t *)(bytes + 0x100) = tail;
}
