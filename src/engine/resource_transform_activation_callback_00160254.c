#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTransform_PrepareUpdate_0025F180(
    void *output_pair, void *state, float frame_step);
extern void ResourceTransform_SyncLinkedPositions_002604C0(
    void *list_owner);
extern uint32_t MenuResourceList_HasNoConflictingState_00260620(
    void *list, void *excluded_resource);
extern void ResourceTree_PrepareActivation_0025EE70(void *entry);
extern void FUN_002A2D50(void *entry);
extern void *StMenuBase_Factory_0022CC34(void);
extern void *ActorStateMachine_RequestStateByFactory(
    void *machine, void *factory_slot);
uint32_t FUN_00160254(void *object, uint32_t unused, void *frame_context) {
    void *resolved_entry;
    uint8_t *state;
    uint8_t scratch[12];
    float frame_step;
    void *factory_slot;
    void *machine;
    (void)unused;
    resolved_entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)((uint8_t *)object + 0x30));
    state = *(uint8_t **)((uint8_t *)resolved_entry + 0x20);
    frame_step = *(float *)((uint8_t *)frame_context + 0x0c);
    ResourceTransform_PrepareUpdate_0025F180(scratch, state + 0x08,
                                               frame_step);
    ResourceTransform_SyncLinkedPositions_002604C0(state + 0x98);
    if (MenuResourceList_HasNoConflictingState_00260620(
            (uint8_t *)object + 0x34, *(void **)((uint8_t *)object + 0x30)) != 0u) {
        state = *(uint8_t **)((uint8_t *)resolved_entry + 0x20);
        ResourceTree_PrepareActivation_0025EE70(state + 0x08);
        FUN_002A2D50(state + 0x08);
        machine = *(void **)((uint8_t *)object + 0x30);
        factory_slot = StMenuBase_Factory_0022CC34();
        ActorStateMachine_RequestStateByFactory(machine, &factory_slot);
    }
    return 0u;
}
