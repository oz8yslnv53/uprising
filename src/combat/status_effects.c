#include <stddef.h>
#include <stdint.h>
#include "actor_combat_views.h"
#include "engine_common_views.h"
extern void *GetEngineSingleton_003B6CF0(void);
extern uint32_t ResourceTableLookup(uint32_t *handle);
extern int Status_ResetModeGate(void *status);
extern int Status_AccumulateChannelValue(void *status, float hidden_value);
extern void *EngineLazySingleton00422CC8(void);
extern void *ResolveRelatedComponent(void *object);
extern void *ResolveCachedComponent_1EC(void *object);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *GetStatusEffectParameterSingleton(void);
extern void *StatusLazySingleton0054EFA8(void);
extern void *GetSharedRegistrySingleton(void);
extern void *StatusModeResourceLookup_00496EBC(void *component);
extern void *StatusModeRecordLookup_0054E208(void *component);
extern void StatusOwnerEventDispatch(void *component, unsigned mode,
                                      unsigned requested_state);
extern void StatusModeFinalize_00574BC8(void *component);
extern void StatusComponentReset_004C1110(void *component, unsigned mode);
extern void StatusChannelPrepareAuxiliary(void *target, unsigned mode);
extern void Health_StatusBitUpdate(void *health, uint32_t mask, int enabled);
extern void *OrderedTree_LowerBoundStatusHandle(void *tree, uint32_t key);
__attribute__((noinline)) int StatusContext_SetFlags(void *context, uint32_t key, uint32_t mask)
{
    uint8_t *bytes = (uint8_t *)context;
    uint8_t *node = (uint8_t *)OrderedTree_LowerBoundStatusHandle(
        bytes + 0x08u, key);
    uint8_t *record = node != 0 ? *(uint8_t **)node : 0;
    uint8_t *sentinel = *(uint8_t **)(bytes + 0x0cu);
    if (record == 0 || record == sentinel)
        return 0;
    *(uint32_t *)(record + 0x20u) |= mask;
    return 1;
}
extern void StatusLink_RefreshOrClear(void *target);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *OrderedTreeLowerBoundStatusHandle(void *tree,
                                                   uint32_t key);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *ResolveRelatedComponent(void *object);
extern void *ResolveStatusEffectComponent(void *object);
extern uint32_t ResourceTableLookup(uint32_t *handle);
extern void *GetEngineSingleton_003B6CF0(void);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern void *GetStatusLinkDescriptor(void);
extern void *GetComponentStatusDescriptor(void);
extern void *FindStatusDescriptorNode(void *object);
extern void *FindRiderDescriptorNode(void *object);
extern int StatusObjectMatchesEngineClass(void *object);
extern void StatusEffectRefreshPendingValue(void *effect);
extern void StatusEffectReleaseIfPresent(void *object);
extern void StatusLinkFinalizeLinkedResource(void *object);
extern void ComponentNotifyStatusChange(void *component, unsigned mode,
                                            unsigned requested_state);
__attribute__((noinline)) void StatusEffect_SetAuxiliaryMode(void *object, int mode)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *component = *(uint8_t **)(bytes + 0x30u);
    uint8_t *mode_byte = bytes + 0x107u;
    void *mode_record;
    void *mode_resource;
    uint8_t *component_descriptor;
    uint32_t *component_flags;
    void *related;
    if (*(int8_t *)mode_byte != mode && *(int8_t *)mode_byte == 0) {
        mode_resource = StatusModeResourceLookup_00496EBC(component);
        *(uint32_t *)(bytes + 0xf0u) =
            *(uint32_t *)((uint8_t *)mode_resource + 0x10u);
        *(uint32_t *)(bytes + 0xf4u) =
            *(uint32_t *)((uint8_t *)mode_resource + 0x14u);
        *(uint32_t *)(bytes + 0xf8u) =
            *(uint32_t *)((uint8_t *)mode_resource + 0x18u);
    }
    mode_record = StatusModeRecordLookup_0054E208(component);
    *(int8_t *)mode_byte = (int8_t)mode;
    component_descriptor = *(uint8_t **)(bytes + 0x38u);
    component_flags = (uint32_t *)(component_descriptor + 0x94u);
    if ((*(uint32_t *)(component_descriptor + 0x98u) & 0x100u) == 0) {
        if (mode != 0)
            *component_flags |= 0x04000000u;
        else
            *component_flags &= ~0x04000000u;
    }
    if (*(int8_t *)mode_byte != 0) {
        StatusChannelPrepareAuxiliary(component, 1u);
        StatusOwnerEventDispatch(component, 0u, 1u);
        ComponentNotifyStatusChange(*(void **)((uint8_t *)mode_record + 0x20u),
                                    0u, 0u);
        related = ResolveRelatedComponent(component);
        if (related != 0)
            Health_StatusBitUpdate(related, 0x00100000u, 1);
        *(float *)(bytes + 0xe4u) = 30.0f;
    } else {
        related = ResolveRelatedComponent(component);
        if (related != 0)
            Health_StatusBitUpdate(related, 0x00100000u, 0);
        StatusChannelPrepareAuxiliary(component, 0u);
        StatusOwnerEventDispatch(component, 1u, 1u);
        ComponentNotifyStatusChange(*(void **)((uint8_t *)mode_record + 0x20u),
                                    0u, 1u);
        StatusComponentReset_004C1110(component, 0u);
        StatusModeFinalize_00574BC8(component);
        *(float *)(bytes + 0xe4u) = 0.0f;
    }
}
extern void *ResolveCachedComponentAt1EC(void *object);
extern int ActorSpecialEligibilityPredicate(void *object);
extern void *StatusResetStateDescriptor(void);
extern void *ActorStateMachineRequestStateByFactory(void *machine,
                                                        void *descriptor);
extern void *StatusEffectNodeLookup(void *object);
extern void ActorApplyStatusState(void *effect, void *state_payload,
                                     void *argument, void *descriptor);
extern void StatusLink_RefreshOrClear(void *target);
extern void StatusEffectRelease(void *effect, unsigned mode);
extern void StatusLinkSharedTail(void *component, void *target);
extern void DamageEffect_ApplyAndQueue(void *owner, void *target,
                                         void *component, void *config,
                                         uint32_t param4, uint32_t param5,
                                         float damage_amount,
                                         float unused_hidden);
