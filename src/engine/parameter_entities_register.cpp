#include <cstdint>
struct EntitiesParameterDescriptor {
    const void* class_data;
    const char* name;
    const void* type_data;
    void* value;
};
extern "C" const std::uint8_t gEntitiesParameterClassData_00D18B9C[];
extern "C" const std::uint8_t gEntitiesParameterTypeData_00D1C7AC[];
extern "C" __attribute__((noinline)) void ParameterEntities_Register_0091FED8(
    void* owner, void* registrar) {
    EntitiesParameterDescriptor descriptor = {
        gEntitiesParameterClassData_00D18B9C,
        "entities_",
        gEntitiesParameterTypeData_00D1C7AC,
        static_cast<std::uint8_t*>(owner) + 0x44,
    };
    void** vtable = *reinterpret_cast<void***>(registrar);
    reinterpret_cast<void (*)(void*, const EntitiesParameterDescriptor*)>(
        vtable[2])(registrar, &descriptor);
}
extern "C" void ParameterRegistrar_Init_001EB95C(void* registrar);
extern "C" void ParameterRegistrar_Finalize_001EB9BC(void* registrar);
extern "C" __attribute__((noinline)) int ParameterEntities_Visit_00C0516C(void* wrapper) {
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    ParameterEntities_Register_0091FED8(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4),
        registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
