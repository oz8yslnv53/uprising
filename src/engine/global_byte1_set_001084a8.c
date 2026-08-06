#include <stdint.h>
__attribute__((noinline)) int Engine_SetGlobalByte1_001084A8(void) {
    int result = 1;
    uint8_t *state = (uint8_t *)0x00D4E64Cu;
    state[1] = (uint8_t)result;
    return result;
}
