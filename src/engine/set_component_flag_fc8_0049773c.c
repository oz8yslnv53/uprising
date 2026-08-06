#include <stdint.h>
void *ResolveCachedComponent_1EC(void *object);
__attribute__((noinline)) void Engine_SetComponentFlagFC8_0049773C(
    void *object)
{
    uint8_t *component = (uint8_t *)ResolveCachedComponent_1EC(object);
    if (component != 0) {
        uint8_t *state = *(uint8_t **)(component + 0x2c);
        if (state != 0)
            state[0xfc8] = 1;
    }
}
