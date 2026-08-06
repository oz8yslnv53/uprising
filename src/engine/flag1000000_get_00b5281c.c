#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_Flag1000000Get_00B5281C(const uint32_t *value)
{
    return (*value & 0x01000000u) >> 24;
}
