#include <stdint.h>
__attribute__((noinline)) bool Engine_GlobalStateSlot8_IsSet_00601638(void)
{
    const uintptr_t global = 0x00D48358u;
    return *(volatile const uint32_t *)(global + 0x8u) != 0u;
}
