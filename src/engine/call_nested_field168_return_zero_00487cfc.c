#include <stdint.h>
extern void Engine_ApplyNestedField_004ACC78(void *object, void *value);
__attribute__((noinline)) uint32_t Engine_CallNestedField168_ReturnZero_00487CFC(
    void *object)
{
    void *nested = *(void **)((uint8_t *)object + 0x30u);
    Engine_ApplyNestedField_004ACC78(object,
                                     *(void **)((uint8_t *)nested + 0x168u));
    return 0u;
}
