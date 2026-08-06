#include <stddef.h>
#include <stdint.h>
int StatusResourceVectorResolve(void *resource, float output[3],
                                   uint32_t index);
extern int HealthStatusParameter_DefaultBuild(void *output, void *descriptor,
                                                float result_vector[3]);
extern unsigned StatusResourceThresholdCrossingCheck(void *output_record,
                                                          void *resource);
extern void StatusSubmitResourceEffectEvent(void *output_record,
                                                void *resource,
                                                void *event_record);
extern float StatusAsin(float value);
extern float StatusRandomRange(float lower, float upper);
extern float Libm_Floorf_0049A940(float value);
extern void SinCosAngleUnits(float angle_units, float *sine, float *cosine);
extern float Trig_AcosCore(float value);
extern void StatusResourceDispatch_004849D4(void *dispatcher, void *resource,
                                               unsigned mode, ...);
extern int Engine_StatusVariantModeByte(void);
extern int Engine_SixPlaneContainmentTest(const float point[3],
                                            float fourth);
extern void *Engine_ComponentRegistryGetter(void);
extern void *Engine_ComponentEntryLookup(void *table, uint32_t key);
extern void *Engine_ComponentEntryLookup_004D6028(void *table,
                                                   uint32_t key);
extern void Engine_StatusEventIdEncode(uint32_t *output, int key,
                                       void *payload, int mode,
                                       int variant);
extern void *Engine_LazySingletonGetter_0054EFA8(void);
extern void *StatusTable_LookupById_0051B688(void *table, uint16_t id);
extern void *StatusRecord_ResolveDescriptor_00498F34(void *record);
extern int StatusDescriptor_SelectVariant_004990A8(void *descriptor,
                                                     int mode, int variant);
extern void *Engine_LazySingletonGetter_003FD6E0(void);
extern void *Engine_LazySingletonGetter_00422CC8(void);
extern void EffectEvent_Submit(void *dispatcher, uint32_t event_id,
                               uint32_t event_type, void *record);
extern void Engine_StatusEventRecordBuild_00492648(void *output,
                                                    void *input,
                                                    uint32_t key,
                                                    uint32_t provider_value);
extern void Engine_SubmitPositionUpdate_0044048C(const float point[3]);
extern void EffectEvent_Submit_00501208(void *owner, void *event);
extern void *ResourceTable_Lookup_0049C5E4(uint32_t *key);
extern uint32_t StatusResource_LazyDescriptorKey_004FCC08(void);
extern void *OrderedTree_LowerBoundByPointer_004C5D3C(void *tree,
                                                       uint32_t key);
extern uint32_t StatusResource_TransformActionBuilder_004C1CCC(
    void *first, void *second, float *first_transform, float *second_transform,
    uint32_t *out_key, int mode, uint32_t context, float limit, float angle,
    float scale);
extern uint32_t ComponentType_GetGlobalDescriptor_00533AEC(void);
extern int ResourceTable_GetSignedByteByKey_00390B7C(void *table,
                                                     int key);
extern void EffectEventReleasePool_0048D320(void *dispatcher, int key,
                                             int variant);
extern void *StatusResource_LookupRecord_005415B8(void *tree,
                                                   uint32_t key);
extern void *CachedComponent_ResolveClass1_0055709C(void *object,
                                                     void *descriptor);
extern void *ResolveStatusDescriptor_0054E1A0(void *descriptor);
extern void StatusResource_InitializeRuntimeClock_00411684(void *record);
extern void StatusResource_FlushPendingComponents_0041B9F4(void);
extern void Engine_RefreshIndexedRecord_00488FE8(void *record);
extern void *EffectState_FactoryGetter_00445194(void);
extern void ActorStateMachine_RequestStateByFactory_0036BEF0(
    void *machine, void *factory_slot);
extern void StateParameterRecord_Init_003B530C(uint32_t *record);
extern void Actor_PlayActionByHash_0036FCA8(uint32_t handle, int channel,
                                             const uint32_t *record,
                                             int arg3, int arg4);
extern int EffectState_CheckComponent_004D1D8C(void *component_result);
extern uint32_t EffectState_BuildValue_004217E0(void *descriptor);
extern void EffectState_ApplyValue_004333CC(void *state, uint32_t value);
extern void *StatusResource_SelectVariantRecord_004A93C0(void *state,
                                                          uint32_t type);
extern int StatusResource_BuildRecord_0045EC28(void *target,
                                                uint32_t key,
                                                void *descriptor,
                                                uint32_t *record_out,
                                                uint32_t *value_out,
                                                uint32_t flags);
extern void StatusResource_NotifyBuildFailure_005361E4(void *state,
                                                        uint32_t record,
                                                        uint32_t key,
                                                        uint32_t value);
extern void StatusResource_ApplyBuiltRecord_004AF894(void *runtime,
                                                      uint32_t record);
extern uint32_t DamagePacket_BuildFlags_0057E7C8(void *state);
extern void StatusEffect_AdjustAndStoreScale_005A5858(void *state,
                                                        int source);
extern uint32_t OwnerHandle_BuildVariant6_0058745C(void *tree,
                                                    uint32_t key);
extern uint32_t OwnerHandle_BuildOther_00562D00(void *tree);
extern void *EffectParameter_SourceDescriptor_004EE6EC(void *source);
extern void *EffectParameter_RecordInitialize_00566924(void *record);
extern void EffectParameter_RecordRandomize_0056665C(void *record,
                                                       int source,
                                                       uint32_t selector,
                                                       int enabled);
extern void ParameterString_RecordInit_003531A4(void *record);
extern void ParameterString_Assign_0043A31C(void *destination,
                                             const void *source);
extern uint32_t ParameterString_Hash_002F2808(void *record);
extern uint32_t ParameterString_Hash_00448668(void *record);
extern void ParameterString_Format_00542F74(void *output,
                                             const char *value,
                                             int capacity);
extern void EffectParameter_BuildAndSubmit_005651D8(void *output,
                                                       uint32_t selector,
                                                       void *record,
                                                       uint32_t flags,
                                                       uint32_t arg4,
                                                       uint32_t arg5);
extern void StatusChannel_ResetOrReplace_005C50E8(void *state,
                                                    uint32_t channel,
                                                    uint32_t flags);
extern void *StatusRecord_LookupByKey_0050DD24(void *table, uint32_t key);
extern void StatusRecord_SetChannelBitMasks_005403EC(void *record,
                                                      uint32_t enable_primary,
                                                      uint32_t enable_secondary,
                                                      uint32_t bit_index);
int StatusResourceVectorResolve(void *resource, float output[3],
                                   uint32_t index);
void StatusResourceValueHook(void *output_record, const void *resource);
void StatusResourceMotionBuild(void *output_record, void *resource,
                                  float hidden_delta);
float StatusResourceIntegrateMotion(void *output_record, void *resource,
                                       void *provider, float hidden_delta);
extern void StatusVector_Normalize_005C1E4C(float *output, const float *input);
extern uint32_t StatusAdjustment_004AED44(void *context, uint32_t *value,
                                          float lower, float ratio);
extern void StatusVector_Clear_005C9C3C(float *vector);
extern void StatusResource_ReleaseBlock_00421DEC(void *block);
extern void *StatusResource_GetBlockBase_004ED674(void *block);
extern void *StatusResource_InitializeStride_00421EA4(void *base,
                                                       void *callback,
                                                       uint32_t stride,
                                                       uint32_t count);
extern void *StatusResource_AllocateTagged_0047466C(uint32_t size,
                                                     void *tag,
                                                     uint32_t count);
extern int StatusState_CheckReady_00433264(void *state);
extern uint32_t ComponentType_GetGlobalDescriptor_00517CC4(void);
extern void Health_StatusBitUpdate(void *health, uint32_t mask,
                                   uint32_t enabled);
extern void *EffectState_AlternateFactory_00432C98(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                      void *factory_slot);
extern void *Engine_LazyListGroup_004C5BFC(void);
extern void *Engine_LazyTaggedListGroup_004C5B30(void);
extern void *EffectState_ComponentPayloadInit_00433B38(void *payload);
extern void EffectState_ComponentInit_004338CC(void *payload, void *arg1,
                                                void *arg2, uint32_t owner_word,
                                                void *arg4, uint32_t enabled);
extern void Component_NotifyStatusChange(void *payload, uint32_t channel,
                                         uint32_t enabled);
extern uint32_t Object_GetAllocatorContext_0042167C(void *object);
extern void *StateVariant_RecordInit_004328E8(void *record, void *state);
extern uint32_t StateMachineVariant_LookupCachedValue_00552008(void *state);
extern void StateVariant_Handler_007E2BAC(void *state);
extern void StateVariant_Handler_007F19F4(void *state);
extern void StateVariant_Handler_007F2268(void *state);
extern void StateVariant_Handler_007F10C8(void *state);
extern void StateVariant_Handler_007DF94C(void *state);
extern void StateVariant_Handler_007D172C(void *state);
extern void StateVariant_Handler_007E0F8C(void *state);
extern void StateVariant_Handler_007E12E4(void *state);
extern void StateVariant_Handler_007D1368(void *state);
extern void StateVariant_Handler_007E1AA0(void *state);
extern void StateVariant_Handler_007E1378(void *state);
extern void StateVariant_Handler_007CF7B8(void *state);
extern void StateVariant_Handler_007D2134(void *state);
extern void StateVariant_Handler_007DFA48(void *state);
extern void StateVariant_Handler_007E1F4C(void *state);
extern void StateVariant_Handler_007CECE8(void *state);
extern void StateVariant_Handler_007E2AE4(void *state);
extern void StateVariant_Handler_007D0964(void *state);
void StatusResource_EncodeTransformEvent(void *unused, void *resource,
                                         void *event, int variant);
