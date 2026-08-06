#include <stdint.h>
__attribute__((noinline)) unsigned int Engine_GlobalSignedByteInvert_00AF2798(void)
{
    volatile int8_t *value = (volatile int8_t *)(uintptr_t)0x00d4b128u;
    return (unsigned int)(*value ^ 1);
}
