#include <stdint.h>
int Engine_ConfigUserReady_0031D4BC(void);
__attribute__((noinline)) uint32_t Engine_QueryReady_0036518C(void)
{
    return Engine_ConfigUserReady_0031D4BC() != 0;
}
