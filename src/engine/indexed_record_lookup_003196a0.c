#include <stdint.h>
__attribute__((noinline)) void *Engine_IndexedRecordLookup_003196A0(void *base, uint32_t group,
                                          uint32_t slot)
{
    if (group < 100u && slot < 6u)
        return (uint8_t *)base + group * 0x4c8u + slot * 0xa8u + 0xd8u;
    return 0;
}
