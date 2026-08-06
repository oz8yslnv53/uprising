#include <stddef.h>
#include <stdint.h>
#include "actor_combat_views.h"
extern int StatusChannelIndexMap(int identifier);
extern void *ResolveRelatedComponent(void *object);
extern void Health_StatusBitUpdate(void *health, uint32_t mask, int enabled);
extern void *StatusLazySingleton0054EFA8(void);
extern void *CachedComponent_ResolveClass1(void *registry, void *object);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *StatusModeRecordLookup_0054E208(void *object);
extern void ComponentNotifyStatusChange(void *component, unsigned mode,
                                         unsigned requested_state);
extern void *StatusOwnerIndexAddress(void *base, int8_t index);
extern void *OrderedTree_LowerBoundStatusHandle(void *tree, uint32_t key);
extern void StatusModeRecord_RefreshAfterFlagChange(void);
extern void *Engine_StatusDescriptorRegistry_Get(void);
extern void *StatusThresholdBufferCreate_00475D70(void);
__attribute__((noinline)) void StatusRuntime_StoreTransitionValue(void *target, float value)
{
    uint8_t *bytes = (uint8_t *)target;
    uint8_t *runtime = *(uint8_t **)(bytes + 0x30u);
    uint8_t *container = *(uint8_t **)(bytes + 0x38u);
    uint8_t *record = *(uint8_t **)(container + 0x34u);
    *(float *)(runtime + 0x60u) = value;
    if (record != 0)
        *(float *)(record + 0x2cu) = value;
}
__attribute__((noinline)) void StatusModeRecord_ApplyRequestedBits(void *state, uint32_t key,
                                         unsigned enabled, unsigned mode,
                                         unsigned bit_index)
{
    uint8_t *bytes = (uint8_t *)state;
    uint8_t *node = (uint8_t *)OrderedTree_LowerBoundStatusHandle(
        bytes + 0x08u, key);
    uint8_t *record = node != 0 ? *(uint8_t **)node : 0;
    uint8_t *sentinel = *(uint8_t **)(bytes + 0x0cu);
    uint32_t bit = 1u << (bit_index & 0xffu);
    if (record == 0 || record == sentinel || record[0x1a] == 0)
        return;
    if (enabled != 0)
        *(uint32_t *)(record + 0x30u) |= bit;
    else
        *(uint32_t *)(record + 0x30u) &= ~bit;
    if (mode != 0)
        *(uint32_t *)(record + 0x34u) |= bit;
    else
        *(uint32_t *)(record + 0x34u) &= ~bit;
    StatusModeRecord_RefreshAfterFlagChange();
}
extern void **StatusHandleRegistrySlot(void);
extern void *CreateStatusHandleRegistry(void);
extern void ReleaseStatusHandle(void *registry, uint32_t handle,
                                   uint32_t mode);
extern void **StatusChannelTypeRegistrySlot(void);
extern void *CreateStatusChannelTypeRegistry(void);
int StatusBuildup_AccumulateAndApply(void *status,
                                       StatusChannel channel,
                                       float amount,
                                       float activation_value);
enum StatusOwnerExpiryMask {
    STATUS_OWNER_EXPIRY_CHANNEL_8 = 0x00000800u,
    STATUS_OWNER_EXPIRY_CHANNEL_9 = 0x00001000u
};
extern void *GetStatusOwnerRegistry(void);
extern void StatusChannelResetOrReplace(void *status,
                                           StatusChannel channel,
                                           unsigned keep_replacement);
extern void *ResolveRelatedComponent(void *object);
extern void *ResolveStatusEffectComponent(void *object);
int StatusBuildup_AccumulateAndApply(void *status,
                                       StatusChannel channel,
                                       float amount,
                                       float activation_value);
extern void StatusChannelClearRequested(void *status,
                                            StatusChannel channel);
extern uint8_t *OrderedTreeLowerBound(void *tree, void *key);
extern void *StatusAlternateParameterKey_004A4BBC(void);
extern void ParameterStringNormalize_00352994(void *destination,
                                                const void *source);
extern void StatusAlternateDescriptorApply_00532500(void *descriptor,
                                                       void *parameters,
                                                       unsigned mode);