extern void StatusConfigFinalize(void *registry, void *record);
extern void *GetStatusConfigRegistry(void);
extern void StatusChannelClearRequested(void *status,
                                            StatusChannel channel);
extern void StatusOwner_TightenThreshold(void *owner, uint32_t key,
                                            float threshold);
extern void HealthSecondaryReset(void *secondary, void *target);
struct StatusEffectEventRecord {
    uint32_t zero_00;         
    uint32_t zero_04;         
    uint16_t zero_08;         
    uint16_t _padding_0a;
    float one_0c;              
    uint32_t zero_10;          
    float zero_14;              
    float one_18;               
    uint32_t payload_1c;        
    uint32_t payload_20;        
    uint32_t payload_24;        
};
extern void *CreateStatusEffectDispatcher(void);
extern uint32_t StatusEffectEventDispatch(void *dispatcher,
                                              uint32_t event_id,
                                              int effect_type,
                                              const void *record,
                                              unsigned flags);
extern void *GetStatusEffectDispatchSingleton(void);
extern void *GetStatusEffectReleaseShared(void);
extern void StatusEffectEventSubmit(void *dispatcher, uint32_t event_id,
                                       uint32_t event_type,
                                       const void *record);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern void *ResolveRelatedComponent(void *object);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *GetAlternateVariantKey(void);
