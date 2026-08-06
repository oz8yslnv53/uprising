#include <stdint.h>
__attribute__((noinline)) void Engine_ReplaceField18IfNonzero_005D75F8(void *object, uint32_t value)
{
    uint32_t *field = (uint32_t *)((char *)object + 0x18);
    if (*field != 0)
        *field = 0;
    if (value != 0)
        *field = value;
}
