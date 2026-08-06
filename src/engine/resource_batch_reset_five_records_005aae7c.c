#include <stdint.h>
extern void ResourceBatch_RecordReset_00489640(void *record);
__attribute__((noinline)) void ResourceBatch_ResetFiveRecords_005AAE7C(
    uint8_t *batch)
{
    int i;
    for (i = 0; i < 5; ++i)
        ResourceBatch_RecordReset_00489640(batch + i * 0x80 + 4);
}
