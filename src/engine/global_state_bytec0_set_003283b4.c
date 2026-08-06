#include <stdint.h>
extern void *Engine_GlobalStateGet_0039FA98(void);
__attribute__((noinline)) void Engine_GlobalStateByteC0Set_003283B4(uint8_t value)
{
    uint8_t *state = (uint8_t *)Engine_GlobalStateGet_0039FA98();
    state[0xc0] = value;
}
