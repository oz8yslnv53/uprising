#include <stdint.h>
__attribute__((noinline)) uint32_t FUN_0023EF54(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    uint32_t *source = *(uint32_t **)(bytes + 0x24u);
    if (source != (uint32_t *)0)
        *(uint32_t *)(bytes + 0x18u) = source[0x39u];
    return *(uint32_t *)(bytes + 0x18u);
}
