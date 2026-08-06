#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_NestedPointerOffset4Get_007270A8(const void *object) {
    const uint8_t *nested = *(const uint8_t * const *)object;
    return *(const uint32_t *)(nested + 0x04);
}
