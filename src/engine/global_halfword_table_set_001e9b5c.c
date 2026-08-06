#include <stdint.h>
__attribute__((noinline)) void Engine_GlobalHalfwordTableSet_001E9B5C(int index, uint16_t value)
{
    uint16_t *table = (uint16_t *)(uintptr_t)0x00DF6A80u;
    table[index] = value;
}
