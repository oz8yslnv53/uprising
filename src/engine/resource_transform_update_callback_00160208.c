#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTransform_PrepareUpdate_0025F180(
    void *output_pair, void *state, float frame_step);
extern void ResourceTransform_SyncLinkedPositions_002604C0(
    void *list_owner);
uint32_t FUN_00160208(void *object, uint32_t unused, void *frame_context) {
    void *entry;
    uint8_t *state;
    uint8_t scratch[12];
    float frame_step;
    (void)unused;
    entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30));
    state = *(uint8_t **)((uint8_t *)entry + 0x20);
    frame_step = *(float *)((uint8_t *)frame_context + 0x0c);
    ResourceTransform_PrepareUpdate_0025F180(scratch, state + 0x08,
                                               frame_step);
    ResourceTransform_SyncLinkedPositions_002604C0(state + 0x98);
    return 0u;
}
