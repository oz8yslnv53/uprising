#include <stdint.h>
void *Engine_Routine_00BAB3C0(void);
__attribute__((noinline)) void Engine_SingletonClearFields24And28_0091DB14(void)
{
    unsigned char *record = (unsigned char *)Engine_Routine_00BAB3C0();
    *(uint32_t *)(record + 0x24) = 0;
    *(uint32_t *)(record + 0x28) = 0;
}
