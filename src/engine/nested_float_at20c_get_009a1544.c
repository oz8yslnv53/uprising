#include <stdint.h>
__attribute__((noinline)) float Engine_NestedFloatAt20CGet_009A1544(const uint8_t *object) {
    const uint8_t *nested = *(const uint8_t * const *)(object + 0x20);
    return *(const float *)(nested + 0x0c);
}
