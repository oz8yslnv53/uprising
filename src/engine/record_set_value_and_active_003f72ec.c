#include <stdint.h>
__attribute__((noinline)) void Engine_RecordSetValueAndActive_003F72EC(void *record, uint32_t value)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)(bytes + 0x48) = value;
    bytes[0x78] = 1;
}
