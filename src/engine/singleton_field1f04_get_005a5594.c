#include <stdint.h>
extern void *Engine_LazySingletonGetter_00422CC8(void);
__attribute__((noinline)) uint32_t Engine_SingletonField1F04_Get_005A5594(void)
{
    void **cache = (void **)(uintptr_t)0x00D6364Cu;
    void *object = *cache;
    if (object == 0) {
        object = Engine_LazySingletonGetter_00422CC8();
        *cache = object;
    }
    return *(uint32_t *)((uint8_t *)object + 0x1F04u);
}
