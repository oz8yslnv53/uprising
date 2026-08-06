#include <stdint.h>
__attribute__((noinline)) int32_t Engine_OrdinalReverse4_003095C8(int32_t value)
{
    if (value == 3)
        return 0;
    if (value == 2)
        return 1;
    if (value == 1)
        return 2;
    if (value == 0)
        return 3;
    return -1;
}
