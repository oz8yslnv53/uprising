#include <stdint.h>
__attribute__((noinline)) uint8_t Engine_IndexedByteGet_00489650(
    const uint8_t *object, unsigned int index, int offset)
{
    const uintptr_t target =
        (uintptr_t)*(const uint8_t **)(object + index * 0x0cu + 4) + offset;
    if (target != 0)
        return *(const uint8_t *)target;
    return 0;
}
