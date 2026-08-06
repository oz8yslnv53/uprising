#include <stdint.h>
extern void ParameterRegistrar_Init_001EB95C(void *context,
                                             uint32_t value1,
                                             uint32_t value2,
                                             uint8_t mode);
extern void ParameterRegistrar_Finalize_006C4278(void *object,
                                                  void *registrar);
extern void *ParameterRegistrar_Finalize_001EB9BC(void *context);
__attribute__((noinline)) int ParameterRegistration_Wrapper_00C00A38(
    void *object, uint32_t value1, uint32_t value2, uint8_t mode)
{
    uint8_t context[16];
    ParameterRegistrar_Init_001EB95C(context, value1, value2, mode);
    ParameterRegistrar_Finalize_006C4278(
        (uint8_t *)(*(void **)((uint8_t *)object + 4u)) + 0x14u, context);
    ParameterRegistrar_Finalize_001EB9BC(context);
    return 1;
}
