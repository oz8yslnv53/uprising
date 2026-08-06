#include <stdint.h>
__attribute__((noinline)) void
Engine_RecordGlobalPointerInit_008C0AD4(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)(bytes + 0x00) = 0x00D145A0u;
    *(uint16_t *)(bytes + 0x0c) = 0;
    bytes[0x0e] = 0;
}
