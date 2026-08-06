#include <cstdint>
struct FloatParameterDescriptor {
    const void* type_data;
    const char* name;
    const void* class_data;
    void* value;
    float default_value;
};
typedef char kiu_sa_center_radius_register_parameters_1[(sizeof(FloatParameterDescriptor) == 0x14) ? 1 : -1] __attribute__((unused));
extern "C" void ParameterDescriptor_BuildFloat_00BACDCC(
    void* descriptor, const char* name, void* value);
extern "C" const std::uint8_t gCenterParameterTypeData_00D171BC[];
extern "C" const std::uint8_t gCenterParameterClassData_00D1A62C[];
extern "C" const std::uint8_t gPositionParameterTypeData_00D16D8C[];
extern "C" const std::uint8_t gPositionParameterClassData_00D1A1EC[];
extern "C" const std::uint8_t gCenterRadiusKindTypeData_00D17A1C[];
extern "C" const std::uint8_t gCenterRadiusKindClassData_00D1B38C[];
extern "C" const std::uint8_t gPositionRadiusKindTypeData_00D17B1C[];
extern "C" const std::uint8_t gPositionRadiusKindClassData_00D1B5BC[];
extern "C" const std::uint8_t gDataIdKindTypeData_00D1797C[];
extern "C" const std::uint8_t gDataIdKindClassData_00D1B17C[];
extern "C" const std::uint8_t gDataIdTypeData_00D190EC[];
extern "C" const std::uint8_t gDataIdClassData_00D1D73C[];
extern "C" const std::uint8_t gIntervalParameterTypeData_00D18EEC[];
extern "C" const std::uint8_t gIntervalParameterClassData_00D1CC0C[];
extern "C" const std::uint8_t gBulletParamTypeData_00D1654C[];
extern "C" const std::uint8_t gBulletParamClassData_00D1962C[];
extern "C" const std::uint8_t gIdParameterTypeData_00D1688C[];
extern "C" const std::uint8_t gIdParameterClassData_00D19C4C[];
static void register_descriptor(void* registrar, const void* descriptor) {
    void** vtable = *reinterpret_cast<void***>(registrar);
    reinterpret_cast<void (*)(void*, const void*)>(vtable[2])(
        registrar, descriptor);
}
extern "C" const char kParameterName_center[];
extern "C" const char kParameterName_radius[];
extern "C" const char kParameterName_pos[];
extern "C" const char kParameterName_kind[];
extern "C" const char kParameterName_dataId[];
extern "C" const char kParameterName_interval[];
extern "C" const char kParameterName_left[];
extern "C" const char kParameterName_bottom[];
extern "C" const char kParameterName_right[];
extern "C" const char kParameterName_top[];
extern "C" const char kParameterName_bulletParam[];
extern "C" const char kParameterName_id[];
extern "C" const char kParameterName_ratio[];
extern "C" __attribute__((noinline)) void CenterRadius_RegisterParameters_006C2F3C(
    void* value, void* registrar) {
    std::uint8_t* fields = static_cast<std::uint8_t*>(value);
    union { std::uint32_t bits; float value; } nan = {0x7fc00000u};
    const FloatParameterDescriptor center = {
        gCenterParameterTypeData_00D171BC, kParameterName_center,
        gCenterParameterClassData_00D1A62C, fields + 4, nan.value,
    };
    register_descriptor(registrar, &center);
    std::uint8_t radius[0x14];
    ParameterDescriptor_BuildFloat_00BACDCC(radius, kParameterName_radius, fields);
    register_descriptor(registrar, radius);
    const float position_x = *reinterpret_cast<const float*>(fields + 4);
    if (position_x == position_x) {
        const FloatParameterDescriptor position = {
            gPositionParameterTypeData_00D16D8C, kParameterName_pos,
            gPositionParameterClassData_00D1A1EC, fields + 4, 0.0f,
        };
        register_descriptor(registrar, &position);
    }
}
extern "C" void PositionRadius_RegisterParameters_006C3038(
    void* value, void* registrar, float pos_default);
