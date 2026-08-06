#include <stdint.h>
extern void Startup_CheckSecondaryServiceResult_00101FA4(void);
__attribute__((noinline)) void Startup_ConditionalByteReset_00101040(void)
{
    volatile uint8_t *flag = (volatile uint8_t *)(uintptr_t)0x00d4d77cu;
    if (*flag != 0u) {
        Startup_CheckSecondaryServiceResult_00101FA4();
        *flag = 0u;
    }
}
