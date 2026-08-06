#include <stdint.h>
__attribute__((noinline)) void FUN_0031D538(
    uint8_t **span, const uint8_t *end, uint32_t count)
{
    uint8_t *start = span[0];
    uint32_t index = (uint32_t)(((uintptr_t)end -
                                 (uintptr_t)span[1]) >> 4);
    uint32_t limit = count + index;
    for (; limit > index; ++index)
        start[index] = 0;
}
