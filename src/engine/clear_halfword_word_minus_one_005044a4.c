#include <stdint.h>
__attribute__((noinline)) void Engine_ClearHalfwordWordMinusOne_005044A4(uint8_t *record) {
    *(uint16_t *)(record + 0x00) = 0xffffu;
    *(uint32_t *)(record + 0x04) = 0xffffffffu;
}
