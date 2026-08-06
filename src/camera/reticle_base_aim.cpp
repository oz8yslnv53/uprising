#include <cstdint>
extern "C" __attribute__((noinline)) const float* ActorReticleGround_GetAdditiveVelocity() {
    return reinterpret_cast<const float*>(0x00D4DE24);
}
extern "C" float AngleUnitsAtan2(float y, float x);
extern "C" float TrigKernel_00474AB0(float x);
extern "C" float RandomUniform01_00588DFC();
extern "C" float ComputePitchRateRatio_005927A8(void* reticle_unused, void* camera_transform);
struct ActorReticleAimCoordinateConstantsView {
    float angle_units_to_radians_000;
    float random_angle_scale_004;
    float shrink_scale_008;
    float shrink_base_00c;
};
typedef char kiu_sa_actor_reticle_aim_coordinate_constants_1[
    (sizeof(ActorReticleAimCoordinateConstantsView) == 0x10) ? 1 : -1] __attribute__((unused));
extern "C" const ActorReticleAimCoordinateConstantsView DAT_00575F44;
extern "C" void FUN_0049c5e4(void* reticle_plus_0x88);
extern "C" void* FUN_005499fc();
__attribute__((noinline)) void ActorReticle_ComputeBaseAimCoordinate(float* out_xy, std::uint8_t* reticle) {
    float* extent_x = reinterpret_cast<float*>(reticle + 0xe4);
    float* extent_y = reinterpret_cast<float*>(reticle + 0xec);
    out_xy[0] = *extent_x;
    out_xy[1] = *extent_y;
    if (reticle[0x81] == 0) {
        FUN_0049c5e4(reticle + 0x88);
        void* active_transform = FUN_005499fc();
        if (active_transform != 0) {
            float ratio = ComputePitchRateRatio_005927A8(reticle, active_transform);
            out_xy[1] -= out_xy[1] * ratio;
        }
        return;
    }
    if (reticle[0x80] != 2) {
        return;
    }
    const float kSignThreshold = 0.5f;               // 0x3F000000
    float reference_angle = AngleUnitsAtan2(*extent_y, *extent_x) *
                            DAT_00575F44.angle_units_to_radians_000;
    float random_angle = RandomUniform01_00588DFC() *
                         DAT_00575F44.random_angle_scale_004;
    float trig = TrigKernel_00474AB0(random_angle);
    float x_offset = *extent_x;
    float y_offset = *extent_y;
    if (random_angle < reference_angle) {
        y_offset = *extent_x * trig;
    } else {
        x_offset = *extent_y / trig;
    }
    float shrink = DAT_00575F44.shrink_base_00c -
                   RandomUniform01_00588DFC() * DAT_00575F44.shrink_scale_008;
    x_offset *= shrink;
    y_offset *= shrink;
    if (RandomUniform01_00588DFC() < kSignThreshold) {
        x_offset = -x_offset;
    }
    if (RandomUniform01_00588DFC() < kSignThreshold) {
        y_offset = -y_offset;
    }
    out_xy[0] = *extent_x + x_offset;
    out_xy[1] = *extent_y + y_offset;
}
__attribute__((noinline)) void ActorReticle_UpdateAimCoordinates(std::uint8_t* reticle) {
    if ((*reinterpret_cast<const std::uint32_t*>(reticle + 0x84) & 0x3u) != 0) {
        return;
    }
    float aim[2];
    ActorReticle_ComputeBaseAimCoordinate(aim, reticle);
    *reinterpret_cast<float*>(reticle + 0xa4) = aim[0];
    *reinterpret_cast<float*>(reticle + 0xa8) = aim[1];
}