extern "C" void ParameterRegistrar_Init_001EB95C(void* registrar, ...);
extern "C" void ParameterRegistrar_Finalize_001EB9BC(void* registrar);
extern "C" __attribute__((noinline)) int CenterRadius_VisitParameters_00C0463C(void* wrapper) {
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    CenterRadius_RegisterParameters_006C2F3C(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4),
        registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
extern "C" __attribute__((noinline)) int PositionRadius_VisitParameters_00C04670(
    void* wrapper, float pos_default) {
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    PositionRadius_RegisterParameters_006C3038(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4),
        registrar, pos_default);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
extern "C" __attribute__((noinline)) int CenterRadiusKind_VisitParameters_00C04008(void* wrapper) {
    std::uint8_t* value = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(wrapper) + 4);
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    struct ByteParameterDescriptor {
        const void* type_data;
        const char* name;
        const void* class_data;
        void* value;
        std::uint8_t default_value;
        std::uint8_t padding[3];
    };
    typedef char kiu_sa_center_radius_register_parameters_2[(sizeof(ByteParameterDescriptor) == 0x14) ? 1 : -1] __attribute__((unused));
    const ByteParameterDescriptor kind = {
        gCenterRadiusKindTypeData_00D17A1C, kParameterName_kind,
        gCenterRadiusKindClassData_00D1B38C, value + 0xc, 0, {},
    };
    register_descriptor(registrar, &kind);
    if (value[0xc] == 0) {
        CenterRadius_RegisterParameters_006C2F3C(value + 0x10, registrar);
    } else if (value[0xc] == 1) {
        PositionRadius_RegisterParameters_006C3038(
            value + 0x10, registrar, 0.0f);
    }
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
extern "C" __attribute__((noinline)) int PositionRadiusKind_VisitParameters_00C04518(void* wrapper) {
    std::uint8_t* value = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(wrapper) + 4);
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    struct ByteParameterDescriptor {
        const void* type_data;
        const char* name;
        const void* class_data;
        void* value;
        std::uint8_t default_value;
        std::uint8_t padding[3];
    };
    const ByteParameterDescriptor kind = {
        gPositionRadiusKindTypeData_00D17B1C, kParameterName_kind,
        gPositionRadiusKindClassData_00D1B5BC, value, 0, {},
    };
    register_descriptor(registrar, &kind);
    union { std::uint32_t bits; float value; } nan = {0x7fc00000u};
    PositionRadius_RegisterParameters_006C3038(value + 4, registrar, nan.value);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
extern "C" void TemporaryLookupContext_Init_0091B9A8(void* storage);
extern "C" void* TemporaryLookupContext_Find_0091AD64(
    void* lookup, void* key, std::uint32_t flags);
extern "C" void TemporaryLookupContext_Destroy_0091B050(void* storage);
extern "C" __attribute__((noinline)) int PositionRadius_VisitWithContext_00C14610(
    void* wrapper, void* lookup, float pos_default, void* init_arg_a,
    void* init_arg_b) {
    std::uint8_t temporary[0x38];
    TemporaryLookupContext_Init_0091B9A8(temporary);
    std::uint8_t* bytes = static_cast<std::uint8_t*>(wrapper);
    void* selected = TemporaryLookupContext_Find_0091AD64(
        lookup, *reinterpret_cast<void**>(bytes + 4), 0);
    if (selected == 0) {
        selected = temporary;
    }
    std::uint8_t registrar[0x14];
    ParameterRegistrar_Init_001EB95C(registrar, selected, init_arg_a, init_arg_b);
    PositionRadius_RegisterParameters_006C3038(
        *reinterpret_cast<void**>(bytes + 0xc), registrar, pos_default);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    TemporaryLookupContext_Destroy_0091B050(temporary);
    return 1;
}
extern "C" __attribute__((noinline)) int PositionRadiusKind_VisitWithContext_00C13D64(
    void* wrapper, void* lookup, void* init_arg_a, void* init_arg_b) {
    std::uint8_t temporary[0x38];
    TemporaryLookupContext_Init_0091B9A8(temporary);
    std::uint8_t* bytes = static_cast<std::uint8_t*>(wrapper);
    void* selected = TemporaryLookupContext_Find_0091AD64(
        lookup, *reinterpret_cast<void**>(bytes + 4), 0);
    if (selected == 0) {
        selected = temporary;
    }
    std::uint8_t registrar[0x14];
    ParameterRegistrar_Init_001EB95C(registrar, selected, init_arg_a, init_arg_b);
    std::uint8_t* value = *reinterpret_cast<std::uint8_t**>(bytes + 0xc);
    struct ByteParameterDescriptor {
        const void* type_data;
        const char* name;
        const void* class_data;
        void* value;
        std::uint8_t default_value;
        std::uint8_t padding[3];
    };
    const ByteParameterDescriptor kind = {
        gPositionRadiusKindTypeData_00D17B1C, kParameterName_kind,
        gPositionRadiusKindClassData_00D1B5BC, value, 0, {},
    };
    register_descriptor(registrar, &kind);
    union { std::uint32_t bits; float value; } nan = {0x7fc00000u};
    PositionRadius_RegisterParameters_006C3038(value + 4, registrar, nan.value);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    TemporaryLookupContext_Destroy_0091B050(temporary);
    return 1;
}
extern "C" __attribute__((noinline)) void DataIdKindPositionRadius_RegisterParameters_00683E18(
    void* value, void* registrar) {
    std::uint8_t* fields = static_cast<std::uint8_t*>(value);
    struct ByteParameterDescriptor {
        const void* type_data;
        const char* name;
        const void* class_data;
        void* value;
        std::uint8_t default_value;
        std::uint8_t padding[3];
    };
    const ByteParameterDescriptor kind = {
        gDataIdKindTypeData_00D1797C, kParameterName_kind,
        gDataIdKindClassData_00D1B17C, fields + 0x10, 0, {},
    };
    const ByteParameterDescriptor data_id = {
        gDataIdTypeData_00D190EC, kParameterName_dataId, gDataIdClassData_00D1D73C,
        fields + 0xc, 0, {},
    };
    register_descriptor(registrar, &kind);
    register_descriptor(registrar, &data_id);
    union { std::uint32_t bits; float value; } nan = {0x7fc00000u};
    PositionRadius_RegisterParameters_006C3038(fields + 0x14, registrar,
                                                nan.value);
}
extern "C" __attribute__((noinline)) int DataIdKindPositionRadius_VisitParameters_00C039E8(
    void* wrapper) {
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    DataIdKindPositionRadius_RegisterParameters_00683E18(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4),
        registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
extern "C" __attribute__((noinline)) void Interval_RegisterParameters_006C2E14(
    void* value, void* registrar) {
    struct FloatParameterDescriptor {
        const void* type_data;
        const char* name;
        const void* class_data;
        void* value;
        float default_value;
    };
    typedef char kiu_sa_center_radius_register_parameters_3[(sizeof(FloatParameterDescriptor) == 0x14) ? 1 : -1] __attribute__((unused));
    const FloatParameterDescriptor interval = {
        gIntervalParameterTypeData_00D18EEC, kParameterName_interval,
        gIntervalParameterClassData_00D1CC0C,
        static_cast<std::uint8_t*>(value) + 0x44, 0.0f,
    };
    register_descriptor(registrar, &interval);
}
extern "C" __attribute__((noinline)) int Interval_VisitParameters_00C045D4(void* wrapper) {
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    Interval_RegisterParameters_006C2E14(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4),
        registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
extern "C" __attribute__((noinline)) void Bounds_RegisterParameters_006C2E74(
    void* value, void* registrar) {
    std::uint8_t* fields = static_cast<std::uint8_t*>(value);
    std::uint8_t left[0x14];
    std::uint8_t bottom[0x14];
    std::uint8_t right[0x14];
    std::uint8_t top[0x14];
    ParameterDescriptor_BuildFloat_00BACDCC(left, kParameterName_left, fields);
    register_descriptor(registrar, left);
    ParameterDescriptor_BuildFloat_00BACDCC(bottom, kParameterName_bottom, fields + 4);
    register_descriptor(registrar, bottom);
    ParameterDescriptor_BuildFloat_00BACDCC(right, kParameterName_right, fields + 8);
    register_descriptor(registrar, right);
    ParameterDescriptor_BuildFloat_00BACDCC(top, kParameterName_top, fields + 0xc);
    register_descriptor(registrar, top);
}
extern "C" __attribute__((noinline)) int Bounds_VisitParameters_00C04608(void* wrapper) {
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    Bounds_RegisterParameters_006C2E74(
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(wrapper) + 4),
        registrar);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
extern "C" __attribute__((noinline)) int BulletParam_VisitParameters_00C046E0(void* wrapper) {
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    const std::uint32_t descriptor[4] = {
        reinterpret_cast<std::uint32_t>(gBulletParamTypeData_00D1654C),
        reinterpret_cast<std::uint32_t>(kParameterName_bulletParam),
        reinterpret_cast<std::uint32_t>(gBulletParamClassData_00D1962C),
        reinterpret_cast<std::uint32_t>(*reinterpret_cast<void**>(
            static_cast<std::uint8_t*>(wrapper) + 4)),
    };
    register_descriptor(registrar, descriptor);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
extern "C" __attribute__((noinline)) int IdRatio_VisitParameters_00C0477C(void* wrapper) {
    std::uint8_t* value = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(wrapper) + 4);
    std::uint8_t registrar[16];
    ParameterRegistrar_Init_001EB95C(registrar);
    struct IdParameterDescriptor {
        const void* type_data;
        const char* name;
        const void* class_data;
        void* value;
        std::uint16_t default_value;
        std::uint16_t padding;
    };
    typedef char kiu_sa_center_radius_register_parameters_4[(sizeof(IdParameterDescriptor) == 0x14) ? 1 : -1] __attribute__((unused));
    const IdParameterDescriptor id = {
        gIdParameterTypeData_00D1688C, kParameterName_id, gIdParameterClassData_00D19C4C,
        value, 0, 0,
    };
    register_descriptor(registrar, &id);
    std::uint8_t ratio[0x14];
    ParameterDescriptor_BuildFloat_00BACDCC(ratio, kParameterName_ratio, value + 4);
    register_descriptor(registrar, ratio);
    ParameterRegistrar_Finalize_001EB9BC(registrar);
    return 1;
}
