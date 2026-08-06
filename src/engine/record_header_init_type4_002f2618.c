#include <stdint.h>
__attribute__((noinline)) void RecordHeader_InitType4_002F2618(void *object, const uint32_t *source,
                                     uint8_t value) {
    uint8_t *bytes = (uint8_t *)object;
    *(uint8_t *)(bytes + 4) = 4;
    *(uint8_t *)(bytes + 6) = value;
    *(uint32_t *)bytes = *source;
}
