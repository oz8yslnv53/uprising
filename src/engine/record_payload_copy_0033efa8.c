#include <stdint.h>
__attribute__((noinline)) void Engine_RecordPayloadCopy_0033EFA8(uint8_t *destination,
                                       const uint8_t *source) {
    uint32_t *destination_words = (uint32_t *)destination;
    const uint32_t *source_words = (const uint32_t *)source;
    destination_words[1] = source_words[1];
    destination_words[2] = source_words[2];
    destination_words[3] = source_words[3];
    destination[0x10] = source[0x10];
}
