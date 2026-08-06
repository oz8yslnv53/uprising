#include <cstdint>
typedef void(*ResourceVirtualCall)(void *);
extern "C" __attribute__((noinline)) void ResourceHandle_InvokeVirtual20_0054EC94(void *handle) {
    std::uint8_t* resource = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t *>(handle) + 4);
    if (!resource)
        return;
    std::uint8_t* vtable = *reinterpret_cast<std::uint8_t**>(resource);
    ResourceVirtualCall call = *reinterpret_cast<ResourceVirtualCall *>(vtable + 0x20);
    call(resource);
}
extern "C" __attribute__((noinline)) void ResourceHandle_InvokeVirtual20_0054ECC0(void *handle) {
    std::uint8_t* resource = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t *>(handle) + 4);
    if (!resource)
        return;
    std::uint8_t* vtable = *reinterpret_cast<std::uint8_t**>(resource);
    ResourceVirtualCall call = *reinterpret_cast<ResourceVirtualCall *>(vtable + 0x20);
    call(resource);
}
