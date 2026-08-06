#include <stdint.h>
typedef void (*GlobalObjectVirtualCall8C)(void *object);
__attribute__((noinline)) void Global_ObjectVirtualCall8C_00369440(void)
{
    void *object = *(void **)(uintptr_t)0x00D4A2A8u;
    if (object != 0) {
        void **vtable = *(void ***)object;
        ((GlobalObjectVirtualCall8C)vtable[0x8c / sizeof(void *)])(object);
    }
}
