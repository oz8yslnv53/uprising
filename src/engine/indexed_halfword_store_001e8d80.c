#include <stdint.h>
__attribute__((noinline)) void IndexedHalfwordStore_001E8D80(void *object, int index,
                                   uint16_t value) {
    uint8_t *bytes = (uint8_t *)object;
    *(uint16_t *)(bytes + 0xa0 + index * 2) = value;
}
