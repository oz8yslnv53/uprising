#include <stdint.h>
__attribute__((noinline)) int Engine_HasNestedPointer_00901FD0(const void *object)
{
    return *(const void *const *)((const uint8_t *)object + 8) != 0;
}
