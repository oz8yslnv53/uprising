#include <stdint.h>
extern void ResourceTransform_PrepareUpdate_0025F180(
    void *output, void *state, float frame_step);
extern void ResourceTransform_Advance_0025EED0(void *state, float frame_step);
int FUN_00171068(void *object, void *unused2, void *unused3,
                 void *step_record)
{
    uint32_t output[3];
    void *owner = *(void **)((uint8_t *)object + 0x114);
    void *transform = *(void **)((uint8_t *)owner + 0x20);
    (void)unused2;
    (void)unused3;
    ResourceTransform_PrepareUpdate_0025F180(output,
                                    (uint8_t *)transform + 0x08,
                                    *(float *)((uint8_t *)step_record + 0x0c));
    ResourceTransform_Advance_0025EED0(
        (uint8_t *)transform + 0x08,
        *(float *)((uint8_t *)step_record + 0x0c));
    return 0;
}
