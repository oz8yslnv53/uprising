#include <stdint.h>
int Engine_StatusModeIsType5(void);
__attribute__((noinline)) void
Engine_IncrementModeCounterUnlessType5_00505B58(uint8_t *object)
{
    if (Engine_StatusModeIsType5() == 0)
        ++*(uint32_t *)(object + 0x2b0);
}
