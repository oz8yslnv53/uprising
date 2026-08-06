#include <stdint.h>
__attribute__((noinline)) int Engine_SignedByteField10BGet_00B37780(const void *object)
{
    const unsigned char *base = (const unsigned char *)object + 0x100;
    return *(const int8_t *)(base + 0xb);
}