union StatusMotionFloatWord {
    uint32_t bits;
    float value;
};
struct StatusMotionExternalView {
    uint8_t active;
    uint8_t opaque_001[0x0f];
    uint32_t key_010;
    uint8_t opaque_014[4];
    union StatusMotionFloatWord position_018[3];
    uint8_t opaque_024[0x18];
    uint32_t field_03c;
    uint32_t field_040;
    uint32_t field_044;
    uint8_t opaque_048[0x10];
    uint32_t field_058;
    uint8_t opaque_05c[0x14];
    uint32_t field_070;
};
struct StatusMotionVectorRecordView {
    uint8_t mode_000;
    uint8_t opaque_001[3];
    uint8_t *field_004;
    union StatusMotionFloatWord position_008[3];
    union StatusMotionFloatWord previous_014[3];
    uint32_t field_020;
    uint32_t field_024;
    uint32_t field_028;
    float normalized_02c[3];
    uint8_t opaque_038[0x0c];
    uint32_t field_044;
    uint32_t field_048;
    uint32_t field_04c;
    uint32_t field_050;
    union StatusMotionFloatWord remaining_054;
    union StatusMotionFloatWord duration_058;
    uint32_t count_05c;
    uint8_t opaque_060[4];
    struct StatusMotionExternalView *external_064;
    uint32_t external_key_068;
};
typedef char kiu_sa_status_resource_motion_1[(offsetof(struct StatusMotionVectorRecordView, position_008) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_resource_motion_2[(offsetof(struct StatusMotionVectorRecordView, normalized_02c) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_resource_motion_3[(offsetof(struct StatusMotionVectorRecordView, external_064) == 0x64) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_resource_motion_4[(sizeof(struct StatusMotionVectorRecordView) == 0x6c) ? 1 : -1] __attribute__((unused));
__attribute__((noinline)) void StatusResource_UpdateVectorRecord(void *context, void *record,
                                       float hidden_delta)
{
    struct StatusMotionVectorRecordView *view =
        (struct StatusMotionVectorRecordView *)record;
    struct StatusMotionExternalView *external;
    float dx;
    float dy;
    float dz;
    float distance;
    float *fallback = *(float **)(uintptr_t)0x0040fa4cu;
    if (view->previous_014[0].value != view->previous_014[0].value ||
        view->previous_014[1].value != view->previous_014[1].value ||
        view->previous_014[2].value != view->previous_014[2].value)
        goto invalid;
    if (view->mode_000 == 1u) {
        external = view->external_064;
        if (external == 0 || external->active == 0 ||
            external->key_010 != view->external_key_068)
            goto enter_decay;
        view->position_008[0].bits = external->position_018[0].bits;
        view->position_008[1].bits = external->position_018[1].bits;
        view->position_008[2].bits = external->position_018[2].bits;
        view->field_020 = external->field_03c;
        view->field_024 = external->field_040;
        view->field_028 = external->field_044;
        view->field_04c = external->field_058;
        view->field_050 = external->field_070;
        dx = view->position_008[0].value - view->previous_014[0].value;
        dy = view->position_008[1].value - view->previous_014[1].value;
        dz = view->position_008[2].value - view->previous_014[2].value;
        distance = __builtin_sqrtf(dx * dx + dy * dy + dz * dz);
        if (distance > 1.0f)
            StatusVector_Normalize_005C1E4C(
                view->normalized_02c, &view->position_008[0].value);
        goto finish;
    }
    if (view->mode_000 != 2u)
        goto finish;
    if (*(float *)(view->field_004 + 0xf8u) < 1.0f) {
        uint32_t count = view->count_05c - 1u;
        view->count_05c = count;
        if ((int32_t)count <= 0) {
            view->mode_000 = 0;
            view->external_key_068 = 0;
            view->external_064 = 0;
            StatusVector_Clear_005C9C3C(view->normalized_02c);
        }
        goto finish;
    }
    view->remaining_054.value -= hidden_delta;
    if (view->remaining_054.value < 1.0f) {
        view->remaining_054.value = 1.0f;
        view->mode_000 = 0;
        view->external_key_068 = 0;
        view->external_064 = 0;
        StatusVector_Clear_005C9C3C(view->normalized_02c);
    }
    view->field_044 = StatusAdjustment_004AED44(
        context, &view->field_044, 1.0f,
        view->remaining_054.value / view->duration_058.value);
    view->field_048 = StatusAdjustment_004AED44(
        context, &view->field_048, 1.0f,
        view->remaining_054.value / view->duration_058.value);
    goto finish;
enter_decay:
    view->mode_000 = 2u;
    view->duration_058.bits = *(uint32_t *)(view->field_004 + 0xf8u);
    view->remaining_054.bits = view->duration_058.bits;
finish:
    view->previous_014[0].bits = view->position_008[0].bits;
    view->previous_014[1].bits = view->position_008[1].bits;
    view->previous_014[2].bits = view->position_008[2].bits;
    return;
invalid:
    external = view->external_064;
    if (external != 0 && external->active != 0 &&
        external->key_010 == view->external_key_068) {
        view->position_008[0].bits = external->position_018[0].bits;
        view->position_008[1].bits = external->position_018[1].bits;
        view->position_008[2].bits = external->position_018[2].bits;
        StatusVector_Normalize_005C1E4C(
            view->normalized_02c, &view->position_008[0].value);
    } else {
        view->previous_014[0].bits = *(uint32_t *)(fallback + 0u);
        view->previous_014[1].bits = *(uint32_t *)(fallback + 1u);
        view->previous_014[2].bits = *(uint32_t *)(fallback + 2u);
    }
}
__attribute__((noinline)) void StatusResource_InitializeRecordArrays(void *owner, uint32_t primary_count,
                                           void *allocator_context)
{
    uint8_t *bytes = (uint8_t *)owner;
    uint8_t *primary;
    uint8_t *secondary;
    uint32_t index;
    *(void **)(bytes + 0x18u) = allocator_context;
    if (*(void **)(bytes + 0x1cu) != 0) {
        StatusResource_ReleaseBlock_00421DEC(*(void **)(bytes + 0x1cu));
        *(void **)(bytes + 0x1cu) = 0;
    }
    if (*(void **)(bytes + 0x20u) != 0) {
        StatusResource_ReleaseBlock_00421DEC(
            (uint8_t *)StatusResource_GetBlockBase_004ED674(
                (uint8_t *)*(void **)(bytes + 0x20u) + 0x2cu) - 0x2cu);
        *(void **)(bytes + 0x20u) = 0;
    }
    *(uint32_t *)(bytes + 8u) = primary_count;
    *(uint32_t *)(bytes + 0x10u) = 0;
    *(uint32_t *)(bytes + 0xcu) = primary_count;
    *(uint32_t *)(bytes + 0x14u) = 0;
    primary = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        primary_count * 0xd4u, (void *)(uintptr_t)0x00ca0f78u,
        *(uint32_t *)(bytes + 0x18u));
    if (primary != 0)
        primary = (uint8_t *)StatusResource_InitializeStride_00421EA4(
            primary, (void *)(uintptr_t)0x00434bd4u, 0xd4u, primary_count);
    *(uint8_t **)(bytes + 0x1cu) = primary;
    for (index = 0; index < primary_count; ++index)
        primary[index * 0xd4u] = 0;
    secondary = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        *(uint32_t *)(bytes + 0xcu) * 0x74u + 8u,
        (void *)(uintptr_t)0x00ca0f78u, *(uint32_t *)(bytes + 0x18u));
    if (secondary != 0) {
        *(uint32_t *)(secondary + 0u) = 0x74u;
        *(uint32_t *)(secondary + 4u) = *(uint32_t *)(bytes + 0xcu);
        secondary = (uint8_t *)StatusResource_InitializeStride_00421EA4(
            secondary + 8u, (void *)(uintptr_t)0x00432398u, 0x74u,
            *(uint32_t *)(bytes + 0xcu));
    }
    *(uint8_t **)(bytes + 0x20u) = secondary;
    for (index = 0; index < *(uint32_t *)(bytes + 0xcu); ++index)
        secondary[index * 0x74u] = 0;
}
__attribute__((noinline)) int EffectState_EnsureComponent(void *state, void *unused,
                                void *unused_descriptor, void *factory_seed)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *machine;
    uint8_t *node;
    uint8_t *parent;
    uint8_t *sentinel;
    uint32_t key;
    void *selected;
    (void)unused;
    (void)unused_descriptor;
    if (state_bytes[0x3du] != 0u) {
        void *factory = EffectState_AlternateFactory_00432C98();
        (void)factory_seed;
        machine = *(uint8_t **)(state_bytes + 0x30u);
        ActorStateMachine_RequestStateByFactory(machine, &factory);
        return 0;
    }
    if (state_bytes[0x3cu] != 0u)
        return 0;
    state_bytes[0x3cu] = (uint8_t)StatusState_CheckReady_00433264(state);
    if (state_bytes[0x3cu] == 0u)
        return 0;
    machine = *(uint8_t **)(state_bytes + 0x30u);
    selected = *(void **)(machine + 0x208u);
    if (selected != 0) {
        Health_StatusBitUpdate(selected, 0x8000u, 1u);
        return 0;
    }
    key = ComponentType_GetGlobalDescriptor_00517CC4();
    sentinel = machine + 0x1a8u;
    parent = sentinel;
    node = *(uint8_t **)(machine + 0x1acu);
    while (node != 0 && node[0x10u] != 0u) {
        if (*(uint32_t *)(node + 0x14u) < key) {
            node = *(uint8_t **)(node + 0x0cu);
        } else {
            parent = node;
            node = *(uint8_t **)(node + 8u);
        }
    }
    if (parent == sentinel || *(uint32_t *)(parent + 0x14u) <= key)
        parent = sentinel;
    selected = parent != 0 ? *(void **)parent : 0;
    if (selected == *(void **)sentinel)
        return 0;
    if (selected == 0)
        return 0;
    *(void **)((uint8_t *)selected + 0x34u) = machine;
    *(void **)(machine + 0x208u) = selected;
    Health_StatusBitUpdate(selected, 0x8000u, 1u);
    return 0;
}
__attribute__((noinline)) void *EffectState_CreateComponentRecord(void *record, void *arg1, void *arg2,
                                        void *owner, void *arg4)
{
    uint8_t *bytes = (uint8_t *)record;
    uint8_t *node_a = bytes + 0x30u;
    uint8_t *node_b = bytes + 0x10u;
    uint8_t *group;
    uint8_t *payload;
    uint32_t owner_word = *(uint32_t *)(
        *(uint8_t **)(*(uint8_t **)((uint8_t *)owner + 0xb0u) + 8u) +
        0x10cu);
    *(void **)(bytes + 0x10u) = record;
    *(void **)(bytes + 0x14u) = node_b;
    *(void **)(bytes + 0x18u) = node_b;
    *(uint32_t *)(bytes + 0x1cu) = 0u;
    *(void **)(bytes + 4u) = bytes + 4u;
    *(void **)(bytes + 8u) = bytes + 4u;
    *(void **)(bytes + 0xcu) = bytes + 4u;
    *(void **)(bytes + 0x20u) = (void *)(uintptr_t)0x00d204f4u;
    *(void **)(bytes + 0x24u) = bytes + 0x20u;
    *(void **)(bytes + 0x28u) = bytes + 0x24u;
    *(void **)(bytes + 0x2cu) = bytes + 0x24u;
    *(void **)(bytes + 0x30u) = record;
    *(void **)(bytes + 0x34u) = node_a;
    *(void **)(bytes + 0x38u) = node_a;
    group = *(uint8_t **)(uintptr_t)0x00d638ccu;
    if (group == 0) {
        group = (uint8_t *)Engine_LazyListGroup_004C5BFC();
        *(uint8_t **)(uintptr_t)0x00d638ccu = group;
    }
    if (group != node_a) {
        *(void **)(*(void **)(bytes + 0x38u) + 4u) =
            *(void **)(bytes + 0x34u);
        *(void **)(*(void **)(bytes + 0x34u) + 8u) =
            *(void **)(bytes + 0x38u);
        *(void **)(*(void **)(group + 8u) + 4u) = node_a;
        *(void **)(bytes + 0x38u) = *(void **)(group + 8u);
        *(void **)(bytes + 0x34u) = group;
        *(void **)(group + 8u) = bytes + 0x34u;
    }
    *(void **)(bytes + 0u) = (void *)(uintptr_t)0x00d1e728u;
    *(void **)(bytes + 0x20u) = (uint8_t *)(uintptr_t)0x00d1e728u + 0x34u;
    bytes[0x3cu] = 0u;
    bytes[0x3du] = 1u;
    bytes[0x3eu] = 0u;
    group = *(uint8_t **)(uintptr_t)0x00d6384cu;
    if (group == 0) {
        group = (uint8_t *)Engine_LazyTaggedListGroup_004C5B30();
        *(uint8_t **)(uintptr_t)0x00d6384cu = group;
    }
    if (group + 4u != node_b) {
        *(void **)(*(void **)(bytes + 0x18u) + 4u) =
            *(void **)(bytes + 0x14u);
        *(void **)(*(void **)(bytes + 0x14u) + 8u) =
            *(void **)(bytes + 0x18u);
        *(void **)(*(void **)(group + 0x0cu) + 4u) = node_b;
        *(void **)(bytes + 0x18u) = *(void **)(group + 0x0cu);
        *(void **)(bytes + 0x14u) = group + 4u;
        *(void **)(group + 0x0cu) = bytes + 0x14u;
    }
    payload = (uint8_t *)EffectState_ComponentPayloadInit_00433B38(
        bytes + 0x40u);
    EffectState_ComponentInit_004338CC(payload, arg1, arg2, owner_word, arg4,
                                       1u);
    Component_NotifyStatusChange(payload, 0u, 1u);
    Component_NotifyStatusChange(payload, 2u, 1u);
    Component_NotifyStatusChange(payload, 4u, 1u);
    *(uint32_t *)(payload + 0xb8u) = owner_word;
    return payload - 0x40u;
}
__attribute__((noinline)) static void StatusResource_DispatchStateVariantDefault(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x30u, (void *)(uintptr_t)0x00412f0cu, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(void **)(record + 0u) = (void *)(uintptr_t)0x00cf8c0cu;
    *(uint32_t *)(record + 0x2cu) = 0u;
}
__attribute__((noinline)) void StatusResource_ApplyEffectVariant(void *state, uint32_t packed_type,
                                       int source, uint32_t mode)
{
    uint32_t source_key;
    void *source_record;
    void *source_descriptor;
    uint8_t parameter_record[0x100u];
    uint8_t string_record[0x20u];
    uint32_t seed_record[2];
    uint32_t output_record = 0u;
    float current = *(float *)((uint8_t *)state + 0xc0cu);
    float stored = *(float *)((uint8_t *)state + 0x1edfcU);
    if (DamagePacket_BuildFlags_0057E7C8(state) != packed_type)
        return;
    StatusEffect_AdjustAndStoreScale_005A5858(state, source);
    if ((packed_type >> 28) == 6u)
        source_key = OwnerHandle_BuildVariant6_0058745C(
            (uint8_t *)state + 0x171acu, packed_type);
    else
        source_key = OwnerHandle_BuildOther_00562D00(
            (uint8_t *)state + 0xf98cu);
    source_record = ResourceTable_Lookup_0049C5E4(&source_key);
    if (source_record == 0)
        return;
    if (stored > current) {
        stored = 0.0f;
        *(float *)((uint8_t *)state + 0x1edfcU) = stored;
    }
    if (current - stored <= 0.2f)
        goto dispatch;
    source_descriptor = EffectParameter_SourceDescriptor_004EE6EC(
        source_record);
    if (*(uint32_t *)((uint8_t *)source_descriptor + 0x24u) == 0u)
        goto dispatch;
    (void)EffectParameter_RecordInitialize_00566924(parameter_record);
    if (*(int16_t *)((uint8_t *)source_record + 0x20u) == 0x324 ||
        *(int16_t *)((uint8_t *)source_record + 0x20u) == 0x32c) {
        EffectParameter_RecordRandomize_0056665C(
            parameter_record, (int)(uintptr_t)source_record, 0u, 0);
    } else {
        ParameterString_RecordInit_003531A4(string_record);
        ParameterString_Assign_0043A31C(
            (uint8_t *)string_record + 4u, (const void *)(uintptr_t)0x003edb8cu);
        *(uint32_t *)string_record = ParameterString_Hash_002F2808(
            (uint8_t *)string_record + 4u);
        seed_record[0] = 0x00ca8bc0u;
        seed_record[1] = 0u;
        (void)ParameterString_Hash_00448668(&seed_record[1]);
        ParameterString_Format_00542F74(
            parameter_record,
            *(const char *const *)string_record, 0x20);
        EffectParameter_RecordRandomize_0056665C(
            parameter_record, (int)(uintptr_t)source_record,
            *(const uint32_t *)((uint8_t *)source_descriptor + 0x24u), 0);
    }
    EffectParameter_BuildAndSubmit_005651D8(
        &output_record, 0x00ca8bc0u, parameter_record, 0u, 1u, 1u);
    *(float *)((uint8_t *)state + 0x1edfcU) = current;
dispatch:
    switch (mode & 0xffu) {
    case 0u:
    case 1u:
        StatusChannel_ResetOrReplace_005C50E8(state, 10u, 0u);
        return;
    case 2u:
    case 3u:
    case 4u:
        StatusChannel_ResetOrReplace_005C50E8(state, 0x17u, 0u);
        return;
    default:
        return;
    }
}
static void *StatusResource_TreePayloadAtKey(void *record, uint32_t key)
{
    uint8_t *tree = (uint8_t *)record + 0x1a8u;
    uint8_t *node = (uint8_t *)OrderedTree_LowerBoundByPointer_004C5D3C(
        tree, key);
    if (node == 0 || node == tree + 4u)
        return 0;
    return *(void **)node;
}
__attribute__((noinline)) void StatusResource_RefreshLinkedRecord(void *state, void *resource)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    void *current;
    void *state_record;
    void *linked;
    uint32_t key;
    uint32_t generated_key = 0xffffffffu;
    uint32_t component_key;
    void *generated;
    void *component;
    float first_transform[3];
    float second_transform[3];
    uint32_t angle_bits = *(uint32_t *)((uint8_t *)state + 0x44u);
    float scale = *(float *)((uint8_t *)state + 0x40u);
    union {
        uint32_t bits;
        float value;
    } angle;
    if (*(int16_t *)(resource_bytes + 0xd4u) != 1 &&
        *(int16_t *)(resource_bytes + 0xd4u) != 0x328)
        return;
    current = ResourceTable_Lookup_0049C5E4(
        (uint32_t *)(resource_bytes + 0xccu));
    state_record = ResourceTable_Lookup_0049C5E4(
        (uint32_t *)((uint8_t *)state + 0x120u));
    if (current == 0)
        return;
    linked = *(void **)((uint8_t *)current + 0x1ecu);
    if (linked == 0) {
        key = StatusResource_LazyDescriptorKey_004FCC08();
        linked = StatusResource_TreePayloadAtKey(current, key);
        if (linked != 0) {
            *(void **)((uint8_t *)linked + 0x1cu) = current;
            *(void **)((uint8_t *)current + 0x1ecu) = linked;
        }
    }
    if (linked == 0)
        return;
    first_transform[0] = *(float *)(resource_bytes + 0x4cu);
    first_transform[1] = *(float *)(resource_bytes + 0x50u);
    first_transform[2] = *(float *)(resource_bytes + 0x54u);
    second_transform[0] = *(float *)(resource_bytes + 0x3cu);
    second_transform[1] = *(float *)(resource_bytes + 0x40u);
    second_transform[2] = *(float *)(resource_bytes + 0x44u);
    if (angle_bits > 0xbfc90fdbu)
        angle_bits = 0xbfc90fdbu;
    else if ((int32_t)angle_bits > (int32_t)0x3fc90fdbu)
        angle_bits = 0x3fc90fdbu;
    angle.bits = angle_bits;
    key = StatusResource_TransformActionBuilder_004C1CCC(
        current, linked, first_transform, second_transform, &generated_key,
        1, (uint32_t)(uintptr_t)state_record, 1000.0f, angle.value, scale);
    generated = ResourceTable_Lookup_0049C5E4(&key);
    if (generated == 0) {
        *(uint32_t *)(resource_bytes + 0x94u) = 0u;
        *(uint32_t *)(resource_bytes + 0x98u) = 0xffffffffu;
        return;
    }
    component = *(void **)((uint8_t *)generated + 0x1e8u);
    if (component == 0) {
        component_key = ComponentType_GetGlobalDescriptor_00533AEC();
        component = StatusResource_TreePayloadAtKey(generated, component_key);
        if (component != 0) {
            *(void **)((uint8_t *)component + 0x1cu) = generated;
            *(void **)((uint8_t *)generated + 0x1e8u) = component;
        }
    }
    *(uint32_t *)(resource_bytes + 0x94u) = component == 0 ? 0u :
        *(uint32_t *)((uint8_t *)component + 0x20u);
    *(uint32_t *)(resource_bytes + 0x98u) = generated_key;
}
__attribute__((noinline)) void StateVariant_ChildInit_007CF79C(void *child)
{
    *(float *)((uint8_t *)child + 8u) = 0.0f;
    *(uint32_t *)((uint8_t *)child + 0u) = 0u;
    *(uint32_t *)((uint8_t *)child + 4u) = 0u;
}
__attribute__((noinline)) void StateVariant_ChildInit_007D211C(void *child)
{
    *(uint32_t *)((uint8_t *)child + 0u) = 0u;
    *(float *)((uint8_t *)child + 4u) = 0.0f;
}
__attribute__((noinline)) void StateVariant_Handler_007E2BAC(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x38u, (void *)(uintptr_t)0x007e2c10u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    *(float *)(record + 0x30u) = 0.0f;
    record[0x34u] = 0u;
    *(void **)(record + 0u) = (void *)(uintptr_t)0x00cf7ee0u;
}
__attribute__((noinline)) void StateVariant_Handler_007DF94C(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *basis = *(const uint32_t **)(uintptr_t)0x007dfa1cu;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x70u, (void *)(uintptr_t)0x007dfa0cu, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    *(float *)(record + 0x30u) = 0.0f;
    *(uint32_t *)(record + 0x34u) = 0u;
    record[0x38u] = 0u;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007dfa18u;
    *(uint32_t *)(record + 0x3cu) = basis[0];
    *(uint32_t *)(record + 0x40u) = basis[1];
    *(uint32_t *)(record + 0x44u) = basis[2];
    *(uint32_t *)(record + 0x48u) = basis[3];
    *(uint32_t *)(record + 0x4cu) = basis[0];
    *(uint32_t *)(record + 0x50u) = basis[1];
    *(uint32_t *)(record + 0x54u) = basis[2];
    *(uint32_t *)(record + 0x58u) = basis[3];
    *(uint32_t *)(record + 0x5cu) = 0u;
    *(uint32_t *)(record + 0x60u) = 0u;
    *(float *)(record + 0x64u) = 0.0f;
    *(uint32_t *)(record + 0x68u) = 0u;
    record[0x6cu] = 0u;
}
__attribute__((noinline)) void StateVariant_Handler_007F10C8(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *fallback = *(const uint32_t **)(uintptr_t)0x007f1174u;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x54u, (void *)(uintptr_t)0x007f1168u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    *(float *)(record + 0x30u) = 0.0f;
    record[0x34u] = 0u;
    record[0x35u] = 0xffu;
    record[0x36u] = 0u;
    *(uint32_t *)(record + 0x38u) = fallback[0];
    *(uint32_t *)(record + 0x3cu) = fallback[1];
    *(uint32_t *)(record + 0x40u) = fallback[2];
    *(float *)(record + 0x44u) = 0.0f;
    record[0x48u] = 0u;
    *(float *)(record + 0x4cu) = 0.0f;
    record[0x50u] = 0u;
    record[0x51u] = 0u;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007f1178u;
}
__attribute__((noinline)) void StateVariant_Handler_007F19F4(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x44u, (void *)(uintptr_t)0x007f1a80u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    *(float *)(record + 0x30u) = 0.0f;
    record[0x34u] = 0u;
    *(uint32_t *)(record + 0x38u) = 0xfffffe00u;
    record[0x3cu] = 0u;
    record[0x3du] = 0xffu;
    record[0x3eu] = 0u;
    *(uint32_t *)(record + 0x40u) = 0u;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007f1a8cu;
}
__attribute__((noinline)) void StateVariant_Handler_007F2268(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *fallback = *(const uint32_t **)(uintptr_t)0x007f2328u;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x60u, (void *)(uintptr_t)0x007f231cu, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    *(float *)(record + 0x30u) = 0.0f;
    record[0x34u] = 0u;
    record[0x35u] = 0xffu;
    record[0x36u] = 0u;
    *(uint32_t *)(record + 0x38u) = fallback[0];
    *(uint32_t *)(record + 0x3cu) = fallback[1];
    *(uint32_t *)(record + 0x40u) = fallback[2];
    *(float *)(record + 0x44u) = 0.0f;
    record[0x48u] = 0u;
    *(uint32_t *)(record + 0x4cu) = fallback[0];
    *(uint32_t *)(record + 0x50u) = fallback[1];
    *(uint32_t *)(record + 0x54u) = fallback[2];
    *(float *)(record + 0x58u) = 0.0f;
    *(float *)(record + 0x5cu) = 0.0f;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007f232cu;
}
__attribute__((noinline)) void StateVariant_Handler_007E0F8C(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *basis = *(const uint32_t **)(uintptr_t)0x007e1048u;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x68u, (void *)(uintptr_t)0x007e1038u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = basis[0];
    *(uint32_t *)(record + 0x30u) = basis[1];
    *(uint32_t *)(record + 0x34u) = basis[2];
    *(uint32_t *)(record + 0x38u) = basis[3];
    *(uint32_t *)(record + 0x3cu) = 0u;
    *(float *)(record + 0x40u) = 0.0f;
    record[0x44u] = 0u;
    *(uint32_t *)(record + 0x48u) = 0u;
    *(uint32_t *)(record + 0x4cu) = 0xffffffffu;
    *(uint32_t *)(record + 0x50u) = 0xffffffffu;
    *(uint32_t *)(record + 0x54u) = 0xffffffffu;
    *(uint32_t *)(record + 0x58u) = 0xffffffffu;
    *(uint32_t *)(record + 0x5cu) = 0xffffffffu;
    *(uint32_t *)(record + 0x60u) = 0u;
    *(uint32_t *)(record + 0x64u) = 0u;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007e1044u;
}
__attribute__((noinline)) void StateVariant_Handler_007E12E4(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x38u, (void *)(uintptr_t)0x007e1350u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    record[0x30u] = 0xffu;
    record[0x31u] = 0u;
    *(float *)(record + 0x34u) = 0.0f;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007e135cu;
}
__attribute__((noinline)) void StateVariant_Handler_007E1378(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *fallback = *(const uint32_t **)(uintptr_t)0x007e1450u;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x68u, (void *)(uintptr_t)0x007e1440u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    record[0x30u] = 0u;
    record[0x31u] = 0xffu;
    *(uint32_t *)(record + 0x34u) = 0xfffffe00u;
    *(uint32_t *)(record + 0x38u) = fallback[0];
    *(uint32_t *)(record + 0x3cu) = fallback[1];
    *(uint32_t *)(record + 0x40u) = fallback[2];
    record[0x44u] = 0u;
    *(float *)(record + 0x48u) = 0.0f;
    *(float *)(record + 0x4cu) = 0.0f;
    record[0x50u] = 0x1fu;
    *(float *)(record + 0x54u) = 0.0f;
    *(float *)(record + 0x58u) = 0.0f;
    *(float *)(record + 0x5cu) = 0.0f;
    *(float *)(record + 0x60u) = 0.0f;
    *(float *)(record + 0x64u) = 0.0f;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007e1454u;
}
__attribute__((noinline)) void StateVariant_Handler_007E1F4C(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x34u, (void *)(uintptr_t)0x007e1facu, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    *(float *)(record + 0x30u) = 0.0f;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007e1fb8u;
}
__attribute__((noinline)) void StateVariant_Handler_007CECE8(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *fallback = *(const uint32_t **)(uintptr_t)0x007ced98u;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x4cu, (void *)(uintptr_t)0x007ced84u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    *(uint32_t *)(record + 0x30u) = 0xfffffe00u;
    *(uint32_t *)(record + 0x34u) = 0u;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007ced94u;
    *(uint32_t *)(record + 0x38u) = fallback[0];
    *(uint32_t *)(record + 0x3cu) = fallback[1];
    *(uint32_t *)(record + 0x40u) = fallback[2];
    *(float *)(record + 0x44u) = 0.0f;
    *(float *)(record + 0x48u) = 0.0f;
}
__attribute__((noinline)) void StateVariant_Handler_007E2AE4(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *basis = *(const uint32_t **)(uintptr_t)0x007e2b94u;
    const uint32_t *fallback = *(const uint32_t **)(uintptr_t)0x007e2b98u;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        100u, (void *)(uintptr_t)0x007e2b84u, allocator);
    uint32_t index;
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 0.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = basis[0];
    for (index = 1u; index <= 7u; ++index)
        *(uint32_t *)(record + 0x2cu + index * 4u) = basis[index];
    for (index = 0u; index < 3u; ++index)
        *(uint32_t *)(record + 0x4cu + index * 4u) = fallback[index];
    *(float *)(record + 0x58u) = 0.0f;
    *(uint32_t *)(record + 0x5cu) = 0u;
    record[0x60u] = 0xffu;
    record[0x61u] = 0u;
    record[0x62u] = 0xffu;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007e2b90u;
}
__attribute__((noinline)) void StateVariant_Handler_007DFA48(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x38u, (void *)(uintptr_t)0x007dfab4u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    record[0x30u] = 0u;
    record[0x31u] = 0xffu;
    *(float *)(record + 0x34u) = 0.0f;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007dfac0u;
}
__attribute__((noinline)) void StateVariant_Handler_007D1368(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x6cu, (void *)(uintptr_t)0x007d1434u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    record[0x30u] = 0u;
    record[0x31u] = 0xffu;
    *(uint32_t *)(record + 0x34u) &= 0xfffffe00u;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007d1440u;
    {
        const uint32_t *basis = *(const uint32_t **)(uintptr_t)0x007d1444u;
        *(uint32_t *)(record + 0x38u) = basis[0];
        *(uint32_t *)(record + 0x3cu) = basis[1];
        *(uint32_t *)(record + 0x40u) = basis[2];
    }
    record[0x44u] = 0u;
    *(float *)(record + 0x48u) = 0.0f;
    *(float *)(record + 0x4cu) = 0.0f;
    record[0x50u] = 0x1fu;
    *(float *)(record + 0x54u) = 0.0f;
    *(float *)(record + 0x58u) = 0.0f;
    *(float *)(record + 0x5cu) = 0.0f;
    *(float *)(record + 0x60u) = 0.0f;
    *(float *)(record + 0x64u) = 0.0f;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007d1448u;
    *(float *)(record + 0x68u) = 0.0f;
}
__attribute__((noinline)) void StateVariant_Handler_007E1AA0(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *first = *(const uint32_t **)(uintptr_t)0x007e1b54u;
    const uint32_t *second = *(const uint32_t **)(uintptr_t)0x007e1b58u;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x58u, (void *)(uintptr_t)0x007e1b44u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007e1b50u;
    *(float *)(record + 0x30u) = 0.0f;
    *(float *)(record + 0x34u) = 0.0f;
    record[0x38u] = 0u;
    *(float *)(record + 0x3cu) = 0.0f;
    *(uint32_t *)(record + 0x40u) = first[0];
    *(uint32_t *)(record + 0x44u) = first[1];
    *(uint32_t *)(record + 0x48u) = first[2];
    *(uint32_t *)(record + 0x4cu) = second[0];
    *(uint32_t *)(record + 0x50u) = second[1];
    *(uint32_t *)(record + 0x54u) = second[2];
}
__attribute__((noinline)) void StateVariant_Handler_007D172C(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *fallback = *(const uint32_t **)(uintptr_t)0x007d17dcu;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x4cu, (void *)(uintptr_t)0x007d17c8u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 0.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    {
        uint32_t masked = *(uint32_t *)(record + 0x30u) & 0xfffffe00u;
        *(uint32_t *)(record + 0x34u) = 0u;
        *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007d17d8u;
        *(uint32_t *)(record + 0x30u) = masked;
    }
    *(uint32_t *)(record + 0x38u) = fallback[0];
    *(uint32_t *)(record + 0x3cu) = fallback[1];
    *(uint32_t *)(record + 0x40u) = fallback[2];
    *(float *)(record + 0x44u) = 0.0f;
    *(float *)(record + 0x48u) = 0.0f;
}
__attribute__((noinline)) void StateVariant_Handler_007D0964(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    const uint32_t *fallback = *(const uint32_t **)(uintptr_t)0x007d0a44u;
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x58u, (void *)(uintptr_t)0x007d0a30u, allocator);
    const uint32_t mask = 0xfffffe00u;
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0x2cu) = 0u;
    *(uint32_t *)(record + 0x30u) &= mask;
    *(uint32_t *)(record + 0x34u) = 0u;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007d0a40u;
    record[0x38u] = 0u;
    record[0x39u] = 0xffu;
    record[0x3au] = 0u;
    *(uint32_t *)(record + 0x3cu) &= mask;
    *(uint32_t *)(record + 0x40u) = fallback[0];
    *(uint32_t *)(record + 0x44u) = fallback[1];
    *(uint32_t *)(record + 0x48u) = fallback[2];
    record[0x4cu] = 0u;
    *(float *)(record + 0x50u) = 0.0f;
    *(float *)(record + 0x54u) = 0.0f;
    *(uint32_t *)(record + 0x3cu) = *(const uint32_t *)state & mask;
}
__attribute__((noinline)) void StateVariant_Handler_007CF7B8(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x9cu, (void *)(uintptr_t)0x007cf83cu, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007cf848u;
    *(uint32_t *)(record + 0x2cu) = 0u;
    (void)StatusResource_InitializeStride_00421EA4(
        record + 0x30u, (void *)StateVariant_ChildInit_007CF79C, 0x0cu, 8u);
    *(float *)(record + 0x90u) = 0.0f;
    *(uint32_t *)(record + 0x94u) = 0u;
    record[0x98u] = 0u;
}
__attribute__((noinline)) void StateVariant_Handler_007D2134(void *state)
{
    uint32_t allocator = Object_GetAllocatorContext_0042167C(state);
    uint8_t *record = (uint8_t *)StatusResource_AllocateTagged_0047466C(
        0x7cu, (void *)(uintptr_t)0x007d21c4u, allocator);
    if (record == 0)
        return;
    record = (uint8_t *)StateVariant_RecordInit_004328E8(record, state);
    *(uint16_t *)(record + 0x1cu) = 3u;
    *(float *)(record + 0x20u) = 1.0f;
    *(float *)(record + 0x24u) = 1.0f;
    *(float *)(record + 0x28u) = 0.0f;
    *(uint32_t *)(record + 0u) = *(const uint32_t *)(uintptr_t)0x007d21d0u;
    record[0x30u] = 0u;
    record[0x31u] = 0xffu;
    *(uint32_t *)(record + 0x34u) = 0u;
    (void)StatusResource_InitializeStride_00421EA4(
        record + 0x38u, (void *)StateVariant_ChildInit_007D211C, 8u, 8u);
    *(float *)(record + 0x78u) = 0.0f;
}
typedef void (*StateVariantHandler)(void *state);
static StateVariantHandler const kStateVariantHandlers_00D46098[65] = {
    StateVariant_Handler_007E2BAC, StateVariant_Handler_007F19F4,
    StateVariant_Handler_007F19F4, StateVariant_Handler_007F2268,
    StateVariant_Handler_007F10C8, StateVariant_Handler_007E2BAC,
    StatusResource_DispatchStateVariantDefault, StateVariant_Handler_007DF94C,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StateVariant_Handler_007D172C,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StateVariant_Handler_007E0F8C, StateVariant_Handler_007DF94C,
    StateVariant_Handler_007E12E4, StateVariant_Handler_007D1368,
    StateVariant_Handler_007E1AA0, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StateVariant_Handler_007E1378,
    StateVariant_Handler_007CF7B8, StateVariant_Handler_007D2134,
    StateVariant_Handler_007D2134, StateVariant_Handler_007DFA48,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StateVariant_Handler_007E1F4C,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StateVariant_Handler_007CECE8,
    StateVariant_Handler_007D172C, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault, StatusResource_DispatchStateVariantDefault,
    StateVariant_Handler_007E2AE4, StateVariant_Handler_007E2AE4,
    StateVariant_Handler_007D0964, StatusResource_DispatchStateVariantDefault,
    StatusResource_DispatchStateVariantDefault
};
__attribute__((noinline)) void StatusResource_DispatchStateVariant(void *state)
{
    uint32_t value = StateMachineVariant_LookupCachedValue_00552008(state);
    if (value - 1u < 65u) {
        kStateVariantHandlers_00D46098[value - 1u](state);
        return;
    }
    StatusResource_DispatchStateVariantDefault(state);
}
__attribute__((noinline)) void StatusResource_ApplyEffectAndRefresh(void *state, void *resource,
                                          void *descriptor, uint32_t variant)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *resource_bytes = (uint8_t *)resource;
    uint8_t *descriptor_bytes = (uint8_t *)descriptor;
    uint32_t key;
    uint32_t *found;
    if (descriptor_bytes[0x29u] != 0u) {
        EffectEvent_Submit_00501208(
            state, *(void **)(resource_bytes + 0x390u) + 0x1acu);
        StatusResourceDispatch_004849D4(
            *(void **)(state_bytes + 0x0cu), resource, 3u, variant);
        return;
    }
    if ((state_bytes[6u] & 2u) != 0u ||
        (state_bytes[8u] & 0x10u) != 0u)
        return;
    *(uint32_t *)(resource_bytes + 0x94u) = 0u;
    key = *(uint32_t *)(descriptor_bytes + 0x24u);
    found = (uint32_t *)ResourceTable_Lookup_0049C5E4(&key);
    if ((resource_bytes[0x88u] & 0x20u) != 0u)
        return;
    state_bytes[8u] |= 2u;
    *(uint32_t *)(resource_bytes + 0x94u) = 0u;
    *(uint32_t *)(resource_bytes + 0x98u) = (uint32_t)-1;
    if (found != 0)
        *(uint32_t *)(state_bytes + 0x120u) = found[0x12cu / 4u];
}
__attribute__((noinline)) void StatusResource_ApplyAlternateEffect(void *state, void *resource,
                                         void *descriptor)
{
    uint8_t *descriptor_bytes = (uint8_t *)descriptor;
    if (descriptor_bytes[0x40u] != 1u)
        return;
    EffectEvent_Submit_00501208(
        state, *(void **)((uint8_t *)resource + 0x390u) + 0x104u);
    StatusResourceDispatch_004849D4(
        *(void **)((uint8_t *)state + 0x0cu), resource, 3u);
}
__attribute__((noinline)) void StatusResource_SubmitQueuedTransformEvents(void *unused, void *resource)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    const uint32_t generation_limit = 0x007fffffu;
    const uint32_t *variant_table = (const uint32_t *)(uintptr_t)0x00e11614u;
    uint32_t count = *(uint32_t *)(resource_bytes + 0x39cu);
    uint32_t index;
    (void)unused;
    for (index = 0u; index < count; ++index) {
        uint32_t event_word =
            *(uint32_t *)(resource_bytes + 0x3b0u + index * 4u);
        uint32_t variant = 0u;
        uint32_t generation = event_word >> 9;
        uint32_t table_index = (event_word << 23) >> 23;
        if (generation != generation_limit) {
            const uint32_t *entry = variant_table + table_index * 2u;
            if (entry[1] == generation)
                variant = entry[0];
        }
        StatusResource_EncodeTransformEvent(
            unused, resource,
            *(void **)(resource_bytes + 0x3a0u + index * 4u),
            (int)variant);
    }
    *(uint32_t *)(resource_bytes + 0x39cu) = 0u;
}
__attribute__((noinline)) void StatusResource_ReleaseTypeFourPool(void *unused, void *resource)
{
    void **dispatcher_slot = (void **)(uintptr_t)0x00d63854u;
    void *dispatcher = *dispatcher_slot;
    int key;
    (void)unused;
    if (dispatcher == 0) {
        dispatcher = Engine_LazySingletonGetter_003FD6E0();
        *dispatcher_slot = dispatcher;
    }
    key = *(int *)((uint8_t *)resource + 0x384u);
    if (ResourceTable_GetSignedByteByKey_00390B7C(dispatcher, key) == 4)
        EffectEventReleasePool_0048D320(dispatcher, key, 0);
}
__attribute__((noinline)) void StatusResource_MarkLinkedRecord(void *object, uint32_t key)
{
    void *record = StatusResource_LookupRecord_005415B8(
        (uint8_t *)object + 0xb284u, key);
    if (record != 0)
        *(uint32_t *)((uint8_t *)record + 0x24u) |= 0x402u;
}
__attribute__((noinline)) void StatusResource_RefreshRuntimeComponent(uint32_t index,
                                            void *descriptor)
{
    const uint8_t *active_flags = (const uint8_t *)(uintptr_t)0x0000123du;
    uint8_t *object = (uint8_t *)(uintptr_t)(index + 0x1000u);
    void *record = *(void **)(object + 0x240u);
    if (active_flags[index] == 0u || record == 0)
        return;
    if (descriptor != 0) {
        void *component =
            CachedComponent_ResolveClass1_0055709C(object, descriptor);
        if (component != 0 && (*(uint8_t *)((uint8_t *)component + 0x58u) & 1u))
            ResolveStatusDescriptor_0054E1A0(descriptor);
    }
    StatusResource_InitializeRuntimeClock_00411684(record);
    StatusResource_FlushPendingComponents_0041B9F4();
}
__attribute__((noinline)) int StatusResource_BuildAndPublishRecord(uint8_t *state, uint8_t *descriptor,
                                         uint32_t request, uint32_t flags,
                                         uint32_t *record_out)
{
    uint8_t descriptor_kind = descriptor[0];
    uint32_t selected_word;
    uint32_t type;
    uint32_t value = 0u;
    uint32_t record_value = 0u;
    int result;
    void *selected;
    if (descriptor_kind == 0u ||
        (descriptor_kind != 0u && *(void **)(descriptor + 4u) == 0))
        return 7;
    if (descriptor_kind == 3u)
        selected_word = *(uint32_t *)(*(void **)(descriptor + 4u));
    else
        selected_word = *(uint32_t *)(*(uint8_t **)(descriptor + 4u) + 0x24u);
    type = selected_word >> 28;
    selected = StatusResource_SelectVariantRecord_004A93C0(state, type);
    if (selected == 0)
        return 2;
    if (type == 4u) {
        uint32_t descriptor_word = 0u;
        void *linked = *(void **)(descriptor + 4u);
        if (descriptor_kind != 0u && linked != 0) {
            if (descriptor_kind == 3u)
                descriptor_word = *(uint32_t *)linked;
            else
                descriptor_word = *(uint32_t *)((uint8_t *)linked + 0x24u);
        }
        result = (int)(uintptr_t)StatusResource_LookupRecord_005415B8(
            state + 0x2ca1u, descriptor_word);
        if (result == 0 ||
            ((*(uint32_t *)((uint8_t *)(uintptr_t)result + 0x24u) & 0x400u) != 0u))
            return 2;
    }
    if (type == 2u) {
        value = *(uint32_t *)(state + 0x1ed34u);
    } else if (type == 3u) {
        return 8;
    } else if (type == 4u) {
        value = *(uint32_t *)(state + 0x1ed3cu);
    } else if (type == 5u) {
        value = *(uint32_t *)(state + 0x1ed40u);
    } else {
        value = *(uint32_t *)selected;
    }
    result = StatusResource_BuildRecord_0045EC28(
        state + 0x9cbcu, value, descriptor, &record_value, &value, request);
    if (result == 0) {
        StatusResource_NotifyBuildFailure_005361E4(
            state, record_value, *(uint32_t *)(descriptor + 4u), value & 0xffu);
        if (*(uint8_t *)(state + 0x123du) != 0u &&
            *(void **)(state + 0x1240u) != 0)
            StatusResource_ApplyBuiltRecord_004AF894(
                *(void **)(state + 0x1240u), record_value);
        if ((flags & 2u) != 0u) {
            void *status_descriptor =
                ResolveStatusDescriptor_0054E1A0((void *)(uintptr_t)record_value);
            void *channel_record = StatusRecord_LookupByKey_0050DD24(
                state + 0xf98cu,
                *(uint32_t *)((uint8_t *)status_descriptor + 0x20u));
            if (channel_record != 0)
                StatusRecord_SetChannelBitMasks_005403EC(
                    channel_record, 0u, 1u, 0u);
        }
    }
    if (record_out != 0)
        *record_out = record_value;
    return result;
}
__attribute__((noinline)) void StatusResource_RefreshIndexedRecord(uint32_t index)
{
    volatile const uint8_t *active_flags =
        (volatile const uint8_t *)(uintptr_t)0x0000123du;
    void *record;
    if (active_flags[index] == 0u)
        return;
    record = *(void **)((uint8_t *)(uintptr_t)(index + 0x1000u) + 0x240u);
    if (record != 0)
        Engine_RefreshIndexedRecord_00488FE8(record);
}
__attribute__((noinline)) void StatusResource_ClearCachedVector(void *resource)
{
    void * volatile *registry_slot =
        (void * volatile *)(uintptr_t)0x00d63590u;
    void *registry = *registry_slot;
    void *entry;
    if (registry == 0) {
        registry = Engine_ComponentRegistryGetter();
        *registry_slot = registry;
    }
    entry = Engine_ComponentEntryLookup_004D6028(
        *(void **)((uint8_t *)registry + 0x94u),
        *(uint32_t *)((uint8_t *)resource + 0x84u));
    if (entry != 0) {
        const float zero = 0.0f;
        *(float *)((uint8_t *)entry + 0x5cu) = zero;
        *(float *)((uint8_t *)entry + 0x60u) = zero;
    }
}
__attribute__((noinline)) int EffectState_RequestFactory(void *state, void *unused, void *descriptor,
                               void *unused_variant)
{
    volatile void *factory_slot = unused_variant;
    (void)unused;
    (void)unused_variant;
    if (*(uint8_t *)((uint8_t *)descriptor + 0x29u) != 1u)
        return 0;
    factory_slot = EffectState_FactoryGetter_00445194();
    ActorStateMachine_RequestStateByFactory_0036BEF0(
        *(void **)((uint8_t *)state + 0x30u), (void *)&factory_slot);
    return 0;
}
static int EffectState_PlayConfiguredAction(void *state, uint32_t action,
                                             uint32_t parameter)
{
    uint32_t record[3];
    StateParameterRecord_Init_003B530C(record);
    record[0] = action;
    record[1] = parameter;
    Actor_PlayActionByHash_0036FCA8(
        *(uint32_t *)((uint8_t *)state + 0x30u), 5, record, 1, 1);
    return 0;
}
__attribute__((noinline)) int EffectState_PlayConfiguredActionA(void *state)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *config = *(uint8_t **)(state_bytes + 0x34u);
    uint8_t *name = *(uint8_t **)(config + 0xa0u);
    if (*name == 0u)
        return 0;
    return EffectState_PlayConfiguredAction(
        state, *(uint32_t *)(config + 0x9cu), *(uint32_t *)(config + 0xa0u));
}
__attribute__((noinline)) int EffectState_PlayConfiguredActionB(void *state, void *unused,
                                      void *descriptor)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *config = *(uint8_t **)(state_bytes + 0x34u);
    uint8_t *name = *(uint8_t **)(config + 0x74u);
    (void)unused;
    if (*(uint8_t *)((uint8_t *)descriptor + 0x40u) != 1u || *name == 0u)
        return 0;
    return EffectState_PlayConfiguredAction(
        state, *(uint32_t *)(config + 0x70u), *(uint32_t *)(config + 0x74u));
}
__attribute__((noinline)) int EffectState_PlayConfiguredActionC(void *state, void *unused,
                                      void *descriptor)
{
    uint8_t *state_bytes = (uint8_t *)state;
    (void)unused;
    if (state_bytes[0x3du] != 0u ||
        *(uint8_t *)((uint8_t *)descriptor + 0x29u) == 0u)
        return 0;
    {
        uint8_t *config = *(uint8_t **)(state_bytes + 0x34u);
        uint8_t *name = *(uint8_t **)(config + 0xccu);
        if (*name == 0u)
            return 0;
        return EffectState_PlayConfiguredAction(
            state, *(uint32_t *)(config + 0xc8u), *(uint32_t *)(config + 0xccu));
    }
}
__attribute__((noinline)) int EffectState_ApplyComponentValue(void *state, void *unused,
                                    void *descriptor)
{
    uint8_t *state_bytes = (uint8_t *)state;
    void *component;
    void *callback_result;
    (void)unused;
    if (state_bytes[0x3du] != 0u)
        return 0;
    component = *(void **)((uint8_t *)descriptor + 0x2cu);
    if (component == 0)
        return 0;
    callback_result = ((void *(*)(void *))(*(void ***)component)[0x74u / 4u])(
        component);
    if (EffectState_CheckComponent_004D1D8C(callback_result) == 0)
        return 0;
    EffectState_ApplyValue_004333CC(
        state, EffectState_BuildValue_004217E0(descriptor));
    return 0;
}
float StatusResourceAdvanceTimer(void *unused, void *resource, void *provider,
                                 float hidden_delta);
