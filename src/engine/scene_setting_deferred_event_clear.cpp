#include <cstdint>
extern "C" __attribute__((noinline)) void SceneSetting_DeferredEvent_ClearRecord_00A40910(void* record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x00) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x04) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x10) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x14) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x18) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x1c) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x20) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x24) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28) = 0;
}
