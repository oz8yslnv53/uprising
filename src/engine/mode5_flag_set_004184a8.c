#include <stdint.h>
extern void *Engine_LazySingletonGetter_0054EFA8(void);
extern void FUN_004AFA14(void *table, int group, int index, uint32_t value);
extern void *Engine_Mode5FlagSingleton_004184E4;
__attribute__((noinline)) void Engine_Mode5Flag_Set_004184A8(uint32_t value)
{
    uint8_t *singleton = (uint8_t *)Engine_Mode5FlagSingleton_004184E4;
    if (singleton == 0) {
        singleton = (uint8_t *)Engine_LazySingletonGetter_0054EFA8();
        Engine_Mode5FlagSingleton_004184E4 = singleton;
    }
    FUN_004AFA14(singleton + 0xfacu, 5, 5, value);
}
