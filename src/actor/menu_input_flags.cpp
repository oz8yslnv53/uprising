#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t MenuInput_GetCombinedFlags_002752B0(
    const void* input) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(input);
    return *reinterpret_cast<const std::uint32_t*>(bytes + 0x2c) |
           *reinterpret_cast<const std::uint32_t*>(bytes + 0x34);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuInput_HasTransitionFlags_002752C0(
    const void* input) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(input);
    std::uint32_t result =
        *reinterpret_cast<const std::uint32_t*>(bytes + 0x2c) & 0xf500u;
    if (result != 0)
        result = 1;
    return result;
}
