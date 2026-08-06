#include <stdint.h>
__attribute__((noinline)) int Indexed_NestedShortGet_0023B854(void *object, int index)
{
    if (index < 2) {
        uint8_t *entry = *(uint8_t **)((uint8_t *)object + 0x3Cu + index * 4);
        return *(int16_t *)(entry + 4u);
    }
    return 0;
}
