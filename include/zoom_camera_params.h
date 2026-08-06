#pragma once
#include "param_descriptor.h"
#include <cstddef>
#include <cstdint>
struct AngleParam {
    const void* type;
    float degrees;
    float radians;
};
typedef char kiu_sa_zoom_camera_params_1[(sizeof(AngleParam) == 0x0c) ? 1 : -1] __attribute__((unused));
struct ZoomCameraParams {
    AngleParam input_pitch_offset_max;
    AngleParam input_pitch_offset_min;
    AngleParam zoom_view_angle;
    float zoom_interp_time;
    float zoom_time;
    float zoom_distance;
    float normal_mode_delay_time;
    float slope_pitch_offset_multiplier;
    float target_translucent_alpha;
    float target_translucent_distance;
    float target_translucent_interp_time;
    float focus_distance_offset;
};
typedef char kiu_sa_zoom_camera_params_2[(sizeof(ZoomCameraParams) == 0x48) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_zoom_camera_params_3[(offsetof(ZoomCameraParams, zoom_view_angle) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_zoom_camera_params_4[(offsetof(ZoomCameraParams, zoom_interp_time) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_zoom_camera_params_5[(offsetof(ZoomCameraParams, focus_distance_offset) == 0x44) ? 1 : -1] __attribute__((unused));
class ParamRegistrar {
public:
    virtual ~ParamRegistrar() {}
    virtual void register_param(const void* descriptor) = 0;
};
void register_camera_params(void* params, ParamRegistrar* registrar);
void register_zoom_camera_params(ZoomCameraParams* params, ParamRegistrar* registrar);
