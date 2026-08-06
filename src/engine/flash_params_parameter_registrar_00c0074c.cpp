#include <stdint.h>
extern void ParameterRegistrar_Init_001EB95C(void *context, uint32_t value1,
                                               uint32_t value2, uint8_t mode);
extern void FlashParams_Register_0060972C(uint32_t target, void *context);
extern void *ParameterRegistrar_Finalize_001EB9BC(void *context);
__attribute__((noinline)) int FlashParams_ParameterRegistrar_00C0074C(
    void *object, uint32_t value1, uint32_t value2, uint8_t mode)
{
    uint8_t context[16];
    ParameterRegistrar_Init_001EB95C(context, value1, value2, mode);
    FlashParams_Register_0060972C(*(uint32_t *)((uint8_t *)object + 4u),
                                  context);
    ParameterRegistrar_Finalize_001EB9BC(context);
    return 1;
}
