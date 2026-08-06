#include <stdint.h>
typedef void *(*Engine_VirtualUpdate_00B406A8)(void *object);
__attribute__((noinline)) float Engine_VirtualUpdateThenGetFloat_00B406A8(void *object) {
    uint8_t *component =
        *(uint8_t **)((uint8_t *)object + 0x290u);
    Engine_VirtualUpdate_00B406A8 update =
        (Engine_VirtualUpdate_00B406A8)(*(uintptr_t *)
            ((uint8_t *)(*(uintptr_t *)component) + 0x14u));
    uint8_t *result = (uint8_t *)update(component);
    return *(float *)(result + 0x4u);
}
