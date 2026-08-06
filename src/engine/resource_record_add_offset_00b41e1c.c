#include <stdint.h>
__attribute__((noinline)) uint8_t *ResourceRecord_AddOffset_00B41E1C(uint8_t *record)
{
    return record + *(int32_t *)(record + 0x10);
}
