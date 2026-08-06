// KIU jp_rev1 address reconstructed here: 0x00717F8C.
#include <cstdint>
extern "C" __attribute__((noinline)) void RenderResource_InvokeModeCallback_00717F8C(
    void* object, std::uint32_t mode) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    if (*reinterpret_cast<void**>(bytes + 0x64) == 0)
        return;
    void** vtable = *reinterpret_cast<void***>(
        *reinterpret_cast<void**>(bytes + 0x64));
    typedef void(*Callback)(void*, std::uint32_t);
    void* callback_object = *reinterpret_cast<void**>(bytes + 0x64);
    reinterpret_cast<Callback>(vtable[0x18 / sizeof(void*)])(
        callback_object, mode);
}
