#include <stdint.h>
extern void StateRecord_AtomicReset_0036A058(void *record);
extern void Engine_GuardedResourceGlobalFieldCSet_0010C7A8(uint32_t value);
__attribute__((noinline)) void Engine_GuardedResourceInitialize_001080EC(void *value)
{
    volatile uint8_t *flag = (volatile uint8_t *)(uintptr_t)0x00d4e66cu;
    if (*flag == 0u) {
        StateRecord_AtomicReset_0036A058((void *)(uintptr_t)0x00df282cu);
        Engine_GuardedResourceGlobalFieldCSet_0010C7A8(
            (uint32_t)(uintptr_t)value);
        *flag = 1u;
    }
}
