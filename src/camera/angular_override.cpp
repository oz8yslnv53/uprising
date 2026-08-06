#include <cmath>
#include <cstdint>
// Semantic reconstruction, JP Rev 1: 0x00B0D48C.
__attribute__((noinline)) int CameraMode1AngularCorrection_GetModeId(void*  ) { return 1; }
extern "C" std::uint8_t* FUN_005C59B8(std::uint8_t* storage);
extern "C" std::uint8_t* FUN_005BF274(std::uint8_t* state);
extern "C" std::uint8_t* FUN_005C7F78(std::uint8_t* state);
extern "C" std::uint8_t* FUN_005BF2DC(std::uint8_t* state);
float TimedBlend_SetProgress(float* state, float progress);
struct DoubleVec3Spring;
extern "C" void DoubleVec3Spring_ConfigureRates_005C7FA4(DoubleVec3Spring* state, float rate,
                                                          float reserved_04);
struct CameraMode1AngularConstantsView {
    float activation_duration_000;
    float spring_epsilon_004;
    float nested_spring_value_008;
    float reserved_00c;
    float nested_spring_rate_010;
};
typedef char kiu_sa_camera_mode1_angular_constants_1[
    (sizeof(CameraMode1AngularConstantsView) == 0x14) ? 1 : -1] __attribute__((unused));
extern "C" const CameraMode1AngularConstantsView DAT_005BB5A4;
__attribute__((noinline)) std::uint8_t* CameraMode1AngularCorrection_Init(std::uint8_t* storage) {
    std::uint8_t* root = FUN_005C59B8(storage);
    *reinterpret_cast<std::uint32_t*>(root) = 0x00CF6C74u;
    std::uint8_t* state = FUN_005BF274(root + 0x14);
    state = FUN_005BF274(state + 0x28);
    state[0x64] = 0;
    state = FUN_005C7F78(state + 0x68);
    state = FUN_005BF2DC(state + 0x0c);
    std::uint8_t* controller = state - 0x74;
    float* activation = reinterpret_cast<float*>(controller + 0x04);
    if (activation[0] != DAT_005BB5A4.activation_duration_000) {
        activation[0] = DAT_005BB5A4.activation_duration_000;
        TimedBlend_SetProgress(activation, activation[1]);
    }
    controller[0x1c] = 1;
    controller[0x30] = 1;
    *reinterpret_cast<float*>(controller + 0x20) = DAT_005BB5A4.spring_epsilon_004;
    *reinterpret_cast<float*>(controller + 0x34) = DAT_005BB5A4.spring_epsilon_004;
    controller[0x44] = 1;
    controller[0x58] = 1;
    *reinterpret_cast<float*>(controller + 0x48) = DAT_005BB5A4.spring_epsilon_004;
    *reinterpret_cast<float*>(controller + 0x5c) = DAT_005BB5A4.spring_epsilon_004;
    *reinterpret_cast<float*>(controller + 0xac) = 0.0f;
    *reinterpret_cast<float*>(state + 0x0c) = DAT_005BB5A4.nested_spring_value_008;
    *reinterpret_cast<float*>(state + 0x28) = DAT_005BB5A4.nested_spring_value_008;
    DoubleVec3Spring_ConfigureRates_005C7FA4(
        reinterpret_cast<DoubleVec3Spring*>(state),
        DAT_005BB5A4.nested_spring_rate_010, DAT_005BB5A4.reserved_00c);
    return controller;
}
extern "C" float UpdateKeyedTransition_00745F58(void* state, bool* out_at_start, bool* out_active,
                                                 int key, float step);
extern "C" void Camera_RebuildTransformFromYawPitch(float* transform, float yaw, float pitch);
extern "C" float WrapAngleRadians(float angle);
extern "C" float InverseLerpClamped(float value, float lo, float hi);
extern "C" float Vec3_ComputeYaw(const float* direction);
extern "C" float CameraAim_SeedPitchAdjustment_00B17A7C(
    const void*, const std::uint8_t*, const std::uint8_t*, const void*, float);
