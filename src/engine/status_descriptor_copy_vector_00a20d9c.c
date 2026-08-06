#include <stdint.h>
__attribute__((noinline)) void StatusDescriptor_CopyF0VectorIfEnabled_00A20D9C(
    void *record, const uint32_t *source)
{
    uint8_t *bytes = (uint8_t *)record;
    if (bytes[0x107] != 0) {
        *(uint32_t *)(bytes + 0xf0) = source[0];
        *(uint32_t *)(bytes + 0xf4) = source[1];
        *(uint32_t *)(bytes + 0xf8) = source[2];
    }
}
