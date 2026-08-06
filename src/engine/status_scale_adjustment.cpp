// KIU jp_rev1 status-scale adjustment readers at 0x005C2AD4/0x005C9934.
#include <cstdint>
extern "C" void* StatusScale_GetSharedState_0057F8C8();
extern "C" __attribute__((noinline)) int StatusScale_GlobalScalar_005C9934() {
    std::uint8_t* state = static_cast<std::uint8_t*>(
        StatusScale_GetSharedState_0057F8C8());
    return *reinterpret_cast<std::int32_t*>(state + 0x14);
}
extern "C" __attribute__((noinline)) int StatusScale_AdjustmentReadA(void* adjustment) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(adjustment);
    if (*reinterpret_cast<void**>(bytes + 0xB4) == 0)
        return 1;
    return StatusScale_GlobalScalar_005C9934();
}
