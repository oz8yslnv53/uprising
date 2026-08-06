#include <stdint.h>
__attribute__((noinline)) void SceneSetting_DeferredEvent_Accumulate_00A40994(
    uint8_t *record, float delta)
{
    float previous;
    if (*record == 0)
        return;
    previous = *(float *)(record + 4);
    *(float *)(record + 4) = previous + delta;
    *(float *)(record + 8) = previous;
    *(uint32_t *)(record + 0xc) += 1;
}
