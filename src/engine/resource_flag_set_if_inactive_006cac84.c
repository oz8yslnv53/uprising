#include <stdint.h>
__attribute__((noinline)) void ResourceFlag_SetIfInactive_006CAC84(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *nested = *(uint8_t **)(bytes + 0x18);
    if (nested == 0 || (*(uint32_t *)(nested + 0x88) & 0x200000u) == 0)
        bytes[0] |= 8;
}
