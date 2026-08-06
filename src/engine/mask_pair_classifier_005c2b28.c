#include <stdint.h>
__attribute__((noinline)) uint32_t MaskPair_ClassifyOverlap_005C2B28(const uint32_t *left,
                                           const uint32_t *right)
{
    uint32_t value = left[0];
    if ((right[0] & value) != 0)
        return 1;
    if ((right[1] & value) != 0)
        return 2;
    return 0;
}
