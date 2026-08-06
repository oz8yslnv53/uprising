#include <stdint.h>
extern void *Engine_LazySingletonGetter_00422CC8(void);
__attribute__((noinline)) int Engine_SingletonField2B4E8IsZero_0033FFC4(void)
{
    void **slot = (void **)(uintptr_t)0x00D6364Cu;
    void *singleton = *slot;
    if (singleton == 0) {
        singleton = Engine_LazySingletonGetter_00422CC8();
        *slot = singleton;
    }
    return *(uint32_t *)((uint8_t *)singleton + 0x2B4E8u) == 0u;
}
