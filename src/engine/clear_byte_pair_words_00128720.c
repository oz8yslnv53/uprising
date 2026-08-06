#include <stdint.h>
__attribute__((noinline)) void Engine_ClearBytePairWords_00128720(void *object)
{
    volatile uint8_t *bytes = (volatile uint8_t *)object;
    bytes[0] = 0u;
    bytes[1] = 0u;
    *(volatile uint32_t *)(bytes + 4u) = 0u;
    *(volatile uint32_t *)(bytes + 8u) = 0u;
}
