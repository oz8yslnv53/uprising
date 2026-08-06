#include <stdint.h>
uint32_t Engine_GetResourceCount_00473DB8(void *entry);
__attribute__((noinline)) uint32_t Engine_CheckIndexedResourceCount_003A9218(uint8_t *base,
                                                   uint32_t index)
{
    if (index >= 3)
        return 0;
    return Engine_GetResourceCount_00473DB8(base + index * 24 + 4) >= 8;
}
