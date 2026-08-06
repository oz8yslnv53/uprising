#include <stdint.h>
typedef int (*ResourceHandleSlot14)(void *object, uint32_t mask);
__attribute__((noinline)) int ResourceHandle_InvokeSlot14_0038EEA8(void *object, uint32_t mask) {
    if (object == 0)
        return (int)(uintptr_t)0xbce046e0u;
    return ((ResourceHandleSlot14)(*(uintptr_t *)(*(uintptr_t *)object +
                                                  0x14u)))(object, mask);
}