extern int EngineOnceGuard(uint32_t *guard);
extern void *ResolveRelatedComponent(void *object);
extern int StatusTargetPassesSpecialFilterRetail(void *target);
int StatusChannelActivatePrimary(void *status, void *target,
                                     unsigned channel, float buildup);
extern void StatusStateHandleClearIfPresent(void *target, unsigned mode);
extern void *GetActorStateFactory(void);
extern void *ActorStateRequestByFactory(void *actor, void *factory);
extern uint32_t *StateParameterRecordInit(void *scratch);
extern void ActorSetDodgeInvulnFlags(void *variant, unsigned a,
                                         unsigned b, unsigned c);
extern void *StatusOwnerResolve(void *registry, void *actor);
void StatusChannelSetReactionState(void *target, unsigned selector);
extern void StatusVariantPrepareRecord(void *variant, unsigned mode);
extern void *ResolveStatusEffectComponent(void *object);
int StatusChannelActivateAlternate(void *status, void *target,
                                      unsigned channel, float buildup);
extern void *StatusEffectSelectVariant(void *target, unsigned mode,
                                        unsigned selector);
extern void StatusPublishActivation(void *registry, void *target,
                                    uint32_t active_mask, float hidden_value);
extern void StatusChannelResetOrReplace(void *actor,
                                           StatusChannel channel,
                                           unsigned keep_replacement);
extern void *GetStatusOwnerRegistry(void);
extern uint32_t GetAlternateStatusKey(void);
extern uint32_t GetAlternateStatusKey(void);
void StatusOwnerClearFlags(void *owner, uint32_t mask, float hidden_value);
int StatusChannelIndexMap(int identifier);
unsigned StatusOwnerIndexByObject(void *actor, void *owner);
unsigned StatusChannelIsActive(void *object, unsigned channel);
uint32_t StatusEffectCreateOrRelease(void *context, int effect_type,
                                         unsigned create);
void StatusChannelResetOrReplace(void *status, StatusChannel channel,
                                    unsigned store_replacement);
void StatusOwnerCleanup(void *registry, unsigned owner_index);
uint8_t *StatusVariantResolveCached(void *target);
void StatusChannelSetReactionState(void *target, unsigned selector);
void StatusChannelPrepareAuxiliary(void *target, unsigned mode);
void StatusChannelClearVariant5(void *target);
void StatusChannelClearVariant10(void *target);
int32_t StatusConditionValueAt(const void *condition, unsigned index);
void StatusConditionAdd(void *condition, int32_t delta, unsigned index);
int StatusBuildup_AccumulateAndApply(void *status,
                                       StatusChannel channel,
                                       float amount,
                                       float activation_value);
void StatusChannelExpire(void *status,
                            void *target,
                            StatusChannel channel);
void StatusChannelExpireAlternate(void *actor,
                                     void *status_component,
                                     StatusChannel channel,
                                     float hidden_value);
void StatusChannelClearRequested(void *actor, StatusChannel channel);
int StatusChannelActivatePrimary(void *status, void *target,
                                    unsigned channel, float buildup);
int StatusChannelActivateAlternate(void *status, void *target,
                                      unsigned channel, float buildup);
