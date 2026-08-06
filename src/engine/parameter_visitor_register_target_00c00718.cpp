// Kid Icarus: Uprising (3DS, JP Rev 1) reconstruction.
#include <cstdint>
extern "C" void ParameterRegistrar_Init_001EB95C(
    void* registrar, unsigned int value1, unsigned int value2, unsigned char mode);
extern "C" void ParameterRegistrar_Finalize_001EB9BC(void* registrar);
extern "C" void ParameterVisitor_RegisterTarget_006079E4(void* object, void* registrar);
extern "C" __attribute__((noinline)) int ParameterVisitor_RegisterTarget_00C00718(
    void* wrapper, unsigned int value1, unsigned int value2, unsigned char mode)
{
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar, value1, value2, mode);
    ParameterVisitor_RegisterTarget_006079E4(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4), registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
