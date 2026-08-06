#include <stddef.h>
#include <stdint.h>
#include "actor_combat_views.h"
extern void *GetEngineSingleton_003B6CF0(void);
extern uint32_t DamagePacketBuildFlags(void *context);
extern void *ResolveRelatedComponent(void *object);
extern void *ResolveStatusDescriptor(void *descriptor);
enum HealthSecondaryPhase {
    HEALTH_SECONDARY_IDLE = 0,
    HEALTH_SECONDARY_PHASE_ONE_STATE = 1,
    HEALTH_SECONDARY_PHASE_TWO_STATE = 2,
    HEALTH_SECONDARY_COMPLETE = 3
};
enum HealthUpdateBehaviorFlag {
    HEALTH_NONPOSITIVE_GUARD_MASK = 0x000041c0,
    HEALTH_MINIMUM_ONE = 0x00080000
};
extern void *ResolveStatusDescriptor(void *descriptor);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern void *GetStatusOwnerRegistry(void);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *ResolveRelatedComponent(void *object);
extern void *GetEngineSingleton_003B6CF0(void);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern void *GetComponentStatusDescriptor(void);
extern void ComponentNotifyStatusChange(void *component, unsigned mode,
                                            unsigned requested_state);
void HealthApplySignedDelta(void *context, void *target, unsigned mode,
                               unsigned extra, float delta);
extern void *GetGlobalHealthDescriptor(void);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern uint8_t *ResolveHealthDescriptor(void *target);
extern void *GetHealthComponentType(void);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
void HealthNotifyModeZero(void *health, float current_hp);
extern void HealthTargetUpdate(void *target);
extern void *GetHealthParameterKey(void);
extern uint8_t *OrderedTreeLowerBound(void *tree, void *key);
float HealthClampCurrent(float value, float lower, float upper);
extern void *GetHealthCapabilityKey(void);
extern void *GetSecondaryComponentType(void);
extern void *GetHealthSharedRegistry(void);
extern int RegistryReadSignedShort(void *registry);
extern unsigned EngineGlobalModeByteIsZero(void *registry);
extern uint32_t GetHealthEngineFlags(void);
extern void *ObjectGetAllocatorContext(void *object);
extern void *AllocateTaggedBlock(uint32_t size,
                                    const void *type_tag,
                                    void *allocator_context);
extern const uint8_t HealthSecondaryAllocationTag;
void Health_StatusBitUpdate(void *health, uint32_t mask, unsigned enabled);
extern void *ResolveRelatedComponent(void *object);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *GetGlobalHealthDescriptor(void);
void HealthNotifyModeZero(void *health, float current_hp);
extern void *GetHealthSharedRegistry(void);
extern void *GetHealthThresholdParameters(void);
extern void HealthThresholdDispatch(void *registry, unsigned mode,
                                       const void *record);
static const uint8_t HealthThresholdRecord = 0;
unsigned HealthSecondaryStateAdvance(void *secondary,
                                        void *target,
                                        float input);
extern void *GetComponentStatusDescriptor(void);
extern void *GetStatusOwnerRegistry(void);
extern void ComponentNotifyStatusChange(void *component, unsigned mode,
                                            unsigned requested_state);
void *ComponentLookupStatusOwner(void *actor, void *descriptor);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
uint32_t DamagePacketBuildFlags(void *context);
float HealthRefreshParameterSelection(
    struct HealthParameterOwnerView *object,
    float hidden_scale);
void DamageOwner_AccumulateIndexedValues(struct StatusOwnerView *owner,
                                           uint32_t first_index,
                                           uint32_t second_index,
                                           float hidden_value);
void HealthComponentInitializeParameterLanes(void *health);
void HealthSecondaryStateInitialize(void *state);
void HealthSecondaryStateClear(void *state);
void HealthComponentRefreshState(void *health);
void HealthComponentInitialize(void *ignored, void *target);
void HealthOwnerStateUpdate(void *object, unsigned slot, unsigned active,
                               float value);
void HealthSharedOwnerSideEffect(void *context);
uint32_t HealthConditionSelectorAt(const void *selection, unsigned index);
void Health_StatusBitUpdate(void *health,
                              uint32_t mask,
                              unsigned enabled);
