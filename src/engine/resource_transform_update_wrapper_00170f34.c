#include <stdint.h>
extern void ResourceTransform_PrepareUpdate_0025F180(
    void *output_pair, void *state, float frame_step);
extern void ResourceTransform_Advance_0025EED0(void *state, float frame_step);
__attribute__((noinline)) int ResourceTransform_UpdateWrapper_00170F34(
    void *object, void *unused1, void *unused2, void *frame_context)
{
    uint8_t scratch[12];
    uint8_t *owner = *(uint8_t **)((uint8_t *)object + 0x114);
    uint8_t *state = *(uint8_t **)(owner + 0x20);
    (void)unused1;
    (void)unused2;
    ResourceTransform_PrepareUpdate_0025F180(
        scratch, state + 8, *(float *)((uint8_t *)frame_context + 0x0c));
    ResourceTransform_Advance_0025EED0(
        state + 8, *(float *)((uint8_t *)frame_context + 0x0c));
    return 0;
}
