#include <stdint.h>
__attribute__((noinline)) void Engine_FloatFieldUpdateClearFlags_004A402C(uint8_t *object, float value) {
    if (*(float *)(object + 0x40) != value) {
        *(volatile float *)(object + 0x40) = value;
        *(volatile uint32_t *)(object + 0x6c) &= ~0x5cu;
    }
}
