#include <stdint.h>
__attribute__((noinline)) void Word_LowByteSetAt4_0053C070(void *record,
                                                            uint32_t value)
{
    volatile uint32_t *word =
        (volatile uint32_t *)((uint8_t *)record + 4);
    *word = (*word & 0xffffff00u) | (value & 0xffu);
}
