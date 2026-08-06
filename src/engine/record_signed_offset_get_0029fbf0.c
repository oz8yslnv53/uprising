#include <stdint.h>
__attribute__((noinline)) int32_t Engine_RecordSignedOffsetGet_0029FBF0(const uint8_t *record) {
    int32_t bank = *(const int8_t *)(record + 7);
    int32_t base = *(const int32_t *)(record + 0x1c);
    return base + ((bank + (bank << 1)) << 17);
}
