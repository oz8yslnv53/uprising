#include <stdint.h>
__attribute__((noinline)) void Engine_GlobalContextByte6Set_0010E918(uint8_t value)
{
    uint8_t *context = (uint8_t *)(uintptr_t)0x00d4d498u;
    context[6] = value;
}
