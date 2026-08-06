#include <stdint.h>
void StateBatchEntry_Clear_0014FF5C(uint32_t *entry)
{
    uint8_t *base = (uint8_t *)entry;
    *(uint32_t *)(base + 0x0c) = 0;
    base[0x14] = 0;
    base[0x15] = 0;
    base[0x16] = 0;
    base[0x17] = 0;
    *(uint16_t *)(base + 0x20) = 0;
    *(uint32_t *)(base + 0x58) = 0;
    *(uint32_t *)(base + 0x5c) = 0;
    entry[0] = 0;
    entry[1] = 0;
}
