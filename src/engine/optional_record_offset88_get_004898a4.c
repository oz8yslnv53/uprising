#include <stdint.h>
__attribute__((noinline)) void *Engine_OptionalRecordOffset88Get_004898A4(uint8_t **slot)
{
    void *result = 0;
    uint8_t *record = *slot;
    if (record != 0)
        result = record + 0x88;
    return result;
}
