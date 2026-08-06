#include <stdint.h>
extern float TrigKernel_00474934(float value);
__attribute__((noinline)) void Engine_StoreAbsTrigResult_0045DFE4(void *object,
                                                                  float value)
{
    *(float *)((uint8_t *)object + 0x8Cu) = __builtin_fabsf(TrigKernel_00474934(value));
}
