#include <stdint.h>
__attribute__((noinline)) void Engine_StoreHalfWordAt46B0_006DDB28(uint8_t *base, uint16_t half_value,
                                         uint32_t word_value, uint32_t index) {
    uint8_t *record = base + index * 8 + 0x46b0;
    *(uint16_t *)record = half_value;
    *(uint32_t *)(record + 4) = word_value;
}
