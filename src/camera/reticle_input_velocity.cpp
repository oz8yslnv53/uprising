#include <cstdint>
extern "C" void ReticleInput_ComposeVelocity(float out[2], const void* input);
extern "C" void ActorReticle_ApplyCameraPitchCompensation(
    std::int8_t* reticle, float* vertical_delta, float* frame_context,
    int apply_limits, std::int8_t* camera_transform,
    float compensation_weight, float rate_scale_a, float rate_scale_b);
extern "C" float InverseLerpClamped(float value, float lo, float hi);
extern "C" __attribute__((noinline)) const float* ActorReticleAir_GetAdditiveVelocity(const void* reticle)
{
    return reinterpret_cast<const float*>(
        reinterpret_cast<const std::uint8_t*>(reticle) + 0x2F4);
}
__attribute__((noinline)) void ActorReticle_IntegrateInputVelocity(std::int32_t* reticle,
                                          float* frame_context,
                                          std::int8_t* camera_owner,
                                          float frame_step)
{
    float input_velocity[2];
    ReticleInput_ComposeVelocity(input_velocity,
                                 reinterpret_cast<std::uint8_t*>(reticle) + 0x100);
    typedef float*(*GetVelocity)(void*);
    void** vtable = *reinterpret_cast<void***>(reticle);
    const float* additive = reinterpret_cast<GetVelocity>(vtable[0x30 / sizeof(void*)])
                                (reticle);
    float delta[2] = {(input_velocity[0] + additive[0]) * frame_step,
                      (input_velocity[1] + additive[1]) * frame_step};
    if (camera_owner != 0 && reinterpret_cast<std::uint8_t*>(reticle)[0xD5] == 0) {
        std::uint8_t* bytes = reinterpret_cast<std::uint8_t*>(reticle);
        const bool special_path =
            bytes[0x14C] != 0 &&
            *reinterpret_cast<float*>(bytes + 0x19C) == 0.0f &&
            *reinterpret_cast<float*>(bytes + 0x1A0) == 0.0f &&
            *reinterpret_cast<float*>(bytes + 0x1C8) == 0.0f &&
            *reinterpret_cast<float*>(bytes + 0x1CC) == 0.0f;
        if (special_path) {
            float blend = InverseLerpClamped(
                *reinterpret_cast<float*>(bytes + 0x160), 0.6981316804885864f,
                3.1415927410125732f);
            if (blend > 0.0f) {
                blend = blend < 1.0f ? 0.1f + 0.7f * blend : 0.1f;
            }
            if (blend > 0.0f) {
                ActorReticle_ApplyCameraPitchCompensation(
                    reinterpret_cast<std::int8_t*>(reticle), &delta[1],
                    frame_context, 1, camera_owner, 1.0f, 0.8726646304130554f,
                    blend);
            }
        } else {
            ActorReticle_ApplyCameraPitchCompensation(
                reinterpret_cast<std::int8_t*>(reticle), &delta[1],
                frame_context, 1, camera_owner, 1.0f, 0.8726646304130554f, 0.0f);
        }
    }
    float* aim = reinterpret_cast<float*>(reinterpret_cast<std::uint8_t*>(reticle) + 0xA4);
    aim[0] += delta[0];
    aim[1] += delta[1];
}
