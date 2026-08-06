#include <cstdint>
extern "C" __attribute__((noinline)) void MatrixCommand_EncodeVec4_005E15A4(
    void* destination, const void* source) {
    const float* input = static_cast<const float*>(source);
    const float v0 = input[0], v1 = input[1], v2 = input[2], v3 = input[3];
    float* output = static_cast<float*>(destination);
    output[3] = v0;
    output[2] = v1;
    output[1] = v2;
    output[0] = v3;
}
extern "C" __attribute__((noinline)) void MatrixCommand_Encode3x4_005E1664(
    void* destination, const void* source, std::uint32_t command) {
    const float* input = static_cast<const float*>(source);
    const float v0 = input[0], v1 = input[1], v2 = input[2], v3 = input[3];
    const float v4 = input[4], v5 = input[5], v6 = input[6], v7 = input[7];
    const float v8 = input[8], v9 = input[9], v10 = input[10], v11 = input[11];
    float* output = static_cast<float*>(destination);
    *reinterpret_cast<std::uint32_t*>(output + 1) = command;
    output[4] = v0;
    output[3] = v1;
    output[2] = v2;
    output[0] = v3;
    output[8] = v4;
    output[7] = v5;
    output[6] = v6;
    output[5] = v7;
    output[12] = v8;
    output[11] = v9;
    output[10] = v10;
    output[9] = v11;
}
extern "C" __attribute__((noinline)) void MatrixCommand_Encode4x4_005E16E8(
    void* destination, const void* source, std::uint32_t command) {
    const float* input = static_cast<const float*>(source);
    const float v0 = input[0], v1 = input[1], v2 = input[2], v3 = input[3];
    const float v4 = input[4], v5 = input[5], v6 = input[6], v7 = input[7];
    const float v8 = input[8], v9 = input[9], v10 = input[10], v11 = input[11];
    const float v12 = input[12], v13 = input[13], v14 = input[14],
                v15 = input[15];
    float* output = static_cast<float*>(destination);
    *reinterpret_cast<std::uint32_t*>(output + 1) = command;
    output[4] = v0;
    output[3] = v1;
    output[2] = v2;
    output[0] = v3;
    output[8] = v4;
    output[7] = v5;
    output[6] = v6;
    output[5] = v7;
    output[12] = v8;
    output[11] = v9;
    output[10] = v10;
    output[9] = v11;
    output[16] = v12;
    output[15] = v13;
    output[14] = v14;
    output[13] = v15;
}
