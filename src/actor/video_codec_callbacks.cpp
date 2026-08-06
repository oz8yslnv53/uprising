#include <cstdint>
struct VideoCodecCallbackPairView {
    std::uint32_t allocate_callback;
    std::uint32_t release_callback;
};
extern VideoCodecCallbackPairView DAT_003b51d0;
extern VideoCodecCallbackPairView DAT_003b5248;
extern VideoCodecCallbackPairView DAT_003b5288;
extern VideoCodecCallbackPairView DAT_003b52b8;
extern VideoCodecCallbackPairView DAT_003b52e4;
extern void* DAT_003b52bc;
extern void VideoCodec_StateReset_0036A058(void* state);
extern "C" __attribute__((noinline)) void VideoCodec_CallbackRegister_003B51AC(
    std::uint32_t allocate, std::uint32_t release) {
    DAT_003b51d0.allocate_callback = allocate;
    DAT_003b51d0.release_callback = release;
}
extern "C" __attribute__((noinline)) void VideoCodec_CallbackRegister_003B5224(
    std::uint32_t allocate, std::uint32_t release) {
    DAT_003b5248.allocate_callback = allocate;
    DAT_003b5248.release_callback = release;
}
extern "C" __attribute__((noinline)) std::uint32_t VideoCodec_CallbackDefaults_003B8DF0(
    std::uint32_t* first, std::uint32_t* second, std::uint32_t* third) {
    *first = 1;
    *second = 1;
    *third = 0;
    return 0;
}
extern "C" __attribute__((noinline)) void VideoCodec_CallbackRegisterWithDefaults_003B524C(
    std::uint32_t allocate, std::uint32_t release) {
    std::uint32_t first;
    std::uint32_t second;
    std::uint32_t third;
    VideoCodec_CallbackDefaults_003B8DF0(&first, &second, &third);
    DAT_003b5288.allocate_callback = allocate;
    DAT_003b5288.release_callback = release;
}
extern "C" __attribute__((noinline)) void VideoCodec_CallbackRegisterWithStateReset_003B528C(
    std::uint32_t allocate, std::uint32_t release) {
    VideoCodec_StateReset_0036A058(DAT_003b52bc);
    DAT_003b52b8.allocate_callback = allocate;
    DAT_003b52b8.release_callback = release;
}
extern "C" __attribute__((noinline)) void VideoCodec_CallbackRegister_003B52C0(
    std::uint32_t allocate, std::uint32_t release) {
    DAT_003b52e4.allocate_callback = allocate;
    DAT_003b52e4.release_callback = release;
}
