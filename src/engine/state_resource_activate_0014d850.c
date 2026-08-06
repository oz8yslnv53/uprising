#include <stdint.h>
extern void StateRecord_Init_001B0E14(void *record, int mode);
extern void StateResource_ActivateBackend_00164F94(void *state, int mode);
void StateResource_Activate_0014D850(void)
{
    int8_t *state = (int8_t *)(uintptr_t)0x00d4d798u;
    if ((state[0] & (int8_t)~state[1]) != 0) {
        StateRecord_Init_001B0E14(state + 8, 1);
        state[2] = 1;
        StateResource_ActivateBackend_00164F94((void *)(uintptr_t)0x00df2b24u,
                                               1);
        state[1] = 1;
    }
}
