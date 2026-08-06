#include <stdint.h>
__attribute__((noinline)) void Engine_GlobalRecordActivate_0034D3A4(uint32_t value)
{
    uint8_t *record = (uint8_t *)0x00D5DD54u;
    *(uint32_t *)(record + 4) = value;
    record[0] = 1;
}
