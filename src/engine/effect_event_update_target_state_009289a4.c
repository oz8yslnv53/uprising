#include <stdint.h>
__attribute__((noinline)) void EffectEvent_UpdateTargetState_009289A4(
    uint8_t *state) {
    uint8_t *target = *(uint8_t **)(state + 0x50);
    int active;
    if (target == 0) {
        state[0x18] = 0;
        return;
    }
    active = (*(int (**)(void *))(*(void **)target + 0x14))(target);
    if (active == 0) {
        state[0x18] = 1;
    } else if ((int8_t)state[0x18] <= 1) {
        state[0x18] = 3;
    }
}
