#include <stdint.h>
__attribute__((noinline)) void Engine_RecordLinkedFieldsSet_003A4BC8(uint8_t *destination,
                                           const uint8_t *source) {
    *(const uint8_t **)(destination + 0x1c) = source;
    uint32_t value = *(const uint32_t *)(source + 0x3c);
    *(uint32_t *)(destination + 0x14) = value;
    *(uint32_t *)(destination + 0x18) = value;
}
