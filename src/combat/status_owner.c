#include <stddef.h>
#include <stdint.h>
#include "actor_combat_views.h"
extern int EngineStatusModeIsType5(void);
extern uint32_t ResourceTableLookup(uint32_t *handle);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *GetStatusOwnerRegistry(void);
extern void *GetSharedRegistrySingleton(void);
extern void *ResolveStatusDescriptor(void *descriptor);
extern uint32_t ResourceTableLookup(uint32_t *handle);
extern void StatusOwner_TightenThreshold(void *owner, uint32_t key,
                                            float threshold);
extern uint32_t DamagePacket_BuildFlags(void *context);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *GetSharedRegistrySingleton(void);
extern void StatusOwnerCleanupZero(void);
extern uint32_t StatusOwnerBuildHandleVariant6(void *source,
                                                uint32_t key);
extern uint32_t StatusOwnerBuildHandleOther(void *source,
                                             uint32_t key);
extern void SharedRegistryRelease(void *registry, uint32_t resource);
extern void GenericResourceState_UpdateMask(void *state,
                                            uint32_t active_mask);
extern uint32_t ResourceTableLookup(uint32_t *handle);
extern void *GetStatusOwnerRegistry(void);
extern void *GetStatusOwnerBaseSingleton(void);
extern void *StatusLazySingleton0054EFA8(void);
extern void *ComponentType_GetGlobalDescriptor(void);
extern void *OrderedTree_LowerBoundByPointer_004C5D3C(void *tree, void *key);
extern void *OrderedTree_LowerBoundStatusHandle(void *tree, uint32_t key);
extern void *CachedComponent_ResolveClass1(void *registry, void *object);
extern int StatusMaskQuery_005C7054(void *state, uint32_t key,
                                    unsigned mode);
extern void *StatusModeRecordLookup_0054E208(void *object);
void *ComponentLookupStatusOwner(void *actor, void *descriptor);
void StatusOwnerStoreValueAndActive(void *owner, uint32_t value,
                                       int active);
void StatusOwnerStorePendingStateIfNotType5(void *owner,
                                                void *pending,
                                                float hidden_value);
void StatusOwnerIncrementPendingCountIfNotType5(void *owner);
void StatusOwnerClearFlags(void *owner, uint32_t mask, float hidden_value);
void StatusOwnerTransitionFlags(void *owner, float value0, float value1);
void StatusOwnerTransitionTo800(void *owner, float value0, float value1);
void *StatusOwnerIndexAddress(void *base, int8_t index);
void *StatusOwnerFindByHandle(void *base, uint32_t handle);
unsigned StatusOwnerIndexByHandle(void *base, uint32_t handle);
unsigned StatusOwnerIndexByObject(void *actor, void *owner);
unsigned StatusOwnerIndexInTable_005B3158(void *table, void *owner);
uint8_t StatusOwnerTableByte(void *registry, unsigned index);
int StatusOwnerTableSignedCode(void *registry, unsigned index);
void StatusHitIncrementOwnerChannel(void *counter_table,
                                        unsigned channel,
                                        void *descriptor);
void DamageOwner_AccumulateIndexedValues(struct StatusOwnerView *owner,
                                           uint32_t first_index,
                                           uint32_t second_index,
                                           float hidden_value);
