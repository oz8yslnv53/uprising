#include <stdint.h>
void IntrusiveList_UnlinkAndDecrement_00463FC0(void *owner, void *node_base)
    __attribute__((noinline));
__attribute__((noinline)) void IntrusiveList_UnlinkAndDecrement_00463FC0(void *owner, void *node_base)
{
    uintptr_t node_address = (uintptr_t)node_base;
    uint8_t *node;
    uint8_t *previous;
    uint8_t *next;
    if (node_address != 0)
        node_address += 4;
    node = (uint8_t *)node_address;
    previous = *(uint8_t **)(node + 4);
    next = *(uint8_t **)(node + 8);
    *(uint8_t **)(previous + 4) = next;
    *(uint8_t **)(next + 8) = previous;
    *(uint8_t **)(node + 4) = node;
    *(uint8_t **)(node + 8) = node;
    *(int32_t *)((uint8_t *)owner + 0xf0) -= 1;
}
