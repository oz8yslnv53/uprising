#include <stddef.h>
#include <stdint.h>
#include "engine_common_views.h"
extern void StatusResource_ResetPendingField_Tail_005BB68C(void *resource);
void StatusResource_ResetPendingField_00590B54(void *object)
{
    uint8_t *resource = *(uint8_t **)((uint8_t *)object + 0x140);
    if (resource != NULL)
        StatusResource_ResetPendingField_Tail_005BB68C(resource);
}
#include <math.h>
extern void *Engine_LazySingletonGetter_004C597C(void);
extern int OnceGuard_TestAndSet_003B4FE4(uint32_t *guard);
extern void Engine_ResourceFactory_Initialize_00161A88(void *factory);
extern void Engine_ComponentRegistry_Initialize_0045F878(void *registry);
extern void *RelatedComponent_CacheResolve(void);
extern void *StatusAlternateParameterKey_004A4BBC(void);
extern int Engine_ComponentRegistryReady_0053A264(void);
extern void *Engine_CommandObjectFactory_001898B8(void *slot,
                                                  void *initializer,
                                                  unsigned size);
__attribute__((noinline)) void *ResourceWrapper_FirstField_00425F64(void *wrapper)
{
    return *(void **)wrapper;
}
__attribute__((noinline)) void *Engine_RelatedComponentCacheGetter_004C129C(void)
{
    static uint32_t *const guard = (uint32_t *)(uintptr_t)0x00d45540u;
    static uint32_t *const fallback = (uint32_t *)(uintptr_t)0x00d724c8u;
    static const uint32_t *const defaults =
        (const uint32_t *)(uintptr_t)0x00dc249cu;
    void *resolved = RelatedComponent_CacheResolve();
    if (resolved != NULL)
        return (uint8_t *)resolved + 0x64u;
    if ((*guard & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        fallback[0] = defaults[0];
        fallback[1] = defaults[1];
        fallback[2] = defaults[2];
        *(float *)((uint8_t *)fallback + 0x0cu) = 1.0f;
    }
    return fallback;
}
__attribute__((noinline)) void *Engine_ComponentRegistryGetter_004C58E0(void)
{
    static uint32_t *const guard = (uint32_t *)(uintptr_t)0x00d63594u;
    static void *const registry = (void *)(uintptr_t)0x00e5f6e0u;
    if ((*guard & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(guard) != 0)
        Engine_ComponentRegistry_Initialize_0045F878(registry);
    return registry;
}
__attribute__((noinline)) void *ResourceFactory_Create_004C5938(void)
{
    static uint32_t *const guard = (uint32_t *)(uintptr_t)0x00d6359cu;
    static void *const factory = (void *)(uintptr_t)0x00e5f7ccu;
    if ((*guard & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(guard) != 0)
        Engine_ResourceFactory_Initialize_00161A88(factory);
    return factory;
}
__attribute__((noinline)) void *Engine_LazySingletonGetter_004A9AFC(void)
{
    static void **const singleton_slot = (void **)(uintptr_t)0x00d635f8u;
    if (*singleton_slot == NULL)
        *singleton_slot = Engine_LazySingletonGetter_004C597C();
    return *singleton_slot;
}
__attribute__((noinline)) int Engine_ObjectMatchesGlobalClass(void *object)
{
    static const uint32_t *const global_class =
        (const uint32_t *)(uintptr_t)0x00c9b9c4u;
    void *class_object = *(void **)((uint8_t *)object + 0x168u);
    return *global_class == *(const uint32_t *)((uint8_t *)class_object + 0x08u);
}
__attribute__((noinline)) void *Engine_ArraySlotSelect_004A3C84(void **table, int selector)
{
    if (selector == 0)
        return table[0];
    if (selector == 1)
        return table[1];
    if (selector == 2)
        return table[2];
    return NULL;
}
__attribute__((noinline)) void *Resource_GetIndexedEntry_00464200(void *resource, int index)
{
    uint8_t *entries = *(uint8_t **)((uint8_t *)resource + 0xecu);
    return entries + (uint32_t)index * 0x28u;
}
extern int OnceGuard_TestAndSet_003B4FE4(uint32_t *guard);
extern void *StatusEventPayload_Initialize_003531A4(void *record);
extern void ParameterString_Format_00542F74(void *output,
                                             const char *value,
                                             int capacity);
extern unsigned ParameterString_Equals_00425E6C(const void *left,
                                                 const void *right);
extern uint32_t IntrusiveList_Count_00473DB8(void *list);
extern void *EffectEvent_HandleResolver_00566F0C(void *dispatcher,
                                                 int32_t handle);
extern void EffectParameter_KeyBuild_00593D58(uint32_t *out,
                                               const void *text);
extern void *Engine_OrderedRecordSelectByKeyAndName_0051CC1C(
    uint32_t selector, const uint32_t *key);
extern void *EffectEvent_FindRecord_004B2894(void *dispatcher,
                                              uint32_t event_id);
extern int EffectEvent_QueueRecordCopy_005AF678(void *queue,
                                                 uint32_t handle,
                                                 const void *record);
extern int EffectEvent_QueueInsert_00417D34(void *queue, uint32_t value,
                                             const void *source,
                                             uint32_t force);
extern int IntrusiveList_ResetAndStoreMetadata_0048D22C(
    void *pool, uint32_t value, uint32_t auxiliary);
extern void ActionSequence_Execute(void *sequence, void *context);
extern void ActionGroup_StartSequence(void *group, void *selected,
                                       uint32_t mode);
extern void *OrderedTree_Successor_00464110(void *node);
extern void *EffectEvent_RecordInit_00544A50(void *record);
extern void *Engine_LazyListGroup_004C5BFC(void);
extern void *Engine_LazyTaggedListGroup_004C5B30(void);
extern void *Engine_LazySingletonGetter_003FD6E0(void);
extern void *Engine_LazySingletonGetter_004EEFBC(void);
extern void *Engine_IndexedRecordAccessor_0043704C(void *table, int index);
extern void *Engine_LazyCallbackTableGetter_004EE830(void);
extern float RandomSpreadIfPositive_00564440(float gate_input);
extern void SinCosAngleUnits(float angle_units, float *sine, float *cosine);
extern void *BotConnector_Factory_00534FC0(void);
extern uint32_t StatusCapabilityKey_Get(void);
extern int AsyncResource_Create_005ABE04(void *destination, void *request,
                                         void *key, uint32_t *owner,
                                         uint32_t callback_result,
                                         uint32_t hidden1, uint32_t hidden2,
                                         uint32_t final_flag);
extern int StatusResource_KeyValidate_004FF108(void *registry,
                                                unsigned mode,
                                                unsigned key);
extern void *StatusResource_ModeRecordLookup_00584270(void *factory,
                                                       unsigned mode,
                                                       unsigned key,
                                                       unsigned selector);
extern void *Engine_ThresholdAuxAllocator_00475D70(void);
extern int StatusResource_Construct_00584B78(void *registry, unsigned key,
                                              uint32_t payload,
                                              unsigned parameter,
                                              uint32_t hidden0,
                                              uint32_t hidden1,
                                              uint32_t hidden2);
extern void *Engine_GlobalTimingState_Get_0054EF64(void);
extern void *ResolveStatusDescriptor(void *object);
uint32_t OwnerHandle_BuildOther(void *tree, uint32_t key);
extern uint32_t OwnerHandle_BuildVariant6(void *tree, uint32_t key);
extern void *ResourceTable_Lookup(uint32_t *handle);
extern void *ComponentType_GetGlobalDescriptor(void);
extern void *OrderedTree_LowerBoundByPointer_004C5D3C(void *tree,
                                                     void *key);
extern void *Engine_StatusParameterKey_Get(void);
extern void FUN_00488D60(void *factory);
extern void FUN_004DEB00(void *range, void **descriptor);
extern void *Engine_AllocateResource_003B5A8C(void *descriptor,
                                               void *initializer,
                                               uint32_t count, ...);
extern int StatusDescriptor_ClassNibble(void *descriptor);
extern void *AvatarOnlineWork_Factory_00507744(void);
__attribute__((noinline)) void *StatusDescriptor_OwnerGet(void *ignored, void *object)
{
    void *descriptor;
    (void)ignored;
    descriptor = ResolveStatusDescriptor(object);
    return descriptor != NULL ? *(void **)((uint8_t *)descriptor + 0x20u)
                              : NULL;
}
__attribute__((noinline)) void *ResourceStatus_LookupByHandle(void *registry, uint32_t key)
{
    uint32_t handle;
    if ((key >> 28) == 6u)
        handle = OwnerHandle_BuildVariant6((uint8_t *)registry + 0x171acu,
                                           key);
    else
        handle = OwnerHandle_BuildOther((uint8_t *)registry + 0xf98cu,
                                        key);
    return ResourceTable_Lookup(&handle);
}
__attribute__((noinline)) void *ResolveRelatedComponent(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    void *component = *(void **)(bytes + 0x208u);
    void *node;
    void *selected;
    void *current;
    if (component != NULL)
        return component;
    node = OrderedTree_LowerBoundByPointer_004C5D3C(
        bytes + 0x1a4u, ComponentType_GetGlobalDescriptor());
    selected = node != NULL ? *(void **)node : NULL;
    current = *(void **)(bytes + 0x1a8u);
    if (selected == current || selected == NULL)
        return NULL;
    *(void **)((uint8_t *)selected + 0x34u) = object;
    *(void **)(bytes + 0x208u) = selected;
    return selected;
}
__attribute__((noinline)) void *ResolveStatusDescriptor(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    void *descriptor = *(void **)(bytes + 0x1e8u);
    void *node;
    void *selected;
    void *current;
    if (descriptor != NULL)
        return descriptor;
    node = OrderedTree_LowerBoundByPointer_004C5D3C(
        bytes + 0x1a4u, ComponentType_GetGlobalDescriptor());
    selected = node != NULL ? *(void **)node : NULL;
    current = *(void **)(bytes + 0x1a8u);
    if (selected == current || selected == NULL)
        return NULL;
    *(void **)((uint8_t *)selected + 0x1cu) = object;
    *(void **)(bytes + 0x1e8u) = selected;
    return selected;
}
__attribute__((noinline)) void Engine_ResourceDescriptorRelink_0054E4D8(void **descriptor,
                                               uint32_t flags)
{
    uint8_t *base = (uint8_t *)*descriptor;
    uint32_t relative = *(uint32_t *)(base + 0x28u);
    uint8_t *records = relative != 0u ? base + 0x28u + relative : NULL;
    uint32_t count = *(uint32_t *)(base + 0x24u);
    uint8_t *end = (records != NULL ? records + 0x1cu : NULL) +
                   count * 0x10u;
    uint8_t *other = relative != 0u ? base + 0x28u + relative : NULL;
    uint8_t *cursor = other != NULL ? other + 0x1cu : NULL;
    while (cursor != end) {
        uint8_t *entry = cursor + 0x0cu;
        uint8_t *resource = *(uint32_t *)entry != 0u
                                ? entry + *(uint32_t *)entry
                                : NULL;
        uint32_t type = *(uint32_t *)resource;
        if (type == 0x20000009u || type == 0x20000011u)
            *(uint32_t *)(resource + 0x30u) = flags;
        cursor += 0x10u;
    }
}
__attribute__((noinline)) void *Engine_IntrusiveListRegistry_GetSentinel_0054F09C(void)
{
    uint32_t *guard = (uint32_t *)(uintptr_t)0x0054f0ecu;
    uint8_t **slot = (uint8_t **)(uintptr_t)0x0054f0f0u;
    uint8_t *sentinel = *slot;
    if (((*guard & 1u) == 0u) && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        *(uint8_t **)(sentinel + 0x00u) = sentinel;
        *(uint8_t **)(sentinel + 0x04u) = sentinel;
        *(uint8_t **)(sentinel + 0x08u) = sentinel;
    }
    return sentinel;
}
__attribute__((noinline)) void *Engine_IntrusiveListRegistry_GetSentinel_0054F0FC(void)
{
    uint32_t *guard = (uint32_t *)(uintptr_t)0x0054f14cu;
    uint8_t **slot = (uint8_t **)(uintptr_t)0x0054f150u;
    uint8_t *sentinel = *slot;
    if (((*guard & 1u) == 0u) && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        *(uint8_t **)(sentinel + 0x00u) = sentinel;
        *(uint8_t **)(sentinel + 0x04u) = sentinel;
        *(uint8_t **)(sentinel + 0x08u) = sentinel;
    }
    return sentinel;
}
__attribute__((noinline)) void *OrderedTree_StatusComponentLookup(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    void *node = OrderedTree_LowerBoundByPointer_004C5D3C(
        bytes + 0x1a4u, Engine_StatusParameterKey_Get());
    void *selected = node != NULL ? *(void **)node : NULL;
    return selected == *(void **)(bytes + 0x1a8u) ? NULL : selected;
}
__attribute__((noinline)) void *OrderedTree_LowerBoundStatusHandle(void *tree, uint32_t key)
{
    uint8_t *sentinel = (uint8_t *)tree + 4u;
    uint8_t *candidate = sentinel;
    uint8_t *current = *(uint8_t **)(sentinel + 4u);
    while (*(uint8_t *)(current + 0x10u) != 0u) {
        if (*(uint32_t *)(current + 0x14u) < key) {
            current = *(uint8_t **)(current + 0x0cu);
        } else {
            candidate = current;
            current = *(uint8_t **)(current + 0x08u);
        }
    }
    if (candidate == sentinel || *(uint32_t *)(candidate + 0x14u) <= key)
        return sentinel;
    return candidate;
}
__attribute__((noinline)) uint32_t OwnerHandle_BuildOther(void *tree, uint32_t key)
{
    uint8_t *base = (uint8_t *)tree;
    uint8_t *node = (uint8_t *)OrderedTree_LowerBoundStatusHandle(
        base + 8u, key);
    uint8_t *payload = node != NULL ? *(uint8_t **)node : NULL;
    if (payload != NULL && payload[0x1au] != 0u)
        return *(uint32_t *)(payload + 0x1cu);
    return 0xfffffe00u;
}
static void *StatusResource_LowerBoundPayload(void *resource,
                                               uint32_t key)
{
    uint8_t *base = (uint8_t *)resource;
    uint8_t *sentinel = base + 0x1a8u;
    uint8_t *node = *(uint8_t **)(base + 0x1acu);
    uint8_t *candidate = sentinel;
    while (*(uint8_t *)(node + 0x10u) != 0u) {
        if (*(uint32_t *)(node + 0x14u) < key) {
            node = *(uint8_t **)(node + 0x0cu);
        } else {
            candidate = node;
            node = *(uint8_t **)(node + 0x08u);
        }
    }
    if (candidate == sentinel || *(uint32_t *)(candidate + 0x14u) <= key)
        candidate = sentinel;
    return *(void **)candidate;
}
__attribute__((noinline)) void *StatusResource_ResolveRelatedRecord(void *resource, int require_related)
{
    static const uint32_t *const generation_slot =
        (const uint32_t *)(uintptr_t)0x00564654u;
    static uint8_t **const generation_table_slot =
        (uint8_t **)(uintptr_t)0x00564658u;
    void *selected = StatusResource_LowerBoundPayload(
        resource, (uint32_t)(uintptr_t)BotConnector_Factory_00534FC0());
    void *current = *(void **)((uint8_t *)resource + 0x1a8u);
    uint8_t *related;
    uint8_t *generation_table = *generation_table_slot;
    uint32_t handle;
    if (selected == current)
        return NULL;
    if (selected == NULL)
        return NULL;
    handle = *(uint32_t *)((uint8_t *)selected + 0x34u);
    if (*generation_slot == (handle >> 9u))
        return NULL;
    if (generation_table == NULL)
        return NULL;
    related = *(uint8_t **)(generation_table + (handle & 0x1ffu) * 8u);
    if (*(uint32_t *)(generation_table + (handle & 0x1ffu) * 8u + 4u) !=
            (handle >> 9u) ||
        related == NULL)
        return NULL;
    if (!require_related)
        return related;
    selected = StatusResource_LowerBoundPayload(
        related, StatusCapabilityKey_Get());
    current = *(void **)(related + 0x1a8u);
    if (selected == current || selected == NULL ||
        (*(uint16_t *)((uint8_t *)selected + 0x1eu) & 1u) == 0u)
        return NULL;
    return related;
}
__attribute__((noinline)) void EffectParameter_RecordRandomize(void *record, int source,
                                     uint32_t selector, int enabled)
{
    uint8_t *bytes = (uint8_t *)record;
    uint32_t key[2];
    uint32_t callback_result;
    void *selected;
    void **callback_object;
    int (*callback)(int);
    bytes[0x84u] = 2u;
    *(uint32_t *)(bytes + 0x88u) = 0u;
    *(int32_t *)(bytes + 0x7cu) = source;
    *(uint32_t *)(bytes + 0x80u) = selector;
    if (source == 0 ||
        ParameterString_Equals_00425E6C(bytes, (const void *)0x005668fcu) == 0) {
        if (*(int32_t *)(bytes + 0x78u) >= 0)
            bytes[0x84u] = 3u;
    } else {
        bytes[0x84u] = 1u;
        if (ParameterString_Equals_00425E6C(
                bytes, (const void *)0x00566904u) != 0) {
            if (selector != 0u) {
                EffectParameter_KeyBuild_00593D58(key, bytes);
                selected = Engine_OrderedRecordSelectByKeyAndName_0051CC1C(
                    selector, key);
                *(void **)(bytes + 0x88u) = selected;
                if (selected != NULL)
                    bytes[0x84u] = 0u;
            }
            callback_object = *(void ***)(uintptr_t)0x0056690cu;
            callback = callback_object != NULL
                           ? *(int (**)(int))callback_object
                           : NULL;
            if (callback != NULL) {
                callback_result = (uint32_t)callback(source);
                if (callback_result != 0u) {
                    EffectParameter_KeyBuild_00593D58(key, bytes);
                    selected = Engine_OrderedRecordSelectByKeyAndName_0051CC1C(
                        callback_result, key);
                    *(void **)(bytes + 0x88u) = selected;
                    if (selected != NULL) {
                        *(uint32_t *)(bytes + 0x80u) = callback_result;
                        bytes[0x84u] = 0u;
                    }
                }
            }
        }
    }
    bytes[0x85u] =
        ParameterString_Equals_00425E6C(
            bytes + 0x20u, (const void *)0x00566910u) == 0;
    bytes[0x8cu] = (uint8_t)enabled;
    if (enabled != 0) {
        float scale = RandomSpreadIfPositive_00564440(
                          *(float *)(bytes + 0x74u)) +
                      *(float *)(bytes + 0x70u);
        float sin_a;
        float cos_a;
        float sin_b;
        float cos_b;
        float sin_c;
        float cos_c;
        const float degrees_to_radians = 0.01745329238474369f;
        *(float *)(bytes + 0xc0u) = scale;
        sin_a = RandomSpreadIfPositive_00564440(
                    *(float *)(bytes + 0x64u)) +
                *(float *)(bytes + 0x58u);
        sin_a *= degrees_to_radians;
        SinCosAngleUnits(sin_a, &sin_a, &cos_a);
        sin_b = RandomSpreadIfPositive_00564440(
                    *(float *)(bytes + 0x68u)) +
                *(float *)(bytes + 0x5cu);
        sin_b *= degrees_to_radians;
        SinCosAngleUnits(sin_b, &sin_b, &cos_b);
        sin_c = RandomSpreadIfPositive_00564440(
                    *(float *)(bytes + 0x6cu)) +
                *(float *)(bytes + 0x60u);
        sin_c *= degrees_to_radians;
        SinCosAngleUnits(sin_c, &sin_c, &cos_c);
        *(float *)(bytes + 0x90u) = cos_b * cos_c * scale;
        *(float *)(bytes + 0x94u) =
            (cos_c * sin_b * sin_a - sin_c * cos_a) * scale;
        *(float *)(bytes + 0x98u) =
            (cos_c * sin_b * cos_a + sin_c * sin_a) * scale;
        *(float *)(bytes + 0xa0u) = cos_b * sin_c * scale;
        *(float *)(bytes + 0xa4u) =
            (sin_c * sin_b * sin_a + cos_c * cos_a) * scale;
        *(float *)(bytes + 0xa8u) =
            (sin_c * sin_b * cos_a - cos_c * sin_a) * scale;
        *(float *)(bytes + 0xacu) = -sin_b * scale;
        *(float *)(bytes + 0xb0u) = -sin_b * scale;
        *(float *)(bytes + 0xb4u) = cos_b * sin_a * scale;
        *(float *)(bytes + 0xb8u) = cos_b * cos_a * scale;
        *(float *)(bytes + 0x9cu) =
            RandomSpreadIfPositive_00564440(*(float *)(bytes + 0x4cu)) +
            *(float *)(bytes + 0x40u);
        *(float *)(bytes + 0xacu) =
            RandomSpreadIfPositive_00564440(*(float *)(bytes + 0x50u)) +
            *(float *)(bytes + 0x44u);
        *(float *)(bytes + 0xbcu) =
            RandomSpreadIfPositive_00564440(*(float *)(bytes + 0x54u)) +
            *(float *)(bytes + 0x48u);
    }
}
struct EffectDefaultBlock8 { float value[8]; };
struct EffectDefaultBlock4 { float value[4]; };
__attribute__((noinline)) void *EffectParameter_RecordInitialize(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    const float *defaults = *(const float **)(uintptr_t)0x005669f8u;
    *(float *)(bytes + 0x40u) = 0.0f;
    *(float *)(bytes + 0x44u) = 0.0f;
    *(float *)(bytes + 0x48u) = 0.0f;
    *(float *)(bytes + 0x4cu) = 0.0f;
    *(float *)(bytes + 0x50u) = 0.0f;
    *(float *)(bytes + 0x54u) = 0.0f;
    *(float *)(bytes + 0x58u) = 0.0f;
    *(float *)(bytes + 0x5cu) = 0.0f;
    *(float *)(bytes + 0x60u) = 0.0f;
    *(float *)(bytes + 0x64u) = 0.0f;
    *(float *)(bytes + 0x68u) = 0.0f;
    *(float *)(bytes + 0x6cu) = 0.0f;
    *(float *)(bytes + 0x70u) = 1.0f;
    *(float *)(bytes + 0x74u) = 0.0f;
    *(uint32_t *)(bytes + 0x78u) = 0xffffffffu;
    *(uint32_t *)(bytes + 0x7cu) = 0u;
    *(uint32_t *)(bytes + 0x80u) = 0u;
    bytes[0x84u] = 0u;
    bytes[0x85u] = 0u;
    *(uint32_t *)(bytes + 0x88u) = 0u;
    bytes[0x8cu] = 0u;
    *(struct EffectDefaultBlock8 *)(bytes + 0x90u) =
        *(const struct EffectDefaultBlock8 *)defaults;
    *(struct EffectDefaultBlock4 *)(bytes + 0xb0u) =
        *(const struct EffectDefaultBlock4 *)(defaults + 8);
    *(float *)(bytes + 0xc0u) = 1.0f;
    ParameterString_Format_00542F74(bytes, "root", 0x20);
    ParameterString_Format_00542F74(bytes + 0x20u, "none", 0x20);
    return record;
}
__attribute__((noinline)) int EffectEvent_QueueVolumeRecord_00566CA4(void *queue, uint32_t value,
                                           const void *source)
{
    uint8_t *base = (uint8_t *)queue;
    uint8_t *node;
    uint8_t *payload;
    uint8_t *previous;
    uint8_t *next;
    if (IntrusiveList_Count_00473DB8(base + 0x0cu) <= 1u)
        return -1;
    node = *(uint8_t **)(base + 0x10u);
    if (*(uint8_t **)node == *(uint8_t **)(base + 0x0cu))
        return -1;
    payload = *(uint8_t **)node;
    previous = *(uint8_t **)(node + 0x04u);
    next = *(uint8_t **)(node + 0x08u);
    *(uint8_t **)(next + 0x04u) = previous;
    *(uint8_t **)(previous + 0x08u) = next;
    *(uint8_t **)(node + 0x04u) = node;
    *(uint8_t **)(node + 0x08u) = node;
    *(uint64_t *)(payload + 0x10u) =
        *(const uint64_t *)(*(uint8_t **)(uintptr_t)0x00566d6cu + 0x30u);
    *(uint32_t *)(payload + 0x18u) = value;
    *(uint32_t *)(payload + 0x5cu) = *(const uint32_t *)((const uint8_t *)source + 0x0cu);
    *(uint32_t *)(payload + 0x60u) = *(const uint32_t *)((const uint8_t *)source + 0x10u);
    *(uint32_t *)(payload + 0x64u) = *(const uint32_t *)((const uint8_t *)source + 0x14u);
    *(uint32_t *)(payload + 0x68u) = *(const uint32_t *)((const uint8_t *)source + 0x18u);
    if (payload != base) {
        previous = *(uint8_t **)(payload + 0x04u);
        next = *(uint8_t **)(payload + 0x08u);
        *(uint8_t **)(next + 0x04u) = previous;
        *(uint8_t **)(previous + 0x08u) = next;
        next = *(uint8_t **)(base + 0x08u);
        *(uint8_t **)(next + 0x04u) = payload;
        *(uint8_t **)(payload + 0x08u) = next;
        *(uint8_t **)(payload + 0x04u) = base;
        *(uint8_t **)(base + 0x08u) = payload;
    }
    return 0;
}
__attribute__((noinline)) void *EffectEvent_HandleResolver_00566F0C(void *dispatcher, int32_t handle)
{
    uint8_t *base = (uint8_t *)dispatcher;
    uint32_t slot = (uint32_t)(handle >> 24);
    uint8_t *entry;
    if (handle == -0x10)
        return base + 0x1d38u;
    if (slot >= 0x20u)
        return NULL;
    entry = base + slot * 0xd8u + 0x238u;
    if (*(int32_t *)(entry + 0x24u) != handle)
        return NULL;
    return entry;
}
__attribute__((noinline)) int EffectEvent_Submit(void *dispatcher, uint32_t event_id,
                       uint32_t event_type, const void *record)
{
    uint8_t *base = (uint8_t *)dispatcher;
    uint8_t *existing = (uint8_t *)EffectEvent_FindRecord_004B2894(
        dispatcher, event_id);
    uint8_t *candidate;
    uint8_t *previous;
    uint8_t *next;
    uint8_t *head;
    uint32_t sequence;
    uint32_t next_sequence;
    uint32_t handle;
    int result;
    if (existing == NULL)
        return -2;
    candidate = *(uint8_t **)(*(uint8_t **)(base + 0x224u));
    if (candidate == NULL || candidate == *(uint8_t **)(base + 0x220u))
        return -3;
    candidate[0x18u] = 4u;
    candidate[0x15u] = 1u;
    candidate[0x16u] = 0u;
    sequence = *(uint32_t *)(base + 0x1e10u);
    next_sequence = sequence + 1u;
    *(uint32_t *)(base + 0x1e10u) = next_sequence;
    if (next_sequence >= 0x1000000u)
        *(uint32_t *)(base + 0x1e10u) = 1u;
    handle = sequence | *(uint32_t *)(candidate + 0x10u);
    *(uint32_t *)(candidate + 0x24u) = handle;
    *(uint32_t *)(candidate + 0x20u) = event_id;
    *(uint32_t *)(candidate + 0x1cu) = event_type;
    candidate[0x2au] = existing[0x16u];
    *(uint16_t *)(candidate + 0x28u) = *(const uint16_t *)record;
    previous = *(uint8_t **)(candidate + 0x08u);
    next = *(uint8_t **)(candidate + 0x0cu);
    *(uint8_t **)(next + 0x04u) = previous;
    *(uint8_t **)(previous + 0x08u) = next;
    head = candidate + 0x04u;
    *(uint8_t **)(candidate + 0x08u) = head;
    *(uint8_t **)(candidate + 0x0cu) = head;
    if (head != base + 0x22cu) {
        uint8_t *sentinel = base + 0x22cu;
        next = *(uint8_t **)(sentinel + 0x08u);
        *(uint8_t **)(next + 0x04u) = head;
        *(uint8_t **)(head + 0x04u) = sentinel;
        *(uint8_t **)(head + 0x08u) = next;
        *(uint8_t **)(sentinel + 0x08u) = head;
    }
    result = EffectEvent_QueueRecordCopy_005AF678(
        base + 0x2148u, handle, record);
    return result == -1 ? -3 : (int)handle;
}
__attribute__((noinline)) void *EffectEvent_FindRecord_004B2894(void *dispatcher, uint32_t event_id)
{
    uint8_t *base = (uint8_t *)dispatcher;
    uint8_t *node = *(uint8_t **)(base + 0x218u);
    uint8_t *sentinel = *(uint8_t **)(base + 0x214u);
    while (*(uint8_t **)node != sentinel) {
        uint8_t *record = *(uint8_t **)node;
        if (*(uint32_t *)(record + 0x18u) == event_id)
            return record;
        node = *(uint8_t **)(node + 0x04u);
    }
    return NULL;
}
__attribute__((noinline)) uint32_t ActionGroups_Update(void *groups, void *parameter, void *unused,
                             const void *frame_context)
{
    uint8_t context[0x24u] = {0};
    uint8_t *base = (uint8_t *)groups;
    uint8_t *iterator = *(uint8_t **)(base + 0x44u);
    uint8_t *sentinel = *(uint8_t **)(base + 0x3cu);
    (void)unused;
    context[0] = 1u;
    *(uint32_t *)(context + 0x04u) = *(uint32_t *)(base + 0x30u);
    *(void **)(context + 0x08u) = parameter;
    *(uint32_t *)(context + 0x18u) = *(uint32_t *)(base + 0x34u);
    *(uint32_t *)(context + 0x1cu) =
        *(const uint32_t *)((const uint8_t *)frame_context + 0x0cu);
    while (iterator != NULL && *(uint8_t **)iterator != sentinel) {
        uint8_t *group = *(uint8_t **)iterator;
        uint8_t *sequence_node = *(uint8_t **)(group + 0x20u);
        *(void **)(context + 0x0cu) = group;
        while (*(void **)sequence_node != *(void **)(group + 0x1cu)) {
            void *sequence = *(void **)sequence_node;
            sequence_node = *(uint8_t **)(sequence_node + 0x04u);
            ActionSequence_Execute(sequence, context);
        }
        {
            void *selected = NULL;
            uint8_t *first = *(uint8_t **)(group + 0x20u);
            if (first != (uint8_t *)(group + 0x1cu)) {
                void *sequence = *(void **)first;
                if (*(void **)((uint8_t *)sequence + 0x10u) !=
                    (uint8_t *)sequence + 0x0cu)
                    selected = *(void **)(*(void **)((uint8_t *)sequence + 0x14u));
            }
            if (*(void **)(group + 0x2cu) != NULL &&
                (selected == NULL ||
                 *(void **)((uint8_t *)selected + 0x34u) == NULL))
                ActionGroup_StartSequence(
                    group, *(void **)(group + 0x2cu), 1u);
        }
        iterator = (uint8_t *)OrderedTree_Successor_00464110(iterator);
    }
    return 0u;
}
__attribute__((noinline)) int EffectEvent_QueueRecordCopy_005AF678(void *queue, uint32_t value,
                                         const void *source)
{
    uint8_t *base = (uint8_t *)queue;
    uint8_t *node;
    uint8_t *payload;
    uint8_t *previous;
    uint8_t *next;
    if (IntrusiveList_Count_00473DB8(base + 0x0cu) <= 1u)
        return -1;
    node = *(uint8_t **)(base + 0x10u);
    if (*(uint8_t **)node == *(uint8_t **)(base + 0x0cu))
        return -1;
    payload = *(uint8_t **)node;
    previous = *(uint8_t **)(node + 0x04u);
    next = *(uint8_t **)(node + 0x08u);
    *(uint8_t **)(next + 0x04u) = previous;
    *(uint8_t **)(previous + 0x08u) = next;
    *(uint8_t **)(node + 0x04u) = node;
    *(uint8_t **)(node + 0x08u) = node;
    *(uint32_t *)(payload + 0x10u) =
        *(uint32_t *)(*(uint8_t **)(uintptr_t)0x005af758u + 0x28u);
    *(uint32_t *)(payload + 0x14u) =
        *(uint32_t *)(*(uint8_t **)(uintptr_t)0x005af758u + 0x2cu);
    *(uint32_t *)(payload + 0x18u) = value;
    *(uint32_t *)(payload + 0x5cu) = *(const uint32_t *)((const uint8_t *)source + 0x0cu);
    *(uint32_t *)(payload + 0x60u) = *(const uint32_t *)((const uint8_t *)source + 0x10u);
    *(uint32_t *)(payload + 0x64u) = *(const uint32_t *)((const uint8_t *)source + 0x14u);
    *(uint32_t *)(payload + 0x68u) = *(const uint32_t *)((const uint8_t *)source + 0x18u);
    *(uint32_t *)(payload + 0x6cu) = *(const uint32_t *)((const uint8_t *)source + 0x1cu);
    *(uint32_t *)(payload + 0x70u) = *(const uint32_t *)((const uint8_t *)source + 0x20u);
    *(uint32_t *)(payload + 0x74u) = *(const uint32_t *)((const uint8_t *)source + 0x24u);
    payload = *(uint8_t **)node;
    if (payload != base) {
        previous = *(uint8_t **)(payload + 0x04u);
        next = *(uint8_t **)(payload + 0x08u);
        *(uint8_t **)(next + 0x04u) = previous;
        *(uint8_t **)(previous + 0x08u) = next;
        next = *(uint8_t **)(base + 0x08u);
        *(uint8_t **)(next + 0x04u) = payload;
        *(uint8_t **)(payload + 0x08u) = next;
        *(uint8_t **)(payload + 0x04u) = base;
        *(uint8_t **)(base + 0x08u) = payload;
    }
    return 0;
}
__attribute__((noinline)) int EffectEvent_QueueInsert_00417D34(void *queue, uint32_t value,
                                     const void *source, uint32_t force)
{
    uint8_t *base = (uint8_t *)queue;
    uint8_t *node;
    uint8_t *payload;
    uint8_t *previous;
    uint8_t *next;
    if (force == 0u && IntrusiveList_Count_00473DB8(base + 0x0cu) <= 1u)
        return -1;
    node = *(uint8_t **)(base + 0x10u);
    if (*(uint8_t **)node == *(uint8_t **)(base + 0x0cu))
        return -1;
    payload = *(uint8_t **)node;
    previous = *(uint8_t **)(node + 0x04u);
    next = *(uint8_t **)(node + 0x08u);
    *(uint8_t **)(next + 0x04u) = previous;
    *(uint8_t **)(previous + 0x08u) = next;
    *(uint8_t **)(node + 0x04u) = node;
    *(uint8_t **)(node + 0x08u) = node;
    *(uint64_t *)(payload + 0x10u) = *(
        const uint64_t *)(*(uint8_t **)(uintptr_t)0x00417e04u + 0x20u);
    *(uint32_t *)(payload + 0x18u) = value;
    *(uint32_t *)(payload + 0x5cu) = *(const uint32_t *)((const uint8_t *)source + 0x0cu);
    *(uint32_t *)(payload + 0x60u) = *(const uint32_t *)((const uint8_t *)source + 0x10u);
    *(uint32_t *)(payload + 0x64u) = *(const uint32_t *)((const uint8_t *)source + 0x14u);
    *(uint32_t *)(payload + 0x68u) = *(const uint32_t *)((const uint8_t *)source + 0x18u);
    payload = *(uint8_t **)node;
    if (payload != base) {
        previous = *(uint8_t **)(payload + 0x04u);
        next = *(uint8_t **)(payload + 0x08u);
        *(uint8_t **)(next + 0x04u) = previous;
        *(uint8_t **)(previous + 0x08u) = next;
        next = *(uint8_t **)(base + 0x08u);
        *(uint8_t **)(next + 0x04u) = payload;
        *(uint8_t **)(payload + 0x08u) = next;
        *(uint8_t **)(payload + 0x04u) = base;
        *(uint8_t **)(base + 0x08u) = payload;
    }
    return 0;
}
__attribute__((noinline)) uint32_t SoundTable_LookupIndexed_005AF75C(const void *table_slot,
                                           uint32_t key, uint32_t index)
{
    const uint8_t *table = *(const uint8_t *const *)table_slot;
    uint32_t low = 0u;
    uint32_t high = *(const uint16_t *)table;
    int32_t query = (int32_t)key;
    while (low != high) {
        uint32_t middle = low + (high - low) / 2u;
        const uint8_t *entry = table + 4u + middle * 8u;
        int32_t entry_key = (int32_t)*(const uint16_t *)entry;
        if (entry_key != query && query <= entry_key)
            high = middle;
        if (entry_key < query)
            low = middle + 1u;
        if (entry_key == query) {
            uint32_t count = *(const uint16_t *)(entry + 2u);
            if (count <= index)
                return 0xffffffffu;
            return *(const uint16_t *)(table +
                                       *(const uint32_t *)(entry + 4u) +
                                       index * 2u);
        }
    }
    return 0xffffffffu;
}
__attribute__((noinline)) void *EffectEvent_RecordInit_00544A50(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    uint8_t *first_head = bytes + 0x10u;
    uint8_t *second_head = bytes + 0x04u;
    uint8_t *first_link = bytes + 0x30u;
    void *first_group;
    void *tagged_group;
    *(uint8_t **)first_head = first_head;
    *(uint8_t **)(first_head + 0x04u) = first_head;
    *(uint8_t **)first_head = bytes;
    *(uint8_t **)(first_head + 0x08u) = NULL;
    *(uint8_t **)second_head = second_head;
    *(uint8_t **)(second_head + 0x04u) = second_head;
    *(uint8_t **)(second_head + 0x08u) = second_head;
    *(uint8_t **)(second_head + 0x0cu) = second_head;
    *(uint32_t *)(bytes + 0x00u) = 0x00d1e944u;
    *(uint8_t **)(bytes + 0x20u) = bytes + 0x24u;
    *(uint8_t **)(bytes + 0x24u) = bytes + 0x20u;
    *(uint8_t **)(bytes + 0x28u) = bytes + 0x24u;
    *(uint8_t **)(bytes + 0x2cu) = bytes + 0x24u;
    *(uint8_t **)(bytes + 0x30u) = bytes;
    *(uint8_t **)(bytes + 0x34u) = bytes + 0x30u;
    *(uint8_t **)(bytes + 0x38u) = bytes + 0x30u;
    first_group = *(void **)(uintptr_t)0x00d638ccu;
    if (first_group == NULL) {
        first_group = Engine_LazyListGroup_004C5BFC();
        *(void **)(uintptr_t)0x00d638ccu = first_group;
    }
    if (first_group != first_link) {
        uint8_t *previous = *(uint8_t **)(first_link + 0x04u);
        uint8_t *next = *(uint8_t **)(first_link + 0x08u);
        uint8_t *group_link = *(uint8_t **)((uint8_t *)first_group + 0x08u);
        *(uint8_t **)(next + 0x04u) = previous;
        *(uint8_t **)(previous + 0x08u) = next;
        *(uint8_t **)(group_link + 0x04u) = first_link;
        *(uint8_t **)(first_link + 0x04u) = (uint8_t *)first_group;
        *(uint8_t **)(first_link + 0x08u) = group_link;
        *(uint8_t **)((uint8_t *)first_group + 0x08u) = first_link;
    }
    *(uint32_t *)(bytes + 0x00u) = 0x00d1e728u;
    *(uint32_t *)(bytes + 0x20u) = 0x00d1e75cu;
    bytes[0x3cu] = 0u;
    bytes[0x3du] = 1u;
    bytes[0x3eu] = 0u;
    tagged_group = *(void **)(uintptr_t)0x00d6384cu;
    if (tagged_group == NULL) {
        tagged_group = Engine_LazyTaggedListGroup_004C5B30();
        *(void **)(uintptr_t)0x00d6384cu = tagged_group;
    }
    {
        uint8_t *tagged_link = (uint8_t *)tagged_group + 0x04u;
        uint8_t *second_link = bytes + 0x04u;
        if (tagged_link != second_link) {
            uint8_t *previous = *(uint8_t **)(second_link + 0x04u);
            uint8_t *next = *(uint8_t **)(second_link + 0x08u);
            uint8_t *group_tail = *(uint8_t **)((uint8_t *)tagged_group + 0x0cu);
            *(uint8_t **)(next + 0x04u) = previous;
            *(uint8_t **)(previous + 0x08u) = next;
            *(uint8_t **)(group_tail + 0x04u) = second_link;
            *(uint8_t **)(second_link + 0x04u) = tagged_link;
            *(uint8_t **)(second_link + 0x08u) = group_tail;
            *(uint8_t **)((uint8_t *)tagged_group + 0x0cu) = second_link;
        }
        *(uint8_t **)(bytes + 0x1cu) = tagged_link;
    }
    return record;
}
__attribute__((noinline)) void *EffectEvent_RecordBuilder_0057EF7C(void *record, uint32_t handle,
                                         uint8_t variant, uint32_t auxiliary)
{
    uint8_t *bytes = (uint8_t *)EffectEvent_RecordInit_00544A50(record);
    uint8_t *list = bytes + 0x40u;
    *(uint8_t **)list = bytes;
    *(uint8_t **)(list + 0x04u) = list;
    *(uint8_t **)(list + 0x08u) = list;
    *(uint32_t *)(bytes + 0x00u) = 0x00cee3a8u;
    *(uint32_t *)(bytes + 0x20u) = 0x00cee3dcu;
    *(uint32_t *)(bytes + 0x4cu) = handle;
    bytes[0x50u] = variant;
    *(uint32_t *)(bytes + 0x54u) = auxiliary;
    return bytes;
}
__attribute__((noinline)) void EffectEvent_BuildAndSubmit(uint32_t event_type, const uint32_t source[3])
{
    uint8_t payload[0x28u] = {0};
    void **dispatcher_slot = (void **)(uintptr_t)0x00d63854u;
    void *dispatcher = *dispatcher_slot;
    uint8_t **sequence_slot = (uint8_t **)(uintptr_t)0x00d5ee4au;
    uint8_t *sequence = *sequence_slot;
    uint8_t *counter = (uint8_t *)(uintptr_t)0x00d4e2f8u;
    if (dispatcher == NULL) {
        dispatcher = Engine_LazySingletonGetter_003FD6E0();
        *dispatcher_slot = dispatcher;
    }
    *(uint32_t *)(payload + 0x0cu) = 0x3f800000u;
    *(uint32_t *)(payload + 0x18u) = 0x3f800000u;
    *(uint32_t *)(payload + 0x1cu) = source[0];
    *(uint32_t *)(payload + 0x20u) = source[1];
    *(uint32_t *)(payload + 0x24u) = source[2];
    if (*sequence == 0u) {
        *counter = (uint8_t)(*counter + 1u);
        *sequence = *counter;
    }
    (void)EffectEvent_Submit(dispatcher, (uint32_t)*sequence << 16u | 2u,
                              event_type, payload);
}
__attribute__((noinline)) uint32_t EffectEvent_Dispatch(void *dispatcher, uint32_t event_id,
                              uint32_t effect_type, const void *record,
                              uint32_t flags)
{
    uint8_t *base = (uint8_t *)dispatcher;
    uint8_t *existing = (uint8_t *)EffectEvent_FindRecord_004B2894(
        dispatcher, event_id);
    uint8_t *candidate;
    uint8_t *previous;
    uint8_t *next;
    uint8_t *head;
    uint32_t sequence;
    uint32_t next_sequence;
    uint32_t handle;
    int result;
    if (existing == NULL)
        return 0xfffffffeu;
    candidate = *(uint8_t **)(*(uint8_t **)(base + 0x224u));
    if (candidate == NULL || candidate == *(uint8_t **)(base + 0x220u))
        return 0xfffffffdu;
    candidate[0x18u] = 4u;
    candidate[0x15u] = 1u;
    candidate[0x16u] = 0u;
    sequence = *(uint32_t *)(base + 0x1e10u);
    next_sequence = sequence + 1u;
    *(uint32_t *)(base + 0x1e10u) = next_sequence;
    if (next_sequence >= 0x1000000u)
        *(uint32_t *)(base + 0x1e10u) = 1u;
    handle = sequence | *(uint32_t *)(candidate + 0x10u);
    *(uint32_t *)(candidate + 0x24u) = handle;
    *(uint32_t *)(candidate + 0x20u) = event_id;
    *(uint32_t *)(candidate + 0x1cu) = effect_type;
    candidate[0x2au] = existing[0x16u];
    *(uint16_t *)(candidate + 0x28u) = *(const uint16_t *)record;
    previous = *(uint8_t **)(candidate + 0x08u);
    next = *(uint8_t **)(candidate + 0x0cu);
    *(uint8_t **)(next + 0x04u) = previous;
    *(uint8_t **)(previous + 0x08u) = next;
    head = candidate + 0x04u;
    *(uint8_t **)(candidate + 0x08u) = head;
    *(uint8_t **)(candidate + 0x0cu) = head;
    if (head != base + 0x22cu) {
        uint8_t *sentinel = base + 0x22cu;
        next = *(uint8_t **)(sentinel + 0x08u);
        *(uint8_t **)(next + 0x04u) = head;
        *(uint8_t **)(head + 0x04u) = sentinel;
        *(uint8_t **)(head + 0x08u) = next;
        *(uint8_t **)(sentinel + 0x08u) = head;
    }
    result = EffectEvent_QueueInsert_00417D34(
        base + 0x2148u, handle, record, flags);
    return result == -1 ? 0xfffffffdu : handle;
}
__attribute__((noinline)) int IntrusiveList_ResetAndStoreMetadata_0048D22C(
    void *pool, uint32_t value, uint32_t auxiliary)
{
    uint8_t *base = (uint8_t *)pool;
    uint8_t *node;
    uint8_t *payload;
    uint8_t *previous;
    uint8_t *next;
    if (IntrusiveList_Count_00473DB8(base + 0x0cu) <= 1u)
        return -1;
    node = *(uint8_t **)(base + 0x10u);
    if (*(uint8_t **)node == *(uint8_t **)(base + 0x0cu))
        return -1;
    payload = *(uint8_t **)node;
    previous = *(uint8_t **)(node + 0x04u);
    next = *(uint8_t **)(node + 0x08u);
    *(uint8_t **)(next + 0x04u) = previous;
    *(uint8_t **)(previous + 0x08u) = next;
    *(uint8_t **)(node + 0x04u) = node;
    *(uint8_t **)(node + 0x08u) = node;
    *(uint64_t *)(payload + 0x10u) = *(
        const uint64_t *)(*(uint8_t **)(uintptr_t)0x0048d2d8u + 0x08u);
    *(uint32_t *)(payload + 0x18u) = value;
    *(uint32_t *)(payload + 0x1cu) = auxiliary;
    payload = *(uint8_t **)node;
    if (payload != base) {
        previous = *(uint8_t **)(payload + 0x04u);
        next = *(uint8_t **)(payload + 0x08u);
        *(uint8_t **)(next + 0x04u) = previous;
        *(uint8_t **)(previous + 0x08u) = next;
        next = *(uint8_t **)(base + 0x08u);
        *(uint8_t **)(next + 0x04u) = payload;
        *(uint8_t **)(payload + 0x08u) = next;
        *(uint8_t **)(payload + 0x04u) = base;
        *(uint8_t **)(base + 0x08u) = payload;
    }
    return 0;
}
__attribute__((noinline)) int EffectEvent_ReleasePool(void *dispatcher, uint32_t value,
                            uint32_t auxiliary)
{
    (void)IntrusiveList_ResetAndStoreMetadata_0048D22C(
        (uint8_t *)dispatcher + 0x2148u, value, auxiliary);
    return 0;
}
__attribute__((noinline)) int EffectEvent_ReleasePool_0048D320(
    void *dispatcher, uint32_t value, uint32_t auxiliary)
{
    return EffectEvent_ReleasePool(dispatcher, value, auxiliary);
}
__attribute__((noinline)) int ResourceService_Register_00562F2C(
    void *destination, void *request, void *key, uint32_t *owner,
    uint32_t hidden0, uint32_t hidden1, uint32_t hidden2)
{
    static void **const service_slot = (void **)(uintptr_t)0x00562fc0u;
    void *service = *service_slot;
    void **vtable = *(void ***)service;
    uint32_t callback_result =
        ((uint32_t (*)(void *, uint32_t))vtable[2])(service, hidden0);
    int result = AsyncResource_Create_005ABE04(
        destination, request, key, owner, callback_result, hidden1,
        hidden2, 1u);
    if (result >= 0) {
        ((uint8_t *)destination)[5u] = 1u;
        return 0;
    }
    ((void (*)(void *, uint32_t, uint32_t))vtable[3])(
        service, callback_result, 1u);
    return result;
}
__attribute__((noinline)) void *Engine_LazyResourceFactory_0054F044(void)
{
    uint32_t *guard = (uint32_t *)(uintptr_t)0x0054f08cu;
    void **slot = (void **)(uintptr_t)0x0054f090u;
    if (((*guard & 1u) == 0u) && OnceGuard_TestAndSet_003B4FE4(guard) != 0)
        FUN_00488D60(*slot);
    return *slot;
}
__attribute__((noinline)) void Engine_ResourceDescriptorFinalize_0054E758(void **descriptor,
                                                uint32_t flags)
{
    uint8_t *range[2];
    uint8_t *outer;
    uint8_t *outer_end;
    FUN_004DEB00(range, descriptor);
    outer_end = range[1];
    FUN_004DEB00(range, descriptor);
    outer = range[0];
    while (outer != outer_end) {
        uint8_t *outer_field = outer + 0x0cu;
        int32_t outer_offset = *(int32_t *)outer_field;
        uint8_t *owner = outer_offset != 0
                             ? outer_field + outer_offset
                             : NULL;
        uint8_t *group_field = owner != NULL ? owner + 0xc8u : NULL;
        int32_t group_offset = group_field != NULL
                                   ? *(int32_t *)group_field
                                   : 0;
        uint8_t *group = group_offset != 0
                             ? group_field + group_offset
                             : NULL;
        uint32_t group_count = *(uint32_t *)(owner + 0xc4u);
        uint8_t *group_end = group + group_count * 4u;
        while (group != group_end) {
            uint8_t *entry_field = group;
            int32_t entry_offset = *(int32_t *)entry_field;
            uint8_t *resource = entry_offset != 0
                                    ? entry_field + entry_offset
                                    : NULL;
            if (resource != NULL &&
                (*(uint32_t *)resource & 0x10000001u) == 0x10000001u) {
                uint8_t *inner_field = resource + 0x3cu;
                int32_t inner_offset = *(int32_t *)inner_field;
                uint8_t *inner = inner_offset != 0
                                     ? inner_field + inner_offset
                                     : NULL;
                uint32_t inner_count = *(uint32_t *)(resource + 0x38u);
                uint8_t *inner_end = inner + inner_count * 4u;
                while (inner != inner_end) {
                    uint8_t *child_field = inner;
                    int32_t child_offset = *(int32_t *)child_field;
                    uint8_t *child = child_offset != 0
                                         ? child_field + child_offset
                                         : NULL;
                    if (child != NULL &&
                        (*(uint32_t *)child & 0x40000000u) != 0u)
                        *(uint32_t *)(child + 0x10u) = flags;
                    inner += 4u;
                }
            }
            group += 4u;
        }
        outer += 0x10u;
    }
}
__attribute__((noinline)) void *Engine_SharedDescriptorKey_Get(void)
{
    uint32_t *guard = (uint32_t *)(uintptr_t)0x00559624u;
    void **slot = (void **)(uintptr_t)0x0055963cu;
    if (((*guard & 1u) == 0u) && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        uint32_t initializer = 0x00ca459cu;
        uint8_t *resource = (uint8_t *)Engine_AllocateResource_003B5A8C(
            (void *)(uintptr_t)0x00d76398u, &initializer, 1u);
        struct ParameterRegistryRecordView *record =
            (struct ParameterRegistryRecordView *)(resource - 4u);
        record->node.tag_000 = 0x00d05910u;
        record->initializer_or_class_name_024 = (void *)(uintptr_t)initializer;
        record->record_size_028 = 0x3cu;
    }
    return *slot;
}
__attribute__((noinline)) void *CachedComponent_ResolveClass1(void *object, void *descriptor)
{
    uint8_t *bytes = (uint8_t *)descriptor;
    void *component;
    if (StatusDescriptor_ClassNibble(descriptor) != 1)
        return NULL;
    component = *(void **)(bytes + 0x1fcu);
    if (component != NULL)
        return component;
    component = OrderedTree_LowerBoundByPointer_004C5D3C(
        bytes + 0x1a4u, AvatarOnlineWork_Factory_00507744());
    component = component != NULL ? *(void **)component : NULL;
    if (component == *(void **)(bytes + 0x1a8u) || component == NULL)
        return NULL;
    *(void **)((uint8_t *)component + 0x5cu) = descriptor;
    *(void **)(bytes + 0x1fcu) = component;
    (void)object;
    return component;
}
__attribute__((noinline)) void *Engine_LazyResourceDescriptorGetter_0055D688(uint32_t allocation_size)
{
    uint32_t *guard = (uint32_t *)(uintptr_t)0x0055d6f4u;
    void **slot = (void **)(uintptr_t)0x0055d70cu;
    if (((*guard & 1u) == 0u) && OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        uint32_t initializer = 0x00ca1394u;
        uint8_t *resource = (uint8_t *)Engine_AllocateResource_003B5A8C(
            (void *)(uintptr_t)0x00d73f68u, &initializer, 1u,
            allocation_size);
        struct ParameterRegistryRecordView *record =
            (struct ParameterRegistryRecordView *)(resource - 4u);
        record->node.tag_000 = 0x00d0d168u;
        record->initializer_or_class_name_024 = (void *)(uintptr_t)initializer;
        record->record_size_028 = 0x88u;
    }
    return *slot;
}
extern void StatusResourceHealthBuildAndEvaluate(void *output_record,
                                                     void *resource,
                                                     float hidden_delta);
extern void StatusResourceAngularEvaluator(void *output_record,
                                               void *resource);
extern void StatusResourceTransformRotate(void *output_record);
extern void StatusResourceDispatch(void *dispatcher, void *resource,
                                      unsigned mode);
extern void StatusResourceTransformCommit(void *transform,
                                              void *profile);
extern void *StatusResourceZeroFill(void *destination, unsigned size);
extern void StatusLinkedVectorWrite(void *linked, const float values[3],
                                        uintptr_t source);
extern void StatusLinkedScalarCommit(void *linked, float value);
extern void StatusResourceAdvanceState(void *auxiliary, void *resource,
                                           float hidden_delta);
extern void StatusResourceAdvanceTypeOne(void *batch_state, void *resource,
                                           float hidden_delta);
extern void StatusResourceAdvanceElapsedMode(void *batch_state, void *resource,
                                               float hidden_delta);
extern void *StatusResource_RegistryGet(void);
extern void *StatusResource_LookupBasic(void *registry, int id);
extern void *StatusResource_LookupSelected(void *registry, int id,
                                               void *selector_context);
extern void *StatusResource_BuildFactoryPayload(const int16_t *id);
extern void *StatusResource_CreateObject(void *factory_context, void *payload,
                                             void *selected, void *source);
extern void *StatusResource_GetGlobalListSentinel(void);
extern void *StatusResource_GetComponentRegistry(void);
extern void StatusResource_RegisterComponent(void *registry, unsigned slot,
                                                 void *object);
extern void *StatusResource_GetCacheDescriptor(void *object);
extern void *StatusResource_GetEmbeddedState(void *object);
extern void *StatusResource_GetRelatedStatusComponent(void *object);
extern void *MessageWork_Factory_004D1524(void);
extern unsigned StatusResource_GetAllocatorContext(void *object);
extern void *Engine_LazySingletonGetter_0049BED0(void);
extern void *Engine_LazySingletonGetter_0049BE78(void);
extern void *Engine_LazySingletonGetter_00422CC8(void);
extern void *Engine_AllocateTaggedBlock(unsigned size, const void *tag,
                                            void *allocator_context);
extern void *Engine_EventPayloadAllocate_005D3DA8(unsigned size);
extern void *Engine_EventPayloadInitialize_005AC800(void *payload,
                                                       unsigned length,
                                                       unsigned mode);
extern void Engine_EventPayloadCopy_005AC798(void *payload,
                                               const void *source,
                                               unsigned length);
extern unsigned ParameterString_Hash_00448668(void *string_slot);
extern void Engine_StringBuilderInit_003D400C(void *string, uint32_t source);
extern unsigned ParameterString_Equals_00425E6C(const void *left,
                                                 const void *right);
extern void *OrderedTree_FindPayloadByNumericKey_0059394C(
    void *object, const uint32_t *entry);
extern void Engine_EffectEventDispatch_004CF9C8(void *dispatcher,
                                                 unsigned mode,
                                                 unsigned argument,
                                                 float elapsed,
                                                 float hidden_value);
extern void *StatusRuntimeRecord_Initialize(void *record, void *source,
                                                const uint32_t payload[4]);
extern int HealthParameterIdIsRange500(int id);
extern void StatusResource_SpecialRefresh(void *object, int mode);
extern const uint8_t StatusResource_RuntimeRecordTag;
extern int Engine_ResourceRegistrySlotRefresh_005A01F4(void *slot);
extern int Engine_ResourceRegistrySlotInitialize_0059FFF0(void *slot, int id);
extern uint32_t ResourceFactory_ConfigureAndSubmit_005B95F0(
    void *factory, int selector_a, int selector_b, uint32_t key,
    uint32_t value, int id);
extern uint32_t ResourceFactory_NextBindResource_005B949C(void *factory);
extern void *Engine_ResourceDescriptorFind_004B2134(uint32_t resource,
                                                     uint32_t descriptor);
__attribute__((noinline)) uint32_t Engine_ResourceTypeTableEntry_00533BC8(unsigned type)
{
    return ((const uint32_t *)(uintptr_t)0x00ca4a10u)[type];
}
extern int Engine_ResourceDescriptorMatches_00543ED4(
    unsigned type, uint32_t table_entry, void *descriptor);
extern void Engine_ResourceDescriptorRelink_0054E4D8(void **descriptor,
                                                       uint32_t flags);
extern void Engine_ResourceDescriptorPrepare_0054E56C(void **descriptor,
                                                        uint32_t flags);
extern void Engine_ResourceDescriptorFinalize_0054E758(void **descriptor,
                                                         uint32_t flags);
extern void Engine_ResourceDescriptorSubmit_00543054(unsigned type,
                                                       uint32_t table_entry,
                                                       void *descriptor);
extern void Engine_ResourceDescriptorRelease_005450DC(void *descriptor);
extern void Engine_ResourceDescriptorDestroy_00510D70(void *descriptor);
extern void Float_ForceIntConversion_0049A8B0(void);
extern float Libm_Floorf_0049A940(float value);
extern void *Engine_SharedObjectSingleton_004C5BA4(void);
extern void Engine_EventRegistryBroadcast_004B2978(void *registry,
                                                     const uint32_t *argument);
extern void *Engine_LazySingletonGetter_00498828(void);
extern void ParameterString_Format_00542F74(void *output,
                                             const char *value,
                                             int capacity);
extern uint32_t Engine_StatusCandidatePrepare_0057C8AC(void *registry,
                                                        void *argument);
extern int Engine_StatusCandidateSelect_0058F9B8(uint32_t selector);
extern int Engine_CandidateGlobalGate_004B5394(void);
extern int Engine_CandidateRegistryReady_0054A8FC(void *registry);
extern void *Engine_CandidateTableGet_005A8990(void);
extern uint32_t Engine_CandidateHandleSelector_0054AE88(uint32_t handle);
extern void OrderedTree_UnlinkNode_003D40E0(void *node, void *replacement);
extern void OrderedTree_LinkInsertedNode_0043AFF8(void *tree_frame,
                                                   int direction, void *node,
                                                   void *tree_root);
extern void *OrderedTree_InsertOrUpdate_0049B694(void *tree, void *node,
                                                  uint32_t key);
extern void *Engine_ResourceKeyResolve_0043A5E4(void *object,
                                                 void **factory_slot);
extern int OnceGuard_TestAndSet_003B4FE4(uint32_t *guard);
extern void Engine_ResourceFactoryRegistryInitialize_003E9560(void *registry);
extern void *Engine_RegistryComponentInitialize_003AE1F4(void *component,
                                                          unsigned kind);
extern void *Engine_ForEachStrideCallback_00421EA4(void *base,
                                                    void *callback,
                                                    unsigned stride,
                                                    unsigned count);
extern void *Engine_CopyBytes_0044C108(void *destination,
                                       const void *source,
                                       unsigned length);
extern void Engine_StateRecordUpdate_003E4EC0(void *record, int mode);
extern void Engine_ResourceTableFinalize_003D436C(void *table);
extern float TrigKernel_00474934(float value);
extern void *StatusResource_CoordinatorKey_0045F02C(void);
extern float *StatusSharedVector_Resolve(void *object);
extern void *Engine_FlaggedResourceLookup_0054AD70(void *table,
                                                    uint32_t flags);
extern void *Engine_FlaggedResourceLookup_0054ADC4(void *table,
                                                     uint32_t flags);
extern void *Engine_FlaggedResourceResolve_0051CE88(void *table,
                                                     uint32_t flags);
extern int Engine_ResourceDispatch_00512CE4(void *table,
                                             void *argument,
                                             void *destination,
                                             unsigned reserved,
                                             unsigned mode,
                                             uint32_t effective_selector,
                                             unsigned object_flag);
extern void Engine_RecordModeApply_005452E0(uint32_t *record);
extern void Engine_RecordModeApply_00545234(uint32_t *record);
extern void Engine_StridedInsertionSort_004C626C(void *base,
                                                  unsigned count,
                                                  unsigned stride,
                                                  void *comparator);
extern void *MemoryZeroEnd_003DC5D0(void *destination, unsigned size);
extern void Engine_StridedSortLargeCase_004C5F44(void *base,
                                                  unsigned count,
                                                  unsigned stride,
                                                  void *comparator);
extern void *EffectParameter_RecordInitialize(void *record);
extern void EffectParameter_RecordRandomize(void *record,
                                                       int source,
                                                       uint32_t selector,
                                                       int enabled);
extern void EffectParameter_BuildAndSubmit_005651D8(void *output,
                                                       uint32_t selector,
                                                       void *record,
                                                       uint32_t flags,
                                                       uint32_t arg4,
                                                       uint32_t arg5);
__attribute__((noinline)) void Engine_StatusEventRecordReset_00583308(uint32_t unused,
                                             void **record_link)
{
    uint8_t *record;
    (void)unused;
    if (record_link == NULL || *record_link == NULL)
        return;
    record = (uint8_t *)*record_link;
    if (record[0] == 0u || *(void **)(record + 0x10u) != record_link[1])
        return;
    record[0] = 0u;
    *(uint32_t *)(record + 0x04u) = 0u;
    *(uint32_t *)(record + 0x98u) = 0u;
    *(uint32_t *)(record + 0x9cu) = 0u;
    if ((record[0x0cu] & 4u) == 0u)
        return;
    static void **const registry_slot = (void **)(uintptr_t)0x00583394u;
    uint32_t argument = *(uint32_t *)(record + 0xccu);
    if (*registry_slot == NULL)
        *registry_slot = Engine_SharedObjectSingleton_004C5BA4();
    Engine_EventRegistryBroadcast_004B2978(*registry_slot, &argument);
    *(uint32_t *)(record + 0xccu) = 0u;
}
__attribute__((noinline)) void *Engine_StatusEventRecordAlloc(void)
{
    static void **const context_slot = (void **)(uintptr_t)0x00584b18u;
    uint8_t *context = (uint8_t *)*context_slot;
    uint8_t *record;
    if (context == NULL) {
        context = (uint8_t *)Engine_LazySingletonGetter_0049BED0();
        *context_slot = context;
    }
    record = (uint8_t *)Engine_AllocateTaggedBlock(
        0x18u, (const void *)(uintptr_t)0x00584b1cu,
        *(void **)(context + 0xc4u));
    if (record != NULL) {
        *(uint16_t *)(record + 0x04u) = 0xffffu;
        *(uint16_t *)(record + 0x06u) = 0u;
        *(uint32_t *)(record + 0x0cu) = 0u;
        *(uint32_t *)(record + 0x00u) = 0x00cf85b0u;
        *(uint32_t *)(record + 0x14u) = 0u;
        record[0x10u] = 0u;
        record[0x08u] = 1u;
    }
    return record;
}
__attribute__((noinline)) void Engine_StatusEventRecordSerialize(void *record, const void *payload,
                                       unsigned length)
{
    void *serialized = Engine_EventPayloadAllocate_005D3DA8(0x1cu);
    if (serialized != NULL) {
        serialized = Engine_EventPayloadInitialize_005AC800(
            serialized, length, 0u);
        if (serialized != NULL)
            Engine_EventPayloadCopy_005AC798(serialized, payload, length);
    }
    *(void **)((uint8_t *)record + 0x0cu) = serialized;
    *(uint16_t *)((uint8_t *)record + 0x06u) = (uint16_t)(length + 0x58u);
}
__attribute__((noinline)) void StatusRuntimeRecord_SetActive_0055CC08(void *record, unsigned enabled)
{
    uint32_t *flags = (uint32_t *)((uint8_t *)record + 0x14u);
    if (enabled == 0u)
        *flags &= ~8u;
    else
        *flags |= 8u;
}
extern void *OrderedTree_Successor_00464110(void *node);
extern void StatusModeRegistry_RelinkAndDispatch_00540430(void *entry);
extern int Engine_StatusModeIsType5(void);
extern void *Engine_LazySingletonGetter_003FD6E0(void);
extern void *Engine_LazySingletonGetter_004C59C0(void);
extern void Engine_EffectEventReleasePool_0048D320(void *dispatcher);
extern void Engine_TransitionEventSubmit_00566E6C(void *dispatcher,
                                                   const void *event_record);
extern void **Engine_LazyRegistryGetter_0049BF80(void);
extern void *Engine_LazyFactoryRegistryGetter_0049BF28(void);
extern int Engine_ResourceLookupOrCreate_004FE294(void *registry,
                                                   unsigned mode,
                                                   unsigned selector,
                                                   unsigned key);
extern void *ResourceFactory_Create_004C5938(void);
extern unsigned ResourceFactory_GetVariant_0057F6A0(void *factory,
                                                     unsigned selector);
extern void ResourceFactoryOwnerParams_Init_004452A4(void *params);
extern int ResourceFactoryOwnerIndex_0057EF10(void *table, void *params,
                                               unsigned parameter);
extern int ResourceFactoryOwnerPublish_00559208(void *factory, int type,
                                                  int subtype, int index);
extern void *ResourceFactoryOwnerTable_Get_0054F000(void);
extern unsigned ResourceFactory_GetOwner_00559508(void *factory,
                                                   unsigned parameter);
extern int Engine_ResourceConstruct_004DC1D4(void *registry,
                                              unsigned registry_word,
                                              unsigned owner,
                                              unsigned variant,
                                              unsigned parameter,
                                              unsigned hidden_bits,
                                              unsigned zero);
extern unsigned FUN_005A8534(void *factory, unsigned kind);
extern unsigned FUN_005A83D0(void *factory, unsigned kind, unsigned arg2);
extern int Engine_ResourceConstruct_004DC1D4_Float(
    void *registry, unsigned registry_word, unsigned owner, unsigned variant,
    unsigned parameter, float hidden_scale, unsigned zero)
    ;
extern void Engine_ResourceRegistrySubmit_004A7354(void *registry,
                                                    unsigned mode,
                                                    unsigned selector,
                                                    unsigned key,
                                                    int resource);
__attribute__((noinline)) unsigned ResourceFactory_GetOwner_00559508(void *factory, unsigned parameter)
{
    static void **const singleton_slot =
        (void **)(uintptr_t)0x005595b0u;
    static void **const table_slot = (void **)(uintptr_t)0x005595b4u;
    uint8_t params[0x18u];
    uint8_t *singleton = (uint8_t *)*singleton_slot;
    void *table;
    int type;
    int subtype;
    int index;
    if (singleton == NULL) {
        singleton = (uint8_t *)Engine_LazySingletonGetter_00422CC8();
        *singleton_slot = singleton;
    }
    type = *(int8_t *)(singleton + 0x3f04u);
    subtype = *(int8_t *)(singleton + 0x3f05u);
    ResourceFactoryOwnerParams_Init_004452A4(params);
    params[0] = (uint8_t)type;
    params[1] = (uint8_t)subtype;
    *(float *)(params + 4u) = *(float *)(singleton + 0x3f08u);
    *(float *)(params + 8u) = *(float *)(singleton + 0x3f0cu);
    table = *table_slot;
    if (table == NULL) {
        table = ResourceFactoryOwnerTable_Get_0054F000();
        *table_slot = table;
    }
    index = ResourceFactoryOwnerIndex_0057EF10(table, params, parameter);
    return (unsigned)ResourceFactoryOwnerPublish_00559208(
        factory, type, subtype, index + 10);
}
__attribute__((noinline)) void StatusOwner_Notify_00544B98(void *owner, int mode, unsigned enabled)
{
    uint8_t *bytes = (uint8_t *)owner;
    bytes[0xb4u] = (uint8_t)enabled;
    bytes[0xb5u] = (uint8_t)mode;
}
__attribute__((noinline)) void StatusEvent_TemporaryRecordBuild(void *output, int mode, int key,
                                      const uint32_t *vector_a,
                                      const uint32_t *vector_b,
                                      uint32_t scalar, void *source,
                                      uint32_t auxiliary, uint32_t hidden)
{
    uint8_t *record = (uint8_t *)output;
    uint32_t handle;
    *(uint32_t *)(record + 0x28u) =
        (*(uint32_t *)(record + 0x28u) & 0xfffffe00u) | 0xfffffe00u;
    StatusEventPayload_Initialize_003531A4(record + 0x30u);
    if (source != NULL)
        handle = *(uint32_t *)((uint8_t *)source + 0x12cu);
    else
        handle = 0xfffffe00u;
    record[0x00u] = (uint8_t)mode;
    *(int32_t *)(record + 0x04u) = key;
    *(uint32_t *)(record + 0x28u) = handle;
    *(uint32_t *)(record + 0x0cu) = vector_a[0];
    *(uint32_t *)(record + 0x10u) = vector_a[1];
    *(uint32_t *)(record + 0x14u) = vector_a[2];
    *(uint32_t *)(record + 0x18u) = vector_b[0];
    *(uint32_t *)(record + 0x1cu) = vector_b[1];
    *(uint32_t *)(record + 0x20u) = vector_b[2];
    *(uint32_t *)(record + 0x24u) = vector_b[3];
    *(uint32_t *)(record + 0x08u) = scalar;
    *(uint32_t *)(record + 0x2cu) = hidden;
    *(uint32_t *)(record + 0x5cu) = auxiliary;
    if (mode == 2) {
        *(uint32_t *)(record + 0x60u) = 0u;
    } else if (mode == 3) {
        record[0x60u] = 0u;
        record[0x61u] = 0u;
        *(uint32_t *)(record + 0x64u) = 0u;
        *(uint32_t *)(record + 0x68u) = 0u;
        *(uint32_t *)(record + 0x6cu) = 0u;
        *(uint32_t *)(record + 0x70u) = 0u;
        record[0x74u] = 0u;
        *(uint32_t *)(record + 0x78u) = 0u;
        record[0x7cu] = 0u;
        *(uint32_t *)(record + 0x80u) = 0u;
        *(uint16_t *)(record + 0x84u) = 0xffffu;
    } else if (mode == 5) {
        record[0x60u] = 0u;
        *(uint32_t *)(record + 0x64u) = 0u;
    }
}
__attribute__((noinline)) int Engine_StatusResourceCreateWrapper_0055CE74(
    void *unused, void *unused2, unsigned key, unsigned mode,
    unsigned selector, unsigned parameter, uint32_t hidden0,
    uint32_t hidden1, uint32_t hidden2)
{
    static void **const factory_registry_slot =
        (void **)(uintptr_t)0x0055cf40u;
    static void **const factory_slot = (void **)(uintptr_t)0x0055cf44u;
    static void **const registry_slot = (void **)(uintptr_t)0x0055cf48u;
    void *factory_registry = *factory_registry_slot;
    void *factory;
    void *record;
    (void)unused;
    (void)unused2;
    if (factory_registry == NULL) {
        factory_registry = Engine_LazyFactoryRegistryGetter_0049BF28();
        *factory_registry_slot = factory_registry;
    }
    if (StatusResource_KeyValidate_004FF108(factory_registry, 0x0bu, key) ==
        0)
        return 0;
    factory = *factory_slot;
    if (factory == NULL) {
        factory = Engine_ThresholdAuxAllocator_00475D70();
        *factory_slot = factory;
    }
    record = StatusResource_ModeRecordLookup_00584270(
        factory, mode, key, selector);
    if (record == NULL)
        return 0;
    {
        void *registry = *registry_slot;
        if (registry == NULL) {
            registry = Engine_LazyRegistryGetter_0049BF80();
            *registry_slot = registry;
        }
        return StatusResource_Construct_00584B78(
            registry, key, *(uint32_t *)((uint8_t *)record + 0xd4u),
            parameter, hidden0, hidden1, hidden2);
    }
}
__attribute__((noinline)) void StatusResource_LinkOrReleaseOwner_00559998(void *resource, unsigned mode)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    uint32_t handle;
    uint8_t *owner;
    uint8_t *old_owner;
    if (*(int32_t *)(resource_bytes + 0x1cu) == -1)
        return;
    resource_bytes[0xe8u] = (uint8_t)mode;
    {
        const uint32_t kNullGeneration = 0x007fffffu;
        handle = *(uint32_t *)(resource_bytes + 0x20u);
        if (kNullGeneration == (handle >> 9u))
            return;
    }
    {
        uint8_t *const generation_table = (uint8_t *)(uintptr_t)0x00e11614u;
        uint8_t *const entry = generation_table + (handle & 0x1ffu) * 8u;
        if (*(uint32_t *)(entry + 4u) != (handle >> 9u))
            return;
        owner = *(uint8_t **)entry;
    }
    old_owner = *(uint8_t **)(owner + 0x1e4u);
    if (old_owner == NULL) {
        uint32_t key = (uint32_t)(uintptr_t)Engine_LazySingletonGetter_00498828();
        uint8_t *sentinel = owner + 0x1a8u;
        uint8_t *node = *(uint8_t **)(owner + 0x1acu);
        uint8_t *candidate = sentinel;
        while (*(uint8_t *)(node + 0x10u) != 0u) {
            if (*(uint32_t *)(node + 0x14u) < key) {
                node = *(uint8_t **)(node + 0x0cu);
            } else {
                candidate = node;
                node = *(uint8_t **)(node + 0x08u);
            }
        }
        if (candidate != sentinel &&
            *(uint32_t *)(candidate + 0x14u) <= key) {
            old_owner = *(uint8_t **)candidate;
        } else {
            old_owner = *(uint8_t **)sentinel;
        }
        if (old_owner == *(uint8_t **)sentinel)
            return;
        if (old_owner != NULL) {
            *(uint8_t **)(old_owner + 0x1cu) = owner;
            *(uint8_t **)(owner + 0x1e4u) = old_owner;
        }
    }
    if (old_owner != NULL && *(void **)(old_owner + 0x24u) != NULL)
        StatusOwner_Notify_00544B98(*(void **)(old_owner + 0x24u),
                                    (int)(int8_t)resource_bytes[0xe8u], 1u);
}
__attribute__((noinline)) float Engine_StatusResourceSingletonEnsure_005A1D08(uint8_t selector)
{
    static void **const slot = (void **)(uintptr_t)0x005a1d64u;
    uint8_t *resource;
    if (*slot == NULL)
        *slot = Engine_LazySingletonGetter_004C59C0();
    resource = (uint8_t *)*slot + 0x20e8;
    if (selector == 1)
        return *(float *)(resource + 0x158);
    if (selector == 2)
        return *(float *)(resource + 0x140);
    if (selector == 3)
        return *(float *)(resource + 0x134);
    if (selector == 4)
        return *(float *)(resource + 0x14c);
    return *(float *)(resource + 0x164);
}
__attribute__((noinline)) void *Engine_StatusSharedBaseGet(void)
{
    static void **const singleton_slot = (void **)(uintptr_t)0x0059075cu;
    void *singleton = *singleton_slot;
    if (singleton == NULL) {
        singleton = Engine_LazySingletonGetter_004C59C0();
        *singleton_slot = singleton;
    }
    return (uint8_t *)singleton + 0x5a0u;
}
__attribute__((noinline)) void *Engine_EmbeddedListNode_005506A8(void *object)
{
    if (object == NULL)
        return NULL;
    return (uint8_t *)object + 0x20cu;
}
__attribute__((noinline)) void StatusResource_RefreshActiveEntries_00562D68(void *base,
                                                   uint32_t mark)
{
    uint8_t *bytes = (uint8_t *)base;
    void *node = *(void **)(bytes + 0x14u);
    void *end_payload = *(void **)(bytes + 0x0cu);
    while ((node != 0 ? *(void **)node : 0) != end_payload) {
        uintptr_t entry_address = node != 0 ?
            (uintptr_t)*(void **)node : 0u;
        void *entry = (void *)entry_address;
        if (*(uint8_t *)(entry_address + 0x1au) != 0u) {
            if (mark != 0u) {
                *(uint8_t *)((uint8_t *)entry + 0x38u) = 1u;
                *(uint8_t *)((uint8_t *)entry + 0x39u) = 1u;
            }
            StatusModeRegistry_RelinkAndDispatch_00540430(entry);
        }
        node = OrderedTree_Successor_00464110(node);
    }
}
__attribute__((noinline)) int StatusResource_FilterEntriesByMaskAt14_00562E94(
    void *base, uint32_t mask, uint32_t selector, void **output)
{
    uint8_t *bytes = (uint8_t *)base;
    void *node = *(void **)(bytes + 0x14u);
    void *end_payload = *(void **)(bytes + 0x0cu);
    int count = 0;
    while ((node != 0 ? *(void **)node : 0) != end_payload) {
        uintptr_t entry_address = node != 0 ?
            (uintptr_t)*(void **)node : 0u;
        if ((mask & selector) ==
            (*(uint32_t *)(entry_address + 0x14u) & selector))
            output[count++] = (void *)entry_address;
        node = OrderedTree_Successor_00464110(node);
    }
    return count;
}
__attribute__((noinline)) int StatusResource_FilterEntriesByMask_00561AB0(
    void *base, uint32_t mask, uint32_t selector, void **output)
{
    uint8_t *bytes = (uint8_t *)base;
    void *node = *(void **)(bytes + 0x0cu);
    void *end_payload = *(void **)(bytes + 4u);
    int count = 0;
    while ((node != 0 ? *(void **)node : 0) != end_payload) {
        uintptr_t entry_address = node != 0 ?
            (uintptr_t)*(void **)node : 0u;
        if ((mask & selector) ==
            (*(uint32_t *)(entry_address + 0x14u) & selector))
            output[count++] = (void *)entry_address;
        node = OrderedTree_Successor_00464110(node);
    }
    return count;
}
__attribute__((noinline)) int StatusResource_SlotCacheHasVacancy(void *base, int index)
{
    uint8_t *bytes = (uint8_t *)base;
    int selector = *(int8_t *)(bytes + index + 0x6cu);
    int count;
    uint32_t *handles;
    if (selector == -1 || bytes[0] == 0u)
        return 0;
    count = *(int32_t *)(bytes + selector * 8 + 4u);
    handles = *(uint32_t **)(bytes + selector * 8 + 8u);
    for (int slot = 0; slot < count; ++slot) {
        uint32_t key = handles[slot];
        uint32_t record_generation;
        uintptr_t record;
        if (*(uint32_t *)(uintptr_t)0x00562cf8u == (key >> 9))
            record_generation = 0u;
        else {
            record = (uintptr_t)*(void **)(uintptr_t)0x00562cfcu +
                     (key & 0x1ffu) * 8u;
            record_generation = *(uint32_t *)(record + 4u) ==
                                (key >> 9) ?
                                *(uint32_t *)record : 1u;
        }
        if (record_generation == 0u)
            return 1;
    }
    return 0;
}
__attribute__((noinline)) void StatusResource_SlotCacheReplace_0057F77C(uint32_t *cache,
                                               void *object)
{
    uint32_t count = cache[0];
    uint32_t *slots = (uint32_t *)(uintptr_t)cache[2];
    for (uint32_t index = 0; index < count; ++index) {
        uint32_t key = slots[index];
        uint32_t record;
        if (*(uint32_t *)(uintptr_t)0x0057f804u == (key >> 9))
            record = 0u;
        else {
            uintptr_t table = (uintptr_t)
                *(void **)(uintptr_t)0x0057f808u;
            uintptr_t entry = table + (key & 0x1ffu) * 8u;
            record = *(uint32_t *)(entry + 4u) == (key >> 9) ?
                     *(uint32_t *)entry : 1u;
        }
        if (record == 0u) {
            uint32_t handle =
                *(uint32_t *)((uint8_t *)object + 0x12cu);
            slots[index] = (handle & 0x1ffu) |
                           ((handle >> 9) << 9);
            return;
        }
    }
}
__attribute__((noinline)) int Record_SumWordRange_00575F98(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    int sum = 0;
    for (unsigned offset = 8u; offset <= 0x48u; offset += 4u)
        sum += *(int32_t *)(bytes + offset);
    return sum;
}
__attribute__((noinline)) int Record_SumWordLanes_005928C8(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    int sum = 0;
    for (unsigned offset = 0x4cu; offset <= 0x8cu; offset += 4u)
        sum += *(int32_t *)(bytes + offset);
    return sum;
}
__attribute__((noinline)) void StatusLane_AccumulateSecondary(void *record, int value, int index)
{
    if (Engine_StatusModeIsType5() != 0)
        return;
    *(int32_t *)((uint8_t *)record + 8u + index * 4) += value;
    *(int32_t *)((uint8_t *)record + 0x2bcu) += value;
    *(uint8_t *)((uint8_t *)record + 0x2c8u) = 1u;
}
__attribute__((noinline)) void StatusLane_AccumulatePrimary(void *record, int value, int index)
{
    if (Engine_StatusModeIsType5() != 0)
        return;
    *(int32_t *)((uint8_t *)record + 0x4cu + index * 4) += value;
    *(int32_t *)((uint8_t *)record + 0x2c0u) += value;
    *(uint8_t *)((uint8_t *)record + 0x2c8u) = 1u;
}
__attribute__((noinline)) void StatusRecord_SetChannelBitMasks_005403EC(void *record,
                                               uint32_t enable_primary,
                                               uint32_t enable_secondary,
                                               uint32_t bit_index)
{
    uint32_t bit = bit_index & 0xffu;
    uint32_t mask = bit < 32u ? 1u << bit : 0u;
    uint8_t *bytes = (uint8_t *)record;
    if (bytes[0x1au] == 0u)
        return;
    if (enable_primary != 0u)
        *(uint32_t *)(bytes + 0x30u) |= mask;
    else
        *(uint32_t *)(bytes + 0x30u) &= ~mask;
    if (enable_secondary != 0u)
        *(uint32_t *)(bytes + 0x34u) |= mask;
    else
        *(uint32_t *)(bytes + 0x34u) &= ~mask;
    StatusModeRegistry_RelinkAndDispatch_00540430(record);
}
__attribute__((noinline)) void Engine_TransitionState_SetSelector_0057259C(uint32_t *state,
                                                     uint32_t selector)
{
    uint32_t flags;
    if (selector > 2u)
        return;
    flags = state[1];
    if (selector == ((flags << 6) >> 30))
        return;
    *(float *)((uint8_t *)state + 0x74u) = 0.0f;
    state[1] = (flags & 0xfcffffffu) | (selector << 24);
}
__attribute__((noinline)) void Engine_TransitionRecord_ForwardAt134_00575184(void *object,
                                                    uint32_t selector)
{
    uint8_t *transition = *(uint8_t **)((uint8_t *)object + 0x140u);
    if (transition == 0)
        return;
    Engine_TransitionState_SetSelector_0057259C(
        (uint32_t *)(transition + 0x134u), selector);
}
__attribute__((noinline)) void Engine_TransitionRecord_SetScalar_00575240(void *object,
                                                 uint32_t value)
{
    uint8_t *transition = *(uint8_t **)((uint8_t *)object + 0x140u);
    if (transition != 0)
        *(uint32_t *)(transition + 0x105cu) = value;
}
__attribute__((noinline)) void Engine_TransitionEvent_Emit_00559ACC(void *object, uint32_t mode,
                                           void *arg3, uint32_t packed)
{
    static void **const singleton_slot =
        (void **)(uintptr_t)0x00559b24u;
    void *dispatcher = *singleton_slot;
    uint32_t event_record;
    (void)object;
    (void)mode;
    (void)arg3;
    if (dispatcher == 0) {
        dispatcher = Engine_LazySingletonGetter_003FD6E0();
        *singleton_slot = dispatcher;
    }
    Engine_EffectEventReleasePool_0048D320(dispatcher);
    event_record = packed & 0xffff0000u;
    Engine_TransitionEventSubmit_00566E6C(dispatcher, &event_record);
}
__attribute__((noinline)) int StatusResource_CreateFromParameters(void *registry, uint32_t param2,
                                        uint32_t param3, uint32_t param4,
                                        uint32_t hidden_bits)
{
    static void **const registry_slot =
        (void **)(uintptr_t)0x00585a90u;
    static void **const factory_slot =
        (void **)(uintptr_t)0x00585a94u;
    void *factory_registry = *registry_slot;
    uint32_t resource_key = ((param2 & 0xffffu) << 8) |
                            (param3 & 0xffu);
    int resource;
    if (factory_registry == NULL) {
        factory_registry = Engine_LazyFactoryRegistryGetter_0049BF28();
        *registry_slot = factory_registry;
    }
    resource = Engine_ResourceLookupOrCreate_004FE294(
        factory_registry, 1u, 0u, resource_key | 0x10000000u);
    if (resource != 0)
        return resource;
    {
        void *factory = *factory_slot;
        unsigned variant;
        unsigned owner;
        if (factory == NULL) {
            factory = ResourceFactory_Create_004C5938();
            *factory_slot = factory;
        }
        variant = ResourceFactory_GetVariant_0057F6A0(factory, param3);
        factory = *factory_slot;
        if (factory == NULL) {
            factory = ResourceFactory_Create_004C5938();
            *factory_slot = factory;
        }
        owner = ResourceFactory_GetOwner_00559508(factory, param2);
        resource = Engine_ResourceConstruct_004DC1D4(
            registry, *(uint32_t *)registry, owner, variant, param4,
            hidden_bits, 0u);
    }
    if (resource != 0)
        Engine_ResourceRegistrySubmit_004A7354(
            factory_registry, 1u, 0u, resource_key | 0x10000000u, resource);
    return resource;
}
__attribute__((noinline)) int Engine_Type3ResourceCreate_0055EF6C(uint32_t *state, uint32_t kind,
                                        uint32_t arg2, uint32_t arg3,
                                        float hidden_scale)
{
    static void **const registry_slot =
        (void **)(uintptr_t)0x0055f060u;
    static void **const factory_slot =
        (void **)(uintptr_t)0x0055f064u;
    void *registry = *registry_slot;
    int result;
    void *factory;
    uint32_t owner;
    uint32_t variant;
    if (registry == NULL) {
        registry = Engine_LazyFactoryRegistryGetter_0049BF28();
        *registry_slot = registry;
    }
    result = Engine_ResourceLookupOrCreate_004FE294(
        registry, 4u, kind, arg2);
    if (result != 0)
        return result;
    factory = *factory_slot;
    if (factory == NULL) {
        factory = ResourceFactory_Create_004C5938();
        *factory_slot = factory;
    }
    owner = FUN_005A8534(factory, kind);
    factory = *factory_slot;
    if (factory == NULL) {
        factory = ResourceFactory_Create_004C5938();
        *factory_slot = factory;
    }
    variant = FUN_005A83D0(factory, kind, arg2);
    result = Engine_ResourceConstruct_004DC1D4_Float(
        state, *state, owner, variant, arg3, hidden_scale, 0u);
    if (result != 0)
        Engine_ResourceRegistrySubmit_004A7354(
            registry, 4u, kind, arg2, result);
    return result;
}
__attribute__((noinline)) void StatusResource_FactoryDispatch(uint32_t ignored0, uint32_t ignored1,
                                    uint32_t arg2, uint32_t arg3,
                                    uint32_t arg4, uint32_t arg5)
{
    static void **const registry_slot =
        (void **)(uintptr_t)0x0055cfa0u;
    void *registry = *registry_slot;
    (void)ignored0;
    (void)ignored1;
    if (registry == 0) {
        registry = Engine_LazyRegistryGetter_0049BF80();
        *registry_slot = registry;
    }
    (void)StatusResource_CreateFromParameters(registry, arg2, arg3, arg4,
                                               arg5);
}
static void StatusResource_MoveListNode(void *sentinel, void *node)
{
    uint8_t *node_bytes = (uint8_t *)node;
    void *previous;
    void *next;
    void *first;
    if (sentinel == node)
        return;
    previous = *(void **)(node_bytes + 4u);
    next = *(void **)(node_bytes + 8u);
    *(void **)((uint8_t *)next + 4u) = previous;
    *(void **)((uint8_t *)previous + 8u) = next;
    first = *(void **)((uint8_t *)sentinel + 8u);
    *(void **)((uint8_t *)first + 4u) = node;
    *(void **)(node_bytes + 8u) = first;
    *(void **)(node_bytes + 4u) = sentinel;
    *(void **)((uint8_t *)sentinel + 8u) = node;
}
void StatusResourceValueHook(void *output_record, const void *resource);
void StatusResourceMotionBuild(void *output_record, void *resource,
                                  float hidden_delta);
unsigned StatusResourceApplyMotionAndState(void *output_record,
                                               void *resource);
__attribute__((noinline)) void StatusResourceUpdateOne(void *output_record, void *resource,
                                float hidden_delta);
void StatusResourceBatchCommit(void *batch);
int StatusResourceBatchUpdate(void *batch, void *unused_1, void *unused_2,
                                 void *frame_context);
__attribute__((noinline)) static void StatusResourceMotionRecordInitialize(uint8_t *record)
{
    *(uint32_t *)(record + 4u) = 0;
    *(uint32_t *)(record + 0xcu) = 0;
    *(uint32_t *)(record + 0x78u) = 0;
    record[0x7cu] = 0;
    *(uint32_t *)(record + 0x10cu) = 0;
    *(uint32_t *)(record + 0x110u) = 0;
    *(uint32_t *)(record + 0x118u) = 0;
    record[6] |= 1u;
}
__attribute__((noinline)) static void StatusResourceTransformRecordInitialize(uint8_t *record)
{
    static const uint32_t *const fallback =
        (const uint32_t *)(uintptr_t)0x00dc249cu;
    *(uint32_t *)(record + 0x9cu) = 0;
    *(uint32_t *)(record + 0u) = 0;
    *(uint32_t *)(record + 8u) = 0;
    *(uint32_t *)(record + 0xcu) = 0;
    *(uint32_t *)(record + 0x10u) = 0;
    *(uint16_t *)(record + 0x14u) = 0;
    *(uint32_t *)(record + 0x70u) = 0;
    record[0] |= 7u;
    *(uint32_t *)(record + 0x30u) = fallback[0];
    *(uint32_t *)(record + 0x34u) = fallback[1];
    *(uint32_t *)(record + 0x38u) = fallback[2];
    record[4] = 1;
}
__attribute__((noinline)) void StatusResourceBatchInitialize(void *batch)
{
    static const uint32_t *const template_words =
        (const uint32_t *)(uintptr_t)0x00dc2638u;
    uint8_t *base = (uint8_t *)batch;
    StatusResourceZeroFill(base + 0x38u, 0x7800u);
    for (unsigned index = 0; index != 32u; ++index) {
        uint8_t *record = base + index * 0x3c0u;
        record[0x3cu] = 0;
        for (unsigned word = 0; word != 8u; ++word)
            *(uint32_t *)(record + 0x70u + word * 4u) = template_words[word];
        *(uint32_t *)(record + 0xb0u) = 0x3f800000u;
        *(uint8_t **)(record + 0x124u) = record + 0x12cu;
        *(uint32_t *)(record + 0x128u) = 0x20u;
        StatusResourceMotionRecordInitialize(record + 0x1acu);
        StatusResourceTransformRecordInitialize(record + 0x2d0u);
    }
}
__attribute__((noinline)) void StatusResourceAdvanceState(void *batch_state, void *resource,
                                float hidden_delta)
{
    uint8_t type = *(uint8_t *)((uint8_t *)resource + 8u);
    if (type == 1u) {
        StatusResourceAdvanceTypeOne(batch_state, resource, hidden_delta);
        return;
    }
    if (type == 2u)
        StatusResourceAdvanceElapsedMode(batch_state, resource, hidden_delta);
}
__attribute__((noinline)) int Engine_ResourceRegistrySlotRefresh_005A01F4(void *slot)
{
    static void **const factory_slot = (void **)(uintptr_t)0x005a0420u;
    static void **const registry_slot = (void **)(uintptr_t)0x005a0424u;
    uint8_t *bytes = (uint8_t *)slot;
    int id = *(int *)(bytes + 4u);
    void *factory = *factory_slot;
    uint32_t packed;
    if (id == -1)
        return 1;
    if (factory == NULL) {
        factory = ResourceFactory_Create_004C5938();
        *factory_slot = factory;
    }
    packed = ResourceFactory_ConfigureAndSubmit_005B95F0(
        factory, (int)(signed char)bytes[8], (int)(signed char)bytes[9],
        *(uint32_t *)(bytes + 0x0cu), *(uint32_t *)(bytes + 0x10u),
        (int)(int16_t)id);
    for (unsigned variant = 0; variant != 0x0bu; ++variant) {
        if (factory == NULL) {
            factory = ResourceFactory_Create_004C5938();
            *factory_slot = factory;
        }
        void *descriptor = Engine_ResourceDescriptorFind_004B2134(
            packed, ResourceFactory_GetVariant_0057F6A0(factory, variant));
        if (descriptor != NULL) {
            void *registry = *registry_slot;
            if (registry == NULL) {
                registry = Engine_LazyFactoryRegistryGetter_0049BF28();
                *registry_slot = registry;
            }
            int resource_address = Engine_ResourceLookupOrCreate_004FE294(
                registry, 2u, (unsigned)id, variant);
            if (resource_address != 0 &&
                *(int *)((uint8_t *)(uintptr_t)resource_address + 0xc0u) > 0)
                return 0;
        }
    }
    if (factory == NULL) {
        factory = ResourceFactory_Create_004C5938();
        *factory_slot = factory;
    }
    packed = ResourceFactory_ConfigureAndSubmit_005B95F0(
        factory, (int)(signed char)bytes[8], (int)(signed char)bytes[9],
        *(uint32_t *)(bytes + 0x0cu), *(uint32_t *)(bytes + 0x10u),
        (int)(int16_t)id);
    if (factory == NULL) {
        factory = ResourceFactory_Create_004C5938();
        *factory_slot = factory;
    }
    void *descriptor = Engine_ResourceDescriptorFind_004B2134(
        packed, ResourceFactory_NextBindResource_005B949C(factory));
    if (descriptor != NULL)
        Engine_ResourceDescriptorDestroy_00510D70(descriptor);
    packed = ResourceFactory_ConfigureAndSubmit_005B95F0(
        factory, (int)(signed char)bytes[8], (int)(signed char)bytes[9],
        *(uint32_t *)(bytes + 0x0cu), *(uint32_t *)(bytes + 0x10u),
        (int)(int16_t)id);
    for (unsigned variant = 0; variant != 0x0bu; ++variant) {
        if (factory == NULL) {
            factory = ResourceFactory_Create_004C5938();
            *factory_slot = factory;
        }
        descriptor = Engine_ResourceDescriptorFind_004B2134(
            packed, ResourceFactory_GetVariant_0057F6A0(factory, variant));
        if (descriptor != NULL) {
            void *registry = *registry_slot;
            if (registry == NULL) {
                registry = Engine_LazyFactoryRegistryGetter_0049BF28();
                *registry_slot = registry;
            }
            int resource_address = Engine_ResourceLookupOrCreate_004FE294(
                registry, 2u, (unsigned)id, variant);
            if (resource_address != 0 &&
                *(int *)((uint8_t *)(uintptr_t)resource_address + 0xc0u) > 0)
                return 0;
            Engine_ResourceDescriptorDestroy_00510D70(descriptor);
            Engine_ResourceDescriptorRelease_005450DC(descriptor);
        }
    }
    bytes[8] = 0xffu;
    bytes[9] = 0xffu;
    *(uint32_t *)(bytes + 0x10u) = 0xffffffffu;
    *(uint32_t *)(bytes + 0x0cu) = 0u;
    *(int *)(bytes + 4u) = -1;
    return 1;
}
__attribute__((noinline)) int Engine_ResourceRegistrySlotInitialize_0059FFF0(void *slot, int id)
{
    static void **const state_slot = (void **)(uintptr_t)0x005a01ecu;
    static void **const factory_slot = (void **)(uintptr_t)0x005a01f0u;
    uint8_t *bytes = (uint8_t *)slot;
    void *state = *state_slot;
    void *factory = *factory_slot;
    uint32_t packed;
    uint32_t descriptor_word;
    void *descriptor;
    if (state == NULL) {
        state = Engine_LazySingletonGetter_00422CC8();
        *state_slot = state;
    }
    state = (uint8_t *)state + 0x3f04u;
    bytes[8] = *(uint8_t *)state;
    bytes[9] = *((uint8_t *)state + 1u);
    *(uint32_t *)(bytes + 0x0cu) = *(uint32_t *)((uint8_t *)state + 8u);
    *(uint32_t *)(bytes + 0x10u) = *(uint32_t *)((uint8_t *)state + 4u);
    if (factory == NULL) {
        factory = ResourceFactory_Create_004C5938();
        *factory_slot = factory;
    }
    packed = ResourceFactory_ConfigureAndSubmit_005B95F0(
        factory, (int)(signed char)bytes[8], (int)(signed char)bytes[9],
        *(uint32_t *)(bytes + 0x0cu), *(uint32_t *)(bytes + 0x10u),
        (int)(int16_t)id);
    descriptor_word = ResourceFactory_NextBindResource_005B949C(factory);
    descriptor = Engine_ResourceDescriptorFind_004B2134(
        packed, descriptor_word);
    if (descriptor != NULL) {
        uint32_t table_entry = Engine_ResourceTypeTableEntry_00533BC8(4u);
        if (Engine_ResourceDescriptorMatches_00543ED4(
                4u, table_entry, descriptor) != 0) {
            uint32_t flags = table_entry | 0x02000000u;
            Engine_ResourceDescriptorRelink_0054E4D8(&descriptor, flags);
            Engine_ResourceDescriptorSubmit_00543054(
                4u, table_entry, descriptor);
            Engine_ResourceDescriptorRelease_005450DC(descriptor);
        }
    }
    packed = ResourceFactory_ConfigureAndSubmit_005B95F0(
        factory, (int)(signed char)bytes[8], (int)(signed char)bytes[9],
        *(uint32_t *)(bytes + 0x0cu), *(uint32_t *)(bytes + 0x10u),
        (int)(int16_t)id);
    for (unsigned variant = 0; variant != 0x0bu; ++variant) {
        if (factory == NULL) {
            factory = ResourceFactory_Create_004C5938();
            *factory_slot = factory;
        }
        descriptor_word = ResourceFactory_GetVariant_0057F6A0(
            factory, variant);
        descriptor = Engine_ResourceDescriptorFind_004B2134(
            packed, descriptor_word);
        if (descriptor != NULL) {
            uint32_t table_entry = Engine_ResourceTypeTableEntry_00533BC8(4u);
            if (Engine_ResourceDescriptorMatches_00543ED4(
                    4u, table_entry, descriptor) != 0) {
                uint32_t flags = table_entry | 0x02000000u;
                Engine_ResourceDescriptorPrepare_0054E56C(&descriptor, flags);
                Engine_ResourceDescriptorFinalize_0054E758(&descriptor, flags);
                Engine_ResourceDescriptorSubmit_00543054(
                    4u, table_entry, descriptor);
                Engine_ResourceDescriptorRelease_005450DC(descriptor);
            }
        }
    }
    *(int *)(bytes + 4u) = id;
    return 1;
}
__attribute__((noinline)) int Engine_ResourceRegistryScanOrCreate_005926B0(void *registry, int id)
{
    uint8_t *slots = (uint8_t *)registry + 0x80u;
    int has_empty = 0;
    for (unsigned index = 0; index != 8u; ++index) {
        int slot_id = *(int *)(slots + index * 0x14u + 4u);
        if (slot_id == id)
            return 1;
        if (slot_id == -1)
            has_empty = 1;
    }
    if (!has_empty) {
        for (unsigned index = 0; index != 8u; ++index) {
            if (Engine_ResourceRegistrySlotRefresh_005A01F4(
                    slots + index * 0x14u) != 0)
                break;
        }
    }
    for (unsigned index = 0; index != 8u; ++index) {
        uint8_t *slot = slots + index * 0x14u;
        if (*(int *)(slot + 4u) == -1) {
            Engine_ResourceRegistrySlotInitialize_0059FFF0(slot, id);
            return 1;
        }
    }
    return 0;
}
__attribute__((noinline)) void *Engine_SignedIdPayloadLookup_0058A5E0(const int16_t *id_slot)
{
    static void **const primary_slot = (void **)(uintptr_t)0x00d3dcb8u;
    static int32_t *const first_dynamic_id =
        (int32_t *)(uintptr_t)0x0058b298u;
    static void **const secondary_slot = (void **)(uintptr_t)0x00d3e0b8u;
    static int32_t *const second_dynamic_id =
        (int32_t *)(uintptr_t)0x0058b2a0u;
    uint8_t *primary = (uint8_t *)*primary_slot;
    int id = (int)*id_slot;
    if (id == 0xcc)
        return *(void **)(primary + 0x2d8u);
    if (id < 0xcc) {
        if (id == -1)
            return *(void **)(primary + 0x128u);
        if (id == 0)
            return *(void **)(primary + 0x12cu);
        if (id == 1)
            return *(void **)(primary + 0x130u);
        if (id == 2)
            return *(void **)(primary + 0x134u);
        if (id >= 100 && id <= 203)
            return *(void **)(primary + 0x138u + (id - 100) * 4u);
        return NULL;
    }
    if (id > 0xcc) {
        if (id == 0xe7)
            return *(void **)(primary + 0x344u);
        if (id < 0xe7) {
            if (id >= 0xcd)
                return *(void **)(primary + 0x2dcu + (id - 0xcd) * 4u);
            return NULL;
        }
        if (id == 0xf5)
            return *(void **)(primary + 0x37cu);
        if (id < 0xf5) {
            if (id >= 0xe8)
                return *(void **)(primary + 0x348u + (id - 0xe8) * 4u);
            return NULL;
        }
        if (id == 0xfc)
            return *(void **)(primary + 0x398u);
        if (id == 0xfd)
            return *(void **)(primary + 0x39cu);
        if (id == 0xfe)
            return *(void **)(primary + 0x3a0u);
        if (id == 0xff)
            return *(void **)(primary + 0x3a4u);
        if (id == 0x100)
            return *(void **)(primary + 0x3a8u);
        if (id == 0x1f4)
            return *(void **)(primary + 0x3acu);
        if (id >= 0xf6 && id <= 0xfb)
            return *(void **)(primary + 0x380u + (id - 0xf6) * 4u);
    }
    {
        int delta = id - *first_dynamic_id;
        uint8_t *secondary = (uint8_t *)*secondary_slot;
        if (delta == 0x1b)
            return *(void **)(secondary + 0x1cu);
        if (delta >= 0 && delta < 0x1b) {
            if (delta >= 1 && delta <= 19)
                return *(void **)(primary + 0x3b4u + (delta - 1) * 8u);
            if (delta >= 20)
                return *(void **)(secondary + (delta - 20) * 4u);
            return NULL;
        }
        if (delta == 0x12c)
            return *(void **)(secondary + 0x54u);
        if (delta == 0x22)
            return *(void **)(secondary + 0x38u);
        if (delta >= 0x1c && delta <= 0x21)
            return *(void **)(secondary + 0x20u + (delta - 0x1c) * 4u);
        if (delta == 0x26)
            return *(void **)(secondary + 0x48u);
        if (delta >= 0x23 && delta <= 0x25)
            return *(void **)(secondary + 0x3cu + (delta - 0x23) * 4u);
        if (delta == 0xc7)
            return *(void **)(secondary + 0x4cu);
        if (delta == 0x12b)
            return *(void **)(secondary + 0x50u);
        if (delta > 0x12c) {
            int upper_delta = delta - *second_dynamic_id;
            if (upper_delta == 0)
                return *(void **)(secondary + 0x70u);
            if (upper_delta >= 1 && upper_delta <= 4)
                return *(void **)(secondary + 0x70u + upper_delta * 4u);
            if (upper_delta == 0x5c)
                return *(void **)(secondary + 0x84u);
            if (delta >= 0x12d && delta <= 0x132)
                return *(void **)(secondary + 0x58u + (delta - 0x12d) * 4u);
        }
    }
    return NULL;
}
struct StatusOrderedTreeNode {
    void *value;
    struct StatusOrderedTreeNode *parent;
    struct StatusOrderedTreeNode *left;
    struct StatusOrderedTreeNode *right;
    uint8_t active;
    uint8_t reserved[3];
    uint32_t key;
};
struct StatusOrderedTreeSearchFrame {
    struct StatusOrderedTreeNode *node;
    int8_t direction;
    uint8_t reserved[3];
};
typedef char kiu_sa_status_resource_batch_1[(offsetof(struct StatusOrderedTreeNode, key) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_resource_batch_2[(offsetof(struct StatusOrderedTreeSearchFrame, direction) == 4) ? 1 : -1] __attribute__((unused));
__attribute__((noinline)) void *Engine_LazyRegistryComponentGet_003FD5B0(void)
{
    static uint32_t **const guard_slot =
        (uint32_t **)(uintptr_t)0x003fd630u;
    static void **const component_slot =
        (void **)(uintptr_t)0x003fd634u;
    void *component;
    if ((**guard_slot & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(*guard_slot) != 0) {
        component = Engine_RegistryComponentInitialize_003AE1F4(
            *component_slot, 1u);
        *(void **)((uint8_t *)component + 0x00u) =
            *(void **)(uintptr_t)0x003fd638u;
        *(void **)((uint8_t *)component + 0x10u) =
            (uint8_t *)component + 0x10u;
        *(void **)((uint8_t *)component + 0x14u) =
            (uint8_t *)component + 0x10u;
        *(void **)((uint8_t *)component + 0x18u) =
            (uint8_t *)component + 0x10u;
        Engine_ForEachStrideCallback_00421EA4(
            (uint8_t *)component + 0x1cu,
            *(void **)(uintptr_t)0x003fd63cu, 0xcu, 0xfu);
    }
    return *component_slot;
}
__attribute__((noinline)) void *Engine_LazyRegistryComponentGet_003FD648(void)
{
    static uint32_t **const guard_slot =
        (uint32_t **)(uintptr_t)0x003fd6c8u;
    static void **const component_slot =
        (void **)(uintptr_t)0x003fd6ccu;
    void *component;
    if ((**guard_slot & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(*guard_slot) != 0) {
        component = Engine_RegistryComponentInitialize_003AE1F4(
            *component_slot, 2u);
        *(void **)((uint8_t *)component + 0x00u) =
            *(void **)(uintptr_t)0x003fd6d0u;
        *(void **)((uint8_t *)component + 0x10u) =
            (uint8_t *)component + 0x10u;
        *(void **)((uint8_t *)component + 0x14u) =
            (uint8_t *)component + 0x10u;
        *(void **)((uint8_t *)component + 0x18u) =
            (uint8_t *)component + 0x10u;
        Engine_ForEachStrideCallback_00421EA4(
            (uint8_t *)component + 0x1cu,
            *(void **)(uintptr_t)0x003fd6d4u, 0xcu, 0xdu);
    }
    return *component_slot;
}
__attribute__((noinline)) void *Engine_AllocatorSingleton_003AFA00(void)
{
    return *(void **)(uintptr_t)0x003afa08u;
}
__attribute__((noinline)) void Engine_BufferGrow_003FD738(void *buffer, unsigned request)
{
    uint8_t *bytes = (uint8_t *)buffer;
    uint32_t current = *(uint32_t *)(bytes + 0x04u);
    uint32_t limit = *(uint32_t *)(bytes + 0x0cu);
    uint32_t target = current + request;
    if (current < limit && target < limit)
        target = limit;
    if (*(uint32_t *)(bytes + 0x08u) == target) {
        *(uint8_t **)(bytes + 0x14u) =
            *(uint8_t **)(bytes + 0x10u) + request * 4u;
        return;
    }
    {
        void *allocator_handle = Engine_AllocatorSingleton_003AFA00();
        void *allocator = *(void **)allocator_handle;
        void **vtable = *(void ***)allocator;
        typedef void *(*Allocate)(void *, unsigned, unsigned);
        typedef void (*Release)(void *, void *);
        void *new_data = NULL;
        uint8_t *old_data = *(uint8_t **)(bytes + 0x10u);
        uint32_t copied = 0u;
        if (target != 0u)
            new_data = ((Allocate)vtable[0])(
                allocator, target * 4u, 0x20u);
        if (old_data != NULL) {
            uint8_t *old_end = *(uint8_t **)(bytes + 0x14u);
            uint32_t old_count = (uint32_t)(old_end - old_data) >> 2;
            copied = request < old_count ? request : old_count;
            for (uint32_t i = 0u; i < copied; ++i)
                ((uint32_t *)new_data)[i] = ((uint32_t *)old_data)[i];
            ((Release)vtable[1])(allocator, old_data);
            *(uint32_t *)(bytes + 0x14u) = 0u;
            *(uint32_t *)(bytes + 0x10u) = 0u;
            *(uint32_t *)(bytes + 0x08u) = 0u;
        }
        *(uint32_t *)(bytes + 0x08u) = target;
        *(void **)(bytes + 0x10u) = new_data;
        *(void **)(bytes + 0x14u) =
            (uint8_t *)new_data + copied * 4u;
    }
}
__attribute__((noinline)) void Engine_SegmentedKeySearch_003FD874(void *result,
                                        void *segment,
                                        const uint32_t *key)
{
    uint8_t *candidate = NULL;
    uint8_t *base = (uint8_t *)segment + 0x0cu;
    uint32_t count = *(uint32_t *)((uint8_t *)segment + 0x14u);
    void *match = NULL;
    if (count != 0u)
        candidate = *(uint8_t **)base;
    while (candidate != NULL) {
        if (*(uint32_t *)candidate == *key) {
            match = candidate;
            break;
        }
        base = (uint8_t *)segment + 0x0cu;
        count = *(uint32_t *)((uint8_t *)segment + 0x14u);
        if (count == 0u) {
            candidate = NULL;
        } else {
            uintptr_t begin = (uintptr_t)*(uint8_t **)base;
            uintptr_t current = (uintptr_t)candidate;
            uintptr_t end = begin + (uintptr_t)count * 8u;
            if (begin == 0u || current < begin || current > end - 8u)
                candidate = NULL;
            else
                candidate += 8u;
        }
    }
    *(void **)result = segment;
    *(void **)((uint8_t *)result + 4u) = match;
}
__attribute__((noinline)) void *Engine_BufferRangeInitialize_003FDC8C(void *result, void *base)
{
    *(void **)result = base;
    *(void **)((uint8_t *)result + 4u) = (uint8_t *)base + 0xc00u;
    *(uint32_t *)((uint8_t *)result + 8u) = 0u;
    return base;
}
__attribute__((noinline)) void *Engine_ForEachStrideReverse_003FDD00(void *base,
                                           void *callback,
                                           unsigned stride,
                                           unsigned count)
{
    uint8_t *current = (uint8_t *)base + stride * count;
    void (*visit)(void *) = (void (*)(void *))callback;
    while (count != 0u) {
        current -= stride;
        visit(current);
        --count;
    }
    return (uint8_t *)base - 8u;
}
void *Engine_CopyBytes_003FDD44(void *destination, const void *source,
                                unsigned length);
__attribute__((noinline)) void *Engine_CopyUtf16Units_003FDD3C(void *destination,
                                     const void *source,
                                     unsigned units)
{
    return Engine_CopyBytes_003FDD44(destination, source, units << 1);
}
__attribute__((noinline)) void *Engine_CopyBytes_003FDD44(void *destination,
                                const void *source,
                                unsigned length)
{
    Engine_CopyBytes_0044C108(destination, source, length);
    return destination;
}
__attribute__((noinline)) unsigned Engine_L2PacketValidate_00404908(const uint8_t *packet,
                                           uint32_t *decoded,
                                           uint16_t *sequence_out)
{
    uint32_t field0;
    uint32_t field1;
    uint32_t checksum;
    uint16_t expected;
    if (packet[0] != 0x4cu || packet[1] != 0x32u)
        return 0u;
    expected = (uint16_t)(((uint16_t)packet[2] << 8) | packet[3]);
    field1 = ((uint32_t)packet[8] << 24) |
             ((uint32_t)packet[9] << 16) |
             ((uint32_t)packet[10] << 8) |
             packet[7];
    field0 = ((uint32_t)packet[8] << 24) |
             ((uint32_t)packet[9] << 16) |
             ((uint32_t)packet[10] << 8) |
             packet[11];
    decoded[1] = field1;
    decoded[0] = field0;
    if ((field1 & 0x80000000u) != 0u)
        field1 &= 0x7fffffffu;
    checksum = (field1 >> 16) ^ 0xaaaau ^ (field1 & 0xffffu) ^
               (field0 >> 16) ^ (field0 & 0xffffu);
    *sequence_out = (uint16_t)((((uint16_t)packet[12] << 8) |
                                packet[13]) + 1u);
    return (unsigned)(checksum == expected);
}
__attribute__((noinline)) int Engine_StateGate_00353C6C(void)
{
    void *state = *(void **)(uintptr_t)0x00353c80u;
    return *(uint32_t *)((uint8_t *)state + 0x10u) != 0u;
}
__attribute__((noinline)) void *Engine_SharedState_0039FA98(void)
{
    void *state = *(void **)(uintptr_t)0x0039faa4u;
    return *(void **)((uint8_t *)state + 0x10u);
}
__attribute__((noinline)) void Engine_StateRecordConfigure_004052C4(void *record,
                                           uint32_t field20,
                                           uint32_t field1c,
                                           uint32_t field18,
                                           uint8_t enabled,
                                           float field28)
{
    void *shared_state;
    if (Engine_StateGate_00353C6C() != 0) {
        shared_state = Engine_SharedState_0039FA98();
        *(uint8_t *)((uint8_t *)shared_state + 0xc0u) = 1u;
        shared_state = Engine_SharedState_0039FA98();
        *(uint32_t *)((uint8_t *)shared_state + 0xc8u) = 10u;
    }
    *(uint8_t *)((uint8_t *)record + 0x13u) = enabled;
    *(uint32_t *)((uint8_t *)record + 0x24u) = 0u;
    *(float *)((uint8_t *)record + 0x28u) = field28;
    *(uint32_t *)((uint8_t *)record + 0x20u) = field20;
    *(uint32_t *)((uint8_t *)record + 0x18u) = field18;
    *(uint32_t *)((uint8_t *)record + 0x1cu) = field1c;
    *(uint8_t *)((uint8_t *)record + 0x10u) = 0u;
    *(void **)((uint8_t *)record + 0x0cu) =
        (void *)(uintptr_t)0x003e4ec0u;
    Engine_StateRecordUpdate_003E4EC0(record, 0);
}
__attribute__((noinline)) void Engine_ResourceTableInitialize_004057BC(void *table)
{
    uint8_t *bytes = (uint8_t *)table;
    uint8_t *global = *(uint8_t **)(uintptr_t)0x0040583cu;
    void *left;
    void *right;
    *(void **)(bytes + 0x40u) = global + 0x40u;
    *(void **)bytes = global;
    *(void **)(bytes + 0x20u) = global + 0x20u;
    Engine_ForEachStrideReverse_003FDD00(
        bytes + 0xbcu, *(void **)(uintptr_t)0x00405840u, 0x1e0u, 0x15u);
    left = *(void **)(bytes + 0x48u);
    right = *(void **)(bytes + 0x4cu);
    *(void **)((uint8_t *)right + 4u) = left;
    *(void **)((uint8_t *)left + 8u) = right;
    left = *(void **)(bytes + 0x54u);
    right = *(void **)(bytes + 0x58u);
    *(void **)((uint8_t *)right + 4u) = left;
    *(void **)((uint8_t *)left + 8u) = right;
    left = *(void **)(bytes + 0x28u);
    right = *(void **)(bytes + 0x2cu);
    *(void **)((uint8_t *)right + 4u) = left;
    *(void **)((uint8_t *)left + 8u) = right;
    left = *(void **)(bytes + 0x34u);
    right = *(void **)(bytes + 0x38u);
    *(void **)((uint8_t *)right + 4u) = left;
    *(void **)((uint8_t *)left + 8u) = right;
    Engine_ResourceTableFinalize_003D436C(table);
}
__attribute__((noinline)) void Engine_ResourceParameterCopy_00405844(void *destination,
                                           const void *source)
{
    uint8_t *out = (uint8_t *)destination;
    const uint8_t *in = (const uint8_t *)source;
    uint16_t size;
    float transformed;
    *(uint32_t *)(out + 0x9cu) = in[0x5cu];
    switch (in[0x5du]) {
    case 1u: size = 0x78u; break;
    case 2u: size = 0x10u; break;
    case 3u: size = 0x180u; break;
    case 4u: size = 0x80u; break;
    case 5u: size = 0x100u; break;
    case 6u: size = 0x200u; break;
    case 7u: size = 0x20u; break;
    case 8u: size = 0x800u; break;
    default: size = 0xfff9u; break;
    }
    *(uint16_t *)(out + 0xa2u) = size;
    *(uint32_t *)(out + 0x130u) = *(const uint32_t *)(in + 0x60u);
    *(uint32_t *)(out + 0x70u) = *(const uint32_t *)(in + 0x6cu);
    *(uint32_t *)(out + 0x90u) = *(const uint32_t *)(in + 0x9cu);
    *(uint32_t *)(out + 0x74u) = *(const uint32_t *)(in + 0x70u);
    *(uint32_t *)(out + 0x7cu) = *(const uint32_t *)(in + 0x74u);
    *(uint32_t *)(out + 0x80u) = *(const uint32_t *)(in + 0x78u);
    *(uint32_t *)(out + 0x78u) = *(const uint32_t *)(in + 0x7cu);
    *(uint32_t *)(out + 0x84u) = *(const uint32_t *)(in + 0x80u);
    *(uint32_t *)(out + 0x88u) = *(const uint32_t *)(in + 0x84u);
    transformed = __builtin_fabsf(TrigKernel_00474934(
        *(const float *)(in + 0x90u)));
    *(float *)(out + 0x8cu) = transformed;
    if (*(const float *)(in + 0xa0u) <=
        *(const float *)(uintptr_t)0x0040597cu) {
        out[0x34u] |= 8u;
    } else {
        *(float *)(out + 0xa4u) = *(const float *)(in + 0xa0u);
        out[0x34u] &= (uint8_t)~8u;
    }
    *(uint32_t *)(out + 0x94u) = *(const uint32_t *)(in + 0xb8u);
    *(uint32_t *)(out + 0x98u) = *(const uint32_t *)(in + 0xc4u);
    out[0x35u] &= (uint8_t)~2u;
}
__attribute__((noinline)) float StatusResource_ResolveCoordinatorVector_00405980(void *output,
                                                       void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    struct StatusOrderedTreeNode *sentinel =
        (struct StatusOrderedTreeNode *)(bytes + 0x1a8u);
    struct StatusOrderedTreeNode *current =
        *(struct StatusOrderedTreeNode **)(bytes + 0x1acu);
    struct StatusOrderedTreeNode *candidate = sentinel;
    uint32_t key = (uint32_t)(uintptr_t)StatusResource_CoordinatorKey_0045F02C();
    void *payload;
    float *vector;
    while (current->active != 0u) {
        if (current->key < key) {
            current = current->right;
        } else {
            candidate = current;
            current = current->left;
        }
    }
    if (candidate == sentinel || candidate->key <= key)
        candidate = sentinel;
    payload = candidate->value;
    if (payload == sentinel->value)
        payload = NULL;
    if (payload != NULL)
        payload = *(void **)((uint8_t *)payload + 0x1cu);
    if (payload != NULL) {
        vector = StatusSharedVector_Resolve(object);
        *(float *)((uint8_t *)output + 0xa8u) = vector[0];
        *(float *)((uint8_t *)output + 0xacu) = vector[1];
        *(float *)((uint8_t *)output + 0xb0u) = vector[2];
        if ((((uint8_t *)output)[0x34u] & 8u) != 0u)
            *(float *)((uint8_t *)output + 0xa4u) = vector[3];
    } else {
        *(float *)((uint8_t *)output + 0xa8u) = 0.0f;
        *(float *)((uint8_t *)output + 0xacu) = 0.0f;
        *(float *)((uint8_t *)output + 0xb0u) = 0.0f;
    }
    return *(float *)((uint8_t *)output + 0xa4u);
}
static __attribute__((noinline)) int
Engine_FlaggedResourceCheck_Impl_0051CEBC(void *object, uint32_t flags)
{
    if ((flags & 0x04000000u) != 0u)
        return Engine_FlaggedResourceLookup_0054AD70(
            (uint8_t *)object + 8u, flags) != NULL;
    if ((flags & 0x08000000u) != 0u)
        return Engine_FlaggedResourceLookup_0054ADC4(
            (uint8_t *)object + 8u, flags) != NULL;
    return 0;
}
__attribute__((noinline)) int Engine_FlaggedResourceCheck_004AD3D4(void *object, uint32_t flags)
{
    if (*(void **)((uint8_t *)object + 0x48u) == NULL)
        return 0;
    return Engine_FlaggedResourceCheck_Impl_0051CEBC(object, flags);
}
__attribute__((noinline)) int Engine_FlaggedResourceAvailability_004AD3E8(void *object,
                                                uint32_t flags)
{
    int32_t result;
    if (*(void **)((uint8_t *)object + 0x48u) == NULL)
        return 0;
    result = (int32_t)(uintptr_t)Engine_FlaggedResourceResolve_0051CE88(
        *(void **)((uint8_t *)object + 0x48u), flags);
    return (result >> 31) + 1;
}
__attribute__((noinline)) void *
Engine_FlaggedResourceResolve_0051CE88(void *table, uint32_t flags)
{
    void *entry;
    if ((flags & 0x04000000u) != 0u) {
        entry = Engine_FlaggedResourceLookup_0054AD70(
            (uint8_t *)table + 8u, flags);
    } else if ((flags & 0x08000000u) != 0u) {
        entry = Engine_FlaggedResourceLookup_0054ADC4(
            (uint8_t *)table + 8u, flags);
    } else {
        return NULL;
    }
    return *(void **)((uint8_t *)entry + 0x10u);
}
__attribute__((noinline)) void *Engine_FlaggedResourceLookup_0054AD70(void *table, uint32_t flags)
{
    uint32_t index = flags & 0xffffu;
    uint8_t *bytes = (uint8_t *)table;
    uint8_t *base;
    uint32_t *bits;
    if ((flags & 0x04000000u) == 0u)
        return NULL;
    base = *(uint8_t **)(bytes + 0x20u);
    if (base == NULL || index >= *(uint32_t *)(bytes + 0x28u))
        return NULL;
    bits = *(uint32_t **)(bytes + 0x24u);
    if (bits == NULL || (bits[index >> 5] & (1u << (index & 31u))) == 0u)
        return NULL;
    return base + index * 120u;
}
__attribute__((noinline)) void *Engine_FlaggedResourceLookup_0054ADC4(void *table, uint32_t flags)
{
    uint32_t index = flags & 0xffffu;
    uint8_t *bytes = (uint8_t *)table;
    uint8_t *base;
    uint32_t *bits;
    if ((flags & 0x08000000u) == 0u)
        return NULL;
    base = *(uint8_t **)(bytes + 0x48u);
    if (base == NULL || index >= *(uint32_t *)(bytes + 0x50u))
        return NULL;
    bits = *(uint32_t **)(bytes + 0x4cu);
    if (bits == NULL || (bits[index >> 5] & (1u << (index & 31u))) == 0u)
        return NULL;
    return base + index * 116u;
}
static void Engine_CopySevenFloats(float *destination, const float *source)
{
    float values[7];
    unsigned i;
    for (i = 0u; i < 7u; ++i)
        values[i] = source[i];
    for (i = 0u; i < 7u; ++i)
        destination[i] = values[i];
}
__attribute__((noinline)) void Engine_ResourceDispatchPrepare_004AD340(void *object,
                                             void *argument,
                                             uint32_t selector,
                                             void *destination)
{
    uint8_t *bytes = (uint8_t *)object;
    void *table = *(void **)(bytes + 0x48u);
    void *resolved_destination;
    uint32_t effective_selector;
    unsigned mode;
    unsigned object_flag;
    if (table == NULL)
        return;
    resolved_destination = destination;
    if (resolved_destination == NULL)
        resolved_destination = bytes + 0x5cu;
    effective_selector = selector;
    if (effective_selector == 0u)
        effective_selector = 0xffffu;
    if ((selector & 2u) != 0u)
        mode = 1u;
    else if ((selector & 4u) != 0u)
        mode = 2u;
    else if ((selector & 0x1000u) != 0u)
        mode = 3u;
    else if ((selector & 0x180u) != 0u)
        mode = 4u;
    else
        mode = ((selector & 0x200u) != 0u) ? 5u : 0u;
    object_flag = *(uint32_t *)(bytes + 0x90u) & 1u;
    Engine_ResourceDispatch_00512CE4(table, argument, resolved_destination,
                                     0u, mode, effective_selector,
                                     object_flag);
}
__attribute__((noinline)) int Engine_RecordModeDispatch_00545348(void *unused, void *record)
{
    (void)unused;
    Engine_RecordModeApply_005452E0((uint32_t *)record);
    return 1;
}
__attribute__((noinline)) int Engine_RecordModeDispatch_0054535C(void *unused, void *record)
{
    (void)unused;
    Engine_RecordModeApply_00545234((uint32_t *)record);
    return 1;
}
static void Engine_CopyEightWords(uint32_t *destination,
                                  const uint32_t *source)
{
    uint32_t values[8];
    unsigned i;
    for (i = 0u; i < 8u; ++i)
        values[i] = source[i];
    for (i = 0u; i < 8u; ++i)
        destination[i] = values[i];
}
__attribute__((noinline)) uint32_t Engine_RecordVectorPack_0054AD28(void *record, uint32_t *output)
{
    uint8_t *bytes = (uint8_t *)record;
    const uint32_t *source = *(const uint32_t **)(bytes + 0x18u);
    uint32_t tail = *(uint32_t *)(bytes + 0x14u);
    Engine_CopyEightWords(output, source + 3u);
    output[0] = *(uint32_t *)(bytes + 0x0cu);
    output[4] = tail;
    return tail;
}
__attribute__((noinline)) uint32_t Engine_RecordVectorPack_0054AD4C(void *record, uint32_t *output)
{
    uint8_t *bytes = (uint8_t *)record;
    const uint32_t *source = *(const uint32_t **)(bytes + 0x18u);
    uint32_t tail = *(uint32_t *)(bytes + 0x14u);
    Engine_CopyEightWords(output, source + 3u);
    output[0] = *(uint32_t *)(bytes + 0x0cu);
    output[3] = tail;
    return tail;
}
__attribute__((noinline)) void Engine_RecordVectorWalk_0054554C(void *descriptor,
                                      int count,
                                      const uint32_t *source,
                                      void *record_table)
{
    uint8_t *bytes = (uint8_t *)descriptor;
    uint8_t *destination = *(uint8_t **)(*(void **)bytes + 0x0cu);
    uint8_t *packed = *(uint8_t **)(*(void **)bytes + 8u);
    const uint8_t *items = (const uint8_t *)source;
    void ***records = (void ***)record_table;
    int i;
    for (i = 0; i < count; ++i) {
        const uint32_t *item = (const uint32_t *)(items + i * 8);
        *(uint32_t *)(destination + i * 4) = item[0];
        Engine_RecordVectorPack_0054AD28(
            *records[item[1]], (uint32_t *)(packed + i * 0x20));
    }
}
__attribute__((noinline)) void Engine_RecordVectorWalk_0054559C(void *descriptor,
                                      int count,
                                      const uint32_t *source,
                                      void *record_table)
{
    uint8_t *bytes = (uint8_t *)descriptor + 4u;
    uint8_t *destination = *(uint8_t **)(*(void **)bytes + 0x0cu);
    uint8_t *packed = *(uint8_t **)(*(void **)bytes + 8u);
    const uint8_t *items = (const uint8_t *)source;
    void ***records = (void ***)record_table;
    int i;
    for (i = 0; i < count; ++i) {
        const uint32_t *item = (const uint32_t *)(items + i * 8);
        *(uint32_t *)(destination + i * 4) = item[0];
        Engine_RecordVectorPack_0054AD4C(
            *records[item[1]], (uint32_t *)(packed + i * 0x20));
    }
}
__attribute__((noinline)) void *Engine_BoundsBitsetRefresh_0058BD88(void *state, unsigned index)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *table = *(uint8_t **)(state_bytes + 0x2cu);
    uint8_t *entry = table + index * 0x1cu;
    uint8_t *output = *(uint8_t **)(entry + 0x18u);
    uint32_t *bitset = *(uint32_t **)(entry + 0x0cu);
    uint8_t *record_index_table = *(uint8_t **)(state_bytes + 0x1cu);
    unsigned record_index = *(uint16_t *)(entry + 4u);
    unsigned word_count = *(uint16_t *)(state_bytes + 0x16u);
    int remaining = *(int16_t *)entry;
    unsigned output_words = 0u;
    unsigned word;
    for (word = 0u; word < word_count && remaining > 0; ++word) {
        uint32_t bits = bitset[word];
        unsigned bit = 0u;
        while (bits != 0u && remaining > 0) {
            if ((bits & 1u) != 0u) {
                unsigned ordinal = word * 32u + bit;
                uint8_t *record = *(uint8_t **)(
                    record_index_table + ordinal * 0x18u + 0x10u);
                *(float *)(output + output_words * 4u) =
                    *(float *)(record + 0x10u + record_index * 4u);
                *(uint32_t *)(output + output_words * 4u + 4u) =
                    ordinal * 2u;
                *(uint32_t *)(output + output_words * 4u + 8u) =
                    *(uint32_t *)(record + 0x1cu + record_index * 4u);
                *(uint32_t *)(output + output_words * 4u + 12u) =
                    ordinal * 2u + 1u;
                output_words += 4u;
                --remaining;
            }
            ++bit;
            bits >>= 1;
        }
    }
    if (output_words > 4u)
        Engine_StridedInsertionSort_004C626C(
            output, output_words / 2u, 8u,
            *(void **)(uintptr_t)0x0058bee0u);
    *(uint16_t *)(entry + 6u) = (uint16_t)(output_words / 2u);
    *(uint32_t *)(state_bytes + 0x10u) |= 1u << (index & 0xffu);
    return state;
}
__attribute__((noinline)) int Engine_RecordBoundsBitsetResolve_005459F8(void *state,
                                               float *bounds,
                                               unsigned direction,
                                               unsigned index)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *table = *(uint8_t **)(state_bytes + 0x2cu);
    uint8_t *entry = table + index * 0x1cu;
    uint8_t *pairs = *(uint8_t **)(entry + 0x18u);
    uint32_t *bitset;
    unsigned pair_count;
    unsigned bound_index;
    float low;
    float high;
    int result = 0;
    if (pairs == NULL)
        return 0;
    if ((*(uint32_t *)(state_bytes + 0x10u) &
         (1u << (index & 31u))) == 0u)
        Engine_BoundsBitsetRefresh_0058BD88(state, index);
    pair_count = *(uint16_t *)(entry + 6u);
    if (pair_count == 0u)
        return 0;
    bitset = *(uint32_t **)(entry + (direction == 0u ? 0x10u : 0x14u));
    MemoryZeroEnd_003DC5D0(
        bitset, (unsigned)*(uint16_t *)(state_bytes + 0x16u) << 2);
    bound_index = *(uint16_t *)(entry + 4u);
    low = bounds[bound_index];
    high = bounds[bound_index + 3u];
    if (*(float *)(pairs + (((pair_count + 1u) >> 1) * 8u)) <= low) {
        unsigned i;
        const uint8_t *pair = pairs;
        for (i = 0u; i < pair_count; ++i, pair += 8u) {
            float value = *(const float *)pair;
            uint32_t id = *(const uint32_t *)(pair + 4u);
            if (value > high)
                break;
            if ((id & 1u) == 0u) {
                ++result;
            } else if (value < low) {
                --result;
                id >>= 1;
                bitset[id >> 5] ^= 1u << (id & 31u);
            }
        }
    } else {
        unsigned i;
        const uint8_t *pair = pairs + (pair_count - 1u) * 8u;
        for (i = 0u; i < pair_count; ++i, pair -= 8u) {
            float value = *(const float *)pair;
            uint32_t id = *(const uint32_t *)(pair + 4u);
            if (value < low)
                break;
            if ((id & 1u) == 0u) {
                ++result;
            } else if (value > high) {
                --result;
                id >>= 1;
                bitset[id >> 5] ^= 1u << (id & 31u);
            }
        }
    }
    *(int16_t *)(entry + (direction == 0u ? 8u : 0xau)) =
        (int16_t)result;
    return result;
}
__attribute__((noinline)) void Engine_StridedInsertionSort_004C626C(void *base,
                                          unsigned count,
                                          unsigned stride,
                                          void *comparator)
{
    int (*compare)(const void *, const void *) =
        (int (*)(const void *, const void *))comparator;
    uint8_t *bytes = (uint8_t *)base;
    if (count == 0u || stride == 0u)
        return;
    if (count > 10u)
        Engine_StridedSortLargeCase_004C5F44(base, count, stride, comparator);
    {
        uint8_t *current = bytes;
        uint8_t *last = bytes + (count - 1u) * stride;
        while (current < last) {
            uint8_t *scan = current;
            unsigned offset;
            current += stride;
            while (scan >= bytes && compare(scan, current) > 0)
                scan -= stride;
            if ((((uintptr_t)bytes | (uintptr_t)stride) & 3u) == 0u) {
                for (offset = 0u; offset < stride; offset += 4u) {
                    uint8_t *source = current + offset - stride;
                    uint8_t *destination = source + stride;
                    if (source >= scan + stride)
                        *(uint32_t *)destination = *(uint32_t *)source;
                    else
                        *(uint32_t *)destination =
                            *(uint32_t *)(current + offset);
                }
            } else {
                for (offset = 0u; offset < stride; ++offset) {
                    uint8_t *source = current + offset - stride;
                    uint8_t *destination = source + stride;
                    if (source >= scan + stride)
                        *destination = *source;
                    else
                        *destination = *(current + offset);
                }
            }
        }
    }
}
__attribute__((noinline)) void Engine_FlaggedResourceVectorCopyBody_004EDC48(float *output,
                                                    void *table_object,
                                                    uint32_t flags)
{
    uint8_t *table = (uint8_t *)table_object;
    const float *source;
    void *entry;
    if ((flags & 0x04000000u) != 0u) {
        entry = Engine_FlaggedResourceLookup_0054AD70(table + 8u, flags);
        source = *(const float **)((uint8_t *)entry + 0x14u);
        if (source == NULL)
            source = *(const float **)(uintptr_t)0x0051ce68u;
    } else if ((flags & 0x08000000u) != 0u) {
        entry = Engine_FlaggedResourceLookup_0054ADC4(table + 8u, flags);
        source = *(const float **)((uint8_t *)entry + 0x14u);
        if (source == NULL)
            source = *(const float **)(uintptr_t)0x0051ce84u;
    } else {
        source = *(const float **)(uintptr_t)0x004edca8u;
    }
    Engine_CopySevenFloats(output, source);
}
__attribute__((noinline)) void Engine_FlaggedResourceVectorCopy_004AD694(float *output,
                                                void *object,
                                                uint32_t flags)
{
    uint8_t *table = *(uint8_t **)((uint8_t *)object + 0x48u);
    if (table != NULL) {
        Engine_FlaggedResourceVectorCopyBody_004EDC48(output, table, flags);
        return;
    }
    Engine_CopySevenFloats(output, (const float *)(uintptr_t)0x00DC261Cu);
}
__attribute__((noinline)) unsigned Engine_FlagBit28_005397F8(uint32_t flags)
{
    return (flags & 0x10000000u) >> 28;
}
__attribute__((noinline)) void Engine_SetIndexedByteAt13_00405344(void *base,
                                        unsigned index,
                                        uint8_t value)
{
    *((uint8_t *)base + index + 0x0du) = value;
}
__attribute__((noinline)) void Engine_SetIndexedByteAt7_00405350(void *base,
                                       unsigned index,
                                       uint8_t value)
{
    *((uint8_t *)base + index + 0x07u) = value;
}
__attribute__((noinline)) void *Engine_LazyFactoryRegistryGetter_0049BF28(void)
{
    static uint32_t **const guard_slot =
        (uint32_t **)(uintptr_t)0x0049bf70u;
    static void **const registry_slot =
        (void **)(uintptr_t)0x0049bf74u;
    if ((**guard_slot & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(*guard_slot) != 0)
        Engine_ResourceFactoryRegistryInitialize_003E9560(*registry_slot);
    return *registry_slot;
}
__attribute__((noinline)) void **Engine_LazyRegistryGetter_0049BF80(void)
{
    static uint32_t *const guard = (uint32_t *)(uintptr_t)0x00d6361cu;
    static void **const registry_slot = (void **)(uintptr_t)0x00d63620u;
    if ((*guard & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(guard) != 0)
        *registry_slot = NULL;
    return registry_slot;
}
__attribute__((noinline)) void *OrderedTree_LowerBoundByPointer_004C5D3C(void *tree_pointer,
                                                void *key_pointer)
{
    struct StatusOrderedTreeNode *tree =
        (struct StatusOrderedTreeNode *)((uint8_t *)tree_pointer + 4u);
    struct StatusOrderedTreeNode *candidate = tree;
    struct StatusOrderedTreeNode *current = tree->parent;
    uint32_t key = (uint32_t)(uintptr_t)key_pointer;
    while (current->active != 0u) {
        if (current->key < key) {
            current = current->right;
        } else {
            candidate = current;
            current = current->left;
        }
    }
    return candidate;
}
__attribute__((noinline)) void OrderedTree_CopySearchFrame_00445CF4(void *destination,
                                           const void *source)
{
    uint32_t pointer = *(const uint32_t *)source;
    uint8_t direction = *((const uint8_t *)source + 4u);
    *(uint32_t *)destination = pointer;
    *((uint8_t *)destination + 4u) = direction;
}
__attribute__((noinline)) void OrderedTree_Rotate_00223AD0(void *node_pointer, int direction,
                                  void *tree_root_pointer)
{
    struct StatusOrderedTreeNode *node =
        (struct StatusOrderedTreeNode *)node_pointer;
    struct StatusOrderedTreeNode *tree_root =
        (struct StatusOrderedTreeNode *)tree_root_pointer;
    struct StatusOrderedTreeNode *parent = node->parent;
    struct StatusOrderedTreeNode *child;
    struct StatusOrderedTreeNode *middle;
    if (direction != 0) {
        child = node->right;
        middle = child->left;
        if (parent->active == 0u) {
            child->parent = tree_root;
            tree_root->parent = child;
        } else {
            if (parent->left == node)
                parent->left = child;
            else
                parent->right = child;
            if (child->active != 0u)
                child->parent = parent;
        }
        node->right = middle;
        if (node->active != 0u)
            node->parent = child;
        child->left = node;
        if (middle->active != 0u)
            middle->parent = node;
        return;
    }
    child = node->left;
    middle = child->right;
    if (parent->active == 0u) {
        child->parent = tree_root;
        tree_root->parent = child;
    } else {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
        if (child->active != 0u)
            child->parent = parent;
    }
    node->left = middle;
    if (node->active != 0u)
        node->parent = child;
    child->right = node;
    if (middle->active != 0u)
        middle->parent = node;
}
__attribute__((noinline)) void OrderedTree_BalanceAfterInsert_0025E1E4(void *node_pointer,
                                              void *tree_root_pointer)
{
    struct StatusOrderedTreeNode *node =
        (struct StatusOrderedTreeNode *)node_pointer;
    struct StatusOrderedTreeNode *tree_root =
        (struct StatusOrderedTreeNode *)tree_root_pointer;
    for (;;) {
        struct StatusOrderedTreeNode *parent = node->parent;
        if (parent->active == 0u) {
            node->active = 2u;
        }
        if (parent->active == 0u || parent->active == 2u) {
            return;
        }
        struct StatusOrderedTreeNode *grandparent = parent->parent;
        struct StatusOrderedTreeNode *uncle =
            grandparent->left == parent ? grandparent->right
                                        : grandparent->left;
        if (uncle->active == 1u) {
            uncle->active = 2u;
            parent->active = 2u;
            node = grandparent;
            grandparent->active = 1u;
            continue;
        }
        int parent_is_left = grandparent->left == parent;
        int node_is_left = parent->left == node;
        if (parent_is_left == node_is_left) {
            OrderedTree_Rotate_00223AD0(parent, parent_is_left,
                                         tree_root);
            parent = node;
        }
        OrderedTree_Rotate_00223AD0(
            grandparent, grandparent->right == parent, tree_root);
        parent->active = 2u;
        grandparent->active = 1u;
        return;
    }
}
__attribute__((noinline)) void OrderedTree_BalanceAfterRemove_00189EB4(
    uint8_t removed_color, void *parent_pointer, void *node_pointer,
    int direction, void *tree_root_pointer)
{
    struct StatusOrderedTreeNode *parent =
        (struct StatusOrderedTreeNode *)parent_pointer;
    struct StatusOrderedTreeNode *node =
        (struct StatusOrderedTreeNode *)node_pointer;
    struct StatusOrderedTreeNode *tree_root =
        (struct StatusOrderedTreeNode *)tree_root_pointer;
    if (removed_color != 2u)
        return;
    for (;;) {
        struct StatusOrderedTreeNode *sibling =
            direction == 0 ? parent->left : parent->right;
        if (node->active == 1u) {
            node->active = 2u;
            return;
        }
        if (parent->active == 0u)
            return;
        if (sibling->active == 1u) {
            OrderedTree_Rotate_00223AD0(parent, direction, tree_root);
            parent->active = 1u;
            sibling->active = 2u;
            sibling = direction == 0 ? parent->left : parent->right;
        } else if (parent->active == 2u && sibling->left->active != 1u &&
                   sibling->right->active != 1u) {
            sibling->active = 1u;
            struct StatusOrderedTreeNode *grandparent = parent->parent;
            OrderedTree_BalanceAfterRemove_00189EB4(
                2u, grandparent, parent, grandparent->left == parent,
                tree_root);
            return;
        }
        if (parent->active != 1u || sibling->left->active == 1u ||
            sibling->right->active == 1u) {
            struct StatusOrderedTreeNode *near_child = sibling->left;
            struct StatusOrderedTreeNode *far_child = sibling->right;
            if (direction == 0) {
                near_child = sibling->right;
                far_child = sibling->left;
            }
            if (near_child->active == 1u && far_child->active != 1u) {
                OrderedTree_Rotate_00223AD0(sibling, direction ^ 1,
                                             tree_root);
                sibling->active = 1u;
                near_child->active = 2u;
                far_child = sibling;
                sibling = near_child;
            }
            OrderedTree_Rotate_00223AD0(parent, direction, tree_root);
            uint8_t color = parent->active;
            parent->active = sibling->active;
            sibling->active = color;
            far_child->active = 2u;
            return;
        }
        parent->active = 2u;
        sibling->active = 1u;
        return;
    }
}
__attribute__((noinline)) void OrderedTree_UnlinkNode_003D40E0(void *node_pointer,
                                      void *tree_root_pointer)
{
    struct StatusOrderedTreeNode *node =
        (struct StatusOrderedTreeNode *)node_pointer;
    struct StatusOrderedTreeNode *tree_root =
        (struct StatusOrderedTreeNode *)tree_root_pointer;
    struct StatusOrderedTreeNode *parent;
    struct StatusOrderedTreeNode *child;
    struct StatusOrderedTreeNode *replacement;
    uint8_t removed_color;
    int replacement_is_left;
    if (node->left->active == 0u) {
        parent = node->parent;
        child = node->right;
        removed_color = node->active;
        replacement_is_left = parent->left == node;
        if (parent->active == 0u) {
            parent->parent = child;
            child->parent = parent;
        } else {
            if (replacement_is_left)
                parent->left = child;
            else
                parent->right = child;
            if (child->active != 0u)
                child->parent = parent;
        }
    } else if (node->right->active == 0u) {
        parent = node->parent;
        child = node->left;
        removed_color = node->active;
        replacement_is_left = parent->left == node;
        if (parent->active == 0u) {
            parent->parent = child;
            child->parent = parent;
        } else {
            if (replacement_is_left)
                parent->left = child;
            else
                parent->right = child;
            if (child->active != 0u)
                child->parent = parent;
        }
    } else {
        replacement = node->left;
        do {
            struct StatusOrderedTreeNode *next = replacement->right;
            if (next->active == 0u)
                break;
            replacement = next;
        } while (1);
        parent = replacement->parent;
        child = replacement->left;
        removed_color = replacement->active;
        replacement_is_left = parent->left == replacement;
        if (parent == node)
            parent = replacement;
        if (child->active == 0u) {
            child->parent = tree_root;
            tree_root->parent = child;
        } else {
            if (replacement_is_left)
                replacement->parent->left = child;
            else
                replacement->parent->right = child;
            child->parent = replacement->parent;
        }
        struct StatusOrderedTreeNode *node_parent = node->parent;
        if (node_parent->active == 0u) {
            node_parent->parent = replacement;
            replacement->parent = node_parent;
        } else {
            if (node_parent->left == node)
                node_parent->left = replacement;
            else
                node_parent->right = replacement;
            if (replacement->active != 0u)
                replacement->parent = node_parent;
        }
        replacement->left = node->left;
        if (replacement->left->active != 0u)
            replacement->left->parent = replacement;
        replacement->right = node->right;
        if (replacement->right->active != 0u)
            replacement->right->parent = replacement;
        replacement->active = node->active;
    }
    OrderedTree_BalanceAfterRemove_00189EB4(
        removed_color, parent, child, replacement_is_left, tree_root);
    struct StatusOrderedTreeNode *minimum = tree_root->parent;
    while (minimum->active != 0u)
        minimum = minimum->left;
    tree_root->left = minimum;
    struct StatusOrderedTreeNode *maximum = tree_root->parent;
    while (maximum->active != 0u)
        maximum = maximum->right;
    tree_root->right = maximum;
    node->right = node;
    node->left = node;
    node->parent = node;
    node->active = 0u;
}
__attribute__((noinline)) void OrderedTree_LinkInsertedNode_0043AFF8(
    void *tree_frame_pointer, int direction, void *node_pointer,
    void *tree_root_pointer)
{
    struct StatusOrderedTreeNode *tree_frame =
        (struct StatusOrderedTreeNode *)tree_frame_pointer;
    struct StatusOrderedTreeNode *node =
        (struct StatusOrderedTreeNode *)node_pointer;
    struct StatusOrderedTreeNode *tree_root =
        (struct StatusOrderedTreeNode *)tree_root_pointer;
    node->right = tree_root;
    node->left = tree_root;
    node->parent = tree_root;
    node->active = 1u;
    if (tree_frame->active == 0u) {
        tree_frame->right = node;
        tree_frame->left = node;
        tree_frame->parent = node;
    } else if (direction == 0) {
        tree_frame->right = node;
        if (node->active != 0u)
            node->parent = tree_frame;
    } else {
        tree_frame->left = node;
        if (node->active != 0u)
            node->parent = tree_frame;
    }
    OrderedTree_BalanceAfterInsert_0025E1E4(node, tree_root);
    struct StatusOrderedTreeNode *minimum = tree_root->parent;
    while (minimum->left->active != 0u)
        minimum = minimum->left;
    tree_root->left = minimum;
    struct StatusOrderedTreeNode *maximum = tree_root->parent;
    while (maximum->right->active != 0u)
        maximum = maximum->right;
    tree_root->right = maximum;
}
__attribute__((noinline)) void *OrderedTree_InsertOrUpdate_0049B694(
    void *tree_pointer, void *node_pointer, uint32_t key)
{
    struct StatusOrderedTreeNode *tree =
        (struct StatusOrderedTreeNode *)((uint8_t *)tree_pointer + 4u);
    struct StatusOrderedTreeSearchFrame frame = {tree, 1, {0u, 0u, 0u}};
    struct StatusOrderedTreeNode *current = tree->parent;
    while (current->active != 0u) {
        struct StatusOrderedTreeSearchFrame next = {
            current, (int8_t)(current->key > key), {0u, 0u, 0u}};
        OrderedTree_CopySearchFrame_00445CF4(&frame, &next);
        current = next.direction != 0 ? current->left : current->right;
    }
    if (frame.direction == 0 || frame.node != tree->left) {
        struct StatusOrderedTreeNode *predecessor = frame.node;
        if (frame.direction != 0) {
            if (predecessor->active == 0u) {
                predecessor = predecessor->right;
            } else if (predecessor->left->active != 0u) {
                predecessor = predecessor->left;
                while (predecessor->right->active != 0u)
                    predecessor = predecessor->right;
            } else {
                struct StatusOrderedTreeNode *child = predecessor;
                predecessor = predecessor->parent;
                while (predecessor->active != 0u &&
                       predecessor->right != child) {
                    child = predecessor;
                    predecessor = predecessor->parent;
                }
            }
        }
        if (predecessor->key >= key)
            return predecessor;
    }
    struct StatusOrderedTreeNode *node =
        (struct StatusOrderedTreeNode *)node_pointer;
    if (node->active != 0u) {
        struct StatusOrderedTreeNode *old_sentinel = node;
        while (old_sentinel->active != 0u)
            old_sentinel = old_sentinel->parent;
        OrderedTree_UnlinkNode_003D40E0(node, old_sentinel);
    }
    node->key = key;
    OrderedTree_LinkInsertedNode_0043AFF8(
        frame.node, frame.direction, node, tree);
    return node;
}
__attribute__((noinline)) void *StatusResource_RuntimeComponentEnsure_00593BB0(void *object)
{
    static uint32_t **const outer_guard_slot =
        (uint32_t **)(uintptr_t)0x00593d40u;
    static void **const outer_link_slot =
        (void **)(uintptr_t)0x00593d44u;
    static uint32_t **const middle_guard_slot =
        (uint32_t **)(uintptr_t)0x00593d48u;
    static void **const middle_link_slot =
        (void **)(uintptr_t)0x00593d4cu;
    static uint32_t **const inner_guard_slot =
        (uint32_t **)(uintptr_t)0x00593d50u;
    static uint32_t **const inner_value_slot =
        (uint32_t **)(uintptr_t)0x00593d54u;
    void *first_factory = MessageWork_Factory_004D1524();
    void *second_factory = MessageWork_Factory_004D1524();
    void *node = OrderedTree_LowerBoundByPointer_004C5D3C(
        (uint8_t *)object + 0x1a4u, second_factory);
    void *sentinel = *(void **)((uint8_t *)object + 0x1a8u);
    void *payload = node != NULL ? *(void **)node : NULL;
    if (payload != sentinel)
        return payload;
    void *created = Engine_ResourceKeyResolve_0043A5E4(
        object, &first_factory);
    void *original = created;
    if (created == NULL)
        return NULL;
    if ((**outer_guard_slot & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(*outer_guard_slot) != 0) {
        if ((**middle_guard_slot & 1u) == 0u &&
            OnceGuard_TestAndSet_003B4FE4(*middle_guard_slot) != 0) {
            uint32_t *inner_value = *inner_value_slot;
            if ((**inner_guard_slot & 1u) == 0u &&
                OnceGuard_TestAndSet_003B4FE4(*inner_guard_slot) != 0)
                *inner_value = 0u;
            *middle_link_slot = inner_value;
        }
        *outer_link_slot = *middle_link_slot;
    }
    sentinel = *outer_link_slot;
    void *(*first_node)(void *) =
        (void *(*)(void *))(*(void ***)created)[0];
    node = first_node(created);
    while (node != NULL && node != sentinel)
        node = *(void **)node;
    if (node == sentinel) {
        OrderedTree_InsertOrUpdate_0049B694(
            (uint8_t *)object + 0x1a4u, (uint8_t *)created + 4u,
            (uint32_t)(uintptr_t)second_factory);
        return created;
    }
    created = NULL;
    if (original != NULL) {
        void (*release)(void *) =
            (void (*)(void *))(*(void ***)original)[0x0cu / 4u];
        release(original);
    }
    return NULL;
}
__attribute__((noinline)) void *StatusResource_CreateRuntimeObject(void *factory_context,
                                         const int16_t *parameter_id,
                                         void *source, void *selector_context,
                                         int special_mode)
{
    int id = (int)*parameter_id;
    uint8_t *selector;
    void *registry = StatusResource_RegistryGet();
    void *selected;
    void *object;
    void *cache;
    void *related;
    void *record;
    uint32_t runtime_payload[4] = {0u, 0u, 0u, 0x3f800000u};
    (void)Engine_ResourceRegistryScanOrCreate_005926B0(registry, id);
    selector = *(uint8_t **)((uint8_t *)selector_context + 4u);
    if (selector[0] == 0u)
        selected = StatusResource_LookupBasic(registry, id);
    else
        selected = StatusResource_LookupSelected(registry, id,
                                                  selector_context);
    if (selected == 0)
        return 0;
    object = StatusResource_CreateObject(
        factory_context, StatusResource_BuildFactoryPayload(parameter_id),
        selected, source);
    if (object == 0)
        return 0;
    cache = StatusResource_GetCacheDescriptor(object);
    {
        uint8_t *nested = *(uint8_t **)((uint8_t *)cache + 0x24u);
        nested = *(uint8_t **)(nested + 0xb0u);
        nested = *(uint8_t **)(nested + 8u);
        *(uint8_t *)(*(uint8_t **)(nested + 0x10cu) + 0x220u) = 1u;
    }
    *(uint8_t *)((uint8_t *)cache + 0x1cu) |= 1u;
    if ((id == 507 && special_mode == 0) || id == 508)
        StatusResource_SpecialRefresh(object, 0);
    StatusResource_MoveListNode(StatusResource_GetGlobalListSentinel(),
                                Engine_EmbeddedListNode_005506A8(object));
    StatusResource_RegisterComponent(StatusResource_GetComponentRegistry(),
                                     1u, object);
    *(int16_t *)((uint8_t *)cache + 0x20u) = (int16_t)id;
    *(uint8_t *)((uint8_t *)cache + 0x2cu) = 1u;
    *(uint8_t *)((uint8_t *)StatusResource_RuntimeComponentEnsure_00593BB0(object) +
                 0x1cu) = 1u;
    record = Engine_AllocateTaggedBlock(
        0x2cu, &StatusResource_RuntimeRecordTag,
        (void *)(uintptr_t)StatusResource_GetAllocatorContext(object));
    if (record != 0)
        record = StatusRuntimeRecord_Initialize(
            record, *(void **)((uint8_t *)cache + 0x24u), runtime_payload);
    if (HealthParameterIdIsRange500(id) != 0) {
        typedef void (*RuntimeRecordModeCallback)(void *, unsigned);
        RuntimeRecordModeCallback callback =
            (RuntimeRecordModeCallback)(*(void ***)record)[0x14u / 4u];
        callback(record, 0u);
    }
    related = StatusResource_GetRelatedStatusComponent(object);
    if (related != 0)
        *(uint32_t *)((uint8_t *)related + 0x88u) |= 0x30000u;
    StatusRuntimeRecord_SetActive_0055CC08(record, 1u);
    *(void **)((uint8_t *)cache + 0x38u) = record;
    return object;
}
__attribute__((noinline)) void StatusResourceUpdateOne(void *output_record, void *resource,
                                float hidden_delta)
{
    uint8_t *output = (uint8_t *)output_record;
    uint8_t *resource_bytes = (uint8_t *)resource;
    void *provider = 0;
    int transitioned;
    union {
        float value;
        uint32_t bits;
    } delta_bits = { hidden_delta };
    if (resource != (void *)(uintptr_t)0xffffff78u)
        provider = *(void **)(resource_bytes + 0x138u);
    *(uint8_t *)(resource_bytes + 0x298u) =
        (uint8_t)((*(uint8_t *)(resource_bytes + 0x298u) & 0xfcu) |
                  (*(uint8_t *)(output + 0x88u) & 1u) | 2u);
    transitioned = StatusResourceApplyMotionAndState(output_record,
                                                         resource);
    if (transitioned != 0)
        StatusResourceDispatch(*(void **)(output + 0x0cu), resource, 3u);
    StatusResourceValueHook(output_record, resource);
    if ((int32_t)delta_bits.bits > (int32_t)0x37800000u) {
        StatusResourceHealthBuildAndEvaluate(output_record, resource,
                                             hidden_delta);
        StatusResourceAngularEvaluator(output_record, resource);
        StatusResourceTransformRotate(output_record);
        {
            typedef float (*ProviderScalarCallback)(void *provider);
            ProviderScalarCallback callback =
                (ProviderScalarCallback)(*(void ***)provider)[0x24u / 4u];
            float callback_value = callback(provider);
            float previous = *(float *)(output + 0x10u);
            if (callback_value == 0.0f) {
                if (previous < 0.01f)
                    *(uint8_t *)(resource_bytes + 9u) |= 8u;
            } else {
                float scale = 1.0f;
                if (resource != (void *)(uintptr_t)0xffffff78u)
                    scale = *(float *)(resource_bytes + 0x11cu);
                callback_value = callback(provider) * scale * hidden_delta /
                                 *(float *)(resource_bytes + 0x8cu);
                callback_value += previous;
                *(float *)(output + 0x10u) = callback_value;
                if (callback_value * previous <= 0.0f) {
                    *(float *)(output + 0x10u) = 0.0f;
                    *(uint8_t *)(resource_bytes + 9u) |= 8u;
                }
            }
        }
    }
    StatusResourceMotionBuild(output_record, resource, hidden_delta);
    *(uint32_t *)(resource_bytes + 0x18u) = *(uint32_t *)(output + 0x10u);
}
__attribute__((noinline)) void StatusResourceBatchCommit(void *batch)
{
    uint8_t *base = (uint8_t *)batch;
    unsigned index;
    for (index = 0; index != 32u; ++index) {
        uint8_t *record = base + index * 0x3c0u;
        if (*(uint8_t *)(record + 0x3cu) == 0u)
            continue;
        if (*(uint8_t *)(record + 0x40u) != 3u)
            StatusResourceTransformCommit(record + 0x2d0u,
                                              record + 0x370u);
        *(uint32_t *)(record + 0x84u) = *(uint32_t *)(record + 0x2e8u);
        *(uint32_t *)(record + 0x88u) = *(uint32_t *)(record + 0x2ecu);
        *(uint32_t *)(record + 0x8cu) = *(uint32_t *)(record + 0x2f0u);
        *(uint32_t *)(record + 0xa4u) = *(uint32_t *)(record + 0x2f4u);
        *(uint32_t *)(record + 0xa8u) = *(uint32_t *)(record + 0x2f8u);
        *(uint32_t *)(record + 0xacu) = *(uint32_t *)(record + 0x2fcu);
        if (*(uint32_t *)(record + 0x3acu) != 0u &&
            *(uint32_t *)(record + 0x374u) != 0u) {
            float values[3];
            values[0] = *(float *)(record + 0x2e8u);
            values[1] = *(float *)(record + 0x2ecu);
            values[2] = *(float *)(record + 0x2f0u);
            StatusLinkedVectorWrite(
                record + 0x37cu, values,
                (uintptr_t)(*(uint32_t *)(record + 0x374u) + 0x50u));
            StatusLinkedScalarCommit(record + 0x37cu, values[0]);
            *(uint32_t *)(record + 0x70u) = *(uint32_t *)(record + 0xb0u);
            *(uint32_t *)(record + 0x38u) = *(uint32_t *)(record + 0x78u);
        }
    }
}
__attribute__((noinline)) int StatusResourceBatchUpdate(void *batch, void *unused_1, void *unused_2,
                                 void *frame_context)
{
    uint8_t *base = (uint8_t *)batch;
    uint8_t *frame = (uint8_t *)frame_context;
    int index;
    (void)unused_1;
    (void)unused_2;
    if (*(float *)(frame + 0x0cu) <= 0.0f ||
        *(uint8_t *)(base + 0x34u) == 0u)
        return 0;
    for (index = 0; index != 32; ++index) {
        uint8_t *record = base + (unsigned)index * 0x3c0u;
        uint8_t *auxiliary = base + 0x783cu;
        if (*(uint8_t *)(record + 0x3cu) == 0u ||
            *(uint8_t *)(record + 0x40u) == 3u ||
            (*(uint8_t *)(record + 0x38u) & 1u) == 0u)
            continue;
        StatusResourceUpdateOne(record + 0x1acu, record + 0x38u,
                                    *(float *)(frame + 0x0cu));
        StatusResourceAdvanceState(auxiliary, record + 0x38u,
                                      *(float *)(frame + 0x0cu));
    }
    StatusResourceBatchCommit(batch);
    return 0;
}
__attribute__((noinline)) uint32_t PackedHandle_Build(int kind, uint32_t index, int active)
{
    uint32_t handle = ((uint32_t)kind & 0xfu) << 28;
    handle |= (index & 0xfffu) << 16;
    if (active != 0)
        handle |= 1u;
    return handle;
}
__attribute__((noinline)) uint32_t IndexedTable_GetPayloadAndValue_00562C24(
    void *table, int index, uint32_t *out)
{
    uint8_t *entry;
    if (*(uint8_t *)table == 0u) {
        *out = 0u;
        return 0u;
    }
    entry = (uint8_t *)table + index * 8;
    *out = *(uint32_t *)(entry + 0x08u);
    return *(uint32_t *)(entry + 0x04u);
}
__attribute__((noinline)) uint32_t Engine_ComponentClassMaskAt_00556F30(void *component,
                                                uint32_t index)
{
    if (index >= 0x20u)
        return 0u;
    return *(uint32_t *)((uint8_t *)component + 0x1ed60u + index * 4u);
}
__attribute__((noinline)) void StateParameterRecord_Build(char *destination, int source, int selector,
                                uint32_t *payload, float scale, float scalar)
{
    static void **const registry_slot =
        (void **)(uintptr_t)0x0058638cu;
    uint8_t parameter_record[0xc4u];
    uint32_t output_record[4];
    *(float *)(destination + 8) = scalar;
    if (destination[0] == 0) {
        if (*(int32_t *)(destination + 4) == selector)
            return;
        {
            void *registry = *registry_slot;
            uint32_t event_id = *(uint32_t *)(destination + 0x0cu);
            uint32_t bucket_index = (event_id & 0xffffu) >> 8;
            uint32_t *bucket;
            if (registry == NULL) {
                registry = Engine_SharedObjectSingleton_004C5BA4();
                *registry_slot = registry;
            }
            bucket = (uint32_t *)((uint8_t *)registry + 0x324u +
                                  bucket_index * 0x0cu);
            if (*bucket == event_id) {
                Engine_EventRegistryBroadcast_004B2978(registry, &event_id);
                *(int32_t *)(destination + 4) = -1;
                *(uint32_t *)(destination + 0x0cu) = 0u;
            }
        }
    }
    EffectParameter_RecordInitialize(parameter_record);
    *(uint32_t *)(parameter_record + 0x40u) = payload[0];
    *(uint32_t *)(parameter_record + 0x44u) = payload[1];
    *(uint32_t *)(parameter_record + 0x48u) = payload[2];
    *(float *)(parameter_record + 0x70u) = scale;
    EffectParameter_RecordRandomize(parameter_record, source, 0u, 1);
    EffectParameter_BuildAndSubmit_005651D8(
        output_record, (uint32_t)selector, parameter_record, 0u, 0u, 0u);
    *(int32_t *)(destination + 4) = selector;
    *(uint32_t *)(destination + 0x0cu) = output_record[0];
}
__attribute__((noinline)) void StateParameterRecord_BuildWithSource(
    char *destination, void *source_object, int selector, uint32_t *payload,
    uint32_t *source_record, float scale, float scalar)
{
    static void **const registry_slot =
        (void **)(uintptr_t)0x00586650u;
    uint8_t parameter_record[0xc4u];
    uint32_t output_record[4];
    uint8_t *source = (uint8_t *)source_object;
    void *selected = *(void **)(source + 0x1e4u);
    *(float *)(destination + 8) = scalar;
    if (destination[0] == 0) {
        if (*(int32_t *)(destination + 4) == selector)
            return;
        {
            void *registry = *registry_slot;
            uint32_t event_id = *(uint32_t *)(destination + 0x0cu);
            uint32_t bucket_index = (event_id & 0xffffu) >> 8;
            uint32_t *bucket;
            if (registry == NULL) {
                registry = Engine_SharedObjectSingleton_004C5BA4();
                *registry_slot = registry;
            }
            bucket = (uint32_t *)((uint8_t *)registry + 0x324u +
                                  bucket_index * 0x0cu);
            if (*bucket == event_id) {
                Engine_EventRegistryBroadcast_004B2978(registry, &event_id);
                *(uint32_t *)(destination + 0x0cu) = 0u;
                *(int32_t *)(destination + 4) = -1;
            }
        }
    }
    if (selected == NULL) {
        uint32_t key = (uint32_t)(uintptr_t)
            Engine_LazySingletonGetter_00498828();
        void *sentinel = source + 0x1a8u;
        void *node = *(void **)(source + 0x1acu);
        void *candidate = sentinel;
        while (*(uint8_t *)((uint8_t *)node + 0x10u) != 0u) {
            uint32_t node_key = *(uint32_t *)((uint8_t *)node + 0x14u);
            if (node_key < key)
                node = *(void **)((uint8_t *)node + 8u + 4u);
            else {
                candidate = node;
                node = *(void **)((uint8_t *)node + 8u);
            }
        }
        if (candidate == sentinel ||
            *(uint32_t *)((uint8_t *)candidate + 0x14u) <= key)
            candidate = sentinel;
        selected = *(void **)candidate;
        if (selected == *(void **)sentinel)
            return;
        if (selected == NULL)
            return;
        *(void **)((uint8_t *)selected + 0x1cu) = source_object;
        *(void **)(source + 0x1e4u) = selected;
    }
    {
        uint32_t selected_selector =
            *(uint32_t *)((uint8_t *)selected + 0x24u);
        if (selected_selector == 0u)
            return;
        EffectParameter_RecordInitialize(parameter_record);
        *(uint32_t *)(parameter_record + 0x40u) = payload[0];
        *(uint32_t *)(parameter_record + 0x44u) = payload[1];
        *(uint32_t *)(parameter_record + 0x48u) = payload[2];
        *(float *)(parameter_record + 0x70u) = scale;
        ParameterString_Format_00542F74(
            parameter_record, (const char *)source_record[1], 0x20);
        EffectParameter_RecordRandomize(
            parameter_record, (int)(uintptr_t)source_object,
            selected_selector, 1);
        EffectParameter_BuildAndSubmit_005651D8(
            output_record, (uint32_t)selector, parameter_record, 0u, 0u, 1u);
        *(int32_t *)(destination + 4) = selector;
        *(uint32_t *)(destination + 0x0cu) = output_record[0];
    }
}
__attribute__((noinline)) int Engine_StatusCandidateLookup_0058E1D0(void *argument)
{
    static void **const registry_slot =
        (void **)(uintptr_t)0x0058e204u;
    void *registry = *registry_slot;
    uint32_t selector;
    if (registry == NULL) {
        registry = Engine_LazySingletonGetter_0049BED0();
        *registry_slot = registry;
    }
    selector = Engine_StatusCandidatePrepare_0057C8AC(registry, argument);
    return Engine_StatusCandidateSelect_0058F9B8(selector);
}
__attribute__((noinline)) int Engine_StatusCandidateSelect_0058F9B8(uint32_t selector)
{
    static void **const registry_slot =
        (void **)(uintptr_t)0x0058faa4u;
    void *registry;
    void *manager;
    uint32_t *entry;
    uint32_t count;
    if (selector == 0u || selector > 6u)
        return 0;
    registry = *registry_slot;
    if (registry == NULL) {
        registry = Engine_LazySingletonGetter_0049BED0();
        *registry_slot = registry;
    }
    if (Engine_CandidateGlobalGate_004B5394() == 0 ||
        Engine_CandidateRegistryReady_0054A8FC(registry) == 0)
        return 0;
    manager = Engine_CandidateTableGet_005A8990();
    count = *(uint32_t *)((uint8_t *)manager + 0x14u);
    entry = count != 0u
        ? *(uint32_t **)((uint8_t *)manager + 0x0cu) : NULL;
    while (entry != NULL) {
        uint32_t handle = *entry;
        if (Engine_CandidateHandleSelector_0054AE88(handle) == selector)
            return (int)handle;
        count = *(uint32_t *)((uint8_t *)manager + 0x14u);
        {
            uint32_t *base = count != 0u
                ? *(uint32_t **)((uint8_t *)manager + 0x0cu) : NULL;
            uint32_t *last = base != NULL ? base + count - 1u : NULL;
            if (base == NULL || entry < base || entry > last)
                entry = NULL;
            else if (entry < last)
                ++entry;
            else
                entry = NULL;
        }
    }
    return 0;
}
__attribute__((noinline)) void StateParameterRecord_ResetScalar(void *record)
{
    *(uint32_t *)((uint8_t *)record + 0x08u) = 0u;
}
__attribute__((noinline)) void Float_QuantizeUnitResidual(unsigned count, uint32_t *whole,
                                float *fraction, float value)
{
    float scaled;
    union {
        float value;
        uint32_t bits;
    } residual;
    *whole = 0u;
    *fraction = 0.0f;
    if (count > 1u) {
        scaled = value / (1.0f / (float)(count - 1u));
        Float_ForceIntConversion_0049A8B0();
        *whole = (uint32_t)scaled;
        residual.value = scaled - Libm_Floorf_0049A940(scaled);
        *fraction = residual.value;
        if ((int32_t)residual.bits >= (int32_t)0x37800000u)
            *fraction = 1.0f - residual.value;
    }
}
__attribute__((noinline)) float Float_QuantizeResidualGuard(float *base, unsigned count, float value)
{
    uint32_t whole = 0u;
    float fraction = 0.0f;
    if (count > 1u) {
        Float_QuantizeUnitResidual(count, &whole, &fraction, value);
        if (whole != 0u) {
            float current = base[whole];
            float previous = base[whole - 1u];
            return current - (current - previous) * fraction;
        }
    }
    return base[0];
}
__attribute__((noinline)) float Engine_ComputeClampedRatio_005729DC(float *state)
{
    float denominator = state[0x34];
    if (denominator > 0.0f) {
        float numerator = state[0x33];
        if (numerator > 1.0f)
            return numerator / denominator;
    }
    return 1.0f;
}
__attribute__((noinline)) void StatusTransition_StampTimestamp(float *record, float timestamp)
{
    union {
        float value;
        uint32_t bits;
    } stamp;
    uint32_t baseline = *(uint32_t *)(uintptr_t)0x00551054u;
    stamp.value = timestamp;
    *(uint32_t *)((uint8_t *)record + 0x24u) = stamp.bits;
    if (stamp.bits - baseline <= 0x180u)
        *(uint8_t *)((uint8_t *)record + 0x30u) = 1u;
}
__attribute__((noinline)) void StatusTransitionQueue_Schedule(void *object, int frame_count, int slot,
                                    float timestamp)
{
    uint8_t *base = (uint8_t *)object + 0xf0u;
    uint8_t *entry = base + (uint32_t)slot * 0x0cu + 0x550u;
    uint32_t first = (uint32_t)slot + 1u;
    uint32_t end;
    *(float *)(entry + 8u) = timestamp;
    entry[0] = 1u;
    if (frame_count < 1)
        entry[1] = 1u;
    else
        *(float *)(entry + 4u) = (float)frame_count * (1.0f / 60.0f);
    end = first + (first < 3u ? ((3u - first) & 1u) : 0u);
    while (first < end) {
        uint8_t *probe = base + first * 0x0cu + 0x550u;
        if (probe[0] != 0u)
            return;
        ++first;
    }
    while (end < 3u) {
        uint8_t *probe = base + end * 0x0cu + 0x500u;
        if (probe[0x50u] != 0u || probe[0x5cu] != 0u)
            return;
        end += 2u;
    }
    {
        void **cached = (void **)(uintptr_t)0x00557e5cu;
        float *record = (float *)*cached;
        if (record == NULL) {
            record = (float *)Engine_GlobalTimingState_Get_0054EF64();
            *cached = record;
        }
        StatusTransition_StampTimestamp(record, timestamp);
    }
}
__attribute__((noinline))
uint32_t OrderedTree_FindPayloadBySignedShort_0055D9CC(
    void *object, int16_t key)
{
    uint8_t *base = (uint8_t *)object;
    uint8_t *sentinel = base + 0x2cu;
    uint8_t *node = *(uint8_t **)(base + 0x30u);
    uint8_t *candidate = sentinel;
    while (*(uint8_t *)(node + 0x10u) != 0u) {
        uint8_t *current = node;
        if (*(int16_t *)(current + 0x12u) < key) {
            node = *(uint8_t **)(current + 0x0cu);
            candidate = sentinel;
        } else {
            node = *(uint8_t **)(current + 0x08u);
            candidate = current;
        }
    }
    if (candidate == sentinel || key < *(int16_t *)(candidate + 0x12u))
        candidate = sentinel;
    if (candidate == NULL)
        return 0u;
    if (*(uint32_t *)candidate == *(uint32_t *)sentinel)
        return 0u;
    return *(uint32_t *)candidate;
}
__attribute__((noinline)) void Engine_ResourceLookupBasic_005841FC(void *object, int16_t key)
{
    uint8_t *record = (uint8_t *)(uintptr_t)
        OrderedTree_FindPayloadBySignedShort_0055D9CC(object, key);
    uint32_t entry[2];
    if (record == NULL)
        return;
    uint32_t hash_input = *(const uint32_t *)(uintptr_t)0x00584248u;
    (void)ParameterString_Hash_00448668(&hash_input);
    entry[0] = *(uint32_t *)(record + 0x2cu);
    entry[1] = *(uint32_t *)(record + 0x30u);
    (void)OrderedTree_FindPayloadByNumericKey_0059394C(record + 0x58u,
                                                        entry);
}
__attribute__((noinline)) void *OrderedTree_FindPayloadByNumericKey_0059394C(void *object,
                                                    const uint32_t *entry)
{
    uint8_t *base = (uint8_t *)object;
    uint8_t *candidate = base + 4u;
    uint8_t *node = *(uint8_t **)(base + 8u);
    uint32_t key = *entry;
    void *payload;
    while (node != NULL && *(uint8_t *)(node + 0x10u) != 0u) {
        if (*(uint32_t *)(node + 0x14u) < key) {
            node = *(uint8_t **)(node + 0x0cu);
        } else {
            candidate = node;
            node = *(uint8_t **)(node + 0x08u);
        }
    }
    payload = candidate != NULL ? *(void **)candidate : NULL;
    if (*(uint8_t *)((uint8_t *)payload + 0x40u) != 0u)
        return payload;
    for (;;) {
        payload = candidate != NULL ? *(void **)candidate : NULL;
        if (payload == *(void **)(base + 4u))
            break;
        if (*(uint32_t *)((uint8_t *)payload + 0x14u) == key)
            break;
        candidate = (uint8_t *)OrderedTree_Successor_00464110(candidate);
    }
    return candidate != NULL ? *(void **)candidate : NULL;
}
__attribute__((noinline))
void *OrderedTree_FindPayloadBySignedShortAt14_0053CAFC(void *object,
                                                         int16_t key)
{
    uint8_t *base = (uint8_t *)object;
    uint8_t *sentinel = base + 0x14u;
    uint8_t *candidate = sentinel;
    uint8_t *node = *(uint8_t **)(base + 0x18u);
    void *payload;
    while (*(uint8_t *)(node + 0x10u) != 0u) {
        if (*(int16_t *)(node + 0x12u) < key) {
            node = *(uint8_t **)(node + 0x0cu);
        } else {
            candidate = node;
            node = *(uint8_t **)(node + 0x08u);
        }
    }
    if (candidate == sentinel || key < *(int16_t *)(candidate + 0x12u))
        candidate = sentinel;
    payload = *(void **)candidate;
    if (payload == *(void **)sentinel)
        return NULL;
    return payload;
}
__attribute__((noinline)) void *Engine_SignedShortPayloadOffsetBC_004AF950(void *object, int16_t key)
{
    void *payload = OrderedTree_FindPayloadBySignedShortAt14_0053CAFC(
        object, key);
    return payload != NULL ? (uint8_t *)payload + 0xbcu : NULL;
}
__attribute__((noinline)) void *Engine_ResourceKeyPairProbe_0055DA5C(void *object, int16_t key,
                                            int index)
{
    uint8_t *record = (uint8_t *)
        OrderedTree_FindPayloadBySignedShortAt14_0053CAFC(object, key);
    uint32_t pairs[6];
    uint32_t string_slot;
    if (record == NULL)
        return NULL;
    string_slot = *(const uint32_t *)(uintptr_t)0x0055daf8u;
    (void)ParameterString_Hash_00448668(&string_slot);
    pairs[0] = *(uint32_t *)(record + 0x14u);
    pairs[1] = *(uint32_t *)(record + 0x18u);
    string_slot = *(const uint32_t *)(uintptr_t)0x0055daf8u;
    (void)ParameterString_Hash_00448668(&string_slot);
    pairs[2] = *(uint32_t *)(record + 0x40u);
    pairs[3] = *(uint32_t *)(record + 0x44u);
    string_slot = *(const uint32_t *)(uintptr_t)0x0055daf8u;
    (void)ParameterString_Hash_00448668(&string_slot);
    pairs[4] = *(uint32_t *)(record + 0x6cu);
    pairs[5] = *(uint32_t *)(record + 0x70u);
    return OrderedTree_FindPayloadByNumericKey_0059394C(
        record + 0x98u, pairs + (unsigned)index * 2u);
}
struct ResourceCandidateString {
    char *data;
    uint32_t capacity;
    char *alias;
    uint32_t size;
    char bytes[44];
};
__attribute__((noinline)) void Engine_ResourceCandidateMatch_004C4E8C(
    void **output_pair, void *tree, const uint32_t *key_entry)
{
    struct ResourceCandidateString string;
    uint8_t *base = (uint8_t *)tree;
    uint8_t *sentinel = base + 4u;
    uint8_t *candidate = sentinel;
    uint8_t *initial;
    uint8_t *node = *(uint8_t **)(base + 8u);
    uint32_t key = *key_entry;
    void *payload;
    void *sentinel_payload;
    int string_empty;
    string.data = string.bytes;
    string.capacity = 0x20u;
    string.alias = string.bytes;
    string.size = 0x20u;
    string.bytes[0] = '\0';
    Engine_StringBuilderInit_003D400C(&string, key_entry[1]);
    while (*(uint8_t *)(node + 0x10u) != 0u) {
        if (*(uint32_t *)(node + 0x14u) < key) {
            node = *(uint8_t **)(node + 0x0cu);
        } else {
            candidate = node;
            node = *(uint8_t **)(node + 0x08u);
        }
    }
    initial = candidate;
    string_empty = string.alias[0] == '\0';
    sentinel_payload = *(void **)sentinel;
    for (;;) {
        payload = *(void **)candidate;
        if (payload == sentinel_payload) {
            void *initial_payload = *(void **)initial;
            if (initial_payload != sentinel_payload &&
                *(uint32_t *)((uint8_t *)initial_payload + 0x14u) == key) {
                output_pair[0] = sentinel;
                output_pair[1] = initial;
            } else {
                output_pair[0] = sentinel;
                output_pair[1] = sentinel;
            }
            return;
        }
        if (!string_empty) {
            void *candidate_string = *(void **)((uint8_t *)payload + 0x18u);
            if (*(char *)candidate_string != '\0' &&
                ParameterString_Equals_00425E6C(candidate_string,
                                                 string.alias) == 0u) {
                output_pair[0] = candidate;
                output_pair[1] = initial;
                return;
            }
        }
        if (*(uint32_t *)((uint8_t *)payload + 0x14u) == key) {
            output_pair[0] = candidate;
            output_pair[1] = initial;
            return;
        }
        candidate = (uint8_t *)OrderedTree_Successor_00464110(candidate);
    }
}
__attribute__((noinline)) void Engine_ResourceLookupSelected_0058424C(void *object, int16_t key,
                                            void *entry)
{
    uint8_t *record = (uint8_t *)(uintptr_t)
        OrderedTree_FindPayloadBySignedShort_0055D9CC(object, key);
    if (record != NULL)
        (void)OrderedTree_FindPayloadByNumericKey_0059394C(record + 0x58u,
                                                            (const uint32_t *)entry);
}
__attribute__((noinline)) void EffectEvent_DispatchTimed(uint32_t ticks, float hidden_value)
{
    static void **const dispatcher_slot = (void **)(uintptr_t)0x0058376cu;
    static const float seconds_per_tick = 0.0166666675359011f;
    void *dispatcher = *dispatcher_slot;
    if (dispatcher == NULL) {
        dispatcher = Engine_LazySingletonGetter_0049BE78();
        *dispatcher_slot = dispatcher;
    }
    Engine_EffectEventDispatch_004CF9C8(
        dispatcher, 3u, 0u, (float)ticks * seconds_per_tick, hidden_value);
}
struct BoundedIntSetView {
    int *values;
    int count;
    int capacity;
};
__attribute__((noinline)) int BoundedIntSet_Insert(struct BoundedIntSetView *set, int value)
{
    int count = set->count;
    int index;
    if (value < 0 || count >= set->capacity)
        return 0;
    for (index = 0; index < count; ++index) {
        if (set->values[index] == value)
            return 1;
    }
    set->values[count] = value;
    set->count = count + 1;
    return 1;
}
__attribute__((noinline)) int StatusRuntimeRecord_SourceLinkHook(void *source_links, void *record)
{
    uint8_t *links = (uint8_t *)source_links;
    void *owner;
    void *target;
    void *old_record;
    if (record == NULL)
        return 0;
    owner = *(void **)(links + 0x08u);
    target = owner != NULL ? *(void **)((uint8_t *)owner + 0x10cu) : NULL;
    if (target == NULL)
        return 0;
    *(void **)((uint8_t *)target + 0x224u) = record;
    old_record = *(void **)(links + 0x14u);
    if (old_record != record) {
        if (old_record != NULL) {
            void (**vtable)(void *) = *(void (***)(void *))old_record;
            vtable[1](old_record);
        }
        *(void **)(links + 0x14u) = record;
    }
    return 1;
}
extern void Engine_ObserverStateApply(void *node, uint32_t argument);
__attribute__((noinline)) void Engine_EventRegistryDispatchArg(void *registry, const uint32_t *event_id,
                                     uint32_t argument)
{
    uint32_t id = *event_id;
    uint8_t *base = (uint8_t *)registry;
    uint32_t bucket_index = (id >> 8) & 0xffu;
    uint32_t *bucket_id = (uint32_t *)(base + 0x324u +
                                       bucket_index * 0x0cu);
    uint32_t *sentinel;
    uint32_t *node;
    if (*bucket_id != id)
        return;
    sentinel = (uint32_t *)(base + ((id & 0xff00u) >> 4) + 4u);
    node = *(uint32_t **)(sentinel + 1);
    while (*sentinel != *node) {
        Engine_ObserverStateApply((void *)*node, argument);
        node = *(uint32_t **)(node + 1);
    }
}
__attribute__((noinline)) void Engine_OrderedDescriptorSelect_00475718(void *out, void *owner,
                                             uint32_t mode, uint32_t key)
{
    uint8_t *owner_bytes = (uint8_t *)owner;
    uint8_t *tree = *(uint8_t **)(*(uint8_t **)(owner_bytes + 0xb0u) + 0x08u);
    uint8_t *sentinel = tree + 0x20u;
    uint8_t *node = *(uint8_t **)(tree + 0x24u);
    uint8_t *candidate = sentinel;
    uint8_t *payload;
    (void)mode;
    while (*(uint8_t *)(node + 0x10u) != 0u) {
        if (*(int32_t *)(node + 0x14u) < (int32_t)key) {
            node = *(uint8_t **)(node + 0x0cu);
        } else {
            candidate = node;
            node = *(uint8_t **)(node + 0x08u);
        }
    }
    if (candidate != sentinel &&
        (int32_t)key >= *(int32_t *)(candidate + 0x14u)) {
        payload = *(uint8_t **)candidate;
        if (payload == *(uint8_t **)sentinel)
            payload = NULL;
    } else {
        payload = NULL;
    }
    *(void **)out = owner;
    *(void **)((uint8_t *)out + 0x04u) = payload;
    *(uint32_t *)((uint8_t *)out + 0x08u) = key;
}
__attribute__((noinline)) void InfoTarget_SelectRecordAtKey_00475704(void *out, void *state)
{
    uint8_t *state_bytes = (uint8_t *)state;
    void *owner = *(void **)(*(void **)(state_bytes + 0x04u) + 0x34u);
    Engine_OrderedDescriptorSelect_00475718(out, owner, 0u, 31u);
}
__attribute__((noinline)) void *OrderedTree_Successor_00464110(void *node)
{
    uint8_t *current = (uint8_t *)node;
    uint8_t *parent;
    uint8_t *child;
    if (*(uint8_t *)(current + 0x10u) == 0u)
        return *(void **)(current + 0x08u);
    child = *(uint8_t **)(current + 0x0cu);
    if (*(uint8_t *)(child + 0x10u) != 0u) {
        current = child;
        child = *(uint8_t **)(current + 0x08u);
        while (*(uint8_t *)(child + 0x10u) != 0u) {
            current = child;
            child = *(uint8_t **)(current + 0x08u);
        }
        return current;
    }
    parent = *(uint8_t **)(current + 0x04u);
    while (*(uint8_t *)(parent + 0x10u) != 0u &&
           *(uint8_t **)(parent + 0x08u) != current) {
        current = parent;
        parent = *(uint8_t **)(current + 0x04u);
    }
    return parent;
}
__attribute__((noinline)) uint32_t IntrusiveList_Count_00473DB8(void *list)
{
    uint8_t *sentinel = (uint8_t *)list;
    uint8_t *node = *(uint8_t **)(sentinel + 0x04u);
    uint32_t count = 0u;
    while (node != sentinel) {
        node = *(uint8_t **)(node + 0x04u);
        ++count;
    }
    return count;
}
__attribute__((noinline)) void *OrderedTree_LookupActive_00473C9C(void *object, const uint32_t *key_ptr)
{
    uint8_t *base = (uint8_t *)object;
    uint8_t *sentinel = base + 0xd4u;
    uint8_t *candidate = sentinel;
    uint8_t *node = *(uint8_t **)(base + 0xd8u);
    uint32_t key;
    void *payload;
    if (*(uint8_t *)(node + 0x10u) != 0u) {
        key = *key_ptr;
        do {
            if (*(uint32_t *)(node + 0x14u) < key) {
                node = *(uint8_t **)(node + 0x0cu);
            } else {
                candidate = node;
                node = *(uint8_t **)(node + 0x08u);
            }
        } while (*(uint8_t *)(node + 0x10u) != 0u);
    }
    payload = *(void **)candidate;
    if (*(uint8_t *)((uint8_t *)payload + 0x1cu) != 0u)
        return payload;
    key = *key_ptr;
    for (;;) {
        uint8_t *right;
        uint8_t *parent;
        uint8_t *child;
        payload = *(void **)candidate;
        if (*(uint32_t *)(*(void **)payload + 0x14u) == key)
            break;
        if (*(uint8_t *)(candidate + 0x10u) == 0u) {
            candidate = *(uint8_t **)(candidate + 0x08u);
        } else {
            right = *(uint8_t **)(candidate + 0x0cu);
            if (*(uint8_t *)(right + 0x10u) != 0u) {
                candidate = right;
                child = *(uint8_t **)(candidate + 0x08u);
                while (*(uint8_t *)(child + 0x10u) != 0u) {
                    candidate = child;
                    child = *(uint8_t **)(candidate + 0x08u);
                }
            } else {
                parent = *(uint8_t **)(candidate + 0x04u);
                while (*(uint8_t *)(parent + 0x10u) != 0u &&
                       *(uint8_t **)(parent + 0x08u) != candidate) {
                    candidate = parent;
                    parent = *(uint8_t **)(candidate + 0x04u);
                }
                candidate = parent;
            }
        }
        if (*(void **)candidate == *(void **)sentinel)
            break;
    }
    return *(void **)candidate;
}
__attribute__((noinline)) int GenerationRecord_MatchesOwner_004884A8(void *record, void *unused0,
                                           void *unused1, uint32_t enabled)
{
    uint8_t *entry = *(uint8_t **)record;
    (void)unused0;
    (void)unused1;
    (void)enabled;
    if (entry != NULL && *(uint8_t *)(entry + 0x04u) != 0u &&
        *(uint32_t *)(entry + 0x30u) == *(uint32_t *)((uint8_t *)record + 0x04u))
        return 1;
    return 0;
}
__attribute__((noinline)) void *Engine_IndexedTableEntry(int index)
{
    static void **const table_slot = (void **)(uintptr_t)0x00d635e8u;
    void *table = *table_slot;
    if (table == NULL) {
        table = Engine_ThresholdAuxAllocator_00475D70();
        *table_slot = table;
    }
    if (index < 0 || index >= 0xd1)
        return NULL;
    return *(void **)((uint8_t *)table + 0x193a8u + (uint32_t)index * 4u);
}
__attribute__((noinline)) void *Engine_StateEntryOffset_0042F42C(void *base, uint32_t mode,
                                       uint32_t index)
{
    return (uint8_t *)base + 0xbcu + mode * 0x1e0u + index * 0x5a0u;
}
__attribute__((noinline)) void *OrderedTree_CreateSentinel_00449C68(void)
{
    static uint32_t *const guard = (uint32_t *)(uintptr_t)0x00d63868u;
    static uint8_t *const sentinel = (uint8_t *)(uintptr_t)0x00f35640u;
    uint8_t *node;
    if ((*guard & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        node = sentinel + 0x04u;
        sentinel[0] = 1u;
        *(uint8_t **)(node + 0x00u) = node;
        *(uint8_t **)(node + 0x04u) = node;
        *(uint8_t **)(node + 0x08u) = node;
        *(uint8_t **)(node + 0x0cu) = node;
        *(uint8_t *)(node + 0x10u) = 0u;
        *(uint8_t **)(sentinel + 0x10u) = node;
    }
    return sentinel;
}
__attribute__((noinline)) float ParameterNode_InvokeCommit_0044A1A8(void *node)
{
    void *nested = *(void **)((uint8_t *)node + 0x04u);
    if (nested == NULL)
        return 0.0f;
    return ((float (*)(void *))(*(void ***)nested)[0x30u / 4u])(nested);
}
__attribute__((noinline)) int Engine_StateTableCompatibilitySelect_004218A0(void *table, uint32_t *handle)
{
    static void **const singleton_slot = (void **)(uintptr_t)0x00421978u;
    static const uint32_t *const generation_slot =
        (const uint32_t *)(uintptr_t)0x0042197cu;
    static const uint32_t *const handle_table_slot =
        (const uint32_t *)(uintptr_t)0x00421980u;
    void *singleton = *singleton_slot;
    uint8_t *records;
    const uint32_t *handle_table =
        (const uint32_t *)(uintptr_t)*handle_table_slot;
    uint32_t generation;
    int index;
    if (singleton == NULL) {
        singleton = Engine_LazySingletonGetter_004EEFBC();
        *singleton_slot = singleton;
    }
    records = *(uint8_t **)((uint8_t *)singleton + 0x80u);
    records = *(uint8_t **)(records + 0x14u);
    generation = *generation_slot;
    for (index = 0; index < 6; ++index) {
        int record_index = *(int *)((uint8_t *)table + 0x50u +
                                    (uint32_t)index * 4u);
        void *record;
        uint32_t packed;
        uint32_t resolved_record;
        uint32_t resolved_handle;
        if (record_index < 0)
            continue;
        record = Engine_IndexedRecordAccessor_0043704C(records, record_index);
        if (*(uint8_t *)((uint8_t *)record + 0x50u) == 0u)
            continue;
        packed = *(uint32_t *)((uint8_t *)record + 0x4cu);
        if (generation == (packed >> 9)) {
            resolved_record = 0u;
        } else {
            const uint32_t *entry = handle_table + (packed & 0x1ffu) * 2u;
            resolved_record = entry[1] == (packed >> 9) ? entry[0] : 0u;
        }
        packed = *handle;
        if (generation == (packed >> 9)) {
            resolved_handle = 0u;
        } else {
            const uint32_t *entry = handle_table + (packed & 0x1ffu) * 2u;
            resolved_handle = entry[1] == (packed >> 9) ? entry[0] : 0u;
        }
        if (resolved_record == resolved_handle)
            return index;
    }
    return -1;
}
__attribute__((noinline)) void *Engine_IndexedParameterLookup_004C30CC(void *value,
                                             uint32_t *handle)
{
    static void **const singleton_slot = (void **)(uintptr_t)0x00d6368cu;
    int index = Engine_StateTableCompatibilitySelect_004218A0(value, handle);
    int record_index;
    void *singleton;
    uint8_t *records;
    if (index < 0)
        return NULL;
    record_index = *(int *)((uint8_t *)value + 0x50u +
                            (uint32_t)index * 4u);
    if (record_index < 0)
        return NULL;
    singleton = *singleton_slot;
    if (singleton == NULL) {
        singleton = Engine_LazySingletonGetter_004EEFBC();
        *singleton_slot = singleton;
    }
    records = *(uint8_t **)((uint8_t *)singleton + 0x80u);
    records = *(uint8_t **)(records + 0x14u);
    return Engine_IndexedRecordAccessor_0043704C(records, record_index);
}
__attribute__((noinline)) void *OrderedTree_OwnerLookup_004C5554(void *object)
{
    void *node = OrderedTree_LowerBoundByPointer_004C5D3C(
        (uint8_t *)object + 0x1a4u, StatusAlternateParameterKey_004A4BBC());
    void *candidate = node != NULL ? *(void **)node : NULL;
    void *cached = *(void **)((uint8_t *)object + 0x1a8u);
    return candidate != cached ? candidate : NULL;
}
__attribute__((noinline)) void *Engine_ComponentRegistryEntryOffset_004D6028(void *table,
                                                   uint32_t packed_index)
{
    if (Engine_ComponentRegistryReady_0053A264() == 0)
        return NULL;
    return (uint8_t *)table + (packed_index & 0xfffu) * 0xb8u + 0x3cu;
}
__attribute__((noinline)) void *Engine_LazyCommandObjectFactory_004D1D1C(void)
{
    static uint32_t *const guard = (uint32_t *)(uintptr_t)0x00d3b494u;
    static void *const factory = (void *)(uintptr_t)0x00d6faacu;
    if ((*guard & 1u) == 0u &&
        OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
        void *allocated = Engine_CommandObjectFactory_001898B8(
            (void *)(uintptr_t)0x00c9e2f0u,
            (void *)(uintptr_t)0x00cff868u, 0x1e8u);
        *(uint32_t *)allocated = 0x00cff868u;
    }
    return factory;
}
__attribute__((noinline)) void *Engine_ComponentDescriptorResolve_00476534(void *descriptor)
{
    uint8_t *bytes;
    uint32_t kind;
    void *(*begin)(void *);
    void *node;
    if (descriptor == NULL)
        return NULL;
    bytes = (uint8_t *)descriptor;
    kind = *(uint32_t *)(bytes + 0x08u);
    if (kind == *(const uint32_t *)(uintptr_t)0x004767e8u) {
        uint32_t *guard = (uint32_t *)(uintptr_t)0x00d639c8u;
        void **slot = (void **)(uintptr_t)0x00d639ccu;
        void *sentinel = (void *)(uintptr_t)0x00d639ccu;
        if ((*guard & 1u) == 0u &&
            OnceGuard_TestAndSet_003B4FE4(guard) != 0)
            *slot = Engine_LazyCallbackTableGetter_004EE830();
        begin = (void *(*)(void *))(*(void ***)descriptor)[0];
        node = begin(descriptor);
        while (node != NULL) {
            if (node == sentinel)
                return bytes + 0xb4u;
            node = *(void **)node;
        }
    }
    if (kind == *(const uint32_t *)(uintptr_t)0x004767f4u) {
        uint32_t *guard = (uint32_t *)(uintptr_t)0x00d5f0a4u;
        void **slot = (void **)(uintptr_t)0x00d5f0a8u;
        void *sentinel = (void *)(uintptr_t)0x00d5f0a8u;
        if ((*guard & 1u) == 0u &&
            OnceGuard_TestAndSet_003B4FE4(guard) != 0) {
            uint32_t *nested_guard = (uint32_t *)(uintptr_t)0x00d612e4u;
            void **nested_slot = (void **)(uintptr_t)0x00d612e8u;
            if ((*nested_guard & 1u) == 0u &&
                OnceGuard_TestAndSet_003B4FE4(nested_guard) != 0)
                *nested_slot = Engine_LazyCallbackTableGetter_004EE830();
            *slot = nested_slot;
        }
        begin = (void *(*)(void *))(*(void ***)descriptor)[0];
        node = begin(descriptor);
        while (node != NULL) {
            if (node == sentinel)
                return bytes + 0x18u;
            node = *(void **)node;
        }
    }
    if (kind == *(const uint32_t *)(uintptr_t)0x00476808u) {
        uint32_t *guard = (uint32_t *)(uintptr_t)0x00d639b0u;
        void **slot = (void **)(uintptr_t)0x00d639b4u;
        void *sentinel = (void *)(uintptr_t)0x00d639b4u;
        if ((*guard & 1u) == 0u &&
            OnceGuard_TestAndSet_003B4FE4(guard) != 0)
            *slot = Engine_LazyCallbackTableGetter_004EE830();
        begin = (void *(*)(void *))(*(void ***)descriptor)[0];
        node = begin(descriptor);
        while (node != NULL) {
            if (node == sentinel)
                return bytes + 0x10u;
            node = *(void **)node;
        }
    }
    if (kind == *(const uint32_t *)(uintptr_t)0x00476814u) {
        uint32_t *guard = (uint32_t *)(uintptr_t)0x00d6006cu;
        void **slot = (void **)(uintptr_t)0x00d60070u;
        void *sentinel = (void *)(uintptr_t)0x00d60070u;
        if ((*guard & 1u) == 0u &&
            OnceGuard_TestAndSet_003B4FE4(guard) != 0)
            *slot = Engine_LazyCallbackTableGetter_004EE830();
        begin = (void *(*)(void *))(*(void ***)descriptor)[0];
        node = begin(descriptor);
        while (node != NULL) {
            if (node == sentinel)
                return bytes + 0x10u;
            node = *(void **)node;
        }
    }
    return NULL;
}
