#include <stdint.h>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <limits>
#include "camera_motion_views.h"
struct CameraTargetOverrideYawConstantsView {
    float pi_000;
    float minimum_window_004;
    float window_slope_008;
    float half_turn_00c;
};
typedef char kiu_sa_camera_target_override_yaw_constants_1[
    (sizeof(CameraTargetOverrideYawConstantsView) == 0x10) ? 1 : -1] __attribute__((unused));
extern "C" const CameraTargetOverrideYawConstantsView DAT_00809DB4;
static float CameraRuntime_ReadFloat(const uint8_t* bytes,
                                     std::size_t offset) {
    return *reinterpret_cast<const float*>(bytes + offset);
}
static float& CameraRuntime_FloatAt(uint8_t* bytes, std::size_t offset) {
    return *reinterpret_cast<float*>(bytes + offset);
}
static float CameraRuntime_Interpolate(float from, float to, float progress) {
    return from + (to - from) * progress;
}
extern "C" void AngleTriple_ToBasis(float*, int, const float[3], int, const float[9]);
extern const float g_AimDirectionBasisSeed[];
extern "C" float TrigKernel_00474AB0(float);
extern "C" float TrigKernel_0049A9DC(float);
extern "C" float AngleUnitsAtan2(float y, float x);
extern "C" void AngleSpring_StepBothStages(void*, float, float);
static inline void AngleSpring_StepBothStages(void* spring, float target) {
    AngleSpring_StepBothStages(spring, target, 0.0f);
}
extern "C" void AngleSpring_Reset(void*, float);
extern "C" int FUN_0049BE78();
extern "C" int FUN_0042F42C(int, int, int);
extern "C" void FUN_0042F4D0(int, const float*);
extern int32_t* g_ActiveEngineCameraSlot; // DAT_00633FDC
extern "C" uint8_t* FUN_0054ACE0(void* table);
extern "C" int FUN_0054ACD0(void* table);
extern "C" int FUN_00910464(const void* value, int stride);
extern "C" int FUN_00A9B994(const void* reticle);
extern void* g_AimFramingProfileTable; // DAT_007DC050
struct CameraAimFramingTableConstantsView {
    void* extent_table_000;
    void* aux_table_004;
    float reset_progress_008;
    float reset_zero_00c;
    float unset_010;
};
typedef char kiu_sa_camera_aim_framing_table_constants_1[
    (sizeof(CameraAimFramingTableConstantsView) == 0x14) ? 1 : -1] __attribute__((unused));
extern const CameraAimFramingTableConstantsView DAT_007DBE48;
struct CameraActorOcclusionConstantsView {
    float clear_target_000;
    float segment_end_distance_004;
    float occlusion_margin_008;
    void* registry_cache_slot_00c;
    float occupied_target_010;
    float segment_extension_014;
    float interior_margin_018;
    float segment_length_01c;
    float offset_squared_threshold_020;
};
typedef char kiu_sa_camera_actor_occlusion_constants_1[
    (sizeof(CameraActorOcclusionConstantsView) == 0x24) ? 1 : -1] __attribute__((unused));
