#include <stdint.h>
__attribute__((noinline)) int Engine_SignClassMatchesByte_00112610(const int32_t *value,
                                         const int8_t *expected)
{
    int32_t signed_value = *value;
    int8_t expected_value = *expected;
    return ((signed_value >> 31) + 1) == expected_value;
}
