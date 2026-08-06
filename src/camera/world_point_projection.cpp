#include <cmath>
#include <cstdint>
extern "C" __attribute__((noinline, noipa)) void
Engine_StateRecord_Read_003B4170(
    int* out, void* state, std::uint32_t entry)
{
    const std::uint8_t* record = reinterpret_cast<const std::uint8_t*>(state) +
                                 entry * 0x30;
    struct Quad { std::uint32_t word[4]; };
    *reinterpret_cast<Quad*>(out) =
        *reinterpret_cast<const Quad*>(record + 0x150);
}
extern "C" void* Engine_StateSingleton_003B6EDC(void);
extern "C" void* Engine_StateEntryOffset_0042F42C(
    void* state, std::uint32_t mode, std::uint32_t index);
extern "C" const float* ResourceProjection_GetMatrix_003AD044(void* record);
extern "C" const float* ResourceProjection_GetRecord_003900BC(void* record);
extern "C" int ResourceProjection_GetMode_003F4098(void* record);
__attribute__((noinline)) void Camera_ProjectWorldPoint_00405368(
    float out[2], const void* entry_table_unused, std::uint32_t entry_index,
    const float point[3], const float matrix[12], const float screen[8],
    int perspective_mode)
{
    (void)entry_table_unused;
    const float x = matrix[0] * point[0] + matrix[1] * point[1] +
                    matrix[2] * point[2] + matrix[3];
    const float y = matrix[4] * point[0] + matrix[5] * point[1] +
                    matrix[6] * point[2] + matrix[7];
    const float z = matrix[8] * point[0] + matrix[9] * point[1] +
                    matrix[10] * point[2] + matrix[11];
    float projected_x;
    float projected_y;
    if (perspective_mode != 0) {
        projected_x = screen[7] + x * screen[4];
        projected_y = screen[3] + y * screen[1];
    } else {
        const float reciprocal = std::fabs(z) < 1.0e-7f ? 0.0f : 1.0f / -z;
        projected_x = screen[6] + reciprocal * x * screen[4];
        projected_y = screen[2] + reciprocal * y * screen[1];
    }
    static void** state_cache = reinterpret_cast<void**>(0x00D637BC);
    void* state = *state_cache;
    if (state == 0) state = Engine_StateSingleton_003B6EDC();
    *state_cache = state;
    int values[4];
    const std::uint32_t* entry_table =
        *reinterpret_cast<const std::uint32_t* const*>(0x00405500);
    const std::uint32_t entry = entry_table[entry_index];
    Engine_StateRecord_Read_003B4170(values, state, entry);
    // Retail reads the same record a second time before converting it.
    Engine_StateRecord_Read_003B4170(values, state, entry);
    const float kHalf = 0.5f; // 0x3F000000
    const float x_scale = values[2] * kHalf;
    const float y_scale = values[3] * kHalf;
    out[0] = static_cast<float>(values[0]) + x_scale - projected_x * x_scale;
    out[1] = static_cast<float>(values[1]) + y_scale - projected_y * y_scale;
}
extern "C" __attribute__((noinline)) void FUN_006069C8(
    float out[2], void* state, std::uint32_t mode, const float point[3],
    std::uint32_t record_index)
{
    std::uint8_t* state_bytes = static_cast<std::uint8_t*>(state);
    void* record;
    if (record_index == 0) {
        record = Engine_StateEntryOffset_0042F42C(
            state, mode, state_bytes[mode + 0x98]);
    } else {
        record = state_bytes + record_index * 0x5a0 + mode * 0x1e0 + 0xbc;
    }
    std::uint8_t* projection_owner = static_cast<std::uint8_t*>(record) + 0x64;
    const float* matrix =
        ResourceProjection_GetMatrix_003AD044(projection_owner);
    const float* viewport =
        ResourceProjection_GetRecord_003900BC(projection_owner);
    const float x = matrix[0] * point[0] + matrix[1] * point[1] +
                    matrix[2] * point[2] + matrix[3];
    const float y = matrix[4] * point[0] + matrix[5] * point[1] +
                    matrix[6] * point[2] + matrix[7];
    const float z = matrix[8] * point[0] + matrix[9] * point[1] +
                    matrix[10] * point[2] + matrix[11];
    float projected_x;
    float projected_y;
    if (ResourceProjection_GetMode_003F4098(projection_owner) != 0) {
        projected_x = -(x * viewport[4]) - viewport[7];
        projected_y = viewport[3] + y * viewport[1];
    } else {
        const float reciprocal = std::fabs(z) < 1.0e-7f ? 0.0f : 1.0f / -z;
        projected_x = -(x * viewport[4]) * reciprocal - viewport[6];
        projected_y = viewport[2] + reciprocal * y * viewport[1];
    }
    const std::uint32_t* entry_table = reinterpret_cast<const std::uint32_t*>(0x00ca7bec);
    const std::uint32_t entry = entry_table[mode];
    void** state_cache = reinterpret_cast<void**>(0x00d637bc);
    if (*state_cache == 0) {
        *state_cache = Engine_StateSingleton_003B6EDC();
    }
    int values[4];
    Engine_StateRecord_Read_003B4170(values, *state_cache, entry);
    values[0] = 0;
    values[1] = 0;
    if (*state_cache == 0) {
        *state_cache = Engine_StateSingleton_003B6EDC();
    }
    Engine_StateRecord_Read_003B4170(values, *state_cache, entry);
    values[0] = 0;
    values[1] = 0;
    const float kHalf = 0.5f;
    const float x_scale = static_cast<float>(values[2]) * kHalf;
    const float y_scale = static_cast<float>(values[3]) * kHalf;
    out[0] = x_scale + projected_x * x_scale;
    out[1] = y_scale - projected_y * y_scale;
}
extern "C" __attribute__((noinline)) void FUN_00606C0C(
    float out[4], void* state, std::uint32_t mode, const float point[3],
    std::uint32_t record_index)
{
    std::uint8_t* state_bytes = static_cast<std::uint8_t*>(state);
    void* record;
    if (record_index == 0) {
        record = Engine_StateEntryOffset_0042F42C(
            state, mode, state_bytes[mode + 0x98]);
    } else {
        record = state_bytes + record_index * 0x5a0 + mode * 0x1e0 + 0xbc;
    }
    std::uint8_t* projection_owner = static_cast<std::uint8_t*>(record) + 0x64;
    const float* matrix = ResourceProjection_GetMatrix_003AD044(projection_owner);
    const float* viewport = ResourceProjection_GetRecord_003900BC(projection_owner);
    const float x = matrix[0] * point[0] + matrix[1] * point[1] +
                    matrix[2] * point[2] + matrix[3];
    const float y = matrix[4] * point[0] + matrix[5] * point[1] +
                    matrix[6] * point[2] + matrix[7];
    const float z = matrix[8] * point[0] + matrix[9] * point[1] +
                    matrix[10] * point[2] + matrix[11];
    float projected_x;
    float projected_y;
    float vertical_scale;
    if (ResourceProjection_GetMode_003F4098(projection_owner) != 0) {
        projected_x = viewport[7] + x * viewport[4];
        projected_y = viewport[3] + y * viewport[1];
        vertical_scale = viewport[1];
    } else {
        const float reciprocal = std::fabs(z) < 1.0e-7f ? 0.0f : 1.0f / z;
        projected_x = viewport[6] + reciprocal * x * viewport[4];
        projected_y = viewport[2] + reciprocal * y * viewport[1];
        vertical_scale = -viewport[1] * reciprocal;
    }
    const std::uint32_t* entry_table =
        reinterpret_cast<const std::uint32_t*>(0x00ca7bec);
    const std::uint32_t entry = entry_table[mode];
    void** state_cache = reinterpret_cast<void**>(0x00d637bc);
    if (*state_cache == 0) {
        *state_cache = Engine_StateSingleton_003B6EDC();
    }
    int values[4];
    Engine_StateRecord_Read_003B4170(values, *state_cache, entry);
    if (*state_cache == 0) {
        *state_cache = Engine_StateSingleton_003B6EDC();
    }
    Engine_StateRecord_Read_003B4170(values, *state_cache, entry);
    const float half = 0.5f;
    const float x_scale = static_cast<float>(values[2]) * half;
    const float y_scale = static_cast<float>(values[3]) * half;
    out[0] = static_cast<float>(values[0]) + x_scale + projected_x * x_scale;
    out[1] = static_cast<float>(values[1]) + y_scale + projected_y * y_scale;
    out[2] = -z;
    out[3] = vertical_scale * y_scale;
}
