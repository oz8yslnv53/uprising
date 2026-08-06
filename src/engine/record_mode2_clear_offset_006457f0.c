#include <stdint.h>
extern void Engine_RecordModeSet_006455B0(void *object, uint32_t mode);
__attribute__((noinline)) void Engine_RecordMode2ClearOffset_006457F0(
    uint8_t *object)
{
    Engine_RecordModeSet_006455B0(object, 2);
    *(uint32_t *)(object + 0x110) = 0;
}
