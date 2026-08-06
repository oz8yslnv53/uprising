#pragma once
#include "zoom_camera_params.h"
#include <cstddef>
#include <cstdint>
struct ReticleParams {
    float keep_time;
    float fade_time;
    float input_velocity_air_multiplier;
    float input_velocity_zoom_add_ratio;
    float flick_velocity;
    float flick_length;
    float flick_interp_ground;
    float flick_interp_air;
    float lock_on_range_x;
    float lock_on_range_y;
    float lock_on_radius_ratio;
    float lock_on_interp_coefficient;
    std::uint8_t normal_color_red;
    std::uint8_t normal_color_green;
    std::uint8_t normal_color_blue;
    std::uint8_t attack_color_red;
    std::uint8_t attack_color_green;
    std::uint8_t attack_color_blue;
    std::uint8_t charge_color_1_red;
    std::uint8_t charge_color_1_green;
    std::uint8_t charge_color_1_blue;
    std::uint8_t charge_color_2_red;
    std::uint8_t charge_color_2_green;
    std::uint8_t charge_color_2_blue;
    std::uint8_t item_color_red;
    std::uint8_t item_color_green;
    std::uint8_t item_color_blue;
    std::uint8_t reserved;
};
typedef char kiu_sa_reticle_params_1[(sizeof(ReticleParams) == 0x40) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_reticle_params_2[(offsetof(ReticleParams, lock_on_range_x) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_reticle_params_3[(offsetof(ReticleParams, normal_color_red) == 0x30) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_reticle_params_4[(offsetof(ReticleParams, item_color_blue) == 0x3e) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_reticle_params_5[(offsetof(ReticleParams, reserved) == 0x3f) ? 1 : -1] __attribute__((unused));
void register_reticle_params(ReticleParams* params, ParamRegistrar* registrar);
