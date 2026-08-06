#include <stdint.h>
__attribute__((noinline)) void Engine_StoreIndexedFloat_001E9084(uint8_t *base, uint32_t index,
                                       float value)
{
    *(float *)(base + index * 4 + 0x38) = value;
}
