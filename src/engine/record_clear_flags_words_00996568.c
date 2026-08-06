#include <stdint.h>
__attribute__((noinline)) void Record_ClearFlagsAndWords_00996568(uint32_t *record)
{
    volatile uint32_t *words = (volatile uint32_t *)record;
    uint32_t flags = words[1];
    if ((flags & 1u) != 0)
        words[1] = flags & ~1u;
    words[0] = 0;
    words[1] = 0;
}
