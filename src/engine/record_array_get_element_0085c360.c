#include <stdint.h>
__attribute__((noinline)) void *RecordArray_GetElement_0085C360(void *object, int index)
{
    uint8_t *base = *(uint8_t **)((uint8_t *)object + 4u);
    return base + (uint32_t)index * 0x18u;
}
