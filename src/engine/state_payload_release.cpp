#include <cstdint>
extern "C" __attribute__((noinline)) void StatePayload_Release(const std::uint32_t handle[2])
{
    std::uint8_t* payload = reinterpret_cast<std::uint8_t*>
        (static_cast<std::uintptr_t>(handle[1]));
    if (payload == 0)
        return;
    typedef void(*Release)(void *);
    Release* vtable = *reinterpret_cast<Release**>(payload);
    vtable[0x2c / sizeof(void *)](payload);
}
