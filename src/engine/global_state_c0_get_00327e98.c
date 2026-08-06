#include <stdint.h>
uint32_t FUN_00353C6C(void);
void *Engine_SharedState_0039FA98(void);
__attribute__((noinline)) uint8_t Engine_GlobalStateC0Get_00327E98(void)
{
    uint8_t *state;
    if (FUN_00353C6C() == 0) {
        return 0;
    }
    state = (uint8_t *)Engine_SharedState_0039FA98();
    return state[0xc0];
}
