#include <stdint.h>
__attribute__((noinline)) void Engine_NestedField34SetAndClearFlag_005AA6C0(void *object,
                                                   unsigned int value)
{
    void *nested = *(void **)((char *)object + 0x9c);
    if (nested != 0 && *(unsigned int *)((char *)nested + 0x34) != value) {
        *(unsigned int *)((char *)nested + 0x34) = value;
        *(unsigned char *)((uintptr_t)0x1313c + (uintptr_t)nested) = 0;
    }
}
