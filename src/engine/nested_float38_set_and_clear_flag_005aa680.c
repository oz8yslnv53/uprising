#include <stdint.h>
__attribute__((noinline)) void Engine_NestedFloat38SetAndClearFlag_005AA680(void *object, float value)
{
    void *nested = *(void **)((char *)object + 0x9c);
    if (nested != 0 && *(float *)((char *)nested + 0x38) != value) {
        *(float *)((char *)nested + 0x38) = value;
        *(unsigned char *)((uintptr_t)0x13154 + (uintptr_t)nested) = 0;
    }
}
