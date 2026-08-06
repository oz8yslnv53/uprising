#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_PrepareActivation_0025EE70(void *entry);
extern void ResourceTree_ActivatePrepared_002A2D50(void *entry);
extern void MenuState_PrepareEntry_0024EE88(void *object);
extern void *ActorState_GetMenuState_002A62B0(void *machine);
extern uint32_t ParameterString_Hash_00448668(void *string_slot);
extern void Actor_PlayActionByHash_0036FCA8(
    uint32_t handle, int channel, const uint32_t *key,
    int arg3, int arg4);
extern void *MenuResource_FindNamedObject_00274FE8(
    void *resource, void *name);
extern void *StMenuBase_Factory_0022CC34(void);
extern void ActorStateMachine_RequestStateByFactory(void *machine,
                                                     void *factory_slot);
void Actor_EnterMenuStay_00216354(void *object) {
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *machine = *(uint8_t **)(bytes + 0x30);
    uint8_t *entry = (uint8_t *)ResourceTree_ResolveCurrentEntry_002A6268(
        machine);
    uint8_t *resource = *(uint8_t **)(entry + 0x20);
    uint8_t *state;
    uint32_t action_key[2];
    void *factory;
    void *menu_name = *(void **)0x00216410u;
    void *resource_name = *(void **)0x00216414u;
    ResourceTree_PrepareActivation_0025EE70(resource + 8);
    ResourceTree_ActivatePrepared_002A2D50(resource + 8);
    MenuState_PrepareEntry_0024EE88(object);
    state = (uint8_t *)ActorState_GetMenuState_002A62B0(machine);
    ParameterString_Hash_00448668(&menu_name);
    action_key[0] = *(uint32_t *)(state + 0x120);
    action_key[1] = *(uint32_t *)(state + 0x124);
    Actor_PlayActionByHash_0036FCA8(
        *(uint32_t *)(bytes + 0x170), 0x14, action_key, 1, 1);
    (void)MenuResource_FindNamedObject_00274FE8(
        *(void **)(bytes + 0x170), resource_name);
    factory = StMenuBase_Factory_0022CC34();
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    *(float *)(bytes + 0x2cc) = 0.0f;
    *(float *)(bytes + 0x2d0) = 25.0f;
    *(float *)(bytes + 0x2d4) = 0.0f;
}
int Menu_RequestStMenuBase_0017F788(
    void *context, void *unused1, void *unused2, void *unused3) {
    void *machine;
    void *factory;
    (void)unused1;
    (void)unused2;
    (void)unused3;
    machine = *(void **)((uint8_t *)context + 0x30);
    factory = StMenuBase_Factory_0022CC34();
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}
