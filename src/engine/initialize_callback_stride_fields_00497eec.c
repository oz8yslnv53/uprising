#include <stdint.h>
void *Engine_ForEachStrideCallback_00421EA4(void *base, void *callback,
                                            unsigned int stride,
                                            unsigned int count);
void *Engine_IndexedStride44Address_004C381C(const uint8_t *object,
                                             unsigned int index);
__attribute__((noinline)) void Engine_InitializeCallbackStrideFields_00497EEC(
    void *object)
{
    void *result = Engine_ForEachStrideCallback_00421EA4(
        object, (void *)Engine_IndexedStride44Address_004C381C, 4, 0x10);
    *(uint32_t *)((uint8_t *)result + 0x40) = 0;
    *(uint32_t *)((uint8_t *)result + 0x44) = 0;
}
