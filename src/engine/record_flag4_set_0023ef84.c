#include <stdint.h>
__attribute__((noinline)) void Record_SetFlag4FromBoolean_0023EF84(uint8_t *record, uint8_t enabled)
{
    uint32_t flags = record[0x0c];
    flags &= ~0x04u;
    enabled = (uint8_t)(flags | ((uint32_t)enabled << 2));
    record[0x0c] = enabled;
}
