#include <stdint.h>
__attribute__((noinline)) void Engine_ClearSharedModeBytes_00166EEC(volatile uint8_t *state) {
    state[0] = 0;
    state[2] = 0;
    state[3] = 0;
    state[4] = 0;
    state[1] = 0;
}
