#include <stdint.h>
extern void *Engine_ResolveRecord_00475590(void *record);
__attribute__((noinline)) void Engine_UpdateResolvedFloat_004981B8(void *base,
                                                                    float value)
{
    void *resolved = Engine_ResolveRecord_00475590(
        *(void **)((uint8_t *)base + 0x30u));
    if (resolved != 0)
        *(float *)((uint8_t *)resolved + 0x2cu) = value;
}
