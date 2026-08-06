#include <stdint.h>
__attribute__((noinline)) void Engine_CopySixVfpLanes_009A5EF4(
    void *record, float value0, float value1, float value2,
    float value3, float value4, float value5)
{
    float *destination = (float *)((uint8_t *)record + 0x0c);
    destination[0] = value0;
    destination[1] = value1;
    destination[2] = value2;
    destination[3] = value3;
    destination[4] = value4;
    destination[5] = value5;
}
