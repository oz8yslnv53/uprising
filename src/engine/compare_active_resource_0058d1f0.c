#include <stdint.h>
__attribute__((noinline)) int Engine_CompareActiveResource_0058D1F0(void *object)
{
    uint32_t active;
    if (object == 0)
        return 0;
    active = *(const uint32_t *)(uintptr_t)0x00D4AA90u;
    if (active != 0u && active != *(const uint32_t *)((uint8_t *)object + 0x20))
        return 1;
    return 0;
}
