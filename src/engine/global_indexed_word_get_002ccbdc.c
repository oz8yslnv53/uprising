#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_GlobalIndexedWordGet_002CCBDC(const uint32_t *unused, int index)
{
    const uint32_t *table = (const uint32_t *)(uintptr_t)0x00CA3744u;
    (void)unused;
    return table[index];
}
