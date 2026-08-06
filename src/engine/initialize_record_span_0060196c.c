#include <stdint.h>
void *Engine_AlignedAllocateAndClear_0035FBFC(uint32_t *cursor,
                                              uint32_t *remaining,
                                              uint32_t size);
static const uint32_t Engine_RecordSpanLimit_00601990 = 0x0004bd20U;
__attribute__((noinline)) void *Engine_InitializeRecordSpan_0060196C(uint32_t *cursor,
                                           uint32_t *remaining)
{
    uint8_t *record = (uint8_t *)Engine_AlignedAllocateAndClear_0035FBFC(
        cursor, remaining, 0x138);
    record[0x11] = 0;
    *(uint32_t *)(record + 0x130) = 0;
    *(uint32_t *)(record + 0x134) = Engine_RecordSpanLimit_00601990;
    return record;
}
