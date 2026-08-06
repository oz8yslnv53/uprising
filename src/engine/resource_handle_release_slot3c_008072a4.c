#include <stdint.h>
typedef void (*ReleaseFunction)(void *object);
__attribute__((noinline)) void ResourceHandle_ReleaseSlot3C_008072A4(void *owner)
{
    uint8_t *bytes = (uint8_t *)owner;
    void *object = *(void **)(bytes + 0x3c);
    if (object != 0) {
        void **vtable = *(void ***)object;
        ((ReleaseFunction)vtable[1])(object);
    }
    *(void **)(bytes + 0x3c) = 0;
}
