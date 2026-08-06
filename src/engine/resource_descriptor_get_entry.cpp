#include <cstdint>
extern "C" __attribute__((noinline)) std::uintptr_t
ResourceDescriptor_GetEntry_005AF908(const void* descriptor, std::uint32_t index) {
    const std::uintptr_t base = *reinterpret_cast<const std::uintptr_t*>(
        static_cast<const std::uint8_t*>(descriptor) + 0x10);
    if (base != 0 && index < *reinterpret_cast<const std::uint32_t*>(
                          static_cast<const std::uint8_t*>(descriptor) + 0x08))
        return base + index * 0x0C;
    return 0;
}
