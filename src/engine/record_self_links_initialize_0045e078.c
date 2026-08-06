#include <stdint.h>
extern void RecordState_InitializeFields_00481B0C(void *record, float initial_value);
__attribute__((noinline)) void *Record_SelfLinksInitialize_0045E078(void *record,
                                                                    float initial_value)
{
    *(void **)((uint8_t *)record + 0x00u) = record;
    *(void **)((uint8_t *)record + 0x04u) = record;
    *(void **)((uint8_t *)record + 0x08u) = record;
    RecordState_InitializeFields_00481B0C(record, initial_value);
    return record;
}
