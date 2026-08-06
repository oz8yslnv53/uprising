#include <stdint.h>
void *ResolveCachedComponent_1EC(void *object);
__attribute__((noinline)) void Engine_ClearComponentFlagC08_00497464(
    void *object)
{
    uint8_t *component = (uint8_t *)ResolveCachedComponent_1EC(object);
    if (component != 0) {
        uint8_t *state = *(uint8_t **)(component + 0x2c);
        if (state != 0)
            state[0xc08] = 0;
    }
}
