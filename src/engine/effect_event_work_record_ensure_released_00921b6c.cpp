#include <cstdint>
extern "C" void ResourceRecord_Unlink_00464184(std::int32_t* record);
extern "C" __attribute__((noinline)) std::int32_t EffectEvent_WorkRecordEnsureReleased_00921B6C(
    void* work_record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(work_record);
    if (bytes[0x3e] == 0) {
        ResourceRecord_Unlink_00464184(
            reinterpret_cast<std::int32_t*>(bytes + 0x20));
        bytes[0x3e] = 1;
    }
    return 1;
}
