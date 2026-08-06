#include <stdint.h>
__attribute__((noinline)) void Engine_NestedValueReadySet_002A07D4(uint8_t *object, uint32_t value) {
    uint32_t *nested = *(uint32_t **)(object + 0x0c);
    nested[0x10 / 4] = value;
    object[0x10] = 1;
}
