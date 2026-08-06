#include <stdint.h>
extern void *Engine_LazySingletonGetter_0054EFA8(void);
__attribute__((noinline)) int Engine_SingletonSignedByte1ECA9_0074C4DC(void)
{
    void **cache = (void **)(uintptr_t)0x00D63578u;
    void *object = *cache;
    if (object == 0) {
        object = Engine_LazySingletonGetter_0054EFA8();
        *cache = object;
    }
    return *(int8_t *)((uint8_t *)object + 0x1ECA9);
}
