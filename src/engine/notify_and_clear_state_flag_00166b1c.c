#include <stdint.h>
extern void FUN_00187B20(void);
__attribute__((noinline)) void Engine_NotifyAndClearStateFlag_00166B1C(
    uint8_t *object)
{
    if (object[0x1e8] != 0) {
        object[0x1eb] = 1;
        FUN_00187B20();
        object[0x1e8] = 0;
    }
}
