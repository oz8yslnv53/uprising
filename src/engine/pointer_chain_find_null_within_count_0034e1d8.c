#include <stdint.h>
__attribute__((noinline)) void *PointerChain_FindNullWithinCount_0034E1D8(void *start,
                                                unsigned int count)
{
    unsigned int step = 0u;
    uint8_t *current = (uint8_t *)start;
    for (;;) {
        if (step == count)
            return current;
        current = *(uint8_t **)(current + 0x48);
        step += 1u;
        if (current == 0)
            return 0;
    }
}
