#include <stdint.h>
extern void Engine_PrepareField4_007ECAA8(void *value);
typedef void *(*EngineVirtualMethod)(void *object);
__attribute__((noinline)) void *Engine_PrepareVirtualDispatch_00654470(
    void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    void **vtable;
    EngineVirtualMethod method;
    Engine_PrepareField4_007ECAA8(*(void **)(bytes + 4u));
    vtable = *(void ***)object;
    method = (EngineVirtualMethod)vtable[5];
    return method(object);
}
