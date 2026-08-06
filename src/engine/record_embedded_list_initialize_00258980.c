#include <stdint.h>
__attribute__((noinline)) void Record_EmbeddedListInitialize_00258980(void *record)
{
    volatile uint32_t *words = (volatile uint32_t *)record;
    uint32_t link = (uint32_t)(uintptr_t)(words + 1);
    words[0] = 0;
    words[1] = link;
    words[3] = 0;
    words[2] = link;
    words[4] = 0;
    words[5] = 0;
    words[6] = 0;
}
