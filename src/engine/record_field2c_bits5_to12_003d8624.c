#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_RecordField2CBits5To12_003D8624(const void *record)
{
    const uint32_t word = *(const uint32_t *)((const uint8_t *)record + 0x2c);
    return (word & 0x1fffu) >> 5;
}