extern const CameraActorOcclusionConstantsView DAT_007EEE00;
struct CameraAimSpringView {
    uint8_t opaque[0x24];
    float value;
};
struct CameraActorAimStateView {
    uint8_t opaque_000[0x24];
    uint8_t mode_024;
    uint8_t opaque_025[0x07];
    float base_translation[3];
    float previous_translation[3];
    float world_anchor[3];
    uint8_t opaque_050[0x28];
    float forward_x;
    uint8_t opaque_07c[0x0c];
    float forward_y;
    uint8_t opaque_08c[0x0c];
    float forward_z;
    uint8_t opaque_09c[0x1c];
    uint8_t stable_0b8;
    uint8_t opaque_0b9[0x03];
    float stable_time;
    uint8_t target_active;
    uint8_t opaque_0c1[0x0b];
    uint8_t tracking_active;
    uint8_t opaque_0cd[0x03];
    float tracking_time;
    uint8_t tracking_ready;
    uint8_t opaque_0d5[0x03];
    float cooldown;
    float mode1_timer;
    uint8_t mode1_ready;
    uint8_t opaque_0e1[0x03];
    float mode1_value;
    uint8_t opaque_0e8[0x10];
    int32_t target_lifetime;
    float target_elapsed;
    uint8_t opaque_100[0x2c];
    float reset_sentinel[3];
    uint8_t opaque_138[0x0d];
    uint8_t special_geometry;
    uint8_t opaque_146[0x02];
    float target_position[3];
    uint8_t opaque_154[0x10];
    float motion_value;
    float cached_yaw;
    float cached_target[3];
    float previous_target_x;
    float previous_target_y;
    float previous_target_z;
    CameraAimSpringView spring;
};
typedef char kiu_sa_camera_runtime_1[(offsetof(CameraActorAimStateView, mode_024) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_2[(offsetof(CameraActorAimStateView, base_translation) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_3[(offsetof(CameraActorAimStateView, world_anchor) == 0x44) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_4[(offsetof(CameraActorAimStateView, forward_x) == 0x78) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_5[(offsetof(CameraActorAimStateView, forward_y) == 0x88) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_6[(offsetof(CameraActorAimStateView, forward_z) == 0x98) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_7[(offsetof(CameraActorAimStateView, reset_sentinel) == 0x12c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_8[(offsetof(CameraActorAimStateView, target_position) == 0x148) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_9[(offsetof(CameraActorAimStateView, motion_value) == 0x164) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_10[(offsetof(CameraActorAimStateView, spring) == 0x184) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_11[(offsetof(CameraActorAimStateView, spring) + offsetof(CameraAimSpringView, value) == 0x1a8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_12[(sizeof(CameraActorAimStateView) == 0x1ac) ? 1 : -1] __attribute__((unused));
struct CameraOrbitTransformView {
    float position[3];
    float forward[3];
    float distance;
    uint8_t opaque_01c[8];
    float focus[3];
    uint8_t opaque_030[4];
    float yaw;
    float pitch;
};
typedef char kiu_sa_camera_runtime_13[(offsetof(CameraOrbitTransformView, forward) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_14[(offsetof(CameraOrbitTransformView, distance) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_15[(offsetof(CameraOrbitTransformView, focus) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_16[(offsetof(CameraOrbitTransformView, yaw) == 0x34) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_17[(offsetof(CameraOrbitTransformView, pitch) == 0x38) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_18[(sizeof(CameraOrbitTransformView) == 0x3c) ? 1 : -1] __attribute__((unused));
struct CameraBoomStateView {
    uint8_t opaque_000[0x24];
    float base_distance;
    float effective_distance;
    uint8_t opaque_02c[0x24];
    float occlusion_scale;
    uint8_t occlusion_occupied;
    uint8_t opaque_055[0x03];
    float occlusion_blend;
    float occlusion_progress;
    float occlusion_elapsed;
    float timer;
    uint8_t opaque_068[0x44];
};
typedef char kiu_sa_camera_runtime_19[(offsetof(CameraBoomStateView, base_distance) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_20[(offsetof(CameraBoomStateView, effective_distance) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_21[(offsetof(CameraBoomStateView, occlusion_scale) == 0x50) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_22[(offsetof(CameraBoomStateView, occlusion_occupied) == 0x54) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_23[(offsetof(CameraBoomStateView, occlusion_blend) == 0x58) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_24[(offsetof(CameraBoomStateView, occlusion_progress) == 0x5c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_25[(offsetof(CameraBoomStateView, occlusion_elapsed) == 0x60) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_26[(offsetof(CameraBoomStateView, timer) == 0x64) ? 1 : -1] __attribute__((unused));
struct CameraBoomTransformView {
    float position[3];
    float forward[3];
    uint8_t opaque_018[0x0c];
    float focus[3];
    float distance;
};
typedef char kiu_sa_camera_runtime_27[(offsetof(CameraBoomTransformView, forward) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_28[(offsetof(CameraBoomTransformView, focus) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_29[(offsetof(CameraBoomTransformView, distance) == 0x30) ? 1 : -1] __attribute__((unused));
struct CameraTrackEndpointView {
    uint8_t type;
    uint8_t opaque_001[3];
    uint32_t actor_handle;
    uint32_t node_key;
    const char* node_name;
    uint8_t opaque_010[0x24];
    float literal_position[3];
};
typedef char kiu_sa_camera_runtime_30[(offsetof(CameraTrackEndpointView, actor_handle) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_31[(offsetof(CameraTrackEndpointView, node_key) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_32[(offsetof(CameraTrackEndpointView, node_name) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_33[(offsetof(CameraTrackEndpointView, literal_position) == 0x34) ? 1 : -1] __attribute__((unused));
// Semantic reconstruction, JP Rev 1: 0x00633F80.
__attribute__((noinline)) void ActorCamera_SubmitMatrix(const uint8_t* actor_camera, const float* matrix) {
    const int8_t slot = static_cast<int8_t>(actor_camera[0x5c]);
    if (slot == -1) return;
    int registry = *g_ActiveEngineCameraSlot;
    if (registry == 0) {
        registry = FUN_0049BE78();
        *g_ActiveEngineCameraSlot = registry;
    }
    const int camera = FUN_0042F42C(registry, slot, 1);
    if (camera != 0) FUN_0042F4D0(camera, matrix);
}
__attribute__((noinline)) void ActorCamera_CommitTransform(uint8_t* actor_camera, const void* frame_context,
                                  const float* transform) {
    (void)frame_context;
    std::memcpy(actor_camera + 0x40, transform + 1, 7 * sizeof(float));
    const float x = transform[1];
    const float y = transform[2];
    const float z = transform[3];
    const float w = transform[4];
    const float xx = 2.0f * x * x;
    const float yy = 2.0f * y * y;
    const float zz = 2.0f * z * z;
    const float xy = 2.0f * x * y;
    const float xz = 2.0f * x * z;
    const float yz = 2.0f * y * z;
    const float xw = 2.0f * x * w;
    const float yw = 2.0f * y * w;
    const float zw = 2.0f * z * w;
    float matrix[12] = {
        1.0f - yy - zz, xy - zw,       xz + yw,       transform[5],
        xy + zw,       1.0f - xx - zz, yz - xw,       transform[6],
        xz - yw,       yz + xw,       1.0f - xx - yy, transform[7],
    };
    ActorCamera_SubmitMatrix(actor_camera, matrix);
}
extern "C" __attribute__((noinline)) void CameraAimFraming_ComputeProjectedScale(
    float* out, const float* aim, const float* basis, const float* forward,
    float angular_scale, float aspect) {
    float distance = (aim[0] - basis[0]) * forward[0] +
                     (aim[1] - basis[1]) * forward[1] +
                     (aim[2] - basis[2]) * forward[2];
    distance = distance < 0.0f ? -distance : distance;
    if (distance < 1.0f) distance = 1.0f;
    const float projected = TrigKernel_00474AB0(angular_scale * 0.5f) * distance;
    out[0] = projected * aspect;
    out[1] = projected;
    out[2] = distance;
}
// Semantic reconstruction, JP Rev 1: 0x007C9DC0.
extern "C" __attribute__((noinline)) void CameraAimFraming_Reset(uint8_t* framing_state,
                                        const uint8_t* reticle,
                                        const float* camera_transform,
                                        const void* context,
                                        float frame_step) {
    const float* aim = reinterpret_cast<const float*>(reticle + 0x44);
    const float basis[3] = {
        camera_transform[0x54 / 4], camera_transform[0x64 / 4], camera_transform[0x74 / 4]};
    const float forward[3] = {
        camera_transform[0x50 / 4], camera_transform[0x60 / 4], camera_transform[0x70 / 4]};
    const float angular_scale = camera_transform[0x40 / 4];
    const float aspect = camera_transform[0x44 / 4];
    float projected[3];
    CameraAimFraming_ComputeProjectedScale(projected, aim, basis, forward,
                                           angular_scale, aspect);
    uint8_t* state = framing_state;
    *reinterpret_cast<float*>(state + 0x9c) = projected[0];
    *reinterpret_cast<float*>(state + 0xa0) = projected[1];
    const uint8_t* const reticle_link = *reinterpret_cast<const uint8_t* const*>(
        reticle + 0x0c);
    const uint8_t* component = reticle_link == 0
        ? 0
        : *reinterpret_cast<const uint8_t* const*>(reticle_link + 0x20);
    if (component != 0 &&
        ((*reinterpret_cast<const uint32_t*>(component + 0x34) & 4U) != 0)) {
        const uint8_t* const bound = *reinterpret_cast<const uint8_t* const*>(
            component + 0x6c);
        if (bound != 0 && context != 0) {
            const uint8_t* camera_bytes = reinterpret_cast<const uint8_t*>(
                camera_transform);
            const uint8_t* context_bytes = static_cast<const uint8_t*>(context);
            const float camera_x = *reinterpret_cast<const float*>(camera_bytes + 0x4c);
            const float camera_y = *reinterpret_cast<const float*>(camera_bytes + 0x5c);
            const float camera_z = *reinterpret_cast<const float*>(camera_bytes + 0x6c);
            const float projected_offset =
                (*reinterpret_cast<const float*>(context_bytes + 0x58) +
                 *reinterpret_cast<const float*>(context_bytes + 0x90)) * camera_x +
                (*reinterpret_cast<const float*>(context_bytes + 0x5c) +
                 *reinterpret_cast<const float*>(context_bytes + 0x94)) * camera_y +
                *reinterpret_cast<const float*>(context_bytes + 0x98) * camera_z;
            const float dx = *reinterpret_cast<const float*>(bound + 0x00) - aim[0];
            const float dy = *reinterpret_cast<const float*>(bound + 0x04) - aim[1];
            const float dz = *reinterpret_cast<const float*>(bound + 0x08) - aim[2];
            const float projected_delta = dx * camera_x + dy * camera_y + dz * camera_z;
            const float lower = projected[1] -
                                *reinterpret_cast<const float*>(bound + 0x0c);
            float first_target = (lower - projected_delta + projected_offset) /
                                 projected[1];
            float second_target = (lower + projected_delta - projected_offset) /
                                  projected[1];
            if (first_target < 0.0f) first_target = 0.0f;
            if (second_target < 0.0f) second_target = 0.0f;
            AngleSpring_StepBothStages(state + 0xa4, first_target, frame_step);
            AngleSpring_StepBothStages(state + 0xcc, second_target, frame_step);
            return;
        }
    }
    AngleSpring_StepBothStages(
        state + 0xa4, *reinterpret_cast<const float*>(state + 0xb4), frame_step);
    AngleSpring_StepBothStages(state + 0xcc, 0.0f, frame_step);
}
extern "C" __attribute__((noinline)) void Camera_UpdateAimFraming(float* framing_state,
                                         float* camera_transform,
                                         int reticle_address, int input_mode,
                                         int reset, int mode_state,
                                         float scalar_extent, float frame_step) {
    uint8_t* state = reinterpret_cast<uint8_t*>(framing_state);
    const uint8_t* reticle = reinterpret_cast<const uint8_t*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(reticle_address)));
    const float* anchor = reinterpret_cast<const float*>(reticle + 0x44);
    if (reset == 0) {
        for (int i = 0; i != 3; ++i)
            AngleSpring_Reset(state + i * 0x28 + 0x24, 2.7f);
        AngleSpring_Reset(state + 0xa4, 0.75f);
        AngleSpring_Reset(state + 0xcc, 0.2f);
        std::memcpy(state, anchor, 3 * sizeof(float));
        std::memcpy(state + 0x0c, anchor, 3 * sizeof(float));
    } else {
        bool skip_axis1 = false;
        if (*reinterpret_cast<const float*>(reinterpret_cast<const uint8_t*>(
                static_cast<uintptr_t>(static_cast<uint32_t>(mode_state))) +
                0x24) < 1.0f &&
            *reinterpret_cast<const int8_t*>(reticle + 0xe1) == -1) {
            skip_axis1 = reticle[0xc0] != 0 ||
                *reinterpret_cast<const void* const*>(reticle + 0xa4) ==
                    reinterpret_cast<const void*>(static_cast<uintptr_t>(0x00c9b994)) ||
                input_mode != 0;
        }
        std::memcpy(state + 0x0c, state, 3 * sizeof(float));
        const float basis[9] = {
            camera_transform[0], camera_transform[4], camera_transform[8],
            camera_transform[1], camera_transform[5], camera_transform[9],
            camera_transform[2], camera_transform[6], camera_transform[10],
        };
        const float profile[8] = {0.3f, 0.0f, 0.5f, 0.3f,
                                  0.0f, 0.2f, 0.01f, 0.01f};
        const float extent[3] = {*reinterpret_cast<float*>(state + 0x9c),
                                 *reinterpret_cast<float*>(state + 0xa0),
                                 scalar_extent};
        const float previous_anchor[3] = {
            *reinterpret_cast<float*>(state + 0x18),
            *reinterpret_cast<float*>(state + 0x1c),
            *reinterpret_cast<float*>(state + 0x20),
        };
        const float anchor_delta[3] = {
            anchor[0] - previous_anchor[0],
            anchor[1] - previous_anchor[1],
            anchor[2] - previous_anchor[2],
        };
        for (int pass = 0; pass != 2; ++pass) {
            const float anchor_projection = pass == 0
                ? anchor_delta[0] * basis[3] + anchor_delta[2] * basis[5]
                : anchor_delta[1] * basis[4];
            const float current_projection =
                (previous_anchor[0] - framing_state[0]) * basis[3] +
                (previous_anchor[1] - framing_state[1]) * basis[4] +
                (previous_anchor[2] - framing_state[2]) * basis[5];
            const float candidate = current_projection + anchor_projection;
            float correction = 0.0f;
            if (anchor_projection > 0.0f) {
                const float limit = *reinterpret_cast<float*>(state + 0xa0) *
                    (pass == 0 ? 0.1f : *reinterpret_cast<float*>(state + 0xc8));
                if (candidate > limit)
                    correction = std::min(candidate - limit, anchor_projection);
            } else {
                const float limit = *reinterpret_cast<float*>(state + 0xa0) *
                    (pass == 0 ? 0.1f : *reinterpret_cast<float*>(state + 0xf0));
                if (candidate < -limit)
                    correction = std::max(candidate + limit, anchor_projection);
            }
            framing_state[0] += basis[3] * correction;
            framing_state[1] += basis[4] * correction;
            framing_state[2] += basis[5] * correction;
        }
        for (int axis = 0; axis != 3; ++axis) {
            const float delta = (anchor[0] - framing_state[0]) * basis[axis * 3] +
                                (anchor[1] - framing_state[1]) * basis[axis * 3 + 1] +
                                (anchor[2] - framing_state[2]) * basis[axis * 3 + 2];
            const float limit = extent[axis] *
                (delta < 0.0f ? profile[axis + 3] : profile[axis]);
            if (std::fabs(delta) > limit) {
                const float correction = (std::fabs(delta) - limit) *
                                         (delta < 0.0f ? -1.0f : 1.0f);
                for (int j = 0; j != 3; ++j)
                    framing_state[j] += basis[axis * 3 + j] * correction;
            }
        }
        float spring_target[3] = {2.7f, 2.7f, 2.7f};
        for (int axis = 0; axis != 3; ++axis) {
            const float delta = (anchor[0] - framing_state[0]) * basis[axis * 3] +
                                (anchor[1] - framing_state[1]) * basis[axis * 3 + 1] +
                                (anchor[2] - framing_state[2]) * basis[axis * 3 + 2];
            if (!(skip_axis1 && axis == 1) && std::fabs(delta) >
                    profile[axis + 6] * extent[axis]) {
                spring_target[axis] = (std::fabs(delta) -
                                       profile[axis + 6] * extent[axis]) /
                                      (std::fabs(delta) * frame_step);
                if (spring_target[axis] <= 2.7f)
                    spring_target[axis] = 2.7f;
            }
            AngleSpring_StepBothStages(state + axis * 0x28 + 0x24,
                                       spring_target[axis], frame_step);
        }
        for (int axis = 0; axis != 3; ++axis) {
            if (skip_axis1 && axis == 1)
                continue;
            const float output = *reinterpret_cast<float*>(state + axis * 0x28 + 0x48);
            if (std::fabs(output) > 0.00034f) {
                for (int j = 0; j != 3; ++j)
                    framing_state[j] += basis[axis * 3 + j] * output;
            } else {
                AngleSpring_Reset(state + axis * 0x28 + 0x24, 2.7f);
            }
        }
        camera_transform[3] += framing_state[0] - framing_state[3];
        camera_transform[7] += framing_state[1] - framing_state[4];
        camera_transform[11] += framing_state[2] - framing_state[5];
    }
    std::memcpy(state + 0x18, anchor, 3 * sizeof(float));
}
extern "C" __attribute__((noinline)) void Camera_RebuildTransformFromYawPitch(float* transform, float yaw, float pitch) {
    CameraOrbitTransformView* state = reinterpret_cast<CameraOrbitTransformView*>(transform);
    state->yaw = yaw;
    state->pitch = pitch;
    const float angles[3] = {yaw, pitch, 0.0f};
    float basis[9];
    AngleTriple_ToBasis(basis, 0, angles, 1, g_AimDirectionBasisSeed);
    state->forward[0] = basis[2];
    state->forward[1] = basis[5];
    state->forward[2] = basis[8];
    for (int i = 0; i != 3; ++i)
        state->position[i] = state->focus[i] - state->forward[i] * state->distance;
}
extern uint8_t g_TargetHandleTable[]; // 0x00E11614
extern const float g_FallbackDirection[3]; // 0x00DC249C
static void CameraRuntime_PublishDefaultMotion(CameraActorAimStateView* aim,
                                               float unset) {
    aim->motion_value = 0.0f;
    aim->cached_yaw = unset;
    std::memcpy(aim->cached_target, g_FallbackDirection,
                sizeof(aim->cached_target));
}
extern "C" int Camera_QueryCollisionPushout(float*, float*, const float*,
                                              const float*, const uint8_t*,
                                              const uint8_t*, const float*);
extern "C" void Camera_ApplyCollisionPushout(float*, const float*);
extern "C" void Camera_RebuildCollisionCorrectedTransform(
    uint8_t*, float*, void*, void*, float, const float*, uint64_t,
    uint32_t, int);
void CameraTrack_InterpolatePosition(uint8_t*, float*, const float*,
                                     const float*, float);
extern const uint32_t g_CameraCollisionQueryMask; // 0x00DC24CC
void Camera_UpdateRelativeOffset(uint8_t*, const float*, const float*,
                                 int);
extern "C" void Camera_TransformBuildBasis_006060A4(float*, float);
extern "C" void Camera_TransformInstallCollisionPoint_0060624C(float*,
                                                                  const float*);
extern "C" int Camera_ResolveCollision(void*, float*, void*, void*, float,
                                         float, float, void*, float);
extern "C" int CollisionQuery_ClassifyFlagsAndDispatch(
      void*, void*, unsigned, void*, void*);
extern "C" void CollisionPlane_ProjectPoint_005FE4D0(
    float*, const float*, const float*, float);
extern const float g_CameraTrackCollisionDirection[3]; // 0x00DC24B4
extern const float g_CameraTrackDefaultState[7]; // 0x00DC261C
extern "C" void* Engine_LazySingletonGetter_00498828();
extern "C" void* Engine_LazySingletonGetter_0054EFA8();
extern "C" int FUN_0051CC1C(void*, uint32_t*);
extern "C" void FUN_004C39D8(float* out, void* node, const void* selected_record);
extern "C" void ParameterString_Assign_0043A31C(void* destination,
                                                  const void* source);
void CameraTrack_Reset(uint8_t* track);
extern "C" float* DoubleVec3Spring_Reset_0090AE84(void*, const float*);
extern "C" void DoubleVec3Spring_Retarget_0090AEEC(void*, const float*);
float TimedBlend_Advance(float*, bool, float);
float TimedBlend_SetProgress(float*, float);
extern "C" float TrigKernel_00474934(float);
extern "C" void FUN_0043A3A0(void*, int, int, float);
extern "C" void SourceLinkedRecordDispatch_00463610(void*, int, uint32_t);
extern "C" void FUN_00A2CD60(void*, int);
extern "C" void FUN_00544B98(void*, int, int);
extern "C" void FUN_005B9838(void*, float);
extern "C" void* FUN_004EE6EC(void*);
extern "C" float Engine_EaseHalfCosine_00259B5C(float);
extern "C" float CameraAim_SeedPitchAdjustment_00B17A7C(
    const void*, const uint8_t*, const uint8_t*, const void*, float);
extern "C" uint32_t FUN_00b1a0ec(void*, const void*, int, uint16_t*);
extern "C" bool FUN_0090b458(float*, const float*);
extern "C" bool FUN_0090b3b8(float*, int);
extern "C" void FUN_0090bba4(float*, int, const float*, int, const float*);
extern "C" bool Vec3_ComputeYawIfInRange_0090B458(float*, const float*);
extern "C" bool Vec3_IsPitchInRange_0090BA44(const float*);
extern "C" void Basis3x3_ToEulerAngles(float*, const float*);
extern "C" void* ActorStatusLinkDescriptor_Resolve(void*);
extern "C" void* OrderedTree_LowerBoundByPointer_004C5D3C(void*, const void*);
extern "C" void* FUN_005000C0();
extern "C" void* FUN_004FD924();
extern "C" void* FUN_004FDD34();
extern "C" __attribute__((noinline)) float ActorTarget_ReadNestedFloat_006D54F8(const uint8_t* object) {
    const uint8_t* const nested = *reinterpret_cast<const uint8_t* const*>(object + 0x3c);
    return nested == 0 ? 0.0f : *reinterpret_cast<const float*>(nested + 0x74);
}
extern "C" __attribute__((noinline)) float ActorTarget_ReadNestedFloat_006D3B2C(const uint8_t* object) {
    const uint8_t* const nested = *reinterpret_cast<const uint8_t* const*>(object + 0x1d0);
    return nested == 0 ? 0.0f : *reinterpret_cast<const float*>(nested + 0x2c);
}
extern "C" __attribute__((noinline)) float ActorTarget_ReadNestedFloat_00639F38(const uint8_t* object) {
    const uint8_t* const nested = *reinterpret_cast<const uint8_t* const*>(object + 0x3c);
    return nested == 0 ? 0.0f : *reinterpret_cast<const float*>(nested + 0x74);
}
extern "C" __attribute__((noinline)) float ActorTarget_ReadNestedFloat_00639534(const uint8_t* object) {
    const uint8_t* const nested = *reinterpret_cast<const uint8_t* const*>(object + 0x1a8);
    return nested == 0 ? 0.0f : *reinterpret_cast<const float*>(nested + 0x2c);
}
extern "C" __attribute__((noinline)) float ActorTarget_ReadNestedFloat_0063AFB8(const uint8_t* object) {
    const uint8_t* const nested = *reinterpret_cast<const uint8_t* const*>(object + 0x1d4);
    return nested == 0 ? 0.0f : *reinterpret_cast<const float*>(nested + 0x4d0);
}
extern "C" __attribute__((noinline)) float ActorTarget_ReadNestedFloat_0063BD44(const uint8_t* object) {
    const uint8_t* const nested = *reinterpret_cast<const uint8_t* const*>(object + 0x3c);
    return nested == 0 ? 0.0f : *reinterpret_cast<const float*>(nested + 0x74);
}
extern "C" bool Engine_ObjectMatchesGlobalClass(void*);
extern "C" void* Engine_RiderDescriptorRegistry_Get();
extern "C" void* ResourceTable_Lookup(void*);
extern "C" void* FUN_00520480(const void* actor = 0);
extern "C" int FUN_002A1224(void*);
extern "C" uint32_t FUN_004A4AA0();
extern "C" __attribute__((noinline)) bool ActorTarget_KindMatchesGlobalPair_00A2C7F0(const void* object) {
    const uint8_t* const descriptor = *reinterpret_cast<const uint8_t* const*>(
        static_cast<const uint8_t*>(object) + 0x168);
    const void* kind = *reinterpret_cast<const void* const*>(descriptor + 0x08);
    return kind == *reinterpret_cast<const void* const*>(0x00C9B968) ||
           kind == *reinterpret_cast<const void* const*>(0x00C9B964);
}
extern "C" __attribute__((noinline)) bool ActorTarget_IsGlobalKind_00A2CE78(const void* kind) {
    return kind == *reinterpret_cast<const void* const*>(0x00C9B9B4) ||
           kind == *reinterpret_cast<const void* const*>(0x00C9B9AC) ||
           kind == *reinterpret_cast<const void* const*>(0x00C9B9B0);
}
extern "C" __attribute__((noinline)) bool ActorTarget_IsCurrentGlobal_00A2BEBC(const void* value) {
    return value == *reinterpret_cast<const void* const*>(0x00C9B9C4);
}
extern "C" __attribute__((noinline)) int ActorTarget_MapMode_006D5154(const uint8_t* object) {
    const int mode = static_cast<int8_t>(object[0x1d4]);
    return mode >= 0 && mode <= 6 ? mode : -1;
}
extern "C" __attribute__((noinline)) int ActorTarget_MapStatusMode_00639BE0(const uint8_t* object) {
    const int8_t mode = static_cast<int8_t>(object[0x1ac]);
    int result = -1;
    if (mode == 0) result = 0;
    else if (mode == 1) result = 1;
    else if (mode == 2) result = 3;
    else if (mode == 3) result = 6;
    return result;
}
extern "C" __attribute__((noinline)) int ActorTarget_MapResourceMode_0063B3E0(const uint8_t* object) {
    switch (static_cast<int8_t>(object[0x1dc])) {
    case 0: return 7;
    case 1: return 8;
    case 2: return 9;
    case 3: return 0;
    case 4: return 1;
    case 5: return 12;
    case 6: return 3;
    case 7: return 13;
    case 8: return 6;
    case 9: return 14;
    default: return -1;
    }
}
extern "C" __attribute__((noinline)) int ActorTarget_SelectModeResource_00A2E67C(
    const uint8_t* actor) {
    uint8_t* descriptor = static_cast<uint8_t*>(FUN_00520480());
    if (descriptor == 0) return -1;
    void* (*key_provider)();
    int (*mode_mapper)(const uint8_t*);
    switch (static_cast<int8_t>(descriptor[0x50])) {
    case 0:
        key_provider = FUN_005000C0;
        mode_mapper = ActorTarget_MapMode_006D5154;
        break;
    case 1:
        key_provider = FUN_004FD924;
        mode_mapper = ActorTarget_MapStatusMode_00639BE0;
        break;
    case 2:
        key_provider = FUN_004FDD34;
        mode_mapper = ActorTarget_MapResourceMode_0063B3E0;
        break;
    default:
        return -1;
    }
    void* node = OrderedTree_LowerBoundByPointer_004C5D3C(
        const_cast<uint8_t*>(actor) + 0x1a4, key_provider());
    void* selected = node == 0 ? 0 : *reinterpret_cast<void**>(node);
    void* cached = *reinterpret_cast<void* const*>(actor + 0x1a8);
    if (selected == cached || selected == 0) return -1;
    return mode_mapper(static_cast<const uint8_t*>(selected));
}
extern "C" __attribute__((noinline)) void ActorTarget_UpdateModeResourceValues_00A2E7BC(
    float* first, float* second, uint8_t* actor) {
    void* descriptor = FUN_00520480(actor);
    if (descriptor == 0) return;
    const int mode = static_cast<int8_t>(
        *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(descriptor) + 0x50));
    if (mode == 0) {
        float first_value = 0.0f;
        void* node = OrderedTree_LowerBoundByPointer_004C5D3C(actor + 0x1a4, FUN_005000C0());
        void* link = node == 0 ? 0 : *reinterpret_cast<void**>(node);
        void* cached = *reinterpret_cast<void**>(actor + 0x1a8);
        if (link != cached && link != 0)
            first_value = ActorTarget_ReadNestedFloat_006D54F8(
                static_cast<const uint8_t*>(link));
        *first = first_value;
        cached = *reinterpret_cast<void**>(actor + 0x1a8);
        node = OrderedTree_LowerBoundByPointer_004C5D3C(actor + 0x1a4, FUN_005000C0());
        link = node == 0 ? 0 : *reinterpret_cast<void**>(node);
        if (link != cached && link != 0)
            *second = ActorTarget_ReadNestedFloat_006D3B2C(
                static_cast<const uint8_t*>(link));
        else
            *second = 0.0f;
        return;
    }
    if (mode == 1) {
        float first_value = 0.0f;
        void* node = OrderedTree_LowerBoundByPointer_004C5D3C(actor + 0x1a4, FUN_004FD924());
        void* link = node == 0 ? 0 : *reinterpret_cast<void**>(node);
        void* cached = *reinterpret_cast<void**>(actor + 0x1a8);
        if (link != cached && link != 0)
            first_value = ActorTarget_ReadNestedFloat_00639F38(
                static_cast<const uint8_t*>(link));
        *first = first_value;
        cached = *reinterpret_cast<void**>(actor + 0x1a8);
        node = OrderedTree_LowerBoundByPointer_004C5D3C(actor + 0x1a4, FUN_004FD924());
        link = node == 0 ? 0 : *reinterpret_cast<void**>(node);
        if (link != cached && link != 0)
            *second = ActorTarget_ReadNestedFloat_00639534(
                static_cast<const uint8_t*>(link));
        else
            *second = 0.0f;
        return;
    }
    if (mode != 2) return;
    float first_value = 0.0f;
    void* node = OrderedTree_LowerBoundByPointer_004C5D3C(actor + 0x1a4, FUN_004FDD34());
    void* link = node == 0 ? 0 : *reinterpret_cast<void**>(node);
    void* cached = *reinterpret_cast<void**>(actor + 0x1a8);
    if (link != cached && link != 0)
        first_value = ActorTarget_ReadNestedFloat_0063BD44(
            static_cast<const uint8_t*>(link));
    *first = first_value;
    cached = *reinterpret_cast<void**>(actor + 0x1a8);
    node = OrderedTree_LowerBoundByPointer_004C5D3C(actor + 0x1a4, FUN_004FDD34());
    link = node == 0 ? 0 : *reinterpret_cast<void**>(node);
    if (link != cached && link != 0)
        *second = ActorTarget_ReadNestedFloat_0063AFB8(
            static_cast<const uint8_t*>(link));
    else
        *second = 0.0f;
}
extern "C" __attribute__((noinline)) void* ActorTarget_ResolveComponent_001307E4(
    uint8_t* actor, void* fallback) {
    if (Engine_ObjectMatchesGlobalClass(actor)) {
        void* node = OrderedTree_LowerBoundByPointer_004C5D3C(
            actor + 0x1a4, Engine_RiderDescriptorRegistry_Get());
        void* selected = node == 0 ? 0 : *reinterpret_cast<void**>(node);
        void* cached = *reinterpret_cast<void**>(actor + 0x1a8);
        if (selected != cached && selected != 0) {
            void* resource = ResourceTable_Lookup(
                static_cast<uint8_t*>(selected) + 0x34);
            if (resource != 0) {
                void* descriptor = FUN_00520480();
                if (descriptor != 0 &&
                    *reinterpret_cast<uint8_t*>(
                        static_cast<uint8_t*>(descriptor) + 0x96) == 0) {
                    return static_cast<uint8_t*>(descriptor) + 0x1c;
                }
            }
        }
        return 0;
    }
    if (FUN_002A1224(actor) != 0) return 0;
    if (fallback != 0) return static_cast<uint8_t*>(fallback) + 0x74;
    const uint32_t key = FUN_004A4AA0();
    uint8_t* sentinel = reinterpret_cast<uint8_t*>(actor + 0x1a8);
    uint8_t* node = *reinterpret_cast<uint8_t**>(actor + 0x1ac);
    uint8_t* parent = sentinel;
    while (node[0x10] != 0) {
        parent = node;
        if (*reinterpret_cast<uint32_t*>(node + 0x14) < key) {
            node = *reinterpret_cast<uint8_t**>(node + 0x0c);
        } else {
            node = *reinterpret_cast<uint8_t**>(node + 0x08);
        }
    }
    if (parent == sentinel || key < *reinterpret_cast<uint32_t*>(parent + 0x14)) {
        parent = sentinel;
    }
    void* selected = parent == 0 ? 0 : *reinterpret_cast<void**>(parent);
    if (selected != 0 && selected != *reinterpret_cast<void**>(actor + 0x1a8)) {
        return static_cast<uint8_t*>(selected) + 0x74;
    }
    return 0;
}
typedef bool(*StatusResourcePredicate)(void*);
extern "C" __attribute__((noinline)) bool ActorTarget_StatusLinkPredicate_00A2CCA0(
    const uint8_t* actor) {
    void* status_link = ActorStatusLinkDescriptor_Resolve(
        const_cast<uint8_t*>(actor));
    void* cached = *reinterpret_cast<void* const*>(actor + 0x1a8);
    if (status_link == 0 || status_link == cached) return false;
    void* resource = *reinterpret_cast<void**>(
        static_cast<uint8_t*>(status_link) + 0x58);
    if (resource == 0) return false;
    StatusResourcePredicate* vtable = *reinterpret_cast<StatusResourcePredicate**>(resource);
    return vtable[2](resource);
}
extern "C" __attribute__((noinline)) bool ActorTarget_StatusLinkPredicate_00A2D1A0(
    const uint8_t* actor) {
    void* status_link = ActorStatusLinkDescriptor_Resolve(
        const_cast<uint8_t*>(actor));
    void* cached = *reinterpret_cast<void* const*>(actor + 0x1a8);
    if (status_link == 0 || status_link == cached) return false;
    void* resource = *reinterpret_cast<void**>(
        static_cast<uint8_t*>(status_link) + 0x58);
    if (resource == 0) return false;
    StatusResourcePredicate* vtable = *reinterpret_cast<StatusResourcePredicate**>(resource);
    return !vtable[3](resource) && vtable[2](resource);
}
extern "C" bool Vec3_NormalizeAndGetLength(float*, float*, const float*);
extern "C" float Vec3_ComputePitch(const float*);
extern "C" float ClampedAcos(float);
extern "C" float InverseLerpClamped(float, float, float);
extern const float g_AimDirectionBasisSeed[]; // 0x00DC25AC
extern "C" void FUN_00588dd8(void*, float, float);
extern "C" float FUN_00b0d4a0(const void*, float);
extern "C" float Camera_UpdateActorOcclusionDistanceScale(
    void*, const void*, const void*, const void*, float, float);
extern "C" void* Engine_ForEachStrideCallback_00421EA4(
    void* out, void* callback, uint32_t stride, uint32_t count);
extern "C" void* Engine_ComponentRegistryGetter_004C58E0();
extern "C" void FUN_003ACDE4(float* out_basis, const float* direction,
                              const float* seed_basis);
extern const float g_CameraTrackCollisionDirection[3]; // DAT_007C9700 -> 0x00DC24B4
extern "C" float Vec3_ComputeYaw(const float*);
extern "C" float WrapAngleRadians(float);
extern "C" float* DoubleVec3Spring_Step_0090AEBC(void*, const float*);
extern "C" bool DoubleVec3Spring_IsSettled_00B461B0(const void*, const float*);
extern "C" void Camera_RebuildTransformFromYawPitch(float*, float, float);
extern "C" bool Camera_IsTrackedTarget_00A2CE30(void*);
extern "C" void FUN_00704008(void*, const float*, const void*, float, float);
extern "C" void Camera_ActorUpdateSpringState_0070457C(
    uint8_t*, const void*, float, float);
extern "C" void FUN_0083322C(void*, int, void*, void*, const float*,
                              const void*, int, float);
extern "C" void CameraMode3_UpdateActivationGate_0082200C(
    uint8_t*, const uint8_t*, const uint8_t*, int,
    const void*, float);
extern "C" bool CameraYawImpulse_IsActive(void*, void*);
extern "C" bool Camera_TargetRelativeTransitionReady_0080A2EC(
    const uint8_t*, const uint8_t*, const void*);
extern "C" bool Camera_OverrideControllerSelect_00809BEC(
    uint8_t*, int, const void*, int);
extern "C" bool Camera_Mode5OverrideGate_007F0524(
    uint8_t*, const uint8_t*, const void*, const void*, int);
extern "C" const uint8_t* Engine_ReticleContextResource_00A9B988(
    const void*);
extern "C" bool Camera_Mode3ControllerIsActive_00821FC8(
    const uint8_t*);
extern "C" bool DoubleVec3Spring_IsSettledWithThreshold_00B46260(
    const void*, const float*, float);
extern "C" bool Camera_TrackedOverrideGate_008175CC(
    uint8_t*, const uint8_t*, const void*, const void*, int);
extern "C" int Camera_SpecialTargetMode_00B1A8B0(
    const void*, const uint8_t*);
extern "C" void* Engine_ThresholdAuxAllocator_00475D70(...);
extern "C" void* FUN_005c2978(void*, int);
extern "C" void* Engine_SharedResourceSingleton_00422D20();
extern "C" void FUN_004aef14(void*, uint32_t);
extern "C" void* FUN_00a2bbd0();
extern uint8_t* g_FovDefaultSingleton;
extern uint8_t* g_FovOverrideSingleton;
extern "C" float UpdateKeyedTransition_00745F58(void*, bool*, bool*, int, float);
extern "C" void AngleSpring_IntegrateSample(void*, float);
extern "C" bool AngleSpring_IsSettled_Thunk(void*, float, float);
extern "C" void FUN_00b17a18(const void*, void*, void*);
extern "C" void BoneTransform_TransformPoint(float* out, const float* point,
                                               const void* transform, const void* alternate,
                                               const void* selected_record);
__attribute__((noinline)) bool Camera_TargetOverride_ClampYaw_00809C5C(const uint8_t* state,
                                              float* out_yaw, float* out_pitch,
                                              const float* camera_transform) {
    *out_yaw = *reinterpret_cast<const float*>(state + 0x64);
    *out_pitch = *reinterpret_cast<const float*>(state + 0x68);
    if (state[0x6c] != 1) return false;
    const float dx = camera_transform[9] -
                     *reinterpret_cast<const float*>(state + 0xfc);
    const float dz = camera_transform[11] -
                     *reinterpret_cast<const float*>(state + 0x104);
    const float distance = std::sqrt(dx * dx + dz * dz);
    if (distance <= 0.0f) return true;
    const float ratio = InverseLerpClamped(distance, 10.0f, 100.0f);
    if (ratio <= 0.0f) return true;
    const float half_window = ratio >= 1.0f
        ? DAT_00809DB4.minimum_window_004
        : DAT_00809DB4.pi_000 + DAT_00809DB4.window_slope_008 * ratio;
    const float center = *reinterpret_cast<const float*>(state + 0x64);
    const float upper = WrapAngleRadians(center + half_window);
    const float lower = WrapAngleRadians(center - half_window);
    const float span = WrapAngleRadians(upper - lower);
    const float camera_yaw = camera_transform[13];
    const float to_lower = WrapAngleRadians(lower - camera_yaw);
    const float to_upper = WrapAngleRadians(upper - camera_yaw);
    bool inside = span * to_lower <= 0.0f && 0.0f <= span * to_upper;
    if (half_window > DAT_00809DB4.half_turn_00c) inside = !inside;
    if (!inside)
        *out_yaw = std::fabs(to_upper) <= std::fabs(to_lower) ? upper : lower;
    return inside;
}
extern "C" __attribute__((noinline)) void BoneTransform_TransformPoint(float* out, const float* point,
                                               const void* transform, const void* alternate,
                                               const void* selected_record) {
    if (selected_record != 0) {
        float m[12] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                       0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
        FUN_004C39D8(m, const_cast<void*>(alternate),
                     const_cast<void*>(selected_record));
        const float x = point[0];
        const float y = point[1];
        const float z = point[2];
        out[0] = m[0] * x + m[1] * y + m[2] * z + m[3];
        out[1] = m[4] * x + m[5] * y + m[6] * z + m[7];
        out[2] = m[8] * x + m[9] * y + m[10] * z + m[11];
        return;
    }
    const uint8_t* base = static_cast<const uint8_t*>(alternate != 0 ? alternate
                                                                               : transform);
    const float* source = reinterpret_cast<const float*>(base + 0x40);
    const float x = source[1], y = source[2], z = source[3], w = source[4];
    const float scale = source[0];
    const float xx = 2.0f * x * x, yy = 2.0f * y * y, zz = 2.0f * z * z;
    const float xy = 2.0f * x * y, xz = 2.0f * x * z, yz = 2.0f * y * z;
    const float xw = 2.0f * x * w, yw = 2.0f * y * w, zw = 2.0f * z * w;
    out[0] = scale * ((1.0f - yy - zz) * point[0] + (xy - zw) * point[1] +
                      (xz + yw) * point[2]) + source[5];
    out[1] = scale * ((xy + zw) * point[0] + (1.0f - xx - zz) * point[1] +
                      (yz - xw) * point[2]) + source[6];
    out[2] = scale * ((xz - yw) * point[0] + (yz + xw) * point[1] +
                      (1.0f - xx - yy) * point[2]) + source[7];
}
void Camera_UpdateTargetOverride(void* state, float* camera_transform,
                                 void* actor_state, void* framing_state,
                                 void* target_state, unsigned int active_mode,
                                 void* mode_state, float frame_step);
// Semantic reconstruction, JP Rev 1: 0x006D6C18.
__attribute__((noinline)) void* Camera_GetActorReticle(void* camera) {
    const void* holder = *reinterpret_cast<void**>(static_cast<uint8_t*>(camera) + 0x08);
    return *reinterpret_cast<void* const*>(static_cast<const uint8_t*>(holder) + 0x28);
}
// Semantic reconstruction, JP Rev 1: 0x006D6C24 core world-anchor equation.
void CameraActorAimState_ComputeWorldAim(void* state, const void* profile) {
    CameraActorAimStateView* aim = static_cast<CameraActorAimStateView*>(state);
    const uint8_t* params = static_cast<const uint8_t*>(profile);
    const float far_distance = *reinterpret_cast<const float*>(params + 0x98);
    const float near_distance = *reinterpret_cast<const float*>(params + 0xb0);
    const float distance = near_distance +
                           (far_distance - near_distance) * aim->spring.value;
    aim->world_anchor[0] = aim->base_translation[0] + aim->forward_x * distance;
    aim->world_anchor[1] = aim->base_translation[1] + aim->forward_y * distance;
    aim->world_anchor[2] = aim->base_translation[2] + aim->forward_z * distance;
}
struct ActorReticleTargetTrackingView {
    uint8_t opaque_000[0xf8];
    int32_t lifetime;
    float elapsed;
    void* target_geometry;
    void* target_component;
    uint8_t opaque_108[0x0c];
    float stabilized_direction[3];
    uint8_t opaque_120[0x0c];
    float previous_geometry_position[3];
    uint8_t opaque_138[0x0c];
    uint8_t special_geometry;
};
typedef char kiu_sa_camera_runtime_34[(offsetof(ActorReticleTargetTrackingView, lifetime) == 0xf8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_35[(offsetof(ActorReticleTargetTrackingView, target_geometry) == 0x100) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_36[(offsetof(ActorReticleTargetTrackingView, target_component) == 0x104) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_37[(offsetof(ActorReticleTargetTrackingView, stabilized_direction) == 0x114) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_38[(offsetof(ActorReticleTargetTrackingView, previous_geometry_position) == 0x12c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_runtime_39[(offsetof(ActorReticleTargetTrackingView, special_geometry) == 0x144) ? 1 : -1] __attribute__((unused));
__attribute__((noinline)) void ActorReticle_UpdateTargetTracking(uint8_t* reticle,
                                       const uint8_t* target_actor,
                                       float frame_step) {
    ActorReticleTargetTrackingView* state = reinterpret_cast<ActorReticleTargetTrackingView*>(reticle);
    if (state->target_geometry == 0) {
        state->lifetime = 0;
        state->elapsed = 0.0f;
        state->target_component = 0;
        state->previous_geometry_position[0] = 3.402823466e38f;
        state->previous_geometry_position[1] = 3.402823466e38f;
        state->previous_geometry_position[2] = 3.402823466e38f;
        state->special_geometry = 0;
        return;
    }
    ++state->lifetime;
    state->elapsed += frame_step;
    void* status_link = ActorStatusLinkDescriptor_Resolve(
        const_cast<uint8_t*>(target_actor));
    state->target_component = status_link == 0
        ? 0
        : *reinterpret_cast<void**>(static_cast<uint8_t*>(status_link) + 0x1c);
    const uint8_t* geometry = static_cast<const uint8_t*>(state->target_geometry);
    const float* source_direction = Vec3_IsPitchInRange_0090BA44(
        reinterpret_cast<const float*>(geometry + 0x70))
        ? reinterpret_cast<const float*>(geometry + 0x70)
        : state->stabilized_direction;
    float target_yaw = 0.0f;
    Vec3_ComputeYawIfInRange_0090B458(&target_yaw, source_direction);
    float pitch = 0.0f;
    if (state->previous_geometry_position[0] != 3.402823466e38f) {
        float direction[3] = {
            *reinterpret_cast<const float*>(geometry + 0x7c) -
                state->previous_geometry_position[0],
            *reinterpret_cast<const float*>(geometry + 0x80) -
                state->previous_geometry_position[1],
            *reinterpret_cast<const float*>(geometry + 0x84) -
                state->previous_geometry_position[2],
        };
        if (!Vec3_NormalizeAndGetLength(direction, 0, direction)) {
            direction[0] = *reinterpret_cast<const float*>(reticle + 0x108);
            direction[1] = *reinterpret_cast<const float*>(reticle + 0x10c);
            direction[2] = *reinterpret_cast<const float*>(reticle + 0x110);
        }
        pitch = Vec3_ComputePitch(direction);
        if (pitch < -1.5533430576f)
            pitch = -1.5533430576f;
        else if (pitch > 1.5533430576f)
            pitch = 1.5533430576f;
    }
    const float angles[3] = {target_yaw, pitch, 0.0f};
    float basis[9];
    AngleTriple_ToBasis(basis, 0, angles, 1,
                        reinterpret_cast<const float*>(0x00DC2588));
    state->stabilized_direction[0] = basis[2];
    state->stabilized_direction[1] = basis[5];
    state->stabilized_direction[2] = basis[8];
    if (state->lifetime < 5 || state->special_geometry == 1) {
        TimedBlend_SetProgress(reinterpret_cast<float*>(reticle + 0x138), 0.0f);
        if (state->lifetime >= 5 && state->special_geometry == 1) {
            std::memcpy(reticle + 0x120, reticle + 0x108, 3 * sizeof(float));
        }
    }
    TimedBlend_Advance(reinterpret_cast<float*>(reticle + 0x138), true,
                       frame_step);
    float progress = *reinterpret_cast<const float*>(reticle + 0x13c);
    if (progress >= 1.0f) {
        std::memcpy(reticle + 0x108, reticle + 0x114, 3 * sizeof(float));
    } else {
        float eased = progress;
        if (progress > 0.0f) {
            eased = 0.5f - 0.5f * TrigKernel_00474934(
                progress * 3.14159265358979323846f);
        }
        float blended[3];
        for (int i = 0; i != 3; ++i) {
            const float previous =
                *reinterpret_cast<const float*>(reticle + 0x120 + i * 4);
            const float current =
                *reinterpret_cast<const float*>(reticle + 0x114 + i * 4);
            blended[i] = previous + (current - previous) * eased;
        }
        if (Vec3_NormalizeAndGetLength(blended, 0, blended)) {
            std::memcpy(reticle + 0x108, blended, 3 * sizeof(float));
        }
    }
    std::memcpy(state->previous_geometry_position, geometry + 0x7c,
                3 * sizeof(float));
    state->special_geometry = 0;
}
extern "C" __attribute__((noinline)) void CameraActorAimState_UpdateBasisFromActor(
    uint8_t* reticle, const uint8_t* target_actor, float frame_step) {
    const uint8_t* basis_source = target_actor;
    const uint8_t* position_source = target_actor;
    if (basis_source == 0) {
        const uint8_t* const holder = *reinterpret_cast<const uint8_t* const*>(reticle + 0x04);
        basis_source = holder != 0
            ? *reinterpret_cast<const uint8_t* const*>(holder + 0x24)
            : 0;
        position_source = *reinterpret_cast<const uint8_t* const*>(reticle + 0x28);
        if (basis_source == 0) basis_source = position_source;
    }
    if (basis_source == 0 || position_source == 0) return;
    const float x = *reinterpret_cast<const float*>(basis_source + 0x44);
    const float y = *reinterpret_cast<const float*>(basis_source + 0x48);
    const float z = *reinterpret_cast<const float*>(basis_source + 0x4c);
    const float w = *reinterpret_cast<const float*>(basis_source + 0x50);
    const float xx = 2.0f * x * x;
    const float yy = 2.0f * y * y;
    const float zz = 2.0f * z * z;
    const float xy = 2.0f * x * y;
    const float xz = 2.0f * x * z;
    const float yz = 2.0f * y * z;
    const float xw = 2.0f * x * w;
    const float yw = 2.0f * y * w;
    const float zw = 2.0f * z * w;
    float basis[9] = {
        1.0f - yy - zz, xy - zw,       xz + yw,
        xy + zw,       1.0f - xx - zz, yz - xw,
        xz - yw,       yz + xw,        1.0f - xx - yy,
    };
    float angles[3];
    const bool mode_zero = reticle[0xe1] == 0;
    float spring_target = 0.0f;
    if (mode_zero || !AngleSpring_IsSettled_Thunk(reticle + 0x1ac, 0.0f, 0.0f)) {
        Basis3x3_ToEulerAngles(angles, basis);
        if (mode_zero &&
            *reinterpret_cast<const float*>(reticle + 0x1d4) !=
                3.402823466e38f &&
            *reinterpret_cast<const float*>(reticle + 0xf0) > 0.0f) {
            float target_yaw = 0.0f;
            Vec3_ComputeYawIfInRange_0090B458(
                &target_yaw, reinterpret_cast<const float*>(reticle + 0x1d4));
            const float delta = WrapAngleRadians(target_yaw - angles[0]);
            const float magnitude = std::fabs(delta);
            float blend;
            if (magnitude < 1.5707963705062866f)
                blend = InverseLerpClamped(magnitude, 0.3490658402442932f,
                                           1.3962633609771729f);
            else
                blend = 1.0f - InverseLerpClamped(
                    magnitude, 1.7453292608261108f, 2.4434609413146973f);
            // Clamp written out; see the note on the other clamp above.
            if (blend < 0.0f)
                blend = 0.0f;
            else if (blend > 1.0f)
                blend = 1.0f;
            blend = blend * 0.5235987901687622f;
            spring_target = delta < 0.0f ? -blend : blend;
        }
        AngleSpring_StepBothStages(reticle + 0x1ac, spring_target);
        if (!AngleSpring_IsSettled_Thunk(reticle + 0x1ac, 0.0f, 0.0f)) {
            angles[0] = WrapAngleRadians(
                angles[0] + *reinterpret_cast<const float*>(reticle + 0x1d0));
            AngleTriple_ToBasis(basis, 0, angles, 1,
                                reinterpret_cast<const float*>(0x00DC2588));
        }
    }
    *reinterpret_cast<float*>(reticle + 0x1d4) = 0.0f;
    *reinterpret_cast<float*>(reticle + 0x1d8) = 0.0f;
    *reinterpret_cast<float*>(reticle + 0x1dc) = 0.0f;
    const float pitch_vector[3] = {basis[2], basis[5], basis[8]};
    if (Vec3_IsPitchInRange_0090BA44(pitch_vector)) {
        *reinterpret_cast<float*>(reticle + 0x74) = basis[0];
        *reinterpret_cast<float*>(reticle + 0x78) = basis[1];
        *reinterpret_cast<float*>(reticle + 0x7c) = basis[2];
        *reinterpret_cast<float*>(reticle + 0x84) = basis[3];
        *reinterpret_cast<float*>(reticle + 0x88) = basis[4];
        *reinterpret_cast<float*>(reticle + 0x8c) = basis[5];
        *reinterpret_cast<float*>(reticle + 0x94) = basis[6];
        *reinterpret_cast<float*>(reticle + 0x98) = basis[7];
        *reinterpret_cast<float*>(reticle + 0x9c) = basis[8];
    }
    *reinterpret_cast<float*>(reticle + 0x80) =
        *reinterpret_cast<const float*>(position_source + 0x54);
    *reinterpret_cast<float*>(reticle + 0x90) =
        *reinterpret_cast<const float*>(position_source + 0x58);
    *reinterpret_cast<float*>(reticle + 0xa0) =
        *reinterpret_cast<const float*>(position_source + 0x5c);
    (void)frame_step;
}
__attribute__((noinline)) void ActorReticle_UpdateWorldAimState(uint8_t* reticle,
                                      const void* camera_position,
                                      const void* framing_profile,
                                      int reset, float frame_step) {
    CameraActorAimStateView* aim = reinterpret_cast<CameraActorAimStateView*>(reticle);
    const uint8_t* camera = static_cast<const uint8_t*>(camera_position);
    float spring_target = 1.0f;
    if (aim->mode_024 == 1) {
        spring_target = InverseLerpClamped(
            *reinterpret_cast<const float*>(camera + 0x30), 10.0f, 30.0f);
    }
    if (reset != 0) {
        const float kUnset = 0x1.fffffep+126f;
        std::memcpy(aim->previous_translation, aim->base_translation,
                    sizeof(aim->previous_translation));
        aim->stable_0b8 = 1;
        aim->stable_time = 0.0f;
        aim->mode1_ready = 0;
        aim->tracking_active = 0;
        aim->tracking_ready = 0;
        aim->mode1_timer = 0.0f;
        aim->cooldown = 0.0f;
        aim->tracking_time = 0.0f;
        aim->mode1_value = 0.0f;
        aim->target_lifetime = aim->target_lifetime < 2 ? aim->target_lifetime : 1;
        aim->target_elapsed = 0.0f;
        aim->reset_sentinel[0] = kUnset;
        aim->reset_sentinel[1] = kUnset;
        aim->reset_sentinel[2] = kUnset;
        AngleSpring_Reset(&aim->spring, spring_target);
    } else {
        AngleSpring_StepBothStages(&aim->spring, spring_target, frame_step);
    }
    CameraActorAimState_ComputeWorldAim(aim, framing_profile);
    const float kUnset = 0x1.fffffep+126f;
    if (reset != 0 || aim->target_active != 0 || aim->target_lifetime > 0 ||
        aim->special_geometry != 1) {
        CameraRuntime_PublishDefaultMotion(aim, kUnset);
    } else {
        const float target_x = aim->target_position[0];
        const float target_y = aim->target_position[1];
        const float target_z = aim->target_position[2];
        const float dx = target_x - aim->previous_target_x;
        const float dz = target_z - aim->previous_target_z;
        const float horizontal_distance = std::sqrt(dx * dx + dz * dz);
        bool candidate_valid = false;
        float candidate = 0.0f;
        if (aim->previous_target_x != kUnset &&
            horizontal_distance > 3.0f &&
            aim->previous_target_y < target_y) {
            const float kAngleUnitsToScale = 0.02454369328916073f;
            const float kThreeAngleUnits = 3.0f;
            const float kOutputScale = 0.05235987901687622f;
            candidate = (AngleUnitsAtan2(
                target_y - aim->previous_target_y,
                horizontal_distance) * kAngleUnitsToScale - kThreeAngleUnits) *
                       kOutputScale;
            candidate_valid = true;
        }
        const float cached_yaw = aim->cached_yaw;
        const float current_yaw = *reinterpret_cast<const float*>(camera + 0x34);
        const float yaw_delta = WrapAngleRadians(current_yaw - cached_yaw);
        const float px = target_x - aim->cached_target[0];
        const float py = target_y - aim->cached_target[1];
        const float pz = target_z - aim->cached_target[2];
        const bool within_gate = cached_yaw == current_yaw ||
            (std::fabs(yaw_delta) <= 0x1.becde6p-2f &&
             px * px + py * py + pz * pz <= 1600.0f);
        if (!within_gate || !candidate_valid ||
            candidate <= aim->motion_value - 0x1.e68a0ep-16f) {
            CameraRuntime_PublishDefaultMotion(aim, kUnset);
        } else {
            aim->motion_value = candidate;
            aim->cached_yaw = current_yaw;
            aim->cached_target[0] = target_x;
            aim->cached_target[1] = target_y;
            aim->cached_target[2] = target_z;
        }
    }
    aim->previous_target_x = kUnset;
    aim->previous_target_y = kUnset;
    aim->previous_target_z = kUnset;
}
extern "C" __attribute__((noinline)) float CameraAim_SeedPitchAdjustment_00B17A7C(
    const void*, const uint8_t* reticle,
    const uint8_t* framing_profile, const void* enabled,
    float camera_yaw) {
    float result = *reinterpret_cast<const float*>(framing_profile + 0xa0);
    if (enabled == 0 ||
        *reinterpret_cast<const int32_t*>(framing_profile + 0xa4) != 1)
        return result;
    float direction[3];
    float pitch;
    if (*reinterpret_cast<const int32_t*>(reticle + 0xf8) > 0) {
        std::memcpy(direction, reticle + 0x108, sizeof(direction));
        pitch = Vec3_ComputePitch(direction);
        float length = 0.0f;
        if (!Vec3_NormalizeAndGetLength(direction, &length, direction))
            return result;
        const float dot = direction[0] * TrigKernel_0049A9DC(camera_yaw) +
                          direction[2] * TrigKernel_00474934(camera_yaw);
        const float blend = InverseLerpClamped(length, 0.0f, 0.3f);
        pitch += (pitch * dot - pitch) * blend;
        return result + pitch;
    }
    if (reticle[0x145] != 1)
        return result;
    direction[0] = *reinterpret_cast<const float*>(reticle + 0x154);
    direction[1] = 0.0f;
    direction[2] = *reinterpret_cast<const float*>(reticle + 0x15c);
    if (!Vec3_NormalizeAndGetLength(direction, 0, direction))
        return result;
    const float dot = direction[0] * TrigKernel_0049A9DC(camera_yaw) +
                      direction[2] * TrigKernel_00474934(camera_yaw);
    const float blend = InverseLerpClamped(ClampedAcos(dot), 0.0f,
                                           3.14159265358979323846f);
    const uint8_t* const owner = *reinterpret_cast<const uint8_t* const*>(
        framing_profile);
    const float scale = *reinterpret_cast<const float*>(owner + 0x34);
    float correction = (blend - 0.5f) * -2.0f *
                       *reinterpret_cast<const float*>(reticle + 0x160) * scale;
    // Clamp written out; std::fmax/std::fmin are C++11.
    if (correction > 0.7853981633974483f)
        correction = 0.7853981633974483f;
    if (correction < -0.7853981633974483f)
        correction = -0.7853981633974483f;
    return result + correction;
}
__attribute__((noinline)) void Camera_UpdateAimDirection(uint8_t* aim_state,
                               const uint8_t* reticle,
                               const uint8_t* camera_position,
                               const uint8_t* target_state,
                               const void* framing_profile,
                               const void* mode_state) {
    *reinterpret_cast<uint32_t*>(aim_state + 0x1c) = 0;
    if (*reinterpret_cast<const uint32_t*>(aim_state + 0x18) != 0) {
        uint16_t marker = 0xffff;
        *reinterpret_cast<uint32_t*>(aim_state + 0x1c) =
            FUN_00b1a0ec(aim_state + 0x18, reticle + 0x2c, 0xff, &marker);
    }
    aim_state[0] = 0;
    *reinterpret_cast<float*>(aim_state + 0x04) =
        *reinterpret_cast<const float*>(reticle + 0x68);
    *reinterpret_cast<float*>(aim_state + 0x08) =
        CameraAim_SeedPitchAdjustment_00B17A7C(
            aim_state, reticle, static_cast<const uint8_t*>(framing_profile),
            mode_state, *reinterpret_cast<const float*>(camera_position + 0x34));
    const float kSentinel = 0x1.fffffep+126f;
    const float kPitchLimit = 1.3962634f; // retail ±79.97° literal
    float* pitch = reinterpret_cast<float*>(aim_state + 0x08);
    if (target_state[0x48] == 1) {
        aim_state[0] = 2;
        const float target_yaw = *reinterpret_cast<const float*>(target_state + 0x18);
        const float target_pitch = *reinterpret_cast<const float*>(target_state + 0x1c);
        if (target_yaw != kSentinel)
            *reinterpret_cast<float*>(aim_state + 0x04) = target_yaw;
        if (target_pitch != kSentinel)
            *pitch = target_pitch;
    } else {
        const bool has_target = reticle[0xe1] != 0;
        uint32_t target = has_target
            ? *reinterpret_cast<const uint32_t*>(aim_state + 0x1c) : 1;
        if (!has_target) {
            aim_state[0] = 1;
        } else if (target != 0) {
            aim_state[0] = 3;
            const uint32_t flags = *reinterpret_cast<const uint32_t*>(
                *reinterpret_cast<const uint32_t*>(aim_state + 0x1c));
            float direction[3];
            const float* source = (flags & 1) != 0
                ? reinterpret_cast<const float*>(target + 0x14)
                : reinterpret_cast<const float*>(reticle + 0x2c);
            direction[0] = *reinterpret_cast<const float*>(target + 0x2c) - source[0];
            direction[1] = *reinterpret_cast<const float*>(target + 0x30) - source[1];
            direction[2] = *reinterpret_cast<const float*>(target + 0x34) - source[2];
            if (Vec3_NormalizeAndGetLength(direction, 0, direction)) {
                if ((flags & 8) != 0) {
                    float yaw;
                    if (FUN_0090b458(&yaw, direction))
                        *reinterpret_cast<float*>(aim_state + 0x04) = yaw;
                }
                if ((flags & 4) != 0) {
                    float desired_pitch = Vec3_ComputePitch(direction);
                    if (reticle[0xc0] != 1 && (flags & 0x10) == 0) {
                        float horizontal[2] = {
                            *reinterpret_cast<const float*>(target + 0x14) -
                                *reinterpret_cast<const float*>(reticle + 0x2c),
                            *reinterpret_cast<const float*>(target + 0x1c) -
                                *reinterpret_cast<const float*>(reticle + 0x34)};
                        if (FUN_0090b3b8(horizontal, 0)) {
                            const float yaw = *reinterpret_cast<const float*>(camera_position + 0x34);
                            const float facing = ClampedAcos(
                                TrigKernel_0049A9DC(yaw) * horizontal[0] +
                                TrigKernel_00474934(yaw) * horizontal[1]);
                            const float blend = InverseLerpClamped(
                                facing, 0.7853982f, 2.355389f);
                            if (blend > 0.0f) {
                                const float current_pitch = *pitch;
                                desired_pitch = blend >= 1.0f
                                    ? current_pitch
                                    : desired_pitch + (current_pitch - desired_pitch) * blend;
                            }
                        }
                    }
                    *pitch = desired_pitch;
                }
            }
        }
    }
    if (*pitch > kPitchLimit) *pitch = kPitchLimit;
    if (*pitch < -kPitchLimit) *pitch = -kPitchLimit;
    float angles[3] = {*reinterpret_cast<float*>(aim_state + 0x04), *pitch, 0.0f};
    float basis[12] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                       0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    FUN_0090bba4(basis, 0, angles, 1, g_AimDirectionBasisSeed);
    *reinterpret_cast<float*>(aim_state + 0x0c) = basis[6];
    *reinterpret_cast<float*>(aim_state + 0x10) = basis[10];
    *reinterpret_cast<float*>(aim_state + 0x14) = basis[2];
}
extern "C" __attribute__((noinline)) int FUN_00A9B994(const void* reticle_pointer) {
    const uint8_t* reticle = static_cast<const uint8_t*>(reticle_pointer);
    const uint8_t* const state = *reinterpret_cast<const uint8_t* const*>(reticle + 0x104);
    if (state == 0 || state[0x1d] != 1)
        return 0;
    const float value = *reinterpret_cast<const float*>(reticle + 0xfc);
    return value >= 17.5f && value <= 28.8f ? 1 : 0;
}
extern "C" __attribute__((noinline)) float FUN_00b0d4a0(const void* profile_pointer,
                               float frame_value) {
    const float timer = *reinterpret_cast<const float*>(
        static_cast<const uint8_t*>(profile_pointer) + 0x2c);
    if (timer <= 0.3f)
        return frame_value;
    if (timer >= 1.0f)
        return 0.0f;
    return frame_value * (1.0f - timer);
}
extern "C" __attribute__((noinline)) void FUN_00b0d4e8(float* out, const uint8_t* profile,
                              const float* input, float frame_step) {
    const float timer = *reinterpret_cast<const float*>(profile + 0x2c);
    const float y_target = *reinterpret_cast<const float*>(profile + 0x30) * frame_step;
    if (timer <= 0.0f) {
        std::memcpy(out, input, 3 * sizeof(float));
        return;
    }
    if (timer >= 0.99999994f) {
        out[0] = 0.0f;
        out[1] = y_target;
        out[2] = 0.0f;
        return;
    }
    out[0] = input[0] * (1.0f - timer);
    out[1] = input[1] + (y_target - input[1]) * timer;
    out[2] = input[2] * (1.0f - timer);
}
__attribute__((noinline)) void Camera_UpdatePositionFromBoomDistance(uint8_t* state_pointer,
                                            float* camera_transform_pointer,
                                            const void* actor_state,
                                            const void* framing_profile,
                                            const void* occlusion_profile,
                                            const void* update_gate,
                                            const void* distance_profile,
                                            float frame_step) {
    CameraBoomStateView& state =
        *reinterpret_cast<CameraBoomStateView*>(state_pointer);
    CameraBoomTransformView& camera_transform =
        *reinterpret_cast<CameraBoomTransformView*>(camera_transform_pointer);
    const float occlusion_step = *reinterpret_cast<const float*>(
        static_cast<const uint8_t*>(occlusion_profile) + 0xac);
    const float occlusion_target = Camera_UpdateActorOcclusionDistanceScale(
        &state, actor_state, &camera_transform, update_gate, occlusion_step,
        frame_step);
    float spring_target = occlusion_target;
    const uint8_t* framing_bytes = static_cast<const uint8_t*>(framing_profile);
    if (framing_bytes[0x48] != 0) {
        const float override_target = *reinterpret_cast<const float*>(framing_bytes + 0x20);
        if (override_target != std::numeric_limits<float>::max())
            spring_target = override_target;
    }
    if (update_gate != 0) {
        if (state.timer > 0.0f) {
            state.timer -= frame_step;
        } else {
            FUN_00588dd8(&state,
                         *reinterpret_cast<const float*>(
                             static_cast<const uint8_t*>(occlusion_profile) + 0xdc) * 6.0f,
                         -1.0f);
            AngleSpring_StepBothStages(&state, spring_target, frame_step);
            AngleSpring_StepBothStages(
                reinterpret_cast<uint8_t*>(&state) + 0x2c, 1.0f,
                frame_step);
        }
    } else {
        AngleSpring_Reset(&state, spring_target);
        AngleSpring_Reset(reinterpret_cast<uint8_t*>(&state) + 0x2c, 1.0f);
        state.timer = 0.0f;
    }
    const float distance = FUN_00b0d4a0(
        distance_profile, state.base_distance);
    state.effective_distance = distance;
    const float scaled_distance = distance * state.occlusion_scale;
    const float effective = scaled_distance > -1.0f ? scaled_distance : -1.0f;
    camera_transform.distance = effective;
    camera_transform.position[0] = camera_transform.focus[0] -
                                   camera_transform.forward[0] * effective;
    camera_transform.position[1] = camera_transform.focus[1] -
                                   camera_transform.forward[1] * effective;
    camera_transform.position[2] = camera_transform.focus[2] -
                                   camera_transform.forward[2] * effective;
}
extern "C" __attribute__((noinline)) void Camera_ResolvePositionCollision(float* position,
                                                  const float* anchor) {
    float anchor_copy[3] = {anchor[0], anchor[1], anchor[2]};
    float direction_packet[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    const float dx = position[0] - anchor[0];
    const float dy = position[1] - anchor[1];
    const float dz = position[2] - anchor[2];
    const float squared = dx * dx + dy * dy + dz * dz;
    bool plane_collision = false;
    if (squared <= 0.0f) {
        std::memcpy(direction_packet, g_CameraTrackCollisionDirection,
                    3 * sizeof(float));
        direction_packet[3] = 1.0f;
    } else {
        const float length = std::sqrt(squared);
        const float inverse = 1.0f / length;
        direction_packet[0] = dx * inverse;
        direction_packet[1] = dy * inverse;
        direction_packet[2] = dz * inverse;
        direction_packet[3] = length + 1.0f;
    }
    void** registry_slot = reinterpret_cast<void**>(0x00D63590u);
    if (*registry_slot == 0)
        *registry_slot = Engine_ComponentRegistryGetter_004C58E0();
    const int hit = CollisionQuery_ClassifyFlagsAndDispatch(
        *registry_slot, anchor_copy, 0x200u, 0, 0);
    if (hit != 0) {
        const uint8_t* registry = static_cast<const uint8_t*>(*registry_slot);
        CollisionPlane_ProjectPoint_005FE4D0(
            position, reinterpret_cast<const float*>(registry + 0x6c),
            anchor_copy, 0.0f);
        plane_collision = true;
    }
    float magnitude = 0.0f;
    float pushout[3] = {g_FallbackDirection[0], g_FallbackDirection[1],
                        g_FallbackDirection[2]};
    if (Camera_QueryCollisionPushout(
            &magnitude, pushout, position, direction_packet, 0, 0,
            reinterpret_cast<const float*>(&g_CameraCollisionQueryMask)) != 0) {
        position[0] += pushout[0] * magnitude;
        position[1] += pushout[1] * magnitude;
        position[2] += pushout[2] * magnitude;
    } else if (plane_collision) {
        const float horizontal_x = position[0] - anchor[0];
        const float horizontal_z = position[2] - anchor[2];
        const float horizontal_squared = horizontal_x * horizontal_x +
                                         horizontal_z * horizontal_z;
        union {
            float value;
            uint32_t bits;
        } horizontal_word;
        horizontal_word.value = horizontal_squared;
        if (static_cast<int32_t>(horizontal_word.bits) <
            static_cast<int32_t>(0x3c23d709u)) {
            position[0] += direction_packet[0] * 0.1f;
            position[1] += direction_packet[1] * 0.1f;
            position[2] += direction_packet[2] * 0.1f;
        }
    }
}
extern "C" void* Engine_IntrusiveListRegistry_GetSentinel_0054F0FC();
extern "C" void* Engine_IntrusiveListRegistry_GetSentinel_0054F09C();
extern "C" void* ComponentType_GetStatusDescriptor_004DC14C();
static uint8_t* CameraRuntime_OcclusionComponent(uint8_t* owner) {
    uint8_t** link = reinterpret_cast<uint8_t**>(owner + 0x1f0);
    if (*link == 0) {
        void* key = ComponentType_GetStatusDescriptor_004DC14C();
        uint8_t* root = *reinterpret_cast<uint8_t**>(owner + 0x1ac);
        uint8_t* selected = owner + 0x1a8;
        while (root != 0 && root[0x10] != 0) {
            if (reinterpret_cast<uintptr_t>(
                    *reinterpret_cast<void**>(root + 0x14)) <
                reinterpret_cast<uintptr_t>(key)) {
                root = *reinterpret_cast<uint8_t**>(root + 0x0c);
            } else {
                selected = root;
                root = *reinterpret_cast<uint8_t**>(root + 0x08);
            }
        }
        if (selected != owner + 0x1a8 && selected != 0) {
            uint8_t* payload = *reinterpret_cast<uint8_t**>(selected);
            if (payload != 0)
                *reinterpret_cast<uint8_t**>(payload + 0x1c) = owner;
            *link = payload;
        }
    }
    return *link == 0 ? 0 : *reinterpret_cast<uint8_t**>(*link + 0x20);
}
static bool CameraRuntime_OcclusionPass(void* sentinel,
                                        const void* camera_geometry,
                                        float margin) {
    const uint8_t* geometry =
        static_cast<const uint8_t*>(camera_geometry);
    const float forward_x = *reinterpret_cast<const float*>(geometry + 0x0c);
    const float forward_z = *reinterpret_cast<const float*>(geometry + 0x14);
    const float focus_x = *reinterpret_cast<const float*>(geometry + 0x24);
    const float focus_z = *reinterpret_cast<const float*>(geometry + 0x2c);
    const float length_squared = forward_x * forward_x +
                                 forward_z * forward_z;
    if (length_squared <= 0.0f)
        return false;
    const float inverse_length = 1.0f / std::sqrt(length_squared);
    const float direction_x = forward_x * inverse_length;
    const float direction_z = forward_z * inverse_length;
    const float start_x = focus_x - direction_x * 41.0f;
    const float start_z = focus_z - direction_z * 41.0f;
    const float end_x = focus_x - direction_x *
                        DAT_007EEE00.segment_end_distance_004;
    const float end_z = focus_z - direction_z *
                        DAT_007EEE00.segment_end_distance_004;
    uint8_t* node = *reinterpret_cast<uint8_t**>(
        static_cast<uint8_t*>(sentinel) + 4);
    while (node != sentinel) {
        uint8_t* owner = *reinterpret_cast<uint8_t**>(node);
        if (owner != 0) {
            uint8_t* component = CameraRuntime_OcclusionComponent(owner);
            if (component != 0 &&
                ((*reinterpret_cast<const uint32_t*>(component + 0x38) & 1u) != 0) &&
                ((*reinterpret_cast<const uint32_t*>(component + 0x34) & 4u) != 0)) {
                const float min_x = *reinterpret_cast<const float*>(component + 0x54);
                const float min_z = *reinterpret_cast<const float*>(component + 0x5c);
                const float max_x = *reinterpret_cast<const float*>(component + 0x60);
                const float max_z = *reinterpret_cast<const float*>(component + 0x68);
                const float center_x = (min_x + max_x) * 0.5f;
                const float center_z = (min_z + max_z) * 0.5f;
                const float radius = std::max(max_x - min_x, max_z - min_z) *
                                     0.5f + margin;
                const float projection = (center_x - start_x) * direction_x +
                                          (center_z - start_z) * direction_z;
                if (projection < -radius ||
                    projection > radius + DAT_007EEE00.segment_extension_014)
                    continue;
                float nearest_x;
                float nearest_z;
                float limit = radius;
                if (projection < 0.0f) {
                    nearest_x = start_x;
                    nearest_z = start_z;
                } else if (projection > DAT_007EEE00.segment_length_01c) {
                    nearest_x = end_x;
                    nearest_z = end_z;
                } else {
                    nearest_x = start_x + direction_x * projection;
                    nearest_z = start_z + direction_z * projection;
                    limit += DAT_007EEE00.interior_margin_018;
                }
                const float ex = center_x - nearest_x;
                const float ez = center_z - nearest_z;
                if (ex * ex + ez * ez <= limit * limit)
                    return true;
            }
        }
        node = *reinterpret_cast<uint8_t**>(node + 4);
    }
    return false;
}
extern "C" __attribute__((noinline)) float Camera_UpdateActorOcclusionDistanceScale(
    void* state_pointer, const void* actor_state, const void* camera_geometry,
    const void* update_gate, float occlusion_step, float frame_step) {
    CameraBoomStateView* state = static_cast<CameraBoomStateView*>(state_pointer);
    const bool was_occupied = state->occlusion_occupied != 0;
    state->occlusion_occupied = 0;
    const uint8_t* actor = static_cast<const uint8_t*>(actor_state);
    const int16_t category =
        *reinterpret_cast<const int16_t*>(actor + 0x22);
    const bool disabled = update_gate == 0 || category == 0x321 || category == 0x322;
    float target = DAT_007EEE00.clear_target_000;
    uint32_t occlusion_step_bits = 0;
    std::memcpy(&occlusion_step_bits, &occlusion_step,
                sizeof(occlusion_step_bits));
    // Retail moves s0 to a GPR and compares against raw bits(41.0f).
    if (!disabled && static_cast<int32_t>(occlusion_step_bits) <
                      static_cast<int32_t>(0x42240000u)) {
        const float hysteresis_margin = was_occupied
            ? DAT_007EEE00.occlusion_margin_008 : 0.0f;
        if (CameraRuntime_OcclusionPass(
                Engine_IntrusiveListRegistry_GetSentinel_0054F0FC(),
                camera_geometry, hysteresis_margin))
            state->occlusion_occupied = 1;
        if (!state->occlusion_occupied &&
            CameraRuntime_OcclusionPass(
                Engine_IntrusiveListRegistry_GetSentinel_0054F09C(),
                camera_geometry, hysteresis_margin))
            state->occlusion_occupied = 1;
    }
    if (disabled) {
        TimedBlend_SetProgress(&state->occlusion_blend, 0.0f);
        return occlusion_step + (41.0f - occlusion_step) * state->occlusion_progress;
    }
    if (state->occlusion_occupied != 0) {
        if (!was_occupied && actor[0xcc] == 1)
            state->occlusion_occupied = 0;
        else
            target = DAT_007EEE00.occupied_target_010;
    }
    if (state->occlusion_blend != target)
        TimedBlend_SetProgress(&state->occlusion_blend, target);
    TimedBlend_Advance(&state->occlusion_blend, state->occlusion_occupied != 0,
                       frame_step);
    return occlusion_step + (41.0f - occlusion_step) * state->occlusion_progress;
}
__attribute__((noinline)) bool CameraMode1_SelectAngularCorrectionState(uint8_t* controller,
                                               int reset,
                                               const void*  ,
                                               const uint8_t* target_state,
                                               const uint8_t* actor_mode,
                                               float frame_step) {
    const bool actor_mode_one = actor_mode[0] == 1;
    if (reset != 0)
        controller[0x64] = 0;
    bool selected = false;
    if (target_state[0xcc] == 0) {
        if (actor_mode_one) {
            const uint8_t* const link = *reinterpret_cast<const uint8_t* const*>(actor_mode + 0x1c);
            const uint32_t* flags = link != 0
                ? *reinterpret_cast<const uint32_t* const*>(link) : 0;
            selected = flags != 0 && ((*flags & 8U) != 0);
        } else if (actor_mode[0] == 3) {
            const uint32_t kNoGeneration = 0x007fffffU;
            const uint32_t handle = *reinterpret_cast<const uint32_t*>(target_state + 0x18);
            const uint32_t generation = handle >> 9;
            if (generation != kNoGeneration) {
                uint8_t* entry = g_TargetHandleTable + (handle & 0x1ffU) * 8;
                if (*reinterpret_cast<const uint32_t*>(entry + 4) == generation) {
                    uint8_t* actor = *reinterpret_cast<uint8_t**>(entry);
                    if (actor != 0) {
                        void* status = ActorStatusLinkDescriptor_Resolve(actor);
                        selected = status != 0 &&
                                   *reinterpret_cast<const float*>(
                                       static_cast<const uint8_t*>(status) + 0x74) > 0.0f;
                    }
                }
            }
        }
    }
    float* blend = reinterpret_cast<float*>(controller + 0x68);
    const float kZero = 0.0f;
    const float kOne = 1.0f;
    const float kNormalDuration = 0.26f;
    if (reset != 0) {
        if (actor_mode_one) {
            TimedBlend_SetProgress(blend, selected ? kOne : kZero);
        } else if (*blend != kOne) {
            *blend = kOne;
            TimedBlend_SetProgress(blend, blend[1]);
        }
    } else if (actor_mode_one) {
        TimedBlend_SetProgress(blend, kZero);
    } else {
        TimedBlend_SetProgress(blend, selected ? kOne : kZero);
    }
    if (actor_mode_one || reset == 0) {
        if (*blend != kNormalDuration) {
            *blend = kNormalDuration;
            TimedBlend_SetProgress(blend, blend[1]);
        }
    }
    TimedBlend_Advance(blend, selected, frame_step);
    return selected;
}
__attribute__((noinline)) void CameraMode1_ApplyAngularCorrection(uint8_t* controller,
                                        float* camera_transform,
                                        int correction_suppressed,
                                        const uint8_t* reticle,
                                        const float* framing_state,
                                        const uint8_t* framing_profile,
                                        const uint8_t* actor_input_packet,
                                        float frame_step,
                                        float activation_progress) {
    const float strength = *reinterpret_cast<const float*>(framing_profile + 0xb8);
    float target[3] = {g_FallbackDirection[0], g_FallbackDirection[1], g_FallbackDirection[2]};
    if (correction_suppressed == 0 && strength > 0.0f && reticle[0xcc] == 0) {
        float displacement[3] = {
            framing_state[0] - framing_state[3], 0.0f,
            framing_state[2] - framing_state[5]};
        float length = 0.0f;
        if (Vec3_NormalizeAndGetLength(displacement, &length, displacement) &&
            length > frame_step * 0.5f) {
            const float yaw = camera_transform[0x34 / 4];
            const float yaw_cos = TrigKernel_0049A9DC(yaw);
            const float yaw_sin = TrigKernel_00474934(yaw);
            const float view_angle = ClampedAcos(
                yaw_cos * displacement[0] + yaw_sin * displacement[2]);
            float weight = 0.0f;
            if (reticle[0xe1] == 0xff) {
                weight = 1.0f;
            } else {
                const void* special_identity = reinterpret_cast<const void*>(
                    static_cast<uintptr_t>(0x00c9b960));
                const bool special_target =
                    *reinterpret_cast<const void* const*>(reticle + 0xa4) == special_identity ||
                    Camera_IsTrackedTarget_00A2CE30(const_cast<uint8_t*>(reticle));
                if (special_target ||
                    std::fabs(*reinterpret_cast<const float*>(reticle + 0xf0)) > 0.00034f) {
                    weight = 1.0f;
                }
            }
            if (reticle[0x24] == 1) {
                if (actor_input_packet != 0 &&
                    (*reinterpret_cast<const float*>(actor_input_packet + 0x38) != 0.0f ||
                     *reinterpret_cast<const float*>(actor_input_packet + 0x3c) != 0.0f)) {
                    weight = 1.0f - InverseLerpClamped(view_angle, 0.0f, 1.5707963f);
                } else {
                    weight = 0.0f;
                }
            } else {
                float input_weight = 1.0f;
                const int16_t category = *reinterpret_cast<const int16_t*>(reticle + 0x22);
                if (category == 0x322 || category == 0x321) {
                    const float x = *reinterpret_cast<const float*>(actor_input_packet + 0x38);
                    const float y = *reinterpret_cast<const float*>(actor_input_packet + 0x3c);
                    input_weight = InverseLerpClamped(std::sqrt(x * x + y * y), 0.5f, 1.0f);
                }
                weight = input_weight *
                    (1.0f - InverseLerpClamped(view_angle, 1.7453293f, 2.6179938f));
            }
            if (weight > 0.0f) {
                target[0] = displacement[0] * strength * weight;
                target[1] = displacement[1] * strength * weight;
                target[2] = displacement[2] * strength * weight;
            }
        }
    }
    DoubleVec3Spring_Step_0090AEBC(controller + 0x74, target);
    if (!DoubleVec3Spring_IsSettled_00B461B0(controller + 0x74, g_FallbackDirection)) {
        float direction[3] = {
            framing_state[3] + *reinterpret_cast<const float*>(controller + 0xa0) *
                activation_progress - camera_transform[0x0c / 4],
            0.0f,
            framing_state[5] + *reinterpret_cast<const float*>(controller + 0xa8) *
                activation_progress - camera_transform[0x14 / 4]};
        if (!Vec3_NormalizeAndGetLength(direction, 0, direction))
            return;
        const float old_yaw = camera_transform[0x34 / 4];
        Camera_RebuildTransformFromYawPitch(camera_transform, Vec3_ComputeYaw(direction),
                                            camera_transform[0x38 / 4]);
        *reinterpret_cast<float*>(controller + 0xac) =
            WrapAngleRadians(camera_transform[0x34 / 4] - old_yaw);
    }
}
__attribute__((noinline)) void Camera_UpdateMode1AngularCorrection(
    uint8_t* controller, float* camera_transform,
    const uint8_t* reticle, float* framing_state,
    const void* actor_mode_descriptor, const uint8_t* framing_profile,
    const uint8_t* actor_input_packet, int active_mode, float frame_step) {
    bool at_start = false;
    bool active = false;
    const float activation = UpdateKeyedTransition_00745F58(
        controller, &at_start, &active, active_mode, frame_step);
    if (at_start) {
        AngleSpring_Reset(controller + 0x14, camera_transform[0x34 / 4]);
        AngleSpring_Reset(controller + 0x3c, camera_transform[0x38 / 4]);
        const float zero[3] = {0.0f, 0.0f, 0.0f};
        DoubleVec3Spring_Reset_0090AE84(controller + 0x74, zero);
    }
    if (!active)
        return;
    int descriptor_state = 0;
    uint8_t descriptor_values[0x1c] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    FUN_00b17a18(actor_mode_descriptor, &descriptor_state, descriptor_values);
    const bool suppressed = CameraMode1_SelectAngularCorrectionState(
        controller, at_start, camera_transform, reticle,
        static_cast<const uint8_t*>(actor_mode_descriptor), frame_step);
    CameraMode1_ApplyAngularCorrection(controller, camera_transform,
                                        suppressed, reticle, framing_state,
                                        framing_profile, actor_input_packet,
                                        frame_step, activation);
    const float timer = *reinterpret_cast<const float*>(controller + 0x6c);
    if (timer > 0.0f)
        AngleSpring_IntegrateSample(controller + 0x14, timer);
    else
        AngleSpring_Reset(controller + 0x14, camera_transform[0x34 / 4]);
    AngleSpring_IntegrateSample(controller + 0x3c, camera_transform[0x38 / 4]);
    bool yaw_moved = false;
    if (timer > 0.0f) {
        float yaw_target = activation;
        if (suppressed != 0)
            yaw_target = *reinterpret_cast<const float*>(framing_profile + 0x04);
        if (!AngleSpring_IsSettled_Thunk(controller + 0x14, yaw_target, 1.0f)) {
            const float rate = descriptor_state == 1
                ? 5.0f : *reinterpret_cast<const float*>(framing_profile + 0xb8);
            const float second_rate = descriptor_state == 1
                ? 2.6179938f : *reinterpret_cast<const float*>(framing_profile + 0xbc);
            FUN_00588dd8(controller + 0x14, rate, second_rate);
            AngleSpring_StepBothStages(controller + 0x14, yaw_target);
            yaw_moved = true;
        }
    }
    const float pitch_target = *reinterpret_cast<const float*>(framing_profile + 0x08);
    if (AngleSpring_IsSettled_Thunk(
            controller + 0x3c, pitch_target,
            *reinterpret_cast<const float*>(
                static_cast<const uint8_t*>(actor_mode_descriptor) + 0x08)) && yaw_moved) {
        Camera_RebuildTransformFromYawPitch(
            camera_transform,
            *reinterpret_cast<const float*>(controller + 0x38),
            *reinterpret_cast<const float*>(controller + 0x60));
    }
    controller[0x64] = suppressed ? 1 : 0;
}
__attribute__((noinline)) void Camera_SetActorTransformFromBasis(uint8_t* camera,
                                       const float* basis,
                                       const float* position) {
    float a = basis[0];
    float b = basis[4];
    float c = basis[8];
    float d = basis[1];
    float e = basis[5];
    float f = basis[6];
    float g = a;
    float h = c;
    bool swap_c = false;
    bool swap_a = false;
    if (a + b + c < 0.0f) {
        swap_c = c <= a || c <= b;
        if (swap_c) {
            h = -c;
            d = -d;
        }
        swap_a = a < c || a < b;
        if (swap_a) {
            g = -a;
            e = -e;
        }
        if (!(a < b && !(b < c))) {
            b = -b;
            f = -f;
        }
    }
    const float sum = g + b + h + 1.0f;
    const float scale = (1.0f / std::sqrt(sum)) * 0.5f;
    e = (basis[7] - e) * scale;
    b = (basis[2] - f) * scale;
    f = (basis[3] - d) * scale;
    a = sum * scale;
    g = a;
    h = b;
    if (swap_c) {
        g = e;
        h = f;
        f = b;
        e = a;
    }
    d = g;
    a = h;
    if (swap_a) {
        d = f;
        a = e;
        f = g;
        e = h;
    }
    const uint32_t position_x =
        *reinterpret_cast<const uint32_t*>(position + 0);
    const uint32_t position_y =
        *reinterpret_cast<const uint32_t*>(position + 1);
    const uint32_t position_z =
        *reinterpret_cast<const uint32_t*>(position + 2);
    *reinterpret_cast<float*>(camera + 0x40) = 1.0f;
    *reinterpret_cast<float*>(camera + 0x44) = e;
    *reinterpret_cast<float*>(camera + 0x50) = d;
    *reinterpret_cast<float*>(camera + 0x48) = a;
    *reinterpret_cast<float*>(camera + 0x4c) = f;
    *reinterpret_cast<uint32_t*>(camera + 0x54) = position_x;
    *reinterpret_cast<uint32_t*>(camera + 0x58) = position_y;
    *reinterpret_cast<uint32_t*>(camera + 0x5c) = position_z;
    *reinterpret_cast<float*>(camera + 0x64) = e;
    *reinterpret_cast<float*>(camera + 0x68) = a;
    *reinterpret_cast<float*>(camera + 0x6c) = f;
    *reinterpret_cast<float*>(camera + 0x70) = d;
}
__attribute__((noinline)) void Camera_ActorUpdate_00704484(uint8_t* owner,
                                 const float* transform,
                                 const void* update_context,
                                 float frame_step) {
    if (owner[0x94] != 1)
        return;
    const float translation[3] = {transform[3], transform[7], transform[11]};
    const float dx = *reinterpret_cast<const float*>(owner + 0xdc) - translation[0];
    const float dy = *reinterpret_cast<const float*>(owner + 0xe0) - translation[1];
    const float dz = *reinterpret_cast<const float*>(owner + 0xe4) - translation[2];
    const float projection = dx * -transform[2] + dy * -transform[6] +
                             dz * -transform[10];
    FUN_00704008(owner, translation, update_context, projection, frame_step);
    Camera_ActorUpdateSpringState_0070457C(owner, update_context, projection,
                                           frame_step);
}
extern "C" __attribute__((noinline)) void Camera_ActorUpdateSpringState_0070457C(
    uint8_t* owner, const void* update_context, float projection,
    float frame_step) {
    if (update_context == 0)
        return;
    uint8_t** context_slot = reinterpret_cast<uint8_t**>(0x00D637ECu);
    if (*context_slot == 0)
        *context_slot = static_cast<uint8_t*>(
            Engine_SharedResourceSingleton_00422D20());
    uint8_t* shared = *context_slot;
    uint8_t* context = *reinterpret_cast<uint8_t**>(
        *reinterpret_cast<uint8_t**>(shared + 0x44) + 4) + 0x5c;
    const bool active = owner[0x350] != 0;
    float target = 6.0f;
    if (active) {
        const int16_t category =
            *reinterpret_cast<const int16_t*>(owner + 0xba);
        if (owner[0x179] != static_cast<uint8_t>(-1) ||
            category == 0x320 || category == 0x322) {
            target = 6.0f;
        } else {
            target = *reinterpret_cast<const float*>(
                *reinterpret_cast<const uint8_t* const*>(owner + 0x3ac) +
                0x44);
        }
        const float projected = projection - target;
        target = projected > 2.0f ? projected : 2.0f;
        const int32_t mode = *reinterpret_cast<const int32_t*>(
            owner + 0xfcc);
        const bool special = mode >= 0 && owner[0xfc1] == 1;
        const bool advance_sample = mode >= 0 && !special;
        const float mode_target = *reinterpret_cast<const float*>(owner + 0xfc4);
        if (mode >= 0 && mode_target > 20.0f) {
            target = mode_target;
            AngleSpring_Reset(owner + 0x10c0, target);
        } else if (category != 0x322) {
            target = *reinterpret_cast<const float*>(owner + 0x10d0);
        } else if ((owner[0x179] != static_cast<uint8_t>(-1) ||
                    advance_sample) && target > 45.0f) {
            target = 45.0f;
        }
        AngleSpring_StepBothStages(owner + 0x10c0, target, frame_step);
        if (advance_sample) {
            const float delta = target -
                *reinterpret_cast<const float*>(owner + 0x10e4);
            float absolute_delta = std::fabs(delta);
            uint32_t absolute_delta_bits = 0;
            std::memcpy(&absolute_delta_bits, &absolute_delta,
                        sizeof(absolute_delta_bits));
            if (absolute_delta_bits > 0x40a00000u) {
                const float sample = delta > 45.0f
                    ? target - 5.0f : target + 5.0f;
                AngleSpring_IntegrateSample(owner + 0x10c0, sample);
            }
        }
        *reinterpret_cast<float*>(context + 0x84) =
            *reinterpret_cast<const float*>(owner + 0x10e4);
    } else {
        AngleSpring_Reset(owner + 0x10c0,
                          *reinterpret_cast<const float*>(context + 0x84));
    }
    uint8_t** target_slot = reinterpret_cast<uint8_t**>(0x00D635E8u);
    if (*target_slot == 0)
        *target_slot = static_cast<uint8_t*>(Engine_ThresholdAuxAllocator_00475D70());
    uint8_t* selected = static_cast<uint8_t*>(
        FUN_005c2978(*target_slot + 0x1ec, 1));
    if (selected != 0)
        *reinterpret_cast<uint32_t*>(context + 0x80) =
            *reinterpret_cast<const uint32_t*>(selected + 0xa8);
}
extern "C" __attribute__((noinline)) void CameraMode3_UpdateActivationGate_0082200C(
    uint8_t* controller, const uint8_t* camera_state,
    const uint8_t* flags, int selected_mode, const void*  ,
    float frame_step) {
    const bool restricted =
        (*reinterpret_cast<const uint32_t*>(flags + 4) & 0x40000u) != 0;
    const bool restricted_by_state =
        restricted && camera_state[0xe1] != 1;
    typedef int(*IdentityFn)(const uint8_t*);
    IdentityFn const* vtable = *reinterpret_cast<IdentityFn const* const*>(controller);
    const bool same_mode = vtable[2](controller) == selected_mode;
    float& transition = *reinterpret_cast<float*>(controller + 0x14);
    if (same_mode) {
        if (restricted_by_state)
            transition += frame_step;
        else
            transition = 0.0f;
        return;
    }
    if (restricted_by_state) {
        controller[0x11] = 0;
        transition += frame_step;
        return;
    }
    controller[0x11] = transition > 0.0f && transition <= 0.25f;
    transition = 0.0f;
}
extern "C" __attribute__((noinline)) bool Camera_TargetRelativeTransitionReady_0080A2EC(
    const uint8_t* state, const uint8_t* context,
    const void* target_slot) {
    if (state[0x48] != 1 || context[0xCC] != 0)
        return false;
    const uint8_t* const target = *reinterpret_cast<const uint8_t* const*>(
        target_slot);
    float distance = *reinterpret_cast<const float*>(target + 0x30);
    if (state[0x44] == 1)
        distance *= 0.5f;
    return distance <= *reinterpret_cast<const float*>(context + 0xD0);
}
extern "C" __attribute__((noinline)) bool Camera_OverrideControllerSelect_00809BEC(
    uint8_t* controller, int enabled, const void*  ,
    int selected_mode) {
    if (enabled != 0) {
        const int override_identity =
            *reinterpret_cast<const int*>(controller + 0x88);
        if (override_identity != -1) {
            controller[0x11] = 0;
            return true;
        }
        typedef int(*IdentityFn)(const uint8_t*);
        IdentityFn const* vtable = *reinterpret_cast<IdentityFn const* const*>(
            controller);
        if (vtable[2](controller) == selected_mode &&
            controller[0x11] != 2) {
            controller[0x11] = 1;
            return true;
        }
    }
    controller[0x11] = 2;
    return false;
}
extern "C" __attribute__((noinline)) bool Camera_TrackedOverrideGate_008175CC(
    uint8_t* controller, const uint8_t* context,
    const void*  , const void*  , int selected_mode) {
    bool enabled = false;
    if (context[0xB8] == 1 &&
        *reinterpret_cast<const float*>(context + 0xBC) >= 0.2f &&
        *reinterpret_cast<const int32_t*>(context + 0xCC) <= 0 &&
        *reinterpret_cast<const float*>(context + 0xD0) >= 0.8f) {
        enabled = true;
    }
    return Camera_OverrideControllerSelect_00809BEC(
        controller, enabled ? 1 : 0, 0, selected_mode);
}
extern "C" __attribute__((noinline)) bool Camera_Mode3ControllerIsActive_00821FC8(
    const uint8_t* controller) {
    if (controller[0x11] == 1)
        return true;
    return controller[0x11] == 2 &&
        !DoubleVec3Spring_IsSettledWithThreshold_00B46260(
            controller + 0x18,
            reinterpret_cast<const float*>(controller + 0x50),
            0.0003046174243f);
}
extern "C" __attribute__((noinline)) int Camera_SpecialTargetMode_00B1A8B0(
    const void*  , const uint8_t* reticle) {
    const uint8_t* const link = *reinterpret_cast<const uint8_t* const*>(
        reticle + 0x104);
    if (link == 0 || link[0x1C] == 0)
        return 0;
    return static_cast<int8_t>(reticle[0xE0]);
}
extern "C" __attribute__((noinline)) bool Camera_Mode5OverrideGate_007F0524(
    uint8_t* controller, const uint8_t* context,
    const void* extra, const void*  , int selected_mode) {
    bool enabled = false;
    switch (controller[0xEC]) {
    case 0:
        enabled = context[0xCC] == 0 &&
            *reinterpret_cast<const float*>(context + 0xD0) >= 0.0f;
        break;
    case 1:
        enabled = Engine_ReticleContextResource_00A9B988(context)[0x1D0] != 0;
        break;
    default:
        enabled = Engine_ReticleContextResource_00A9B988(context)[0x200] == 1;
        break;
    }
    return Camera_OverrideControllerSelect_00809BEC(
        controller, enabled ? 1 : 0, extra, selected_mode);
}
__attribute__((noinline)) void Camera_SelectActiveMode(uint8_t* camera, int force_default,
                             int selected_mode, const void* param4,
                             float frame_step) {
    CameraMode3_UpdateActivationGate_0082200C(
        camera + 0x804, camera + 0x98, camera + 0x1028,
        selected_mode, param4, frame_step);
    camera[0x351] = 0;
    if (force_default != 0) {
        camera[0x350] = 0;
        return;
    }
    void* selected_mode_bits = reinterpret_cast<void*>(
        static_cast<uintptr_t>(selected_mode));
    if (CameraYawImpulse_IsActive(camera + 0xb90, selected_mode_bits)) {
        camera[0x350] = 7;
        return;
    }
    if (Camera_TargetRelativeTransitionReady_0080A2EC(
            camera + 0xbc0, camera + 0x98, camera + 0x3ac)) {
        camera[0x350] = 8;
        return;
    }
    if (Camera_OverrideControllerSelect_00809BEC(
            camera + 0x860, 1, camera + 0x278, selected_mode)) {
        camera[0x350] = 4;
        camera[0x351] = camera[0x950] != 0;
        return;
    }
    if (Camera_Mode5OverrideGate_007F0524(
            camera + 0x970, camera + 0x98, camera + 0x278,
            camera + 0x3ac, selected_mode)) {
        camera[0x350] = 5;
        return;
    }
    if (Camera_Mode3ControllerIsActive_00821FC8(camera + 0x804)) {
        camera[0x350] = 3;
        return;
    }
    if (Camera_TrackedOverrideGate_008175CC(
            camera + 0xa80, camera + 0x98, camera + 0x278,
            camera + 0x3ac, selected_mode)) {
        camera[0x350] = 6;
        return;
    }
    if (Camera_SpecialTargetMode_00B1A8B0(
            camera + 0xc60, camera + 0x98)) {
        camera[0x350] = 9;
        return;
    }
    camera[0x350] = camera[0x178] != 0 ? 1 : 2;
}
__attribute__((noinline)) void Camera_SelectFovEndpoints(float* out_endpoints,
                               const void* camera_context,
                               const uint8_t* profile,
                               const uint8_t* const* active_profile_slot) {
    float first = 0.7853982f;
    const float fallback = 1.0431621f;
    if (g_FovDefaultSingleton == 0)
        g_FovDefaultSingleton = static_cast<uint8_t*>(
            Engine_ThresholdAuxAllocator_00475D70(
                0u,
                static_cast<uint32_t>(
                    reinterpret_cast<uintptr_t>(camera_context)),
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(profile))));
    uint8_t* descriptor = static_cast<uint8_t*>(
        FUN_005c2978(g_FovDefaultSingleton + 0x1ec, 1));
    if (descriptor != 0)
        first = *reinterpret_cast<const float*>(descriptor + 0x40);
    float progress = *reinterpret_cast<const float*>(profile + 0x14);
    if (progress > 0.0f && progress < 1.0f)
        progress = 0.5f - TrigKernel_00474934(progress * 3.1415927f) * 0.5f;
    if (progress <= 0.0f)
        out_endpoints[0] = first;
    else if (progress < 1.0f)
        out_endpoints[0] = first + (fallback - first) * progress;
    else
        out_endpoints[0] = fallback;
    const uint8_t* active_profile = *active_profile_slot;
    out_endpoints[1] =
        *reinterpret_cast<const float*>(active_profile + 0x20);
    if (g_FovOverrideSingleton == 0)
        g_FovOverrideSingleton = static_cast<uint8_t*>(
            Engine_LazySingletonGetter_0054EFA8());
    FUN_004aef14(g_FovOverrideSingleton,
                 *reinterpret_cast<const uint32_t*>(static_cast<const uint8_t*>(camera_context) + 0x28));
    if (void* override_state = FUN_00a2bbd0())
        out_endpoints[1] = *reinterpret_cast<const float*>(
            static_cast<const uint8_t*>(override_state) + 0x4e0);
}
__attribute__((noinline)) void CameraTrack_ResolveEndpoint(void*  , float* out_position,
                                 const uint8_t* endpoint,
                                 const float* current_transform,
                                 const float* fallback_position, int allow_current) {
    const CameraTrackEndpointView& descriptor =
        *reinterpret_cast<const CameraTrackEndpointView*>(endpoint);
    switch (descriptor.type) {
    case 0:
        std::memcpy(out_position, descriptor.literal_position,
                    sizeof(descriptor.literal_position));
        return;
    case 1: {
        const uint32_t handle = descriptor.actor_handle;
        if ((handle >> 9) == 0x7fffffU) return;
        uint8_t* entry = g_TargetHandleTable + (handle & 0x1ffU) * 8;
        if (*reinterpret_cast<const uint32_t*>(entry + 4) != (handle >> 9)) return;
        uint8_t* actor = *reinterpret_cast<uint8_t**>(entry);
        if (actor == 0) return;
        uint8_t* node = *reinterpret_cast<uint8_t**>(actor + 0x1e4);
        if (node == 0) {
            const uintptr_t key = reinterpret_cast<uintptr_t>(
                Engine_LazySingletonGetter_00498828());
            uint8_t* sentinel = actor + 0x1a8;
            uint8_t* walk = *reinterpret_cast<uint8_t**>(actor + 0x1ac);
            uint8_t* parent = sentinel;
            while (walk != 0 && walk[0x10] != 0) {
                parent = walk;
                if (*reinterpret_cast<const uint32_t*>(walk + 0x14) < key) {
                    walk = *reinterpret_cast<uint8_t**>(walk + 0x0c);
                    parent = sentinel;
                } else {
                    walk = *reinterpret_cast<uint8_t**>(walk + 0x08);
                }
            }
            if (parent == sentinel ||
                key < *reinterpret_cast<const uint32_t*>(parent + 0x14))
                parent = sentinel;
            uint8_t* selected = parent == 0
                ? 0 : *reinterpret_cast<uint8_t**>(parent);
            uint8_t* cached = *reinterpret_cast<uint8_t**>(sentinel);
            if (selected != cached && selected != 0) {
                *reinterpret_cast<uint8_t**>(selected + 0x1c) = actor;
                *reinterpret_cast<uint8_t**>(actor + 0x1e4) = selected;
                node = selected;
            }
        }
        if (node == 0) return;
        uint8_t* transform = *reinterpret_cast<uint8_t**>(node + 0x24);
        if (transform == 0) return;
        if (descriptor.node_name[0] == '\0') {
            std::memcpy(out_position, transform + 0x54, 0x0c);
        } else {
            struct NodeSelector {
                uint32_t key;
                const char* name;
            } selector = {descriptor.node_key, descriptor.node_name};
            const int named = FUN_0051CC1C(transform,
                                           reinterpret_cast<uint32_t*>(&selector));
            float effective[12] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
            FUN_004C39D8(effective, transform,
                         reinterpret_cast<const void*>(
                             static_cast<uintptr_t>(named)));
            out_position[0] = effective[3];
            out_position[1] = effective[7];
            out_position[2] = effective[11];
        }
        return;
    }
    case 2:
        if (allow_current != 0)
            std::memcpy(out_position,
                        reinterpret_cast<const uint8_t*>(current_transform) + 0x10,
                        3 * sizeof(float));
        return;
    case 3:
        std::memcpy(out_position, fallback_position, 3 * sizeof(float));
        return;
    case 4:
        if (allow_current != 0) std::memcpy(out_position, fallback_position, 0x0c);
        return;
    default:
        return;
    }
}
__attribute__((noinline)) void CameraTrack_UpdateAndApply(uint8_t* track, const uint8_t* actor_camera,
                                const float* current_transform, const float* fallback_position,
                                float frame_step) {
    CameraTrackStateView* state = reinterpret_cast<CameraTrackStateView*>(track);
    const int32_t count = *reinterpret_cast<const int32_t*>(track);
    int32_t index = state->keyframe_index;
    if (index < 0) return;
    const float old_time = state->segment_time;
    const bool allow_current = index == 0 && old_time == 0.0f;
    float time = old_time + frame_step;
    state->segment_time = time;
    if (index < count) {
        CameraTrackKeyframeView* key = &state->keyframes[index];
        bool advance = false;
        if (reinterpret_cast<const uint8_t*>(key)[0x88] != 0) {
            if (state->transition_active == 1) {
                time = frame_step;
                state->segment_time = time;
                advance = true;
            }
        } else {
            const float segment_end = key->duration + key->segment_delay;
            if (time >= segment_end) {
                time -= segment_end;
                state->segment_time = time;
                advance = true;
            }
        }
        if (advance) {
            ++index;
            state->keyframe_index = index;
            if (index < count)
                std::memcpy(state->source_transform, state->destination_transform,
                            sizeof(state->source_transform));
        }
    }
    state->transition_active = 0;
    if (index == 0) {
        if (allow_current) {
            std::memcpy(state->source_transform, current_transform + 1,
                        sizeof(state->source_transform));
        } else {
            std::memcpy(state->source_transform + 4, current_transform + 5,
                        3 * sizeof(float));
        }
    }
    float start[3] = {0.0f, 0.0f, 0.0f};
    float end[3] = {0.0f, 0.0f, 0.0f};
    float position[3] = {0.0f, 0.0f, 0.0f};
    float progress = 1.0f;
    if (index < count) {
        CameraTrackKeyframeView* key = &state->keyframes[index];
        CameraTrack_ResolveEndpoint(
            track, state->start_position,
            reinterpret_cast<const uint8_t*>(key) + 0x04,
            current_transform, fallback_position, allow_current);
        CameraTrack_ResolveEndpoint(
            track, state->end_position,
            reinterpret_cast<const uint8_t*>(key) + 0x44,
            current_transform, fallback_position, allow_current);
        std::memcpy(start, state->start_position, sizeof(start));
        std::memcpy(end, state->end_position, sizeof(end));
        const float duration = key->duration;
        if (duration > 0.0f) {
            progress = time / duration;
            if (progress > 1.0f) progress = 1.0f;
        }
    } else {
        std::memcpy(state->destination_transform, current_transform + 1,
                    sizeof(state->destination_transform));
        std::memcpy(start, state->source_transform + 4, sizeof(start));
        std::memcpy(end, state->destination_transform + 4, sizeof(end));
        if (time >= state->total_duration) {
            CameraTrack_Reset(track);
            return;
        }
        progress = time / state->total_duration;
    }
    float eased_progress;
    if (state->field_1ae == 0) {
        eased_progress = Engine_EaseHalfCosine_00259B5C(progress);
    } else {
        eased_progress = std::sqrt(2.0f * progress - progress * progress);
    }
    if (index == 0)
        state->segment_value = eased_progress;
    else if (index > 0)
        state->segment_value = 1.0f - eased_progress;
    if (index < count) {
        float direction[3] = {end[0] - start[0], end[1] - start[1],
                              end[2] - start[2]};
        if (Vec3_NormalizeAndGetLength(direction, 0, direction) &&
            std::fabs(std::fabs(direction[1]) - 1.0f) > 0.001f) {
            float corrected_position[3] = {start[0], start[1], start[2]};
            if (state->collision_enabled == 1)
                Camera_ApplyCollisionPushout(corrected_position, direction);
            const float negated_direction[3] = {-direction[0], -direction[1],
                                                 -direction[2]};
            float basis[12] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                               0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
            FUN_003ACDE4(
                basis, negated_direction,
                reinterpret_cast<const float*>(0x00DC24C0u));
            float a = basis[0], b = basis[1], c = basis[2];
            float d = basis[3], e = basis[4], f = basis[5];
            float g = basis[6], h = basis[7], i = basis[8];
            const bool i_gt_a = i > a;
            const bool i_gt_e = i > e;
            const bool e_gt_a = e > a;
            bool swap_q0_q3 = false;
            bool swap_q1_q2 = false;
            if (!(i_gt_a && i_gt_e)) {
                i = -i;
                g = -g;
                swap_q0_q3 = true;
            }
            if (i_gt_a || e_gt_a) {
                a = -a;
                b = -b;
                swap_q1_q2 = true;
            }
            if (!(e_gt_a && !i_gt_e)) {
                e = -e;
                f = -f;
            }
            const float scale = 0.5f / std::sqrt(a + e + i + 1.0f);
            float repaired[4] = {(h - f) * scale, (c - g) * scale,
                                 (d - b) * scale,
                                 (a + e + i + 1.0f) * scale};
            if (swap_q0_q3) {
                std::swap(repaired[0], repaired[3]);
                std::swap(repaired[1], repaired[2]);
            }
            if (swap_q1_q2) {
                std::swap(repaired[0], repaired[1]);
                std::swap(repaired[2], repaired[3]);
            }
            std::memcpy(state->destination_transform, repaired,
                        sizeof(repaired));
            std::memcpy(state->destination_transform + 4, corrected_position,
                        sizeof(corrected_position));
        }
    }
    CameraTrack_InterpolatePosition(track, position, start, end,
                                    eased_progress);
    float q[4];
    const float* from = state->source_transform;
    const float* to = state->destination_transform;
    float destination[4] = {to[0], to[1], to[2], to[3]};
    float dot = from[0] * destination[0] + from[1] * destination[1] +
                from[2] * destination[2] + from[3] * destination[3];
    if (dot < 0.0f) {
        dot = -dot;
        for (int i = 0; i != 4; ++i) destination[i] = -destination[i];
    }
    const float kSlerpLinearThreshold = 0.99999f; // DAT_007C9DBC
    if (dot > kSlerpLinearThreshold) {
        for (int i = 0; i != 4; ++i)
            q[i] = from[i] + (destination[i] - from[i]) * eased_progress;
    } else {
        const float angle = ClampedAcos(dot);
        const float sine = TrigKernel_0049A9DC(angle);
        const float from_weight =
            TrigKernel_0049A9DC((1.0f - eased_progress) * angle) / sine;
        const float to_weight =
            TrigKernel_0049A9DC(eased_progress * angle) / sine;
        for (int i = 0; i != 4; ++i)
            q[i] = from[i] * from_weight + destination[i] * to_weight;
    }
    const float length = std::sqrt(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3]);
    if (length > 0.0f)
        for (int i = 0; i != 4; ++i) q[i] /= length;
    const float x = q[0], y = q[1], z = q[2], w = q[3];
    const float xx = 2.0f * x * x, yy = 2.0f * y * y, zz = 2.0f * z * z;
    const float xy = 2.0f * x * y, xz = 2.0f * x * z, yz = 2.0f * y * z;
    const float xw = 2.0f * x * w, yw = 2.0f * y * w, zw = 2.0f * z * w;
    const float matrix[12] = {
        1.0f - yy - zz, xy - zw,       xz + yw,       position[0],
        xy + zw,       1.0f - xx - zz, yz - xw,       position[1],
        xz - yw,       yz + xw,       1.0f - xx - yy, position[2],
    };
    ActorCamera_SubmitMatrix(actor_camera, matrix);
}
// Semantic reconstruction, JP Rev 1: 0x007EF63C.
__attribute__((noinline)) void Camera_UpdateRelativeOffset(uint8_t* camera_state,
                                  const float* world_position,
                                  const float* base_position, int snap) {
    float target[3] = {
        world_position[0] - (base_position[0] + *reinterpret_cast<const float*>(camera_state + 0x58)),
        world_position[1] - (base_position[1] + *reinterpret_cast<const float*>(camera_state + 0x5c)),
        world_position[2] - (base_position[2] + *reinterpret_cast<const float*>(camera_state + 0x60)),
    };
    uint8_t* spring = camera_state + 0x64;
    const float kEpsilon = 0.00034f; // DAT_007EF704
    if (snap != 0) {
        DoubleVec3Spring_Reset_0090AE84(spring, target);
    } else if (std::fabs(target[0] - *reinterpret_cast<const float*>(camera_state + 0x90)) > kEpsilon ||
               std::fabs(target[1] - *reinterpret_cast<const float*>(camera_state + 0x94)) > kEpsilon ||
               std::fabs(target[2] - *reinterpret_cast<const float*>(camera_state + 0x98)) > kEpsilon) {
        DoubleVec3Spring_Retarget_0090AEEC(spring, target);
    }
}
__attribute__((noinline)) void Camera_UpdateTargetRelativeFocusOffset(uint8_t* state,
                                            uint8_t* camera_state,
                                            const float* aim_position,
                                            float frame_step) {
    const float kZero = 0.0f;
    uint8_t mode = state[0x48];
    const bool target_mode = mode == 1;
    if (target_mode)
        mode = state[0x2c];
    if (!(target_mode && mode == 1)) {
        TimedBlend_SetProgress(reinterpret_cast<float*>(state + 0x88), kZero);
        return;
    }
    if (CameraRuntime_ReadFloat(state, 0x8c) <= kZero) {
        *reinterpret_cast<float*>(state + 0x94) = aim_position[0] + CameraRuntime_ReadFloat(camera_state, 0x58) + CameraRuntime_ReadFloat(camera_state, 0x90);
        *reinterpret_cast<float*>(state + 0x98) = aim_position[1] + CameraRuntime_ReadFloat(camera_state, 0x5c) + CameraRuntime_ReadFloat(camera_state, 0x94);
        *reinterpret_cast<float*>(state + 0x9c) = aim_position[2] + CameraRuntime_ReadFloat(camera_state, 0x60) + CameraRuntime_ReadFloat(camera_state, 0x98);
    }
    TimedBlend_Advance(reinterpret_cast<float*>(state + 0x88), true, frame_step);
    float progress = CameraRuntime_ReadFloat(state, 0x8c);
    if (progress > kZero && progress < 1.0f)
        progress = 0.5f - TrigKernel_00474934(progress * 3.1415927f) * 0.5f;
    float blended[3];
    if (progress > kZero) {
        if (progress < 1.0f) {
            for (int i = 0; i != 3; ++i)
                blended[i] = CameraRuntime_ReadFloat(state, 0x94 + i * 4) +
                    (CameraRuntime_ReadFloat(state, 0x30 + i * 4) - CameraRuntime_ReadFloat(state, 0x94 + i * 4)) * progress;
        } else {
            for (int i = 0; i != 3; ++i)
                blended[i] = CameraRuntime_ReadFloat(state, 0x30 + i * 4);
        }
    } else {
        for (int i = 0; i != 3; ++i)
            blended[i] = CameraRuntime_ReadFloat(state, 0x94 + i * 4);
    }
    Camera_UpdateRelativeOffset(camera_state, blended, aim_position, 1);
}
__attribute__((noinline)) void Camera_ConsumeActorCameraRequest(void* camera) {
    uint8_t* owner = *reinterpret_cast<uint8_t**>(
        static_cast<uint8_t*>(camera) + 0x64);
    uint8_t* request = owner + 0x30c;
    const uint8_t kind = request[0x0d];
    if (kind == 0)
        return;
    request[0x0e] = kind == 1 ? 1 : 0;
    request[0x0d] = 0;
}
__attribute__((noinline)) int Camera_BeginActorCameraRequest(void* camera) {
    uint8_t* owner = *reinterpret_cast<uint8_t**>(
        static_cast<uint8_t*>(camera) + 0x64);
    uint8_t* request = owner + 0x30c;
    if (request[0x0d] != 0)
        return 0;
    request[0x0d] = request[0x0e] != 0 ? 1 : 2;
    request[0x0e] = 0;
    return 0;
}
// Semantic reconstruction, JP Rev 1: 0x006E9F40.
__attribute__((noinline)) void Camera_CopyActorInputPacket(void* actor, const void* packet) {
    uint8_t* camera = *reinterpret_cast<uint8_t**>(static_cast<uint8_t*>(actor) + 0x64);
    if (camera == 0) {
        return;
    }
    const uint8_t* source = static_cast<const uint8_t*>(packet);
    camera[0x1028] = source[0];
    std::memcpy(camera + 0x102c, source + 4, 0x4c);
}
// Semantic reconstruction, JP Rev 1: 0x007DBE5C.
__attribute__((noinline)) void CameraAimFraming_InterpolateProfile(void* state, float progress) {
    uint8_t* values = static_cast<uint8_t*>(state);
    CameraRuntime_FloatAt(values, 0x6c) = CameraRuntime_Interpolate(CameraRuntime_FloatAt(values, 0x14), CameraRuntime_FloatAt(values, 0x40), progress);
    CameraRuntime_FloatAt(values, 0x70) = CameraRuntime_Interpolate(CameraRuntime_FloatAt(values, 0x18), CameraRuntime_FloatAt(values, 0x44), progress);
    CameraRuntime_FloatAt(values, 0x74) = CameraRuntime_Interpolate(CameraRuntime_FloatAt(values, 0x1c), CameraRuntime_FloatAt(values, 0x48), progress);
    CameraRuntime_FloatAt(values, 0x80) = CameraRuntime_Interpolate(CameraRuntime_FloatAt(values, 0x28), CameraRuntime_FloatAt(values, 0x54), progress);
    CameraRuntime_FloatAt(values, 0x84) = CameraRuntime_Interpolate(CameraRuntime_FloatAt(values, 0x2c), CameraRuntime_FloatAt(values, 0x58), progress);
    CameraRuntime_FloatAt(values, 0x88) = CameraRuntime_Interpolate(CameraRuntime_FloatAt(values, 0x30), CameraRuntime_FloatAt(values, 0x5c), progress);
    CameraRuntime_FloatAt(values, 0x8c) = CameraRuntime_Interpolate(CameraRuntime_FloatAt(values, 0x34), CameraRuntime_FloatAt(values, 0x60), progress);
    CameraRuntime_FloatAt(values, 0x90) = CameraRuntime_Interpolate(CameraRuntime_FloatAt(values, 0x38), CameraRuntime_FloatAt(values, 0x64), progress);
    CameraRuntime_FloatAt(values, 0x94) = CameraRuntime_Interpolate(CameraRuntime_FloatAt(values, 0x3c), CameraRuntime_FloatAt(values, 0x68), progress);
}
__attribute__((noinline)) void CameraAimFraming_UpdateProfile(uint8_t* state, const uint8_t* reticle,
                                    bool reset, float frame_step) {
    int category = 0;
    const int16_t reticle_kind = *reinterpret_cast<const int16_t*>(reticle + 0x22);
    if (reticle_kind == 800) category = 3;
    else if (reticle_kind == 0x322) category = 2;
    else if (reticle_kind == 0x321) category = 1;
    int mode;
    switch (reticle[0xe1]) {
    case 0: mode = 1; break;
    case 1: mode = 2; break;
    case 2: mode = 3; break;
    default:
        mode = FUN_00A9B994(reticle) == 0 ? (reticle[0xf8] < 1 ? 0 : 4) : 5;
        break;
    }
    uint8_t* rows = FUN_0054ACE0(g_AimFramingProfileTable);
    const int row_count = FUN_0054ACD0(g_AimFramingProfileTable);
    uint8_t* selected = 0;
    for (int i = 0; i < row_count; ++i) {
        uint8_t* row = rows + i * 0x48;
        const int32_t* keys = reinterpret_cast<const int32_t*>(row);
        if ((keys[0] == -1000 || keys[0] == category) &&
            (keys[1] == -1000 || keys[1] == mode)) {
            selected = row;
            break;
        }
    }
    if (selected == 0) return;
    uint8_t* extent_rows = FUN_0054ACE0(DAT_007DBE48.extent_table_000);
    uint8_t* extent = extent_rows + FUN_00910464(selected + 8, 0x20) * 0x20;
    std::memcpy(state + 0x40, extent, 0x20);
    uint8_t* aux_rows = FUN_0054ACE0(DAT_007DBE48.aux_table_004);
    uint8_t* aux = aux_rows + FUN_00910464(selected + 0x28, 0x20) * 0x0c;
    std::memcpy(state + 0x60, aux, 0x0c);
    float* blend = reinterpret_cast<float*>(state + 8);
    if (!reset) {
        if (*reinterpret_cast<uint8_t**>(state + 4) != selected) {
            std::memcpy(state + 0x14, state + 0x6c, 0x2c);
            TimedBlend_SetProgress(blend, blend[1]);
        }
        TimedBlend_Advance(blend, true, frame_step);
        std::memcpy(state + 0x6c, state + 0x40, 0x2c);
        if (blend[1] < 1.0f) CameraAimFraming_InterpolateProfile(state, blend[1]);
    } else {
        std::memcpy(state + 0x14, state + 0x40, 0x2c);
        std::memcpy(state + 0x6c, state + 0x40, 0x20);
        std::memcpy(state + 0x8c, state + 0x34, 0x0c);
        TimedBlend_SetProgress(blend, blend[1]);
    }
    std::memcpy(state + 0x98, state + 0x6c, 0x2c);
    const float kUnset = DAT_007DBE48.unset_010;
    if (CameraRuntime_FloatAt(state, 0xc4) != kUnset) CameraRuntime_FloatAt(state, 0x98) = CameraRuntime_FloatAt(state, 0xc4);
    if (CameraRuntime_FloatAt(state, 0xc8) != kUnset) CameraRuntime_FloatAt(state, 0x9c) = CameraRuntime_FloatAt(state, 0xc8);
    if (CameraRuntime_FloatAt(state, 0xcc) != kUnset) CameraRuntime_FloatAt(state, 0xa0) = CameraRuntime_FloatAt(state, 0xcc);
    if (*reinterpret_cast<const int32_t*>(state + 0xd0) == 0) CameraRuntime_FloatAt(state, 0xa4) = 0.0f;
    if (*reinterpret_cast<const int32_t*>(state + 0xd0) > 0) CameraRuntime_FloatAt(state, 0xa4) = 1.0f;
    if (*reinterpret_cast<const int32_t*>(state + 0xd4) == 0) CameraRuntime_FloatAt(state, 0xa8) = 0.0f;
    if (*reinterpret_cast<const int32_t*>(state + 0xd4) > 0) CameraRuntime_FloatAt(state, 0xa8) = 1.0f;
    if (CameraRuntime_FloatAt(state, 0xd8) != kUnset) CameraRuntime_FloatAt(state, 0xac) = CameraRuntime_FloatAt(state, 0xd8);
    *reinterpret_cast<uint8_t**>(state + 4) = selected;
}
__attribute__((noinline)) void Camera_UpdateTargetOverride(void* raw_state, float* camera_transform,
                                 void* actor_state, void* framing_state,
                                 void* target_state, unsigned int active_mode,
                                 void* mode_state, float frame_step) {
    (void)actor_state;
    (void)framing_state;
    uint8_t* state = static_cast<uint8_t*>(raw_state);
    const uint8_t* mode = static_cast<const uint8_t*>(mode_state);
    const uint8_t* target_record = static_cast<const uint8_t*>(target_state);
    typedef uint32_t (*StateModeQuery)(void*);
    bool entered = false;
    bool active = false;
    const float activation_progress = UpdateKeyedTransition_00745F58(
        state, &entered, &active, static_cast<int>(active_mode), frame_step);
    if (active) {
        if (entered) {
            *reinterpret_cast<float*>(state + 0x64) = camera_transform[0x34 / 4];
            *reinterpret_cast<float*>(state + 0x68) = camera_transform[0x38 / 4];
            AngleSpring_Reset(state + 0x14, camera_transform[0x34 / 4]);
            AngleSpring_Reset(state + 0x3c, camera_transform[0x38 / 4]);
        }
        void** state_vtable = *reinterpret_cast<void***>(state);
        const StateModeQuery state_mode_query =
            reinterpret_cast<StateModeQuery>(state_vtable[2]);
        if (state_mode_query(state) == active_mode && state[0x11] == 0) {
            if (state[0x9e] == 1) {
                const uint32_t handle =
                    *reinterpret_cast<const uint32_t*>(state + 0xa0);
                if ((handle >> 9) != 0x7fffffU) {
                    uint8_t* entry = g_TargetHandleTable + (handle & 0x1ffU) * 8;
                    if (*reinterpret_cast<const uint32_t*>(entry + 4) ==
                        (handle >> 9)) {
                        const uint8_t* target =
                            *reinterpret_cast<const uint8_t* const*>(entry);
                        if (target != 0) {
                            BoneTransform_TransformPoint(
                                reinterpret_cast<float*>(state + 0xfc),
                                reinterpret_cast<const float*>(state + 0xd0), target,
                                reinterpret_cast<const void*>(static_cast<uintptr_t>(
                                    *reinterpret_cast<const int32_t*>(state + 0xf4))),
                                reinterpret_cast<const void*>(static_cast<uintptr_t>(
                                    *reinterpret_cast<const int32_t*>(state + 0xf8))));
                        }
                    }
                }
            }
            const uint8_t* actor = static_cast<const uint8_t*>(actor_state);
            const float actor_x = *reinterpret_cast<const float*>(actor + 0x2c);
            const float actor_z = *reinterpret_cast<const float*>(actor + 0x34);
            const float camera_x = camera_transform[0x24 / 4];
            const float camera_z = camera_transform[0x2c / 4];
            const float target_x = *reinterpret_cast<const float*>(state + 0xfc);
            const float target_z = *reinterpret_cast<const float*>(state + 0x104);
            const float target_range = std::sqrt(
                (target_x - actor_x) * (target_x - actor_x) +
                (target_z - actor_z) * (target_z - actor_z));
            const float camera_range = std::sqrt(
                (camera_x - actor_x) * (camera_x - actor_x) +
                (camera_z - actor_z) * (camera_z - actor_z));
            const float raw_ratio = target_range / camera_range - 0.5f;
            float ratio = 0.0f;
            if (raw_ratio > 0.0f)
                ratio = raw_ratio < 1.0f ? raw_ratio : 1.0f;
            const float anchor_x = actor_x + (camera_x - actor_x) * ratio;
            const float anchor_z = actor_z + (camera_z - actor_z) * ratio;
            float direction[3] = {target_x - anchor_x, 0.0f,
                                  target_z - anchor_z};
            if (Vec3_NormalizeAndGetLength(direction, 0, direction)) {
                float target_yaw = Vec3_ComputeYaw(direction);
                float yaw_offset =
                    *reinterpret_cast<const float*>(state + 0x78);
                if (ratio > 0.0f) {
                    const float end_offset =
                        *reinterpret_cast<const float*>(state + 0x7c);
                    yaw_offset = ratio < 1.0f
                        ? yaw_offset + (end_offset - yaw_offset) * ratio
                        : end_offset;
                }
                if (ratio > 0.0f && state[0xf0] == 0 &&
                    *reinterpret_cast<const uint32_t*>(mode + 0x24) <
                        0x3f800000U) {
                    if (*reinterpret_cast<const float*>(
                            static_cast<const uint8_t*>(framing_state) +
                            0x50) > 0.0f)
                        yaw_offset = -yaw_offset;
                    target_yaw += yaw_offset;
                }
                *reinterpret_cast<float*>(state + 0x64) = target_yaw;
            }
            if (state[0x9d] == 1) {
                *reinterpret_cast<float*>(state + 0x68) =
                    *reinterpret_cast<const float*>(target_record + 0x08);
            } else {
                float pitch_direction[3] = {
                    target_x - camera_transform[0],
                    *reinterpret_cast<const float*>(state + 0x100) - camera_transform[1],
                    target_z - camera_transform[2]};
                if (Vec3_NormalizeAndGetLength(pitch_direction, 0,
                                                pitch_direction)) {
                    float target_pitch = Vec3_ComputePitch(pitch_direction);
                    const float upper =
                        *reinterpret_cast<const float*>(state + 0x80);
                    const float lower =
                        *reinterpret_cast<const float*>(state + 0x84);
                    if (target_pitch > upper) target_pitch = upper;
                    else if (target_pitch <= lower) target_pitch = lower;
                    *reinterpret_cast<float*>(state + 0x68) = target_pitch;
                }
            }
            float target_yaw = 0.0f;
            float target_pitch = 0.0f;
            const bool constrained = Camera_TargetOverride_ClampYaw_00809C5C(
                state, &target_yaw, &target_pitch, camera_transform);
            if (!constrained) {
                const float spring_step = frame_step * activation_progress;
                AngleSpring_IntegrateSample(
                    state + 0x14, camera_transform[0x34 / 4]);
                AngleSpring_IntegrateSample(
                    state + 0x3c, camera_transform[0x38 / 4]);
                const bool yaw_settled = AngleSpring_IsSettled_Thunk(
                    state + 0x14, target_yaw,
                    *reinterpret_cast<const float*>(state + 0x70));
                const bool pitch_settled = AngleSpring_IsSettled_Thunk(
                    state + 0x3c, target_pitch,
                    *reinterpret_cast<const float*>(state + 0x74));
                if (!yaw_settled || !pitch_settled) {
                    AngleSpring_StepBothStages(state + 0x14, target_yaw,
                                               spring_step);
                    AngleSpring_StepBothStages(state + 0x3c, target_pitch,
                                               spring_step);
                    Camera_RebuildTransformFromYawPitch(
                        camera_transform,
                        *reinterpret_cast<float*>(state + 0x24),
                        *reinterpret_cast<float*>(state + 0x4c));
                }
            } else {
                AngleSpring_Reset(state + 0x14,
                                  camera_transform[0x34 / 4]);
                AngleSpring_Reset(state + 0x3c,
                                  camera_transform[0x38 / 4]);
                if (state[0x11] == 1) state[0x11] = 2;
            }
        }
        if (state[0x11] == 1) {
            const bool waiting = state[0x6c] == 0 &&
                                  state[0xf0] == 0 && state[0xf1] == 0;
            if (!waiting ||
                (AngleSpring_IsSettled_Thunk(
                     state + 0x14, *reinterpret_cast<const float*>(state + 0x64),
                     *reinterpret_cast<const float*>(state + 0x70)) &&
                 (state[0x9d] != 0 ||
                  AngleSpring_IsSettled_Thunk(
                      state + 0x3c, *reinterpret_cast<const float*>(state + 0x68),
                      *reinterpret_cast<const float*>(state + 0x74))))) {
                state[0x11] = 2;
            }
        }
    }
    if (*reinterpret_cast<const int32_t*>(state + 0x88) == -1)
        return;
    bool complete = false;
    if (state[0x94] == 0) {
        const float duration = *reinterpret_cast<const float*>(state + 0x98);
        if (duration >= 0.0f) {
            float& elapsed = *reinterpret_cast<float*>(state + 0x108);
            elapsed += frame_step;
            complete = elapsed > duration;
        }
    } else if (state[0x94] == 1) {
        const uint32_t handle = *reinterpret_cast<const uint32_t*>(state + 0xa0);
        const uint32_t generation = handle >> 9;
        if (state[0x9e] == 1) {
            uint8_t* entry = g_TargetHandleTable + (handle & 0x1ffU) * 8;
            complete = generation == 0x7fffffU ||
                       *reinterpret_cast<const uint32_t*>(entry + 4) != generation ||
                       *reinterpret_cast<const void* const*>(entry) == 0;
        }
    }
    const int32_t previous_count = *reinterpret_cast<const int32_t*>(state + 0x10c);
    *reinterpret_cast<int32_t*>(state + 0x10c) = *reinterpret_cast<int32_t*>(state + 0x10c) + 1;
    if (complete && previous_count + 1 > 2) {
        *reinterpret_cast<int32_t*>(state + 0x88) = -1;
        state[0x8c] = 0xff;
    }
}
// Semantic reconstruction, JP Rev 1: 0x007F04D8.
__attribute__((noinline)) void Camera_UpdateTargetOverrideWithDefaultAngles(
    void* state, float* camera_transform, void* actor_state,
    void* framing_state, void* target_state, unsigned int active_mode,
    void* mode_state, float frame_step) {
    uint8_t* bytes = static_cast<uint8_t*>(state);
    *reinterpret_cast<float*>(bytes + 0x78) = 0.436332315f;
    *reinterpret_cast<float*>(bytes + 0x7c) = 0.261799395f;
    *reinterpret_cast<float*>(bytes + 0x80) = 1.04719758f;
    *reinterpret_cast<float*>(bytes + 0x84) = -1.04719758f;
    Camera_UpdateTargetOverride(state, camera_transform, actor_state,
                                framing_state, target_state, active_mode,
                                mode_state, frame_step);
}
extern "C" __attribute__((noinline)) void Camera_ActorUpdateAimResourceState_00704008(
    uint8_t* owner, const float* translation, const void* update_context,
    float projection, float frame_step) {
    uint8_t* reticle;
    uint8_t* const resource_state =
        *reinterpret_cast<uint8_t* const*>(owner + 0x9c);
    bool forward;
    float target;
    if (resource_state == 0 || owner[0xb8] != 0)
        return;
    reticle = static_cast<uint8_t*>(Camera_GetActorReticle(owner + 0x98));
    const int8_t category = *reinterpret_cast<const int8_t*>(
        owner + 0x179);
    FUN_0083322C(owner + 0x109c, 0, reticle, owner + 0x10c,
                 translation, update_context, category, frame_step);
    const bool mode_ready =
        *reinterpret_cast<const int32_t*>(owner + 0xfcc) >= 0 &&
        owner[0xfc1] == 2;
    const uintptr_t context_bits =
        reinterpret_cast<uintptr_t>(update_context);
    if ((context_bits & ~static_cast<uintptr_t>(mode_ready)) == 0U) {
        owner[0x10ac] = 1;
        TimedBlend_SetProgress(reinterpret_cast<float*>(owner + 0x10b0),
                               1.0f);
        owner[0x380] = 0;
        target = 0.0f;
        if (mode_ready) {
            owner[0x109c] = 0;
            TimedBlend_SetProgress(reinterpret_cast<float*>(owner + 0x10a0),
                                   0.0f);
        }
    } else {
        target = *reinterpret_cast<const float*>(owner + 0x34c);
        const int16_t category_value =
            *reinterpret_cast<const int16_t*>(owner + 0xba);
        if (category_value == 0x322) {
            target = 8.0f;
        } else {
            const uint8_t* record =
                *reinterpret_cast<const uint8_t* const*>(owner + 0x3ac);
            target = *reinterpret_cast<const float*>(record + 0x3c);
        }
        if (owner[0x10ac] == 0)
            target += 2.0f;
        uint32_t reticle_progress_bits = 0;
        std::memcpy(&reticle_progress_bits, owner + 0x17c,
                    sizeof(reticle_progress_bits));
        if (category != -1 && reticle_progress_bits >= 0x3f800000u) {
            if (category == 1)
                target += 5.0f;
            else if (category == 2)
                target += 20.0f;
            else
                target += 10.0f;
        }
    }
    forward = *reinterpret_cast<const float*>(owner + 0x34c) > 0.0f ||
              projection >= target;
    owner[0x10ac] = static_cast<uint8_t>(forward);
    TimedBlend_Advance(reinterpret_cast<float*>(owner + 0x10b0), forward,
                       frame_step);
    const uint8_t provider_gate =
        *reinterpret_cast<const uint8_t*>(owner + 0x1098) == 0 ? 1 : 0;
    const bool enter_provider_tail =
        (*reinterpret_cast<const int8_t*>(owner + 0x10bc) |
         static_cast<int8_t>(provider_gate)) != 0;
    if (!enter_provider_tail)
        return;
    const float blend = *reinterpret_cast<const float*>(owner + 0x10b4);
    float eased = blend;
    if (blend < 1.0f)
        eased = 0.5f - TrigKernel_00474934(blend * 3.1415927f) * 0.5f;
    const uint32_t quantized = static_cast<uint32_t>(
        (1.0f - *reinterpret_cast<const float*>(owner + 0x34c)) *
            (80.0f + 175.0f * eased) + 0.0001f);
    const int publish_flag = quantized >= 3U ? 1 : 0;
    const bool blend_incomplete = blend < 1.0f;
    uint8_t* resource_table = resource_state + 0x30;
    if (blend_incomplete)
        FUN_0043A3A0(resource_table, 0, -1, eased);
    SourceLinkedRecordDispatch_00463610(resource_table, 0, quantized);
    FUN_00A2CD60(owner + 0xc0, publish_flag);
    uint8_t** shared_slot = reinterpret_cast<uint8_t**>(0x00d637ecu);
    if (*shared_slot == 0)
        *shared_slot = static_cast<uint8_t*>(
            Engine_SharedResourceSingleton_00422D20());
    FUN_005B9838(*reinterpret_cast<void**>(*shared_slot + 0x48),
                 quantized < 0xfeU ? eased : 1.0f);
    const uint32_t table_sentinel = 0x007fffffu;
    uint8_t* generation_table = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(0x00e11614u));
    const uint8_t* first_source =
        *reinterpret_cast<const uint8_t* const*>(owner + 0xa0);
    const uint32_t first_handle =
        *reinterpret_cast<const uint32_t*>(first_source + 0x4c);
    if ((first_handle >> 9) != table_sentinel) {
        const uint32_t first_index = first_handle & (table_sentinel >> 14);
        uint8_t* entry = *reinterpret_cast<uint8_t**>(
            generation_table + first_index * 8);
        if (entry != 0 && *reinterpret_cast<const uint32_t*>(entry + 4) ==
                               (first_handle >> 9)) {
            uint8_t* record = static_cast<uint8_t*>(
                FUN_004EE6EC(*reinterpret_cast<void**>(entry)));
            if (record != 0) {
                if (blend_incomplete)
                    FUN_0043A3A0(record + 0x30, 0, -1, eased);
                SourceLinkedRecordDispatch_00463610(record + 0x30, 0,
                                                    quantized);
                FUN_00544B98(record + 0x24, publish_flag, 1);
            }
        }
    }
    const uint32_t second_handle =
        *reinterpret_cast<const uint32_t*>(owner + 0x180);
    if ((second_handle >> 9) != table_sentinel) {
        const uint32_t second_index = second_handle & 0x1ffu;
        uint8_t* entry = *reinterpret_cast<uint8_t**>(
            generation_table + second_index * 8);
        if (entry != 0 && *reinterpret_cast<const uint32_t*>(entry + 4) ==
                               (second_handle >> 9)) {
            uint8_t* record = static_cast<uint8_t*>(
                FUN_004EE6EC(*reinterpret_cast<void**>(entry)));
            if (record != 0) {
                if (blend_incomplete) {
                    FUN_0043A3A0(record + 0x30, 0, -1, eased);
                    FUN_0043A3A0(record + 0x30, 1, -1, eased);
                }
                SourceLinkedRecordDispatch_00463610(record + 0x30, 0,
                                                    quantized);
                SourceLinkedRecordDispatch_00463610(record + 0x30, 1,
                                                    quantized);
            }
        }
    }
}
