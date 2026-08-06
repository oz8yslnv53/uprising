#include <stdint.h>
__attribute__((noinline)) void Engine_RecordType3_002F2630(uint8_t *record,
                                 const uint32_t *source,
                                 uint32_t field10)
{
    record[4] = 3;
    *(uint32_t *)(record + 0x10) = field10;
    *(uint32_t *)record = *source;
}
