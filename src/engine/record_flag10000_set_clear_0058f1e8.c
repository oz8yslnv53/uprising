#include <stdint.h>
__attribute__((noinline)) void Record_Flag10000SetClear_0058F1E8(
    void *record, int enable)
{
    volatile uint32_t *word =
        (volatile uint32_t *)((uint8_t *)record + 0x14);
    uint32_t value = *word;
    if (enable != 0)
        value |= 0x10000u;
    else
        value &= ~0x10000u;
    *word = value;
}
