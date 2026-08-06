#include <cstdint>
#include <cstddef>
#include "camera_motion_views.h"
float TimedBlend_SetProgress(float* state, float progress);
struct CameraYawImpulseStateView {
    std::uint32_t vtable;
    TimedBlendView outer_blend;
    std::uint8_t opaque_010[0x04];
    float amplitude;
    float alternate_duration;
    std::uint8_t kind;
    std::uint8_t sign;
    std::uint8_t opaque_01e[0x02];
    TimedBlendView blend;
    float cached_elapsed;
};
typedef char kiu_sa_yaw_impulse_1[(offsetof(CameraYawImpulseStateView, amplitude) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_yaw_impulse_2[(offsetof(CameraYawImpulseStateView, alternate_duration) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_yaw_impulse_3[(offsetof(CameraYawImpulseStateView, kind) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_yaw_impulse_4[(offsetof(CameraYawImpulseStateView, blend) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_yaw_impulse_5[(offsetof(CameraYawImpulseStateView, cached_elapsed) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_yaw_impulse_6[(sizeof(CameraYawImpulseStateView) == 0x30) ? 1 : -1] __attribute__((unused));
struct CameraYawImpulseConstantsView {
    float amplitude_000;
    float alternate_duration_004;
    float cached_elapsed_008;
    float outer_duration_00c;
};
typedef char kiu_sa_yaw_impulse_constants_1[
    (sizeof(CameraYawImpulseConstantsView) == 0x10) ? 1 : -1] __attribute__((unused));
extern "C" const CameraYawImpulseConstantsView DAT_005BB4D8;
struct CameraYawImpulseEaseConstantsView {
    float fresh_progress_000;
    float alt_duration_004;
    float ease_pi_008;
    float ease_half_00c;
};
typedef char kiu_sa_yaw_impulse_ease_constants_1[
    (sizeof(CameraYawImpulseEaseConstantsView) == 0x10) ? 1 : -1] __attribute__((unused));
extern "C" const CameraYawImpulseEaseConstantsView DAT_007CA734;
// Semantic reconstruction, JP Rev 1: 0x00B0D484.
__attribute__((noinline)) int CameraYawImpulse_GetModeId(void*  ) { return 7; }
// Semantic reconstruction, JP Rev 1: 0x007CA570.
__attribute__((noinline)) bool CameraYawImpulse_IsActive(const std::int32_t* state, std::int32_t selected_mode) {
    if (*reinterpret_cast<const std::uint8_t*>(state + 7) == 1)
        return true;
    typedef std::int32_t(*ModeIdFn)(const std::int32_t*);
    ModeIdFn const* vtable = *reinterpret_cast<ModeIdFn const* const*>(state);
    const std::int32_t mode_id = vtable[2](state);
    return mode_id == selected_mode && *reinterpret_cast<const float*>(state + 9) > 0.0f;
}
extern "C" std::uint8_t* FUN_005C59B8(std::uint8_t* storage);
extern "C" float* FUN_005C7F78(float* state);
__attribute__((noinline)) std::uint8_t* CameraYawImpulse_Init(std::uint8_t* storage) {
    std::uint8_t* allocated = FUN_005C59B8(storage);
    CameraYawImpulseStateView* state = reinterpret_cast<CameraYawImpulseStateView*>(allocated);
    state->vtable = 0x00CF6C60u;
    state->amplitude = DAT_005BB4D8.amplitude_000;
    state->alternate_duration = DAT_005BB4D8.alternate_duration_004;
    state->kind = 0;
    state->sign = 1;
    float* nested_end = FUN_005C7F78(&state->blend.duration);
    state = reinterpret_cast<CameraYawImpulseStateView*>(
        reinterpret_cast<std::uint8_t*>(nested_end) - 0x20);
    state->cached_elapsed = DAT_005BB4D8.cached_elapsed_008;
    state->outer_blend.duration = DAT_005BB4D8.outer_duration_00c;
    TimedBlend_SetProgress(&state->outer_blend.duration,
                           state->outer_blend.progress);
    return reinterpret_cast<std::uint8_t*>(state);
}
extern "C" void Camera_RebuildTransformFromYawPitch(float* transform, float yaw, float pitch);
extern "C" void CameraController_UpdateActivationState(void* state, std::uint8_t* out_entered,
                                                         std::uint8_t* out_active, int mode,
                                                         float step);
float TimedBlend_Advance(float* state, bool forward, float step);
float TimedBlend_SetProgress(float* state, float progress);
extern "C" float RandomUniform01_00588DFC();
extern "C" float TrigKernel_00474934(float x); // libm-cluster Cody-Waite trig
__attribute__((noinline)) void Camera_UpdateYawImpulse(std::uint8_t* state, float* transform, int mode_byte,
                              int reroll_sign_gate, float dt) {
    const float kFreshProgress = DAT_007CA734.fresh_progress_000;
    const float kAltDuration = DAT_007CA734.alt_duration_004;
    const float kEasePi = DAT_007CA734.ease_pi_008;
    const float kEaseHalf = DAT_007CA734.ease_half_00c;
    const float kSignThreshold = 0.5f;
    std::uint8_t entered = 0;
    std::uint8_t active = 0;
    CameraController_UpdateActivationState(state, &entered, &active, mode_byte, dt);
    if (!active) {
        return;
    }
    float* blend = reinterpret_cast<float*>(state + 0x20);
    float* amplitude = reinterpret_cast<float*>(state + 0x14);
    float* cached_elapsed = reinterpret_cast<float*>(state + 0x2c);
    if (entered) {
        if (reroll_sign_gate != 0) {
            state[0x1d] = (RandomUniform01_00588DFC() < kSignThreshold) ? 1 : 0;
        }
        TimedBlend_SetProgress(blend, kFreshProgress);
        *cached_elapsed = kFreshProgress;
    } else {
        TimedBlend_SetProgress(blend, *cached_elapsed / *amplitude);
    }
    float target_duration = (state[0x1c] != 0) ? kAltDuration
                                                 : *reinterpret_cast<float*>(state + 0x18);
    if (blend[0] != target_duration) {
        blend[0] = target_duration;
        TimedBlend_SetProgress(blend, blend[1]);
    }
    TimedBlend_Advance(blend, state[0x1c] != 0, dt);
    float progress = blend[1];
    float ease = progress;
    if (kFreshProgress < progress && progress < 1.0f) {
        float cosine = TrigKernel_00474934(progress * kEasePi);
        ease = kEaseHalf - cosine * kEaseHalf;
    }
    float delta = *amplitude * (ease * dt);
    if (state[0x1d] == 0) {
        delta = -delta;
    }
    float yaw = transform[0x0d] + delta; // transform+0x34
    float pitch = transform[0x0e];       // transform+0x38
    Camera_RebuildTransformFromYawPitch(transform, yaw, pitch);
    *cached_elapsed = *amplitude * progress;
}
