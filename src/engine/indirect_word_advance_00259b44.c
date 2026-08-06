#include <stdint.h>
__attribute__((noinline)) uint32_t *Engine_IndirectWordAdvance_00259B44(uint32_t *slot) {
    uint32_t *next = (uint32_t *)slot[0];
    if (next != 0)
        slot[0] = next[0];
    return next;
}
