#include <stdint.h>
__attribute__((noinline)) void Engine_IndexedHalfwordStoreCc_001E9B08(
    void *base,
    int index,
    uint16_t value)
{
    uint8_t *bytes = (uint8_t *)base;
    *(uint16_t *)(bytes + index * 2 + 0xcc) = value;
}
