#include <stdint.h>
__attribute__((noinline)) void Engine_RecordCopyTail_00101870(void *target, const volatile uint32_t *source)
{
    uint32_t source_word0 = source[0];
    volatile uint8_t *bytes = (volatile uint8_t *)target;
    *(volatile uint32_t *)(bytes + 0xa0) = source_word0;
    {
        uint32_t source_word3 = source[3];
        uint32_t source_word2 = source[2];
        *(volatile uint32_t *)(bytes + 0xa8) = source_word2;
        *(volatile uint32_t *)(bytes + 0xac) = source_word3;
    }
}
