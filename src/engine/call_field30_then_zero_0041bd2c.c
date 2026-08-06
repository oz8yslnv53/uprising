#include <stdint.h>
void Engine_Routine_004B5E7C(uint32_t value);
__attribute__((noinline)) uint32_t Engine_CallField30ThenZero_0041BD2C(void *record)
{
    Engine_Routine_004B5E7C(*(uint32_t *)((unsigned char *)record + 0x30));
    return 0;
}
