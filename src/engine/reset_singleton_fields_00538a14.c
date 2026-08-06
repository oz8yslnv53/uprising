#include <stdint.h>
__attribute__((noinline)) void Engine_ResetSingletonFields_00538A14(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    *(uint32_t *)(bytes + 0xC60u) = 0u;
    *(uint32_t *)(bytes + 0xC64u) = 0u;
    *(uint32_t *)(bytes + 0xC68u) = 0u;
    *(uint32_t *)(bytes + 0xC6Cu) = 0u;
}
