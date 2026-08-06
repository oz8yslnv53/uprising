#include <stdint.h>
__attribute__((noinline)) uint32_t Indexed_TableLookup_0026D5B8(int index)
{
    if ((uint32_t)(index - 1) <= 11u) {
        volatile uint32_t *table =
            (volatile uint32_t *)(uintptr_t)0x00CB1100u;
        return table[index];
    }
    return 0u;
}
