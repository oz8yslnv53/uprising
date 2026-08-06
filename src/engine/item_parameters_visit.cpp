#include <cstdint>
extern "C" void ParameterRegistrar_Init_001EB95C(void* registrar);
extern "C" void ParameterRegistrar_Finalize_001EB9BC(void* registrar);
extern "C" void ItemParameters_RegisterParameters_00808E9C(
    void* value, void* registrar);
extern "C" __attribute__((noinline)) int ItemParameters_VisitParameters_00C01A90(void* wrapper) {
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    ItemParameters_RegisterParameters_00808E9C(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4),
        registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
