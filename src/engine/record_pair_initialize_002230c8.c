#include <stdint.h>
__attribute__((noinline)) void Engine_RecordPairInitialize_002230C8(uint32_t *record,
                                           uint32_t value, uint32_t tail)
{
    record[2] = tail;
    ((uint8_t *)record)[0xc] = 0xeu;
    record[0] = value;
    ((uint8_t *)record)[0xd] = 0xeu;
    record[1] = value;
}
