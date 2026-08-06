#include <stdint.h>
__attribute__((noinline)) void InputFrame_AddCounters_00919DB0(
    uint8_t *destination, const uint8_t *source) {
    *(int32_t *)(destination + 0x20c) += *(const int32_t *)(source + 0x20c);
    *(int32_t *)(destination + 0x210) += *(const int32_t *)(source + 0x210);
    *(int32_t *)(destination + 0x214) += *(const int32_t *)(source + 0x214);
    *(int32_t *)(destination + 0x218) += *(const int32_t *)(source + 0x218);
}
