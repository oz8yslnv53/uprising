#include <stdint.h>
__attribute__((noinline)) void Record_InitializeInvalidMode_0060E66C(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)(bytes + 0x0) = 0xffffffffu;
    *(uint32_t *)(bytes + 0x4) = 0xffffffffu;
    bytes[0x8] = 0x10;
    bytes[0x9] = 0;
}
