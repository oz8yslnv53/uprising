#include <stdint.h>
__attribute__((noinline)) uint8_t *Engine_IndexedStride44Address_004C381C(
    const uint8_t *object, unsigned int index)
{
    return *(uint8_t **)(object + 0x1c) + index * 0x2cu;
}
