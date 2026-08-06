#include <cstdarg>
#include <cstdint>
extern "C" int Utf16_FormatBounded_0026D56C(
    std::uint16_t *output, std::uint32_t capacity,
    const std::uint16_t *format, std::va_list arguments);
extern "C" __attribute__((noinline)) void ParameterString_FormatUtf16_00261AC4(
    std::uint16_t *output, const std::uint16_t *format, ...)
{
    std::va_list arguments;
    va_start(arguments, format);
    Utf16_FormatBounded_0026D56C(output, 10u, format, arguments);
    va_end(arguments);
}
