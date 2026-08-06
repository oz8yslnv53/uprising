#include <stdint.h>
__attribute__((noinline)) void Engine_ClearGlobalWordIfSet_0013563C(void)
{
    uint32_t *value = (uint32_t *)(uintptr_t)0x00D4E4E4u;
    if (*value != 0u)
        *value = 0u;
}
