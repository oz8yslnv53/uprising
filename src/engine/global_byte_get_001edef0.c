// 001EDEF0: return the byte at retained global address D4DDD0.
#include <stdint.h>
__attribute__((noinline)) unsigned int Engine_GlobalByteGet_001EDEF0(void)
{
    return *(volatile uint8_t *)(uintptr_t)0x00D4DDD0u;
}
