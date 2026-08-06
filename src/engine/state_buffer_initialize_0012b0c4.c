#include <stdint.h>
extern void StateRecord_Initialize_001539F4(
    void *record, void *storage, uint32_t size);
void StateBuffer_Initialize_0012B0C4(uint8_t *object, uint32_t base,
                                     uint32_t byte_count)
{
    *(uint32_t *)(object + 0x168) = 0;
    *(uint32_t *)(object + 0x16c) = 0;
    *(uint32_t *)(object + 0x170) = 0;
    *(uint32_t *)(object + 0x180) = 0;
    *(uint32_t *)(object + 0x184) = 0;
    object[0x188] = 0;
    *(uint32_t *)(object + 0x178) = base;
    *(uint32_t *)(object + 0x17c) = byte_count >> 2;
    StateRecord_Initialize_001539F4(object, object + 0x34, 0x20);
    StateRecord_Initialize_001539F4(object + 0xb4, object + 0xe8,
                                              0x20);
}
