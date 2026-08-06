#ifndef CAMERA_MOTION_VIEWS_H
#define CAMERA_MOTION_VIEWS_H
#include <cstddef>
#include <cstdint>
struct TimedBlendView {
    float duration;
    float progress;
    float elapsed;
};
class TransitionKeyProvider {
public:
    virtual ~TransitionKeyProvider() {}
    virtual int GetActiveKey() const = 0;
};
struct Transition {
    TransitionKeyProvider* provider; 
    float duration;                  
    float progress;                  
    float elapsed;                   
    std::uint8_t snap_at_start;      
};
struct AngleSpringStage {
    float rate;
    float reserved_04;
    std::uint8_t angle_wrap;
    std::uint8_t padding[3];
    float threshold;
    float value;
};
struct AngleSpring {
    AngleSpringStage stage_a;
    AngleSpringStage stage_b;
};
struct Vec3Spring {
    float rate;
    float reserved_04; 
    std::uint8_t angle_wrap;
    std::uint8_t padding[3];
    float threshold;
    float value[3];
};
struct DoubleVec3Spring {
    Vec3Spring first;  
    Vec3Spring second;  
};
struct CameraTrackKeyframeView {
    std::uint8_t opaque_000[0x08];
    std::uint32_t start_handle;
    std::uint8_t opaque_00c[0x28];
    float start_fallback[3];
    std::uint8_t opaque_040[0x08];
    std::uint32_t end_handle;
    std::uint8_t opaque_04c[0x28];
    float end_fallback[3];
    float segment_offset;
    float duration;
    float segment_delay;
};
struct CameraTrackStateView {
    CameraTrackKeyframeView keyframes[3];
    std::uint8_t opaque_1a4[4];
    float total_duration;
    std::uint8_t collision_enabled;
    std::uint8_t opaque_1ad;
    std::uint8_t field_1ae;
    std::uint8_t padding_1af;
    float sentinel;
    std::uint8_t transition_active;
    std::uint8_t opaque_1b5[3];
    std::int32_t keyframe_index;
    float segment_value;
    float segment_time;
    float start_position[3];
    float end_position[3];
    float source_transform[7];
    float destination_transform[7];
};
struct CameraTrackCollisionRayView {
    float origin[3];
    float direction[3];
    float length;
};
struct CameraTrackCollisionRecordView {
    float opaque_00[2];
    float distance;
    float opaque_0c[6];
};
typedef char kiu_sa_camera_motion_views_1[(sizeof(TimedBlendView) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_2[(sizeof(Transition) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_3[(offsetof(Transition, snap_at_start) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_4[(sizeof(AngleSpringStage) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_5[(sizeof(AngleSpring) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_6[(offsetof(Vec3Spring, value) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_7[(sizeof(Vec3Spring) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_8[(offsetof(DoubleVec3Spring, second) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_9[(sizeof(DoubleVec3Spring) == 0x38) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_10[(offsetof(CameraTrackKeyframeView, start_handle) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_11[(offsetof(CameraTrackKeyframeView, start_fallback) == 0x34) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_12[(offsetof(CameraTrackKeyframeView, end_handle) == 0x48) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_13[(offsetof(CameraTrackKeyframeView, end_fallback) == 0x74) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_14[(offsetof(CameraTrackKeyframeView, segment_offset) == 0x80) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_15[(offsetof(CameraTrackKeyframeView, duration) == 0x84) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_16[(sizeof(CameraTrackKeyframeView) == 0x8c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_17[(offsetof(CameraTrackStateView, total_duration) == 0x1a8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_18[(offsetof(CameraTrackStateView, collision_enabled) == 0x1ac) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_19[(offsetof(CameraTrackStateView, field_1ae) == 0x1ae) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_20[(offsetof(CameraTrackStateView, sentinel) == 0x1b0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_21[(offsetof(CameraTrackStateView, keyframe_index) == 0x1b8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_22[(offsetof(CameraTrackStateView, segment_time) == 0x1c0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_23[(offsetof(CameraTrackStateView, start_position) == 0x1c4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_24[(offsetof(CameraTrackStateView, source_transform) == 0x1dc) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_25[(offsetof(CameraTrackStateView, destination_transform) == 0x1f8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_26[(sizeof(CameraTrackStateView) == 0x214) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_27[(sizeof(CameraTrackCollisionRayView) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_28[(offsetof(CameraTrackCollisionRecordView, distance) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_camera_motion_views_29[(sizeof(CameraTrackCollisionRecordView) == 0x24) ? 1 : -1] __attribute__((unused));
#endif 
