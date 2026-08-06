#include <stdint.h>
__attribute__((noinline)) void Engine_ClearBit0IfSet_009E6EC4(uint32_t *word)
{
    uint32_t value = *word;
    if ((value & 1u) != 0)
        *word = value & ~1u;
}
