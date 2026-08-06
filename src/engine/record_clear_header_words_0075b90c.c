#include <stdint.h>
__attribute__((noinline)) void Record_ClearHeaderWords_0075B90C(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)(bytes + 0x08) = 0;
    *(uint32_t *)(bytes + 0x04) = 0xffffffffu;
    *(uint32_t *)(bytes + 0x0c) = 0;
    *(uint32_t *)(bytes + 0x10) = 0;
}
