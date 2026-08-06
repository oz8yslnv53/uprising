#include <stdint.h>
__attribute__((noinline)) void Engine_SetValueIfBelow3_003199FC(uint32_t *target, uint32_t value)
{
    if (value < 3u)
        *target = value;
}