static float StatusResourceApplyTypeOneRate(void *resource, void *provider,
                                            float state_factor)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    void **vtable = *(void ***)provider;
    float blend = state_factor;
    float current = *(float *)(resource_bytes + 0x3b0u);
    float callback;
    if (blend < 0.0f)
        blend = 0.0f;
    if (blend > 1.0f)
        blend = 1.0f;
    callback = ((float (*)(void *))vtable[0x60u / sizeof(void *)])(
        provider);
    current += (callback * current - current) * blend;
    *(float *)(resource_bytes + 0x78u) =
        *(float *)(resource_bytes + 0x114u) *
        *(float *)(resource_bytes + 0x118u) * current;
    if (resource != (void *)(uintptr_t)0xfffffec4u) {
        *(uint32_t *)(resource_bytes + 0x14cu) =
            *(uint32_t *)(resource_bytes + 0x148u);
        *(float *)(resource_bytes + 0x148u) = blend;
        *(float *)(resource_bytes + 0x150u) =
            ((float (*)(void *))vtable[0x60u / sizeof(void *)])(provider);
    }
    return callback;
}
static void StatusResourceFinalizeTypeOne(void *batch_state, void *resource,
                                          float state_factor,
                                          unsigned transitioned)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    if (Engine_StatusVariantModeByte() == 0 &&
        (resource_bytes[0x88u] & 0x40u) == 0u) {
        float point[4] = {
            *(float *)(resource_bytes + 0x6cu),
            *(float *)(resource_bytes + 0x70u),
            *(float *)(resource_bytes + 0x74u),
            *(float *)(resource_bytes + 0xdcu)
        };
        if (Engine_SixPlaneContainmentTest(point, point[3]) == 0) {
            if ((resource_bytes[0x88u] & 2u) != 0u)
                StatusResourceDispatch_004849D4(
                    *(void **)((uint8_t *)batch_state + 4u), resource, 3u, 0u);
        } else {
            resource_bytes[0x88u] |= 2u;
        }
    }
    union {
        float value;
        uint32_t bits;
    } state_factor_bits = { state_factor };
    if ((int32_t)state_factor_bits.bits < (int32_t)0x3f800000u &&
        transitioned == 0u)
        return;
    resource_bytes[0x298u] =
        (uint8_t)((resource_bytes[0x298u] & (uint8_t)~2u) | 8u);
    StatusResourceDispatch_004849D4(
        *(void **)((uint8_t *)batch_state + 4u), resource, 2u, 0u);
}
unsigned StatusResourceApplyMotionAndState(void *output_record,
                                               void *resource);
