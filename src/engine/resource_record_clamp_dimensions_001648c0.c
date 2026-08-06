#include <stdint.h>
__attribute__((noinline)) void ResourceRecord_ClampDimensions_001648C0(
    int16_t *record)
{
    if (record[0] < 0x28)
        record[0] = 0x28;
    if (record[1] < 0x24)
        record[1] = 0x24;
    if (record[3] > 0x91)
        record[3] = 0x91;
    if (record[4] > 0x91)
        record[4] = 0x91;
    if (record[5] > 0x91)
        record[5] = 0x91;
}
