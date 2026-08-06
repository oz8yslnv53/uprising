#include <stdint.h>
extern void Runtime_InitializeResource_00713660(void *object,
                                                  unsigned int arg1,
                                                  unsigned int arg2,
                                                  unsigned int arg3,
                                                  void *stack_arg);
__attribute__((noinline)) void *ResourceOwner_InitializeReturnField_0070D018(
    void *object, unsigned int arg1, unsigned int arg2, unsigned int arg3,
    void *stack_arg)
{
    Runtime_InitializeResource_00713660(object, arg1, arg2, arg3, stack_arg);
    return (uint8_t *)object + 0x24bc;
}