unsigned StatusResourceThresholdCrossingCheck(void *output_record,
                                                   void *resource);
__attribute__((noinline)) void StatusResource_EncodeTransformEvent(void *unused, void *resource,
                                         void *event, int variant)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    uint8_t *event_bytes = (uint8_t *)event;
    float payload[12];
    uint32_t encoded;
    float q0;
    float q1;
    float q2;
    float q3;
    float scale;
    float event_scale;
    float doubled_q0;
    float doubled_q1;
    float q2_twice_squared;
    float one_minus_q0_term;
    float f15;
    float f12;
    float f9;
    float f7;
    float f13;
    float f14;
    float f2;
    float f1;
    float f3;
    const float zero = 0.0f;
    const float one = 1.0f;
    const float two = 2.0f;
    (void)unused;
    if (variant == 0 || *(int32_t *)(event_bytes + 0x18u) < 0)
        return;
    q0 = *(float *)(resource_bytes + 0x5cu);
    q1 = *(float *)(resource_bytes + 0x60u);
    q2 = *(float *)(resource_bytes + 0x64u);
    q3 = *(float *)(resource_bytes + 0x68u);
    scale = *(float *)(resource_bytes + 0x58u);
    event_scale = *(float *)(event_bytes + 0x50u);
    doubled_q0 = q0 * two;
    doubled_q1 = q1 * two;
    q2_twice_squared = q2 * two * q2;
    one_minus_q0_term = one - doubled_q0 * q0;
    f15 = (doubled_q0 * q1 + q2 * two * q3) * scale;
    f12 = (doubled_q0 * q2 - doubled_q1 * q3) * scale;
    f9 = (doubled_q0 * q1 - q2 * two * q3) * scale;
    f7 = (one_minus_q0_term - q2_twice_squared) * scale;
    f13 = (doubled_q1 * q2 - doubled_q0 * q3) * scale;
    f14 = (doubled_q1 * q2 + doubled_q0 * q3) * scale;
    f2 = ((one - doubled_q1 * q1) - q2_twice_squared) * scale;
    f1 = (doubled_q0 * q2 + doubled_q1 * q3) * scale;
    f3 = (one_minus_q0_term - doubled_q1 * q1) * scale;
    payload[0] = f2 * event_scale + f9 * zero + f1 * zero;
    payload[1] = f2 * zero + f9 * event_scale + f1 * zero;
    payload[2] = f2 * zero + f9 * zero + f1 * event_scale;
    payload[3] = f9 * zero + f1 * zero +
                 *(float *)(resource_bytes + 0x6cu) + f2 * zero;
    payload[4] = f15 * event_scale + f7 * zero + f13 * zero;
    payload[5] = f15 * zero + f7 * event_scale + f13 * zero;
    payload[6] = f15 * zero + f7 * zero + f13 * event_scale;
    payload[7] = f7 * zero + f13 * zero +
                 *(float *)(resource_bytes + 0x70u) + f15 * zero;
    payload[8] = f12 * event_scale + f14 * zero + f3 * zero;
    payload[9] = f12 * zero + f14 * event_scale + f3 * zero;
    payload[10] = f12 * zero + f14 * zero + f3 * event_scale;
    payload[11] = f14 * zero + f3 * zero +
                  *(float *)(resource_bytes + 0x74u) + f12 * zero;
    Engine_StatusEventIdEncode(&encoded, *(int *)(event_bytes + 0x18u),
                               payload, 0, variant);
}
__attribute__((noinline)) void StatusResource_SubmitVariantEvent(void *unused, void *resource)
{
    static void **const status_registry_slot =
        (void **)(uintptr_t)0x00d63578u;
    static void **const dispatcher_slot =
        (void **)(uintptr_t)0x00d63854u;
    static void **const channel_state_slot =
        (void **)(uintptr_t)0x00d6364cu;
    static const int32_t *const channel_offset =
        (const int32_t *)(uintptr_t)0x0040b858u;
    static uint8_t *const channel_counter =
        (uint8_t *)(uintptr_t)0x00d5ee49u;
    static uint8_t *const channel_serial =
        (uint8_t *)(uintptr_t)0x00d4e2f8u;
    uint8_t record[0x28] = {0};
    void *registry;
    void *status_record;
    void *descriptor;
    void *channel_state;
    void *dispatcher;
    uint8_t *channel;
    int event_type;
    uint8_t serial;
    int8_t channel_id;
    (void)unused;
    *(float *)(record + 0x0cu) = 1.0f;
    *(float *)(record + 0x18u) = 1.0f;
    *(uint32_t *)(record + 0x1cu) =
        *(uint32_t *)((uint8_t *)resource + 0x158u);
    *(uint32_t *)(record + 0x20u) =
        *(uint32_t *)((uint8_t *)resource + 0x15cu);
    *(uint32_t *)(record + 0x24u) =
        *(uint32_t *)((uint8_t *)resource + 0x160u);
    registry = *status_registry_slot;
    if (registry == 0) {
        registry = Engine_LazySingletonGetter_0054EFA8();
        *status_registry_slot = registry;
    }
    status_record = StatusTable_LookupById_0051B688(
        (uint8_t *)registry + 0x1e9acu,
        *(uint16_t *)((uint8_t *)resource + 0x170u));
    if (status_record == 0)
        return;
    descriptor = StatusRecord_ResolveDescriptor_00498F34(status_record);
    if (descriptor == 0)
        return;
    event_type = StatusDescriptor_SelectVariant_004990A8(
        (uint8_t *)descriptor + 0x80u, 2, 0);
    if (event_type < 0)
        return;
    dispatcher = *dispatcher_slot;
    if (dispatcher == 0) {
        dispatcher = Engine_LazySingletonGetter_003FD6E0();
        *dispatcher_slot = dispatcher;
    }
    channel_state = *channel_state_slot;
    if (channel_state == 0) {
        channel_state = Engine_LazySingletonGetter_00422CC8();
        *channel_state_slot = channel_state;
    }
    channel_id = *(int8_t *)((uint8_t *)channel_state + *channel_offset);
    channel = channel_counter;
    if (*channel == 0u) {
        serial = (uint8_t)(*channel_serial + 1u);
        *channel_serial = serial;
        *channel = serial;
    }
    EffectEvent_Submit(dispatcher,
                       (uint32_t)(int32_t)channel_id |
                           ((uint32_t)*channel << 16),
                       (uint32_t)event_type, record);
}
__attribute__((noinline)) void StatusResource_PrepareAndSubmitVariantEvent(void *unused,
                                                 void *resource)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    struct EventArgumentBlock {
        uint32_t output_word;
        float output[2];
        float input[3];
    } arguments;
    void *provider = *(void **)(resource_bytes + 0x138u);
    uint16_t key = *(uint16_t *)(resource_bytes + 0x2acu);
    arguments.output_word = *(uint32_t *)(resource_bytes + 0x2bcu);
    arguments.output[0] = *(float *)(resource_bytes + 0x2c0u);
    arguments.output[1] = *(float *)(resource_bytes + 0x2c4u);
    arguments.input[0] = *(float *)(resource_bytes + 0x2e0u);
    arguments.input[1] = *(float *)(resource_bytes + 0x2e4u);
    arguments.input[2] = *(float *)(resource_bytes + 0x2e8u);
    *(uint32_t *)(resource_bytes + 0x158u) = arguments.output_word;
    *(float *)(resource_bytes + 0x15cu) = arguments.output[0];
    *(float *)(resource_bytes + 0x160u) = arguments.output[1];
    *(float *)(resource_bytes + 0x164u) = arguments.input[0];
    *(float *)(resource_bytes + 0x168u) = arguments.input[1];
    *(float *)(resource_bytes + 0x16cu) = arguments.input[2];
    *(uint16_t *)(resource_bytes + 0x170u) = key;
    {
        void **vtable = *(void ***)provider;
        uint32_t provider_value =
            ((uint32_t (*)(void *))vtable[0x64u / sizeof(void *)])(provider);
    Engine_StatusEventRecordBuild_00492648(&arguments.output_word,
                                           arguments.input, key,
                                           provider_value);
    }
    StatusResource_SubmitVariantEvent(unused, resource);
}
__attribute__((noinline)) void StatusResource_SubmitPositionUpdate(void *unused, void *resource)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    float point[3];
    (void)unused;
    point[0] = *(float *)(resource_bytes + 0x6cu);
    point[1] = *(float *)(resource_bytes + 0x70u);
    point[2] = *(float *)(resource_bytes + 0x74u);
    Engine_SubmitPositionUpdate_0044048C(point);
}
static void StatusResourceNormalizeVector(float vector[3],
                                           const float fallback[3])
{
    float length_squared = vector[0] * vector[0] +
                           vector[1] * vector[1] +
                           vector[2] * vector[2];
    if (length_squared <= 0.0f) {
        vector[0] = fallback[0];
        vector[1] = fallback[1];
        vector[2] = fallback[2];
        return;
    }
    {
        float scale = 1.0f / __builtin_sqrtf(length_squared);
        vector[0] *= scale;
        vector[1] *= scale;
        vector[2] *= scale;
    }
}
static float StatusResourceClampedAcos(float value)
{
    union {
        float value;
        uint32_t bits;
    } input = { value };
    if (input.bits > 0xbf800000u)
        input.value = -1.0f;
    else if ((int32_t)input.bits > (int32_t)0x3f800000u)
        input.value = 1.0f;
    value = input.value;
    return Trig_AcosCore(value);
}
static void StatusResourceHealthBuildQuaternion(float q[5],
                                                const float unit[3],
                                                const float reference[3],
                                                int first_path)
{
    float s0 = unit[2];
    float s1 = reference[1] * s0;
    float s2 = reference[0] * unit[1];
    float s3 = unit[1];
    float s4 = reference[2] * unit[0];
    float s5 = reference[1];
    float s6 = unit[0];
    float s8 = reference[2];
    float s9 = reference[0];
    int r0;
    int r1;
    int r2;
    int r3;
    int r12;
    float length;
    s1 -= s8 * s3;
    s2 -= s5 * s6;
    s4 -= s9 * s0;
    length = __builtin_sqrtf(s1 * s1 + s4 * s4 + s2 * s2);
    {
        float inverse = 1.0f / length;
        s1 *= inverse;
        s8 = s4 * inverse;
        s4 = s2 * inverse;
    }
    s2 = s0 * s1;
    s9 = s6 * s8;
    s5 = s3 * s4;
    s2 -= s6 * s4;
    s9 -= s3 * s1;
    s5 -= s0 * s8;
    r2 = s0 > s2;
    r3 = s2 > s1;
    r12 = s0 > s1;
    r0 = 0;
    r1 = 0;
    if (!(r2 && r3)) {
        s0 = -s0;
        s5 = -s5;
        r0 = 1;
    }
    if (r2 || r12) {
        s1 = -s1;
        s3 = -s3;
        r1 = 1;
    }
    if (!(r12 && !r3)) {
        s2 = -s2;
        s4 = -s4;
    }
    if (first_path) {
        s5 = s8 - s5;
        s1 = s1 + s2;
        s2 = s9 - s3;
        s4 = s6 - s4;
        s0 = s1 + s0;
        s3 = s0 + 1.0f;
        length = __builtin_sqrtf(s3);
        s1 = 1.0f / length;
        s1 *= 0.5f;
        s2 *= s1;
        s4 *= s1;
        s0 *= s1;
        s1 = s3 * s1;
        if (r0) {
            s3 = s1;
            s1 = s2;
            s2 = s3;
            s3 = s0;
            s0 = s4;
            s4 = s3;
        }
        if (r1) {
            s3 = s4;
            s4 = s2;
            s2 = s3;
            s3 = s1;
            s1 = s0;
            s0 = s3;
        }
        s3 = s1;
    } else {
        s5 = s8 - s5;
        s2 = s1 + s2;
        s6 = s6 - s4;
        s1 = s9 - s3;
        s0 = s2 + s0;
        s4 = s0 + 1.0f;
        length = __builtin_sqrtf(s4);
        s2 = 1.0f / length;
        s3 = s2 * 0.5f;
        s2 = s1 * s3;
        s1 = s6 * s3;
        s0 = s5 * s3;
        s3 = s4 * s3;
        if (r0) {
            s4 = s3;
            s3 = s2;
            s2 = s4;
            s4 = s0;
            s0 = s1;
            s1 = s4;
        }
        if (r1) {
            s4 = s1;
            s1 = s2;
            s2 = s4;
            s4 = s3;
            s3 = s0;
            s0 = s4;
        }
        s4 = s1;
    }
    q[0] = s0;
    q[1] = s1;
    q[2] = s2;
    q[3] = s3;
    q[4] = s4;
}
__attribute__((noinline)) void StatusResourceHealthBuildAndEvaluate(void *output_record, void *resource,
                                          float hidden_delta)
{
    uint8_t *output = (uint8_t *)output_record;
    const uint8_t *resource_bytes = (const uint8_t *)resource;
    const float *default_vector = (const float *)(uintptr_t)0x00dc249cu;
    float direction[3];
    float length;
    float dot;
    float angle_a;
    float angle_b;
    uint32_t flags;
    union {
        float value;
        uint32_t bits;
    } compare;
    direction[0] = default_vector[0];
    direction[1] = default_vector[1];
    direction[2] = default_vector[2];
    if (HealthStatusParameter_DefaultBuild(output_record, resource,
                                             direction) == 0) {
        output[5] = 0;
        return;
    }
    {
        float *timer = (float *)(output + 0x10cu);
        if (*timer == 0.0f) {
            output[5] = 0;
        } else {
            *timer -= hidden_delta;
            if (*timer <= 0.0f)
                *timer = 0.0f;
            output[5] = 1;
        }
    }
    direction[0] -= *(const float *)(resource_bytes + 0x2b0u);
    direction[1] -= *(const float *)(resource_bytes + 0x2b4u);
    direction[2] -= *(const float *)(resource_bytes + 0x2b8u);
    length = __builtin_sqrtf(direction[0] * direction[0] +
                             direction[1] * direction[1] +
                             direction[2] * direction[2]);
    {
        float inverse = 1.0f / length;
        direction[0] *= inverse;
        direction[1] *= inverse;
        direction[2] *= inverse;
    }
    dot = *(const float *)(output + 0xdcu) *
              *(const float *)(output + 0x48u) +
          *(const float *)(output + 0xe0u) *
              *(const float *)(output + 0x4cu) +
          *(const float *)(output + 0xe4u) *
              *(const float *)(output + 0x50u);
    compare.value = dot;
    if ((int32_t)compare.bits <= (int32_t)0x3f7d70a4u) {
        flags = output[0x7cu];
        if ((flags & 2u) == 0u) {
            float x = *(const float *)(output + 0xe0u);
            float y = *(const float *)(output + 0xe4u);
            float z = *(const float *)(output + 0xdcu);
            float a = *(const float *)(output + 0x70u);
            float b = *(const float *)(output + 0x74u);
            float c = *(const float *)(output + 0x6cu);
            float p = *(const float *)(output + 0x4cu);
            float q = *(const float *)(output + 0x50u);
            float r = *(const float *)(output + 0x48u);
            dot = (x * b - y * a) * (p * b - q * a) +
                  (y * c - z * b) * (q * c - r * b) +
                  (z * a - x * c) * (r * a - p * c);
            angle_a = StatusResourceClampedAcos(dot);
            if ((angle_a < 0.0f ? -angle_a : angle_a) >
                *(const float *)(output + 0x40u))
                output[0x7cu] |= 2u;
        }
    }
    if ((output[0x7cu] & 1u) == 0u) {
        dot = *(const float *)(output + 0x48u) *
                  *(const float *)(output + 0x6cu) +
              *(const float *)(output + 0x4cu) *
                  *(const float *)(output + 0x70u) +
              *(const float *)(output + 0x50u) *
                  *(const float *)(output + 0x74u);
        angle_a = StatusResourceClampedAcos(dot);
        dot = *(const float *)(output + 0xdcu) *
                  *(const float *)(output + 0x6cu) +
              *(const float *)(output + 0xe0u) *
                  *(const float *)(output + 0x70u) +
              *(const float *)(output + 0xe4u) *
                  *(const float *)(output + 0x74u);
        angle_b = StatusResourceClampedAcos(dot);
        dot = angle_b - angle_a;
        if ((dot < 0.0f ? -dot : dot) >
            *(const float *)(output + 0x44u))
            output[0x7cu] |= 1u;
    }
    flags = output[0x7cu] & 3u;
    if ((flags & 3u) != 3u &&
        (*(const float *)(resource_bytes + 0xb8u) != 0.0f ||
         *(const float *)(resource_bytes + 0xbcu) != 0.0f ||
         *(const float *)(resource_bytes + 0xc0u) != 0.0f)) {
        static const float *const reference_a =
            (const float *)(uintptr_t)0x00dc24c0u;
        static const float *const reference_b =
            (const float *)(uintptr_t)0x00dc24ccu;
        float unit[3] = { direction[0], direction[1], direction[2] };
        float q[5];
        float reference_dot = unit[0] * reference_a[0] +
                              unit[1] * reference_a[1] +
                              unit[2] * reference_a[2];
        union {
            float value;
            uint32_t bits;
        } reference_compare = { reference_dot };
        const float *reference =
            ((int32_t)reference_compare.bits < (int32_t)0x3f666666u)
                ? reference_a : reference_b;
        float blend = (*(const float *)(resource_bytes + 0x78u) + 1.0f) *
                      0.5f;
        float s7;
        float s8;
        float s9;
        float s10;
        float s5;
        float s6;
        float s1;
        StatusResourceHealthBuildQuaternion(q, unit, reference,
                                             reference == reference_a);
        s1 = *(const float *)(resource_bytes + 0xb8u) * blend;
        s6 = *(const float *)(resource_bytes + 0xbcu) * blend;
        s5 = *(const float *)(resource_bytes + 0xc0u) * blend;
        s7 = s1 * q[3];
        s8 = s1 * q[0];
        s9 = s6 * q[2];
        s10 = s1 * q[2];
        s7 -= q[0] * s6;
        s8 += q[3] * s6;
        s9 -= q[4] * s1;
        s10 += q[4] * s6;
        s7 += q[4] * s5;
        s8 -= q[2] * s5;
        s9 += q[3] * s5;
        s10 += q[0] * s5;
        s5 = q[3] * s7;
        s6 = q[2] * s8;
        s1 = q[0] * s7;
        s5 -= q[0] * s8;
        s6 -= q[4] * s7;
        s1 += q[3] * s8;
        s5 += q[4] * s9;
        s6 += q[3] * s9;
        s1 -= q[2] * s9;
        s5 += q[2] * s10;
        s6 += q[0] * s10;
        direction[0] += s5;
        direction[1] += s1;
        direction[2] += s6;
        *(float *)(output + 0x28u) = direction[0];
        *(float *)(output + 0x2cu) = direction[1];
        *(float *)(output + 0x30u) = direction[2];
    }
    if ((output[6] & 1u) != 0u)
        output[5] = 1;
}
static void StatusResourceCross(float output[3], const float left[3],
                                 const float right[3])
{
    output[0] = left[0] * right[1] - left[1] * right[0];
    output[1] = left[1] * right[2] - left[2] * right[1];
    output[2] = left[2] * right[0] - left[0] * right[2];
}
__attribute__((noinline)) void StatusResource_UpdateTargetVectors(void *unused, void *resource)
{
    static void **registry_slot = (void **)(uintptr_t)0x00d63590u;
    static const float *const fallback =
        (const float *)(uintptr_t)0x00dc24b4u;
    uint8_t *bytes = (uint8_t *)resource;
    void *provider = *(void **)(bytes + 0x378u);
    void *registry;
    void *target;
    void *key;
    void **vtable;
    float first[3];
    float second[3];
    float first_length;
    float second_length;
    (void)unused;
    if (provider == 0)
        return;
    vtable = *(void ***)provider;
    key = ((void *(*)(void *))vtable[0x34u / sizeof(void *)])(provider);
    registry = *registry_slot;
    if (registry == 0) {
        registry = Engine_ComponentRegistryGetter();
        *registry_slot = registry;
    }
    if (registry == 0)
        return;
    target = Engine_ComponentEntryLookup(*(void **)((uint8_t *)registry + 0x94u),
                                         (uint32_t)(uintptr_t)key);
    if (target == 0 || ((((uint8_t *)target)[0x20u] & 7u) != 2u))
        return;
    first[0] = *(float *)(bytes + 0x7cu) - *(float *)((uint8_t *)target + 0x0u);
    first[1] = *(float *)(bytes + 0x80u) - *(float *)((uint8_t *)target + 0x4u);
    first[2] = *(float *)(bytes + 0x84u) - *(float *)((uint8_t *)target + 0x8u);
    first_length = first[0] * first[0] + first[1] * first[1] +
                   first[2] * first[2];
    if (first_length > 0.0f) {
        float length = __builtin_sqrtf(first_length);
        float scale = 1.0f / length;
        first[0] *= scale;
        first[1] *= scale;
        first[2] *= scale;
        first_length = length;
    } else {
        first[0] = fallback[0];
        first[1] = fallback[1];
        first[2] = fallback[2];
    }
    *(float *)((uint8_t *)target + 0x0cu) = first[0];
    *(float *)((uint8_t *)target + 0x10u) = first[1];
    *(float *)((uint8_t *)target + 0x14u) = first[2];
    *(float *)((uint8_t *)target + 0x18u) = first_length;
    ((uint8_t *)provider)[0xa4u] &= (uint8_t)~1u;
    second[0] = *(float *)(bytes + 0x7cu) - *(float *)(bytes + 0x6cu);
    second[1] = *(float *)(bytes + 0x80u) - *(float *)(bytes + 0x70u);
    second[2] = *(float *)(bytes + 0x84u) - *(float *)(bytes + 0x74u);
    second_length = second[0] * second[0] + second[1] * second[1] +
                    second[2] * second[2];
    *(float *)((uint8_t *)target + 0x44u) = *(float *)(bytes + 0x6cu);
    *(float *)((uint8_t *)target + 0x48u) = *(float *)(bytes + 0x70u);
    *(float *)((uint8_t *)target + 0x4cu) = *(float *)(bytes + 0x74u);
    if (second_length > 0.0f) {
        float length = __builtin_sqrtf(second_length);
        float scale = 1.0f / length;
        second[0] *= scale;
        second[1] *= scale;
        second[2] *= scale;
        second_length = length;
    } else {
        second[0] = fallback[0];
        second[1] = fallback[1];
        second[2] = fallback[2];
        second_length = 0.0f;
    }
    *(float *)((uint8_t *)target + 0x50u) = second[0];
    *(float *)((uint8_t *)target + 0x54u) = second[1];
    *(float *)((uint8_t *)target + 0x58u) = second[2];
    *(float *)((uint8_t *)target + 0x5cu) = second_length;
    *(float *)((uint8_t *)target + 0x60u) = 0.0f;
}
void StatusResourceAdvanceElapsedMode(void *batch_state, void *resource,
                                       float hidden_delta)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    void *provider = *(void **)(resource_bytes + 0x138u);
    unsigned provider_mode =
        (unsigned)((int (*)(void *))(*(void ***)provider)[0x6cu / 4u])(
            provider);
    const float *limits = (const float *)(uintptr_t)0x00d45ea4u;
    float ratio;
    if (provider_mode == 1u) {
        float candidate;
        float scale;
        *(float *)(resource_bytes + 0x2cu) += hidden_delta;
        ratio = *(float *)(resource_bytes + 0x2cu) / limits[0];
        candidate = *(float *)(resource_bytes + 0x28u) * (1.0f - ratio);
        scale = candidate >= 0.01f ? candidate : 0.01f;
        if (scale > *(float *)(resource_bytes + 0x28u))
            scale = *(float *)(resource_bytes + 0x28u);
        {
            *(float *)(resource_bytes + 0x78u) =
                *(float *)(resource_bytes + 0x114u) *
                *(float *)(resource_bytes + 0x118u) * scale;
        }
    } else if (provider_mode == 2u) {
        *(float *)(resource_bytes + 0x2cu) += hidden_delta;
        ratio = *(float *)(resource_bytes + 0x2cu) / limits[1];
    } else {
        ratio = 1.0f;
    }
    {
        union {
            float value;
            uint32_t bits;
        } ratio_bits = { ratio };
        if ((int32_t)ratio_bits.bits < (int32_t)0x3f800000u)
            return;
    }
    resource_bytes[0x298u] |= 8u;
    StatusResourceDispatch_004849D4(*(void **)((uint8_t *)batch_state + 4u),
                                    resource, 3u, 0u);
}
void StatusResourceAdvanceTypeOne(void *batch_state, void *resource,
                                  float hidden_delta)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    void *provider = *(void **)(resource_bytes + 0x138u);
    void **vtable = *(void ***)provider;
    float old_timer = *(float *)(resource_bytes + 0x36cu);
    float timer = old_timer - hidden_delta;
    unsigned provider_mode;
    unsigned transitioned = 0u;
    float state_factor = 1.0f;
    resource_bytes[9] &= (uint8_t)~3u;
    if (timer <= 0.0f) {
        timer = 0.0f;
        *(float *)(resource_bytes + 0x36cu) = timer;
        *(float *)(resource_bytes + 0x114u) = 0.0f;
        state_factor = 0.0f;
    } else {
        float ratio = timer / old_timer;
        *(float *)(resource_bytes + 0x36cu) = timer;
        ((void (*)(void *))vtable[0x58u / sizeof(void *)])(provider);
        ((void (*)(void *))vtable[0x5cu / sizeof(void *)])(provider);
        *(float *)(resource_bytes + 0x114u) =
            1.0f + (timer - 1.0f) * ratio;
    }
    provider_mode = (unsigned)((int (*)(void *))
        vtable[0x68u / sizeof(void *)])(provider);
    if (provider_mode == 0u || provider_mode == 2u)
        state_factor = StatusResourceAdvanceTimer(
            batch_state, resource, provider, hidden_delta);
    else if (provider_mode == 1u) {
        state_factor = StatusResourceIntegrateMotion(
            batch_state, resource, provider, hidden_delta);
        transitioned = (resource_bytes[9] & 8u) >> 3;
    } else if (provider_mode == 3u) {
        StatusResourceIntegrateMotion(batch_state, resource, provider,
                                      hidden_delta);
        state_factor = StatusResourceAdvanceTimer(
            batch_state, resource, provider, hidden_delta);
    }
    if (provider_mode == 0u)
        transitioned = (resource_bytes[9] & 8u) >> 3;
    union {
        float value;
        uint32_t bits;
    } state_factor_bits = { state_factor };
    if ((int32_t)state_factor_bits.bits > (int32_t)0x37800000u)
        StatusResourceApplyTypeOneRate(resource, provider, state_factor);
    StatusResourceFinalizeTypeOne(batch_state, resource, state_factor,
                                  transitioned);
}
__attribute__((noinline)) void StatusResource_AngularEvaluator(void *output_record)
{
    static const float *const fallback_axis_a =
        (const float *)(uintptr_t)0x00dc24b4u;
    static const float *const fallback_axis_b =
        (const float *)(uintptr_t)0x00dc24c0u;
    static const float *const fallback_axis_zero =
        (const float *)(uintptr_t)0x00dc24ccu;
    uint8_t *output = (uint8_t *)output_record;
    const float first_reference[3] = {
        *(float *)(output + 0x70u),
        *(float *)(output + 0x74u),
        *(float *)(output + 0x6cu)
    };
    const float second_reference[3] = {
        *(float *)(output + 0x74u),
        *(float *)(output + 0x6cu),
        *(float *)(output + 0x70u)
    };
    const float first[3] = {
        *(float *)(output + 0xe0u),
        *(float *)(output + 0xe4u),
        *(float *)(output + 0xdcu)
    };
    const float second[3] = {
        *(float *)(output + 0xc4u),
        *(float *)(output + 0xc8u),
        *(float *)(output + 0xccu)
    };
    const float final_reference[3] = {
        *(float *)(output + 0x6cu),
        *(float *)(output + 0x70u),
        *(float *)(output + 0x74u)
    };
    const float final_left[3] = {
        *(float *)(output + 0xdcu),
        *(float *)(output + 0xe0u),
        *(float *)(output + 0xe4u)
    };
    float axis_a[3];
    float axis_b[3];
    float axis_c[3];
    float angle_a;
    float angle_b;
    *(float *)(output + 0xecu) = 0.0f;
    *(float *)(output + 0xf0u) = 0.0f;
    for (unsigned lane = 0; lane < 3u; ++lane) {
        ((float *)(output + 0xf4u))[lane] = fallback_axis_a[lane];
        ((float *)(output + 0x100u))[lane] = fallback_axis_b[lane];
    }
    if (*(float *)(output + 0xe8u) == 0.0f || output[5] != 0u)
        return;
    if ((output[0x7cu] & 2u) == 0u) {
        StatusResourceCross(axis_a, first, first_reference);
        StatusResourceNormalizeVector(axis_a, fallback_axis_zero);
        StatusResourceCross(axis_b, second, second_reference);
        StatusResourceNormalizeVector(axis_b, fallback_axis_zero);
        angle_a = StatusResourceClampedAcos(
            axis_a[0] * axis_b[0] + axis_a[1] * axis_b[1] +
            axis_a[2] * axis_b[2]);
        *(float *)(output + 0xf0u) = angle_a;
        StatusResourceCross(axis_c, axis_a, axis_b);
        StatusResourceNormalizeVector(axis_c, fallback_axis_b);
        for (unsigned lane = 0; lane < 3u; ++lane)
            ((float *)(output + 0x100u))[lane] = axis_c[lane];
    } else {
        for (unsigned lane = 0; lane < 3u; ++lane)
            ((float *)(output + 0x100u))[lane] = fallback_axis_zero[lane];
    }
    if ((output[0x7cu] & 1u) != 0u)
        return;
    angle_a = StatusResourceClampedAcos(
        second[0] * final_reference[0] +
        second[1] * final_reference[1] +
        second[2] * final_reference[2]);
    angle_b = StatusResourceClampedAcos(
        final_left[0] * final_reference[0] +
        final_left[1] * final_reference[1] +
        final_left[2] * final_reference[2]);
    *(float *)(output + 0xecu) = angle_b - angle_a;
    StatusResourceCross(axis_c, final_left, final_reference);
    StatusResourceNormalizeVector(axis_c, fallback_axis_a);
    for (unsigned lane = 0; lane < 3u; ++lane)
        ((float *)(output + 0xf4u))[lane] = axis_c[lane];
}
static float StatusResourceClampAngle(float value, float bound)
{
    float lower = -value;
    if (lower > bound)
        bound = lower;
    if (value < bound)
        bound = value;
    return bound;
}
__attribute__((noinline)) void StatusResource_ApplyAngularRotation(void *output_record, void *resource,
                                           float hidden_delta)
{
    uint8_t *output = (uint8_t *)output_record;
    const uint8_t *resource_bytes = (const uint8_t *)resource;
    float first = *(float *)(output + 0x38u) *
                  *(float *)(resource_bytes + 0x38cu) * hidden_delta;
    float second = *(float *)(output + 0x3cu) *
                   *(float *)(resource_bytes + 0x388u) * hidden_delta;
    float angle_a;
    float angle_b;
    float sine_a;
    float cosine_a;
    float sine_b;
    float cosine_b;
    float x1;
    float y1;
    float z1;
    float x2;
    float y2;
    float z2;
    float w1;
    float w2;
    float qx;
    float qy;
    float qz;
    float qw;
    float vx = *(float *)(output + 0x1cu);
    float vy = *(float *)(output + 0x20u);
    float vz = *(float *)(output + 0x24u);
    float tx;
    float ty;
    float tz;
    float tw;
    float rx;
    float ry;
    float rz;
    float length_squared;
    first = StatusResourceClampAngle(first, *(float *)(output + 0xecu));
    angle_a = first * 0.5f * 0.15915493667125702f;
    angle_a -= Libm_Floorf_0049A940(angle_a);
    angle_a *= 6.2831854820251465f * 40.7436637878418f;
    SinCosAngleUnits(angle_a, &sine_a, &cosine_a);
    second = StatusResourceClampAngle(second, *(float *)(output + 0xf0u));
    angle_b = second * 0.5f * 0.15915493667125702f;
    angle_b -= Libm_Floorf_0049A940(angle_b);
    angle_b *= 6.2831854820251465f * 40.7436637878418f;
    SinCosAngleUnits(angle_b, &sine_b, &cosine_b);
    x1 = *(float *)(output + 0xf4u) * sine_a;
    y1 = *(float *)(output + 0xf8u) * sine_a;
    z1 = *(float *)(output + 0xfcu) * sine_a;
    x2 = *(float *)(output + 0x100u) * sine_b;
    y2 = *(float *)(output + 0x104u) * sine_b;
    z2 = *(float *)(output + 0x108u) * sine_b;
    w1 = cosine_a;
    w2 = cosine_b;
    qw = -x1 * x2 - y1 * y2 - z1 * z2 + w1 * w2;
    qz = x1 * y2 - y1 * x2 + w1 * z2 + z1 * w2;
    qx = w1 * x2 - z1 * y2 + y1 * z2 + x1 * w2;
    qy = z1 * x2 + w1 * y2 - x1 * z2 + y1 * w2;
    tx = vx * qw - qz * vy + qy * vz;
    ty = vx * qz + qw * vy - qx * vz;
    tz = vy * qx - qy * vx + qw * vz;
    tw = vx * qx + vy * qy + vz * qz;
    rx = qw * tx - qz * ty + qy * tz + qx * tw;
    ry = qz * tx + qw * ty - qx * tz + qy * tw;
    rz = qx * ty - qy * tx + qw * tz + qz * tw;
    length_squared = rx * rx + ry * ry + rz * rz;
    if (length_squared <= 0.0f) {
        const float *fallback = (const float *)(uintptr_t)0x00dc24ccu;
        rx = fallback[0];
        ry = fallback[1];
        rz = fallback[2];
    } else {
        float scale = 1.0f / __builtin_sqrtf(length_squared);
        rx *= scale;
        ry *= scale;
        rz *= scale;
    }
    *(float *)(output + 0x1cu) = rx;
    *(float *)(output + 0x20u) = ry;
    *(float *)(output + 0x24u) = rz;
}
__attribute__((noinline)) float StatusResourceAdvanceTimer(void *unused, void *resource, void *provider,
                                 float hidden_delta)
{
    void **vtable;
    float callback;
    float product;
    float result = 1.0f;
    (void)unused;
    *(float *)((uint8_t *)resource + 0x14u) += hidden_delta;
    vtable = *(void ***)provider;
    callback = ((float (*)(void *))vtable[0x70u / sizeof(void *)])(
        provider);
    product = callback * *(float *)((uint8_t *)resource + 0x8cu);
    if (product > 0.0f)
        result = *(float *)((uint8_t *)resource + 0x14u) / product;
    if (result < 0.0f)
        result = 0.0f;
    if (result > 1.0f)
        result = 1.0f;
    return result;
}
__attribute__((noinline)) int StatusResourceVectorResolve(void *resource, float output[3],
                                   uint32_t index)
{
    uint8_t *bytes = (uint8_t *)resource;
    uint32_t flags = *(uint32_t *)(bytes + 0x34u);
    uint32_t state_flags = *(uint32_t *)(bytes + 0x38u);
    uint32_t count;
    uint32_t *mask;
    uint8_t *entry;
    uint32_t entry_flags;
    if ((flags & 2u) == 0u || (state_flags & 1u) == 0u)
        return 0;
    count = *(uint32_t *)(bytes + 0x40u);
    if (index >= count)
        return 0;
    mask = *(uint32_t **)(bytes + 0x50u);
    if ((mask[index >> 5u] & (1u << (index & 31u))) == 0u)
        return 0;
    entry = *(uint8_t **)(bytes + 0x4cu) + index * 0x34u;
    entry_flags = *(uint32_t *)entry;
    if ((entry_flags & 1u) == 0u) {
        output[0] = *(float *)(entry + 0x0cu);
        output[1] = *(float *)(entry + 0x10u);
        output[2] = *(float *)(entry + 0x14u);
    } else {
        float scale = *(float *)(entry + 0x24u) * 0.5f;
        output[0] = *(float *)(entry + 0x0cu) +
                    *(float *)(entry + 0x18u) * scale;
        output[1] = *(float *)(entry + 0x10u) +
                    *(float *)(entry + 0x1cu) * scale;
        output[2] = *(float *)(entry + 0x14u) +
                    *(float *)(entry + 0x20u) * scale;
    }
    return 1;
}
static void StatusNormalizeVector3(const float input[3], float output[3])
{
    static const float *const fallback =
        (const float *)(uintptr_t)0x00dc24ccu;
    float length_squared = input[0] * input[0] + input[1] * input[1] +
                           input[2] * input[2];
    if (length_squared <= 0.0f) {
        output[0] = fallback[0];
        output[1] = fallback[1];
        output[2] = fallback[2];
        return;
    }
    {
        float scale = 1.0f / __builtin_sqrtf(length_squared);
        output[0] = input[0] * scale;
        output[1] = input[1] * scale;
        output[2] = input[2] * scale;
    }
}
__attribute__((noinline)) void StatusResourceValueHook(void *output_record, const void *resource)
{
    uint8_t *output = (uint8_t *)output_record;
    const uint8_t *input = (const uint8_t *)resource;
    float vector[3];
    *(uint32_t *)(output + 0xa0u) = *(const uint32_t *)(input + 0x28u);
    *(uint32_t *)(output + 0xa4u) = *(const uint32_t *)(input + 0x2cu);
    *(uint32_t *)(output + 0xa8u) = *(const uint32_t *)(input + 0x30u);
    *(uint32_t *)(output + 0xacu) = *(const uint32_t *)(input + 0x2b0u);
    *(uint32_t *)(output + 0xb0u) = *(const uint32_t *)(input + 0x2b4u);
    *(uint32_t *)(output + 0xb4u) = *(const uint32_t *)(input + 0x2b8u);
    *(uint32_t *)(output + 0xd0u) = *(const uint32_t *)(input + 0x2c8u);
    *(uint32_t *)(output + 0xd4u) = *(const uint32_t *)(input + 0x2ccu);
    *(uint32_t *)(output + 0xd8u) = *(const uint32_t *)(input + 0x2d0u);
    vector[0] = *(float *)(output + 0xd0u);
    vector[1] = *(float *)(output + 0xd4u);
    vector[2] = *(float *)(output + 0xd8u);
    float motion_length = __builtin_sqrtf(
        vector[0] * vector[0] + vector[1] * vector[1] +
        vector[2] * vector[2]);
    StatusNormalizeVector3(vector, (float *)(output + 0x1cu));
    *(float *)(output + 0x10u) = motion_length;
    vector[0] = *(float *)(output + 0xa0u) - *(float *)(output + 0xacu);
    vector[1] = *(float *)(output + 0xa4u) - *(float *)(output + 0xb0u);
    vector[2] = *(float *)(output + 0xa8u) - *(float *)(output + 0xb4u);
    *(float *)(output + 0xb8u) = vector[0];
    *(float *)(output + 0xbcu) = vector[1];
    *(float *)(output + 0xc0u) = vector[2];
    StatusNormalizeVector3(vector, (float *)(output + 0xc4u));
    vector[0] = *(float *)(output + 0xd0u);
    vector[1] = *(float *)(output + 0xd4u);
    vector[2] = *(float *)(output + 0xd8u);
    StatusNormalizeVector3(vector, (float *)(output + 0xdcu));
    *(float *)(output + 0xe8u) = __builtin_sqrtf(
        *(float *)(output + 0xb8u) * *(float *)(output + 0xb8u) +
        *(float *)(output + 0xbcu) * *(float *)(output + 0xbcu) +
        *(float *)(output + 0xc0u) * *(float *)(output + 0xc0u));
}
__attribute__((noinline)) void StatusResourceMotionBuild(void *output_record, void *resource,
                                  float hidden_delta)
{
    uint8_t *output = (uint8_t *)output_record;
    uint8_t *resource_bytes = (uint8_t *)resource;
    float scale = *(float *)(output + 0x10u);
    if ((*(uint8_t *)(output + 8u) & 1u) != 0u &&
        scale * hidden_delta <= *(float *)(output + 0xe8u))
        scale = *(float *)(output + 0x14u);
    if (*(float *)(output + 0x34u) < 0.0f)
        scale = -scale;
    *(float *)(resource_bytes + 0x2c8u) =
        *(float *)(output + 0x1cu) * scale;
    *(float *)(resource_bytes + 0x2ccu) =
        *(float *)(output + 0x20u) * scale;
    *(float *)(resource_bytes + 0x2d0u) =
        *(float *)(output + 0x24u) * scale;
}
__attribute__((noinline)) float StatusResourceIntegrateMotion(void *output_record, void *resource,
                                       void *provider, float hidden_delta)
{
    uint8_t *output = (uint8_t *)output_record;
    uint8_t *resource_bytes = (uint8_t *)resource;
    float current_x = *(float *)(resource_bytes + 0x2b0u);
    float current_y = *(float *)(resource_bytes + 0x2b4u);
    float current_z = *(float *)(resource_bytes + 0x2b8u);
    float previous_x = *(float *)(output + 0x1cu);
    float previous_y = *(float *)(output + 0x20u);
    float previous_z = *(float *)(output + 0x24u);
    float accumulated;
    float result = 1.0f;
    typedef float (*ProviderMotionCallback)(void *provider);
    ProviderMotionCallback callback =
        (ProviderMotionCallback)(*(void ***)provider)[0x28u / 4u];
    if (__builtin_isfinite(previous_x) && __builtin_isfinite(previous_y) &&
        __builtin_isfinite(previous_z)) {
        float dx = current_x - previous_x;
        float dy = current_y - previous_y;
        float dz = current_z - previous_z;
        *(float *)(output + 0x0cu) +=
            __builtin_sqrtf(dx * dx + dy * dy + dz * dz);
    }
    *(float *)(output + 0x1cu) = current_x;
    *(float *)(output + 0x20u) = current_y;
    *(float *)(output + 0x24u) = current_z;
    accumulated = *(float *)(output + 0x0cu);
    if (accumulated <= 0.0f) {
        result = 0.0f;
    } else {
        float rate = callback(provider);
        float product = rate * *(float *)(output + 0x8cu);
        if (product > 0.0f) {
            result = (accumulated + *(float *)(output + 0x18u) *
                                      hidden_delta) / product;
            if (*(float *)(output + 0x10u) >= 0.0f) {
                result = 1.0f;
            } else {
                union {
                    float value;
                    uint32_t bits;
                } result_bits = { result };
                if ((int32_t)result_bits.bits > (int32_t)0x3f800000u) {
                    float step = *(float *)(output + 0x18u) * hidden_delta;
                    if (step > 0.0f) {
                        float scale = 1.0f -
                            (accumulated + step - product) / step;
                        *(float *)(output + 0x10u) = scale;
                        if (scale <= 0.0f) {
                            *(float *)(output + 0x10u) = 0.0f;
                            result = 1.0f;
                        } else {
                            *(float *)(resource_bytes + 0x2c8u) *= scale;
                            *(float *)(resource_bytes + 0x2ccu) *= scale;
                            *(float *)(resource_bytes + 0x2d0u) *= scale;
                            result = 0.99999f;
                        }
                    }
                }
            }
        }
    }
    if (result < 0.0f)
        result = 0.0f;
    if (result > 1.0f)
        result = 1.0f;
    return result;
}
__attribute__((noinline)) unsigned StatusResourceApplyMotionAndState(void *output_record,
                                               void *resource)
{
    uint8_t *output = (uint8_t *)output_record;
    uint8_t *resource_bytes = (uint8_t *)resource;
    void *provider;
    uint32_t mode;
    unsigned transitioned = 0u;
    static const float *const fallback =
        (const float *)(uintptr_t)0x00dc24ccu;
    typedef float (*ProviderRateCallback)(void *provider);
    typedef void (*ProviderVoidCallback)(void *provider);
    if (resource == (void *)(uintptr_t)0xffffff78u)
        return 0u;
    provider = *(void **)(resource_bytes + 0x138u);
    if (provider == 0)
        return 0u;
    mode = *(uint32_t *)(resource_bytes + 0x2a0u);
    if ((resource_bytes[0x89u] & 4u) != 0u) {
        if ((mode & 3u) != 0u)
            return 0u;
        resource_bytes[0x89u] &= (uint8_t)~4u;
    }
    output[8u] &= (uint8_t)~8u;
    if ((mode & 3u) == 0u) {
        output[8u] &= (uint8_t)~4u;
    } else {
        if ((output[8u] & 4u) == 0u)
            output[8u] |= 8u;
        output[8u] |= 4u;
    }
    if ((mode & 8u) != 0u) {
        ProviderRateCallback callback =
            (ProviderRateCallback)(*(void ***)provider)[0x78u / 4u];
        *(float *)(resource_bytes + 0x154u) =
            *(float *)(resource_bytes + 0x154u) * callback(provider);
        *(float *)(output + 0x18u) = *(float *)(output + 0x10u);
        *(float *)(resource_bytes + 0x78u) *= 0.2f;
        return 0u;
    }
    if ((mode & 3u) == 0u)
        return 0u;
    if ((output[0x88u] & 8u) != 0u &&
        StatusResourceThresholdCrossingCheck(output_record, resource) != 0u) {
        transitioned = 1u;
    } else if (*(int32_t *)(output + 0x118u) >= 0) {
        --*(int32_t *)(output + 0x118u);
        if (*(int32_t *)(output + 0x118u) < 0) {
            ProviderVoidCallback callback =
                (ProviderVoidCallback)(*(void ***)provider)[0x98u / 4u];
            transitioned = 1u;
            callback(provider);
        }
    }
    if ((mode & 1u) != 0u && (output[4u] & 4u) != 0u &&
        transitioned == 0u) {
        float x = *(float *)(resource_bytes + 0x2c8u);
        float y = *(float *)(resource_bytes + 0x2ccu);
        float z = *(float *)(resource_bytes + 0x2d0u);
        float length = __builtin_sqrtf(x * x + y * y + z * z);
        *(float *)(output + 0x88u) = x;
        *(float *)(output + 0x8cu) = y;
        *(float *)(output + 0x90u) = z;
        if (length != 0.0f) {
            float inverse = 0.2f / length;
            *(float *)(output + 0x1cu) = x * inverse;
            *(float *)(output + 0x20u) = y * inverse;
            *(float *)(output + 0x24u) = z * inverse;
            *(float *)(output + 0x10u) = length;
            *(float *)(output + 0x18u) = length;
        }
        output[0x7cu] |= 1u;
    }
    if ((mode & 2u) != 0u && (output[4u] & 2u) != 0u &&
        transitioned == 0u) {
        float x = *(float *)(resource_bytes + 0x2c8u);
        float y = *(float *)(resource_bytes + 0x2ccu);
        float z = *(float *)(resource_bytes + 0x2d0u);
        float length = __builtin_sqrtf(x * x + y * y + z * z);
        *(float *)(output + 0x88u) = x;
        *(float *)(output + 0x8cu) = y;
        *(float *)(output + 0x90u) = z;
        if (length != 0.0f) {
            float inverse = 0.2f / length;
            *(float *)(output + 0x1cu) = x * inverse;
            *(float *)(output + 0x20u) = y * inverse;
            *(float *)(output + 0x24u) = z * inverse;
            *(float *)(output + 0x10u) = length;
            *(float *)(output + 0x18u) = length;
        }
    }
    if (transitioned != 0u) {
        resource_bytes[0u] |= 8u;
        resource_bytes[0x298u] |= 8u;
        *(float *)(resource_bytes + 0x2c8u) = fallback[0];
        *(float *)(resource_bytes + 0x2ccu) = fallback[1];
        *(float *)(resource_bytes + 0x2d0u) = fallback[2];
        *(float *)(output + 0x10u) = 1.0f;
        *(float *)(output + 0x18u) = 1.0f;
    } else if ((output[8u] & 8u) != 0u && (output[6u] & 2u) == 0u) {
        StatusSubmitResourceEffectEvent(
            output_record, resource,
            *(uint8_t **)(resource_bytes + 0x390u) + 0x2a8u);
    }
    return transitioned;
}
__attribute__((noinline)) unsigned StatusResourceThresholdCrossingCheck(void *output_record,
                                                   void *resource)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    void *provider;
    uint32_t mode;
    float projection;
    float angle;
    float gate;
    float random_value;
    float secondary_gate;
    float blend;
    typedef float (*ProviderScalarCallback)(void *provider);
    ProviderScalarCallback callback;
    (void)output_record;
    if (resource == (void *)(uintptr_t)0xffffff78u)
        return 0u;
    provider = *(void **)(resource_bytes + 0x138u);
    if (provider == 0)
        return 0u;
    mode = *(uint32_t *)(resource_bytes + 0x2a0u);
    projection = *(float *)(resource_bytes + 0x2e0u) *
                     *(float *)(resource_bytes + 0x2ecu) +
                 *(float *)(resource_bytes + 0x2e4u) *
                     *(float *)(resource_bytes + 0x2f0u) +
                 *(float *)(resource_bytes + 0x2e8u) *
                     *(float *)(resource_bytes + 0x2f4u);
    angle = StatusAsin(projection);
    callback = (ProviderScalarCallback)(*(void ***)provider)[0x7cu / 4u];
    gate = callback(provider);
    random_value = StatusRandomRange(0.0f, 1.0f);
    if (!(gate < 0.0f || gate >= random_value))
        return 0u;
    {
        callback =
            (ProviderScalarCallback)(*(void ***)provider)[0x84u / 4u];
        secondary_gate = callback(provider);
        if (secondary_gate <= angle) {
            projection = *(float *)(resource_bytes + 0x2e0u) *
                             *(float *)(resource_bytes + 0x2f8u) +
                         *(float *)(resource_bytes + 0x2e4u) *
                             *(float *)(resource_bytes + 0x2fcu) +
                         *(float *)(resource_bytes + 0x2e8u) *
                             *(float *)(resource_bytes + 0x300u);
            if (projection < 0.0f)
                return 0u;
        }
    }
    callback = (ProviderScalarCallback)(*(void ***)provider)[0x80u / 4u];
    blend = callback(provider);
    if (blend < 0.0f)
        blend = 0.0f;
    if (blend > 1.0f)
        blend = 1.0f;
    if (blend > 0.0f) {
        float target_28;
        float target_70;
        float factor = 1.0f - blend;
        callback = (ProviderScalarCallback)(*(void ***)provider)[0x28u / 4u];
        target_28 = callback(provider) * *(float *)(resource_bytes + 0x8cu);
        callback = (ProviderScalarCallback)(*(void ***)provider)[0x70u / 4u];
        target_70 = callback(provider) * *(float *)(resource_bytes + 0x8cu);
        *(float *)(resource_bytes + 0x0cu) +=
            (target_28 - *(float *)(resource_bytes + 0x0cu)) * factor;
        *(float *)(resource_bytes + 0x14u) +=
            (target_70 - *(float *)(resource_bytes + 0x14u)) * factor;
    }
    if ((mode & 3u) == 0u)
        return 0u;
    projection = *(float *)(resource_bytes + 0x2f8u) *
                     *(float *)(resource_bytes + 0x2f8u) +
                 *(float *)(resource_bytes + 0x2fcu) *
                     *(float *)(resource_bytes + 0x2fcu) +
                 *(float *)(resource_bytes + 0x300u) *
                     *(float *)(resource_bytes + 0x300u);
    {
        callback =
            (ProviderScalarCallback)(*(void ***)provider)[0x88u / 4u];
        blend = callback(provider);
        if (projection <= blend)
            return 0u;
        if (__builtin_sqrtf(projection) < projection)
            return 0u;
    }
    return 1u;
}
