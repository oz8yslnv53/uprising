#include <stdint.h>
__attribute__((noinline)) int FUN_00B36ABC(uint8_t *object, uint32_t mask)
{
    return (mask & ~(uint32_t)object[0x50]) == 0;
}
