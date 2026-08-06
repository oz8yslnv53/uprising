#include <stdint.h>
void ResourceEntryTable_Init_0043ECB8(uint8_t *base)
{
    uint32_t i;
    for (i = 0; i != 0x10; ++i) {
        uint8_t *entry = base + i * 0x10;
        *(uint32_t *)(entry + 0) = 0xffffffffu;
        entry[0x0c] = 0;
        entry[0x0d] = 0;
    }
    *(uint32_t *)(base + 0x100) = 0;
}
void ResourceEntryTable_ClearOne_0043ECE8(uint8_t *base)
{
    *(uint32_t *)(base + 0) = 0xffffffffu;
    base[0x0c] = 0;
    base[0x0d] = 0;
}
