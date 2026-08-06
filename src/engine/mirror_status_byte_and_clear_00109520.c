#include <stdint.h>
__attribute__((noinline)) void Engine_MirrorStatusByteAndClear_00109520(uint8_t *object)
{
    uintptr_t address = (uintptr_t)object;
    int8_t state = *(int8_t *)(uintptr_t)(0x24b8u + address);
    *(int8_t *)(uintptr_t)(0x12279u + address) = state;
    if (state != 0) {
        *(uint32_t *)(object + 0x24bc) = 0;
        object[0x24b8] = 0;
    }
}
