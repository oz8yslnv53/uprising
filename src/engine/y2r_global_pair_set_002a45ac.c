#include <stdint.h>
__attribute__((noinline)) void Y2R_GlobalPairSet_002A45AC(uint32_t first, uint32_t second)
{
    volatile uint32_t *global = (volatile uint32_t *)(uintptr_t)0x00D4E348;
    global[1] = second;
    global[0] = first;
}
