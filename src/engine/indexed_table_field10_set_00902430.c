#include <stdint.h>
__attribute__((noinline)) void Engine_IndexedTableField10Set_00902430(void *object, uint32_t index)
{
    const uint32_t *table = (const uint32_t *)(uintptr_t)0x00CE3C00u;
    *(uint32_t *)((uint8_t *)object + 0x10) = table[index];
}
