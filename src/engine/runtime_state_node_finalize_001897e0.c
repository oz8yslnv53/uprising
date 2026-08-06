#include <stdint.h>
extern void Runtime_NodeCleanupBegin_001EA114(void);
extern void Runtime_NodeCleanupHandle_001EA0AC(void *handle);
extern void *Runtime_StateContextGet_00166C50(void);
extern void Runtime_StateNodeRelease_001B3F04(void *context, void *state);
void Runtime_StateNodeFinalize_001897E0(uint8_t *state)
{
    void (*callback)(void *, uint32_t, uint32_t);
    if (*(void **)(state + 0x134) == 0)
        return;
    Runtime_NodeCleanupBegin_001EA114();
    Runtime_NodeCleanupHandle_001EA0AC(*(void **)(state + 0x134));
    *(void **)(state + 0x134) = 0;
    state[0xc5] = 0;
    state[0xc6] = 0;
    callback = *(void (**)(void *, uint32_t, uint32_t))(state + 0x12c);
    if (callback != 0)
        callback(state, 0, *(uint32_t *)(state + 0x130));
    if (state[0xc7] != 0) {
        state[0xc7] = 0;
        Runtime_StateNodeRelease_001B3F04(
            Runtime_StateContextGet_00166C50(), state);
    }
}
