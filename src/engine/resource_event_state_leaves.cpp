#include <cstdint>
extern "C" __attribute__((noinline)) void ResourceEvent_SetFlag2_00717FB0(void* record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    *reinterpret_cast<std::uint8_t*>(bytes + 0x68) |= 2u;
}
extern "C" __attribute__((noinline)) void ResourceEvent_ClearPayloadAndFlag2_00717FC0(void* record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    std::uint8_t* payload = *reinterpret_cast<std::uint8_t**>(bytes + 0x64);
    if (payload != 0) {
        void** vtable = *reinterpret_cast<void***>(payload);
        reinterpret_cast<void (*)(void*)>(vtable[1])(payload);
        *reinterpret_cast<void**>(bytes + 0x64) = 0;
    }
    *reinterpret_cast<std::uint8_t*>(bytes + 0x68) &= 0xfdu;
}
extern "C" __attribute__((noinline)) void ResourceEvent_InvokePayloadSlot14_00717FF8(void* record) {
    std::uint8_t* payload = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(record) + 0x64);
    void** vtable = *reinterpret_cast<void***>(payload);
    reinterpret_cast<void (*)(void*)>(vtable[5])(payload);
}