struct AngularOverrideDirectionSource {
    std::uint8_t padding_00[0xfc];
    std::uint8_t* linked_direction;
};
extern "C" __attribute__((noinline)) bool CameraAngularOverride_ReadDirection_00A2118C(
    const AngularOverrideDirectionSource* source, float* out_direction) {
    const std::uint8_t* linked = source->linked_direction;
    if (linked == 0) return false;
    const float* direction = reinterpret_cast<const float*>(linked + 0x30);
    out_direction[0] = direction[0];
    out_direction[1] = direction[1];
    out_direction[2] = direction[2];
    return true;
}
struct AngularOverrideControllerView {
    std::uint8_t padding_00[0x11];
    std::uint8_t request_stage;
    std::uint8_t padding_12[0x06];
    std::uint8_t* vtable;
    std::uint8_t padding_1c[0x34];
    float angular_target;
    float angular_result;
};
extern "C" void InitAngularOverride_008220BC(
    AngularOverrideControllerView* controller, const float* camera_transform,
    const std::uint8_t* frame_context, const std::uint8_t* override_record,
    const std::uint8_t* framing_profile) {
    if (*override_record != 0) {
        controller->angular_target = *reinterpret_cast<const float*>(override_record + 4);
        controller->angular_result = *reinterpret_cast<const float*>(override_record + 8);
        return;
    }
    controller->angular_target = *reinterpret_cast<const float*>(frame_context + 0x68);
    const std::uint8_t* owner = *reinterpret_cast<const std::uint8_t* const*>(frame_context + 8);
    const std::uint8_t* resource = owner == 0
        ? 0 : *reinterpret_cast<const std::uint8_t* const*>(owner + 0x34);
    if (resource != 0 && resource[4] != 0) {
        controller->angular_target = *reinterpret_cast<const float*>(
            reinterpret_cast<const std::uint8_t*>(camera_transform) + 0x34);
    }
    float linked_direction[3];
    const AngularOverrideDirectionSource* const direction_source = *reinterpret_cast<const AngularOverrideDirectionSource* const*>(
        frame_context + 0x10);
    if (direction_source != 0 &&
        CameraAngularOverride_ReadDirection_00A2118C(direction_source, linked_direction)) {
        const float linked_yaw = Vec3_ComputeYaw(linked_direction);
        float delta = WrapAngleRadians(linked_yaw - controller->angular_target);
        if (std::fabs(delta) > 0.2617994f) controller->angular_target = linked_yaw;
    }
    float pitch_delta = WrapAngleRadians(
        *reinterpret_cast<const float*>(reinterpret_cast<const std::uint8_t*>(camera_transform) + 0x38) -
        *reinterpret_cast<const float*>(override_record + 8));
    typedef const void*(*FramingGate)(const void*);
    const void* framing_gate = reinterpret_cast<FramingGate*>(controller->vtable)[1](controller);
    controller->angular_result = controller->angular_target + pitch_delta +
        CameraAim_SeedPitchAdjustment_00B17A7C(
            override_record, frame_context, framing_profile, framing_gate,
            controller->angular_target);
    if (controller->angular_result > 1.3962634f) controller->angular_result = 1.3962634f;
    if (controller->angular_result < -1.3962634f) controller->angular_result = -1.3962634f;
}
extern "C" float* DoubleVec3Spring_Step_0090AEBC(DoubleVec3Spring* state, const float* target);
extern "C" bool DoubleVec3Spring_IsSettled_00B461B0(const DoubleVec3Spring* state,
                                                     const float* target);
extern "C" float* DoubleVec3Spring_Reset_0090AE84(DoubleVec3Spring* state, const float* target);
extern "C" void DoubleVec3Spring_Retarget_0090AEEC(DoubleVec3Spring* state, const float* target);
__attribute__((noinline)) void Camera_UpdateAngularOverride(std::uint8_t* controller, float* camera_transform,
                                   std::uint8_t* frame_context, const std::uint8_t* init_arg_a,
                                   const std::uint8_t* init_arg_b, const std::uint8_t* init_arg_c, int key,
                                   float dt) {
    const float kFacingLo = 1.57079637f;  // 0x3FC90FDB, pi/2
    const float kFacingHi = 3.14159274f;  // 0x40490FDB, pi
    const float kFacingForced = -1.0f;    // 0xBF800000
    const float kSpringRate = 25.0f;       // 0x41C80000
    const float kSpringReserved04 = 9.59931087f; // 0x4119E8FA
    bool at_start = false;
    bool active = false;
    UpdateKeyedTransition_00745F58(controller, &at_start, &active, key, dt);
    if (!active) {
        return;
    }
    if (controller[0x11] == 1) {
        InitAngularOverride_008220BC(
            reinterpret_cast<AngularOverrideControllerView*>(controller), camera_transform,
            init_arg_a, init_arg_b,
                                      init_arg_c);
        controller[0x11] = 2;
    }
    DoubleVec3Spring* spring_state = reinterpret_cast<DoubleVec3Spring*>(controller + 0x18);
    float* target = reinterpret_cast<float*>(controller + 0x50);
    float current_orientation[3] = {camera_transform[0x0d], camera_transform[0x0e], 0.0f};
    if (!at_start) {
        DoubleVec3Spring_Retarget_0090AEEC(spring_state, current_orientation);
    } else {
        DoubleVec3Spring_Reset_0090AE84(spring_state, current_orientation);
        float delta = *target - camera_transform[0x0d]; // transform+0x34
        delta = WrapAngleRadians(delta);
        delta = (delta < 0.0f) ? -delta : delta;
        float facing = InverseLerpClamped(delta, kFacingLo, kFacingHi);
        if (facing <= 0.0f) {
            facing = kFacingForced;
        }
        *reinterpret_cast<float*>(frame_context + 0x250) = facing;
    }
    if (!DoubleVec3Spring_IsSettled_00B461B0(spring_state, target)) {
        DoubleVec3Spring_ConfigureRates_005C7FA4(spring_state, kSpringRate, kSpringReserved04);
        float* yaw_pitch = DoubleVec3Spring_Step_0090AEBC(spring_state, target);
        Camera_RebuildTransformFromYawPitch(camera_transform, yaw_pitch[0], yaw_pitch[1]);
    }
}
