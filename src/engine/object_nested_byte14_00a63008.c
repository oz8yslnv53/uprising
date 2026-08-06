#include <stdint.h>
__attribute__((noinline)) uint8_t Object_NestedByte14_00A63008(const uint8_t *object)
{
    const uint8_t *nested = *(const uint8_t **)(object + 0xb4);
    return nested != 0 ? nested[0x14] : 0;
}