float HealthGetResolvedMaximum(void *ignored_context, void *target);
void *ComponentLookupStatusOwner(void *actor, void *descriptor);
float HealthClampCurrent(float value, float lower, float upper);
void HealthNotifyPositive(void *health, float amount);
void HealthNotifyNonPositive(void *health,
                                unsigned extra,
                                float current_hp);
void HealthNotifyModeZero(void *health, float current_hp);
float HealthSelectNotifyAndReadCurrent(void *status,
                                  unsigned mode,
                                  unsigned extra,
                                  float notification_value);
void HealthApplySignedDelta(void *context, void *target, unsigned mode,
                               unsigned extra, float delta);
unsigned HealthSecondaryStateAdvance(void *secondary,
                                        void *target,
                                        float input);
__attribute__((noinline)) void HealthComponentInitializeParameterLanes(void *health)
{
    struct HealthParameterOwnerView *target =
        *(struct HealthParameterOwnerView **)((uint8_t *)health + 0x30);
    uint8_t *entry = OrderedTreeLowerBound(
        &target->parameter_tree_anchor, GetHealthParameterKey());
    uint8_t *upper = (uint8_t *)target->parameter_tree_upper;
    uint8_t *record;
    uint8_t *link;
    if (entry == 0 || *(uint8_t **)entry == upper)
        return;
    record = *(uint8_t **)(*(uint8_t **)entry + 0x1c);
    if (record == 0)
        return;
    link = *(uint8_t **)(record + 0x1c);
    while (link != record + 0x18) {
        uint8_t *lane = *(uint8_t **)link;
        unsigned index = *(uint32_t *)(lane + 0x0c);
        uint32_t value_bits = *(uint32_t *)(lane + 0x10);
        if (index < 8u) {
            float value = *(float *)(lane + 0x10);
            *(float *)(health + 0x1a4 + index * 4u) = value;
            if (0xb7800000u >= value_bits) {
                float scaled = value * *(float *)(health + 0x180);
                *(float *)(health + 0x184 + index * 4u) =
                    HealthClampCurrent(scaled, 0.0f, scaled);
            }
        }
        link = *(uint8_t **)(link + 4);
    }
}
__attribute__((noinline)) void HealthComponentRefreshState(void *health)
{
    uint8_t *bytes = (uint8_t *)health;
    uint8_t *target = *(uint8_t **)(bytes + 0x30);
    uint8_t *entry;
    uint8_t *selected;
    uint8_t *upper;
    HealthComponentInitializeParameterLanes(health);
    *(uint32_t *)(bytes + 0x174) = 0;
    entry = OrderedTreeLowerBound(target + 0x1a4,
                                     GetHealthCapabilityKey());
    selected = entry != 0 ? *(uint8_t **)entry : 0;
    upper = *(uint8_t **)(target + 0x1a8);
    if (selected != upper && selected != 0) {
        selected = *(uint8_t **)(selected + 0x1c);
        if (selected != 0) {
            if (*(uint8_t *)(selected + 0xb9) == 0)
                Health_StatusBitUpdate(health, 0x100u, 1);
            if (*(uint8_t *)(selected + 0xba) == 0)
                Health_StatusBitUpdate(health, 0x8000u, 1);
        }
    }
    selected = *(uint8_t **)(target + 0x1e8);
    if (selected == 0) {
        entry = OrderedTreeLowerBound(target + 0x1a4,
                                         GetSecondaryComponentType());
        selected = entry != 0 ? *(uint8_t **)entry : 0;
        upper = *(uint8_t **)(target + 0x1a8);
        if (selected != upper && selected != 0) {
            selected = *(uint8_t **)entry;
            if (selected != 0) {
                *(void **)(selected + 0x1c) = target;
                *(uint8_t **)(target + 0x1e8) = selected;
            }
        }
    }
    if (selected != 0) {
        uint8_t *descriptor = *(uint8_t **)(selected + 0x20);
        void *registry = GetHealthSharedRegistry();
        int result = RegistryReadSignedShort(registry);
        unsigned class_id = *(uint32_t *)(descriptor) >> 28;
        Health_StatusBitUpdate(health, 1u, class_id == 1u);
        Health_StatusBitUpdate(health, 2u, class_id == 2u);
        Health_StatusBitUpdate(
            health, 4u, ((unsigned)result - 0x101u) < 0x11bu);
        Health_StatusBitUpdate(
            health, 0x20u,
            EngineGlobalModeByteIsZero(registry));
        if (*(void **)(bytes + 0x170) == 0 &&
            (*(uint32_t *)(bytes + 0x174) & 1u) != 0 &&
            (*(uint8_t *)((uint8_t *)GetHealthSharedRegistry() +
                          STATUS_SELECTOR_A) == 0 ||
             *(uint8_t *)((uint8_t *)GetHealthSharedRegistry() +
                          STATUS_SELECTOR_B) == 0) &&
            (GetHealthEngineFlags() & 4u) == 0 &&
            (*(uint32_t *)(selected + 0x20) & 0x0fff0000u) == 0) {
            void *allocator_context = ObjectGetAllocatorContext(target);
            void *state = AllocateTaggedBlock(
                0x20u, &HealthSecondaryAllocationTag, allocator_context);
            if (state != 0)
                HealthSecondaryStateClear(state);
            *(void **)(bytes + 0x170) = state;
            if (state != 0)
                HealthSecondaryStateInitialize(state);
        }
    }
    entry = OrderedTreeLowerBound(target + 0x1a4,
                                     GetHealthCapabilityKey());
    selected = entry != 0 ? *(uint8_t **)entry : 0;
    upper = *(uint8_t **)(target + 0x1a8);
    if (selected != upper && selected != 0) {
        selected = *(uint8_t **)(selected + 0x1c);
        if (selected != 0)
            *(uint32_t *)(bytes + 0x11c) =
                *(uint32_t *)(selected + 0xb4);
    }
}
__attribute__((noinline)) void HealthComponentInitialize(void *ignored, void *target)
{
    uint8_t *descriptor = ResolveHealthDescriptor(target);
    uint8_t *health;
    (void)ignored;
    if (descriptor == 0 || *(void **)(descriptor + 0x1c) == 0 ||
        *(void **)(descriptor + 0x20) == 0)
        return;
    health = *(uint8_t **)((uint8_t *)target + 0x208);
    if (health == 0) {
        uint8_t *entry = OrderedTreeLowerBoundByPointer(
            (uint8_t *)target + 0x1a4, GetHealthComponentType());
        uint8_t *selected = entry != 0 ? *(uint8_t **)entry : 0;
        uint8_t *upper = *(uint8_t **)((uint8_t *)target + 0x1a8);
        if (selected != upper) {
            if (entry != 0)
                selected = *(uint8_t **)entry;
            if (selected != 0) {
                *(void **)(selected + 0x34) = target;
                health = selected;
                *(uint8_t **)((uint8_t *)target + 0x208) = selected;
            }
        }
    }
    if (health != 0) {
        float scale = *(float *)(descriptor + 0x3c);
        float maximum = *(float *)(*(uint8_t **)(descriptor + 0x20) + 0xa8) *
                        scale;
        *(float *)(health + 0x17c) = maximum;
        HealthNotifyModeZero(health, maximum);
        *(float *)(health + 0x180) = scale;
        HealthComponentRefreshState(health);
    }
    HealthTargetUpdate(target);
}
static uint8_t *RefreshStatusLink(void *target)
{
    uint8_t *object = (uint8_t *)target;
    uint8_t *selected = *(uint8_t **)(object + 0x1f0);
    uint8_t *cursor;
    uint8_t *candidate;
    void *key;
    if (selected != 0)
        return selected;
    key = GetComponentStatusDescriptor();
    cursor = *(uint8_t **)(object + 0x1ac);
    candidate = object + 0x1a8;
    while (cursor[0x10] != 0) {
        uint8_t *node = cursor;
        if (*(uint32_t *)(node + 0x14) < (uint32_t)(uintptr_t)key)
            cursor = *(uint8_t **)(node + 0x0c);
        else
            cursor = *(uint8_t **)(node + 0x08);
        candidate = node;
    }
    if (candidate == object + 0x1a8 ||
        (uint32_t)(uintptr_t)key < *(uint32_t *)(candidate + 0x14))
        candidate = object + 0x1a8;
    selected = *(uint8_t **)candidate;
    if (selected != 0) {
        *(void **)(selected + 0x1c) = target;
        *(uint8_t **)(object + 0x1f0) = selected;
    }
    return selected;
}
__attribute__((noinline)) void Health_StatusBitUpdate(void *health,
                              uint32_t mask,
                              unsigned enabled)
{
    uint8_t *bytes = (uint8_t *)health;
    void *target = *(void **)(bytes + 0x30);
    uint8_t *linked;
    uint32_t flags = *(uint32_t *)(bytes + 0x174);
    if (enabled != 0)
        flags |= mask;
    else
        flags &= ~mask;
    *(uint32_t *)(bytes + 0x174) = flags;
    if ((mask & 0x40u) != 0) {
        linked = RefreshStatusLink(target);
        if (linked != 0) {
            if ((flags & 1u) != 0) {
                struct StatusOwnerView *owner =
                    (struct StatusOwnerView *)ComponentLookupStatusOwner(
                        GetStatusOwnerRegistry(), target);
                if (owner != 0 && owner->notification_gate_724 == 0)
                    linked = 0;
            }
            if (linked != 0)
                ComponentNotifyStatusChange(*(void **)(linked + 0x20), 0, 0);
        }
    }
    if ((mask & 0x80u) != 0) {
        linked = RefreshStatusLink(target);
        if (linked != 0) {
            uint8_t *linked_object = *(uint8_t **)(linked + 0x20);
            uint32_t linked_flags = *(uint32_t *)(linked_object + 0x30);
            if (((linked_flags >> 1) & 1u) != ((flags >> 7) & 1u))
                *(uint32_t *)(linked_object + 0x30) = linked_flags ^ 2u;
        }
    }
}
__attribute__((noinline)) float HealthGetResolvedMaximum(void *ignored_context, void *target)
{
    struct HealthStatusComponent *health;
    (void)ignored_context;
    health = (struct HealthStatusComponent *)ResolveRelatedComponent(target);
    return health->maximum_hp.value;
}
__attribute__((noinline)) float HealthClampCurrent(float value, float lower, float upper)
{
    float floor_value = value > lower ? value : lower;
    return floor_value < upper ? floor_value : upper;
}
__attribute__((noinline)) void HealthSecondaryAddOverflow_005D34B4(void *secondary_object,
                                              float scaled)
{
    struct HealthSecondaryStateView *secondary =
        (struct HealthSecondaryStateView *)secondary_object;
    if (scaled > 0.0f)
        secondary->overflow += scaled;
}
__attribute__((noinline)) void HealthNotifyPositive(void *health, float amount)
{
    struct HealthStatusComponent *component =
        (struct HealthStatusComponent *)health;
    float scaled = component->weak_rate * amount;
    uint32_t flags = component->flags;
    struct HealthSecondaryStateView *secondary =
        (struct HealthSecondaryStateView *)component->secondary;
    if (secondary != 0 && (flags & HEALTH_SECONDARY_ACTIVE) != 0) {
        HealthSecondaryAddOverflow_005D34B4(secondary, scaled);
        return;
    }
    component->current_hp.value = HealthClampCurrent(
        component->current_hp.value + scaled,
        (flags & HEALTH_MINIMUM_ONE) != 0 ? 1.0f : 0.0f,
        component->maximum_hp.value);
}
__attribute__((noinline)) void HealthNotifyNonPositive(void *health,
                                unsigned extra,
                                float current_hp)
{
    struct HealthStatusComponent *component =
        (struct HealthStatusComponent *)health;
    float scaled;
    float lower = 0.0f;
    void *secondary;
    if ((component->flags & HEALTH_NONPOSITIVE_GUARD_MASK) != 0 && extra == 0)
        return;
    scaled = component->weak_scale * current_hp;
    secondary = component->secondary;
    if (secondary != 0) {
        unsigned state = HealthSecondaryStateAdvance(
            secondary, component->target, current_hp);
        if (state != 3u)
            lower = 1.0f;
        if (state == HEALTH_SECONDARY_PHASE_ONE_STATE) {
            Health_StatusBitUpdate(health, HEALTH_SECONDARY_ACTIVE, 1);
            Health_StatusBitUpdate(health, HEALTH_SECONDARY_PHASE_ONE, 1);
        } else if (state == HEALTH_SECONDARY_PHASE_TWO_STATE) {
            Health_StatusBitUpdate(health, HEALTH_SECONDARY_ACTIVE, 1);
            Health_StatusBitUpdate(health, HEALTH_SECONDARY_PHASE_ONE, 0);
        }
    }
    if ((component->flags & HEALTH_MINIMUM_ONE) != 0)
        lower = 1.0f;
    component->current_hp.value = HealthClampCurrent(
        component->current_hp.value + scaled, lower,
        component->maximum_hp.value);
}
__attribute__((noinline)) void HealthNotifyModeZero(void *health, float current_hp)
{
    struct HealthStatusComponent *component =
        (struct HealthStatusComponent *)health;
    component->current_hp.value = HealthClampCurrent(
        current_hp, 0.0f, component->maximum_hp.value);
}
__attribute__((noinline)) float HealthSelectNotifyAndReadCurrent(void *status,
                                  unsigned mode,
                                  unsigned extra,
                                  float notification_value)
{
    struct ActorObjectView *object =
        (struct ActorObjectView *)status;
    uint8_t *selected = (uint8_t *)object->cached_health_component;
    if (selected == 0) {
        uint8_t *cursor = (uint8_t *)object->component_tree_root;
        uint8_t *candidate = (uint8_t *)&object->component_tree_upper;
        void *key = GetGlobalHealthDescriptor();
        while (cursor[0x10] != 0) {
            uint8_t *node = cursor;
            if (*(uint32_t *)(node + 0x14) < (uint32_t)(uintptr_t)key) {
                cursor = *(uint8_t **)(node + 0x0c);
            } else {
                cursor = *(uint8_t **)(node + 0x08);
                candidate = node;
            }
        }
        if (candidate == (uint8_t *)&object->component_tree_upper ||
            *(uint32_t *)(candidate + 0x14) <=
                (uint32_t)(uintptr_t)key)
            candidate = (uint8_t *)&object->component_tree_upper;
        selected = *(uint8_t **)candidate;
        if (selected == 0)
            return 0.0f;
        *(void **)(selected + 0x34) = status;
        object->cached_health_component = selected;
    }
    if (mode == 0)
        HealthNotifyModeZero(selected, notification_value);
    else if (notification_value <= 0.0f)
        HealthNotifyNonPositive(selected, extra, notification_value);
    else
        HealthNotifyPositive(selected, notification_value);
    return ((struct HealthStatusComponent *)selected)->current_hp.value;
}
__attribute__((noinline)) void HealthApplySignedDelta(void *context, void *target, unsigned mode,
                               unsigned extra, float delta)
{
    struct StatusDescriptorView *resolved;
    struct HealthStatusComponent *component;
    uint32_t descriptor_word;
    float maximum;
    float current;
    float current_ratio;
    float updated_ratio;
    if (mode == 0u) {
        component = (struct HealthStatusComponent *)
            ResolveRelatedComponent(target);
        if (component != 0 && component->current_hp.value == delta)
            return;
    }
    resolved = (struct StatusDescriptorView *)ResolveStatusDescriptor(target);
    if (resolved == 0)
        return;
    descriptor_word = resolved->tagged_handle;
    component = (struct HealthStatusComponent *)ResolveRelatedComponent(target);
    maximum = component->maximum_hp.value;
    current = component->current_hp.value;
    current_ratio = current / maximum;
    updated_ratio = HealthSelectNotifyAndReadCurrent(target, mode, extra, delta) /
                    maximum;
    if ((descriptor_word >> 28) != 1u)
        return;
    if (DamagePacketBuildFlags(context) == descriptor_word)
        HealthSharedOwnerSideEffect(GetHealthSharedRegistry());
    if (*(uint8_t *)((uint8_t *)context + STATUS_SELECTOR_B) != 0) {
        uint8_t *engine = (uint8_t *)GetEngineSingleton_003B6CF0();
        if (*(uint8_t *)(engine + 0x1f14) == 6u) {
            uint8_t *parameters = (uint8_t *)GetHealthThresholdParameters();
            float threshold = *(float *)(parameters + 0xc8);
            if (updated_ratio < threshold && current_ratio >= threshold) {
                uint32_t selected = HealthConditionSelectorAt(
                    *(void **)((uint8_t *)context + 0x1240), 0);
                if (selected == descriptor_word) {
                    HealthThresholdDispatch(GetHealthSharedRegistry(),
                                               3, &HealthThresholdRecord);
                } else {
                    selected = HealthConditionSelectorAt(
                        *(void **)((uint8_t *)context + 0x1240), 1);
                    if (selected == descriptor_word)
                        HealthThresholdDispatch(
                            GetHealthSharedRegistry(), 4,
                            &HealthThresholdRecord);
                }
            }
        }
    }
    HealthOwnerStateUpdate(
        GetHealthSharedRegistry(), resolved->owner_slot,
        (component->active_mask & 0x800u) >> 11, updated_ratio);
}
