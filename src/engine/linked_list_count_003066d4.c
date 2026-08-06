#include <stdint.h>
__attribute__((noinline)) int LinkedList_CountOffset20_003066D4(void *record)
{
    uint8_t *node = *(uint8_t **)((uint8_t *)record + 4);
    int count = 0;
    while (node != 0) {
        ++count;
        node = *(uint8_t **)(node + 0x20);
    }
    return count;
}
