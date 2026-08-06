#include <stdint.h>
__attribute__((noinline)) void *Engine_Field9COffset28OrGlobal_00A30C5C(void *object)
{
    void *value = *(void **)((unsigned char *)object + 0x9c);
    return value != 0 ? (void *)((unsigned char *)value + 0x28)
                      : (void *)(uintptr_t)0x00dc249cu;
}
