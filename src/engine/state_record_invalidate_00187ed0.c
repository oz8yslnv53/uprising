#include <stdint.h>
void Engine_StateRecord_Invalidate_00187ED0(uint8_t *record)
{
    if (record[0] != 0u) {
        *(uint32_t *)(record + 0x3cu) = 0xffffffffu;
        record[0] = 0u;
    }
}
