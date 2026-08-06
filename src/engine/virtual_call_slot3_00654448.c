#include <stdint.h>
typedef void (*VirtualCall)(void *object);
void __attribute__((noinline)) Engine_VirtualCallSlot3_00654448(void *object) {
    uint8_t *vtable = *(uint8_t **)object;
    VirtualCall call = (VirtualCall)*(uintptr_t *)(vtable + 0x0C);
    call(object);
}
