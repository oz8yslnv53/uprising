#include <stdint.h>
__attribute__((noinline)) void Engine_RecordWordClearBytes_0048A530(uint32_t *record, uint32_t value) {
    uint8_t *bytes = (uint8_t *)record;
    *record = value;
    bytes[0x05] = 0;
    bytes[0x06] = 0;
}
