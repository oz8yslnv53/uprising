#include <cstdarg>
#include <cstdint>
extern "C" int Utf16_FormatBounded_0026D56C(
    std::uint16_t *output, std::uint32_t capacity,
    const std::uint16_t *format, std::va_list arguments);
extern "C" std::uint32_t Utf16_FormatWrapper_0049C748(
    std::uint16_t *output, std::uint32_t capacity, void *format,
    void *arguments);
extern "C" __attribute__((noinline)) int Utf16_FormatBounded_0026D56C(
    std::uint16_t *output, std::uint32_t capacity,
    const std::uint16_t *format, std::va_list arguments)
{
    if (capacity == 0u)
        return -1;
    const std::uint32_t produced = Utf16_FormatWrapper_0049C748(
        output, capacity, const_cast<std::uint16_t *>(format), &arguments);
    if (static_cast<std::int32_t>(produced) < 0) {
        *output = 0;
        return static_cast<int>(produced);
    }
    const std::uint32_t index = produced < capacity ? produced : capacity - 1u;
    output[index] = 0;
    return static_cast<int>(index);
}
static void ParameterString_FormatUtf16(
    std::uint16_t *output, std::uint32_t capacity,
    const std::uint16_t *format, std::va_list arguments)
{
    Utf16_FormatBounded_0026D56C(output, capacity, format, arguments);
}
extern "C" __attribute__((noinline)) void ParameterString_FormatUtf16_002F2598(
    std::uint16_t *output, const std::uint16_t *format, ...)
{
    std::va_list arguments;
    va_start(arguments, format);
    ParameterString_FormatUtf16(output, 0x20u, format, arguments);
    va_end(arguments);
}
extern "C" __attribute__((noinline)) void ParameterString_FormatUtf16_002A47D0(
    std::uint16_t *output, const std::uint16_t *format, ...)
{
    std::va_list arguments;
    va_start(arguments, format);
    ParameterString_FormatUtf16(output, 4u, format, arguments);
    va_end(arguments);
}
