#include <stddef.h>
#include <stdint.h>
#include "actor_combat_views.h"
extern void StatusRuntimeRecord_SourceLinkHook(void *source, void *record);
extern void *ResourceTableLookup(uint32_t *handle);
extern void StatusTransformPayloadBuild(uint32_t output[3], void *source,
                                           void *resource,
                                           void *profile_object,
                                           void *transform_source);
extern void StatusResourceDispatch_004849D4(void *dispatcher, void *resource,
                                                unsigned mode);
extern void *ResolveStatusDescriptor(void *target);
extern int StatusContext_SetFlags(void *context, uint32_t key,
                                  uint32_t mask);
extern void *ResolveRelatedComponent(void *object);
extern void HealthNotifyModeZero(void *health, float current_value);
extern void Health_StatusBitUpdate(void *health, uint32_t mask,
                                   unsigned enabled);
extern void FloatQuantizeResidualGuard(uint32_t *pair, unsigned count);
extern void *ActorMovementEngineGet004C59C0(void);
extern void *StatusParameterGlobalState_Get(void);
extern void *GetStatusCapabilityKey(void);
extern void *GetStatusBacklinkKey(void);
extern void *OrderedTreeLowerBoundByPointer(void *tree, void *key);
extern void *OrderedTree_FindPayloadByPointer_00326C6C(void *tree,
                                                       void *key);
extern void *ResolveCachedComponent_1EC(void *target);
extern void *StatusEventRecordResolve(void *target);
extern void *Engine_StatusDescriptorRegistry_Get(void);
extern void Engine_StoreQuantizedPair(uint32_t *pair);
extern int StatusParameter_GenericRecordInitialize(void *payload);
extern void OrderedTree_UnlinkNode_003D40E0(void *node, void *replacement);
extern void HealthParameter_RefreshSelection(void *parameter_owner);
extern void StatusQueueAttachParameterRecord(void *queue, void *record,
                                              uint32_t mode);
extern void *Engine_LazySingletonGetter_0054EFA8(void);
extern void *StatusOwnerIndexAddress(void *base, int8_t index);
extern void *Engine_LazySingletonGetter_003B6C98(void);
extern int Engine_ObjectStatePredicate(void *object);
extern void Engine_ComponentEnsureOrCreate_004B71DC(void *record,
                                                       unsigned mode);
extern void *ComponentType_GetGlobalDescriptor(void);
extern void Engine_NoopCallback_00434BAC(void *component, int code);
static void **const StatusParameterGlobalSingleton =
    (void **)(uintptr_t)0x00d635f8u;
