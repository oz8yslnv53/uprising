#include <stdint.h>
extern void Engine_ApplyField_004ACFB8(void *object, uint32_t value);
__attribute__((noinline)) int Engine_ApplyNestedField168_00480864(void *object)
{
    uint8_t *nested = *(uint8_t **)((uint8_t *)object + 0x30u);
    Engine_ApplyField_004ACFB8(object,
                               *(uint32_t *)(nested + 0x168u));
    return 0;
}
