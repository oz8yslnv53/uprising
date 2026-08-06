#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_BoundedIndexedFieldC0_00319358(const uint8_t *base,
                                               uint32_t index)
{
    if (index >= 100u) {
        return 0xffffffffu;
    }
    return *(const uint32_t *)(base + index * 0x4c8u + 0xc0u);
}
