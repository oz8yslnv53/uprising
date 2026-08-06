#include <stdint.h>
typedef void (*NestedVirtual2C_0049B5D4)(void *object);
__attribute__((noinline)) void Engine_InvokeNestedVirtual2C_0049B5D4(
    void *container)
{
    void *nested = *(void **)((uint8_t *)container + 4);
    if (nested != 0) {
        void **vtable = *(void ***)nested;
        ((NestedVirtual2C_0049B5D4)vtable[0x2c / sizeof(void *)])(nested);
    }
}
