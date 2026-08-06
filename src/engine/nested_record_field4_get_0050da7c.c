#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_NestedRecordField4Get_0050DA7C(uint8_t *object)
{
    uint8_t *nested = *(uint8_t **)(object + 0x114);
    return nested != 0 ? *(uint32_t *)(nested + 4) : 0U;
}
