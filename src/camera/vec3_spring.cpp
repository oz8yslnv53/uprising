#include <cmath>
#include <cstddef>
#include <cstdint>
#include "camera_motion_views.h"
float WrapAngleRadians(float radians);
__attribute__((noinline)) void Vec3Spring_ComputeDelta(const Vec3Spring* spring, float* out_delta,
                             const float* target, const float* current) {
    for (int i = 0; i < 3; ++i) {
        float delta = target[i] - current[i];
        if (spring->angle_wrap) delta = WrapAngleRadians(delta);
        out_delta[i] = delta;
    }
}
__attribute__((noinline)) float* Vec3Spring_StepTowardTarget(Vec3Spring* spring, const float* target) {
    float delta[3];
    Vec3Spring_ComputeDelta(spring, delta, target, spring->value);
    const float squared_magnitude =
        delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    if (spring->threshold < std::fabs(squared_magnitude)) {
        const float magnitude = std::sqrt(squared_magnitude);
        float rate = spring->rate;
        if (spring->angle_wrap) rate = WrapAngleRadians(rate);
        const float step = rate / magnitude;
        spring->value[0] += delta[0] * step;
        spring->value[1] += delta[1] * step;
        spring->value[2] += delta[2] * step;
        if (spring->angle_wrap) {
            for (int i = 0; i < 3; ++i) {
                spring->value[i] = WrapAngleRadians(spring->value[i]);
            }
        }
    }
    return spring->value;
}
__attribute__((noinline)) bool Vec3Spring_IsSettled(const Vec3Spring* spring, const float* target,
                          float threshold) {
    float delta[3];
    Vec3Spring_ComputeDelta(spring, delta, target, spring->value);
    const float squared_magnitude =
        delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    return std::fabs(squared_magnitude) <= threshold;
}
__attribute__((noinline)) float* Vec3Spring_Reset(Vec3Spring* spring, const float* target) {
    spring->value[0] = target[0];
    spring->value[1] = target[1];
    spring->value[2] = target[2];
    return spring->value;
}
