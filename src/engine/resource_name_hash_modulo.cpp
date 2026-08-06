#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t ResourceName_HashModulo_0049CC14(
    const char *text, std::uint32_t divisor)
{
    std::uint32_t hash = 0;
    std::uint32_t index = 0;
    for (;;) {
        const std::int32_t character = static_cast<std::int32_t>(
            static_cast<signed char>(text[index]));
        if (character == 0)
            break;
        ++index;
        hash = hash * 0x492u + static_cast<std::uint32_t>(character);
    }
    return hash % divisor;
}
