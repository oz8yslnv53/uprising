#include <stdint.h>
void ResourceRecord_PairInit_00435568(uint8_t *record)
{
    const volatile uint32_t *seed = (const volatile uint32_t *)0x00d4de24u;
    *(uint32_t *)(record + 0x10) = 0;
    *(uint32_t *)(record + 0x0c) = 0;
    *(uint32_t *)(record + 0x08) = 0;
    *(uint32_t *)(record + 0x04) = 0;
    *(uint32_t *)(record + 0x20) = 0;
    *(uint32_t *)(record + 0x1c) = 0;
    *(uint32_t *)(record + 0x18) = 0;
    *(uint32_t *)(record + 0x14) = 0;
    *(uint32_t *)(record + 0x28) = 0;
    *(uint32_t *)(record + 0x2c) = 0;
    *(uint32_t *)(record + 0x30) = seed[0];
    *(uint32_t *)(record + 0x34) = seed[1];
    *(uint32_t *)(record + 0x38) = seed[0];
    *(uint32_t *)(record + 0x3c) = seed[1];
    *(uint32_t *)(record + 0x40) = seed[0];
    *(uint32_t *)(record + 0x44) = seed[1];
    *(uint32_t *)(record + 0x48) = seed[0];
    *(uint32_t *)(record + 0x4c) = seed[1];
    record[0] = 0;
}
