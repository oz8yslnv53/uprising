#include <stdint.h>
extern void Engine_ClearField38_001503BC(void *object);
extern void Engine_InitializePairZero2000_00150634(uint32_t *words);
__attribute__((noinline)) void *RenderResource_Initialize_001303C8(
    void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    *(uint32_t *)(bytes + 0x00) = 0x00D1FF38u;
    *(uint32_t *)(bytes + 0x04) = 0;
    bytes[0x08] = 1;
    *(uint32_t *)(bytes + 0x0c) = 0;
    *(uint32_t *)(bytes + 0x10) = 0;
    *(uint32_t *)(bytes + 0x14) = 0;
    *(uint32_t *)(bytes + 0x18) = 0;
    bytes[0x1c] = 0;
    *(uint32_t *)(bytes + 0x24) = 0;
    *(uint32_t *)(bytes + 0x28) = 0;
    *(uint32_t *)(bytes + 0x2c) = 0;
    *(uint32_t *)(bytes + 0x30) = 0;
    bytes[0x34] = 0;
    Engine_ClearField38_001503BC(bytes + 4);
    Engine_InitializePairZero2000_00150634((uint32_t *)(bytes + 0x40));
    bytes[0x48] = 2;
    bytes[0x49] = 1;
    *(uint32_t *)(bytes + 0x4c) = 0;
    *(uint32_t *)(bytes + 0x54) = 0;
    bytes[0x50] = 0;
    return object;
}
