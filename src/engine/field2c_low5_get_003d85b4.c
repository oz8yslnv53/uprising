#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_Field2CLow5Get_003D85B4(const uint8_t *object) {
    return *(const uint32_t *)(object + 0x2c) & 0x1fu;
}
