#include <stdint.h>
__attribute__((noinline)) uint8_t *ResourceEntry_AddressAtIndex_00B1A04C(const uint8_t *table,
                                               int index)
{
    return *(uint8_t * const *)(table + 0x40) + index * 0x34;
}
