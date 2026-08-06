#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_LowIndexBitMask_00612040(uint32_t index) {
    if (index >= 8u) {
        return 0;
    }
    return (1u << index) & 0xffu;
}
