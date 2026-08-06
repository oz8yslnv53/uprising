#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_Field58IndexedWordGet_00890780(
    const uint8_t *object, int index) {
    const uint32_t *table =
        *(const uint32_t * const *)(object + 0x58);
    return table[index];
}
