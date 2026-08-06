#include <stdint.h>
extern "C" __attribute__((noinline)) void RenderConfig_AppendDescriptor_0012DAEC(
    uint32_t *descriptor, uint32_t offset, uint32_t span,
    uint32_t count, uint8_t flag) {
    uint32_t *count_word = (uint32_t *)0x00D4E334u;
    uint32_t *nodes = (uint32_t *)0x00DE8F18u;
    uint32_t old_count;
    uint32_t *first;
    uint32_t index;
    descriptor[0] = 0;
    descriptor[1] = 0;
    descriptor[2] = 0;
    descriptor[3] = offset;
    descriptor[4] = offset + span;
    descriptor[5] = count;
    *(uint8_t *)((uint8_t *)descriptor + 0x18) = flag;
    old_count = *count_word;
    *count_word = old_count + count;
    first = (uint32_t *)((uint8_t *)nodes + old_count * 0x14u);
    first[0] = 0;
    first[1] = 0;
    first[2] = 0;
    first[3] = 0;
    first[4] = 0;
    index = 1;
    while (index < count) {
        uint32_t *current = first + index * 5;
        uint32_t *next = (uint32_t *)(uintptr_t)current[-1];
        current[0] = 0;
        current[1] = 0;
        current[2] = 0;
        current[3] = 0;
        current[4] = 0;
        if (next != (uint32_t *)0) {
            current[4] = (uint32_t)(uintptr_t)next;
            next[3] = (uint32_t)(uintptr_t)current;
        }
        current[-1] = (uint32_t)(uintptr_t)current;
        current[3] = (uint32_t)(uintptr_t)(current - 5);
        ++index;
    }
    descriptor[2] = (uint32_t)(uintptr_t)first;
    if (first != (uint32_t *)0)
        descriptor[2] = first[4];
    if (first[3] != 0)
        ((uint32_t *)(uintptr_t)first[3])[4] = first[4];
    if (first[4] != 0)
        ((uint32_t *)(uintptr_t)first[4])[3] = first[3];
    first[3] = 0;
    first[4] = 0;
    first[1] = offset;
    first[0] = span;
    descriptor[1] = (uint32_t)(uintptr_t)first;
}
extern "C" __attribute__((noinline)) void RenderConfig_ZeroDescriptor_0012DE10(uint32_t *record) {
    record[0] = 0;
    record[1] = 0;
    record[2] = 0;
}
