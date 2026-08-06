#include <cstdint>
extern "C" std::uint8_t* g_RenderCommand_SubmissionState_00D4E4E4;
// Retail 0x0018BCEC. Publishes the current packet mode to the caller's word.
extern "C" __attribute__((noinline)) void FUN_0018BCEC(
    std::uint32_t* output) {
    *output = g_RenderCommand_SubmissionState_00D4E4E4[0x0c] == 0
        ? 0x800u : 0x801u;
}
extern "C" __attribute__((noinline)) void FUN_0018BD50(
    std::uint32_t mode) {
    if (mode == 0x800u) {
        mode = 0;
    } else {
        mode -= 0x800u;
        if (mode != 1u)
            return;
        mode = 1;
    }
    g_RenderCommand_SubmissionState_00D4E4E4[0x0c] =
        static_cast<std::uint8_t>(mode);
}
