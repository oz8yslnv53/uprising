#include <cstdint>
extern "C" __attribute__((noinline)) std::uint8_t
EngineResource_IsActive_00B60960(const void* resource) {
    return *(static_cast<const std::uint8_t*>(resource) + 0x840) & 1u;
}
