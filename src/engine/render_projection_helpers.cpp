#include <stdint.h>
struct Matrix4x4 {
    float values[16];
};
struct Matrix3x4 {
    float values[12];
};
extern "C" void SdkBreak_0013B2F0();
extern "C" void Matrix3x4_Copy_0044C0A0(
    void* destination, const void* source);
extern "C" float Projection_BuildFrustum_008D1028(
    void* projection, void* first_1a8, void* first_148,
    void* second_1a8, void* second_148, const void* matrix4x4,
    const void* matrix3x4, int mode, float value, float scale);
extern uint8_t g_RenderProjectionScaleOwner_00DF5A00[];
extern volatile uint8_t g_CtrConfigMemory_1FF81000[];
extern "C" __attribute__((noinline)) void Matrix4x4_Copy_003FDA38(
    void* destination, const void* source) {
    if (source != destination) {
        Matrix4x4 copy = *static_cast<const Matrix4x4*>(source);
        *static_cast<Matrix4x4*>(destination) = copy;
    }
}
extern "C" __attribute__((noinline)) void RenderProjection_SetValue48_008D0FF8(
    void* projection, float value) {
    if (value < 0.0f)
        SdkBreak_0013B2F0();
    *reinterpret_cast<float*>(
        static_cast<uint8_t*>(projection) + 0x48) = value;
}
extern "C" __attribute__((noinline)) float
RenderProjection_GetScaledValue48_00B3BCF4(
    const void* projection) {
    const uint8_t* const bytes = static_cast<const uint8_t*>(projection);
    const float value = *reinterpret_cast<const float*>(bytes + 0x48);
    const float half = 0.5f;
    volatile const uint8_t* const config = g_CtrConfigMemory_1FF81000;
    const float scale = *reinterpret_cast<const float*>(
        g_RenderProjectionScaleOwner_00DF5A00 + 8);
    const float quotient = value / scale;
    const uint8_t flag = config[0x84];
    const float slider = flag != 0
                             ? 0.0f
                             : *reinterpret_cast<volatile const float*>(config + 0x80);
    return quotient * half * slider;
}
extern "C" __attribute__((noinline)) float
RenderProjection_GetValueRatio_00B3BD38(
    const void* projection) {
    const uint8_t* bytes = static_cast<const uint8_t*>(projection);
    return *reinterpret_cast<const float*>(bytes + 0x5C) /
           *reinterpret_cast<const float*>(bytes + 0x4C);
}
extern "C" __attribute__((noinline)) void FUN_009160AC(
    void* output, void* projection, const void* matrix3x4,
    const void* matrix4x4, float scale) {
    uint8_t* bytes = static_cast<uint8_t*>(output);
    *reinterpret_cast<Matrix3x4*>(bytes) =
        *static_cast<const Matrix3x4*>(matrix3x4);
    *reinterpret_cast<Matrix4x4*>(bytes + 0x30) =
        *static_cast<const Matrix4x4*>(matrix4x4);
    Matrix4x4 transformed;
    Matrix3x4 affine;
    Matrix4x4_Copy_003FDA38(&transformed, matrix4x4);
    Matrix3x4_Copy_0044C0A0(&affine, matrix3x4);
    const float value0 = transformed.values[0];
    const float value1 = transformed.values[1];
    transformed.values[0] = -transformed.values[4];
    transformed.values[1] = transformed.values[5];
    transformed.values[4] = value0;
    transformed.values[5] = value1;
    RenderProjection_SetValue48_008D0FF8(
        projection, *reinterpret_cast<float*>(bytes + 0x80));
    uint8_t* first = *reinterpret_cast<uint8_t**>(bytes + 0x70);
    uint8_t* second = *reinterpret_cast<uint8_t**>(bytes + 0x74);
    Projection_BuildFrustum_008D1028(
        projection, first + 0x1a8, first + 0x148, second + 0x1a8,
        second + 0x148, &transformed, &affine,
        static_cast<int>(*reinterpret_cast<int8_t*>(bytes + 0x8c)),
        *reinterpret_cast<float*>(bytes + 0x84),
        *reinterpret_cast<float*>(bytes + 0x88) * scale);
    *reinterpret_cast<float*>(bytes + 0x78) =
        RenderProjection_GetValueRatio_00B3BD38(projection);
    *reinterpret_cast<float*>(bytes + 0x7c) =
        RenderProjection_GetScaledValue48_00B3BCF4(projection);
}
