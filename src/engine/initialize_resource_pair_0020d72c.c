#include <stdint.h>
void Engine_InitializeResourceSlot_001EBE20(void *destination,
                                            uint32_t *source,
                                            uint32_t mode);
__attribute__((noinline)) uint32_t Engine_InitializeResourcePair_0020D72C(uint8_t *object)
{
    uint32_t *first = *(uint32_t **)(object + 0x70);
    Engine_InitializeResourceSlot_001EBE20(object + 0xf4, first, 0);
    Engine_InitializeResourceSlot_001EBE20(object + 0xf4,
                                           *(uint32_t **)(object + 0x74), 1);
    return 0;
}
