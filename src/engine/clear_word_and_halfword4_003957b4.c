#include <stdint.h>
__attribute__((noinline)) void Engine_ClearWordAndHalfword4_003957B4(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)bytes = 0;
    *(uint16_t *)(bytes + 4) = 0;
}
