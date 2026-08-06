#include <stdint.h>
__attribute__((noinline)) void Engine_ConditionalField8DCStore_005B23B8(uint8_t *object,
                                               uint32_t value) {
    uint8_t *nested = *(uint8_t **)(object + 0x140);
    if (nested != 0)
        *(uint32_t *)(nested + 0x8dc) = value;
}
