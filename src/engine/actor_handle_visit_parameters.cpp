#include <cstdint>
extern "C" void ParameterRegistrar_Init_001EB95C(void* registrar);
extern "C" void ParameterRegistrar_Finalize_001EB9BC(void* registrar);
extern "C" void ActorHandle_RegisterParameters_00A53630(
    void* value, void* registrar);
extern "C" __attribute__((noinline)) int ActorHandle_VisitParameters_00C050C8(
    void* wrapper) {
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    ActorHandle_RegisterParameters_00A53630(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4),
        registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
