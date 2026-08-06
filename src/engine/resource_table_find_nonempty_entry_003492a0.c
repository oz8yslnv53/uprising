#include <stdint.h>
void *ResourceTable_FindNonEmptyEntry_003492A0(void *base, uint32_t index)
{
    uint8_t *entry;
    if (index >= 100)
        return 0;
    entry = (uint8_t *)base + index * 0x4C8u;
    if ((*(uint32_t *)(entry + 8) | *(uint32_t *)(entry + 0xC)) == 0)
        return 0;
    return entry;
}
