#include <stdint.h>
__attribute__((noinline)) void Engine_GlobalRecordPublish_0034DCEC(unsigned int value)
{
    volatile uint8_t *state = (volatile uint8_t *)(uintptr_t)0x00D5DD54u;
    *(volatile uint32_t *)(state + 0x0c) = value;
    state[2] = 1;
}
