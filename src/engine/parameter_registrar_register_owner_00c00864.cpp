#include <cstdint>
extern "C" void ParameterRegistrar_Init_001EB95C(
    void* context, std::uint32_t value1, std::uint32_t value2,
    std::uint8_t mode);
extern "C" void ParameterRegistrar_Apply_006385B4(
    void* owner, void* context);
extern "C" void ParameterRegistrar_Finalize_001EB9BC(void* context);
extern "C" __attribute__((noinline)) int ParameterRegistrar_RegisterOwner_00C00864(
    void* wrapper, std::uint32_t value1, std::uint32_t value2,
    std::uint8_t mode)
{
    std::uint8_t context[16];
    ParameterRegistrar_Init_001EB95C(context, value1, value2, mode);
    ParameterRegistrar_Apply_006385B4(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4),
        context);
    ParameterRegistrar_Finalize_001EB9BC(context);
    return 1;
}
