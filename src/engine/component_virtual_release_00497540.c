#include <stdint.h>
void *ResolveCachedComponent_1EC(void *object);
typedef void (*ComponentReleaseFn_00497540)(void *object);
__attribute__((noinline)) void Engine_ComponentVirtualRelease_00497540(
    void *object)
{
    uint8_t *component = (uint8_t *)ResolveCachedComponent_1EC(object);
    if (component != 0) {
        void *state = *(void **)(component + 0x30);
        if (state != 0) {
            void **vtable = *(void ***)state;
            ComponentReleaseFn_00497540 release =
                (ComponentReleaseFn_00497540)vtable[0x44 / sizeof(void *)];
            release(state);
        }
    }
}
