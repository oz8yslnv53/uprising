#include <stdint.h>
uint8_t ThreadProcessStatus_Mode_001B0A64(void)
{
    uint8_t *state = *(uint8_t **)(uintptr_t)(0x00D5DE08u + 0x0Cu);
    return state[8];
}
