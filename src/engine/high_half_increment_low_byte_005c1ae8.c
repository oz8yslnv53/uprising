#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_HighHalfIncrementLowByte_005C1AE8(uint32_t value) {
    return ((value >> 16) + 1u) & 0xffu;
}
