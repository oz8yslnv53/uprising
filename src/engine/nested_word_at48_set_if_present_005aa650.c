#include <stdint.h>
__attribute__((noinline)) void Engine_NestedWordAt48SetIfPresent_005AA650(uint8_t *object,
                                                uint32_t value) {
    uint8_t *nested = *(uint8_t **)(object + 0x9c);
    if (nested != 0) {
        *(uint32_t *)(nested + 0x48) = value;
    }
}
