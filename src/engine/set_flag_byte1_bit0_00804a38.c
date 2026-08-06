#include <stdint.h>
__attribute__((noinline)) void Engine_SetFlagByte1Bit0_00804A38(uint8_t *object)
{
    object[1] = (uint8_t)(object[1] | 1U);
}
