#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_StatusTableWordGet_006E7DBC(
    const uint8_t *base, int index) {
    return *(const uint32_t *)(base + (index << 2) + 0x1e7c4);
}
