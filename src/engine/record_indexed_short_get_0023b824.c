#include <stdint.h>
__attribute__((noinline)) int Engine_RecordIndexedShortGet_0023B824(const uint8_t *record, int index) {
    if (index < 2)
        return *(const int16_t *)(*(const uint32_t *)(record + index * 4 + 0x3c) + 8);
    return 0;
}
