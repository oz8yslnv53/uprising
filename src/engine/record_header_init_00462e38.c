#include <stdint.h>
__attribute__((noinline)) void Engine_RecordHeaderInit_00462E38(uint8_t *record) {
    const uint32_t zero = 0;
    const uint32_t slash = 0x2fu;
    const uint32_t value = 0x00D150D4u;
    *(uint32_t *)(record + 0x04) = zero;
    *(uint32_t *)(record + 0x00) = value;
    record[0x08] = (uint8_t)slash;
    record[0x09] = 0;
}
