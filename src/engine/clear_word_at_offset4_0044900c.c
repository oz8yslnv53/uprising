#include <stdint.h>
__attribute__((noinline)) void Engine_ClearWordAtOffset4_0044900C(void *object)
{
    uint32_t *field = (uint32_t *)((uint8_t *)object + 4);
    if (*field != 0u)
        *field = 0u;
}
