#include <stdint.h>
__attribute__((noinline)) int Engine_RecordHalfwordIs64_00B38C2C(void *object)
{
    return *(const uint16_t *)((const uint8_t *)object + 0x18u) == 0x40u;
}
