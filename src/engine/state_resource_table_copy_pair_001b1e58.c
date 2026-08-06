#include <stdint.h>
void StateResource_TableCopyPair_001B1E58(
    void *table, int index, uint32_t *first, uint32_t *second)
{
    uint8_t *entry;
    entry = (uint8_t *)table + index * 4;
    *first = *(uint32_t *)(entry + 0x14);
    *second = *(uint32_t *)(entry + 0x1C);
}
