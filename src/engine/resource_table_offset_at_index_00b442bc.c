#include <stdint.h>
__attribute__((noinline)) uint8_t *ResourceTable_OffsetAtIndex_00B442BC(const uint8_t *table,
                                               uint32_t index)
{
    uint8_t *base = (uint8_t *)table + 0x14;
    const uint32_t count = *(const uint32_t *)base;
    if (index >= count)
        return 0;
    return base + *(const int32_t *)(base + 8 + index * 8);
}
