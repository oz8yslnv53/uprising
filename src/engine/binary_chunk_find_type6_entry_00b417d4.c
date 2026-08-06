#include <stdint.h>
__attribute__((noinline)) void *BinaryChunk_FindType6Entry_00B417D4(void *object, uint32_t key) {
    uint8_t *base;
    uint32_t index;
    if ((key >> 24) != 6u)
        return 0;
    index = key & 0x00FFFFFFu;
    base = (uint8_t *)object +
        *(int32_t *)((uint8_t *)object + 0x24u);
    if (index >= *(uint32_t *)base)
        return 0;
    return base + *(int32_t *)(base + index * 8u + 0x8u);
}
