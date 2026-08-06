#include <stdint.h>
#include <stdarg.h>
extern int Utf16_FormatBounded_0026D56C(uint16_t *output, uint32_t capacity,
                                       const void *format, va_list arguments);
__attribute__((noinline)) void Utf16_FormatFiveFromPair_00326A2C(uint16_t *output, const void *format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    Utf16_FormatBounded_0026D56C(output, 5u, format, arguments);
    va_end(arguments);
}
