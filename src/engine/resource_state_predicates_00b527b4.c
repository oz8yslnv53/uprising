#include <stdint.h>
__attribute__((noinline)) int ResourceState_IsReady_00B527B4(const uint8_t *state)
{
    return *(const uint32_t *)(state + 4) >= 8;
}
