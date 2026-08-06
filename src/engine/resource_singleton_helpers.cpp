#include <stdint.h>
static uint32_t reserve_unit(uint32_t mode)
{
    if (mode == 0 || mode == 1)
        return 1;
    if (mode == 2)
        return 2;
    if (mode == 3)
        return 4;
    return 0;
}
extern "C" __attribute__((noinline)) void *
ResourceSubrecord_ReserveSlot_00461848(void *object, uint32_t index,
                                        uint32_t count, uint32_t mode)
{
    uint8_t *base = (uint8_t *)object;
    uint32_t unit;
    uint32_t used;
    uint32_t next;
    uint8_t *record;
    if (count == 0)
        return (void *)0;
    unit = reserve_unit(mode);
    used = *(uint32_t *)(base + 0x284);
    next = used + unit * count;
    if (next > 0x100 || index >= *(uint32_t *)(base + 0x180))
        return (void *)0;
    record = base + index * 0x0c;
    record[0] = (uint8_t)mode;
    *(uint32_t *)(record + 4) = (uint32_t)(base + 0x184) + used;
    *(uint32_t *)(record + 8) = count;
    *(uint32_t *)(base + 0x284) = next;
    return record + 4;
}
extern "C" __attribute__((noinline)) int
ResourceSubrecord_AppendBytes_00435664(void *object, uint32_t index,
                                        uint32_t count)
{
    uint8_t *base = (uint8_t *)object;
    uint32_t units;
    uint32_t old_used;
    uint32_t next;
    uint8_t *record;
    uint8_t *storage;
    uint32_t i;
    if (count == 0)
        return 0;
    units = ((count - 1) >> 3) + 1;
    old_used = *(uint32_t *)(base + 0x284);
    next = old_used + units;
    if (next > 0x100 || index >= *(uint32_t *)(base + 0x180))
        return 0;
    record = base + index * 0x0c;
    record[0] = 4;
    storage = base + 0x184 + old_used;
    *(uint8_t **)(record + 4) = storage;
    *(uint32_t *)(record + 8) = units;
    for (i = 0; i < units; ++i)
        storage[i] = 0;
    *(uint32_t *)(base + 0x284) = next;
    return 1;
}
extern "C" __attribute__((noinline)) int
ResourceSubrecord_FillBytes_00435718(void *object, uint32_t index,
                                      uint32_t count, uint8_t value)
{
    uint8_t *cursor = (uint8_t *)ResourceSubrecord_ReserveSlot_00461848(
        object, index, count, 1);
    uint32_t i;
    if (count != 0) {
        cursor -= 1;
        for (i = 0; i < count; ++i)
            cursor[i] = value;
    }
    return 1;
}
extern "C" __attribute__((noinline)) int
ResourceSubrecord_FillWords_00435760(void *object, uint32_t index,
                                      uint32_t count, uint16_t value)
{
    uint16_t *cursor = (uint16_t *)ResourceSubrecord_ReserveSlot_00461848(
        object, index, count, 2);
    uint32_t i;
    if (count != 0) {
        cursor -= 1;
        for (i = 0; i < count; ++i)
            cursor[i] = value;
    }
    return 1;
}
