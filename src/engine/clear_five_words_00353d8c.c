#include <stdint.h>
__attribute__((noinline)) void Engine_ClearFiveWords_00353D8C(uint32_t *record)
{
    record[0x48 / 4] = 0;
    record[0x4c / 4] = 0;
    record[0x50 / 4] = 0;
    record[0x54 / 4] = 0;
    record[0x58 / 4] = 0;
}
