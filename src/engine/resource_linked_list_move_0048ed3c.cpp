#include <stdint.h>
extern "C" void *FUN_004C5DA0(void *table, uint32_t key);
extern "C" int ResourceLinkedListMove_0048ED3C(
    void *record, void *anchor, uint32_t flags)
{
    uint8_t *node;
    if ((flags & 0x02000000u) == 0)
        return 0;
    node = (uint8_t *)FUN_004C5DA0((uint8_t *)record + 0x30,
                                   flags & 0xffffu);
    if (node == 0)
        return 0;
    if (node != (uint8_t *)anchor) {
        uint8_t *previous = *(uint8_t **)(node + 4);
        uint8_t *next = *(uint8_t **)(node + 8);
        *(uint8_t **)(previous + 8) = next;
        *(uint8_t **)(next + 4) = previous;
        next = *(uint8_t **)((uint8_t *)anchor + 8);
        *(uint8_t **)(next + 4) = node;
        *(uint8_t **)(node + 8) = next;
        *(uint8_t **)(node + 4) = (uint8_t *)anchor;
        *(uint8_t **)((uint8_t *)anchor + 8) = node;
    }
    return 1;
}
