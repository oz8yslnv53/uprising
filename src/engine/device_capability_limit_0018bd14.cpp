#include <cstdint>
extern "C" int FUN_0014DAE8();
extern "C" __attribute__((noinline)) std::uint32_t DeviceCapability_Limit_0018BD14(
    std::uint32_t mode) {
    if (mode == 0x20000u) {
        FUN_0014DAE8();
        return 0x1F2FFFFFu;
    }
    if (mode == 0x30000u) {
        FUN_0014DAE8();
        return 0x1F5FFFFFu;
    }
    return 0;
}
