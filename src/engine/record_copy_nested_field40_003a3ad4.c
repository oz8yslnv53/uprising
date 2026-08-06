#include <stdint.h>
__attribute__((noinline)) void Record_CopyNestedField40_003A3AD4(void *object) {
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *nested = *(uint8_t **)(bytes + 0x4a4);
    *(uint32_t *)(bytes + 0xc8) = *(uint32_t *)(nested + 0x40);
}
