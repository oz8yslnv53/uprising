#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t ResourceStream_DescriptorValue_00601650(
    void* queue) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(queue);
    const std::uint32_t* const descriptor =
        *reinterpret_cast<const std::uint32_t* const*>(bytes);
    return descriptor[0x48 / sizeof(std::uint32_t)];
}
