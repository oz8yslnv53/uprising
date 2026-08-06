#include <stdint.h>
__attribute__((noinline)) void
Engine_CounterIncrementCap9_001AB7B4(void *object)
{
    int32_t value = *(int32_t *)((char *)object + 8);
    if (value >= 9)
        value = 9;
    else
        value++;
    *(int32_t *)((char *)object + 8) = value;
}
