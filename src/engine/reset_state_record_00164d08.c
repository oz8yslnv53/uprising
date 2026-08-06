#include <stdint.h>
extern void Engine_StateRecord_Invalidate_00187ED0(void * context);
__attribute__((noinline)) void Engine_ResetStateRecord_00164D08(
    uint8_t *object)
{
    if (object[0] != 0) {
        Engine_StateRecord_Invalidate_00187ED0(
            (void *)(uintptr_t)0x00E0BC54u);
        *(uint32_t *)(object + 0x4c) = 0xffffffffu;
        object[0] = 0;
    }
}
