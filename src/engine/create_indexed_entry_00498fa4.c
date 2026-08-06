#include <stdint.h>
uint8_t *Engine_IndexedStride44Address_004C381C(const uint8_t *object,
                                                unsigned int index);
__attribute__((noinline)) uint8_t *Engine_CreateIndexedEntry_00498FA4(
    const uint8_t *descriptor)
{
    return Engine_IndexedStride44Address_004C381C(
               *(const uint8_t **)descriptor, descriptor[5]) + 0x1c;
}
