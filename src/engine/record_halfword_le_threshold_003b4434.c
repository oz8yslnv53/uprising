#include <stdint.h>
__attribute__((noinline)) int Engine_RecordHalfwordLeThreshold_003B4434(const uint8_t *record) {
    return *(const uint16_t *)(record + 2) <= 0x270e;
}
