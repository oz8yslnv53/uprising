#include <stdint.h>
__attribute__((noinline)) void Engine_NestedFloatAt6CSetIfPresent_005AA660(uint8_t *object, float value) {
    uint8_t *nested = *(uint8_t **)(object + 0x9c);
    if (nested != 0) {
        *(float *)(nested + 0x6c) = value;
    }
}
__attribute__((noinline)) void Engine_NestedFloatAt60SetIfPresent_005AA6B0(uint8_t *object, float value) {
    uint8_t *nested = *(uint8_t **)(object + 0x9c);
    if (nested != 0) {
        *(float *)(nested + 0x60) = value;
    }
}
__attribute__((noinline)) void
Engine_NestedFloatAt58SetIfPresent_0075BE4C(uint8_t *object, float value)
{
    uint8_t *nested = *(uint8_t **)(object + 0x9c);
    if (nested != 0)
        *(float *)(nested + 0x58) = value;
}
