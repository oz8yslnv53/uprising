#include <cstdint>
extern "C" std::uint8_t *g_RenderCommand_SubmissionState_00D4E4E4;
extern "C" __attribute__((noinline)) void RenderResource_ClearSlotDirty_00B8850C(std::uint32_t slot)
{
    std::uint8_t*state = g_RenderCommand_SubmissionState_00D4E4E4;
    unsigned char* dirty = state + slot * 0x18u + 0x3fdu;
    if (*dirty != 0u) {
        *dirty = 0u;
        *reinterpret_cast<std::uint32_t *>(state) |= 0x40u;
    }
}
