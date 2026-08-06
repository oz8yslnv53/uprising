#include <stdint.h>
__attribute__((noinline)) void FUN_002F2314(void *destination,
                                            const void *source)
{
    uint8_t *dst = (uint8_t *)destination;
    const uint8_t *src = (const uint8_t *)source;
    *(uint32_t *)(dst + 0u) = *(const uint32_t *)(src + 0u);
    *(uint16_t *)(dst + 4u) = *(const uint16_t *)(src + 4u);
    *(uint8_t *)(dst + 6u) = *(const uint8_t *)(src + 6u);
}
