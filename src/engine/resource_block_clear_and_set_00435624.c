#include <stdint.h>
extern void MemoryZeroEnd_003DC5D0(void *destination, unsigned int size);
__attribute__((noinline)) void ResourceBlock_ClearAndSet_00435624(void *record,
                                                                   uint32_t value)
{
    uint8_t *base = (uint8_t *)record;
    MemoryZeroEnd_003DC5D0(base + 0x184u, 0x100u);
    MemoryZeroEnd_003DC5D0(base + 0x184u, 0x100u);
    MemoryZeroEnd_003DC5D0(base, 0x180u);
    *(uint32_t *)(base + 0x180u) = value;
    *(uint32_t *)(base + 0x284u) = 0u;
}
