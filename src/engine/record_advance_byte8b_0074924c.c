#include <stdint.h>
__attribute__((noinline)) int Record_AdvanceByte8BIfReady_0074924C(void *record, uint32_t value)
{
    uint8_t *bytes = (uint8_t *)record;
    if (value >= 0xffu)
        return 0;
    if (*(uint32_t *)(bytes + 0x4c) == 0)
        return 0;
    if (*(uint32_t *)(bytes + 0x40) == 0)
        return 0;
    if (bytes[0x8b] != 0)
        return 0;
    bytes[0x8b] = (uint8_t)value + 1u;
    return 1;
}
