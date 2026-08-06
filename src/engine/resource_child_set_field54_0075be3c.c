#include <stdint.h>
__attribute__((noinline)) void ResourceChild_SetField54IfPresent_0075BE3C(void *object, uint32_t value)
{
    uint8_t *child = *(uint8_t **)((uint8_t *)object + 0x9Cu);
    if (child != 0) {
        *(uint32_t *)(child + 0x54u) = value;
    }
}
