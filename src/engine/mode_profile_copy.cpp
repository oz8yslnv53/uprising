#include <cstdint>
extern "C" const void* ModeProfile_GetSelectedBlock(const void* profile);
struct EightWords {
    float values[8];
};
extern "C" __attribute__((noinline)) void ModeProfile_CopyEightWords(
    std::uint32_t output[8], const void*, std::int32_t object) {
    const EightWords* source = static_cast<const EightWords*>(ModeProfile_GetSelectedBlock(
        reinterpret_cast<const std::uint8_t*>(static_cast<std::uintptr_t>(object)) + 0x298));
    *reinterpret_cast<EightWords*>(output) = *source;
}
