#include <stdint.h>
__attribute__((noinline)) void Record_InitializeType3FromPointer_00BA5954(
    void *record, const uint32_t *source, uint32_t value)
{
    uint8_t *bytes = (uint8_t *)record;
    bytes[4] = 3;
    *(uint32_t *)(bytes + 0x10) = value;
    *(uint32_t *)bytes = *source;
}
