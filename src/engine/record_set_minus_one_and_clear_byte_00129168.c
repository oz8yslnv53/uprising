#include <stdint.h>
__attribute__((noinline)) void Record_SetMinusOneAndClearByte_00129168(
    void *record)
{
    *(uint32_t *)record = 0xffffffffu;
    *((uint8_t *)record + 4u) = 0u;
}
