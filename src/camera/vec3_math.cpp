#include <cmath>
#include <cstdint>
extern "C" float acosf(float x);
extern "C" float asinf(float x);
extern const float g_FallbackDirection[3];
__attribute__((noinline)) static float ClampedAsin(float x) {
    if (x >= 1.0f) return 1.57079633f;
    if (x <= -1.0f) return -1.57079633f;
    return asinf(x);
}
__attribute__((noinline)) float ClampedAcos(float x) {
    if (x >= 1.0f) return 0.0f;
    if (x <= -1.0f) return 3.14159265f;
    return acosf(x);
}
__attribute__((noinline)) float Vec3_ComputeYaw(const float* dir) {
    float yaw = ClampedAcos(dir[2]);
    if (dir[0] < 0.0f) yaw = -yaw;
    return yaw;
}
__attribute__((noinline)) float Vec3_ComputePitch(const float* dir) {
    return -ClampedAsin(dir[1]);
}
__attribute__((noinline)) bool Vec3_NormalizeAndGetLength(float* out_normalized, float* out_length,
                                const float* in_vec) {
    const float x = in_vec[0], y = in_vec[1], z = in_vec[2];
    const float squared_length = x * x + y * y + z * z;
    if (squared_length == 1.0f) {
        if (out_normalized) {
            const std::uint32_t* source =
                reinterpret_cast<const std::uint32_t*>(in_vec);
            std::uint32_t* destination =
                reinterpret_cast<std::uint32_t*>(out_normalized);
            destination[0] = source[0];
            destination[1] = source[1];
            destination[2] = source[2];
        }
        if (out_length) *out_length = 1.0f;
        return true;
    }
    const float kEpsilon = 1.49668524e-6f;  // 0x358637BC
    if (squared_length > 0.0f) {
        const float length = std::sqrt(squared_length);
        if (out_normalized) {
            const float inv_length = 1.0f / length;
            out_normalized[0] = in_vec[0] * inv_length;
            out_normalized[1] = y * inv_length;
            out_normalized[2] = z * inv_length;
        }
        if (out_length) *out_length = length;
        return squared_length > kEpsilon;
    }
    if (out_normalized) {
        out_normalized[0] = g_FallbackDirection[0];
        out_normalized[1] = g_FallbackDirection[1];
        out_normalized[2] = g_FallbackDirection[2];
    }
    if (out_length) *out_length = 0.0f;
    return false;
}
extern "C" float AngleUnitsAtan2(float y, float x);
// Semantic reconstruction, JP Rev 1: 0x0090BA44.
extern "C" __attribute__((noinline)) bool Vec3_IsPitchInRange_0090BA44(const float* vector) {
    const float kGimbalLockThreshold = 0.999899983f; // 0x3F7FF972
    float y = vector[1];
    if (y < 0.0f) y = -y;
    return y < kGimbalLockThreshold;
}
// Semantic reconstruction, JP Rev 1: 0x0090B458.
extern "C" __attribute__((noinline)) bool Vec3_ComputeYawIfInRange_0090B458(float* out_angle,
                                                   const float* vector) {
    const float kGimbalLockThreshold = 0.999899983f; // 0x3F7FF972
    const float kAngleUnitsToRadians = 0.0245436933f; // 2*pi/256
    float y = vector[1];
    if (y < 0.0f) y = -y;
    if (y >= kGimbalLockThreshold) {
        *out_angle = 0.0f;
        return false;
    }
    *out_angle = AngleUnitsAtan2(vector[0], vector[2]) * kAngleUnitsToRadians;
    return true;
}
struct Basis3x3EulerConstantsView {
    float gimbal_lock_threshold_000;
    float angle_units_to_radians_004;
    float fallback_x_008;
};
typedef char kiu_sa_basis3x3_euler_constants_1[
    (sizeof(Basis3x3EulerConstantsView) == 0x0c) ? 1 : -1] __attribute__((unused));
extern "C" const Basis3x3EulerConstantsView DAT_005C80E0;
__attribute__((noinline)) void Basis3x3_ToEulerAngles(float* out, const float* basis) {
    out[1] = ClampedAsin(-basis[0x14 / 4]);
    if ((basis[0x14 / 4] < 0.0f ? -basis[0x14 / 4] : basis[0x14 / 4]) <
        DAT_005C80E0.gimbal_lock_threshold_000) {
        out[0] = AngleUnitsAtan2(basis[0x08 / 4], basis[0x20 / 4]) *
                 DAT_005C80E0.angle_units_to_radians_004;
        out[2] = AngleUnitsAtan2(basis[0x0c / 4], basis[0x10 / 4]) *
                 DAT_005C80E0.angle_units_to_radians_004;
        return;
    }
    out[0] = DAT_005C80E0.fallback_x_008;
    out[2] = AngleUnitsAtan2(-basis[0x04 / 4], basis[0x00 / 4]) *
             DAT_005C80E0.angle_units_to_radians_004;
}
__attribute__((noinline)) bool Vec3_ComputeElevationAndBoundedAzimuth(float* out_azimuth,
                                            float* out_elevation,
                                            const float* dir) {
    *out_elevation = -ClampedAsin(dir[1]);
    const float abs_y = dir[1] < 0.0f ? -dir[1] : dir[1];
    const bool in_range = abs_y < DAT_005C80E0.gimbal_lock_threshold_000;
    *out_azimuth = in_range
        ? AngleUnitsAtan2(abs_y, dir[0]) * DAT_005C80E0.angle_units_to_radians_004
        : DAT_005C80E0.fallback_x_008;
    return in_range;
}
__attribute__((noinline)) float Vec3_ComputeAxisAngleBetween(float* out_axis, const float* from,
                                   const float* to) {
    float cross_x = from[1] * to[2] - from[2] * to[1];
    float cross_y = from[2] * to[0] - from[0] * to[2];
    float cross_z = from[0] * to[1] - from[1] * to[0];
    const float kDegenerateEpsilon = 0.00100000005f; // 0x3A83126F
    const float kNearZAxisThreshold = 0.899999976f;  // 0x3F666666
    static const float kFallbackAxisA[3] = {0.0f, 0.0f, 0.0f};
    static const float kFallbackAxisB[3] = {0.0f, 0.0f, 0.0f};
    const float abs_cross_x = cross_x < 0.0f ? -cross_x : cross_x;
    const float abs_cross_y = cross_y < 0.0f ? -cross_y : cross_y;
    const float abs_cross_z = cross_z < 0.0f ? -cross_z : cross_z;
    if (abs_cross_x <= kDegenerateEpsilon && abs_cross_y <= kDegenerateEpsilon &&
        abs_cross_z <= kDegenerateEpsilon) {
        const float abs_from_z = from[2] < 0.0f ? -from[2] : from[2];
        const float* ref = (abs_from_z <= kNearZAxisThreshold) ? kFallbackAxisB
                                                                : kFallbackAxisA;
        cross_y = from[2] * ref[0] - from[0] * ref[2];
        cross_z = from[0] * ref[1] - from[1] * ref[0];
        cross_x = from[1] * ref[2] - from[2] * ref[1];
    }
    const float inv_length =
        1.0f / std::sqrt(cross_x * cross_x + cross_y * cross_y + cross_z * cross_z);
    if (out_axis) {
        out_axis[0] = cross_x * inv_length;
        out_axis[1] = cross_y * inv_length;
        out_axis[2] = cross_z * inv_length;
    }
    const float dot = from[0] * to[0] + from[1] * to[1] + from[2] * to[2];
    return ClampedAcos(dot);
}
