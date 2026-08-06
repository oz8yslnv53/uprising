#include <stdint.h>
__attribute__((noinline)) void ResourceState_SetIndexedPointer_00A1F56C(uint8_t *state,
                                               uint32_t index,
                                               void *value)
{
    if (value != 0)
        *(void **)(state + 0xf0 + index * 4) = value;
}
