#include <cstdint>
extern "C" __attribute__((noinline)) void StateHandle_ReleasePayload(
    std::uint32_t handle[2], const std::uint32_t descriptor[3]) {
    void* payload = *reinterpret_cast<void* const*>(descriptor + 1);
    if (payload != 0) {
        typedef void(*Release)(std::uint32_t*, void*);
        void* vtable = *reinterpret_cast<void* const*>(payload);
        Release release = *reinterpret_cast<Release*>(
            reinterpret_cast<std::uint8_t*>(vtable) + 0x40);
        release(handle, payload);
        return;
    }
    handle[1] = 0;
}
