#include <stdint.h>
__attribute__((noinline)) void ResourceFlag_SetBit10000IfPresent_0046028C(void *object, int enabled)
{
    uint8_t *bytes = (uint8_t *)object;
    uint32_t flags;
    if (*(uint32_t *)(bytes + 0x4Cu) != 0u) {
        flags = *(uint32_t *)(bytes + 0x34u);
        if (enabled != 0) {
            flags |= 0x10000u;
        } else {
            flags &= ~0x10000u;
        }
        *(uint32_t *)(bytes + 0x34u) = flags;
    }
}
