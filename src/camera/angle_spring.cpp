#include <cstdint>
#include "camera_motion_views.h"
__attribute__((noinline)) float WrapAngleRadians(float radians) {
    union FloatBits {
        float f;
        std::uint32_t u;
    };
    FloatBits fb;
    fb.f = radians;
    const std::uint32_t bits = fb.u;
    std::uint32_t neg_pi_bits = 0xC0490FDBu;
    const std::uint32_t pos_pi_bits = neg_pi_bits + 0x80000000u;
    if (bits <= neg_pi_bits) {
        if (static_cast<std::int32_t>(bits) <= static_cast<std::int32_t>(pos_pi_bits)) {
            return radians;
        }
    }
    FloatBits copysign_pi;
    copysign_pi.u = (bits & 0x80000000u) | pos_pi_bits;
    FloatBits inv_two_pi;
    inv_two_pi.u = 0x3E22F983u;
    FloatBits two_pi;
    two_pi.u = 0x40C90FDBu;
    const float scaled = (radians + copysign_pi.f) * inv_two_pi.f;
    const float n = static_cast<float>(static_cast<std::int32_t>(scaled));
    return radians - n * two_pi.f;
}
__attribute__((noinline)) void AngleSpring_Reset(AngleSpring* spring, float value) {
    spring->stage_a.value = value;
    spring->stage_b.value = value;
}
__attribute__((noinline)) void AngleSpringStage_Step(AngleSpringStage* stage, float target,
                           float frame_step) {
    (void)frame_step;
    float delta = target - stage->value;
    if (stage->angle_wrap) delta = WrapAngleRadians(delta);
    if (stage->threshold < (delta < 0.0f ? -delta : delta)) {
        float value = stage->value + stage->rate;
        if (stage->angle_wrap) value = WrapAngleRadians(value);
        stage->value = value;
    }
}
__attribute__((noinline)) void AngleSpring_StepBothStages(AngleSpring* spring, float target,
                                float frame_step) {
    AngleSpringStage_Step(&spring->stage_a, target, frame_step);
    AngleSpringStage_Step(&spring->stage_b, spring->stage_a.value, frame_step);
}
__attribute__((noinline)) void AngleSpring_IntegrateSample(AngleSpring* spring, float sample) {
    float delta = sample - spring->stage_b.value;
    if (spring->stage_b.angle_wrap) delta = WrapAngleRadians(delta);
    spring->stage_b.value = sample;
    float value = spring->stage_a.value + delta;
    if (spring->stage_a.angle_wrap) value = WrapAngleRadians(value);
    spring->stage_a.value = value;
}
__attribute__((noinline)) bool AngleSpring_IsSettled(const AngleSpring* spring, float target, float threshold) {
    const bool wrap = spring->stage_b.angle_wrap != 0;
    float delta_b = spring->stage_b.value - target;
    if (wrap) delta_b = WrapAngleRadians(delta_b);
    if (threshold < (delta_b < 0.0f ? -delta_b : delta_b)) return false;
    float delta_a = spring->stage_a.value - target;
    if (wrap) delta_a = WrapAngleRadians(delta_a);
    return (delta_a < 0.0f ? -delta_a : delta_a) <= threshold;
}
