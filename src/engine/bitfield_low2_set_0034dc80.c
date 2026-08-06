#include <stdint.h>
__attribute__((noinline)) void Bitfield_Low2Set_0034DC80(void *object, uint32_t value)
{
    uint32_t *field = (uint32_t *)((uint8_t *)object + 4u);
    *field = (*field & 0xFFFFFFFCu) | (value & 3u);
}
