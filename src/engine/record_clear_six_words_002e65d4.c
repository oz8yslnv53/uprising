#include <stdint.h>
__attribute__((noinline)) void Record_ClearSixWords_002E65D4(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)(bytes + 0x1c) = 0u;
    *(uint32_t *)(bytes + 0x28) = 0u;
    *(uint32_t *)(bytes + 0x2c) = 0u;
    *(uint32_t *)(bytes + 0x20) = 0u;
    *(uint32_t *)(bytes + 0x24) = 0u;
    *(uint32_t *)(bytes + 0x30) = 0u;
}
