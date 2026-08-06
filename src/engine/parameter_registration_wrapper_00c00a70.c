#include <stdint.h>
void ParameterRegistrar_Init_001EB95C(void *storage,
                                      uint32_t value1,
                                      uint32_t value2,
                                      uint8_t mode);
void ParameterRegistrar_Finalize_001EB9BC(void *storage);
void ParameterRegistration_Apply_006D7CB4(void *target, void *storage);
__attribute__((noinline)) uint32_t ParameterRegistration_Wrapper_00C00A70(void *object,
                                                 uint32_t value1,
                                                 uint32_t value2,
                                                 uint8_t mode)
{
    uint8_t storage[16];
    ParameterRegistrar_Init_001EB95C(storage, value1, value2, mode);
    ParameterRegistration_Apply_006D7CB4(*(void **)((uint8_t *)object + 4),
                                         storage);
    ParameterRegistrar_Finalize_001EB9BC(storage);
    return 1u;
}
