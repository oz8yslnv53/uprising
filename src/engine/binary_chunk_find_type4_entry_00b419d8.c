#include <stdint.h>
__attribute__((noinline)) void *BinaryChunk_FindType4Entry_00B419D8(void *object, uint32_t key)
{
    uint8_t *base;
    uint32_t index;
    if ((key >> 24) != 4u)
        return 0;
    index = key & 0x00ffffffu;
    base = (uint8_t *)object + *(int32_t *)((uint8_t *)object + 0x2cu);
    if (index >= *(uint32_t *)base)
        return 0;
    return base + *(int32_t *)(base + index * 8u + 0x8u);
}
