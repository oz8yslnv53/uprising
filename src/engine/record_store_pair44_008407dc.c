#include <stdint.h>
__attribute__((noinline)) void Engine_RecordStorePair44_008407DC(
    void *object,
    uint32_t first,
    uint32_t second)
{
    uint32_t *words = (uint32_t *)((uint8_t *)object + 0x44);
    words[0] = first;
    words[1] = second;
}
