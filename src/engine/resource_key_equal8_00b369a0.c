#include <stdint.h>
extern int MemoryCompare_003960A8(const void *left, const void *right,
                                  uint32_t size);
__attribute__((noinline)) int Engine_ResourceKeyEqual8_00B369A0(const void *first, const void *second)
{
    if (second == 0)
        return 0;
    return MemoryCompare_003960A8(second, first, 8u) == 0;
}
