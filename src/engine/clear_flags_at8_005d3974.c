#include <stdint.h>
__attribute__((noinline)) void Engine_ClearFlagsAt8_005D3974(void *object, uint32_t mask)
{
    uint32_t *flags = (uint32_t *)((char *)object + 8);
    *flags &= ~mask;
}
