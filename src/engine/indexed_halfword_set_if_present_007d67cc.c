#include <stdint.h>
__attribute__((noinline)) void IndexedHalfword_SetIfPresent_007D67CC(
    void *owner, int index, int offset, uint16_t value)
{
    uint8_t *record = (uint8_t *)owner + index * 0xc;
    uint16_t *slot = (uint16_t *)(*(uint8_t **)(record + 4) + offset * 2);
    if (slot != 0)
        *slot = value;
}
