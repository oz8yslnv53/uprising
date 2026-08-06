#include <stdint.h>
__attribute__((noinline)) uint8_t *ResourceRecord_AddRelativeOffset_00B40C5C(
    uint8_t *record)
{
    return record + *(int32_t *)(record + 4);
}
__attribute__((noinline)) uint8_t *ResourceRecord_AddRelativeOffset2_00B40CD8(
    uint8_t *record)
{
    return record + *(int32_t *)(record + 4);
}
__attribute__((noinline)) uint8_t *ResourceTable_Find4900_00B40C68(
    uint8_t *table, uint32_t index)
{
    uint8_t *entries = table + *(int32_t *)(table + 0x0c);
    if (index < *(uint32_t *)entries &&
        *(uint16_t *)(entries + index * 8 + 4) == 0x4900)
        return entries + *(int32_t *)(entries + index * 8 + 8);
    return 0;
}
__attribute__((noinline)) uint8_t *ResourceTable_Find4902AtOffset_00B40C9C(
    uint8_t *table, uint32_t index)
{
    uint8_t *entries = table + *(int32_t *)(table + 0x14);
    if (index < *(uint32_t *)entries &&
        *(uint16_t *)(entries + index * 8 + 4) == 0x4902)
        return entries + *(int32_t *)(entries + index * 8 + 8);
    return 0;
}
