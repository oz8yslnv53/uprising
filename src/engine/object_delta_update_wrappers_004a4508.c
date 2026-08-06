#include <stdint.h>
extern void Engine_ObjectDeltaUpdate_004CFD8C(void *object, float delta);
__attribute__((noinline)) uint32_t Engine_ObjectDeltaUpdateWrapper_004A4508(
    void *object, void *unused1, void *unused2, const uint8_t *record)
{
    (void)unused1;
    (void)unused2;
    Engine_ObjectDeltaUpdate_004CFD8C(object, *(const float *)(record + 0xc));
    return 0;
}
__attribute__((noinline)) uint32_t Engine_ObjectDeltaUpdateWrapper_004A4900(
    void *object, void *unused1, void *unused2, const uint8_t *record)
{
    (void)unused1;
    (void)unused2;
    Engine_ObjectDeltaUpdate_004CFD8C(object, *(const float *)(record + 0xc));
    return 0;
}
