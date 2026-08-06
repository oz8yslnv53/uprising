#include <stdint.h>
extern void *Engine_ItemHandlerOwnerGet_00B60214(void);
__attribute__((noinline)) float Engine_SingletonFloatField314_00834840(void)
{
    uint8_t *object = (uint8_t *)Engine_ItemHandlerOwnerGet_00B60214();
    return *(float *)(object + 0x314u);
}
__attribute__((noinline)) float Engine_SingletonSignedField324ToFloat_00834850(
    void)
{
    uint8_t *object = (uint8_t *)Engine_ItemHandlerOwnerGet_00B60214();
    return (float)*(int32_t *)(object + 0x324u);
}