int StatusDescriptorClassNibble(void *descriptor);
void StatusOwnerCleanup(void *registry, unsigned owner_index);
void StatusOwnerStatePublish(void *object, uint32_t active_mask);
void GenericResourceState_UpdateMask(void *state, uint32_t active_mask);
void *StatusDescriptorOwnerBase(void *descriptor);
void *StatusOwnerIndexedBase(void *ignored, unsigned index);
void *ComponentLookupStatusOwner(void *actor, void *descriptor);
void StatusOwner_TightenThreshold(void *owner, uint32_t key, float threshold);
__attribute__((noinline)) int StatusMaskQuery_005C7054(void *state, uint32_t key, unsigned mode)
{
    uint8_t *bytes = (uint8_t *)state;
    uint8_t *node = (uint8_t *)OrderedTree_LowerBoundStatusHandle(
        bytes + 0x8u, key);
    uint32_t candidate = node != 0 ? *(uint32_t *)node : 0u;
    uint32_t sentinel = *(uint32_t *)(bytes + 0xcu);
    uint8_t *record;
    if (candidate == sentinel)
        return 0;
    record = node != 0 ? *(uint8_t **)node : 0;
    return record != 0 &&
           ((*(uint32_t *)(record + 0x30u) &
             (1u << (mode & 0xffu))) != 0);
}
enum StatusRuntimeMaskBits {
    STATUS_RUNTIME_MASK_BASE = 0x00000fffu,
    STATUS_RUNTIME_MASK_QUERY_0 = 0x00001000u,
    STATUS_RUNTIME_MASK_QUERY_1 = 0x00002000u,
    STATUS_RUNTIME_MASK_OWNER_1000 = 0x00004000u,
    STATUS_RUNTIME_MASK_OWNER_2000 = 0x00008000u,
    STATUS_RUNTIME_MASK_DESCRIPTOR_DISABLED = 0x00010000u,
    STATUS_RUNTIME_MASK_OWNER_04000000 = 0x00020000u,
    STATUS_RUNTIME_MASK_OWNER_AD8_40 = 0x00040000u,
    STATUS_RUNTIME_MASK_OWNER_AD8_80 = 0x00080000u,
    STATUS_RUNTIME_MASK_MODE_RECORD = 0x00100000u,
    STATUS_RUNTIME_MASK_OWNER_AD8_200 = 0x00200000u,
    STATUS_RUNTIME_MASK_COMPONENT_7A_04 = 0x00400000u
};
__attribute__((noinline)) uint32_t StatusComponent_BuildRuntimeMaskBody_005B8C4C(void *singleton,
                                                       void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    struct ActorObjectView *actor = (struct ActorObjectView *)object;
    void **candidate;
    struct HealthStatusComponent *selected;
    void *component;
    struct StatusDescriptorView *descriptor;
    struct StatusOwnerView *owner;
    uint32_t mask;
    candidate = (void **)OrderedTree_LowerBoundByPointer_004C5D3C(
        &actor->component_tree_anchor, ComponentType_GetGlobalDescriptor());
    selected = candidate != 0
        ? (struct HealthStatusComponent *)*candidate : 0;
    if ((void *)selected == actor->component_tree_upper)
        selected = 0;
    mask = selected->active_mask & STATUS_RUNTIME_MASK_BASE;
    component = CachedComponent_ResolveClass1(singleton, object);
    descriptor = (struct StatusDescriptorView *)ResolveStatusDescriptor(object);
    if ((descriptor->tagged_handle >> 28) == 1u) {
        owner = (struct StatusOwnerView *)StatusOwnerIndexAddress(
            bytes + 0xb3f8, (int8_t)descriptor->owner_slot);
        if (owner != 0) {
            void *mode_record = StatusModeRecordLookup_0054E208(object);
            uint32_t descriptor_flags = *(uint32_t *)
                (*(void **)((uint8_t *)mode_record + 0x20) + 0x38);
            if (StatusMaskQuery_005C7054(
                    bytes + 0xf98c, descriptor->tagged_handle, 0) == 0)
                mask |= STATUS_RUNTIME_MASK_QUERY_0;
            if (StatusMaskQuery_005C7054(
                    bytes + 0xf98c, descriptor->tagged_handle, 1) == 0)
                mask |= STATUS_RUNTIME_MASK_QUERY_1;
            if ((owner->flags_478 & 0x1000u) != 0)
                mask |= STATUS_RUNTIME_MASK_OWNER_1000;
            if ((owner->flags_478 & 0x2000u) != 0)
                mask |= STATUS_RUNTIME_MASK_OWNER_2000;
            if ((owner->flags_478 & 0x04000000u) != 0)
                mask |= STATUS_RUNTIME_MASK_OWNER_04000000;
            if ((descriptor_flags & 1u) == 0)
                mask |= STATUS_RUNTIME_MASK_DESCRIPTOR_DISABLED;
            if ((owner->flags_ad8 & 0x40u) != 0)
                mask |= STATUS_RUNTIME_MASK_OWNER_AD8_40;
            if ((owner->flags_ad8 & 0x80u) != 0)
                mask |= STATUS_RUNTIME_MASK_OWNER_AD8_80;
            if ((*(uint32_t *)(*(void **)((uint8_t *)mode_record + 0x20) +
                               0x30) & 1u) != 0)
                mask |= STATUS_RUNTIME_MASK_MODE_RECORD;
            if ((owner->flags_ad8 & 0x200u) != 0)
                mask |= STATUS_RUNTIME_MASK_OWNER_AD8_200;
            if ((*(uint8_t *)((uint8_t *)component + 0x7a) & 4u) != 0)
                mask |= STATUS_RUNTIME_MASK_COMPONENT_7A_04;
        }
    }
    *(uint32_t *)((uint8_t *)component + 0x60) = mask;
    return mask;
}
__attribute__((noinline)) uint32_t StatusComponent_BuildRuntimeMask(void *object)
{
    void **singleton_cache = (void **)(uintptr_t)0x00D63578u;
    if (*singleton_cache == 0)
        *singleton_cache = StatusLazySingleton0054EFA8();
    return StatusComponent_BuildRuntimeMaskBody_005B8C4C(*singleton_cache,
                                                          object);
}
__attribute__((noinline)) void StatusOwnerStoreValueAndActive(void *owner, uint32_t value,
                                       int active)
{
    struct StatusOwnerView *record = (struct StatusOwnerView *)owner;
    uint32_t flags = record->flags_088;
    if ((flags & 0x100u) != 0)
        return;
    record->value_090 = value;
    if (active != 0)
        flags |= 0x100u;
    else
        flags &= ~0x100u;
    record->flags_088 = flags;
}
__attribute__((noinline)) void StatusOwnerStorePendingStateIfNotType5(void *owner,
                                                void *pending,
                                                float hidden_value)
{
    struct StatusOwnerView *record = (struct StatusOwnerView *)owner;
    if (!EngineStatusModeIsType5()) {
        record->pending_state = pending;
        record->pending_value = hidden_value;
    }
}
__attribute__((noinline)) void StatusOwnerIncrementPendingCountIfNotType5(void *owner)
{
    struct StatusOwnerView *record = (struct StatusOwnerView *)owner;
    if (!EngineStatusModeIsType5())
        ++record->pending_count;
}
__attribute__((noinline)) void StatusOwnerClearFlags(void *owner, uint32_t mask, float hidden_value)
{
    struct StatusOwnerView *record = (struct StatusOwnerView *)owner;
    uint16_t flags = record->status_flags;
    if ((mask & ~(uint32_t)flags) != 0)
        return;
    record->status_flags = (uint16_t)(flags & ~(uint16_t)mask);
    record->parameter_d4[0] = *(const float *)(uintptr_t)0x00dc249cu;
    record->parameter_d4[1] = *(const float *)(uintptr_t)0x00dc24a0u;
    record->parameter_d4[2] = *(const float *)(uintptr_t)0x00dc24a4u;
    record->parameter_e0[0] = *(const float *)(uintptr_t)0x00d4de24u;
    record->parameter_e0[1] = *(const float *)(uintptr_t)0x00d4de28u;
    record->parameter_e8 = hidden_value;
}
__attribute__((noinline)) void StatusOwnerTransitionFlags(void *owner, float value0, float value1)
{
    struct StatusOwnerView *record = (struct StatusOwnerView *)owner;
    uint16_t flags = record->status_flags;
    if ((flags & 0x800u) != 0) {
        const uint32_t *const defaults_d4 =
            (const uint32_t *)(uintptr_t)0x00dc249cu;
        const uint32_t *const defaults_e0 =
            (const uint32_t *)(uintptr_t)0x00d4de24u;
        uint32_t *const lanes_d4 = (uint32_t *)record->parameter_d4;
        uint32_t *const lanes_e0 = (uint32_t *)record->parameter_e0;
        record->status_flags = (uint16_t)(flags & ~0x800u);
        lanes_d4[0] = defaults_d4[0];
        lanes_d4[1] = defaults_d4[1];
        lanes_d4[2] = defaults_d4[2];
        lanes_e0[0] = defaults_e0[0];
        lanes_e0[1] = defaults_e0[1];
        record->parameter_e8 = 0.0f;
    }
    record->status_flags = (uint16_t)(record->status_flags | 0x1000u);
    record->parameter_e0[0] = value0;
    record->parameter_e0[1] = value1;
    record->parameter_e8 = 0.0f;
}
__attribute__((noinline)) void StatusOwnerTransitionTo800(void *owner, float value0, float value1)
{
    struct StatusOwnerView *record = (struct StatusOwnerView *)owner;
    {
        const uint16_t flags = record->status_flags;
        const uint16_t reset_mask =
            (uint16_t)(0x1000u & (uint16_t)~flags);
        if (reset_mask == 0)
            goto reset_defaults;
    }
publish_values:
    record->status_flags = (uint16_t)(record->status_flags | 0x800u);
    record->parameter_e0[0] = value0;
    record->parameter_e0[1] = value1;
    record->parameter_e8 = 0.0f;
    return;
reset_defaults:
    {
        const uint32_t *const defaults_d4 =
            (const uint32_t *)(uintptr_t)0x00dc249cu;
        const uint32_t *const defaults_e0 =
            (const uint32_t *)(uintptr_t)0x00d4de24u;
        uint32_t *const lanes_d4 = (uint32_t *)record->parameter_d4;
        uint32_t *const lanes_e0 = (uint32_t *)record->parameter_e0;
        record->status_flags = (uint16_t)(record->status_flags & ~0x1000u);
        lanes_d4[0] = defaults_d4[0];
        lanes_d4[1] = defaults_d4[1];
        lanes_d4[2] = defaults_d4[2];
        lanes_e0[0] = defaults_e0[0];
        lanes_e0[1] = defaults_e0[1];
        record->parameter_e8 = 0.0f;
    }
    goto publish_values;
}
__attribute__((noinline)) void *Object_GetB3F8Subobject(void *object)
{
    return (uint8_t *)object + 0xb3f8;
}
__attribute__((noinline)) void *StatusOwner_FindByHandleFromObject(void *object)
{
    return (uint8_t *)object + 0xb3f8;
}
__attribute__((noinline)) void *StatusOwnerIndexAddress(void *base, int8_t index)
{
    return (uint8_t *)base + (int32_t)index * 0xb98;
}
__attribute__((noinline)) void *StatusOwnerFindByHandle(void *base, uint32_t handle)
{
    unsigned index;
    for (index = 0; index < 6u; ++index) {
        void *record = StatusOwnerIndexAddress(base, (int8_t)index);
        if (*(uint32_t *)record == handle)
            return record;
    }
    return base;
}
__attribute__((noinline)) unsigned StatusOwnerIndexByHandle(void *base, uint32_t handle)
{
    unsigned index;
    for (index = 0; index < 6u; ++index) {
        if (*(uint32_t *)((uint8_t *)base + index * 0xb98u) == handle)
            return index;
    }
    return 0;
}
__attribute__((noinline)) unsigned StatusOwnerIndexInTable_005B3158(void *table,
                                                                   void *owner)
{
    uint8_t *bytes = (uint8_t *)table;
    unsigned index;
    for (index = 0; index < 6; ++index) {
        if (*(void **)(bytes + index * 0xb98u) == owner)
            return index;
    }
    return 0;
}
__attribute__((noinline)) unsigned StatusOwnerIndexByObject(void *actor, void *owner)
{
    return StatusOwnerIndexInTable_005B3158((uint8_t *)actor + 0xb3f8, owner);
}
__attribute__((noinline)) uint8_t StatusOwnerTableByte(void *registry, unsigned index)
{
    uint8_t *records = *(uint8_t **)((uint8_t *)registry + 0xe4);
    return records[index * 0x1cu + 0x0c];
}
__attribute__((noinline)) int StatusOwnerTableSignedCode(void *registry, unsigned index)
{
    uint8_t *records = *(uint8_t **)((uint8_t *)registry + 0xe4);
    return *(int8_t *)(records + index * 0x1cu + 0x0d);
}
__attribute__((noinline)) void StatusHitIncrementOwnerChannel(void *counter_table,
                                        unsigned channel,
                                        void *descriptor)
{
    struct StatusOwnerView *owner =
        (struct StatusOwnerView *)counter_table;
    uint8_t *registry = (uint8_t *)GetStatusOwnerRegistry();
    unsigned owner_index = StatusOwnerIndexByObject(registry, descriptor);
    if (registry[STATUS_SELECTOR_A] != 0 &&
        registry[STATUS_SELECTOR_B] != 0)
        owner_index = (unsigned)StatusOwnerTableByte(registry, owner_index) - 1u;
    ++owner->counts[channel][owner_index];
}
__attribute__((noinline)) int StatusDescriptorClassNibble(void *descriptor)
{
    uint8_t *resolved = (uint8_t *)ResolveStatusDescriptor(descriptor);
    return resolved != 0 ? (int)(*(uint32_t *)(resolved + 0x20) >> 28) : 0;
}
__attribute__((noinline)) void StatusOwnerCleanup(void *registry, unsigned owner_index)
{
    uint8_t *bytes = (uint8_t *)registry;
    uint8_t *record = bytes + 0x46b0u + owner_index * 8u;
    uint32_t old_handle = *(uint32_t *)(record + 4);
    uint32_t handle;
    uint32_t resource;
    void *shared;
    if (owner_index == 0u)
        StatusOwnerCleanupZero();
    *(uint16_t *)record = 0xffffu;
    *(uint32_t *)(record + 4) = 0;
    if ((old_handle >> 28) == 6u)
        handle = StatusOwnerBuildHandleVariant6(bytes + 0x171acu, old_handle);
    else
        handle = StatusOwnerBuildHandleOther(bytes + 0xf98cu, old_handle);
    resource = ResourceTableLookup(&handle);
    if (resource == 0)
        return;
    shared = GetSharedRegistrySingleton();
    SharedRegistryRelease(shared, resource);
}
__attribute__((noinline)) void StatusOwnerStatePublish(void *object, uint32_t active_mask)
{
    uint8_t *state = *(uint8_t **)((uint8_t *)object + 0x140u);
    if (state != 0)
        GenericResourceState_UpdateMask(state + 0x134u, active_mask);
}
__attribute__((noinline)) void *StatusDescriptorOwnerBase(void *descriptor)
{
    uint8_t *resolved = (uint8_t *)ResolveStatusDescriptor(descriptor);
    uint8_t *base = (uint8_t *)GetStatusOwnerBaseSingleton();
    if (resolved != 0 && (*(uint32_t *)(resolved + 0x20) >> 28) == 1u)
        base += *(uint8_t *)(resolved + 0x2c) * 0x370u;
    return base;
}
__attribute__((noinline)) void *StatusOwnerIndexedBase(void *ignored, unsigned index)
{
    (void)ignored;
    return (uint8_t *)GetStatusOwnerBaseSingleton() + index * 0x370u;
}
__attribute__((noinline)) void *ComponentLookupStatusOwner(void *actor, void *descriptor)
{
    struct StatusDescriptorView *component =
        (struct StatusDescriptorView *)ResolveStatusDescriptor(descriptor);
    uint32_t class_word = component->tagged_handle;
    unsigned index;
    if ((class_word >> 28) != 1u)
        return 0;
    index = component->owner_slot;
    return StatusOwnerIndexAddress((uint8_t *)actor + 0xb3f8,
                                      (int8_t)index);
}
__attribute__((noinline)) void StatusOwner_TightenThreshold(void *owner, uint32_t key, float threshold)
{
    uint8_t *bytes = (uint8_t *)owner;
    uint8_t **link = *(uint8_t ***)(bytes + 0x464);
    uint8_t **sentinel = *(uint8_t ***)(bytes + 0x460);
    while (link != sentinel) {
        uint8_t *entry = *link;
        uint8_t *typed = *(uint8_t **)(entry + 0x10);
        if (typed[0x78] == 0x14 &&
            *(uint32_t *)(typed + 0x7c) == key &&
            *(float *)(entry + 0x14) > threshold)
            *(float *)(entry + 0x14) = threshold;
        link = *(uint8_t ***)(link + 1);
    }
}
__attribute__((noinline)) void *StatusOwner_FindForDamageContext_00502850(
    void *context)
{
    uint32_t handle = DamagePacket_BuildFlags(context);
    return StatusOwnerFindByHandle((uint8_t *)context + 0xb3f8, handle);
}
