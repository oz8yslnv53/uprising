#include <stdint.h>
__attribute__((noinline)) uint8_t *Engine_IndexedRecordOffset18Plus8_003D47D8(uint8_t *base,
                                                    uint32_t index) {
    uint32_t scaled = index + (index << 3);
    return base + (scaled << 1) + 8;
}
