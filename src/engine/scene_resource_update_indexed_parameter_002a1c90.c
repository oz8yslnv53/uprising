#include <stdint.h>
extern float FUN_002E3C04(void *object);
void SceneResource_UpdateIndexedParameter_002A1C90(void *owner)
{
    uint8_t *object = (uint8_t *)owner;
    uint8_t bank = object[0x518];
    uint8_t *record = object + bank * 0x18C + 0x74;
    float value = FUN_002E3C04(object + 0x6278);
    *(float *)(record + 0x124) = value;
}
