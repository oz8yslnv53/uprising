#include <stdint.h>
__attribute__((noinline)) void Indexed_Stride1160ConditionalStore_00369090(void *base,
                                                 unsigned int index,
                                                 uint32_t value)
{
    if (index < 0x10u) {
        uint8_t *entry = (uint8_t *)base + index * 0x488u;
        if (entry != 0)
            *(uint32_t *)(entry + 0x478) = value;
    }
}
