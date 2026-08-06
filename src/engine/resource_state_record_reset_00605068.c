#include <stdint.h>
extern void Engine_ClearWordAndHalfword4_003957B4(void *record);
void ResourceState_RecordReset_00605068(uint8_t *record)
{
    record[0] = 0xFF;
    record[1] = 0xFF;
    record[2] = 0xFF;
    Engine_ClearWordAndHalfword4_003957B4(record + 3);
    Engine_ClearWordAndHalfword4_003957B4(record + 9);
    *(uint32_t *)(record + 0x10) = 0;
    record[0x14] = 0;
    record[0x15] = 0;
}
