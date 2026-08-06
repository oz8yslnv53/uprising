#include <stdint.h>
extern uint32_t *FUN_00840510(void);
extern uint8_t DAT_008B19C4[];
__attribute__((noinline)) void Engine_GlobalField0Set_008B19B0(void)
{
    uint32_t *target = FUN_00840510();
    uint32_t value = (uint32_t)DAT_008B19C4;
    *target = value;
}
