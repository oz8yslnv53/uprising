#include <stdint.h>
extern void Engine_InvokeWithMode_009A25BC(void *argument, unsigned mode);
__attribute__((noinline)) int Engine_InvokeOneClearFlag_00613C94(
    void *object, void *argument)
{
    Engine_InvokeWithMode_009A25BC(argument, 1u);
    *(uint8_t *)((uint8_t *)object + 4u) = 0u;
    return 0;
}
