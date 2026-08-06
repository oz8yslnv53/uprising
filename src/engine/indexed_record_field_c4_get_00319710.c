#include <stdint.h>
uint32_t IndexedRecord_FieldC4Get_00319710(void *record, uint32_t index)
    __attribute__((noinline));
__attribute__((noinline)) uint32_t IndexedRecord_FieldC4Get_00319710(void *record, uint32_t index)
{
    if (index >= 100u)
        return 0xffffffffu;
    return *(uint32_t *)((uint8_t *)record + index * 0x4c8u + 0xc4u);
}
