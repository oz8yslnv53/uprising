#include <stdint.h>
__attribute__((noinline)) void Engine_StoreModeIfAtMost2_009FB700(uint8_t *object, int32_t mode) {
    if (mode <= 2)
        *(int32_t *)(object + 0x54) = mode;
}
