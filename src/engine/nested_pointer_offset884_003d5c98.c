#include <stdint.h>
__attribute__((noinline)) uint8_t *Engine_NestedPointerOffset884_003D5C98(const uint8_t *object) {
    uint8_t *pointer = *(uint8_t * const *)(object + 0x34);
    pointer += 0x800;
    pointer += 0x84;
    return pointer;
}
