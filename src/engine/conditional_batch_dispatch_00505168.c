#include <stdint.h>
extern void FUN_004AFFB8(void *callback, void *first, void *second,
                         void *third, uint32_t fourth);
__attribute__((noinline)) void Engine_ConditionalBatchDispatch_00505168(void *first, void *second,
                                              void *third, uint32_t fourth)
{
    void **slot = (void **)(uintptr_t)0x00D49490u;
    if (*slot != 0)
        FUN_004AFFB8(*slot, first, second, third, fourth);
}
