#include <cstdint>
extern "C" void ParameterRegistrar_Init_001EB95C(std::uint32_t* context);
extern "C" void ParameterRegistrar_Finalize_001EB9BC(std::uint32_t* context);
extern "C" void ParameterRegistrar_Register_0067D5A4(void* target,
                                                       std::uint32_t* context);
extern "C" __attribute__((noinline)) int ParameterRegistration_Wrapper_00C03744(void* object) {
    std::uint32_t context[4];
    ParameterRegistrar_Init_001EB95C(context);
    ParameterRegistrar_Register_0067D5A4(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(object) + 4),
        context);
    ParameterRegistrar_Finalize_001EB9BC(context);
    return 1;
}
