#include <stdint.h>
__attribute__((noinline)) void *ResourceTable_RecordAt_00A643FC(void *base, int index, int alternate)
{
    uint8_t *bytes = (uint8_t *)base;
    uint32_t *table = *(uint32_t **)(bytes + 0x104);
    int count;
    uint32_t selected;
    if (table == 0)
        return 0;
    count = *(int *)(bytes + 0x108);
    if (count < 0)
        return 0;
    if (count == 0)
        return 0;
    selected = alternate == 0 ? table[0] : table[2];
    return *(void **)(bytes + 0x10c) + (index + selected) * 0x5c;
}
