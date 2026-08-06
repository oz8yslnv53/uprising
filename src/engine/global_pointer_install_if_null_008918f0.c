#include <stdint.h>
__attribute__((noinline)) int GlobalPointer_InstallIfNull_008918F0(void *value)
{
    void **slot = (void **)(uintptr_t)0x00d4d050;
    if (*slot == 0)
    {
        *slot = value;
        return 1;
    }
    return 0;
}
