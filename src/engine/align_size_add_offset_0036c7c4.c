#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_AlignSizeAddOffset_0036C7C4(uint32_t count, uint32_t offset)
{
    uint32_t size = offset + (count << 4) + 0x37u;
    return size & 0xffffffe0u;
}
