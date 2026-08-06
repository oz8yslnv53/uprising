#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_NestedRecordField4Get_008040E0(uint8_t *object)
{
    uint8_t *nested = *(uint8_t **)(object + 0x10c);
    return nested != 0 ? *(uint32_t *)(nested + 4) : 0U;
}
