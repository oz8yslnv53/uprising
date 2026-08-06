#include <stdint.h>
extern void Startup_CheckServiceResult_00101F68(void);
extern void FUN_0010CF64(void);
__attribute__((noinline)) void Startup_ConditionalByteSet_00101068(void)
{
    volatile uint8_t *flag = (volatile uint8_t *)(uintptr_t)0x00d4d77cu;
    if (*flag == 0u) {
        Startup_CheckServiceResult_00101F68();
        FUN_0010CF64();
        *flag = 1u;
    }
}
