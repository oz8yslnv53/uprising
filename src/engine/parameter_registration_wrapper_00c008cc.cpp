#include <stdint.h>
extern "C" void ParameterRegistrar_Init_001EB95C(
    uint32_t *context, uint32_t value1, uint32_t value2, uint8_t mode);
extern "C" void ParameterRegistration_Apply_0063D82C(
    void *target, uint32_t *context);
extern "C" void *ParameterRegistrar_Finalize_001EB9BC(uint32_t *context);
extern "C" __attribute__((noinline)) int ParameterRegistration_Wrapper_00C008CC(
    void *object, uint32_t value1, uint32_t value2, uint8_t mode) {
    uint32_t context[4];
    ParameterRegistrar_Init_001EB95C(context, value1, value2, mode);
    ParameterRegistration_Apply_0063D82C(
        *(void **)((uint8_t *)object + 4), context);
    ParameterRegistrar_Finalize_001EB9BC(context);
    return 1;
}
