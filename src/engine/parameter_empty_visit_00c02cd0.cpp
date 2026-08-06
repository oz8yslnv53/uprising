#include <cstdint>
extern "C" void ParameterRegistrar_Init_001EB95C(void* registrar);
extern "C" void ParameterRegistrar_Finalize_001EB9BC(void* registrar);
extern "C" __attribute__((noinline)) int
ParameterVisitor_Empty_00C02CD0(void* wrapper)
{
    std::uint8_t registrar[16];
    (void)wrapper;
    ParameterRegistrar_Init_001EB95C(registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
