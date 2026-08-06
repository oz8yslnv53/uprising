// 00B49868: return the embedded parameter-string object or its default.
#include <stdint.h>
typedef void *(*ResourceObject_FirstFieldFn)(void *object);
__attribute__((noinline)) void *ResourceObject_GetParameterString_00B49868(
    void *object)
{
    void *value = *(void **)((uint8_t *)object + 0x88);
    if (value == 0)
        return (void *)(uintptr_t)0x00CB11D0u;
    return (*(ResourceObject_FirstFieldFn *)(*(void **)value + 0x10))(value);
}
