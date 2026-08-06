#include <stdint.h>
__attribute__((noinline)) void *Indexed_Entry80IfInRange_0047363C(void *record, int index)
{
    int count = *(int *)((uint8_t *)record + 0x3c);
    if (count > 0 && count > index)
        return (void *)(*(uint8_t **)((uint8_t *)record + 0x40) +
                        index * 0x50);
    return 0;
}
