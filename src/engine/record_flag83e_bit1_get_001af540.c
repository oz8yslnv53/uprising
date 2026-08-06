#include <stdint.h>
__attribute__((noinline)) uint32_t Record_Flag83EBit1Get_001AF540(void *record)
{
    return (((uint8_t *)record)[0x83Eu] & 2u) >> 1;
}
