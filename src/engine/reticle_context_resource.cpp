#include <cstdint>
extern "C" __attribute__((noinline)) void*
Engine_ReticleContextResource_00A9B988(const void* context) {
    const std::uint8_t* const owner = *reinterpret_cast<const std::uint8_t* const*>(
        static_cast<const std::uint8_t*>(context) + 0x08);
    return *reinterpret_cast<void* const*>(owner + 0x28);
}
