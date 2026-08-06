#include <cstdint>
#include <cstddef>
#include "camera_motion_views.h"
extern "C" float* Vec3Spring_StepTowardTarget(Vec3Spring* spring, const float* target);
extern "C" void Vec3Spring_ComputeDelta(const Vec3Spring* spring, float* out_delta,
                                         const float* target, const float* current);
__attribute__((noinline)) bool DoubleVec3Spring_IsSettledWithThreshold_00B46260(
    const DoubleVec3Spring* state, const float* target, float threshold) {
    float delta[3];
    Vec3Spring_ComputeDelta(&state->second, delta, target, state->second.value);
    float squared = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    if (threshold < (squared < 0.0f ? -squared : squared)) return false;
    Vec3Spring_ComputeDelta(&state->first, delta, target, state->first.value);
    squared = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    return threshold >= (squared < 0.0f ? -squared : squared);
}
__attribute__((noinline)) float* DoubleVec3Spring_Step_0090AEBC(DoubleVec3Spring* state, const float* target) {
    Vec3Spring_StepTowardTarget(&state->first, target);
    Vec3Spring_StepTowardTarget(&state->second, state->first.value);
    return state->second.value;
}
__attribute__((noinline)) bool DoubleVec3Spring_IsSettled_00B461B0(const DoubleVec3Spring* state, const float* target) {
    const float kThresholdScale = 9.0f; // 0x41100000, DAT_00b4625c
    float threshold = state->second.threshold * kThresholdScale;
    float delta[3];
    Vec3Spring_ComputeDelta(&state->second, delta, target, state->second.value);
    float second_sq = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    second_sq = (second_sq < 0.0f) ? -second_sq : second_sq;
    if (second_sq > threshold) {
        return false;
    }
    Vec3Spring_ComputeDelta(&state->first, delta, target, state->first.value);
    float first_sq = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    first_sq = (first_sq < 0.0f) ? -first_sq : first_sq;
    return threshold >= first_sq;
}
__attribute__((noinline)) float* DoubleVec3Spring_Reset_0090AE84(DoubleVec3Spring* state, const float* target) {
    state->first.value[0] = target[0];
    state->first.value[1] = target[1];
    state->first.value[2] = target[2];
    state->second.value[0] = target[0];
    state->second.value[1] = target[1];
    state->second.value[2] = target[2];
    return state->second.value;
}
__attribute__((noinline)) void DoubleVec3Spring_Retarget_0090AEEC(DoubleVec3Spring* state, const float* target) {
    float delta[3];
    Vec3Spring_ComputeDelta(&state->second, delta, target, state->second.value);
    float neg_delta[3] = {-delta[0], -delta[1], -delta[2]};
    float new_first[3];
    Vec3Spring_ComputeDelta(&state->first, new_first, state->first.value, neg_delta);
    state->first.value[0] = new_first[0];
    state->first.value[1] = new_first[1];
    state->first.value[2] = new_first[2];
    state->second.value[0] = target[0];
    state->second.value[1] = target[1];
    state->second.value[2] = target[2];
}
struct DoubleVec3SpringConfigureConstantsView {
    float second_rate_scale_000;
    float second_reserved_004;
};
typedef char kiu_sa_double_vec3_spring_constants_1[
    (sizeof(DoubleVec3SpringConfigureConstantsView) == 0x08) ? 1 : -1] __attribute__((unused));
extern "C" const DoubleVec3SpringConfigureConstantsView DAT_005C7FC0;
__attribute__((noinline)) void DoubleVec3Spring_ConfigureRates_005C7FA4(DoubleVec3Spring* state, float rate,
                                               float reserved_04) {
    state->first.rate = rate;
    state->first.reserved_04 = reserved_04;
    state->second.rate = rate * DAT_005C7FC0.second_rate_scale_000;
    state->second.reserved_04 = DAT_005C7FC0.second_reserved_004;
}