__attribute__((noinline)) void StatusMask_ApplyRequested(void *target, uint32_t requested_mask,
                               unsigned mode, float activation_value)
{
    uint8_t *component;
    void *runtime_component;
    void *descriptor;
    void *singleton;
    uint32_t runtime_changed;
    uint32_t changed;
    void *selected_runtime = 0;
    unsigned channel;
    (void)mode;
    singleton = StatusLazySingleton0054EFA8();
    component = (uint8_t *)ResolveRelatedComponent(target);
    if (component == 0)
        return;
    runtime_component = CachedComponent_ResolveClass1(singleton, target);
    changed = (*(uint32_t *)(component + STATUS_ACTIVE_MASK_OFFSET) ^
               requested_mask) & 0xfffu;
    for (channel = 0; channel < STATUS_CHANNEL_COUNT; ++channel) {
        uint32_t bit = 1u << channel;
        if ((changed & bit) == 0)
            continue;
        if ((requested_mask & bit) == 0) {
            StatusChannelClearRequested(component, (StatusChannel)channel);
            if (channel == 1u || channel == 2u)
                StatusChannelSetReactionState(target, 0u);
        } else {
            Health_StatusBitUpdate(component, 0x02000300u, 0);
            StatusBuildup_AccumulateAndApply(
                component, (StatusChannel)channel, 0.0f, activation_value);
        }
    }
    runtime_changed = (*(uint32_t *)((uint8_t *)runtime_component + 0x60) ^
                       requested_mask) & 0x007ff000u;
    if (runtime_changed != 0) {
        descriptor = ResolveStatusDescriptor(target);
        if ((runtime_changed & 0x00001000u) != 0)
            StatusModeRecord_ApplyRequestedBits(
                (uint8_t *)singleton + 0xf98cu,
                *(uint32_t *)((uint8_t *)descriptor + 0x20u),
                (requested_mask & 0x1000u) == 0u, 1u, 0u);
        if ((runtime_changed & 0x00002000u) != 0)
            StatusModeRecord_ApplyRequestedBits(
                (uint8_t *)singleton + 0xf98cu,
                *(uint32_t *)((uint8_t *)descriptor + 0x20u),
                (requested_mask & 0x2000u) == 0u, 1u, 1u);
        if ((runtime_changed & 0x0000c000u) != 0) {
            uint8_t *entry = OrderedTreeLowerBound(
                (uint8_t *)target + 0x1a4u,
                Engine_StatusDescriptorRegistry_Get());
            uint8_t *upper = *(uint8_t **)((uint8_t *)target + 0x1a8u);
            uint8_t *cache;
            float transition_value;
            selected_runtime = entry != 0 ? *(void **)entry : 0;
            if (selected_runtime == upper)
                selected_runtime = 0;
            {
                uint8_t **cache_slot = *(uint8_t ***)
                    (uintptr_t)0x006e86fcu;
                cache = *cache_slot;
                if (cache == 0) {
                    cache = (uint8_t *)StatusThresholdBufferCreate_00475D70();
                    *cache_slot = cache;
                }
            }
            cache += 0x196ecu;
            if ((requested_mask & 0x00008000u) != 0)
                transition_value = *(float *)(cache + 0x90u);
            else if ((requested_mask & 0x00004000u) != 0)
                transition_value = *(float *)(cache + 0x94u);
            else
                transition_value = 1.0f;
            StatusRuntime_StoreTransitionValue(selected_runtime,
                                               transition_value);
        }
        if ((runtime_changed & 0x00010000u) != 0) {
            void *mode_record = StatusModeRecordLookup_0054E208(target);
            void *linked = *(void **)((uint8_t *)mode_record + 0x20u);
            ComponentNotifyStatusChange(
                linked, 0u,
                ((requested_mask & 0x00010000u) != 0u) ^ 1u);
        }
        if ((runtime_changed & 0x00100000u) != 0) {
            void *mode_record = StatusModeRecordLookup_0054E208(target);
            void *linked = *(void **)((uint8_t *)mode_record + 0x20u);
            uint32_t flags = *(uint32_t *)((uint8_t *)linked + 0x30u);
            uint32_t wanted = (requested_mask & 0x00100000u) != 0u;
            if ((flags & 1u) != wanted)
                *(uint32_t *)((uint8_t *)linked + 0x30u) = flags ^ 1u;
        }
        if ((runtime_changed & 0x000c0000u) != 0) {
            void *owner = StatusOwnerIndexAddress(
                (uint8_t *)singleton + 0xb3f8u,
                *(int8_t *)((uint8_t *)descriptor + 0x2cu));
            uint32_t *owner_flags =
                (uint32_t *)((uint8_t *)owner + 0xad8u);
            if ((runtime_changed & 0x00040000u) != 0) {
                if ((requested_mask & 0x00040000u) == 0) {
                    *owner_flags &= ~0x40u;
                    *(float *)((uint8_t *)owner + 0xb54u) = 0.0f;
                } else {
                    *owner_flags |= 0x40u;
                }
            }
            if ((runtime_changed & 0x00080000u) != 0) {
                if ((requested_mask & 0x00080000u) == 0) {
                    *owner_flags &= ~0x80u;
                    *(float *)((uint8_t *)owner + 0xb58u) = 0.0f;
                } else {
                    *owner_flags |= 0x80u;
                }
            }
        }
    }
    *(uint32_t *)((uint8_t *)runtime_component + 0x60u) = requested_mask;
}
__attribute__((noinline)) int StatusChannelIndexMap(int identifier)
{
    if (identifier != -1)
        return *(const uint8_t *)((uintptr_t)0x00ca84a0u + identifier);
    return -1;
}
__attribute__((noinline)) unsigned StatusChannelIsActive(void *object, unsigned channel)
{
    uint8_t *component = (uint8_t *)ResolveRelatedComponent(object);
    if (component == 0 || channel >= 32u)
        return 0u;
    return (*(uint32_t *)(component + 0x1dc) & (1u << (channel & 0xffu)))
        != 0u;
}
__attribute__((noinline)) void StatusChannelResetOrReplace(void *status, StatusChannel channel,
                                    unsigned store_replacement)
{
    uint8_t *bytes = (uint8_t *)status;
    uint32_t *slot = (uint32_t *)(bytes + 0x1eccc + channel * 4u);
    void *registry;
    void **registry_slot;
    uint32_t effect_type;
    uint32_t replacement;
    if (*slot != 0xffffffffu) {
        registry_slot = StatusHandleRegistrySlot();
        registry = *registry_slot;
        if (registry == 0) {
            registry = CreateStatusHandleRegistry();
            *registry_slot = registry;
        }
        ReleaseStatusHandle(registry, *slot, 0);
    }
    registry_slot = StatusChannelTypeRegistrySlot();
    registry = *registry_slot;
    if (registry == 0) {
        registry = CreateStatusChannelTypeRegistry();
        *registry_slot = registry;
    }
    effect_type = *(uint32_t *)((uint8_t *)registry + 0x4664u +
                                channel * 4u);
    replacement = StatusEffectCreateOrRelease(status, (int)effect_type, 1);
    *slot = 0xffffffffu;
    if (store_replacement != 0)
        *slot = replacement;
}
static void RequestReactionState(uint8_t *variant, uint8_t *actor,
                                     unsigned source_offset,
                                     unsigned state_code)
{
    uint32_t factory_record[2];
    uint32_t parameter_storage[5] = {0, 0, 0, 0, 0};
    uint32_t *parameters;
    uint8_t *state;
    uint8_t *source = *(uint8_t **)(variant + 0x34);
    factory_record[0] = (uint32_t)(uintptr_t)GetActorStateFactory();
    factory_record[1] = 0;
    state = (uint8_t *)ActorStateRequestByFactory(
        *(void **)(variant + 0x30), factory_record);
    StateParameterRecordInit(parameter_storage);
    parameters = parameter_storage;
    parameters[0] = *(uint32_t *)(source + source_offset);
    parameters[1] = *(uint32_t *)(source + source_offset + 4);
    *(uint32_t *)(state + 0x34) = parameters[0];
    *(uint32_t *)(state + 0x38) = parameters[1];
    *(uint32_t *)(actor + 0x34) = parameters[0];
    *(uint32_t *)(actor + 0x38) = parameters[1];
    actor[0x54] = (uint8_t)state_code;
    ActorSetDodgeInvulnFlags(variant, 1, 1, 0);
}
__attribute__((noinline)) void StatusChannelSetReactionStateBody_0055DC04(void *variant_object,
                                                    unsigned selector)
{
    uint8_t *variant = (uint8_t *)variant_object;
    uint8_t *actor;
    uint8_t *state_handle;
    uint32_t flags;
    void *registry;
    void *owner;
    state_handle = *(uint8_t **)(variant + 0x3c);
    if (state_handle != 0)
        *(uint32_t *)(state_handle + 0xcc) =
            *(uint32_t *)(state_handle + 0xd0);
    actor = *(uint8_t **)(variant + 0x38);
    flags = *(uint32_t *)(actor + 0x98);
    if (selector == 1) {
        if ((flags & 0x400000u) == 0) {
            *(uint32_t *)(actor + 0x98) = flags | 2u;
            *(uint32_t *)(actor + 0x94) &= ~0x200u;
            StatusStateHandleClearIfPresent(
                *(void **)(variant + 0x30), 0);
            RequestReactionState(variant, actor, 0x184u, 3);
        }
    } else {
        if (selector != 2 && (flags & 0x400000u) != 0) {
            *(uint32_t *)(actor + 0x98) = flags & ~2u;
            RequestReactionState(variant, actor, 0x168u, 4);
            goto reaction_common;
        }
        if ((flags & 0x400000u) == 0) {
            *(uint32_t *)(actor + 0x98) = flags | 2u;
            *(uint32_t *)(actor + 0x94) &= ~0x200u;
            StatusStateHandleClearIfPresent(
                *(void **)(variant + 0x30), 0);
            RequestReactionState(variant, actor, 0x1a0u, 3);
        }
    }
reaction_common:
    registry = GetStatusOwnerRegistry();
    owner = StatusOwnerResolve(
        registry, *(void **)(variant + 0x30));
    StatusOwnerCleanup(registry, StatusOwnerIndexByObject(registry, owner));
    *(uint32_t *)(actor + 0x94) &= ~0x20001u;
    variant[0xdd] |= 1u;
}
__attribute__((noinline)) void StatusChannelSetReactionState(void *target, unsigned selector)
{
    uint8_t *variant = StatusVariantResolveCached(target);
    if (variant == 0)
        return;
    StatusChannelSetReactionStateBody_0055DC04(variant, selector);
}
__attribute__((noinline)) void StatusChannelPrepareAuxiliary(void *target, unsigned mode)
{
    uint8_t *variant = StatusVariantResolveCached(target);
    if (variant != 0)
        StatusVariantPrepareRecord(variant, mode);
}
__attribute__((noinline)) void StatusChannelClearVariant5(void *target)
{
    uint8_t *component = (uint8_t *)ResolveStatusEffectComponent(target);
    uint8_t *nested = component != 0 ? *(uint8_t **)(component + 0x2c) : 0;
    if (nested != 0)
        nested[0xbac] = 0;
}
__attribute__((noinline)) void StatusChannelClearVariant10(void *target)
{
    uint8_t *component = (uint8_t *)ResolveStatusEffectComponent(target);
    uint8_t *nested = component != 0 ? *(uint8_t **)(component + 0x28) : 0;
    if (nested != 0)
        nested[0x2a9] = 1;
}
__attribute__((noinline)) int32_t StatusConditionValueAt(const void *condition, unsigned index)
{
    return *(const int32_t *)((const uint8_t *)condition + 0x24c +
                              index * 0x0cu);
}
__attribute__((noinline)) void StatusConditionAdd(void *condition, int32_t delta, unsigned index)
{
    uint8_t *bytes = (uint8_t *)condition;
    if ((*(uint32_t *)(bytes + 0x1e8) & 0x3000u) == 0)
        *(int32_t *)(bytes + 0x24c + index * 0x0cu) += delta;
}
__attribute__((noinline)) int StatusBuildup_AccumulateAndApply(void *status,
                                       StatusChannel channel,
                                       float amount,
                                       float activation_value)
{
    enum {
        STATUS_FLAG_SUPPRESS_BUILDUP = 0x00100000u,
        STATUS_FLAG_ALTERNATE_ACTIVATION = 0x00000002u,
        STATUS_FLAG_SPECIAL_FILTER = 0x00000001u
    };
    struct HealthStatusComponent *component =
        (struct HealthStatusComponent *)status;
    float *buildup;
    float total;
    void *target;
    if (channel >= 12 ||
        (component->flags & STATUS_FLAG_SUPPRESS_BUILDUP) != 0)
        return 0;
    buildup = &component->buildup[channel];
    total = *buildup + amount;
    *buildup = total;
    if (total < 100.0f)
        return 0;
    target = component->target;
    if ((component->flags & STATUS_FLAG_ALTERNATE_ACTIVATION) == 0) {
        if ((component->flags & STATUS_FLAG_SPECIAL_FILTER) != 0 &&
            (!StatusTargetPassesSpecialFilterRetail(target) ||
             -10.0f < component->remaining_time[channel])) {
            *buildup = 99.9f;
            return 0;
        }
        StatusChannelActivatePrimary(status, target, channel,
                                        activation_value);
    } else {
        StatusChannelActivateAlternate(status, target, channel,
                                          activation_value);
    }
    return 1;
}
__attribute__((noinline)) void StatusChannelExpire(void *status,
                            void *target,
                            StatusChannel channel)
{
    struct HealthStatusComponent *component =
        (struct HealthStatusComponent *)status;
    uint32_t bit;
    uint32_t mask;
    float publish_value = 0.0f;
    if (channel >= 12)
        return;
    bit = 1u << channel;
    if ((component->active_mask & bit) == 0)
        return;
    if ((int32_t)component->current_hp.bits <= (int32_t)0x377fffff &&
        channel != 1 && channel != 2)
        return;
    component->remaining_time[channel] = 0.0f;
    component->secondary_buildup[channel] = 0.0f;
    component->buildup[channel] = 0.0f;
    switch (channel) {
    case 1:
        StatusChannelSetReactionState(target, 0);
        StatusEffectSelectVariant(target, 1, 0);
        component->buildup[2] = 0.0f;
        component->buildup[3] = 0.0f;
        component->buildup[4] = 0.0f;
        break;
    case 2:
        StatusChannelSetReactionState(target, 0);
        StatusEffectSelectVariant(target, 1, 0);
        component->buildup[3] = 0.0f;
        component->buildup[4] = 0.0f;
        break;
    case 3:
        StatusChannelPrepareAuxiliary(target, 0);
        StatusEffectSelectVariant(target, 1, 0);
        component->remaining_time[3] = -13.0f;
        component->buildup[4] = 0.0f;
        publish_value = -13.0f;
        break;
    case 4:
        StatusChannelPrepareAuxiliary(target, 0);
        StatusEffectSelectVariant(target, 1, 0);
        component->weak_scale = 1.0f;
        component->remaining_time[4] = -13.0f;
        publish_value = 1.0f;
        break;
    case 5:
        StatusChannelClearVariant5(target);
        break;
    case 9:
        StatusEffectSelectVariant(target, 1, 0);
        break;
    case 10:
        StatusChannelClearVariant10(target);
        break;
    default:
        break;
    }
    mask = component->active_mask & ~bit;
    component->active_mask = mask;
    StatusPublishActivation(StatusLazySingleton0054EFA8(), target, mask,
                            publish_value);
}
static void *StatusAlternateOwnerSentinel(void)
{
    uint32_t *outer_guard = (uint32_t *)(uintptr_t)0x00d5ff44u;
    uint32_t *outer_slot = (uint32_t *)(uintptr_t)0x00d5ff48u;
    uint32_t *middle_guard = (uint32_t *)(uintptr_t)0x00d627c4u;
    uint32_t *middle_slot = (uint32_t *)(uintptr_t)0x00d627c8u;
    uint32_t *inner_guard = (uint32_t *)(uintptr_t)0x00d619c8u;
    uint32_t *inner_slot = (uint32_t *)(uintptr_t)0x00d619ccu;
    if (EngineOnceGuard(outer_guard)) {
        if (EngineOnceGuard(middle_guard)) {
            if (EngineOnceGuard(inner_guard))
                *inner_slot = 0;
            *middle_slot = *inner_slot;
        }
        *outer_slot = *middle_slot;
    }
    return *(void **)(uintptr_t)0x00d5ff48u;
}
__attribute__((noinline)) void StatusChannelExpireAlternate(void *actor,
                                     void *status_component,
                                     StatusChannel channel,
                                     float hidden_value)
{
    struct HealthStatusComponent *component =
        (struct HealthStatusComponent *)actor;
    struct ActorObjectView *target_object =
        (struct ActorObjectView *)status_component;
    uint8_t *owner = 0;
    uint8_t *selected_descriptor = 0;
    uint32_t bit;
    float clear_value = hidden_value;
    if (channel >= 12)
        return;
    {
        uint8_t *entry = OrderedTreeLowerBound(
            &target_object->component_tree_anchor,
            (void *)(uintptr_t)GetAlternateStatusKey());
        uint8_t *selected = entry != 0 ? *(uint8_t **)entry : 0;
        uint8_t *upper = (uint8_t *)target_object->component_tree_upper;
        if (selected != upper && selected != 0)
            owner = *(uint8_t **)(selected + 0x28);
    }
    if (channel == 3 || channel == 4) {
        uint8_t *owner_list = *(uint8_t **)(
            (uint8_t *)status_component + 0x168u);
        if (owner_list != 0) {
            typedef void *(*OwnerListHead)(void *list);
            void *sentinel = StatusAlternateOwnerSentinel();
            void *node = ((OwnerListHead)(*(void ***)owner_list)[0])(
                owner_list);
            while (node != 0 && node != sentinel)
                node = *(void **)node;
            if (node == sentinel)
                owner_list[0x2c] = 1;
        }
    }
    if (channel == 3 || channel == 4) {
        uint8_t *entry = OrderedTreeLowerBound(
            &target_object->component_tree_anchor,
            StatusAlternateParameterKey_004A4BBC());
        uint8_t *upper = (uint8_t *)target_object->component_tree_upper;
        if (entry != 0)
            selected_descriptor = *(uint8_t **)entry;
        if (selected_descriptor == upper)
            selected_descriptor = 0;
        if (selected_descriptor != 0) {
            uint8_t normalized_parameter[0x20];
            uint32_t normalized_record[3] = {
                (uint32_t)(uintptr_t)normalized_parameter, 0x20u, 0u
            };
            uint32_t parameter_storage[5] = {0, 0, 0, 0, 0};
            uint32_t *parameters;
            ParameterStringNormalize_00352994(
                normalized_record, selected_descriptor + 0x198);
            parameters = StateParameterRecordInit(parameter_storage);
            parameters[0] = *(uint32_t *)(selected_descriptor + 0x194);
            parameters[1] = normalized_record[0];
            StatusAlternateDescriptorApply_00532500(
                selected_descriptor, parameters, 0);
        }
    }
    switch (channel) {
    case 3:
        component->buildup[4] = 0.0f;
        clear_value = 0.0f;
        break;
    case 4:
        component->weak_scale = 1.0f;
        clear_value = 1.0f;
        break;
    case 8:
    case 9:
        if (owner != 0)
            StatusOwnerClearFlags(owner,
                                     channel == 8 ? STATUS_OWNER_EXPIRY_CHANNEL_8
                                                  : STATUS_OWNER_EXPIRY_CHANNEL_9,
                                     hidden_value);
        break;
    default:
        break;
    }
    bit = 1u << channel;
    component->active_mask &= ~bit;
    component->remaining_time[channel] = clear_value;
    component->secondary_buildup[channel] = clear_value;
    component->buildup[channel] = clear_value;
}
__attribute__((noinline)) void StatusChannelClearRequested(void *actor, StatusChannel channel)
{
    struct HealthStatusComponent *component =
        (struct HealthStatusComponent *)actor;
    uint8_t *status_component;
    uint32_t flags;
    if (channel >= 12)
        return;
    component->buildup[channel] = 0.0f;
    status_component = (uint8_t *)component->target;
    flags = component->flags;
    if ((flags & 0x2u) != 0)
        StatusChannelExpireAlternate(actor, status_component, channel,
                                     0.0f);
    else if ((flags & 0x1u) != 0)
        StatusChannelExpire(actor, status_component, channel);
}
extern void StatusOwnerLinkedTextRelease_005726CC(void *linked_text_record);
extern void EngineRegistryRefresh_004851AC(void *registry, int mode);
__attribute__((noinline)) void StatusOwner_SetTransitionPending_005B220C(void *owner)
{
    uint8_t *owner_bytes = (uint8_t *)owner;
    uint32_t *flags_slot = (uint32_t *)(owner_bytes + 0xc0);
    uint32_t previous_flags = *flags_slot;
    *flags_slot = previous_flags | 0x20000u;
    if ((previous_flags & 0x10000u) == 0)
        return;
    {
        uint8_t *linked = *(uint8_t **)(owner_bytes + 0x140);
        StatusOwnerLinkedTextRelease_005726CC(linked + 0x243c);
    }
    *flags_slot &= ~0x10000u;
    {
        void *registry = StatusLazySingleton0054EFA8();
        EngineRegistryRefresh_004851AC(registry, 0);
    }
}