__attribute__((noinline)) void *StatusParameter_SelectPublishedSlot(void *parameter)
{
    static void **const singleton_slot = (void **)(uintptr_t)0x005c2b24u;
    void *object = *singleton_slot;
    if (object == 0) {
        object = Engine_LazySingletonGetter_003B6C98();
        *singleton_slot = object;
    }
    return (uint8_t *)parameter +
           (Engine_ObjectStatePredicate(object) ? 0x1a8u : 0x17cu);
}
__attribute__((noinline)) void *StatusResource_SelectActionSlot(void *record)
{
    static void **const singleton_slot = (void **)(uintptr_t)0x00445458u;
    void *object = *singleton_slot;
    if (object == 0) {
        object = Engine_LazySingletonGetter_003B6C98();
        *singleton_slot = object;
    }
    return (uint8_t *)record +
           (Engine_ObjectStatePredicate(object) ? 0x148u : 0x11cu);
}
__attribute__((noinline)) void StatusParameter_EnableComponentFlag40(void *record)
{
    uint8_t *component;
    Engine_ComponentEnsureOrCreate_004B71DC(record, 1u);
    component = *(uint8_t **)((uint8_t *)record + 0x38u);
    *(uint32_t *)(component + 0x98u) |= 0x40u;
}
static uint8_t *StatusParameter_ResolveCachedDescriptor(void *target)
{
    uint8_t *target_bytes = (uint8_t *)target;
    uint8_t *selected = *(uint8_t **)(target_bytes + 0x208u);
    if (selected == 0) {
        uint8_t *cursor = *(uint8_t **)(target_bytes + 0x1acu);
        uint8_t *candidate = target_bytes + 0x1a8u;
        uint32_t key = (uint32_t)(uintptr_t)ComponentType_GetGlobalDescriptor();
        while (cursor[0x10u] != 0u) {
            uint8_t *node = cursor;
            if (*(uint32_t *)(node + 0x14u) < key)
                cursor = *(uint8_t **)(node + 0x0cu);
            else {
                candidate = node;
                cursor = *(uint8_t **)(node + 0x08u);
            }
        }
        if (candidate == target_bytes + 0x1a8u ||
            *(uint32_t *)(candidate + 0x14u) <= key)
            candidate = target_bytes + 0x1a8u;
        selected = *(uint8_t **)candidate;
        if (selected != 0) {
            *(void **)(selected + 0x34u) = target;
            *(uint8_t **)(target_bytes + 0x208u) = selected;
        }
    }
    return selected;
}
__attribute__((noinline)) char StatusParameter_ResolveAndPublishFactors(uint8_t output[16],
                                               const uint8_t *parameter,
                                               void *target)
{
    static const unsigned subrecord_offsets[8] = {
        0x78u, 0x88u, 0x98u, 0xa8u,
        0xb8u, 0xc8u, 0xd8u, 0xe8u
    };
    static const int8_t output_slots[4] = { 0, 0, 1, 1 };
    static const int8_t output_codes[4] = { 1, 0, 1, 0 };
    float factors[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    uint8_t active[4] = { 0, 0, 0, 0 };
    uint8_t found_factor = 0;
    uint8_t *selected;
    int return_code = 0;
    unsigned index;
    for (index = 0; index < 8u; ++index) {
        const uint8_t *subrecord = parameter + subrecord_offsets[index];
        unsigned lane;
        if (subrecord[0] == 0x1au)
            lane = subrecord[8] == 0u ? 1u : 0u;
        else if (subrecord[0] == 0x1bu)
            lane = subrecord[8] == 0u ? 3u : 2u;
        else
            continue;
        found_factor = 1u;
        active[lane] = 1u;
        factors[lane] *= *(const float *)(subrecord + 4u);
    }
    if (found_factor == 0u)
        return 0;
    selected = StatusParameter_ResolveCachedDescriptor(target);
    if (selected == 0)
        return 0;
    *(uint8_t *)(output + 0u) = 0;
    *(float *)(output + 4u) = 1.0f;
    *(uint8_t *)(output + 8u) = 0;
    *(float *)(output + 12u) = 1.0f;
    for (index = 0; index < 4u; ++index) {
        unsigned slot;
        if (active[index] == 0u)
            continue;
        slot = (unsigned)output_slots[index];
        return_code = output_codes[index];
        Engine_NoopCallback_00434BAC(selected, return_code);
        *(float *)(output + slot * 8u + 4u) *= factors[index];
        *(uint8_t *)(output + slot * 8u) = 1u;
    }
    return (char)return_code;
}
enum StatusParameterContextMask {
    STATUS_CONTEXT_PARAMETER_ACTIVE = 0x00000400u,
    STATUS_CONTEXT_PARAMETER_SOURCE = 0x00002000u,
    STATUS_CONTEXT_PARAMETER_SELECTED = 0x00004000u,
    STATUS_CONTEXT_PARAMETER_RUNTIME = 0x00010000u
};
struct StatusRuntimeRecordView {
    void *vtable_000;
    void *link_next_004;
    void *link_prev_008;
    void *link_owner_00c;
    void *source_010;
    uint32_t state_014;
    float scalar_018;
    uint32_t payload_01c[4];
};
void StatusParameter_InitializeGeneratedQueueTail(
    void *record, const void *parameter, float selected_value,
    float selected_product)
{
    uint8_t *bytes = (uint8_t *)record;
    const uint8_t *source = (const uint8_t *)parameter;
    float scaled = selected_value * *(const float *)(source + 0x5cu);
    bytes[0x10u] = 0;
    bytes[0x78u] = 0x19u;
    *(uint32_t *)(bytes + 0x7cu) = *(const uint32_t *)(source + 0x58u);
    bytes[0x88u] = 1;
    *(float *)(bytes + 0x8cu) = scaled;
    *(float *)(bytes + 0x90u) = scaled;
    *(float *)(bytes + 0x94u) = selected_product;
    bytes[0x98u] = 0x1du;
    *(uint32_t *)(bytes + 0x9cu) = *(const uint32_t *)(source + 0x68u);
    bytes[0xa8u] = 0x20u;
    bytes[0xb8u] = 0x20u;
    bytes[0xc8u] = 0x20u;
    bytes[0xd8u] = 0x20u;
    bytes[0xe8u] = 0x20u;
    *(uint8_t *)(bytes + 0x104u) = 1;
    *(float *)(bytes + 0x108u) = 0.0f;
    *(float *)(bytes + 0x10cu) = 16.0f;
    *(float *)(bytes + 0x110u) = 0.0f;
    *(float *)(bytes + 0x114u) = 0.0f;
    *(float *)(bytes + 0x118u) = 23.0f;
    *(float *)(bytes + 0x11cu) = 20.0f;
    *(float *)(bytes + 0x120u) = -1.0f;
}
__attribute__((noinline)) void StatusParameterApplyResourceTransform(void *source, void *resource,
                                             void *descriptor)
{
    uint32_t handle = *(uint32_t *)((uint8_t *)descriptor + 0x24u);
    uint8_t *resource_bytes = (uint8_t *)resource;
    uint8_t *descriptor_bytes = (uint8_t *)descriptor;
    void *resolved = ResourceTableLookup(&handle);
    uint32_t payload[3];
    if ((descriptor_bytes[0x38u] & 1u) != 0u || resolved == 0 ||
        (resource_bytes[0x89u] & 2u) != 0u)
        return;
    resource_bytes[0x89u] |= 8u;
    *(uint32_t *)(resource_bytes + 0x120u) =
        *(uint32_t *)((uint8_t *)resolved + 0x12cu);
    StatusTransformPayloadBuild(payload, source, resource, 0u,
                                descriptor_bytes + 0x2cu);
    *(uint32_t *)(resource_bytes + 0x124u) = payload[0];
    *(uint32_t *)(resource_bytes + 0x128u) = payload[1];
    *(uint32_t *)(resource_bytes + 0x12cu) = payload[2];
    StatusResourceDispatch_004849D4(
        *(void **)((uint8_t *)source + 0x0cu), resource, 3u);
}
typedef char kiu_sa_status_parameter_modes_1[(sizeof(struct StatusRuntimeRecordView) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_parameter_modes_2[(offsetof(struct StatusRuntimeRecordView, payload_01c) == 0x1c) ? 1 : -1] __attribute__((unused));
extern void GenericResourceState_UpdateMask(void *state,
                                            uint32_t active_mask);
extern void GenericResourceStateInterpolate(void *state, unsigned mode);
struct StatusRuntimeRecordView *StatusRuntimeRecord_Initialize(
    struct StatusRuntimeRecordView *record, void *source,
    const uint32_t payload[4]);
float Float_ClampScaledUnit(const struct UnitScaleRecordView *record,
                            float hidden_scale);
void StatusParameter_ApplyDescriptorFlags(
    struct StatusParameterSelectionRecordView *selected,
    const struct StatusParameterDescriptorOptionsView *descriptor,
    uint32_t *component_flags);
void StatusParameter_CopyRuntimeFields(
    struct StatusParameterRuntimeFieldsView *runtime,
    const struct StatusParameterDescriptorOptionsView *descriptor);
void GenericResourceState_UpdateMask(void *state, uint32_t active_mask);
__attribute__((noinline)) struct StatusRuntimeRecordView *StatusRuntimeRecord_Initialize(
    struct StatusRuntimeRecordView *record, void *source,
    const uint32_t payload[4])
{
    uint8_t *link = (uint8_t *)record + 4u;
    record->vtable_000 = (void *)(uintptr_t)0x00cf1b98u;
    record->link_next_004 = link;
    record->link_prev_008 = link;
    record->link_owner_00c = link;
    record->source_010 = source;
    record->state_014 = 0;
    record->scalar_018 = 1.0f;
    for (unsigned index = 0; index < 4u; ++index)
        record->payload_01c[index] = payload[index];
    if (source != 0)
        StatusRuntimeRecord_SourceLinkHook((uint8_t *)source + 0xb0u, record);
    return record;
}
void StatusParameter_PublishSelectedValue(
    const struct StatusParameterSelectionRecordView *selected,
    const void *parameter, const void *global_state, void *target)
{
    const uint8_t *parameter_bytes = (const uint8_t *)parameter;
    uint8_t *related;
    float value = selected->scale_038 *
                  *(const float *)(parameter_bytes + 0x38u);
    union {
        float value;
        uint32_t bits;
    } global_scale = { *(const float *)((const uint8_t *)global_state +
                                        0x30u) };
    if (parameter_bytes[0x19u] != 0u &&
        (int32_t)global_scale.bits < (int32_t)0x3f800000u) {
        void *residual_state = ActorMovementEngineGet004C59C0();
        FloatQuantizeResidualGuard(
            (uint32_t *)((uint8_t *)residual_state + 0x1884u), 3u);
        value *= global_scale.value;
    }
    related = (uint8_t *)ResolveRelatedComponent(target);
    *(float *)(related + 0x17cu) = value;
    HealthNotifyModeZero(related, value);
    if ((selected->flags_01e & 0x0200u) != 0u)
        Health_StatusBitUpdate(related, 0x78000u, 1u);
}
__attribute__((noinline)) float Float_ClampScaledUnit(const struct UnitScaleRecordView *record,
                            float hidden_scale)
{
    float value = record->scale_00c * hidden_scale;
    if (value < 0.0f)
        value = 0.0f;
    if (value > 1.0f)
        value = 1.0f;
    return value;
}
void StatusParameter_ApplyDescriptorFlags(
    struct StatusParameterSelectionRecordView *selected,
    const struct StatusParameterDescriptorOptionsView *descriptor,
    uint32_t *component_flags)
{
    uint16_t flags = selected->flags_01e;
    if (descriptor->flag_01a != 0)
        flags |= 0x0040u;
    if (descriptor->flag_01e != 0)
        flags |= 0x0200u;
    if (descriptor->flag_01c != 0)
        flags |= 0x0080u;
    if (descriptor->flag_01d != 0)
        flags |= 0x0100u;
    if (descriptor->flag_01b != 0)
        flags |= 0x0020u;
    if (descriptor->flag_01f != 0)
        flags |= 0x0400u;
    selected->flags_01e = flags;
    if (descriptor->component_flag_020 != 0 && component_flags != 0)
        *component_flags |= 0x01000000u;
}
void StatusParameter_CopyRuntimeFields(
    struct StatusParameterRuntimeFieldsView *runtime,
    const struct StatusParameterDescriptorOptionsView *descriptor)
{
    if ((int32_t)descriptor->value_024.bits <= 0)
        return;
    runtime->value_0f0 = descriptor->value_024.value;
    runtime->value_0f4 = descriptor->value_028;
    runtime->mode_12a = descriptor->resource_key_02c != 0 ? 1u : 0u;
    runtime->mode_0fc = descriptor->mode_030;
    runtime->sentinel_100 = -1;
}
void StatusParameter_ApplyContextMasks(
    void *context, const struct StatusParameterDescriptorOptionsView *options,
    void *target)
{
    uint8_t *status_context = (uint8_t *)context + 0xf98cu + 0x18cu;
    uint8_t *resolved;
    uint32_t key;
    if (options->scale_gate_019 != 0u) {
        resolved = (uint8_t *)ResolveStatusDescriptor(target);
        key = resolved != 0 ? *(uint32_t *)(resolved + 0x20u) : 0u;
        StatusContext_SetFlags(status_context, key,
                               STATUS_CONTEXT_PARAMETER_SELECTED);
    }
    if ((int32_t)options->value_024.bits > 0) {
        resolved = (uint8_t *)ResolveStatusDescriptor(target);
        key = resolved != 0 ? *(uint32_t *)(resolved + 0x20u) : 0u;
        StatusContext_SetFlags(status_context, key,
                               STATUS_CONTEXT_PARAMETER_SELECTED);
        StatusContext_SetFlags(status_context, key,
                               STATUS_CONTEXT_PARAMETER_ACTIVE);
        StatusContext_SetFlags(status_context, key,
                               STATUS_CONTEXT_PARAMETER_SOURCE);
    }
    if ((int32_t)options->value_024.bits > 0) {
        resolved = (uint8_t *)ResolveStatusDescriptor(target);
        key = resolved != 0 ? *(uint32_t *)(resolved + 0x20u) : 0u;
        StatusContext_SetFlags(status_context, key,
                               STATUS_CONTEXT_PARAMETER_RUNTIME);
    }
}
__attribute__((noinline)) void StatusParameter_ApplyAndDispatch(void *context, void *parameter,
                                      void *target, float hidden_scale)
{
    uint8_t *parameter_bytes = (uint8_t *)parameter;
    uint8_t *context_bytes = (uint8_t *)context;
    uint8_t *selected;
    uint8_t *descriptor_record;
    uint8_t *component;
    uint8_t *replacement_parameter;
    uint8_t stack_record[0x17cu] = {0};
    uint8_t *replacement = stack_record;
    float selected_value;
    float selected_product;
    void *descriptor;
    void *bound;
    void *key;
    void *global_state = *StatusParameterGlobalSingleton;
    uint32_t descriptor_key;
    if (global_state == 0) {
        global_state = StatusParameterGlobalState_Get();
        *StatusParameterGlobalSingleton = global_state;
    }
    bound = OrderedTreeLowerBoundByPointer(
        parameter_bytes + 0x1a4u, GetStatusCapabilityKey());
    selected = bound != 0 ? *(uint8_t **)bound : 0;
    if (selected == 0 || selected == *(uint8_t **)(parameter_bytes + 0x1a8u))
        selected = 0;
    component = (uint8_t *)ResolveCachedComponent_1EC(target);
    if (selected == 0 || component == 0)
        return;
    HealthParameter_RefreshSelection(parameter);
    selected_value = hidden_scale;
    *(float *)(selected + 0x38u) = selected_value;
    key = GetStatusBacklinkKey();
    bound = OrderedTree_FindPayloadByPointer_00326C6C(parameter, &key);
    if (bound != 0) {
        replacement_parameter = *(uint8_t **)((uint8_t *)bound + 0x1cu);
        if (replacement_parameter == 0)
            return;
        parameter = replacement_parameter;
        parameter_bytes = replacement_parameter;
    }
    if (bound != 0 && parameter_bytes[0x18u] != 0xffu) {
        uint8_t *event = (uint8_t *)StatusEventRecordResolve(target);
        event[0x2du] = parameter_bytes[0x18u];
    }
    descriptor = Engine_StatusDescriptorRegistry_Get();
    bound = OrderedTreeLowerBoundByPointer(
        (uint8_t *)target + 0x1a4u, descriptor);
    descriptor_record = bound != 0 ? *(uint8_t **)bound : 0;
    if (descriptor_record != *(uint8_t **)((uint8_t *)target + 0x1a8u) &&
        descriptor_record != 0)
        *(uint32_t *)(descriptor_record + 0xc4u) =
            *(uint32_t *)(parameter_bytes + 0x34u);
    StatusParameter_ApplyDescriptorFlags(
        (struct StatusParameterSelectionRecordView *)selected,
        (const struct StatusParameterDescriptorOptionsView *)parameter,
        (uint32_t *)(component + 0x98u));
    Engine_StoreQuantizedPair((uint32_t *)(parameter_bytes + 0x3cu));
    StatusParameter_PublishSelectedValue(
        (const struct StatusParameterSelectionRecordView *)selected,
        parameter, global_state, target);
    uint8_t *status_context = context_bytes + 0xf98cu + 0x18cu;
    uint32_t resolved_key = 0;
    if (parameter_bytes[0x19u] != 0u) {
        descriptor = ResolveStatusDescriptor(target);
        resolved_key = descriptor != 0 ? *(uint32_t *)((uint8_t *)descriptor + 0x20u) : 0;
        StatusContext_SetFlags(status_context, resolved_key,
                               STATUS_CONTEXT_PARAMETER_SELECTED);
    }
    if ((int32_t)*(uint32_t *)(parameter_bytes + 0x24u) > 0) {
        descriptor = ResolveStatusDescriptor(target);
        if (descriptor != 0) {
            resolved_key = *(uint32_t *)((uint8_t *)descriptor + 0x20u);
            StatusContext_SetFlags(status_context, resolved_key,
                                   STATUS_CONTEXT_PARAMETER_SELECTED);
            StatusContext_SetFlags(status_context, resolved_key,
                                   STATUS_CONTEXT_PARAMETER_ACTIVE);
            StatusContext_SetFlags(status_context, resolved_key,
                                   STATUS_CONTEXT_PARAMETER_SOURCE);
        }
        *(uint32_t *)(context_bytes + 0xf0u) =
            *(uint32_t *)(parameter_bytes + 0x24u);
        *(uint32_t *)(context_bytes + 0xf4u) =
            *(uint32_t *)(parameter_bytes + 0x28u);
        *(uint8_t *)(context_bytes + 0x12au) =
            *(uint8_t *)(parameter_bytes + 0x2cu) != 0u;
        *(uint8_t *)(context_bytes + 0xfc) = parameter_bytes[0x30u];
        *(int32_t *)(context_bytes + 0x100u) = -1;
        descriptor = ResolveStatusDescriptor(target);
        resolved_key = descriptor != 0 ? *(uint32_t *)((uint8_t *)descriptor + 0x20u) : 0;
        StatusContext_SetFlags(status_context, resolved_key,
                               STATUS_CONTEXT_PARAMETER_RUNTIME);
        uint8_t *state = (uint8_t *)Engine_LazySingletonGetter_0054EFA8();
        state[0x104u] = 1;
        *(float *)(state + 0x108u) = 0.0f;
        *(float *)(state + 0x10cu) = 16.0f;
        *(float *)(state + 0x110u) = 0.0f;
        *(float *)(state + 0x114u) = 0.0f;
        *(float *)(state + 0x118u) = 23.0f;
        *(float *)(state + 0x11cu) = 20.0f;
        *(float *)(state + 0x120u) = -1.0f;
    }
    *(void **)(stack_record + 0) = stack_record;
    *(void **)(stack_record + 4) = stack_record;
    *(void **)(stack_record + 8) = stack_record;
    *(void **)(stack_record + 0xc) = stack_record;
    stack_record[0x10u] = 0;
    (void)StatusParameter_GenericRecordInitialize(stack_record + 0x14u);
    *(void **)(stack_record + 0) = stack_record;
    stack_record[0x78u] = 0x19u;
    *(uint32_t *)(stack_record + 0x7cu) =
        *(uint32_t *)(parameter_bytes + 0x58u);
    stack_record[0x88u] = 1;
    Engine_StoreQuantizedPair((uint32_t *)(parameter_bytes + 0x60u));
    selected_product = *(float *)(selected + 0x38u) *
                       *(float *)(parameter_bytes + 0x5cu);
    *(float *)(stack_record + 0x8cu) = selected_product;
    *(float *)(stack_record + 0x90u) = selected_product;
    *(float *)(stack_record + 0x94u) = *(float *)(selected + 0x38u) *
                                       *(float *)(parameter_bytes + 0x38u);
    stack_record[0x98u] = 0x1du;
    *(uint32_t *)(stack_record + 0x9cu) =
        *(uint32_t *)(parameter_bytes + 0x68u);
    stack_record[0xa8u] = 0x20u;
    stack_record[0xb8u] = 0x20u;
    stack_record[0xc8u] = 0x20u;
    stack_record[0xd8u] = 0x20u;
    stack_record[0xe8u] = 0x20u;
    descriptor = ResolveStatusDescriptor(target);
    descriptor_key = *(uint32_t *)((uint8_t *)descriptor + 0x20u);
    if ((descriptor_key >> 28) == 1u)
        replacement = (uint8_t *)StatusOwnerIndexAddress(
            context_bytes + 0xb3f8u, *(int8_t *)((uint8_t *)descriptor + 0x2cu));
    StatusQueueAttachParameterRecord(replacement + 0x2d8u, stack_record, 0);
    if (stack_record[0x10u] != 0u) {
        while (replacement[0x10u] != 0u)
            replacement = *(uint8_t **)(replacement + 4u);
        OrderedTree_UnlinkNode_003D40E0(stack_record, replacement);
    }
}
__attribute__((noinline)) void GenericResourceState_UpdateMask(void *state, uint32_t active_mask)
{
    uint8_t *bytes = (uint8_t *)state;
    static const uint32_t *lane_masks =
        (const uint32_t *)(uintptr_t)0x00ca94a4u;
    unsigned lane = 0;
    int index;
    if (*(uint32_t *)(bytes + 0x0cu) == active_mask)
        return;
    if ((active_mask & 0xfffu) != 0) {
        for (index = 11; index > 0; --index) {
            if ((lane_masks[index] & active_mask) != 0) {
                lane = (unsigned)index;
                break;
            }
        }
    }
    *(uint32_t *)(bytes + 0x0cu) = active_mask;
    bytes[0x10u] = (uint8_t)lane;
    if (((*(uint32_t *)(bytes + 4u) & 0x100000u) >> 20) ==
        ((active_mask & 0x800u) >> 11))
        return;
    *(uint32_t *)(bytes + 4u) ^= 0x100000u;
    GenericResourceStateInterpolate(bytes, 1u);
}
