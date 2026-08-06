#include <stdint.h>
extern int Engine_ResolveValue_0025A4F4(int value);
__attribute__((noinline)) int Engine_ResultClamp19_00205DD8(void *object)
{
    int result = Engine_ResolveValue_0025A4F4(
        *(int *)((uint8_t *)object + 0x38u));
    if (result < 0)
        result = 0x13;
    return result;
}
