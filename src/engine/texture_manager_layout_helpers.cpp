#include <cstdint>
extern "C" __attribute__((noinline)) std::uint8_t* TextureManager_GetMetadata_0090FDFC(
    void* manager) {
    return static_cast<std::uint8_t*>(manager) + 0x72c;
}
extern "C" __attribute__((noinline)) std::uint8_t* TextureManager_SlotAddress_0090FE08(
    void* manager, std::int32_t slot) {
    return static_cast<std::uint8_t*>(manager) + slot * 0x18 + 0x690;
}
