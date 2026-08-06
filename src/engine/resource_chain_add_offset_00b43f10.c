#include <stdint.h>
__attribute__((noinline)) uint8_t *ResourceChain_AddOffset_00B43F10(uint8_t *record)
{
    return record + *(int32_t *)(record + 4);
}
