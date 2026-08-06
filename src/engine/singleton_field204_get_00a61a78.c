#include <stdint.h>
extern void *GetEngineSingleton_003B6CF0(void);
__attribute__((noinline)) void *Engine_SingletonField16604Get_00A61A78(void)
{
    void **slot = (void **)(uintptr_t)0x00D6365Cu;
    if (*slot == 0)
        *slot = GetEngineSingleton_003B6CF0();
    return (uint8_t *)*slot + 0x16604u;
}
