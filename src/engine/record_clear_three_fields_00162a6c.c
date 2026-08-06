#include <stdint.h>
__attribute__((noinline)) void Record_ClearThreeFields_00162A6C(void *record)
{
    *(uint32_t *)record = 0u;
    ((uint8_t *)record)[4] = 0u;
    *(uint32_t *)((uint8_t *)record + 8u) = 0u;
}
