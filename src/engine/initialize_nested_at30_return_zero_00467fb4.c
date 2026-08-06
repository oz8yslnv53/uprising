#include <stdint.h>
extern void Engine_InitializeNested_004C1110(void *nested, uint32_t mode);
__attribute__((noinline)) uint32_t Engine_InitializeNestedAt30_ReturnZero_00467FB4(
    void *object)
{
    Engine_InitializeNested_004C1110(*(void **)((uint8_t *)object + 0x30u), 0u);
    return 0u;
}
