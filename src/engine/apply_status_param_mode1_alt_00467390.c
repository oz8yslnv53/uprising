#include <stdint.h>
extern void Engine_ApplyStatus_00490784(void *owner, int first, int second,
                                         int mode, float value);
__attribute__((noinline)) uint32_t Engine_ApplyStatusParamMode1Alt_00467390(
    void *owner, void *unused, uint8_t *source_record, uint8_t *value_record)
{
    uint8_t *status = *(uint8_t **)(source_record + 0x2cu);
    (void)unused;
    Engine_ApplyStatus_00490784(owner, (int)(int8_t)status[0x14au],
                                (int)(int8_t)status[0x148u], 1,
                                *(float *)(value_record + 0x0cu));
    return 0u;
}
