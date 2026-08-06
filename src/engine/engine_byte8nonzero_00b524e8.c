#include <stdint.h>
__attribute__((noinline)) int Engine_Byte8Nonzero_00B524E8(const uint8_t *object) {
    return (*(const uint32_t *)(object + 8) & 0xffu) != 0;
}
