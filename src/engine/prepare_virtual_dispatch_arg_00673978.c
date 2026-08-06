#include <stdint.h>
extern void Engine_PrepareField18_00672A6C(void *value);
typedef void *(*EngineVirtualMethodWithArg)(void *object, void *argument);
__attribute__((noinline)) void *Engine_PrepareVirtualDispatchArg_00673978(
    void *object, void *argument)
{
    uint8_t *bytes = (uint8_t *)object;
    void **vtable;
    EngineVirtualMethodWithArg method;
    Engine_PrepareField18_00672A6C(bytes + 0x18u);
    vtable = *(void ***)object;
    method = (EngineVirtualMethodWithArg)vtable[4];
    return method(object, argument);
}
