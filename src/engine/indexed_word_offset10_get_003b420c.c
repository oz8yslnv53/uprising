#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_IndexedWordOffset10Get_003B420C(const uint8_t *base,
                                                uint32_t index) {
    return *(const uint32_t *)(base + index * 4 + 0x10);
}
