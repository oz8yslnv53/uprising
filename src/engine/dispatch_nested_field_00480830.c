#include <stdint.h>
extern void FUN_004ACDA8(void *object, void *nested_value);
__attribute__((noinline)) int Engine_DispatchNestedField_00480830(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *nested = *(uint8_t **)(bytes + 0x30u);
    FUN_004ACDA8(object, *(void **)(nested + 0x168u));
    return 0;
}
__attribute__((noinline)) int Engine_DispatchNestedField_00487D1C(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *nested = *(uint8_t **)(bytes + 0x30u);
    FUN_004ACDA8(object, *(void **)(nested + 0x168u));
    return 0;
}
