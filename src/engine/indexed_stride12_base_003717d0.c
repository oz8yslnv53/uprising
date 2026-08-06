#include <stdint.h>
__attribute__((noinline)) uint32_t Indexed_Stride12Base_003717D0(void *object, int index)
{
    return *(uint32_t *)((uint8_t *)object + 0xCu) + index * 12;
}
