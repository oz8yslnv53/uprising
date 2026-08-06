#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_NestedWordAt30Get_00505120(const uint8_t *object) {
    const uint8_t *nested = *(const uint8_t * const *)(object + 0x04);
    return *(const uint32_t *)(nested + 0x30);
}
