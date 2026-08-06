#include <stdint.h>
extern void *Engine_SharedResourceSingleton_Initialize_0010AFF0(void);
__attribute__((noinline)) void Engine_LazySingletonField40Set_00101AEC(void *value)
{
    void **slot = (void **)(uintptr_t)0x00d6371cu;
    void *object = *slot;
    if (object == 0) {
        object = Engine_SharedResourceSingleton_Initialize_0010AFF0();
        *slot = object;
    }
    *(void **)((uint8_t *)object + 0x40) = value;
}
