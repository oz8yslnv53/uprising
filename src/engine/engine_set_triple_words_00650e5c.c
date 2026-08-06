#include <stdint.h>
__attribute__((noinline)) void Engine_SetTripleWords_00650E5C(void *object, uint32_t first,
                                    uint32_t second, uint32_t third)
{
    uint8_t *bytes = (uint8_t *)object;
    *(uint32_t *)(bytes + 0x1292Cu) = first;
    *(uint32_t *)(bytes + 0x12930u) = second;
    *(uint32_t *)(bytes + 0x12934u) = third;
}
