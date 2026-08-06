// 0010871C: store the argument in the retained global pointer at D4E588.
#include <stdint.h>
__attribute__((noinline)) void Engine_GlobalPointerSet_0010871C(void *value)
{
    *(volatile void **)(uintptr_t)0x00D4E588u = value;
}
