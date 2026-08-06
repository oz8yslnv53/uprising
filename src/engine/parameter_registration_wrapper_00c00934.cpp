#include <stdint.h>
extern "C" void ParameterRegistrar_Init_001EB95C(
    uint32_t *context, uint32_t value1, uint32_t value2, uint8_t mode);
extern "C" void RegisterGameplayParameterGroups_00653F44(
    void *parameter_object, void *registrar);
extern "C" void *ParameterRegistrar_Finalize_001EB9BC(uint32_t *context);
extern "C" __attribute__((noinline)) int ParameterGameplayGroups_Visit_00C00934(
    void *object, uint32_t value1, uint32_t value2, uint8_t mode) {
    uint32_t context[4];
    ParameterRegistrar_Init_001EB95C(context, value1, value2, mode);
    RegisterGameplayParameterGroups_00653F44(
        *(void **)((uint8_t *)object + 4), context);
    ParameterRegistrar_Finalize_001EB9BC(context);
    return 1;
}
