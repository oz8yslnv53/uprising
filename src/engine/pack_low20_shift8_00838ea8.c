#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_PackLow20Shift8_00838EA8(uint32_t value,
                                                                    uint32_t suffix)
{
    return suffix | ((value & ~0x00f00000U) << 8);
}
