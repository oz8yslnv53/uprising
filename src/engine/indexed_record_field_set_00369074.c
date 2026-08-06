#include <stdint.h>
__attribute__((noinline)) void Engine_IndexedRecordFieldSet_00369074(uint8_t *base, uint32_t index,
                                           uint32_t value) {
    if (index < 0x10) {
        uint32_t scaled = index + (index << 4);
        scaled += index << 7;
        uint8_t *entry = base + (scaled << 3);
        if (entry != 0) {
            *(uint32_t *)(entry + 0x474) = value;
        }
    }
}
