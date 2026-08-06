#include <cstdint>
extern "C" __attribute__((noinline)) void Engine_VirtualResourceCallback_00448728(void *owner)
{
    std::uint8_t* owner_bytes = static_cast<std::uint8_t*>(owner);
    void* resource = *reinterpret_cast<void**>(owner_bytes + 0x04);
    if (resource == 0)
        return;
    std::uint8_t* vtable = *reinterpret_cast<std::uint8_t**>(resource);
    void (*callback)(void *) = *reinterpret_cast<void (**)(void *)>(vtable + 0x2c);
    callback(resource);
}
