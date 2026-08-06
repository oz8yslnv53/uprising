#include <stdint.h>
extern void ParameterRegistrar_Init_001EB95C(void *registrar);
extern void ParameterRegistrar_Finalize_001EB9BC(void *registrar);
extern void FUN_0060EE90(void *value, void *registrar);
__attribute__((noinline)) int ParameterRegistration_Wrapper_00C00780(void *context, uint32_t unused1,
                                           uint32_t unused2, uint8_t unused3)
{
    uint8_t registrar[16];
    (void)unused1;
    (void)unused2;
    (void)unused3;
    ParameterRegistrar_Init_001EB95C(registrar);
    FUN_0060EE90(*(void **)((uint8_t *)context + 4u), registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
