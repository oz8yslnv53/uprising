#include <stdint.h>
__attribute__((noinline)) void *Engine_Tag300RelativePointerGet_00B414C0(const void *record)
{
    const unsigned char *bytes = (const unsigned char *)record;
    if (*(const uint16_t *)bytes == 0x300u)
        return (void *)(bytes + *(const uint32_t *)(bytes + 4));
    return 0;
}
