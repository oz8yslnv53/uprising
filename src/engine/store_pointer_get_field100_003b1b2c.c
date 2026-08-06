// 003B1B2C: store a pointer through out, then return source field +0x100.
#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_StorePointerAndGetField100_003B1B2C(
    const uint8_t *source, uint32_t **out)
{
    *out = (uint32_t *)source;
    return *(const uint32_t *)(source + 0x100);
}