extern void *GetStatusVariantKey(void);
extern void *GetStatusScaleAdjustmentSingleton(void);
extern int32_t StatusScaleAdjustmentReadA(void *adjustment);
extern int32_t StatusScaleAdjustmentReadB(void *adjustment);
extern void StatusScaleAdjustAndStore(void *parameters, int32_t value);
struct StatusScaleObjectView {
    uint8_t opaque_000[0x1fcu];
    uint8_t mode6_code;
    uint8_t opaque_1fd[3];
    uint32_t code_a;
    uint32_t code_b;
    uint32_t code_c;
    uint8_t opaque_20c[0x310];
    float base_51c;
    float multiplier_520;
};
struct StatusScaleParametersView {
    uint8_t opaque_000[0x1eefcu];
    float minimum_base;
    float base_rate;
    float adjustment_rate_a;
    float adjustment_rate_b;
    float mode6_add;
    float code_a_add;
    float code_b_add;
    float code_c_add;
};
typedef char kiu_sa_status_effects_1[(offsetof(struct StatusScaleObjectView, base_51c) == 0x51c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_effects_2[(offsetof(struct StatusScaleParametersView, minimum_base) == 0x1eefc) ? 1 : -1] __attribute__((unused));
extern void StatusAuxiliaryRecordReset(void *record);
extern void StatusEffectDispatchMatchingHandle(void *dispatcher, void *target,
                                             uint32_t argument);
extern void StatusDispatchEvent(void *dispatcher, void *event,
                                   uint32_t argument);
extern void *ResolveStatusEffectComponent(void *object);
extern uint32_t ResourceTableLookup(uint32_t *handle);
float StatusEffectNegativeValueResolve(float value);
extern void *GetStatusEffectDescriptorKey(void);
extern void *StatusEffectOwnerLookup(void *target);
extern void StatusEffectOwnerFlagsUpdate(void *owner, unsigned mode,
                                            unsigned notification);
extern void *StatusEffectComponentLookup(void *target);
extern void *GetStatusEffectRefreshKey(void);
void StatusEffectNegativeTransition(void *object);
void StatusEffectDescriptorRefresh(void *object);
int StatusEffectUpdate(void *object, unsigned mode,
                          float input, float auxiliary, float previous);
void EffectQueueAppend(struct EffectQueueVariant *queue,
                           uint32_t first_value,
                           uint32_t second_value,
                           uint32_t flags,
                           float duration);
void EffectQueueReset(struct EffectQueueView *queue, unsigned variant);
extern void *GetComponentStatusDescriptor(void);
extern void ComponentNotifyStatusChange(void *component, unsigned mode,
                                            unsigned requested_state);
struct StatusDispatchLink {
    void *event;
    struct StatusDispatchLink *next;
};
extern void EffectEventDispatchTimed(void *object, float value);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
uint32_t StatusContextGetFlags(void *status_context, uint32_t key);
void *StatusOwnerIndexAddress(void *base, int8_t index);
int Status_ResetModeGate(void *ignored_status);
int Status_AccumulateChannelValue(void *status, float hidden_value);
int StatusComponentHasBit00800000(void *object);
uint8_t StatusOwnerTableByte(void *registry, unsigned index);
int StatusOwnerTableSignedCode(void *registry, unsigned index);
unsigned CachedComponent_FlagsContain(void *object, uint32_t mask);
void StatusEffectResetActorState(void *effect, unsigned reset_mode,
                                    void *argument, void *descriptor);
uint32_t StatusEffectCreateOrRelease(void *context, int effect_type,
                                         unsigned create);
void StatusEffectSubmitEvent(void *context, uint32_t event_type,
                                const uint32_t payload[3], int create);
void StatusEffectReleaseSelected(void *target, int selector);
void StatusLink_RefreshOrClear(void *target);
void StatusLinkFinalizeLinkedResource(void *object);
void StatusEffectRefreshPendingValue(void *effect);
void StatusEffectReleaseIfPresent(void *object);
int StatusDescriptorClassNibble(void *descriptor);
void StatusConfigClearSelectedChannels(void *registry, void *target,
                                          uint8_t *config, uint32_t param4,
                                          uint32_t param5,
                                          float damage_amount);
void HealthOwnerStateUpdate(void *object, unsigned slot, unsigned active,
                               float value);
uint8_t *StatusVariantResolveCached(void *target);
int StatusVariantMode(void);
unsigned EngineStatusModeByte(void);
void StatusEffectComputeGlobalScale(void *object);
void *StatusEffectSelectVariant(void *target, unsigned mode,
                                    unsigned selector);
void StatusEffectDispatchToTarget(void *context, void *target);
void StatusOwnerStatePublish(void *object, uint32_t active_mask);
void StatusPublishActivation(void *registry, void *target,
                                uint32_t active_mask, float hidden_value);
void HealthSecondaryReset(void *secondary, void *target);
void BuildStatusRandomizedEffectParams(void *prng, const void *config,
                                          struct StatusRandomizedEffectParams *out);
void StatusEffectStoreRandomizedParams(void *object,
                                           const struct StatusRandomizedEffectParams *params);
void StatusEffectStoreAuxiliaryParams(void *target, const void *record);
int StatusAlternateUpdateTimer(void *status, unsigned channel, float requested,
                                  const void *config);
void StatusAlternateCommit(void *status, unsigned channel);
void StatusEffectDispatchMatchingHandle(void *dispatcher, void *target,
                                     uint32_t argument);
int StatusEffectRefreshMode0(void *object, float value, float previous_value);
int StatusEffectUpdateMode0Selected(void *object, void *selected_entry,
                                       float value, float previous_value);
void StatusChannelClearRequested(void *actor, StatusChannel channel);
void StatusOwner_TightenThreshold(void *owner, uint32_t key, float threshold);
void EffectQueueAppend(struct EffectQueueVariant *queue,
                           uint32_t first_value,
                           uint32_t second_value,
                           uint32_t flags,
                           float duration);
void EffectQueueReset(struct EffectQueueView *queue, unsigned variant);
void StatusEffectQueueSeedIfUninitialized(void *object,
                                             uint32_t second_duration,
                                             uint32_t flags,
                                             void *callback,
                                             float duration,
                                             float callback_value);
int StatusTargetPassesSpecialFilter(int matches_excluded_global,
                                       int has_component,
                                       uint32_t component_flags);
int StatusEffectUpdate(void *object, unsigned mode,
                          float input, float auxiliary, float previous);
float StatusEffectNegativeValueResolve(float value);
void StatusEffectNegativeTransition(void *object);
void StatusEffectDescriptorRefresh(void *object);
__attribute__((noinline)) uint32_t StatusContextGetFlags(void *status_context, uint32_t key)
{
    uint8_t *bytes = (uint8_t *)status_context;
    uint8_t *entry = (uint8_t *)OrderedTreeLowerBoundStatusHandle(
        bytes + 8u, key);
    uint8_t *selected = entry != 0 ? *(uint8_t **)entry : 0;
    uint8_t *sentinel = *(uint8_t **)(bytes + 0xcu);
    if (selected == sentinel || selected == 0)
        return 0;
    return *(uint32_t *)(selected + 0x20u);
}
__attribute__((noinline)) int Status_ResetModeGate(void *ignored_status)
{
    static void **parameter_slot = (void **)(uintptr_t)0x00d6364cu;
    uint8_t *parameters = (uint8_t *)*parameter_slot;
    int8_t mode;
    (void)ignored_status;
    if (parameters == 0) {
        parameters = (uint8_t *)EngineLazySingleton00422CC8();
        *parameter_slot = parameters;
    }
    if (parameters[0x1efdu] != 0)
        return 0;
    mode = *(int8_t *)(parameters + 0x2fcu);
    switch (mode) {
    case 0x10:
        return *(int16_t *)parameters != 0x325;
    case 0x14:
        return *(int32_t *)(parameters + 0x1f04u) != 1;
    case 0x13:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x45:
        return 0;
    default:
        return 1;
    }
}
__attribute__((noinline)) int Status_AccumulateChannelValue(void *status, float hidden_value)
{
    static void **parameter_slot = (void **)(uintptr_t)0x00d6364cu;
    uint8_t *parameters = (uint8_t *)*parameter_slot;
    float old_value;
    float new_value;
    if (parameters == 0) {
        parameters = (uint8_t *)EngineLazySingleton00422CC8();
        *parameter_slot = parameters;
    }
    if ((*(uint32_t *)(parameters + 0x1f18u) & 0x10u) != 0)
        return 0;
    old_value = *(float *)((uint8_t *)status + 0x1238u);
    new_value = old_value + hidden_value;
    if (new_value < 0.0f)
        new_value = 0.0f;
    if (new_value > 2.0f)
        new_value = 2.0f;
    *(float *)((uint8_t *)status + 0x1238u) = new_value;
    return (int)new_value != (int)old_value;
}
__attribute__((noinline)) int StatusComponentHasBit00800000(void *object)
{
    uint8_t *component = (uint8_t *)ResolveRelatedComponent(object);
    return component != 0 &&
           ((*(uint32_t *)(component + 0x174u) & 0x00800000u) != 0);
}
__attribute__((noinline)) unsigned CachedComponent_FlagsContain(void *object, uint32_t mask)
{
    uint8_t *component = (uint8_t *)ResolveCachedComponentAt1EC(object);
    return (*(uint32_t *)(component + 0x94) & mask) != 0u;
}
__attribute__((noinline)) void StatusEffectResetActorState(void *effect, unsigned reset_mode,
                                    void *argument, void *descriptor)
{
    uint8_t *bytes = (uint8_t *)effect;
    void *object = *(void **)(bytes + 0x30);
    void *selected_descriptor = descriptor;
    if (ActorSpecialEligibilityPredicate(object) == 0)
        return;
    if (reset_mode == 0u) {
        selected_descriptor = StatusResetStateDescriptor();
        ActorStateMachineRequestStateByFactory(object,
                                                   &selected_descriptor);
    }
    *(uint32_t *)(bytes + 0x34) = 0xfffffe00u;
    (*(uint8_t **)(bytes + 0x3c))[0x20] = 0;
    {
        uint8_t *node = (uint8_t *)StatusEffectNodeLookup(object);
        if (node != 0)
            node[0x21] = 1;
    }
    ActorApplyStatusState(effect, bytes + 0x64, argument,
                             selected_descriptor);
}
static void StatusEffectBuildEventRecord(
    struct StatusEffectEventRecord *record)
{
    record->zero_00 = 0;
    record->zero_04 = 0;
    record->zero_08 = 0;
    record->_padding_0a = 0;
    record->one_0c = 1.0f;
    record->zero_10 = 0;
    record->zero_14 = 0.0f;
    record->one_18 = 1.0f;
}
__attribute__((noinline)) uint32_t StatusEffectCreateOrRelease(void *context, int effect_type,
                                         unsigned create)
{
    struct StatusEffectEventRecord record;
    uint8_t *shared;
    uint8_t *counter;
    uint8_t *event_id;
    void **dispatcher_slot;
    void *dispatcher;
    uint32_t id;
    (void)context;
    StatusEffectBuildEventRecord(&record);
    if (create != 0) {
        counter = (uint8_t *)(uintptr_t)0x00d4e2f8u;
        event_id = (uint8_t *)(uintptr_t)0x00d5ee4au;
        dispatcher_slot = (void **)(uintptr_t)0x00d63854u;
        dispatcher = *dispatcher_slot;
        if (dispatcher == 0) {
            dispatcher = CreateStatusEffectDispatcher();
            *dispatcher_slot = dispatcher;
        }
        if (*event_id == 0)
            *event_id = (uint8_t)(*counter + 1u);
        id = ((uint32_t)*event_id << 16) | 2u;
        return StatusEffectEventDispatch(dispatcher, id, effect_type,
                                            &record, 0);
    }
    shared = (uint8_t *)GetEngineSingleton_003B6CF0();
    counter = (uint8_t *)(uintptr_t)0x00d4e2f8u;
    event_id = (uint8_t *)(uintptr_t)0x00d5ee49u;
    dispatcher_slot = (void **)(uintptr_t)0x00d6364cu;
    dispatcher = *dispatcher_slot;
    if (dispatcher == 0) {
        dispatcher = GetEngineSingleton_003B6CF0();
        *dispatcher_slot = dispatcher;
    }
    if (*event_id == 0)
        *event_id = (uint8_t)(*counter + 1u);
    id = ((uint32_t)*event_id << 16) |
         (uint32_t)(int8_t)*(int8_t *)(shared + 0x1efc);
    return StatusEffectEventDispatch(dispatcher, id, effect_type,
                                        &record, 0);
}
__attribute__((noinline)) void StatusEffectSubmitEvent(void *context, uint32_t event_type,
                                const uint32_t payload[3], int create)
{
    struct StatusEffectEventRecord record;
    uint8_t *counter = (uint8_t *)(uintptr_t)0x00d4e2f8u;
    uint8_t *event_id;
    void *dispatcher;
    uint32_t id;
    (void)context;
    StatusEffectBuildEventRecord(&record);
    record.payload_1c = payload[0];
    record.payload_20 = payload[1];
    record.payload_24 = payload[2];
    if (create != 0) {
        event_id = (uint8_t *)(uintptr_t)0x00d5ee4au;
        dispatcher = GetStatusEffectDispatchSingleton();
        if (*event_id == 0)
            *event_id = (uint8_t)(*counter + 1u);
        id = ((uint32_t)*event_id << 16) | 2u;
    } else {
        int32_t effect_type;
        event_id = (uint8_t *)(uintptr_t)0x00d5ee49u;
        effect_type = *(int8_t *)((uint8_t *)GetStatusEffectReleaseShared() +
                                  0x1efc);
        dispatcher = GetStatusEffectDispatchSingleton();
        if (*event_id == 0)
            *event_id = (uint8_t)(*counter + 1u);
        id = ((uint32_t)*event_id << 16) + (uint32_t)effect_type;
    }
    StatusEffectEventSubmit(dispatcher, id, event_type, &record);
}
__attribute__((noinline)) void StatusEffectReleaseSelected(void *target, int selector)
{
    uint8_t *bytes = (uint8_t *)target;
    uint8_t *parameters;
    int effect_type;
    if (bytes[0x123d] == 0)
        return;
    parameters = (uint8_t *)GetStatusEffectParameterSingleton();
    effect_type = *(int *)(parameters + 0x48a4 + selector * 4);
    (void)StatusEffectCreateOrRelease(target, effect_type, 0);
}
__attribute__((noinline)) void StatusLink_RefreshOrClear(void *target)
{
    struct ActorObjectView *object =
        (struct ActorObjectView *)target;
    static void **const engine_slot = (void **)(uintptr_t)0x00d63578u;
    uint8_t *engine = (uint8_t *)*engine_slot;
    if (engine == 0) {
        engine = (uint8_t *)StatusLazySingleton0054EFA8();
        *engine_slot = engine;
    }
    uint8_t *self_target = (uint8_t *)(uintptr_t)ResourceTableLookup(
        (uint32_t *)(engine + 0xb278));
    uint8_t *entry = OrderedTreeLowerBoundByPointer(
        &object->component_tree_anchor, GetStatusLinkDescriptor());
    uint8_t *selected = entry != 0 ? *(uint8_t **)entry : 0;
    uint8_t *cached = (uint8_t *)object->component_tree_upper;
    uint8_t *linked = selected != cached ? selected : 0;
    if (self_target == target) {
        linked = (uint8_t *)object->cached_component_descriptor;
        if (linked == 0) {
            entry = OrderedTreeLowerBoundByPointer(
                &object->component_tree_anchor,
                GetComponentStatusDescriptor());
            selected = entry != 0 ? *(uint8_t **)entry : 0;
            cached = (uint8_t *)object->component_tree_upper;
            if (selected != cached && selected != 0) {
                linked = *(uint8_t **)selected;
                if (linked != 0) {
                    *(void **)(linked + 0x1c) = target;
                    object->cached_component_descriptor = linked;
                }
            }
        }
        if (linked != 0)
            ComponentNotifyStatusChange(*(void **)(linked + 0x20), 1, 0);
        linked = (uint8_t *)FindStatusDescriptorNode(target);
        if (linked != 0) {
            StatusEffectRefreshPendingValue(linked);
            *(uint32_t *)(linked + 0xcc) = *(uint32_t *)(linked + 0xd0);
            if (StatusObjectMatchesEngineClass(target)) {
                uint8_t *rider = (uint8_t *)FindRiderDescriptorNode(target);
                if (rider != 0)
                    StatusEffectReleaseIfPresent(rider);
            }
        }
        return;
    }
    if (linked == 0) {
        linked = (uint8_t *)ResolveCachedComponent_1EC(target);
        if (linked == 0 || (*(uint32_t *)(linked + 0x94) & 0x100u) != 0)
            return;
        StatusLinkSharedTail(engine, target);
        return;
    }
    uint8_t *resource = (uint8_t *)(uintptr_t)ResourceTableLookup(
        (uint32_t *)(linked + 0x54));
    if (resource != 0) {
        uint8_t *resource_link = *(uint8_t **)(resource + 0x1f0);
        if (resource_link == 0) {
            entry = OrderedTreeLowerBoundByPointer(
                resource + 0x1a4, GetComponentStatusDescriptor());
            selected = entry != 0 ? *(uint8_t **)entry : 0;
            cached = *(uint8_t **)(resource + 0x1a8);
            if (selected != cached && selected != 0) {
                resource_link = *(uint8_t **)selected;
                if (resource_link != 0) {
                    *(void **)(resource_link + 0x1c) = resource;
                    *(uint8_t **)(resource + 0x1f0) = resource_link;
                }
            }
        }
        if (resource_link != 0)
            ComponentNotifyStatusChange(
                *(void **)(resource_link + 0x20), 1, 0);
        selected = (uint8_t *)FindStatusDescriptorNode(resource);
        if (selected != 0) {
            StatusEffectRefreshPendingValue(selected);
            *(uint32_t *)(selected + 0xcc) = *(uint32_t *)(selected + 0xd0);
            if (StatusObjectMatchesEngineClass(resource)) {
                uint8_t *rider = (uint8_t *)FindRiderDescriptorNode(resource);
                if (rider != 0)
                    StatusEffectReleaseIfPresent(rider);
            }
        }
    }
    StatusLinkFinalizeLinkedResource(*(void **)(linked + 0x58));
}
__attribute__((noinline)) void StatusLinkFinalizeLinkedResource(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    uint32_t flags = *(uint32_t *)(bytes + 0x160);
    if ((flags & 8u) != 0)
        return;
    *(uint32_t *)(bytes + 0x160) = (flags & ~3u) | 8u;
    void **vtable = *(void ***)object;
    ((void (*)(void *))vtable[0x18u / sizeof(void *)])(object);
    *(float *)(bytes + 0x164) = 0.0f;
}
__attribute__((noinline)) void StatusEffectRefreshPendingValue(void *effect)
{
    uint8_t *bytes = (uint8_t *)effect;
    uint8_t *owner = *(uint8_t **)(bytes + 0x38);
    if (*(float *)(bytes + 0xb8) <= 0.0f && owner != 0 &&
        (*(uint32_t *)(owner + 0x94) & 0x10000000u) == 0) {
        float *pair = *(float **)(0x00d46704u);
        *(float *)(bytes + 0xb8) = pair[0] + pair[1];
    }
}
__attribute__((noinline)) void StatusEffectReleaseIfPresent(void *object)
{
    void *effect = (void *)(uintptr_t)ResourceTableLookup(
        (uint32_t *)((uint8_t *)object + 0x34));
    if (effect != 0)
        StatusEffectRelease(effect, 0);
}
__attribute__((noinline)) void StatusConfigClearSelectedChannels(void *registry, void *target,
                                          uint8_t *config, uint32_t param4,
                                          uint32_t param5,
                                          float damage_amount)
{
    uint8_t *resolved;
    uint8_t *component;
    uint8_t *owner;
    uint32_t clear_mask;
    if (StatusDescriptorClassNibble(target) != 1)
        return;
    resolved = (uint8_t *)ResolveStatusDescriptor(target);
    if (resolved == 0 || (*(uint32_t *)(resolved + 0x20) >> 28) != 1u)
        return;
    owner = (uint8_t *)StatusOwnerIndexAddress(
        (uint8_t *)registry + 0xb3f8, (int8_t)*(uint8_t *)(resolved + 0x2c));
    component = (uint8_t *)ResolveRelatedComponent(target);
    clear_mask = *(uint32_t *)(config + 0x58);
    if ((clear_mask & 1u) != 0) {
        void *secondary = *(void **)(component + 0x170);
        if (secondary != 0 && *(uint8_t *)secondary != 0)
            HealthSecondaryReset(secondary, target);
    }
    DamageEffect_ApplyAndQueue(owner, target, component, config,
                               param4, param5, damage_amount, 0.0f);
    if ((clear_mask & 0x2u) != 0) StatusChannelClearRequested(component, 7);
    if ((clear_mask & 0x4u) != 0) StatusChannelClearRequested(component, 11);
    if ((clear_mask & 0x8u) != 0) StatusChannelClearRequested(component, 10);
    if ((clear_mask & 0x10u) != 0) StatusChannelClearRequested(component, 5);
    if ((clear_mask & 0x20u) != 0) StatusChannelClearRequested(component, 9);
    if ((clear_mask & 0x40u) != 0) StatusChannelClearRequested(component, 4);
    if ((clear_mask & 0x80u) != 0) StatusChannelClearRequested(component, 8);
    if ((clear_mask & 0x100u) != 0) StatusChannelClearRequested(component, 6);
    if ((clear_mask & 0x200u) != 0) StatusChannelClearRequested(component, 3);
    if ((param4 != 1u || (*(uint32_t *)(component + 0x1dc) & 6u) == 0) &&
        (clear_mask & 0x400u) != 0)
        StatusChannelClearRequested(component, 2);
    if ((param4 != 1u || (*(uint32_t *)(component + 0x1dc) & 6u) == 0) &&
        (clear_mask & 0x800u) != 0)
        StatusChannelClearRequested(component, 1);
    if ((clear_mask & 0x1000u) != 0)
        StatusOwner_TightenThreshold(owner + 0x2d8, 0x01000000u, 0.0f);
    if ((clear_mask & 0x8000u) != 0)
        StatusOwner_TightenThreshold(owner + 0x2d8, 0x02000000u, 0.0f);
    if (*(uint8_t *)((uint8_t *)registry + STATUS_SELECTOR_A) != 0 &&
        *(uint8_t *)((uint8_t *)registry + STATUS_SELECTOR_B) != 0 &&
        *(uint32_t *)(config + 0x50) == 1u) {
        uint32_t record[4] = {
            8u, *(uint32_t *)(resolved + 0x20),
            *(uint32_t *)(config + 0x5c), 2u
        };
        StatusConfigFinalize(GetStatusConfigRegistry(), record);
    }
}
__attribute__((noinline)) uint8_t *StatusVariantResolveCached(void *target)
{
    uint8_t *bytes = (uint8_t *)target;
    uint8_t *entry = OrderedTreeLowerBoundByPointer(
        bytes + 0x1a4, GetStatusVariantKey());
    uint8_t *selected = entry != 0 ? *(uint8_t **)entry : 0;
    uint8_t *upper = *(uint8_t **)(bytes + 0x1a8);
    if (selected == upper)
        return 0;
    return selected;
}
__attribute__((noinline)) int StatusVariantMode(void)
{
    return (int)*(int8_t *)((uint8_t *)GetEngineSingleton_003B6CF0() + 0x1efd);
}
__attribute__((noinline)) unsigned EngineStatusModeByte(void)
{
    return ((uint8_t *)GetEngineSingleton_003B6CF0())[0x1f14];
}
__attribute__((noinline)) void StatusEffectComputeGlobalScale(void *object)
{
    static void **adjustment_slot = (void **)(uintptr_t)0x00d63558u;
    static void **parameters_slot = (void **)(uintptr_t)0x00d63578u;
    static void **shared_slot = (void **)(uintptr_t)0x00d6364cu;
    struct StatusScaleObjectView *record =
        (struct StatusScaleObjectView *)object;
    uint8_t *parameters = (uint8_t *)*parameters_slot;
    uint8_t *adjustment = (uint8_t *)*adjustment_slot;
    struct StatusScaleParametersView *parameter_view;
    float base;
    float value;
    int32_t truncated;
    if (adjustment == 0) {
        adjustment = (uint8_t *)GetStatusScaleAdjustmentSingleton();
        *adjustment_slot = adjustment;
    }
    if (parameters == 0) {
        parameters = (uint8_t *)StatusLazySingleton0054EFA8();
        *parameters_slot = parameters;
    }
    parameter_view = (struct StatusScaleParametersView *)parameters;
    base = record->base_51c;
    if (parameter_view->minimum_base > base)
        base = parameter_view->minimum_base;
    value = record->multiplier_520 * parameter_view->base_rate * base;
    value += (float)StatusScaleAdjustmentReadA(adjustment) *
             parameter_view->adjustment_rate_a;
    value += (float)StatusScaleAdjustmentReadB(adjustment) *
             parameter_view->adjustment_rate_b;
    if (EngineStatusModeByte() == 6u) {
        if (record->mode6_code != 0u &&
            StatusOwnerTableSignedCode(parameters, 0) ==
                record->mode6_code)
            value += parameter_view->mode6_add;
    } else {
        uint8_t code = StatusOwnerTableByte(parameters, 0);
        if (record->code_a == code)
            value += parameter_view->code_a_add;
        else if (record->code_b == code)
            value += parameter_view->code_b_add;
        else if (record->code_c == code)
            value += parameter_view->code_c_add;
    }
    truncated = (int32_t)value;
    StatusScaleAdjustAndStore(parameters, truncated);
    {
        uint8_t *shared = (uint8_t *)*shared_slot;
        if (shared == 0) {
            shared = (uint8_t *)EngineLazySingleton00422CC8();
            *shared_slot = shared;
        }
        *(int32_t *)(shared + 0x4020u) = truncated;
    }
}
__attribute__((noinline)) void *StatusVariantRecordMutate_00584658(
    uint8_t *record, unsigned selector)
{
    uint8_t *linked = *(uint8_t **)record;
    uint32_t mode_bits;
    if (linked != 0 && linked[0x68] != 0)
        return 0;
    if (linked != 0) {
        linked[0x68] = 0;
        linked[0x69] = 0;
        *(float *)(linked + 0x6c) = 0.0f;
        *(float *)(linked + 0x70) = 0.0f;
    }
    *(float *)(record + 0x04) = 0.0f;
    *(float *)(record + 0x08) = 0.0f;
    *(float *)(record + 0x0c) = 0.0f;
    *(float *)(record + 0x10) = 0.0f;
    mode_bits = *(uint32_t *)(record + 0x14);
    *(uint32_t *)(record + 0x14) = (mode_bits & ~7u) | 5u;
    record[0x14] = (uint8_t)(record[0x14] & (uint8_t)~0x38u);
    linked = *(uint8_t **)record;
    linked[0x68] = 1;
    record[0x14] = (uint8_t)((record[0x14] & (uint8_t)~0x10u) |
                             ((selector & 0xffu) << 4));
    return (void *)1;
}
__attribute__((noinline)) void *StatusVariantRecordClearLinked_00584644(
    uint8_t *record)
{
    uint8_t *linked = *(uint8_t **)record;
    if (linked != 0)
        linked[0x68] = 0;
    return linked;
}
__attribute__((noinline)) void *StatusVariantDispatchCached_0055E030(
    void *variant, unsigned mode, unsigned selector)
{
    uint8_t *record = (uint8_t *)variant + 0xc4u;
    if (mode != 0)
        return StatusVariantRecordMutate_00584658(record, selector);
    return StatusVariantRecordClearLinked_00584644(record);
}
__attribute__((noinline)) void *StatusVariantDispatchTree_00584628(
    void *variant, unsigned mode, unsigned selector)
{
    uint8_t *record = (uint8_t *)variant + 0xa4u;
    if (mode != 0)
        return StatusVariantRecordMutate_00584658(record, selector);
    return StatusVariantRecordClearLinked_00584644(record);
}
__attribute__((noinline)) void *StatusEffectSelectVariant(void *target, unsigned mode,
                                    unsigned selector)
{
    static void **const registry_slot = (void **)(uintptr_t)0x00d63578u;
    uint8_t *bytes = (uint8_t *)target;
    uint8_t *entry;
    uint8_t *variant;
    if (*registry_slot == 0)
        *registry_slot = StatusLazySingleton0054EFA8();
    if (StatusVariantMode() != 0) {
        variant = StatusVariantResolveCached(target);
        if (variant == 0)
            return 0;
        return StatusVariantDispatchCached_0055E030(variant, mode, selector);
    }
    entry = OrderedTreeLowerBoundByPointer(bytes + 0x1a4,
                                           GetAlternateVariantKey());
    if ((entry != 0 ? *(uint8_t **)entry : 0) ==
        *(uint8_t **)(bytes + 0x1a8))
        return 0;
    variant = entry != 0 ? *(uint8_t **)entry : 0;
    if (variant == 0)
        return 0;
    return StatusVariantDispatchTree_00584628(variant, mode, selector);
}
__attribute__((noinline)) void StatusEffectDispatchToTarget(void *context, void *target)
{
    static void **dispatcher_slot = (void **)(uintptr_t)0x00d6385cu;
    void *dispatcher = *dispatcher_slot;
    (void)context;
    if (dispatcher == 0) {
        dispatcher = GetEngineSingleton_003B6CF0();
        *dispatcher_slot = dispatcher;
    }
    StatusEffectDispatchMatchingHandle(dispatcher, target, 0);
}
__attribute__((noinline)) void StatusPublishActivation(void *registry, void *target,
                                uint32_t active_mask, float hidden_value)
{
    uint32_t selected = ResourceTableLookup(
        (uint32_t *)((uint8_t *)registry + 0xb278u));
    uint8_t *descriptor;
    void *shared = GetSharedRegistrySingleton();
    if (selected == (uint32_t)(uintptr_t)target)
        StatusOwnerStatePublish(shared, active_mask);
    descriptor = (uint8_t *)ResolveStatusDescriptor(target);
    (void)ResolveRelatedComponent(target);
    HealthOwnerStateUpdate(shared, *(uint8_t *)(descriptor + 0x2cu),
                              (active_mask & 0x800u) >> 11, hidden_value);
}
__attribute__((noinline)) void StatusEffectStoreRandomizedParams(void *object,
                                           const struct StatusRandomizedEffectParams *params)
{
    uint8_t *component = (uint8_t *)ResolveStatusEffectComponent(object);
    uint8_t *effect;
    if (component == 0 || *(void **)(component + 0x2c) == 0)
        return;
    effect = *(uint8_t **)(component + 0x2c);
    *(float *)(effect + 0xba4) = params->chance;
    *(float *)(effect + 0xba8) = params->scale;
    effect[0xbac] = 1;
}
__attribute__((noinline)) void StatusEffectStoreAuxiliaryParams(void *target, const void *record)
{
    uint8_t *component = (uint8_t *)ResolveCachedComponentAt1EC(target);
    uint8_t *effect;
    if (component == 0)
        return;
    effect = *(uint8_t **)(component + 0x28u);
    if (effect == 0)
        return;
    StatusAuxiliaryRecordReset(effect + 0x29cu);
    *(uint32_t *)(effect + 0x29cu) = *(const uint32_t *)record;
    *(uint32_t *)(effect + 0x2a0u) =
        *(const uint32_t *)((const uint8_t *)record + 4u);
    *(uint32_t *)(effect + 0x2a4u) =
        *(const uint32_t *)((const uint8_t *)record + 8u);
    effect[0x2a8u] = 1;
}
int StatusAlternateUpdateTimer(void *status, unsigned channel, float requested,
                                  const void *config)
{
    uint8_t *bytes = (uint8_t *)status;
    const uint8_t *cfg = (const uint8_t *)config;
    if (channel == 6 && config != 0) {
        *(float *)(bytes + 0x228) = requested * *(const float *)(cfg + 0x59c);
        return 1;
    }
    if (channel == 7 && config != 0) {
        *(float *)(bytes + 0x22c) = requested * *(const float *)(cfg + 0x52c);
        return 1;
    }
    if (channel == 8) {
        *(float *)(bytes + 0x230) = requested;
        return 1;
    }
    if (channel == 9) {
        *(float *)(bytes + 0x234) = requested;
        return 1;
    }
    return 0;
}
void StatusAlternateCommit(void *status, unsigned channel)
{
    uint8_t *bytes = (uint8_t *)status;
    *(float *)(bytes + 0x1e0 + channel * 4) = 0.0f;
    *(float *)(bytes + 0x240 + channel * 4) = 0.0f;
    *(uint32_t *)(bytes + 0x1dc) |= 1u << channel;
}
__attribute__((noinline)) void StatusEffectDispatchMatchingHandle(void *dispatcher, void *target,
                                     uint32_t argument)
{
    uint8_t *bytes = (uint8_t *)dispatcher;
    const struct EngineResourceHandleEntryView *table =
        (const struct EngineResourceHandleEntryView *)(uintptr_t)0x00e11614u;
    struct StatusDispatchLink *link =
        *(struct StatusDispatchLink **)(bytes + 0x2ccc);
    struct StatusDispatchLink *sentinel =
        *(struct StatusDispatchLink **)(bytes + 0x2cc8);
    while (link != sentinel) {
        uint32_t packed_handle = *(uint32_t *)((uint8_t *)link->event + 0x6c);
        uint32_t index = packed_handle & 0x1ffu;
        uint32_t generation = packed_handle >> 9;
        void *mapped = 0;
        if (generation != 0x007fffffu &&
            table[index].generation == generation)
            mapped = table[index].object;
        if (mapped == target)
            StatusDispatchEvent(dispatcher, link->event, argument);
        link = link->next;
    }
}
__attribute__((noinline)) int StatusEffectRefreshMode0(void *object, float value, float previous_value)
{
    (void)StatusEffectUpdate(object, 0, value, 0.0f, previous_value);
    return 1;
}
int StatusEffectUpdateMode0Selected(void *object, void *selected_entry,
                                       float value, float previous_value)
{
    uint8_t *bytes = (uint8_t *)object;
    float accepted = previous_value;
    if (value > 0.0f) {
        if (accepted < 0.0f && bytes[0xd9] != 0)
            accepted = value;
        if (accepted >= 0.0f) {
            *(float *)(bytes + 0x3c) = value;
            if (selected_entry != 0) {
                uint8_t *slot = *(uint8_t **)((uint8_t *)selected_entry + 0x24);
                uint8_t *linked = slot != 0 ? *(uint8_t **)(slot + 0xb0) : 0;
                if (linked != 0) {
                    if (*(float *)(bytes + 0xd0) < 0.0f)
                        *(float *)(bytes + 0xd0) = *(float *)(linked + 0x24);
                    *(float *)(linked + 0x24) = accepted;
                }
            }
        }
    }
    if (bytes[0xd8] != 0 && accepted < 0.0f)
        StatusEffectNegativeTransition(object);
    return 1;
}
__attribute__((noinline)) void StatusEffectQueueSeedIfUninitialized(void *object,
                                             uint32_t second_duration,
                                             uint32_t flags,
                                             void *callback,
                                             float duration,
                                             float callback_value)
{
    uint8_t *bytes = (uint8_t *)object;
    struct EffectQueueView *queue =
        (struct EffectQueueView *)(bytes + 0xf0);
    if (bytes[0x1edf8] != 0)
        return;
    EffectQueueReset(queue, 0);
    EffectQueueAppend(&queue->variants[0], 0, second_duration, flags,
                          duration);
    if (callback != 0)
        EffectEventDispatchTimed(callback, callback_value);
    bytes[0x1edf8] = (uint8_t)*(uint32_t *)(bytes + 0x1ee44);
}
__attribute__((noinline)) int StatusTargetPassesSpecialFilter(int matches_excluded_global,
                                       int has_component,
                                       uint32_t component_flags)
{
    if (matches_excluded_global)
        return 0;
    if (has_component && (component_flags & 0x100u))
        return 0;
    return 1;
}
__attribute__((noinline)) int StatusEffectUpdate(void *object, unsigned mode,
                          float input, float auxiliary, float previous)
{
    uint8_t *bytes = (uint8_t *)object;
    float accepted = previous;
    if (input > 0.0f) {
        float sum = input + auxiliary;
        if (previous < 0.0f && bytes[0xd9] != 0)
            accepted = StatusEffectNegativeValueResolve((float)bytes[0xd9]);
        if (accepted >= 0.0f) {
            uint8_t *target = *(uint8_t **)(bytes + 0x30);
            uint8_t *selected = *(uint8_t **)(bytes + 0x1e4);
            if (selected == 0) {
                uint8_t *entry = OrderedTreeLowerBoundByPointer(
                    target + 0x1a4, GetStatusEffectDescriptorKey());
                uint8_t *upper = *(uint8_t **)(target + 0x1a8);
                if (entry != 0 && *(uint8_t **)entry != upper) {
                    selected = *(uint8_t **)entry;
                    if (selected != 0) {
                        *(void **)(selected + 0x1c) = target;
                        *(uint8_t **)(bytes + 0x1e4) = selected;
                    }
                }
            }
            if (selected != 0) {
                uint8_t *slot = *(uint8_t **)(selected + 0x24);
                uint8_t *linked = slot != 0
                    ? *(uint8_t **)(slot + 0xb0) : 0;
                if (linked != 0) {
                    if (*(float *)(bytes + 0xd0) < previous)
                        *(float *)(bytes + 0xd0) =
                            *(float *)(linked + 0x24);
                    *(float *)(linked + 0x24) = accepted;
                }
            }
            *(float *)(bytes + 0x3c) = sum;
            if (mode != 0) {
                void *owner = StatusEffectOwnerLookup(target);
                if (owner != 0)
                    StatusEffectOwnerFlagsUpdate(owner, 1, 1);
            }
            {
                uint8_t *component = (uint8_t *)
                    StatusEffectComponentLookup(target);
                if (component != 0)
                    *(uint32_t *)(component + 0x88) |= 0x400u;
            }
        }
    }
    if (bytes[0xd8] != 0 && previous != accepted && accepted <= previous)
        StatusEffectNegativeTransition(object);
    return 1;
}
__attribute__((noinline)) float StatusEffectNegativeValueResolve(float value)
{
    if (value <= 0.0f)
        return 1.0f;
    return (0.25f / (value + 0.25f)) * (1.0f / 60.0f);
}
__attribute__((noinline)) void StatusEffectNegativeTransition(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    void *target = *(void **)(bytes + 0x30);
    *(float *)(bytes + 0x3c) = 0.0f;
    StatusEffectDescriptorRefresh(object);
    {
        void *owner = StatusEffectOwnerLookup(target);
        if (owner != 0)
            StatusEffectOwnerFlagsUpdate(owner, 0, 1);
    }
    {
        uint8_t *component = (uint8_t *)StatusEffectComponentLookup(target);
        if (component != 0)
            *(uint32_t *)(component + 0x88) &= ~0x400u;
    }
}
__attribute__((noinline)) void StatusEffectDescriptorRefresh(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *target = *(uint8_t **)(bytes + 0x30);
    uint8_t *selected = *(uint8_t **)(target + 0x1e4);
    if (selected == 0) {
        uint8_t *sentinel = target + 0x1a4;
        uint8_t *root = *(uint8_t **)(target + 0x1ac);
        uint8_t *candidate = *(uint8_t **)(target + 0x1a8);
        uint8_t *key = (uint8_t *)GetStatusEffectRefreshKey();
        while (*(uint8_t *)(root + 0x10) != 0) {
            if (*(uint32_t *)(root + 0x14) < (uint32_t)key)
                root = *(uint8_t **)(root + 0x0c);
            else {
                candidate = root;
                root = *(uint8_t **)(root + 0x08);
            }
        }
        if (candidate != sentinel + 4 &&
            *(uint32_t *)(candidate + 0x14) <= (uint32_t)key)
            candidate = sentinel + 4;
        if (candidate != 0 &&
            *(uint8_t **)candidate != *(uint8_t **)(target + 0x1a8)) {
            selected = *(uint8_t **)candidate;
            if (selected != 0) {
                *(void **)(selected + 0x1c) = target;
                *(uint8_t **)(target + 0x1e4) = selected;
            }
        }
    }
    if (selected != 0) {
        uint8_t *slot = *(uint8_t **)(selected + 0x24);
        uint8_t *linked = *(uint8_t **)(slot + 0xb0);
        if (*(float *)(bytes + 0xd0) > 0.0f)
            *(float *)(linked + 0x24) = *(float *)(bytes + 0xd0);
    }
    *(float *)(bytes + 0xd0) = -1.0f;
}
__attribute__((noinline)) int StatusEffect_DescriptorRefreshZero_004DC9F4(void *object)
{
    StatusEffectDescriptorRefresh(object);
    return 0;
}
