#include <stdint.h>
extern void *ResolveCachedComponent_1EC(void *object);
extern void FUN_00363380(void *object, int mode);
__attribute__((noinline)) void FUN_00A2335C(void *object, const uint32_t *values)
{
    void *component = ResolveCachedComponent_1EC(object);
    if (component != 0 && *(void **)((uint8_t *)component + 0x28) != 0) {
        void *state = *(void **)((uint8_t *)component + 0x28);
        FUN_00363380(state, 1);
        *(uint32_t *)((uint8_t *)state + 0xac) = values[0];
        *(uint32_t *)((uint8_t *)state + 0xb0) = values[1];
        *(uint32_t *)((uint8_t *)state + 0xb4) = values[2];
    }
}
