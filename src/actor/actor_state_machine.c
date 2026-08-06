#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "actor_combat_views.h"
struct FrameContextView {
    uint8_t opaque_00[0x0c];
    float delta_time;
};
extern void StateControllerApplyPoseVector(void *controller,
                                               void *object,
                                               void *vector);
extern void EffectQueueAppend(void *queue,
                                 uint32_t first_value,
                                 uint32_t second_value,
                                 uint32_t flags,
                                 float duration);
extern void EffectQueueReset(void *queue, unsigned variant);
extern void StateParameterRecordUpdate(uint8_t *destination, int value,
                                           float accumulated_value);
extern int StatusVariantMode(void);
extern void *EngineLazySingletonGetter_0054EFA8(void);
extern void *Engine_LazyStrideRegistry_003B6D84(void);
extern uint8_t *ActorEligibilityFallbackRecord(void);
extern void *ActorEligibilitySingletonCache_00D63578;
extern uint32_t ResourceTableLookup(uint32_t *handle);
extern void *StatusOwnerLookupByHandle(void *registry, uint32_t handle);
extern void *EngineClassNibbleComponentSelect(void *engine,
                                                  void *object);
extern void *ActorEligibilityTreeKey(void);
extern void *StateVariantEntryKey(void);
extern int StateVariantKeyOnceGuard(const void *guard);
extern void *StateVariantKeyCreate(void *registry, void *name,
                                      uint32_t size);
extern void *StDashStartGetDescriptor(void);
extern void StateParameterRecordInit(uint32_t *record);
extern void *OrderedTreeLowerBoundByPointer(void *tree, void *key);
extern void *Engine_ActorVariantTreeKey(void);
extern void *ActorMovementEngineGet_004C59C0(void);
extern const float ActorZeroDirection_00DC24B4[3];
extern unsigned CachedComponent_FlagsContain(void *object,
                                                uint32_t mask);
extern unsigned StatusComponentHasBit00800000(void *object);
unsigned ClassifyDirectionSector(const float *direction,
                                    const float *input,
                                    const float *thresholds)
{
    float dot = direction[0] * input[0] +
                direction[1] * input[1] +
                direction[2] * input[2];
    if (thresholds[2] < dot)
        return 1u;
    if (thresholds[5] <= dot)
        return direction[2] * input[0] - direction[0] * input[2] > 0.0f
            ? 4u : 5u;
    return direction[2] * input[0] - direction[0] * input[2] > 0.0f
        ? 2u : 3u;
}
__attribute__((noinline)) void ActorThreatQuery_Build(void *actor, float *out)
{
    uint8_t *bytes = (uint8_t *)actor;
    uint8_t *entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
        bytes + 0x1a4u, Engine_ActorVariantTreeKey());
    uint8_t *upper = *(uint8_t **)(bytes + 0x1a8u);
    uint8_t *record = (entry != 0 && *(uint8_t **)entry != upper)
        ? *(uint8_t **)entry : 0;
    uint8_t *payload;
    float axis;
    float squared;
    float scale;
    if (record == 0 || record == upper)
        return;
    payload = *(uint8_t **)(record + 0x1cu);
    if (payload == 0)
        return;
    axis = *(float *)(payload + 0xaccu);
    squared = (axis + axis) * (axis + axis);
    out[0] = 0.0f;
    out[1] = -axis;
    out[2] = *(float *)(payload + 0xadcu);
    out[7] = *(float *)(payload + 0xac8u);
    if (squared > 0.0f) {
        scale = 1.0f / __builtin_sqrtf(squared);
        out[3] = 0.0f;
        out[4] = (axis + axis) * scale;
        out[5] = 0.0f;
        out[6] = squared * scale;
    } else {
        out[3] = ActorZeroDirection_00DC24B4[0];
        out[4] = ActorZeroDirection_00DC24B4[1];
        out[5] = ActorZeroDirection_00DC24B4[2];
        out[6] = 0.0f;
    }
}
extern void ActorState_TemporaryMessageInit_A(void *message);
extern void ActorState_TemporaryMessageInit_B(void *message);
extern void ActorState_TemporaryMessageInit_C(void *message);
extern void TemporaryRecord_ZeroInit(void *record, void *owner,
                                     unsigned type, unsigned value);
extern void ActorStateMachine_DispatchMessage(void *machine,
                                               void *message,
                                               void *context);
extern void ActorStateMachine_UpdateCore(void *machine, void *context,
                                          uint32_t limit, void *frame);
extern uint32_t *ActorHandleRecordInit_00421FA8(uint32_t *record,
                                                 unsigned mode);
extern void ActorThreatSearchVariant(void *machine, void *object,
                                     const float *query, int category,
                                     int destination_lane,
                                     float hidden_scale);
extern void *Engine_RelatedComponentCacheGetter_004C129C(void);
extern void *ResolveCachedComponent_1EC(void *object);
extern void *Engine_ComponentRegistryGetter_004C58E0(void);
extern void *Engine_ForEachStrideCallback(void *base, void *callback,
                                           unsigned stride, unsigned count);
extern uint32_t Engine_ActorSearchTierResolve(void *registry,
                                               unsigned selector,
                                               const void *query,
                                               unsigned limit,
                                               unsigned count,
                                               uint32_t *pairs,
                                               uint32_t lane_arg);
extern int ActorThreatCandidateSelect(void *context, uint32_t filtered,
                                      uint32_t *pairs, float *score,
                                      void *object);
extern void ActorThreatSearchPrepare(void *machine, void *object,
                                     const void *query, int category,
                                     uint32_t mode, uint32_t hidden_lo);
extern void *Engine_LazySingletonGetter_00520634(void);
extern void *Engine_ArraySlotSelect_004A3C84(void **table, int selector);
extern uint32_t ActorThreatCandidateBuild_0053985C(
    void *registry, unsigned selector, const void *query,
    const float *direction, unsigned limit, unsigned count,
    uint32_t *pairs, float hidden_scale);
extern void *ActorThreatRegistryCache_00D63590;
extern uint32_t ActorThreatTargetComponentLookup_005588F4(void *registry,
                                                            uint32_t selector);
extern void *ActorThreatTargetProfile_0054E208(void *resource);
extern void ActorThreatTargetApplyProfile_0051BAC8(void *profile,
                                                    void *record,
                                                    int mode);
extern int ActorThreatSpatialDispatch_00510A24(unsigned mode,
                                                void *machine,
                                                const void *record,
                                                unsigned flags,
                                                void *auxiliary);
extern void ActorBuildVectorRecord(float *out, const float *input);
extern void *ActorThreatSearch(void *machine, void *object,
                               const uint32_t *query, int category,
                               int arg5, int arg6, int arg7, int arg8);
struct ActorThreatSearchGlobalsView {
    uint32_t handle_mask;
    uint32_t prepare_mode;
    float initial_score;
    void **registry_slot;
};
extern struct ActorThreatSearchGlobalsView DAT_00518410;
__attribute__((noinline)) void *ActorThreatSearch(void *machine, void *object, const uint32_t *query,
                        int category, int arg5, int arg6, int arg7, int arg8)
{
    uint32_t pairs[20];
    uint32_t selected[2];
    float score = DAT_00518410.initial_score;
    void *registry;
    uint32_t filtered;
    int index;
    void *resource;
    selected[0] = DAT_00518410.handle_mask;
    (void)Engine_ForEachStrideCallback(
        pairs, (void *)(uintptr_t)0x005004d8u, 8u, 10u);
    ActorThreatSearchPrepare(machine, object, query, category,
                             DAT_00518410.prepare_mode, (uint32_t)arg6);
    registry = *DAT_00518410.registry_slot;
    if (registry == 0) {
        registry = Engine_ComponentRegistryGetter_004C58E0();
        *DAT_00518410.registry_slot = registry;
    }
    filtered = Engine_ActorSearchTierResolve(registry, 1u, query,
                                              10u, 10u, pairs,
                                              (uint32_t)arg7);
    index = ActorThreatCandidateSelect(machine, filtered, pairs, &score,
                                       object);
    if (index < 0) {
        filtered = Engine_ActorSearchTierResolve(registry, 3u, query,
                                                  10u, 10u, pairs,
                                                  (uint32_t)arg7);
        index = ActorThreatCandidateSelect(machine, filtered, pairs, &score,
                                           object);
        if (index < 0) {
            filtered = Engine_ActorSearchTierResolve(registry, 4u, query,
                                                      10u, 10u, pairs, 0u);
            index = ActorThreatCandidateSelect(machine, filtered, pairs,
                                               &score, object);
        }
    }
    if (index >= 0) {
        selected[0] = pairs[index * 2];
        selected[1] = pairs[index * 2 + 1];
    }
    filtered = Engine_ActorSearchTierResolve(registry, 0u, query,
                                              10u, 10u, pairs, 0u);
    index = ActorThreatCandidateSelect(machine, filtered, pairs, &score,
                                       object);
    if (index >= 0) {
        selected[0] = pairs[index * 2];
        selected[1] = pairs[index * 2 + 1];
    }
    resource = (void *)(uintptr_t)ResourceTableLookup(selected);
    if (arg8 == 0 && resource != 0) {
        uint32_t *destination = (uint32_t *)((uint8_t *)object +
                                             (arg5 == 0 ? 0x3cu : 0x44u));
        destination[0] = selected[0];
        destination[1] = selected[1];
    }
    return resource;
}
__attribute__((noinline)) void ActorRelativeTransformRecord_0054924C(void *machine, void *object,
                                           float *query, float hidden_scale)
{
    float *origin = (float *)Engine_RelatedComponentCacheGetter_004C129C();
    uint8_t *record = *(uint8_t **)((uint8_t *)object + 0x34u);
    float a = *(float *)((uint8_t *)machine + 0x44u);
    float b = *(float *)((uint8_t *)machine + 0x48u);
    float c = *(float *)((uint8_t *)machine + 0x4cu);
    float d = *(float *)((uint8_t *)machine + 0x50u);
    float x;
    float y;
    float z;
    float tx;
    float ty;
    float tz;
    float tw;
    (void)hidden_scale;
    if (record != 0 && *(uint8_t *)(record + 4u) != 0) {
        a = *(float *)(record + 0x1cu);
        b = *(float *)(record + 0x20u);
        c = *(float *)(record + 0x24u);
        d = *(float *)(record + 0x28u);
    }
    x = query[0];
    y = query[1];
    z = query[2];
    tx = (x * c + d * y) - a * z;
    ty = (x * d - c * y) + b * z;
    tz = (y * a - b * x) + d * z;
    tw = x * a + b * y + c * z;
    query[0] = origin[0] + (d * ty - c * tx) + b * tz + a * tw;
    query[1] = origin[1] + ((c * ty + d * tx) - a * tz) + b * tw;
    query[2] = origin[2] + (a * tx - b * ty) + d * tz + c * tw;
    query[3] = (b * c + a * d) * 2.0f;
    query[4] = (a * b - c * d) * 2.0f;
    query[5] = ((b * b + d * d) - a * a) - c * c;
}
__attribute__((noinline)) void ActorThreat_BuildRelativeDirection_004EC31C(
    float *output, void *object, void *component_owner,
    unsigned full_normalize)
{
    const float *origin = (const float *)
        Engine_RelatedComponentCacheGetter_004C129C();
    float x = origin[0];
    float y = origin[1];
    float z = origin[2];
    if (component_owner == 0)
        component_owner = ResolveCachedComponent_1EC(object);
    const uint8_t *component = component_owner == 0 ? 0 :
        *(const uint8_t **)((const uint8_t *)component_owner + 0x28u);
    if (component != 0) {
        const uint8_t *position = component +
                                  (full_normalize == 0 ? 0x74u : 0x54u);
        x = *(const float *)(position + 0u) - origin[0];
        y = *(const float *)(position + 4u) - origin[1];
        z = *(const float *)(position + 8u) - origin[2];
    } else {
        x = y = z = 0.0f;
    }
    const float length_squared = x * x + y * y + z * z;
    if (length_squared <= 0.0f) {
        const float a = *(const float *)((const uint8_t *)object + 0x44u);
        const float b = *(const float *)((const uint8_t *)object + 0x48u);
        const float c = *(const float *)((const uint8_t *)object + 0x4cu);
        const float d = *(const float *)((const uint8_t *)object + 0x50u);
        output[0] = (a * c + b * d) * 2.0f;
        output[1] = (b * c - a * d) * 2.0f;
        output[2] = ((c * c + d * d) - b * b) - a * a;
        return;
    }
    if (full_normalize == 0) {
        const float scale = 1.0f / __builtin_sqrtf(x * x + z * z);
        output[0] = x * scale;
        output[1] = 0.0f;
        output[2] = z * scale;
    } else {
        const float scale = 1.0f / __builtin_sqrtf(length_squared);
        output[0] = x * scale;
        output[1] = y * scale;
        output[2] = z * scale;
    }
}
static void actor_threat_rotate_point(float *output, const float *quaternion,
                                      const float *origin, const float *input)
{
    const float a = quaternion[0];
    const float b = quaternion[1];
    const float c = quaternion[2];
    const float d = quaternion[3];
    const float x = input[0];
    const float y = input[1];
    const float z = input[2];
    const float tx = (x * c + d * y) - a * z;
    const float ty = (x * d - c * y) + b * z;
    const float tz = (y * a - b * x) + d * z;
    const float tw = x * a + b * y + c * z;
    output[0] = origin[0] + (d * ty - c * tx) + b * tz + a * tw;
    output[1] = origin[1] + ((c * ty + d * tx) - a * tz) + b * tw;
    output[2] = origin[2] + (a * tx - b * ty) + d * tz + c * tw;
}
__attribute__((noinline)) void ActorThreatSearchPrepare(void *machine, void *object, const void *query,
                              int category, uint32_t correction_gate,
                              uint32_t lane_mode)
{
    float *record = (float *)(uintptr_t)query;
    const uint8_t *machine_bytes = (const uint8_t *)machine;
    const uint8_t *object_bytes = (const uint8_t *)object;
    const uint8_t *override = *(const uint8_t **)(object_bytes + 0x34u);
    float quaternion[4];
    float origin[3];
    float first[3];
    float advanced[3];
    float advanced_input[3];
    float delta[3];
    const uint32_t quaternion_offset = lane_mode == 0 ? 0x64u : 0x44u;
    quaternion[0] = *(const float *)(machine_bytes + quaternion_offset + 0x0u);
    quaternion[1] = *(const float *)(machine_bytes + quaternion_offset + 0x4u);
    quaternion[2] = *(const float *)(machine_bytes + quaternion_offset + 0x8u);
    quaternion[3] = *(const float *)(machine_bytes + quaternion_offset + 0xcu);
    if (override != 0 && override[4] != 0) {
        quaternion[0] = *(const float *)(override + 0x1cu);
        quaternion[1] = *(const float *)(override + 0x20u);
        quaternion[2] = *(const float *)(override + 0x24u);
        quaternion[3] = *(const float *)(override + 0x28u);
    }
    if (correction_gate != 0) {
        float correction[3];
        ActorThreat_BuildRelativeDirection_004EC31C(
            correction, machine, object, lane_mode);
        if (__builtin_fabsf(correction[2]) > 0.99999f) {
            const float *fallback = correction[2] > 0.0f
                ? (const float *)(uintptr_t)0x00dc2538u
                : (const float *)(uintptr_t)0x00dc2558u;
            quaternion[0] = fallback[0];
            quaternion[1] = fallback[1];
            quaternion[2] = fallback[2];
            quaternion[3] = fallback[3];
        } else {
            const float inverse = 1.0f /
                __builtin_sqrtf(2.0f + correction[2] * 2.0f);
            quaternion[0] = -correction[1] * inverse;
            quaternion[1] = correction[0] * inverse;
            quaternion[2] = (1.0f + correction[2]) * inverse;
            quaternion[3] = 0.0f;
        }
    }
    if (lane_mode != 0) {
        const float *shared_origin = (const float *)
            Engine_RelatedComponentCacheGetter_004C129C();
        origin[0] = shared_origin[0];
        origin[1] = shared_origin[1];
        origin[2] = shared_origin[2];
        if (category != 0) {
            void **table = *(void ***)
                (uintptr_t)0x00549210u;
            if (table == 0) {
                table = (void **)Engine_LazySingletonGetter_00520634();
                *(void **)(uintptr_t)0x00549210u = table;
            }
            void *entry = Engine_ArraySlotSelect_004A3C84(table, 0);
            if (entry != 0) {
                void (*update)(void) = *(void (**)(void))
                    (*(void ***)entry + 0x8u);
                update();
            }
        }
    } else {
        origin[0] = *(const float *)(machine_bytes + 0x74u);
        origin[1] = *(const float *)(machine_bytes + 0x78u);
        origin[2] = *(const float *)(machine_bytes + 0x7cu);
    }
    actor_threat_rotate_point(first, quaternion, origin, record);
    advanced_input[0] = record[0] + record[3] * record[6];
    advanced_input[1] = record[1] + record[4] * record[6];
    advanced_input[2] = record[2] + record[5] * record[6];
    actor_threat_rotate_point(advanced, quaternion, origin, advanced_input);
    record[0] = advanced[0];
    record[1] = advanced[1];
    record[2] = advanced[2];
    delta[0] = advanced[0] - first[0];
    delta[1] = advanced[1] - first[1];
    delta[2] = advanced[2] - first[2];
    const float length_squared = delta[0] * delta[0] +
                                delta[1] * delta[1] +
                                delta[2] * delta[2];
    if (length_squared > 0.0f) {
        const float inverse = 1.0f / __builtin_sqrtf(length_squared);
        record[3] = delta[0] * inverse;
        record[4] = delta[1] * inverse;
        record[5] = delta[2] * inverse;
        record[6] = length_squared * inverse;
    } else {
        record[3] = ActorZeroDirection_00DC24B4[0];
        record[4] = ActorZeroDirection_00DC24B4[1];
        record[5] = ActorZeroDirection_00DC24B4[2];
        record[6] = 0.0f;
    }
}
__attribute__((noinline)) void ActorThreatSearchVariant(void *machine, void *object, const float *query,
                              int category, int destination_lane,
                              float hidden_scale)
{
    uint32_t pairs[20];
    uint32_t selected[2];
    float direction[3];
    float threshold = 1000.0f;
    void *registry;
    uint32_t filtered;
    int index;
    void *resource;
    (void)category;
    selected[0] = 0xfffffe00u;
    (void)Engine_ForEachStrideCallback(
        pairs, (void *)(uintptr_t)0x005004d8u, 8u, 10u);
    ActorRelativeTransformRecord_0054924C(machine, object, (float *)query,
                                          hidden_scale);
    direction[0] = (*(const float *)((const uint8_t *)machine + 0x44u) *
                    *(const float *)((const uint8_t *)machine + 0x4cu)) +
                   (*(const float *)((const uint8_t *)machine + 0x48u) *
                    *(const float *)((const uint8_t *)machine + 0x50u));
    direction[1] = (*(const float *)((const uint8_t *)machine + 0x48u) *
                    *(const float *)((const uint8_t *)machine + 0x4cu)) -
                   (*(const float *)((const uint8_t *)machine + 0x44u) *
                    *(const float *)((const uint8_t *)machine + 0x50u));
    direction[2] = (((*(const float *)((const uint8_t *)machine + 0x4cu) *
                     *(const float *)((const uint8_t *)machine + 0x4cu)) +
                    (*(const float *)((const uint8_t *)machine + 0x50u) *
                     *(const float *)((const uint8_t *)machine + 0x50u))) -
                   (*(const float *)((const uint8_t *)machine + 0x48u) *
                    *(const float *)((const uint8_t *)machine + 0x48u))) -
                   (*(const float *)((const uint8_t *)machine + 0x44u) *
                    *(const float *)((const uint8_t *)machine + 0x44u));
    {
        uint8_t *record = *(uint8_t **)((uint8_t *)object + 0x34u);
        if (record != 0 && *(uint8_t *)(record + 4u) != 0) {
            float a = *(float *)(record + 0x24u);
            float b = *(float *)(record + 0x28u);
            float c = *(float *)(record + 0x1cu);
            float d = *(float *)(record + 0x20u);
            direction[0] = c * a + d * b;
            direction[1] = d * a - c * b;
            direction[2] = ((a * a + b * b) - d * d) - c * c;
        }
    }
    direction[0] *= 2.0f;
    direction[1] *= 2.0f;
    registry = ActorThreatRegistryCache_00D63590;
    if (registry == 0) {
        registry = Engine_ComponentRegistryGetter_004C58E0();
        ActorThreatRegistryCache_00D63590 = registry;
    }
    filtered = ActorThreatCandidateBuild_0053985C(
        registry, 1u, query, direction, 10u, 10u, pairs, hidden_scale);
    index = ActorThreatCandidateSelect(machine, filtered, pairs, &threshold,
                                       object);
    if (index < 0) {
        filtered = ActorThreatCandidateBuild_0053985C(
            registry, 3u, query, direction, 10u, 10u, pairs, hidden_scale);
        index = ActorThreatCandidateSelect(machine, filtered, pairs,
                                           &threshold, object);
        if (index < 0) {
            filtered = ActorThreatCandidateBuild_0053985C(
                registry, 4u, query, direction, 10u, 10u, pairs, hidden_scale);
            index = ActorThreatCandidateSelect(machine, filtered, pairs,
                                               &threshold, object);
        }
    }
    if (index >= 0) {
        selected[0] = pairs[index * 2];
        selected[1] = pairs[index * 2 + 1];
    }
    filtered = ActorThreatCandidateBuild_0053985C(
        registry, 0u, query, direction, 10u, 10u, pairs, hidden_scale);
    index = ActorThreatCandidateSelect(machine, filtered, pairs, &threshold,
                                       object);
    if (index >= 0) {
        selected[0] = pairs[index * 2];
        selected[1] = pairs[index * 2 + 1];
    }
    resource = (void *)(uintptr_t)ResourceTableLookup(selected);
    if (resource != 0) {
        uint32_t *destination = (uint32_t *)((uint8_t *)object +
                                             (destination_lane == 0
                                                  ? 0x3cu : 0x44u));
        destination[0] = selected[0];
        destination[1] = selected[1];
    }
}
struct ActorMessageWorkLink {
    void *message;
    struct ActorMessageWorkLink *next;
    struct ActorMessageWorkLink *previous;
};
static inline __attribute__((always_inline))
void ActorMessageWorkLink_Unlink(struct ActorMessageWorkLink *link)
{
    link->previous->next = link->next;
    link->next->previous = link->previous;
}
static inline __attribute__((always_inline))
void ActorMessageWorkLink_InsertBefore(struct ActorMessageWorkLink *position,
                                       struct ActorMessageWorkLink *link)
{
    position->previous->next = link;
    link->next = position;
    link->previous = position->previous;
    position->previous = link;
}
static inline __attribute__((always_inline))
int32_t ActorMessageWorkLink_Key(const struct ActorMessageWorkLink *link)
{
    return *(const int32_t *)((const uint8_t *)link->message + 0x20u);
}
static void ActorMessageWorkList_StableSort(
    struct ActorMessageWorkLink *sentinel)
{
    struct ActorMessageWorkLink *link = sentinel->next->next;
    while (link != sentinel) {
        struct ActorMessageWorkLink *next = link->next;
        struct ActorMessageWorkLink *position = link->previous;
        int32_t key = ActorMessageWorkLink_Key(link);
        if (ActorMessageWorkLink_Key(position) > key) {
            ActorMessageWorkLink_Unlink(link);
            do {
                position = position->previous;
            } while (position != sentinel &&
                     ActorMessageWorkLink_Key(position) > key);
            ActorMessageWorkLink_InsertBefore(position->next, link);
        }
        link = next;
    }
}
__attribute__((noinline)) void ActorStateMachine_UpdateCore(void *machine, void *range_start_value,
                                  uint32_t range_end_value, void *frame)
{
    typedef void *(*UpdateMessage)(void *, void *);
    typedef void (*ReleaseResult)(void *, int32_t);
    uint8_t *machine_bytes = (uint8_t *)machine;
    uint8_t *messages[32];
    uint32_t count = 0;
    uint8_t *outer = *(uint8_t **)(machine_bytes + 0x178u);
    uint8_t *outer_end = *(uint8_t **)(machine_bytes + 0x174u);
    int32_t range_start = (int32_t)(intptr_t)range_start_value;
    int32_t range_end = (int32_t)range_end_value;
    uint32_t i;
    float saved_delta;
    float delta_scale = 1.0f;
    while (*(uint8_t **)outer != outer_end) {
        uint8_t *owner = *(uint8_t **)outer;
        uint8_t *container = *(uint8_t **)(owner + 0x0cu);
        uint8_t *inner = *(uint8_t **)(container + 0x1cu);
        uint8_t *inner_end = *(uint8_t **)(container + 0x18u);
        while (*(uint8_t **)inner != inner_end) {
            uint8_t *message = *(uint8_t **)inner;
            int32_t key = *(int32_t *)(message + 0x20u);
            if (key >= range_start && key < range_end) {
                if (count < 32u)
                    messages[count] = message;
                ++count;
            }
            inner = *(uint8_t **)(inner + 0x04u);
        }
        outer = *(uint8_t **)(outer + 0x04u);
    }
    if (count == 0u)
        return;
    if (count > 32u) {
        struct ActorMessageWorkLink sentinel;
        sentinel.message = &sentinel;
        sentinel.next = &sentinel;
        sentinel.previous = &sentinel;
        outer = *(uint8_t **)(machine_bytes + 0x178u);
        outer_end = *(uint8_t **)(machine_bytes + 0x174u);
        while (*(uint8_t **)outer != outer_end) {
            uint8_t *owner = *(uint8_t **)outer;
            uint8_t *container = *(uint8_t **)(owner + 0x0cu);
            uint8_t *inner = *(uint8_t **)(container + 0x1cu);
            uint8_t *inner_end = *(uint8_t **)(container + 0x18u);
            while (*(uint8_t **)inner != inner_end) {
                uint8_t *message = *(uint8_t **)inner;
                int32_t key = *(int32_t *)(message + 0x20u);
                if (key >= range_start && key < range_end) {
                    struct ActorMessageWorkLink *link =
                        (struct ActorMessageWorkLink *)(message + 0x14u);
                    if (link != &sentinel) {
                        ActorMessageWorkLink_Unlink(link);
                        ActorMessageWorkLink_InsertBefore(&sentinel, link);
                    }
                }
                inner = *(uint8_t **)(inner + 0x04u);
            }
            outer = *(uint8_t **)(outer + 0x04u);
        }
        if (*(uint8_t *)(machine_bytes + 0x164u) == 0u)
            ActorMessageWorkList_StableSort(&sentinel);
        saved_delta = ((struct FrameContextView *)frame)->delta_time;
        outer = *(uint8_t **)(machine_bytes + 0x148u);
        outer_end = *(uint8_t **)(machine_bytes + 0x144u);
        while (*(uint8_t **)outer != outer_end) {
            delta_scale *= *(float *)(*(uint8_t **)outer + 0x10u);
            outer = *(uint8_t **)(outer + 0x04u);
        }
        ((struct FrameContextView *)frame)->delta_time =
            saved_delta * delta_scale;
        {
            struct ActorMessageWorkLink *link;
            for (link = sentinel.next; link != &sentinel;
                 link = link->next) {
                uint8_t *message = (uint8_t *)link->message;
                uintptr_t *vtable = *(uintptr_t **)message;
                void *result =
                    ((UpdateMessage)(uintptr_t)vtable[8])(message, machine);
                if (result == 0) {
                    ActorStateMachine_DispatchMessage(
                        machine, message, frame);
                } else if (((struct FrameContextView *)frame)->delta_time >
                           0.0f) {
                    uintptr_t *result_vtable = *(uintptr_t **)result;
                    ((ReleaseResult)(uintptr_t)result_vtable[7])(
                        result, *(int32_t *)(message + 0x20u));
                }
            }
        }
        ((struct FrameContextView *)frame)->delta_time = saved_delta;
        sentinel.previous->next = sentinel.next;
        sentinel.next->previous = sentinel.previous;
        sentinel.previous->next = sentinel.next;
        sentinel.next->previous = sentinel.previous;
        return;
    }
    saved_delta = ((struct FrameContextView *)frame)->delta_time;
    outer = *(uint8_t **)(machine_bytes + 0x148u);
    outer_end = *(uint8_t **)(machine_bytes + 0x144u);
    while (*(uint8_t **)outer != outer_end) {
        delta_scale *= *(float *)(*(uint8_t **)outer + 0x10u);
        outer = *(uint8_t **)(outer + 0x04u);
    }
    ((struct FrameContextView *)frame)->delta_time =
        saved_delta * delta_scale;
    if (*(uint8_t *)(machine_bytes + 0x164u) == 0u) {
        for (i = 4u; i < count; ++i) {
            uint8_t *message = messages[i];
            uint32_t position = i;
            while (position >= 4u &&
                   *(int32_t *)(messages[position - 4u] + 0x20u) >
                       *(int32_t *)(message + 0x20u)) {
                messages[position] = messages[position - 4u];
                position -= 4u;
            }
            messages[position] = message;
        }
        for (i = 1u; i < count; ++i) {
            uint8_t *message = messages[i];
            uint32_t position = i;
            while (position != 0u &&
                   *(int32_t *)(messages[position - 1u] + 0x20u) >
                       *(int32_t *)(message + 0x20u)) {
                messages[position] = messages[position - 1u];
                --position;
            }
            messages[position] = message;
        }
    }
    for (i = 0u; i < count; ++i) {
        uint8_t *message = messages[i];
        uintptr_t *vtable = *(uintptr_t **)message;
        void *result = ((UpdateMessage)(uintptr_t)vtable[8])(message, machine);
        if (result == 0) {
            ActorStateMachine_DispatchMessage(machine, message, frame);
        } else if (((struct FrameContextView *)frame)->delta_time > 0.0f) {
            uintptr_t *result_vtable = *(uintptr_t **)result;
            ((ReleaseResult)(uintptr_t)result_vtable[7])(
                result, *(int32_t *)(message + 0x20u));
        }
    }
    ((struct FrameContextView *)frame)->delta_time = saved_delta;
}
__attribute__((noinline)) void ActorStateMachine_UpdateWrapper_A(void *machine, void *unused,
                                       void *frame)
{
    uint8_t message[0x2c];
    (void)unused;
    if (*(uint8_t *)((uint8_t *)machine + 0x151u) != 0) {
        ActorState_TemporaryMessageInit_A(message);
        ActorStateMachine_DispatchMessage(machine, message, frame);
        uint8_t *first = *(uint8_t **)(message + 0x18u);
        uint8_t *first_link = *(uint8_t **)(message + 0x1cu);
        *(uint8_t **)(first_link + 4u) = first;
        *(uint8_t **)(first + 8u) = first_link;
        uint8_t *second = *(uint8_t **)(message + 0x0cu);
        uint8_t *second_link = *(uint8_t **)(message + 0x10u);
        *(uint8_t **)(second_link + 4u) = second;
        *(uint8_t **)(second + 8u) = second_link;
        return;
    }
    uint8_t *table = *(uint8_t **)(uintptr_t)0x009211b8u;
    ActorStateMachine_UpdateCore(machine, *(void **)(table + 0x18u),
                                 0x7fffffffu, frame);
}
__attribute__((noinline)) void ActorStateMachine_UpdateWrapper_B(void *machine, void *unused,
                                       void *frame)
{
    uint8_t message[0x2c];
    (void)unused;
    if (*(uint8_t *)((uint8_t *)machine + 0x151u) != 0) {
        ActorState_TemporaryMessageInit_B(message);
        ActorStateMachine_DispatchMessage(machine, message, frame);
        uint8_t *first = *(uint8_t **)(message + 0x18u);
        uint8_t *first_link = *(uint8_t **)(message + 0x1cu);
        *(uint8_t **)(first_link + 4u) = first;
        *(uint8_t **)(first + 8u) = first_link;
        uint8_t *second = *(uint8_t **)(message + 0x0cu);
        uint8_t *second_link = *(uint8_t **)(message + 0x10u);
        *(uint8_t **)(second_link + 4u) = second;
        *(uint8_t **)(second + 8u) = second_link;
        return;
    }
    uint8_t *config = *(uint8_t **)(uintptr_t)0x0092122cu;
    ActorStateMachine_UpdateCore(machine, *(void **)(config + 0x00u),
                                 *(uint32_t *)(config + 0x04u), frame);
}
__attribute__((noinline)) void ActorStateMachine_VisitStateChain_00921BD4(void *machine,
                                                void *context,
                                                const uint32_t *payload)
{
    typedef void (*MachineUpdateHook)(void *, void *, uint32_t *);
    typedef void (*StateVisitHook)(void *, void *, uint32_t *);
    uint32_t copied_payload[8];
    if (*(uint8_t *)((uint8_t *)machine + 0x3cu) == 0)
        return;
    memcpy(copied_payload, payload, sizeof(copied_payload));
    ((MachineUpdateHook)(uintptr_t)(*(uintptr_t **)(machine + 0x00u))[8u])(
        machine, context, copied_payload);
    if (*(uint8_t *)((uint8_t *)machine + 0x3du) == 0)
        return;
    uint8_t *link = *(uint8_t **)((uint8_t *)machine + 0x08u);
    uint8_t *sentinel = *(uint8_t **)((uint8_t *)machine + 0x04u);
    while (*(uint8_t **)link != sentinel) {
        uint8_t *state = *(uint8_t **)link;
        StateVisitHook visit =
            (StateVisitHook)(uintptr_t)(*(uintptr_t **)(state + 0x00u))[7u];
        visit(state, context, copied_payload);
        link = *(uint8_t **)(link + 0x04u);
    }
}
__attribute__((noinline)) void ActorStateMachine_UpdateAndDispatch_00920ED8(void *machine,
                                                  void *frame_context,
                                                  void *payload)
{
    uint8_t stack_record[0x30];
    uint8_t *message = stack_record;
    uint32_t *table = *(uint32_t **)(uintptr_t)0x00920f7cu;
    float saved_delta_time;
    TemporaryRecord_ZeroInit(stack_record + 0x2cu,
                             *(void **)((uint8_t *)machine + 0x1bcu),
                             5u, 0u);
    ActorStateMachine_UpdateCore(machine, (void *)(uintptr_t)table[0],
                                 table[1], frame_context);
    saved_delta_time = *(float *)((uint8_t *)frame_context + 0x0cu);
    ActorStateMachine_VisitStateChain_00921BD4(machine, frame_context,
                                                (const uint32_t *)payload);
    *(uint8_t *)((uint8_t *)machine + 0x3du) = 1u;
    *(float *)((uint8_t *)frame_context + 0x0cu) = saved_delta_time;
    ActorState_TemporaryMessageInit_C(message);
    ActorStateMachine_DispatchMessage(machine, message, frame_context);
    uint8_t *first = *(uint8_t **)(message + 0x18u);
    uint8_t *first_link = *(uint8_t **)(message + 0x1cu);
    *(uint8_t **)(first_link + 0x04u) = first;
    *(uint8_t **)(first + 0x08u) = first_link;
    uint8_t *second = *(uint8_t **)(message + 0x0cu);
    uint8_t *second_link = *(uint8_t **)(message + 0x10u);
    *(uint8_t **)(second_link + 0x04u) = second;
    *(uint8_t **)(second + 0x08u) = second_link;
}
__attribute__((noinline)) void ActorThreatTarget_Update(void *controller,
                                                         float hidden_scale)
{
    uint8_t *controller_bytes = (uint8_t *)controller;
    uint8_t *machine = *(uint8_t **)(controller_bytes + 0x30u);
    uint8_t *object = *(uint8_t **)(controller_bytes + 0x38u);
    uint32_t handle_record[2];
    float query[8];
    float position[3];
    float spatial_record[18] = {0};
    uint32_t auxiliary = 0;
    uint32_t selected;
    void *resource;
    selected = *ActorHandleRecordInit_00421FA8(handle_record, 0u);
    *(uint32_t *)(object + 0x3cu) = selected;
    uint32_t state_key = *(uint32_t *)
        (*(uint8_t **)(machine + 0x168u) + 8u);
    const uint32_t state_a = *(const uint32_t *)(uintptr_t)0x00c9b97cu;
    const uint32_t state_b = *(const uint32_t *)(uintptr_t)0x00c9b978u;
    const uint32_t state_c = *(const uint32_t *)(uintptr_t)0x00c9b988u;
    if (state_key == state_a || state_key == state_b || state_key == state_c) {
        ActorBuildVectorRecord(query,
                               (const float *)(*(uint8_t **)(controller_bytes +
                                                              0x34u) + 0xb18u));
        (void)ActorThreatSearch(machine, object, (const uint32_t *)query,
                                0, 0, 0, 0, 0);
    } else {
        ActorThreatQuery_Build(machine, query);
        (void)ActorThreatSearchVariant(machine, object, query, 0, 0,
                                       hidden_scale);
    }
    resource = (void *)(uintptr_t)ResourceTableLookup(
        (uint32_t *)(object + 0x3cu));
    if (resource == 0)
        return;
    (void)Engine_RelatedComponentCacheGetter_004C129C();
    position[0] = *(float *)((uint8_t *)resource + 0x54u);
    position[1] = *(float *)((uint8_t *)resource + 0x58u) + 3.0f;
    position[2] = *(float *)((uint8_t *)resource + 0x5cu);
    spatial_record[0] = position[0];
    spatial_record[1] = position[1];
    spatial_record[2] = position[2];
    if (*(int32_t *)(object + 0x40u) >= 0) {
        void *profile = ActorThreatTargetProfile_0054E208(resource);
        if (profile != 0)
            ActorThreatTargetApplyProfile_0051BAC8(
                profile, spatial_record, *(int32_t *)(object + 0x40u));
    }
    if (ActorThreatSpatialDispatch_00510A24(
            8u, machine, spatial_record, 0u, &auxiliary) != 0) {
        static void **component_registry_slot =
            (void **)(uintptr_t)0x00d63590u;
        void *registry = *component_registry_slot;
        uint32_t component_handle;
        if (registry == 0) {
            registry = Engine_ComponentRegistryGetter_004C58E0();
            *component_registry_slot = registry;
        }
        component_handle = ActorThreatTargetComponentLookup_005588F4(
            registry, auxiliary);
        if (ResourceTableLookup(&component_handle) !=
            (uint32_t)(uintptr_t)resource) {
            uint32_t replacement_record[2];
            *(uint32_t *)(object + 0x3cu) =
                *ActorHandleRecordInit_00421FA8(replacement_record, 0u);
        }
    }
}
__attribute__((noinline)) void ActorConditionPrepareTableLookup_0042121C(void *record,
                                                uint32_t *word_out,
                                                float *value_out)
{
    uint8_t *record_bytes = (uint8_t *)record;
    uint8_t *tree = *(uint8_t **)(record_bytes + 4u);
    uint8_t *sentinel = *(uint8_t **)tree;
    uint8_t *link = *(uint8_t **)(tree + 4u);
    uint8_t *selected = 0;
    float lower = 0.0f;
    float upper = 0.0f;
    const float position = *(float *)(record_bytes + 0x0cu);
    while (link != 0) {
        uint8_t *entry = *(uint8_t **)link;
        if (entry == sentinel)
            break;
        selected = entry;
        upper = lower + *(float *)(entry + 0x24u);
        if (position < upper)
            break;
        lower = upper;
        link = *(uint8_t **)(link + 4u);
    }
    if (selected == 0)
        return;
    const float fraction = (position - lower) / (upper - lower);
    const float remainder = 1.0f - fraction;
    if (*(uint8_t *)(selected + 0x28u) != 0) {
        float channel0 =
            (float)*(uint8_t *)(selected + 0x0cu) * remainder +
            (float)*(uint8_t *)(selected + 0x10u) * fraction;
        float channel1 =
            (float)*(uint8_t *)(selected + 0x0du) * remainder +
            (float)*(uint8_t *)(selected + 0x11u) * fraction;
        float channel2 =
            (float)*(uint8_t *)(selected + 0x0eu) * remainder +
            (float)*(uint8_t *)(selected + 0x12u) * fraction;
        float scalar = *(float *)(selected + 0x14u) * remainder +
                       *(float *)(selected + 0x18u) * fraction;
        if (channel0 < 0.0f) channel0 = 0.0f;
        if (channel1 < 0.0f) channel1 = 0.0f;
        if (channel2 < 0.0f) channel2 = 0.0f;
        if (channel0 > 255.0f) channel0 = 255.0f;
        if (channel1 > 255.0f) channel1 = 255.0f;
        if (channel2 > 255.0f) channel2 = 255.0f;
        *word_out = ((uint32_t)channel0 << 24) |
                    ((uint32_t)channel1 << 16) |
                    ((uint32_t)channel2 << 8) | 0xffu;
        *value_out = scalar;
        return;
    }
    *word_out = ((uint32_t)*(uint8_t *)(selected + 0x0cu) << 24) |
                ((uint32_t)*(uint8_t *)(selected + 0x0du) << 16) |
                ((uint32_t)*(uint8_t *)(selected + 0x0eu) << 8) | 0xffu;
    *value_out = *(float *)(selected + 0x14u);
}
__attribute__((noinline)) int ActorStateApplyPoseVector(struct HealthStatusComponent *actor,
                                 void *unused, void *state)
{
    (void)unused;
    StateControllerApplyPoseVector(actor->pose_state,
                                      actor->target,
                                      (uint8_t *)state + 0x2c);
    return 0;
}
void ActorBuildVectorRecord(float *out, const float *input)
{
    float dx = input[4] - input[1];
    float dy = input[5] - input[2];
    float dz = input[6] - input[3];
    float length_squared = dx * dx + dy * dy + dz * dz;
    out[0] = input[1];
    out[1] = input[2];
    out[2] = input[3];
    out[7] = input[0];
    if (length_squared > 0.0f) {
        float scale = 1.0f / __builtin_sqrtf(length_squared);
        out[3] = dx * scale;
        out[4] = dy * scale;
        out[5] = dz * scale;
        out[6] = length_squared * scale;
    } else {
        out[3] = ActorZeroDirection_00DC24B4[0];
        out[4] = ActorZeroDirection_00DC24B4[1];
        out[5] = ActorZeroDirection_00DC24B4[2];
        out[6] = input[6];
    }
}
__attribute__((noinline)) int StateVariantReadSignedByteOrDefault(
    void *actor, int offset, int fallback)
{
    uint8_t *bytes = (uint8_t *)actor;
    uint8_t *entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
        bytes + 0x1a4, StateVariantEntryKey());
    void *selected = entry != 0 ? *(void **)entry : 0;
    void *upper = *(void **)(bytes + 0x1a8);
    if (selected != upper) {
        if (entry != 0)
            selected = *(void **)entry;
        if (selected != 0)
            return *(int8_t *)((uint8_t *)selected + offset);
    }
    return fallback;
}
void *StateVariantEntryKey(void)
{
    if ((*(uint32_t *)(uintptr_t)0x00D3A608u & 1u) == 0u &&
        StateVariantKeyOnceGuard((const void *)(uintptr_t)0x00D3A608u) !=
            0) {
        void **key = (void **)StateVariantKeyCreate(
            (void *)(uintptr_t)0x00D6822Cu,
            (void *)(uintptr_t)0x00C99B3Cu, 0x48u);
        *key = (void *)(uintptr_t)0x00D09A9Cu;
    }
    return (void *)(uintptr_t)0x00D6822Cu;
}
__attribute__((noinline)) int ActorStateEligibilityGate(struct ActorObjectView *actor)
{
    int state_id;
    if (ActorEligibilitySingletonCache_00D63578 == 0)
        ActorEligibilitySingletonCache_00D63578 =
            EngineLazySingletonGetter_0054EFA8();
    state_id = *(int *)((uint8_t *)actor->active_state + 0x08);
    if (StatusVariantMode() == 1) {
        if (state_id == 0x15 || state_id == 0x16 ||
            state_id == 0x12 || state_id == 0x14)
            return 1;
        {
            uint8_t *record = ActorEligibilityFallbackRecord();
            return record != 0 &&
                   (record[4] == 1 || record[4] == 3 || record[4] == 5);
        }
    }
    if (state_id == 0x15 || state_id == 1 || state_id == 2 ||
        state_id == 5 || state_id == 0x18)
        return 1;
    if (CachedComponent_FlagsContain(actor, 1u) == 0)
        return 0;
    if (state_id == 0x11)
        return 1;
    return CachedComponent_FlagsContain(actor, 0x400000u) != 0;
}
int ActorSpecialEligibilityPredicate(struct ActorObjectView *actor)
{
    uint8_t *engine;
    if (ActorEligibilitySingletonCache_00D63578 == 0)
        ActorEligibilitySingletonCache_00D63578 =
            EngineLazySingletonGetter_0054EFA8();
    engine = (uint8_t *)ActorEligibilitySingletonCache_00D63578;
    if (engine[0x123c] == 0 || engine[0x123d] == 0) {
        if ((void *)(uintptr_t)ResourceTableLookup(
                (uint32_t *)(engine + 0xb280)) == (void *)actor)
            return 0;
    } else {
        uint8_t *record = (uint8_t *)EngineClassNibbleComponentSelect(
            engine, actor);
        if (record != 0) {
            if ((record[0x58] & 4u) != 0)
                return 1;
            if ((record[0x58] & 1u) == 0)
                return 0;
        }
    }
    if (*(int *)((uint8_t *)actor->active_state + 8) == 0x36) {
        uint8_t *entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            &actor->component_tree_anchor, ActorEligibilityTreeKey());
        void *selected = entry != 0 ? *(void **)entry : 0;
        void *upper = actor->component_tree_upper;
        if (entry == 0 || selected == 0 || selected == upper)
            return 0;
    }
    return 1;
}
extern void *ResolveRelatedComponent(void *object);
unsigned DodgeRelatedComponentGate(void *object)
{
    uint8_t *related = (uint8_t *)ResolveRelatedComponent(object);
    if (related == 0)
        return 1u;
    return (~(*(uint32_t *)(related + 0x174) >> 16)) & 1u;
}
extern void *StAroundGetDescriptor(void);
extern void *StDodgeGetDescriptor(void);
extern void *ResourceOwnerLookup_004898E8(uint32_t key);
extern void *EngineComponentRegistryGetter_004C58E0(void);
extern void *ComponentRegistryLookup_004D6028(void *table,
                                                  uint32_t index);
extern void *ResolveStatusDescriptor(void *object);
extern void *ActorStateMachineRequestStateByFactory(void *machine,
                                                       void *descriptor);
extern uint32_t StatusContextGetFlags(void *status_context, uint32_t key);
extern void StatusContextSetFlags(void *status_context, uint32_t key,
                                  unsigned enabled);
extern void EffectResourceNotify(void *singleton, uint32_t owner);
extern void *ConditionFactoryDescriptor_004BFB7C(void);
extern void *ConditionFactoryDescriptor_004897D0(void);
extern unsigned ActorStateConditionType1Handler(void *actor, void *target,
                                                   unsigned selector,
                                                   void *resource_context);
extern void ActorStateConditionType5ResourceReset(void *unused0,
                                                       void *unused1,
                                                       uint32_t value,
                                                       uint32_t handle);
extern int ActorConditionModePredicate_00513330(void);
extern void *StatusEventRecordAlloc_00584AB0(void);
extern void StatusEventRecordSerialize_00584B24(void *record,
                                                   const void *packet,
                                                   unsigned size);
extern void StatusEventQueueInsert_00586824(void *queue, void *record);
extern void StatusOwnerIndexByObject_005B314C(void *registry,
                                                 uint32_t handle);
extern void *StatusEventCandidate_0058E1D0(void);
extern void *StatusEventCandidateValidate_005B0070(void *candidate);
extern void StatusEventCandidateFinalize_005B2874(void *candidate);
static __attribute__((noinline)) void
ActorStateConditionType1QueueStatusEventBody(void *owner,
                                              const uint32_t payload[5])
{
    static void **registry_slot = (void **)(uintptr_t)0x00d63578u;
    if (ActorConditionModePredicate_00513330() == 0)
        return;
    {
        uint8_t owner_mode = *(uint8_t *)((uint8_t *)owner + 0x14u);
        if (owner_mode == 5u || owner_mode == 6u)
            return;
    }
    {
        uint8_t packet[0x15];
        void *record;
        unsigned word;
        packet[0] = 3u;
        for (word = 0; word < 5u; ++word)
            memcpy(packet + 1u + word * 4u, &payload[word], sizeof(uint32_t));
        record = StatusEventRecordAlloc_00584AB0();
        if (record != 0) {
            StatusEventRecordSerialize_00584B24(record, packet, 0x15u);
            StatusEventQueueInsert_00586824(
                (uint8_t *)owner + 0x18u, record);
            *(uint8_t *)((uint8_t *)record + 0x10u) = 1u;
        }
        if ((payload[1] >> 28) == 1u) {
            void *candidate;
            if (*registry_slot == 0)
                *registry_slot = EngineLazySingletonGetter_0054EFA8();
            StatusOwnerIndexByObject_005B314C(*registry_slot, payload[1]);
            candidate = StatusEventCandidate_0058E1D0();
            if (candidate != 0 &&
                StatusEventCandidateValidate_005B0070(candidate) != 0)
                StatusEventCandidateFinalize_005B2874(candidate);
        }
    }
}
__attribute__((noinline)) void ActorStateConditionType1QueueStatusEvent(void *context,
                                                const uint32_t payload[5])
{
    static void **registry_slot = (void **)(uintptr_t)0x00d63578u;
    void *owner = *(void **)((uint8_t *)context + 0xb4u);
    if (owner == 0) {
        if (*registry_slot == 0)
            *registry_slot = EngineLazySingletonGetter_0054EFA8();
        return;
    }
    ActorStateConditionType1QueueStatusEventBody(owner, payload);
}
__attribute__((noinline)) int PlayerStartDodgeOrDash(void *player, void *context, int spin,
                              uint32_t resource_handle,
                              uint32_t fallback_key, int enable_direction)
{
    uint8_t *player_bytes = (uint8_t *)player;
    uint8_t *context_bytes = (uint8_t *)context;
    uint8_t *object = *(uint8_t **)(player_bytes + 0x38);
    uint8_t *machine = *(uint8_t **)(player_bytes + 0x30);
    uint8_t *parameters = *(uint8_t **)(player_bytes + 0x34);
    uint32_t parameter_record[7];
    uint32_t descriptor_record[1];
    uint32_t resource_record = resource_handle;
    uint32_t *selected_pair;
    uintptr_t resource;
    int selector = 0;
    unsigned sector;
    if ((*(uint32_t *)(object + 0x98) & 0x0400300u) != 0u)
        return 0;
    resource = (uintptr_t)ResourceTableLookup(
        &resource_record);
    if (resource != 0u) {
        uint8_t *resolved = (uint8_t *)ResolveStatusDescriptor(
            (void *)resource);
        if (resolved != 0) {
            selector = *(int *)(resolved + 0x20);
        } else {
            uint8_t *fallback = (uint8_t *)ResourceOwnerLookup_004898E8(
                fallback_key);
            if (fallback != 0)
                selector = *(int *)(fallback + 0x90);
        }
        {
            void **cache_slot = *(void ***)(uintptr_t)0x004e5768u;
            void *registry = *cache_slot;
            if (registry == 0) {
                registry = EngineComponentRegistryGetter_004C58E0();
                *cache_slot = registry;
            }
            {
                void *entry = ComponentRegistryLookup_004D6028(
                    *(void **)((uint8_t *)registry + 0x94),
                    (uint32_t)selector);
                if (*(int *)(object + 0x60) == selector && entry != 0 &&
                    (((*(uint8_t *)((uint8_t *)entry + 0x20) & 0x7fu) >>
                      4) != 1u))
                    return 0;
            }
        }
        *(int *)(object + 0x5c) = selector;
    }
    if (spin != 0 && resource != 0u &&
        ((*(uint8_t *)(context_bytes + 0x48)) & 1u) != 0u) {
        uint8_t *orientation = *(uint8_t **)(object + 0x2c);
        float q0 = *(float *)(orientation + 0x44);
        float q1 = *(float *)(orientation + 0x48);
        float q2 = *(float *)(orientation + 0x4c);
        float q3 = *(float *)(orientation + 0x50);
        float lateral = -(q0 * q2 + q1 * q3) * 2.0f;
        float forward = q0 * q0 - ((q2 * q2 + q3 * q3) - q1 * q1);
        float scale = 1.0f / __builtin_sqrtf(lateral * lateral +
                                             forward * forward);
        unsigned around_side =
            0.0f < forward * scale * *(float *)(context_bytes + 0x30) -
                        lateral * scale * *(float *)(context_bytes + 0x38)
                ? 4u
                : 5u;
        if (DodgeRelatedComponentGate((void *)resource) != 0u) {
            void *descriptor = StAroundGetDescriptor();
            uint8_t *state;
            uint8_t *pair = parameters +
                (around_side == 4u ? 0x53cu : 0x558u);
            descriptor_record[0] = (uint32_t)(uintptr_t)descriptor;
            state = (uint8_t *)ActorStateMachineRequestStateByFactory(
                machine, descriptor_record);
            StateParameterRecordInit(parameter_record);
            parameter_record[0] = *(uint32_t *)(pair + 0x00);
            parameter_record[1] = *(uint32_t *)(pair + 0x04);
            *(uint32_t *)(state + 0x28) = parameter_record[0];
            *(uint32_t *)(state + 0x2c) = parameter_record[1];
            if (around_side == 4u)
                state[0x30] = 1;
            return 1;
        }
    }
    if (enable_direction == 0)
        return 0;
    StateParameterRecordInit(parameter_record);
    {
        uint8_t *vector_source = *(uint8_t **)(player_bytes + 0x30);
        float q0 = *(float *)(vector_source + 0x64);
        float q1 = *(float *)(vector_source + 0x68);
        float q2 = *(float *)(vector_source + 0x6c);
        float q3 = *(float *)(vector_source + 0x70);
        float lateral = (q1 * q2 + q0 * q3) * 2.0f;
        float forward = ((q2 * q2 + q3 * q3) - q1 * q1) - q0 * q0;
        float length_squared = lateral * lateral + forward * forward;
        float direction[3];
        if (length_squared > 0.0f) {
            float scale = 1.0f / __builtin_sqrtf(length_squared);
            direction[0] = lateral * scale;
            direction[1] = 0.0f;
            direction[2] = forward * scale;
        } else {
            const float *fallback = (const float *)(uintptr_t)0x00dc24ccu;
            direction[0] = fallback[0];
            direction[1] = fallback[1];
            direction[2] = fallback[2];
        }
        sector = ClassifyDirectionSector(
            direction, (const float *)(context_bytes + 0x30),
            (const float *)(parameters + 0x9b4));
    }
    {
        void *descriptor = StDodgeGetDescriptor();
        uint8_t *state;
        uint8_t *active_state = *(uint8_t **)(object + 0x168);
        uint32_t expected_state = *(uint32_t *)(uintptr_t)
            *(uint32_t **)(uintptr_t)0x004e577cu;
        descriptor_record[0] = (uint32_t)(uintptr_t)descriptor;
        state = (uint8_t *)ActorStateMachineRequestStateByFactory(
            machine, descriptor_record);
        if (*(uint32_t *)(active_state + 0x08) == expected_state)
            state[0x48] |= 4u;
        if (sector == 2u || sector == 3u)
            selected_pair = (uint32_t *)(parameters + 0x4e8);
        else if (sector == 4u)
            selected_pair = (uint32_t *)(parameters + 0x504);
        else if (sector == 5u)
            selected_pair = (uint32_t *)(parameters + 0x520);
        else {
            selected_pair = (uint32_t *)(parameters + 0x4cc);
            if (spin != 0 && resource != 0u)
                state[0x48] |= 2u;
        }
        StateParameterRecordInit(parameter_record);
        parameter_record[0] = selected_pair[0];
        parameter_record[1] = selected_pair[1];
        *(uint32_t *)(state + 0x28) = parameter_record[0];
        *(uint32_t *)(state + 0x2c) = parameter_record[1];
    }
    return 1;
}
extern void QuaternionTransform_004C353C(float *out, void *orientation);
extern void *ActorThreatSearch(void *machine, void *object,
                                   const uint32_t *query, int category,
                                   int arg5, int arg6, int arg7, int arg8);
extern void *ActorSpatialQueryContext(void *machine);
extern int ActorSpatialTest(unsigned mode, void *query_context,
                               const float *position, unsigned flags);
extern float Libm_Floorf_0049A940(float value);
extern void SinCosAngleUnits(float angle_units, float *out_sin,
                             float *out_cos);
extern int ActorRequestMovementState(void *controller,
                                        const uint32_t *explicit_pair,
                                        const uint32_t *vector, unsigned mode,
                                        unsigned mirror);
void PlayerDodgeOrientation(float *out, const float *position,
                               void *orientation)
{
    const float epsilon_length = 0.99998474f;  
    const float zero = 0.0f;
    float x = -position[0];
    float z = -position[1];
    float length = __builtin_sqrtf(x * x + z * z);
    float scale;
    float axis_x;
    float axis_z;
    float quaternion[4];
    float q0;
    float q1;
    float q2;
    float q3;
    float f5;
    float f6;
    float f7;
    float f2;
    if (epsilon_length < length)
        length = 1.0f;
    scale = 1.0f / length;
    axis_x = x * scale;
    axis_z = z * scale;
    QuaternionTransform_004C353C(quaternion, orientation);
    if (length == zero) {
        const float *fallback = (const float *)(uintptr_t)0x00dc249cu;
        out[0] = zero;
        out[1] = fallback[0];
        out[2] = fallback[1];
        out[3] = fallback[2];
        return;
    }
    q0 = quaternion[0];
    q1 = quaternion[1];
    q2 = quaternion[2];
    q3 = quaternion[3];
    f5 = (axis_x * q2 + q3 * zero) - q0 * axis_z;
    f7 = (axis_x * q3 - q2 * zero) + q1 * axis_z;
    f6 = (zero * q0 - q1 * axis_x) + q3 * axis_z;
    f2 = axis_x * q0 + q1 * zero + q2 * axis_z;
    out[0] = length;
    out[3] = (q0 * f5 - q1 * f7) + q3 * f6 + q2 * f2;
    out[1] = (q3 * f7 - q2 * f5) + q1 * f6 + q0 * f2;
    out[2] = ((q2 * f7 + q3 * f5) - q0 * f6) + q1 * f2;
}
__attribute__((noinline)) int PlayerConsumeDashEvent(void *player, void *context, void *input,
                              int mode, void *optional_timer)
{
    uint8_t *player_bytes = (uint8_t *)player;
    uint8_t *context_bytes = (uint8_t *)context;
    uint8_t *input_bytes = (uint8_t *)input;
    uint8_t *event = *(uint8_t **)(input_bytes + 0x30);
    uint8_t *machine = *(uint8_t **)(player_bytes + 0x30);
    uint8_t *object = *(uint8_t **)(player_bytes + 0x38);
    uint8_t *parameters = *(uint8_t **)(player_bytes + 0x34);
    uint32_t scratch_record[7];
    uint32_t movement_pair[2] = {0, 0};
    union {
        uint32_t bits[3];
        float values[3];
    } movement_vector = {{0x7fc00000u, 0u, 0u}};
    float current_position[2];
    float orientation[4];
    float direction[3];
    unsigned movement_mode = 0;
    unsigned mirror = 0;
    unsigned sector;
    float zero = 0.0f;
    if (mode != 0 &&
        StateVariantReadSignedByteOrDefault(machine, 0x3e, 0) == 0)
        return 0;
    if (input_bytes[0x2c] < 2u)
        input_bytes[0x2c] = 1u;
    current_position[0] = *(float *)(event + 0x08);
    current_position[1] = *(float *)(event + 0x0c);
    {
        int event_kind = *(int8_t *)(event + 0x12);
        if (optional_timer != 0) {
            uint8_t *timer = (uint8_t *)optional_timer;
            if (event_kind == 0 && zero < *(float *)(timer + 0x124)) {
                current_position[0] = *(float *)(timer + 0x11c);
                current_position[1] = *(float *)(timer + 0x120);
                event_kind = 1;
            }
            *(float *)(timer + 0x124) = zero;
            if (player_bytes[0x108] != 0) {
                current_position[0] = zero;
                current_position[1] = -1.0f;
                event_kind = 1;
            }
        }
        if (event_kind == 0)
            return 0;
    }
    if ((*(uint32_t *)(object + 0x98) & 0x100u) != 0u)
        return 0;
    if ((*(uint32_t *)(object + 0x94) & 0x10u) != 0u &&
        event[0x10] == 0) {
        uint32_t query[8];
        void *candidate;
        float candidate_position[3];
        ActorBuildVectorRecord((float *)query,
                                   (const float *)(parameters + 0xafcu));
        candidate = ActorThreatSearch(
            machine, object, query, (int8_t)player_bytes[0x104],
            0, 1, 0, 1);
        if (candidate != 0) {
            void *spatial_context = ActorSpatialQueryContext(machine);
            candidate_position[0] = *(float *)((uint8_t *)candidate + 0x54);
            candidate_position[1] = *(float *)((uint8_t *)candidate + 0x58) +
                                    3.0f;
            candidate_position[2] = *(float *)((uint8_t *)candidate + 0x5c);
            if (ActorSpatialTest(8u, spatial_context,
                                    candidate_position, 0u) == 0) {
                if (PlayerStartDodgeOrDash(
                        player, context, 1,
                        *(uint32_t *)((uint8_t *)candidate + 0x12c),
                        0u, 0) != 0)
                    return 0;
            }
        }
    }
    PlayerDodgeOrientation(
        orientation, current_position,
        *(void **)(object + 0x2c));
    if (orientation[0] == zero)
        return 0;
    {
        uint8_t *vector_source = machine;
        float q0 = *(float *)(vector_source + 0x64);
        float q1 = *(float *)(vector_source + 0x68);
        float q2 = *(float *)(vector_source + 0x6c);
        float q3 = *(float *)(vector_source + 0x70);
        float x = (q0 * q2 + q1 * q3) * 2.0f;
        float y = (q1 * q2 - q0 * q3) * 2.0f;
        float z = ((q2 * q2 + q3 * q3) - q1 * q1) - q0 * q0;
        if (y != zero) {
            float scale = 1.0f / __builtin_sqrtf(x * x + y * y + z * z);
            x *= scale;
            z *= scale;
            y = zero;
        }
        direction[0] = x;
        direction[1] = y;
        direction[2] = z;
    }
    sector = ClassifyDirectionSector(
        direction, &orientation[1], (const float *)(parameters + 0x9b4));
    switch (sector) {
    case 1: {
        unsigned variant = (unsigned)StateVariantReadSignedByteOrDefault(
            machine, 0x3f, 1);
        uint8_t *pair = parameters + 0x398u + ((variant ^ 1u) * 0x1cu);
        StateParameterRecordInit(scratch_record);
        movement_pair[0] = *(uint32_t *)(pair + 0x00);
        movement_pair[1] = *(uint32_t *)(pair + 0x04);
        break;
    }
    case 2:
    case 3: {
        uint8_t *pair;
        if (mode == 0) {
            pair = parameters + 0x3ec;
            StateParameterRecordInit(scratch_record);
            movement_pair[0] = *(uint32_t *)(pair + 0x00);
            movement_pair[1] = *(uint32_t *)(pair + 0x04);
            context_bytes[0x48] |= 2u;
            *(float *)(player_bytes + 0x54) = orientation[1];
            *(float *)(player_bytes + 0x58) = orientation[2];
            *(float *)(player_bytes + 0x5c) = orientation[3];
            *(float *)(player_bytes + 0x48) = orientation[1];
            *(float *)(player_bytes + 0x4c) = orientation[2];
            *(float *)(player_bytes + 0x50) = orientation[3];
            *(float *)(context_bytes + 0x3c) = orientation[1];
            *(float *)(context_bytes + 0x40) = orientation[2];
            *(float *)(context_bytes + 0x44) = orientation[3];
            mirror = 1;
        } else {
            pair = parameters + 0x3d0;
            StateParameterRecordInit(scratch_record);
            movement_pair[0] = *(uint32_t *)(pair + 0x00);
            movement_pair[1] = *(uint32_t *)(pair + 0x04);
            movement_vector.values[0] = orientation[1];
            movement_vector.values[1] = orientation[2];
            movement_vector.values[2] = orientation[3];
            movement_mode = 1;
        }
        break;
    }
    case 4:
    case 5: {
        uint8_t *pair = parameters + (sector == 4u ? 0x408u : 0x424u);
        StateParameterRecordInit(scratch_record);
        movement_pair[0] = *(uint32_t *)(pair + 0x00);
        movement_pair[1] = *(uint32_t *)(pair + 0x04);
        if (mode == 0) {
            float angle = sector == 4u ? 0.125f : -0.125f;
            float sine;
            float cosine;
            float f14;
            float f12;
            float f15;
            float f13;
            context_bytes[0x48] |= 2u;
            angle = (angle - Libm_Floorf_0049A940(angle)) *
                    6.2831855f * 40.7436638f;
            SinCosAngleUnits(angle, &sine, &cosine);
            f14 = (orientation[2] * zero - cosine * orientation[1]) +
                  sine * orientation[3];
            f12 = orientation[1] * zero + sine * orientation[2] +
                  zero * orientation[3];
            f15 = (orientation[1] * cosine - zero * orientation[2]) +
                  sine * orientation[3];
            f13 = orientation[1] * zero + cosine * orientation[2] -
                  zero * orientation[3];
            *(float *)(context_bytes + 0x3c) =
                (cosine * f15 - zero * f13) + sine * f14 + zero * f12;
            *(float *)(context_bytes + 0x40) =
                ((zero * f15 + cosine * f13) - zero * f14) + sine * f12;
            *(float *)(context_bytes + 0x44) =
                (zero * f13 - sine * f15) + cosine * f14 + zero * f12;
        }
        break;
    }
    default:
        return 0;
    }
    if (ActorRequestMovementState(
            player, movement_pair, movement_vector.bits,
            movement_mode, mirror) != 0 &&
        (*(uint32_t *)(object + 0x98) & 0x100u) == 0u) {
        *(float *)(player_bytes + 0xcc) -=
            *(float *)(parameters + 0xbc8) * *(float *)(player_bytes + 0xd4);
    }
    return 1;
}
extern int ActorSpecialStatePredicate(void *object);
extern unsigned StatusChannelIsActive(void *object, unsigned channel);
extern unsigned CachedComponent_FlagsContain(void *object,
                                                uint32_t mask);
extern void *SpecialActorStateDescriptor(void);
extern void *ActorStateMachineRequestStateByFactory(void *machine,
                                                       void *descriptor);
int ActorRequestSpecialState(void *actor, void *arg2, void *arg3,
                                void *unused_descriptor)
{
    void *object = *(void **)((uint8_t *)actor + 0x30);
    (void)arg2;
    (void)arg3;
    (void)unused_descriptor;
    if (ActorSpecialStatePredicate(object) != 0 &&
        StatusChannelIsActive(object, 3u) == 0 &&
        StatusChannelIsActive(object, 4u) == 0 &&
        CachedComponent_FlagsContain(object, 0x04000000u) == 0) {
        void *descriptor = SpecialActorStateDescriptor();
        ActorStateMachineRequestStateByFactory(object, &descriptor);
    }
    return 0;
}
int ActorRequestMovementState(void *controller, const uint32_t *explicit_pair,
                                 const uint32_t *vector, unsigned mode,
                                 unsigned mirror)
{
    uint8_t *controller_bytes = (uint8_t *)controller;
    uint8_t *state;
    uint32_t pair[3];
    pair[0] = 0;
    pair[1] = 0;
    pair[2] = 0;
    pair[0] = (uint32_t)(uintptr_t)StDashStartGetDescriptor();
    state = (uint8_t *)ActorStateMachineRequestStateByFactory(
        *(void **)(controller_bytes + 0x30), pair);
    state[0x70] = (uint8_t)((((state[0x70] & 0xf7u) | 1u |
                              ((mode & 1u) << 3)) & 0xefu) |
                            ((mirror & 1u) << 4));
    if (vector != 0) {
        *(uint32_t *)(state + 0x80) = vector[0];
        *(uint32_t *)(state + 0x84) = vector[1];
        *(uint32_t *)(state + 0x88) = vector[2];
    }
    if (explicit_pair == 0) {
        unsigned variant = (unsigned)StateVariantReadSignedByteOrDefault(
            *(void **)(controller_bytes + 0x30), 0x3f, 1);
        uint8_t *parameter_block = *(uint8_t **)(controller_bytes + 0x34);
        StateParameterRecordInit(pair);
        pair[0] = *(uint32_t *)(parameter_block + 0x398u +
                                ((variant ^ 1u) * 0x1cu));
        pair[1] = *(uint32_t *)(parameter_block + 0x39cu +
                                ((variant ^ 1u) * 0x1cu));
        *(uint32_t *)(state + 0x78) = pair[0];
        *(uint32_t *)(state + 0x7c) = pair[1];
    } else {
        *(uint32_t *)(state + 0x78) = explicit_pair[0];
        *(uint32_t *)(state + 0x7c) = explicit_pair[1];
    }
    return 1;
}
enum StateConditionType {
    CONDITION_FLAGS = 0,
    CONDITION_EVENTS = 1,
    CONDITION_TARGET_DESCRIPTOR = 2,
    CONDITION_LIVE_S0_BELOW_THRESHOLD = 3,
    CONDITION_OWNER_FLAG_40 = 4,
    CONDITION_OWNER_FLAG_80 = 5
};
struct StateCondition {
    uint32_t type;
    uint32_t mask;
    uint32_t state;
};
enum HealthConditionFlag {
    HEALTH_CONDITION_FLAG_4000 = 0x00004000u,  
    HEALTH_CONDITION_FLAG_2000 = 0x00002000u   
};
enum HealthSecondaryActorState {
    HEALTH_SECONDARY_PHASE_1 = 0x34,  
    HEALTH_SECONDARY_PHASE_2 = 0x35   
};
const struct StateCondition main_state_conditions[11] = {
    { CONDITION_FLAGS,   HEALTH_CONDITION_FLAG_4000,
      HEALTH_SECONDARY_PHASE_1 },
    { CONDITION_FLAGS,   0x01000000u, 0x2c },
    { CONDITION_FLAGS,   0x02000000u, 0x2d },
    { CONDITION_EVENTS,  0x00000040u, 0x27 },
    { CONDITION_EVENTS,  0x00000080u, 0x25 },
    { CONDITION_OWNER_FLAG_40, 0x00000000u, 0x32 },
    { CONDITION_OWNER_FLAG_80, 0x00000000u, 0x33 },
    { CONDITION_FLAGS,   HEALTH_CONDITION_FLAG_2000,
      HEALTH_SECONDARY_PHASE_2 },
    { CONDITION_TARGET_DESCRIPTOR, 0x00000000u, 0x31 },
    { CONDITION_LIVE_S0_BELOW_THRESHOLD, 0x00000000u, 0x30 },
    { CONDITION_FLAGS,   0x00800000u, 0x2e }
};
const struct StateCondition secondary_state_conditions[2] = {
    { CONDITION_EVENTS, 0x00000008u, 0x28 },
    { CONDITION_EVENTS, 0x00000010u, 0x26 }
};
typedef char kiu_sa_actor_state_machine_1[(sizeof(struct StateCondition) == 12) ? 1 : -1] __attribute__((unused));
static const uint32_t TARGET_DESCRIPTOR_CONDITION_KEY = 0x00c9b9dcu;
static const float LIVE_S0_CONDITION_THRESHOLD = 0.2f;
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *GetStatusDescriptorType(void);
extern void *ComponentType_GetStatusDescriptor_004DC14C(void);
extern void *GetActorStatusDescriptorKey(void);
extern void *OrderedTreeLowerBoundByPointer(void *tree, void *key);
extern void *StatusRegistrySingletonGet(void);
extern uint32_t StatusConditionAdmissionCode(void *engine, void *target);
extern void ActorStateConditionTransitionDispatch(void *engine,
                                                      void *target,
                                                      unsigned mode,
                                                      void *resource_context);
extern void *ActorStateConditionTargetGet_00520480(void);
extern void ActorStateResourceReset_0050519C(void *resource, unsigned mode,
                                                 uint32_t value,
                                                 uint32_t handle);
extern void ComponentNotifyStatusChange(void *component, unsigned mode);
extern void *StatusOwnerIndexAddress(void *base, unsigned index);
extern void StatusChannelResetOrReplace(void *actor, unsigned channel,
                                            unsigned keep_replacement);
extern void DodgeTransformDispatch(void *result, uint32_t key,
                                       const void *transform,
                                       unsigned mode, unsigned flags);
extern void StatusOwner_TightenThreshold(void *owner, uint32_t key,
                                            float threshold);
extern void StatusChannelExpireAlternate(void *state, void *target,
                                          unsigned channel,
                                          float hidden_value);
extern void StatusChannelExpire(void *state, void *target,
                                   unsigned channel);
extern void *ResolveCachedComponent_1EC(void *object);
extern void *EngineLazySingletonGetter_003FD6E0(void);
extern void *EngineLazySingletonGetter_00498828(void);
extern void *EffectEventHandleResolver_00566F0C(void *dispatcher,
                                                    uint32_t handle);
extern int EngineRecordPoolWrite_004B275C(void *pool, uint32_t handle,
                                              const void *record);
extern int EffectEventReleasePool_0048D320(void *dispatcher);
extern uint32_t EffectTableLookupSimpleVariant_005B30B0(void *table,
                                                            unsigned index);
extern uint32_t EffectTableLookupVariantC8_0059290C(void *table,
                                                        unsigned index);
extern uint32_t EffectTableLookupVariant108_00592924(void *table,
                                                         unsigned index);
extern uint32_t EffectTableLookupModeVariant_005B30BC(void *table,
                                                          unsigned index,
                                                          int mode);
__attribute__((noinline)) uint32_t EffectTableLookupSimpleVariant_005B30B0(void *table,
                                                  unsigned index)
{
    return *(uint32_t *)((uint8_t *)table + 0x1c8 + index * 4u);
}
__attribute__((noinline)) uint32_t EffectTableLookupModeVariant_005B30BC(void *table,
                                                unsigned index,
                                                int mode)
{
    if (index >= 0x10u || mode < 0 || mode >= 2)
        return UINT32_MAX;
    return *(uint32_t *)((uint8_t *)table + 0x148 + index * 8u +
                         (unsigned)mode * 4u);
}
__attribute__((noinline)) uint32_t EffectTableLookupVariantC8_0059290C(void *table, unsigned index)
{
    if (index >= 0x10u)
        return UINT32_MAX;
    return *(uint32_t *)((uint8_t *)table + 0xc8 + index * 4u);
}
__attribute__((noinline)) uint32_t EffectTableLookupVariant108_00592924(void *table, unsigned index)
{
    if (index >= 0x10u)
        return UINT32_MAX;
    return *(uint32_t *)((uint8_t *)table + 0x108 + index * 4u);
}
extern uint32_t EffectEventBuildAndSubmit_00550EE4(
    uint32_t event_type, const uint32_t *record);
extern void StatusChannelUpdateTimers(void *state, void *target,
                                         void *frame_context);
extern unsigned HealthSecondaryStateClassify(void *secondary,
                                                void *target,
                                                void *frame_context);
extern void HealthSecondaryReset(void *secondary, void *target);
extern void Health_StatusBitUpdate(void *state, uint32_t mask,
                                     unsigned enabled);
extern float HealthClampCurrent(float value, float lower, float upper);
extern void *ComponentLookupStatusOwner(void *registry, void *target);
extern void *GetStatusDescriptorRegistry(void);
extern void StatusStateTransition(void *state_char);
extern void StatusStateReturnToIdle(void *state_char);
extern float ActorConditionUpdateFrame(void *target, void *frame_state);
extern float ActorConditionScalePrepared(void *record, void *target,
                                           void *shared_state);
extern void ActorConditionApplyResource(void *resource, unsigned state,
                                          uint32_t word_value, float value);
extern void ActorConditionApplyResourceInverted(void *resource,
                                                  unsigned state,
                                                  uint32_t word_value,
                                                  float value);
extern void ActorConditionFinalizeResource(void *resource, unsigned state,
                                              unsigned mode, float value);
extern void ActorStateConditionEventBatchRefresh(void *record,
                                                     void *target,
                                                     void *frame_context);
extern void *EngineSharedObjectSingleton(void);
extern void EngineEventRegistryBroadcast(void *registry,
                                             const uint32_t *argument);
extern void EngineEventRegistryDispatchArg(void *registry,
                                               const uint32_t *argument,
                                               int marker);
extern float TrigKernel_0049A9DC(float angle);
__attribute__((noinline)) unsigned ActorConditionPrepareRecord(void *record, uint32_t *word_out,
                                      float *value_out)
{
    uint8_t *bytes = (uint8_t *)record;
    float value;
    if ((char)bytes[0] == 'J')
        return 0u;
    if ((char)bytes[0] == 'I') {
        uint8_t *state = *(uint8_t **)(bytes + 8u);
        float phase = (bytes[0x0c] / *(float *)(state + 4u)) *
                      3.1415927f * (float)state[8] * 0.01f;
        float sine = TrigKernel_0049A9DC(phase);
        int span = (int)state[0x0b] - (int)state[0x0a];
        value = (float)span * 0.01f *
                    (sine < 0.0f ? -sine : sine) +
                (float)state[0x0a] * 0.01f;
        if (value < 0.0f)
            value = 0.0f;
        if (value > 1.0f)
            value = 1.0f;
        *value_out = value;
        *word_out = **(uint32_t **)(bytes + 8u) | 0xffu;
    } else {
        ActorConditionPrepareTableLookup_0042121C(record, word_out, value_out);
    }
    *value_out *= *(float *)(bytes + 0x14u);
    return 1u;
}
__attribute__((noinline)) void ActorConditionApplyPrepared(void *record, uint32_t word_value,
                                  unsigned is_state_49, unsigned repeat_bit,
                                  void *frame_context, float value)
{
    uint8_t *bytes = (uint8_t *)record;
    uint8_t *target = (uint8_t *)frame_context;
    uint8_t *descriptor = *(uint8_t **)(target + 0x1e4u);
    uint8_t *entry;
    uint8_t *upper;
    uint8_t *shared;
    float scaled_value;
    float applied;
    if (descriptor == 0) {
        entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            target + 0x1a4u, EngineLazySingletonGetter_00498828());
        upper = *(uint8_t **)(target + 0x1a8u);
        descriptor = (entry != 0 && *(uint8_t **)entry != upper)
            ? *(uint8_t **)entry : 0;
        if (descriptor != 0) {
            *(void **)(descriptor + 0x1cu) = target;
            *(uint8_t **)(target + 0x1e4u) = descriptor;
        }
    }
    if (descriptor == 0)
        return;
    shared = (uint8_t *)ActorMovementEngineGet_004C59C0();
    scaled_value = value;
    if (repeat_bit == 0u) {
        scaled_value *= ActorConditionUpdateFrame(target, target + 0x54u);
        scaled_value *= ActorConditionScalePrepared(record, target,
                                                       shared + 0x1d4u);
    }
    applied = *(float *)(bytes + 0xa4u) * scaled_value;
    if (applied < 0.0f)
        applied = 0.0f;
    if (applied > 1.0f)
        applied = 1.0f;
    applied = 1.0f - applied;
    if (is_state_49 != 0u) {
        ActorConditionApplyResourceInverted(*(void **)(descriptor + 0x30u),
                                               bytes[0], word_value, applied);
    } else {
        ActorConditionApplyResource(*(void **)(descriptor + 0x30u),
                                      bytes[0], word_value, applied);
    }
}
__attribute__((noinline)) void ActorStateConditionPreUpdate(void *record, void *target,
                                    void *frame_context)
{
    uint8_t *base = (uint8_t *)record;
    uint8_t *selected = 0;
    uint8_t *descriptor;
    uint8_t *entry;
    uint8_t *upper;
    uint32_t prepared_word;
    float prepared_value;
    unsigned index;
    for (index = 0; index < 5u; ++index) {
        uint8_t *candidate = base + 4u + index * 0x1cu;
        if (candidate[0] != 0x4au) {
            selected = candidate;
            break;
        }
    }
    if (selected != 0) {
        unsigned is_state_49;
        unsigned repeat_bit;
        ActorConditionPrepareRecord(selected, &prepared_word,
                                     &prepared_value);
        is_state_49 = selected[0] == 0x49u;
        repeat_bit = (selected[0x18] & 2u) >> 1;
        ActorConditionApplyPrepared(base, prepared_word, is_state_49,
                                     repeat_bit, target,
                                     prepared_value);
        base[0x90] = 1u;
    } else {
        if (base[0x90] != 0u) {
            descriptor = *(uint8_t **)((uint8_t *)target + 0x1e4u);
            if (descriptor == 0) {
                entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
                    (uint8_t *)target + 0x1a4u,
                    EngineLazySingletonGetter_00498828());
                upper = *(uint8_t **)((uint8_t *)target + 0x1a8u);
                descriptor = (entry != 0 && *(uint8_t **)entry != upper)
                    ? *(uint8_t **)entry : 0;
                if (descriptor != 0) {
                    *(void **)(descriptor + 0x1cu) = target;
                    *(uint8_t **)((uint8_t *)target + 0x1e4u) = descriptor;
                }
            }
            if (descriptor != 0) {
                ActorConditionFinalizeResource(
                    *(void **)(descriptor + 0x30u), base[0], 0u, 1.0f);
            }
            base[0x90] = 0u;
        }
    }
    for (index = 0; index < 5u; ++index) {
        uint8_t *entry = base + index * 0x1cu;
        uint8_t *condition = entry + 4u;
        float elapsed;
        if (condition[0] == 0x4au)
            continue;
        elapsed = *(float *)(condition + 0x10u) +
                  *(const float *)((const uint8_t *)frame_context + 0x0cu);
        *(float *)(condition + 0x10u) = elapsed;
        if (elapsed >= *(float *)(condition + 0x14u)) {
            if ((condition[0x18] & 1u) == 0u)
                condition[0] = 0x4au;
            else {
                do {
                    elapsed -= *(float *)(condition + 0x14u);
                    *(float *)(condition + 0x10u) = elapsed;
                } while (elapsed >= *(float *)(condition + 0x14u));
            }
        }
    }
}
extern void *ActorStateEngineGet(void);
extern void *ActorActiveChannelKey_004A8A80(void);
extern void *ActorMovementEngineGet_004C59C0(void);
extern void *GetStatusLinkDescriptor(void);
extern void *ActorStatusComponent_004C5204(void);
extern void ActorMovementNotify_0059095C(void *actor, unsigned mode,
                                             int selector);
extern float ActorStateHealthStatusParameterUpdate(void *record,
                                                       void *descriptor,
                                                       float delta);
extern void *HealthRandomSingleton(void);
extern float TrigKernel_00474934(float value);
extern float TrigKernel_0049A9DC(float value);
extern const float ActorHealthFallbackPair_00DC24A0[2];
extern const float ActorHealthFallbackVector_00DC249C[3];
extern uint32_t DamagePacketBuildFlags(void *context);
extern uint32_t StatusContextGetFlags(void *status_context, uint32_t key);
extern void HealthNotifyModeZero(void *component, float value);
extern void StatusRegistryUpdate(void *actor, uint32_t key, unsigned mode);
extern void ActorStateEffectQueueSeed(void *actor);
extern void *StatusConditionSingleton_005786AC(void);
extern void StatusConditionApplyShared(void *singleton, unsigned mode);
extern void *StatusSharedSingleton_004C5874(void);
extern void *ActorMovementDescriptorKey_00517CC4(void);
extern void StateParameterReset_0058626C(void *state, void *target,
                                             uint32_t selector,
                                             const void *defaults,
                                             float scale, float scalar);
extern void StateParameterClear_0058665C(void *state);
extern void StateParameterResetScalar_0058665C(void *state,
                                                   float scalar);
extern void StateParameterPublish_00586390(void *state, void *target,
                                               uint32_t selector,
                                               const uint32_t *parameters,
                                               const void *source,
                                               float scale, float scalar);
extern int EngineGlobalModeByteIsZero(void);
extern void MovementParameterSelect(float *record, void *table,
                                       unsigned mode, unsigned flags);
extern const float MovementQuaternionIdentity_00DC2538[4];
enum ActorConditionType2Mask {
    ACTOR_CONDITION_RESOURCE_READY = 0x00004000u,
    ACTOR_CONDITION_OWNER_UPDATE = 0x00008000u,
    ACTOR_CONDITION_STATUS_SETUP = 0x00000400u,
    ACTOR_CONDITION_SECONDARY_UPDATE = 0x00010000u
};
static void **gConditionSharedSlot =
    (void **)(uintptr_t)0x00d635a8u;
static void **gConditionStatusSlot =
    (void **)(uintptr_t)0x00d63550u;
__attribute__((noinline)) int ActorState_ConditionType2Gate(void *actor, void *target)
{
    uint8_t *actor_bytes = (uint8_t *)actor;
    uint8_t *descriptor = (uint8_t *)ResolveStatusDescriptor(target);
    uint8_t *target_related = (uint8_t *)ResolveRelatedComponent(target);
    uint32_t status_flags = StatusContextGetFlags(
        actor_bytes + 0xf98cu,
        *(uint32_t *)(descriptor + 0x20u));
    void *resource = (void *)(uintptr_t)ResourceTableLookup(
        (uint32_t *)(actor_bytes + 0xb278u));
    if ((status_flags & ACTOR_CONDITION_RESOURCE_READY) != 0u &&
        resource != 0) {
        uint8_t *resource_related = resource != 0
            ? (uint8_t *)ResolveRelatedComponent(resource) : 0;
        if (resource_related == 0 ||
            *(float *)(resource_related + 0x178u) <= 0.0f) {
            HealthNotifyModeZero(target_related, 0.1f);
            return 0;
        }
    }
    if ((status_flags & ACTOR_CONDITION_OWNER_UPDATE) != 0u) {
        uint32_t packet_flags = DamagePacketBuildFlags(actor);
        uint8_t *owner = (uint8_t *)StatusOwnerLookupByHandle(
            actor_bytes + 0xb3f8u, packet_flags);
        *(uint32_t *)(owner + 0xad8u) |= 0x10u;
    }
    if ((status_flags & ACTOR_CONDITION_STATUS_SETUP) != 0u) {
        uint8_t *status_singleton;
        actor_bytes[0xa72u] = 1u;
        actor_bytes[0x1ede0u] = 1u;
        StatusRegistryUpdate(actor, UINT32_MAX, 1u);
        ActorStateEffectQueueSeed(actor);
        *(uint32_t *)(actor_bytes + 0x124u) =
            *(uint32_t *)((uint8_t *)target + 0x12cu);
        if (actor_bytes[0x12eu] != 0x12u)
            actor_bytes[0xf0u + 0x3eu] = 0x1bu;
        actor_bytes[0x129u] = (uint8_t)((status_flags & 0x2000u) >> 13);
        actor_bytes[0x128u] = (uint8_t)((status_flags & 0x800u) >> 11);
        if ((status_flags & 0x800u) != 0u) {
            status_singleton = (uint8_t *)*gConditionSharedSlot;
            if (status_singleton == 0) {
                status_singleton = (uint8_t *)
                    StatusConditionSingleton_005786AC();
                *gConditionSharedSlot = status_singleton;
            }
            StatusConditionApplyShared(status_singleton, 0u);
        }
    }
    if ((status_flags & ACTOR_CONDITION_SECONDARY_UPDATE) != 0u) {
        uint8_t *status_singleton = (uint8_t *)*gConditionStatusSlot;
        if (actor_bytes[0xa73u] != 0u) {
            if (status_singleton == 0) {
                status_singleton = (uint8_t *)
                    StatusSharedSingleton_004C5874();
                *gConditionStatusSlot = status_singleton;
            }
            status_singleton[0xb8u] |= 4u;
        }
        uint8_t *resource_related = resource != 0
            ? (uint8_t *)ResolveRelatedComponent(resource) : 0;
        if (resource_related != 0 &&
            *(uint8_t **)(resource_related + 0x170u) != 0 &&
            **(uint8_t **)(resource_related + 0x170u) != 0u) {
            if (status_singleton == 0) {
                status_singleton = (uint8_t *)
                    StatusSharedSingleton_004C5874();
                *gConditionStatusSlot = status_singleton;
            }
            status_singleton[0xb8u] |= 8u;
        }
    }
    return 1;
}
void ActorStatePublishHeadN(void *state, void *target,
                               const uint8_t *parameter_record,
                               unsigned publish_primary,
                               unsigned publish_secondary,
                               unsigned secondary_fallback);
extern void ActorConditionNoOp(void);
__attribute__((noinline)) void *ActorStateMachineSetPendingState(struct HealthStatusComponent *machine,
                                          void *state)
{
    void *pending = machine->pending_state;
    if (pending == 0)
        machine->active_state = state;
    else
        *(void **)pending = state;
    machine->pending_state = state;
    *(void **)state = 0;
    return machine->deferred_state;
}
typedef void (*ActorStateMessageHandler)(void *, void *, void *, void *,
                                          void *, void *);
__attribute__((noinline)) void ActorStateMachine_DispatchMessage(void *machine, void *message,
                                        void *context)
{
    uint8_t *machine_bytes = (uint8_t *)machine;
    uint8_t *message_bytes = (uint8_t *)message;
    uint8_t *registry;
    uint8_t *node;
    uint8_t *sentinel;
    void **registry_slot = (void **)(uintptr_t)0x00d63714u;
    uint32_t multiplier_a;
    uint32_t multiplier_b;
    uint32_t multiplier_c;
    registry = (uint8_t *)*registry_slot;
    if (registry == 0) {
        registry = (uint8_t *)Engine_LazyStrideRegistry_003B6D84();
        *registry_slot = registry;
    }
    node = *(uint8_t **)(machine_bytes + 0x15cu);
    sentinel = *(uint8_t **)(machine_bytes + 0x158u);
    multiplier_a = *(uint32_t *)(registry + 0x04u);
    multiplier_b = *(uint32_t *)(registry + 0x08u);
    multiplier_c = *(uint32_t *)(registry + 0x0cu);
    while (node != sentinel &&
           ((message_bytes[0x28u] & 1u) == 0u)) {
        uint8_t *active = *(uint8_t **)(machine_bytes + 0x168u);
        uint32_t key = *(uint32_t *)(node + 0x28u) * multiplier_a;
        uint32_t bucket_index;
        uint8_t *bucket;
        ActorStateMessageHandler handler = 0;
        key = (key + *(uint32_t *)(active + 0x04u)) * multiplier_b;
        key = (key + *(uint32_t *)(message_bytes + 0x04u)) * multiplier_c;
        key += *(uint32_t *)((uint8_t *)context + 0x04u);
        bucket_index = (key ^ (key >> 10)) & 0x3ffu;
        bucket = registry + bucket_index * 0x20u;
        if (*(uint32_t *)(bucket + 0x24u) == key)
            handler = *(ActorStateMessageHandler *)(bucket + 0x20u);
        else if (*(uint32_t *)(bucket + 0x2cu) == key)
            handler = *(ActorStateMessageHandler *)(bucket + 0x28u);
        else if (*(uint32_t *)(bucket + 0x34u) == key)
            handler = *(ActorStateMessageHandler *)(bucket + 0x30u);
        else if (*(uint32_t *)(bucket + 0x3cu) == key)
            handler = *(ActorStateMessageHandler *)(bucket + 0x38u);
        else {
            uint8_t *begin = *(uint8_t **)(registry + 0x10u);
            uint8_t *end = begin + *(uint32_t *)(registry + 0x18u) * 8u;
            uint8_t *cursor = begin;
            uint32_t count = (uint32_t)(end - begin) / 8u;
            while (count != 0u) {
                uint32_t half = count >> 1;
                uint8_t *middle = cursor + half * 8u;
                if (*(uint32_t *)(middle + 0x04u) < key) {
                    cursor = middle + 8u;
                    count -= half + 1u;
                } else {
                    count = half;
                }
            }
            if (cursor != end && *(uint32_t *)(cursor + 0x04u) == key)
                handler = *(ActorStateMessageHandler *)cursor;
            *(uint32_t *)(bucket + 0x38u) =
                *(uint32_t *)(bucket + 0x30u);
            *(uint32_t *)(bucket + 0x3cu) =
                *(uint32_t *)(bucket + 0x34u);
            *(uint32_t *)(bucket + 0x30u) =
                *(uint32_t *)(bucket + 0x28u);
            *(uint32_t *)(bucket + 0x34u) =
                *(uint32_t *)(bucket + 0x2cu);
            *(uint32_t *)(bucket + 0x28u) =
                *(uint32_t *)(bucket + 0x20u);
            *(uint32_t *)(bucket + 0x2cu) =
                *(uint32_t *)(bucket + 0x24u);
            *(ActorStateMessageHandler *)(bucket + 0x20u) = handler;
            *(uint32_t *)(bucket + 0x24u) = key;
        }
        if (handler != 0)
            handler(node, active, message, context, machine, message);
        node = *(uint8_t **)(node + 0x04u);
    }
}
extern void ActorStateExitMessageInit(void *message);
extern void ActorStateEnterMessageInit(void *message, void *previous_state);
static void ActorStateRelease(void *state)
{
    uint32_t vtable;
    void (*release)(void *state);
    if (state == 0)
        return;
    vtable = *(uint32_t *)state;
    release = *(void (**)(void *))((uint8_t *)(uintptr_t)vtable + 0x0c);
    release(state);
}
static void ActorStateMessageUnlink(void *message)
{
    uint8_t *bytes = (uint8_t *)message;
    uint32_t left;
    uint32_t right;
    left = *(uint32_t *)(bytes + 0x18);
    right = *(uint32_t *)(bytes + 0x1c);
    *(uint32_t *)(uintptr_t)(left + 4) = right;
    *(uint32_t *)(uintptr_t)(right + 8) = left;
    left = *(uint32_t *)(bytes + 0x0c);
    right = *(uint32_t *)(bytes + 0x10);
    *(uint32_t *)(uintptr_t)(left + 4) = right;
    *(uint32_t *)(uintptr_t)(right + 8) = left;
}
__attribute__((noinline)) void ActorStateMachineApplyPendingState(
    struct HealthStatusComponent *machine, void *context)
{
    void *deferred = machine->deferred_state;
    void *previous;
    void *active;
    void *pending;
    uint8_t exit_message[0x30];
    uint8_t enter_message[0x30];
    if (deferred != 0) {
        ActorStateRelease(deferred);
        machine->deferred_state = 0;
    }
    pending = machine->pending_state;
    if (pending == 0)
        return;
    ActorStateExitMessageInit(exit_message);
    ActorStateMachine_DispatchMessage(machine, exit_message, context);
    previous = machine->active_state;
    machine->active_state = 0;
    ActorStateEnterMessageInit(enter_message, previous);
    pending = machine->pending_state;
    machine->pending_state = 0;
    active = machine->active_state;
    if (active != pending) {
        ActorStateRelease(active);
        machine->active_state = pending;
    }
    ActorStateMachine_DispatchMessage(machine, enter_message, context);
    ActorStateMessageUnlink(enter_message);
    ActorStateRelease(previous);
    ActorStateMessageUnlink(exit_message);
}
static int ActorGenerationHandlePresent(void *engine)
{
    uint32_t generation = *(uint32_t *)((uint8_t *)engine + 0x1eca0);
    uint32_t expected = generation >> 9;
    uint32_t index = generation & 0x1ffu;
    uint32_t *entry;
    if (*(int32_t *)((uint8_t *)engine + 0x1eca4) < 0 ||
        expected == 0x7fffffu)
        return 0;
    entry = (uint32_t *)(uintptr_t)(0x00e11614u + index * 8u);
    if (entry[1] != expected)
        return 0;
    return entry[0] != 0;
}
__attribute__((noinline)) void ActorStateUpdateActiveChannel(void *state, void *target,
                                      void *engine_state)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *target_bytes = (uint8_t *)target;
    uint8_t *engine_bytes = (uint8_t *)engine_state;
    uint32_t channel;
    for (channel = 0; channel < STATUS_CHANNEL_COUNT; ++channel) {
        uint32_t bit = 1u << channel;
        uint32_t selector;
        uint8_t *entry;
        uint8_t *upper;
        uint8_t *descriptor;
        uint8_t *source;
        uint32_t parameters[3];
        if ((*(uint32_t *)(state_bytes + 0x1dcu) & bit) == 0)
            continue;
        selector = *(uint32_t *)(engine_bytes + 0x1b4u + channel * 4u);
        if (*(uint32_t *)(state_bytes + 0x144u) == selector) {
            StateParameterReset_0058626C(
                state_bytes + 0x140u, target, selector,
                (const void *)(uintptr_t)0x00dc249cu, 1.0f, 1.0f);
            return;
        }
        entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            target_bytes + 0x1a4u, ActorActiveChannelKey_004A8A80());
        upper = *(uint8_t **)(target_bytes + 0x1a8u);
        descriptor = (entry != 0 && *(uint8_t **)entry != upper)
            ? *(uint8_t **)entry : 0;
        source = descriptor != 0 ? *(uint8_t **)(descriptor + 0x1cu) : 0;
        if (source == 0) {
            StateParameterReset_0058626C(
                state_bytes + 0x140u, target, selector,
                (const void *)(uintptr_t)0x00dc249cu, 1.0f, 1.0f);
            return;
        }
        parameters[0] = *(uint32_t *)(source + 0xa4u);
        parameters[1] = *(uint32_t *)(source + 0xa8u);
        parameters[2] = *(uint32_t *)(source + 0xacu);
        StateParameterPublish_00586390(
            state_bytes + 0x140u, target, selector, parameters,
            source + 0x78u,
            *(const float *)(target_bytes + 0x60u) *
                *(const float *)(source + 0xb0u) /
                *(const float *)(engine_bytes + 0x1f4u),
            1.0f);
        return;
    }
    StateParameterClear_0058665C(state_bytes + 0x140u);
}
__attribute__((noinline)) void ActorStatePublishMovementParameters(void *state, void *target,
                                             const uint8_t *action)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *target_bytes = (uint8_t *)target;
    uint8_t *engine;
    uint8_t *entry;
    uint8_t *upper;
    uint8_t *descriptor;
    uint8_t *source;
    uint32_t selector;
    uint32_t parameters[3];
    if ((action[0x1d] & 0x10u) != 0 || action[3] == 3 ||
        (action[0x1d] & 1u) != 0 || action[0] == 4)
        return;
    engine = (uint8_t *)ActorMovementEngineGet_004C59C0();
    entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
        target_bytes + 0x1a4u, ActorActiveChannelKey_004A8A80());
    upper = *(uint8_t **)(target_bytes + 0x1a8u);
    descriptor = (entry != 0 && *(uint8_t **)entry != upper)
        ? *(uint8_t **)entry : 0;
    source = descriptor != 0 ? *(uint8_t **)(descriptor + 0x1cu) : 0;
    selector = *(uint32_t *)(engine + 0x4924u +
                             (unsigned)action[1] * 4u + 0xecu);
    if (source == 0) {
        StateParameterReset_0058626C(
            state_bytes + 0x150u, target, selector,
            (const void *)(uintptr_t)0x00dc249cu, 1.0f,
            *(const float *)(engine + 0x4924u +
                             (unsigned)action[1] * 0x10u +
                             (unsigned)action[3] * 4u + 0x118u));
        return;
    }
    parameters[0] = *(uint32_t *)(source + 0xa4u);
    parameters[1] = *(uint32_t *)(source + 0xa8u);
    parameters[2] = *(uint32_t *)(source + 0xacu);
    StateParameterPublish_00586390(
        state_bytes + 0x150u, target, selector, parameters,
        source + 0x78u,
        *(const float *)(target_bytes + 0x60u) *
            *(const float *)(source + 0xb0u) /
            *(const float *)(engine + 0x4924u +
                             (unsigned)action[1] * 0x10u +
                             (unsigned)action[3] * 4u + 0x114u),
        *(const float *)(engine + 0x4924u +
                         (unsigned)action[1] * 0x10u +
                         (unsigned)action[3] * 4u + 0x118u));
}
__attribute__((noinline)) void ActorStatePublishSelectedParameter(void *state, void *unused,
                                            const uint8_t *action)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *engine;
    uint8_t *destination;
    uint8_t variant;
    int8_t value;
    (void)unused;
    if ((action[0x1c] & 0x10u) != 0 || action[3] == 3)
        return;
    engine = (uint8_t *)ActorMovementEngineGet_004C59C0();
    destination = state_bytes + 0x7c +
                  (unsigned)*(const uint8_t *)(uintptr_t)0x00d45d40u * 0x1cu;
    variant = action[3];
    if ((action[0x1d] & 1u) != 0) {
        value = *(const int8_t *)(engine + 0x224u + variant);
        StateParameterRecordUpdate(destination, value, 1.0f);
        return;
    }
    if ((action[0x1c] & 0x40u) != 0) {
        StateParameterRecordUpdate(destination, 0, 1.0f);
        return;
    }
    if ((action[0x1c] & 0x80u) != 0)
        value = *(const int8_t *)(engine + 0x227u + variant);
    else
        value = *(const int8_t *)(engine + 0x22au + variant + action[1] * 3u);
    StateParameterRecordUpdate(destination, value,
                                  *(const float *)(engine + 0x21cu) +
                                  (*(const float *)(engine + 0x220u) -
                                   *(const float *)(engine + 0x21cu)) *
                                      *(const float *)(action + 8u));
}
__attribute__((noinline)) uint32_t ActorStateUpdateMovementParameter(void *state, void *target,
                                               uint8_t *action,
                                               float frame_scale)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *target_bytes = (uint8_t *)target;
    uint8_t *engine;
    uint8_t *table;
    uint8_t mode;
    uint32_t selector = UINT32_MAX;
    float payload[3];
    float q1;
    float q2;
    float q3;
    float q4;
    float length;
    float inverse_length;
    float dx;
    float dy;
    float dz;
    float t0;
    float t1;
    float t2;
    float t3;
    float scale;
    union FloatBits normalize_threshold;
    if ((action[0x1c] & 8u) != 0u || action[3] == 3u)
        return UINT32_MAX;
    engine = (uint8_t *)ActorMovementEngineGet_004C59C0();
    table = engine + 0x4924u;
    mode = action[3] < 3u ? action[3] : 2u;
    MovementParameterSelect((float *)(action + 0x0cu), table,
                               EngineGlobalModeByteIsZero(),
                               *(const uint32_t *)(state_bytes + 0x174u) & 1u);
    q1 = *(const float *)(target_bytes + 0x44u);
    q2 = *(const float *)(target_bytes + 0x48u);
    q3 = *(const float *)(target_bytes + 0x4cu);
    q4 = *(const float *)(target_bytes + 0x50u);
    length = q1 * q1 + q2 * q2 + q3 * q3 + q4 * q4;
    normalize_threshold.bits = 0x33d6bf95u;
    if (length > normalize_threshold.value) {
        inverse_length = 1.0f / length;
        t0 = q1 * inverse_length;
        t1 = q2 * inverse_length;
        t2 = q3 * inverse_length;
        t3 = q4 * inverse_length;
        q1 = -t0;
        q2 = -t1;
        q3 = t3;
        q4 = t2;
    } else {
        q1 = MovementQuaternionIdentity_00DC2538[0];
        q2 = MovementQuaternionIdentity_00DC2538[1];
        q3 = MovementQuaternionIdentity_00DC2538[2];
        q4 = MovementQuaternionIdentity_00DC2538[3];
    }
    dx = *(const float *)(action + 0x0cu) -
         *(const float *)(target_bytes + 0x54u);
    dy = *(const float *)(action + 0x10u) -
         *(const float *)(target_bytes + 0x58u);
    dz = *(const float *)(action + 0x14u) -
         *(const float *)(target_bytes + 0x5cu);
    t0 = dx * q4;
    t1 = dx * q3;
    t2 = dx * q1;
    t3 = dy * q1;
    t0 += q3 * dy;
    t1 -= q4 * dy;
    t2 += q2 * dy;
    t3 -= q2 * dx;
    t0 -= q1 * dz;
    t1 += q2 * dz;
    t2 += q3 * dz;
    t3 += q4 * dz;
    dx = q1 * t0 - q2 * t1 + q4 * t3 + q3 * t2;
    dy = q4 * t1 - q3 * t0 + q2 * t3 + q1 * t2;
    dz = q3 * t1 + q4 * t0 - q1 * t3 + q2 * t2;
    inverse_length = 1.0f / *(const float *)(target_bytes + 0x40u);
    payload[0] = dx * inverse_length;
    payload[1] = dy * inverse_length;
    payload[2] = dz * inverse_length;
    scale = *(const float *)(state_bytes + 0x160u) * frame_scale;
    if ((action[0x1c] & 0x40u) != 0u) {
        uint8_t *timing = (uint8_t *)(uintptr_t)0x00d45d40u;
        float engine_time = *(const float *)(
            (const uint8_t *)EngineLazySingletonGetter_0054EFA8() +
            0xc0cu);
        if (engine_time < *(float *)(timing + 4u))
            *(float *)(timing + 4u) = 0.0f;
        if (0.5f < engine_time - *(float *)(timing + 4u))
            *(uint32_t *)(timing + 8u) = 0u;
        else if (*(uint32_t *)(timing + 8u) > 1u)
            return UINT32_MAX;
        selector = *(const uint32_t *)(table +
            (unsigned)action[1] * 0x10u + (unsigned)mode * 4u + 0x58u);
        StateParameterReset_0058626C(
            state_bytes + 0x120u, target, selector, payload,
            scale, payload[0]);
        if (action[0] == 4u)
            StateParameterResetScalar_0058665C(state_bytes + 0x150u,
                                                   scale);
        *(float *)(timing + 4u) = engine_time;
        *(uint32_t *)(timing + 8u) += 1u;
        return selector;
    }
    if (action[0] == 4u) {
        selector = 0x27b1u;
        StateParameterReset_0058626C(
            state_bytes + 0x130u, target, selector, payload,
            scale, payload[0]);
        return selector;
    }
    if ((action[0x1d] & 8u) != 0u) {
        selector = *(const uint32_t *)(table + (unsigned)mode * 4u + 0x38u);
    } else if ((action[0x1d] & 1u) != 0u) {
        if (*(const float *)(state_bytes + 0x1d0u) <= 0.1f)
            return UINT32_MAX;
        selector = *(const uint32_t *)(table + (unsigned)mode * 4u + 0x38u);
        *(float *)(state_bytes + 0x1d0u) = 0.0f;
    } else if ((action[0x1c] & 0x80u) != 0u) {
        if (*(const float *)(state_bytes + 0x1d0u) <= 0.1f)
            return UINT32_MAX;
        selector = *(const uint32_t *)(table + (unsigned)mode * 4u + 0x28u);
        *(float *)(state_bytes + 0x1d0u) = 0.0f;
    } else {
        float low;
        float high;
        if (*(const float *)(state_bytes + 0x1d0u) <= 0.1f)
            return UINT32_MAX;
        selector = *(const uint32_t *)(table +
            (unsigned)action[1] * 0x10u + (unsigned)mode * 4u + 0x4cu);
        low = *(const float *)(table + (unsigned)action[1] * 0x10u + 0x20u);
        high = *(const float *)(table + (unsigned)action[1] * 0x10u + 0x24u);
        scale *= low + (high - low) * *(const float *)(action + 8u);
        *(float *)(state_bytes + 0x1d0u) = 0.0f;
    }
    StateParameterReset_0058626C(
        state_bytes + 0x120u, target, selector, payload,
        scale, payload[0]);
    return selector;
}
__attribute__((noinline)) void ActorActionRecordInitialize(uint8_t *record, float scalar)
{
    uint32_t flags;
    record[0] = 0x11u;
    record[1] = 0u;
    record[2] = 3u;
    record[3] = 3u;
    record[4] = 0u;
    *(float *)(record + 8u) = scalar;
    *(float *)(record + 0x0cu) = ActorZeroDirection_00DC24B4[0];
    *(float *)(record + 0x10u) = ActorZeroDirection_00DC24B4[1];
    *(float *)(record + 0x14u) = ActorZeroDirection_00DC24B4[2];
    record[0x1c] = 0u;
    record[0x1d] &= 0xc0u;
    flags = *(uint32_t *)(record + 0x18u);
    *(uint32_t *)(record + 0x18u) = flags | 0xfffffe00u;
}
void ActorEffectQueueSeed(void *actor)
{
    uint8_t *object = (uint8_t *)actor;
    void *queue = object + 0x450u;
    const uint32_t pattern = 0xc0c0c0ffu;
    const uint32_t rotated_pattern =
        pattern & ((pattern >> 31u) | (pattern << 1u));
    EffectQueueReset(object + 0xf0u, 3u);
    EffectQueueAppend(queue, 0u, 4u, UINT32_MAX, 0.4f);
    EffectQueueAppend(queue, 0u, 2u, pattern, 0.4f);
    EffectQueueAppend(queue, 0u, 2u, rotated_pattern, 0.4f);
    EffectQueueAppend(queue, 4u, 4u, UINT32_MAX, 0.3f);
    EffectQueueAppend(queue, 0u, 2u, pattern, 0.3f);
    EffectQueueAppend(queue, 0u, 2u, rotated_pattern, 0.3f);
    EffectQueueAppend(queue, 4u, 4u, UINT32_MAX, 0.15f);
    EffectQueueAppend(queue, 0u, 2u, pattern, 0.15f);
    EffectQueueAppend(queue, 0u, 2u, rotated_pattern, 0.15f);
    EffectQueueAppend(queue, 4u, 4u, UINT32_MAX, 0.05f);
    EffectQueueAppend(queue, 0u, 2u, pattern, 0.05f);
    EffectQueueAppend(queue, 0u, 2u, rotated_pattern, 0.05f);
}
__attribute__((noinline)) void *ActorStatusLinkDescriptor_Resolve(void *actor)
{
    uint8_t *object = (uint8_t *)actor;
    uint8_t *entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
        object + 0x1a4u, GetStatusLinkDescriptor());
    uint8_t *upper = *(uint8_t **)(object + 0x1a8u);
    if (entry == 0 || *(uint8_t **)entry == upper)
        return 0;
    return *(void **)entry;
}
int ActorStatusAdmission(void *actor, void *target)
{
    uint8_t *actor_bytes = (uint8_t *)actor;
    uint8_t *target_bytes = (uint8_t *)target;
    uint8_t *object = *(uint8_t **)(actor_bytes + 0x30u);
    uint8_t *active_state = *(uint8_t **)(object + 0x168u);
    uint8_t *status = (uint8_t *)ActorStatusComponent_004C5204();
    uint8_t *entry;
    uint8_t *upper;
    uint8_t *descriptor;
    if (*(uint32_t *)(active_state + 8u) != 0x00c9b95cu || status == 0)
        return 0;
    if (*(uint8_t *)(status + 0x60u) == 0x10u) {
        if (StatusChannelIsActive(target, 2u) != 0 ||
            StatusChannelIsActive(target, 1u) == 0)
            return 0;
    } else if (StatusChannelIsActive(target, 0u) == 0) {
        return 0;
    }
    entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
        target_bytes + 0x1a4u, GetStatusDescriptorRegistry());
    upper = *(uint8_t **)(target_bytes + 0x1a8u);
    descriptor = (entry != 0 && *(uint8_t **)entry != upper)
        ? *(uint8_t **)entry : 0;
    if (descriptor != 0 && descriptor[0x109] != 0)
        return 0;
    return 1;
}
__attribute__((noinline)) int ActorStateHasEligibleClass(void *actor)
{
    uint8_t *state = *(uint8_t **)((uint8_t *)actor + 0x16cu);
    uint32_t class_key;
    if (state == 0)
        return 0;
    class_key = *(uint32_t *)(state + 8u);
    return class_key == 0x00c9b988u || class_key == 0x00c9b98cu;
}
__attribute__((noinline)) unsigned ActorStateClassPredicate(void *object, unsigned mode)
{
    const struct ActorObjectView *view =
        (const struct ActorObjectView *)object;
    uint32_t class_key = *(uint32_t *)((uint8_t *)view->active_state + 8u);
    unsigned first = class_key == 0x00c9b964u || class_key == 0x00c9b9acu;
    unsigned second = class_key == 0x00c9b968u ||
                      class_key == 0x00c9b96cu ||
                      class_key == 0x00c9b9b0u;
    return (mode & ~first) == 0 ? first : second;
}
__attribute__((noinline)) int ActorStatusHasNonnegativeRelatedValue(void *target)
{
    uint8_t *descriptor = (uint8_t *)ResolveCachedComponent_1EC(target);
    uint8_t *related;
    if (descriptor == 0)
        return 0;
    related = *(uint8_t **)(descriptor + 0x2cu);
    if (related == 0)
        return 0;
    return (*(int32_t *)(related + 0xfccu) >> 31) + 1;
}
static uint8_t *ActorStateResolveHealthDescriptor(void *target)
{
    uint8_t *target_bytes = (uint8_t *)target;
    uint8_t *descriptor = *(uint8_t **)(target_bytes + 0x1e4u);
    if (descriptor == 0) {
        uint8_t *entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            target_bytes + 0x1a4u,
            EngineLazySingletonGetter_00498828());
        uint8_t *upper = *(uint8_t **)(target_bytes + 0x1a8u);
        descriptor = entry != 0 && *(uint8_t **)entry != upper
            ? *(uint8_t **)entry : 0;
        if (descriptor != 0) {
            *(void **)(descriptor + 0x1cu) = target;
            *(uint8_t **)(target_bytes + 0x1e4u) = descriptor;
        }
    }
    return descriptor;
}
static uint32_t ActorStateHealthRandomNext(void *random_object,
                                             unsigned preserve_first_word)
{
    uint32_t *state = (uint32_t *)((uint8_t *)random_object + 0x10u);
    uint32_t x = state[0];
    uint32_t w = state[3];
    uint32_t next;
    if (!preserve_first_word)
        state[0] = state[1];
    state[1] = state[2];
    state[2] = w;
    x ^= x << 11;
    next = x ^ (x >> 8) ^ w ^ (w >> 19);
    state[3] = next;
    return next;
}
static void *ActorStateHealthRandomObject(void)
{
    static void **random_slot = (void **)(uintptr_t)0x00d63548u;
    if (*random_slot == 0)
        *random_slot = HealthRandomSingleton();
    return *random_slot;
}
static float ActorStateHealthRandomAngle(void *random_object,
                                          unsigned preserve_first_word)
{
    uint32_t next = ActorStateHealthRandomNext(random_object,
                                                preserve_first_word);
    const uint64_t multiplier = 0x5b05b05bull;
    uint32_t quotient = (uint32_t)
        ((((uint64_t)next * multiplier) + multiplier) >> 39);
    return (float)(next - quotient * 360u) * 0.01745329238474369f;
}
static void ActorStateHealthThresholdBody(void *record, void *target)
{
    uint8_t *record_bytes = (uint8_t *)record;
    uint8_t *descriptor;
    uint8_t *payload;
    record_bytes[0] = 5u;
    descriptor = ActorStateResolveHealthDescriptor(target);
    if (descriptor == 0 || *(void **)(descriptor + 0x24u) == 0)
        return;
    payload = *(uint8_t **)(descriptor + 0x24u);
    *(float *)(payload + 0x74u) = ActorHealthFallbackVector_00DC249C[0];
    *(float *)(payload + 0x78u) = ActorHealthFallbackVector_00DC249C[1];
    *(float *)(payload + 0x7cu) = ActorHealthFallbackVector_00DC249C[2];
    *(float *)(record_bytes + 0x14u) = 50.0f;
    *(float *)(record_bytes + 0x18u) = 0.0f;
}
__attribute__((noinline)) void ActorStateHealthStatusUpdate(void *record, void *target,
                                     void *frame_context)
{
    uint8_t *record_bytes = (uint8_t *)record;
    const uint8_t *frame_bytes = (const uint8_t *)frame_context;
    int32_t delta_bits = *(const int32_t *)(frame_bytes + 0x0cu);
    float delta;
    float threshold;
    float elapsed;
    float lane0;
    float lane1;
    float lane2;
    float scale;
    int apply_scale = 1;
    void *random_object;
    uint8_t *descriptor;
    if (record_bytes[0] == 5u || delta_bits <= 0x37800000)
        return;
    delta = *(const float *)(frame_bytes + 0x0cu);
    threshold = *(float *)(record_bytes + 8u);
    elapsed = *(float *)(record_bytes + 0xcu) + delta;
    *(float *)(record_bytes + 0xcu) = elapsed;
    if (elapsed > threshold) {
        ActorStateHealthThresholdBody(record, target);
        return;
    }
    descriptor = ActorStateResolveHealthDescriptor(target);
    if (descriptor == 0 || *(void **)(descriptor + 0x24u) == 0)
        return;
    lane0 = 0.01745329238474369f;
    lane1 = ActorHealthFallbackPair_00DC24A0[0];
    lane2 = ActorHealthFallbackPair_00DC24A0[1];
    random_object = 0;
    if (record_bytes[0x1cu] != 0u && record_bytes[0] == 3u) {
        float angle = ActorStateHealthStatusParameterUpdate(
            record, descriptor, delta);
        lane0 = TrigKernel_0049A9DC(angle);
        lane1 = TrigKernel_00474934(angle);
    } else if (record_bytes[0x1cu] != 0u) {
        random_object = ActorStateHealthRandomObject();
        float first = ActorStateHealthRandomAngle(random_object, 1u);
        float second = ActorStateHealthRandomAngle(random_object, 0u);
        float sin_first = TrigKernel_00474934(first);
        float cos_second = TrigKernel_0049A9DC(second);
        float cos_first = TrigKernel_0049A9DC(first);
        float sin_second = TrigKernel_00474934(second);
        lane0 = sin_first * cos_second;
        lane1 = cos_first;
        lane2 = sin_first * sin_second;
    } else if (record_bytes[0] == 3u) {
        float angle = ActorStateHealthStatusParameterUpdate(
            record, descriptor, delta);
        lane0 = TrigKernel_0049A9DC(angle);
        lane2 = TrigKernel_00474934(angle);
    } else {
        random_object = ActorStateHealthRandomObject();
        float angle = ActorStateHealthRandomAngle(random_object, 1u);
        lane0 = TrigKernel_0049A9DC(angle);
        lane2 = TrigKernel_00474934(angle);
    }
    switch (record_bytes[0]) {
    case 0:
        scale = *(float *)(record_bytes + 4u);
        break;
    case 1:
        scale = (1.0f - elapsed / threshold) *
                *(float *)(record_bytes + 4u);
        break;
    case 2:
        scale = (elapsed / threshold) * *(float *)(record_bytes + 4u);
        break;
    case 3:
        scale = (0.7f + (1.0f - *(float *)(record_bytes + 0x14u) /
                         *(float *)(record_bytes + 0x10u)) * 0.3f) *
                *(float *)(record_bytes + 4u);
        break;
    default:
        apply_scale = 0;
        break;
    }
    {
        uint8_t *payload = *(uint8_t **)(descriptor + 0x24u);
        if (apply_scale) {
            lane0 *= scale;
            lane1 *= scale;
            lane2 *= scale;
        }
        *(float *)(payload + 0x74u) = lane0;
        *(float *)(payload + 0x78u) = lane1;
        *(float *)(payload + 0x7cu) = lane2;
    }
}
__attribute__((noinline)) void ActorStateConditionEventBatchRefresh(void *records, void *target,
                                             void *frame_context)
{
    static void **registry_slot = (void **)(uintptr_t)0x00d6385cu;
    uint8_t *target_bytes = (uint8_t *)target;
    uint8_t *descriptor = *(uint8_t **)(target_bytes + 0x1e4u);
    int marker = 0;
    uint8_t *node;
    uint8_t *upper;
    uint8_t *payload;
    uint8_t *registry;
    float delta = *(const float *)((const uint8_t *)frame_context + 0x0cu);
    if (descriptor == 0) {
        node = (uint8_t *)OrderedTreeLowerBoundByPointer(
            target_bytes + 0x1a4u,
            EngineLazySingletonGetter_00498828());
        upper = *(uint8_t **)(target_bytes + 0x1a8u);
        descriptor = node != 0 ? *(uint8_t **)node : 0;
        if (descriptor == upper)
            descriptor = 0;
        if (descriptor != 0) {
            *(void **)(descriptor + 0x1cu) = target;
            *(uint8_t **)(target_bytes + 0x1e4u) = descriptor;
        }
    }
    if (descriptor != 0 && *(void **)(descriptor + 0x24u) != 0) {
        payload = *(uint8_t **)(descriptor + 0x24u);
        marker = *(int8_t *)(payload + 0xb5u);
    }
    for (unsigned index = 0; index < 4u; ++index) {
        uint8_t *entry = (uint8_t *)records + index * 0x10u;
        uint32_t handle = *(uint32_t *)(entry + 0x0cu);
        uint32_t *table;
        unsigned table_index = (handle & 0xffffu) >> 8;
        uint32_t argument;
        registry = (uint8_t *)*registry_slot;
        if (registry == 0) {
            registry = (uint8_t *)EngineSharedObjectSingleton();
            *registry_slot = registry;
        }
        table = (uint32_t *)(registry + 0x324u);
        if (table[table_index * 3u] != handle) {
            *(uint32_t *)(entry + 4u) = UINT32_MAX;
            *(float *)(entry + 8u) = 0.0f;
        } else {
            *(float *)(entry + 8u) -= delta;
            if (*(float *)(entry + 8u) <= 0.0f) {
                argument = handle;
                EngineEventRegistryBroadcast(registry, &argument);
                *(uint32_t *)(entry + 4u) = UINT32_MAX;
                *(uint32_t *)(entry + 0xcu) = 0u;
            }
        }
        registry = (uint8_t *)*registry_slot;
        if (registry == 0) {
            registry = (uint8_t *)EngineSharedObjectSingleton();
            *registry_slot = registry;
        }
        handle = *(uint32_t *)(entry + 0xcu);
        table_index = (handle & 0xffffu) >> 8;
        table = (uint32_t *)(registry + 0x324u);
        if (table[table_index * 3u] == handle) {
            argument = handle;
            EngineEventRegistryDispatchArg(registry, &argument, marker);
        }
    }
}
__attribute__((noinline)) void ActorStateConditionEventRefresh(void *record,
                                        void *target,
                                        void *unused,
                                        const struct FrameContextView *frame)
{
    uint8_t *record_bytes = (uint8_t *)record;
    uint8_t *target_bytes = (uint8_t *)target;
    uint8_t *descriptor;
    uint8_t *entry;
    uint8_t *upper;
    void *dispatcher;
    void *engine;
    uint16_t descriptor_type;
    uint32_t event_handle;
    uint32_t payload[10] = { 0 };
    (void)unused;
    dispatcher = EngineLazySingletonGetter_003FD6E0();
    event_handle = *(uint32_t *)(record_bytes + 4u);
    if (EffectEventHandleResolver_00566F0C(dispatcher, event_handle) != 0) {
        *(uint32_t *)(payload + 7) = *(uint32_t *)(target_bytes + 0x54u);
        *(uint32_t *)(payload + 8) = *(uint32_t *)(target_bytes + 0x58u);
        *(uint32_t *)(payload + 9) = *(uint32_t *)(target_bytes + 0x5cu);
        *(uint32_t *)((uint8_t *)payload + 0x0cu) = 1u;
        *(uint32_t *)((uint8_t *)payload + 0x18u) = 1u;
        EngineRecordPoolWrite_004B275C(
            (uint8_t *)dispatcher + 0x2148u, event_handle, payload);
    }
    engine = ActorMovementEngineGet_004C59C0();
    if (*(const float *)((const uint8_t *)frame + 8u) <
        *(const float *)((const uint8_t *)engine + 0x668u)) {
        record_bytes[9] = 1;
        return;
    }
    if (record_bytes[9] == 0)
        return;
    descriptor = *(uint8_t **)(target_bytes + 0x1e4u);
    if (descriptor == 0) {
        entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            target_bytes + 0x1a4u,
            EngineLazySingletonGetter_00498828());
        upper = *(uint8_t **)(target_bytes + 0x1a8u);
        descriptor = (entry != 0 && *(uint8_t **)entry != upper)
            ? *(uint8_t **)entry : 0;
        if (descriptor != 0) {
            *(void **)(descriptor + 0x1cu) = target;
            *(uint8_t **)(target_bytes + 0x1e4u) = descriptor;
        }
    }
    if (descriptor == 0)
        return;
    descriptor_type = *(uint16_t *)(descriptor + 0x20u);
    if (descriptor_type != 1u && descriptor_type != 2u)
        return;
    engine = ActorMovementEngineGet_004C59C0();
    event_handle = EffectTableLookupSimpleVariant_005B30B0(
        (uint8_t *)engine + 0x4664u, descriptor_type == 2u);
    event_handle = EffectEventBuildAndSubmit_00550EE4(
        event_handle, (const uint32_t *)(target_bytes + 0x54u));
    *(uint32_t *)(record_bytes + 4u) = event_handle;
    record_bytes[9] = 0;
}
__attribute__((noinline)) void ActorStatePublishConditionTypeEvent(void *record,
                                             void *target,
                                             unsigned channel)
{
    uint8_t *target_bytes = (uint8_t *)target;
    uint8_t *descriptor = *(uint8_t **)(target_bytes + 0x1e4u);
    uint8_t *entry;
    uint8_t *upper;
    uint16_t descriptor_type;
    void *engine;
    uint32_t event_handle;
    (void)record;
    engine = ActorMovementEngineGet_004C59C0();
    if (descriptor == 0) {
        entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            target_bytes + 0x1a4u,
            EngineLazySingletonGetter_00498828());
        upper = *(uint8_t **)(target_bytes + 0x1a8u);
        descriptor = (entry != 0 && *(uint8_t **)entry != upper)
            ? *(uint8_t **)entry : 0;
        if (descriptor != 0) {
            *(void **)(descriptor + 0x1cu) = target;
            *(uint8_t **)(target_bytes + 0x1e4u) = descriptor;
        }
    }
    if (descriptor == 0)
        return;
    descriptor_type = *(uint16_t *)(descriptor + 0x20u);
    if (descriptor_type != 1u && descriptor_type != 2u)
        return;
    event_handle = EffectTableLookupModeVariant_005B30BC(
        (uint8_t *)engine + 0x4664u, channel, descriptor_type == 2u);
    EffectEventBuildAndSubmit_00550EE4(
        event_handle, (const uint32_t *)(target_bytes + 0x54u));
}
__attribute__((noinline)) void ActorStateConditionResourceUpdate(void *record,
                                          void *target,
                                          void *action,
                                          const uint32_t *context)
{
    uint8_t *record_bytes = (uint8_t *)record;
    void *dispatcher;
    void *engine;
    uint32_t handle;
    uint32_t channel = 0;
    uint32_t payload[10] = { 0 };
    *(uint32_t *)((uint8_t *)payload + 0x0cu) = 1u;
    *(uint32_t *)((uint8_t *)payload + 0x18u) = 1u;
    *(uint32_t *)(payload + 7) = *(uint32_t *)((uint8_t *)target + 0x54u);
    *(uint32_t *)(payload + 8) = *(uint32_t *)((uint8_t *)target + 0x58u);
    *(uint32_t *)(payload + 9) = *(uint32_t *)((uint8_t *)target + 0x5cu);
    ActorStateConditionEventRefresh(record, target, action,
                                        (const struct FrameContextView *)
                                            context);
    while (channel < 0x10u &&
           (context[1] & (1u << channel)) == 0u)
        ++channel;
    if (record_bytes[2] != (uint8_t)channel) {
        if (*(int32_t *)record_bytes != -1) {
            dispatcher = EngineLazySingletonGetter_003FD6E0();
            EffectEventReleasePool_0048D320(dispatcher);
            *(int32_t *)record_bytes = -1;
        }
        record_bytes[2] = (uint8_t)channel;
    }
    if (channel == 0x10u)
        return;
    if (*(int32_t *)record_bytes != -1) {
        dispatcher = EngineLazySingletonGetter_003FD6E0();
        EngineRecordPoolWrite_004B275C(
            (uint8_t *)dispatcher + 0x2148u,
            *(uint32_t *)record_bytes, payload);
        return;
    } else {
        engine = ActorMovementEngineGet_004C59C0();
        handle = EffectTableLookupVariant108_00592924(
            (uint8_t *)engine + 0x4664u, record_bytes[2]);
        *(uint32_t *)record_bytes = EffectEventBuildAndSubmit_00550EE4(
            handle, (const uint32_t *)((const uint8_t *)target + 0x54u));
    }
    dispatcher = EngineLazySingletonGetter_003FD6E0();
    if (EffectEventHandleResolver_00566F0C(
            dispatcher, *(uint32_t *)record_bytes) == 0) {
        *(int32_t *)record_bytes = -1;
        return;
    }
    engine = ActorMovementEngineGet_004C59C0();
    handle = EffectTableLookupVariantC8_0059290C(
        (uint8_t *)engine + 0x4664u, record_bytes[2]);
    EffectEventBuildAndSubmit_00550EE4(
        handle, (const uint32_t *)((const uint8_t *)target + 0x54u));
    if ((context[0] & 1u) == 0u)
        return;
    ActorStatePublishConditionTypeEvent(record, target, record_bytes[2]);
}
static uint32_t HashHeadN(void)
{
    static const char key[] = "HeadN";
    uint32_t hash = 0;
    unsigned i;
    for (i = 0; i < sizeof(key) - 1u; ++i) {
        int32_t character = (int8_t)key[i];
        hash ^= (uint32_t)character + (hash << 6) + (hash >> 2) +
                0x9e3779b9u;
    }
    return hash;
}
__attribute__((noinline)) void ActorStatePublishHeadN(void *state,
                               void *target,
                               const uint8_t *parameter_record,
                               unsigned publish_primary,
                               unsigned publish_secondary,
                               unsigned secondary_fallback)
{
    uint8_t *state_bytes = (uint8_t *)state;
    struct ActorObjectView *target_view =
        (struct ActorObjectView *)target;
    uint8_t *descriptor;
    uint8_t *entry;
    uint8_t *upper;
    uint8_t *engine;
    uint8_t *table_object;
    uint32_t generation;
    uint32_t expected;
    uint32_t *table_entry;
    uint32_t hash;
    if ((*(uint32_t *)(state_bytes + 0x174u) & 1u) == 0u &&
        *(int32_t *)(state_bytes + 0x134u) == -1)
        goto clear;
    engine = (uint8_t *)EngineLazySingletonGetter_0054EFA8();
    generation = *(uint32_t *)(engine + 0xb278u);
    expected = generation >> 9;
    if (expected == 0x7fffffu)
        goto clear;
    table_entry = (uint32_t *)(uintptr_t)(0x00e11614u +
                                           (generation & 0x1ffu) * 8u);
    if (table_entry[1] != expected || table_entry[0] == 0)
        goto clear;
    table_object = (uint8_t *)(uintptr_t)table_entry[0];
    descriptor = *(uint8_t **)(table_object + 0x1ecu);
    if (descriptor == 0) {
        entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            table_object + 0x1a4u, GetStatusDescriptorType());
        upper = *(uint8_t **)(table_object + 0x1a8u);
        descriptor = (entry != 0 && *(uint8_t **)entry != upper)
            ? *(uint8_t **)entry : 0;
        if (descriptor != 0) {
            *(void **)(descriptor + 0x1cu) = table_object;
            *(uint8_t **)(table_object + 0x1ecu) = descriptor;
        }
    }
    if (descriptor != 0 &&
        (*(uint32_t *)(descriptor + 0x94u) & 0x10000000u) == 0u)
        goto clear;
    if ((*(uint32_t *)(state_bytes + 0x1dcu) & 6u) != 0u)
        goto clear;
    descriptor = (uint8_t *)target_view->cached_status_descriptor;
    if (descriptor == 0) {
        entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            &target_view->component_tree_anchor,
            GetStatusDescriptorType());
        upper = (uint8_t *)target_view->component_tree_upper;
        descriptor = (entry != 0 && *(uint8_t **)entry != upper)
            ? *(uint8_t **)entry : 0;
        if (descriptor != 0) {
            *(void **)(descriptor + 0x1cu) = target;
            target_view->cached_status_descriptor = descriptor;
        }
    }
    if (descriptor != 0 &&
        (*(uint32_t *)(descriptor + 0x98u) & 0x00400000u) != 0u)
        goto clear;
    hash = HashHeadN();
    if (publish_primary != 0) {
        StateParameterPublish_00586390(
            state_bytes + 0x130u, target,
            *(uint32_t *)(parameter_record + 0x234u),
            (const uint32_t *)(uintptr_t)0x00dc249cu, &hash,
            1.0f, 0.5f);
        return;
    }
    if (publish_secondary == 0)
        publish_secondary = secondary_fallback;
    if (publish_secondary != 0) {
        StateParameterPublish_00586390(
            state_bytes + 0x130u, target,
            *(uint32_t *)(parameter_record + 0x238u),
            (const uint32_t *)(uintptr_t)0x00dc249cu, &hash,
            1.0f, 0.5f);
        return;
    }
clear:
    StateParameterClear_0058665C(state_bytes + 0x130u);
}
__attribute__((noinline)) int ActorStateDescriptorAdmission(void *descriptor, void *target)
{
    uint8_t *target_bytes = (uint8_t *)target;
    struct ActorObjectView *descriptor_view =
        (struct ActorObjectView *)descriptor;
    struct ActorObjectView *table_view;
    uint8_t *first;
    uint8_t *table_object;
    uint8_t *second;
    uint8_t *entry;
    uint8_t *upper;
    uint32_t generation;
    uint32_t expected;
    uint32_t index;
    uint32_t *table_entry;
    first = (uint8_t *)descriptor_view->cached_status_descriptor;
    if (first == 0) {
        entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            &descriptor_view->component_tree_anchor,
            GetStatusDescriptorType());
        upper = (uint8_t *)descriptor_view->component_tree_upper;
        first = (entry != 0 && *(uint8_t **)entry != upper)
            ? *(uint8_t **)entry : 0;
        if (first != 0) {
            *(void **)(first + 0x1cu) = descriptor;
            descriptor_view->cached_status_descriptor = first;
        }
    }
    if (first == 0)
        return 0;
    generation = *(uint32_t *)(target_bytes + 0x24u);
    expected = generation >> 9;
    if (expected == 0x7fffffu)
        return 0;
    index = generation & (0x7fffffu >> 14);
    table_entry = (uint32_t *)(uintptr_t)(0x00e11614u + index * 8u);
    if (table_entry[1] != expected || table_entry[0] == 0)
        return 0;
    table_object = (uint8_t *)(uintptr_t)table_entry[0];
    table_view = (struct ActorObjectView *)table_object;
    second = (uint8_t *)table_view->cached_status_descriptor;
    if (second == 0) {
        entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            &table_view->component_tree_anchor,
            GetStatusDescriptorType());
        upper = (uint8_t *)table_view->component_tree_upper;
        second = (entry != 0 && *(uint8_t **)entry != upper)
            ? *(uint8_t **)entry : 0;
        if (second != 0) {
            *(void **)(second + 0x1cu) = table_object;
            table_view->cached_status_descriptor = second;
        }
    }
    if (second == 0)
        return 0;
    if (*(uint32_t *)((uint8_t *)table_view->active_state + 8u) ==
        *(uint32_t *)(uintptr_t)0x00c9b96cu)
        return 1;
    {
        uint8_t *active = (uint8_t *)descriptor_view->active_state;
        uint8_t *pending = (uint8_t *)descriptor_view->pending_state;
        uint32_t state_key = *(uint32_t *)(active + 8u);
        if (state_key != *(uint32_t *)(uintptr_t)0x00c9b96cu &&
            (pending == 0 ||
             *(uint32_t *)(pending + 8u) !=
                 *(uint32_t *)(uintptr_t)0x00c9b96cu))
            return 0;
        if (state_key == *(uint32_t *)(uintptr_t)0x00c9b974u)
            return 0;
    }
    generation = *(uint32_t *)(first + 0x44u);
    expected = generation >> 9;
    if (expected != 0x7fffffu) {
        index = generation & (0x7fffffu >> 14);
        table_entry = (uint32_t *)(uintptr_t)(0x00e11614u + index * 8u);
        if (table_entry[1] == expected && table_entry[0] != 0 &&
            table_entry[0] == (uint32_t)(uintptr_t)table_object &&
            StatusComponentHasBit00800000(descriptor) != 0 &&
            ActorStateClassPredicate(descriptor, 1u) != 0)
            return 1;
    }
    {
        uint8_t *pending = (uint8_t *)descriptor_view->pending_state;
        if (pending != 0 &&
            *(uint32_t *)(pending + 8u) ==
                *(uint32_t *)(uintptr_t)0x00c9b970u)
            return 1;
    }
    return 0;
}
int ActorMovementResourceGate(void *actor, void *source, void *message)
{
    uint8_t *actor_bytes = (uint8_t *)actor;
    uint8_t *source_bytes = (uint8_t *)source;
    uint8_t *descriptor = *(uint8_t **)(actor_bytes + 0x208u);
    uint8_t *entry;
    uint8_t *upper;
    void *resolved;
    if (descriptor == 0) {
        entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            actor_bytes + 0x1a4u,
            ActorMovementDescriptorKey_00517CC4());
        upper = *(uint8_t **)(actor_bytes + 0x1a8u);
        descriptor = (entry != 0 && *(uint8_t **)entry != upper)
            ? *(uint8_t **)entry : 0;
        if (descriptor != 0) {
            *(void **)(descriptor + 0x34u) = actor;
            *(uint8_t **)(actor_bytes + 0x208u) = descriptor;
        }
    }
    resolved = ActorStatusLinkDescriptor_Resolve(actor);
    if (resolved != 0) {
        if (*(uint32_t *)(source_bytes + 0x58u) == 2u &&
            ResourceTableLookup((uint32_t *)((uint8_t *)resolved +
                                                0x54u)) != 0) {
            ActorStateMachine_DispatchMessage(
                (void *)(uintptr_t)ResourceTableLookup(
                    (uint32_t *)((uint8_t *)resolved + 0x54u)),
                source, message);
            if (descriptor != 0) {
                uint32_t mode = 0;
                void *source_data = *(void **)(source_bytes + 0x2cu);
                if (source_data != 0) {
                    void **vtable = *(void ***)source_data;
                    mode = ((uint32_t (*)(void *))
                        vtable[0x70u / sizeof(void *)])(source_data);
                    if (mode > 2u)
                        mode = 2u;
                }
                ActorMovementNotify_0059095C(
                    actor, 2u,
                    *(int8_t *)((uint8_t *)ActorMovementEngineGet_004C59C0() +
                                0x22au + mode));
            }
            return 1;
        }
        if (descriptor != 0)
            descriptor[0x78] = 0;
    }
    if (resolved != 0 &&
        DamagePacketBuildFlags(EngineLazySingletonGetter_0054EFA8()) ==
            *(uint32_t *)(source_bytes + 0x60u))
        *(float *)(source_bytes + 0x30u) *= 0.25f;
    return 0;
}
void ActorConditionRecordReset(uint8_t *record)
{
    record[0] = 0x4au;
    *(uint32_t *)(record + 4u) = 0u;
    *(uint32_t *)(record + 8u) = 0u;
}
void ActorStateClearConditionScratch(uint32_t scratch[2]);
__attribute__((noinline)) void ActorStateConditionType5ResourceReset(void *unused0, void *unused1,
                                             uint32_t value,
                                             uint32_t handle)
{
    void *descriptor;
    void *resource;
    (void)unused0;
    (void)unused1;
    descriptor = ActorStateConditionTargetGet_00520480();
    resource = descriptor != 0 ? *(void **)((uint8_t *)descriptor + 0x58) : 0;
    if (resource != 0)
        ActorStateResourceReset_0050519C(resource, 1u, value, handle);
}
__attribute__((noinline)) void ActorStateConditionTransitionDispatch(void *engine, void *target,
                                             unsigned selector,
                                             void *resource_context)
{
    uint8_t *descriptor = (uint8_t *)ResolveStatusDescriptor(target);
    uint8_t *related = (uint8_t *)ResolveRelatedComponent(target);
    uint32_t key;
    uint32_t result_flags = 0;
    if (related != 0)
        HealthNotifyModeZero(related, 0.0f);
    key = *(uint32_t *)(descriptor + 0x20u);
    if ((StatusContextGetFlags((uint8_t *)engine + 0xf98cu,
                               key) & 1u) != 0u)
        return;
    switch (key >> 28) {
    case 1u:
        result_flags = ActorStateConditionType1Handler(
            engine, target, selector == 7u ? 1u : 0u, resource_context);
        break;
    case 2u:
        if (ActorState_ConditionType2Gate(engine, target) != 0) {
            void *factory = ConditionFactoryDescriptor_004BFB7C();
            ActorStateMachineRequestStateByFactory(target, &factory);
            result_flags = 2u;
        }
        break;
    case 4u:
        if (related != 0 &&
            *(uint32_t *)(*(void **)((uint8_t *)target + 0x168u) + 8u) !=
                *(const uint32_t *)(uintptr_t)0x00c9b8ecu) {
            void *machine = *(void **)(related + 0x30u);
            void *factory = ConditionFactoryDescriptor_004897D0();
            ActorStateMachineRequestStateByFactory(machine, &factory);
        }
        result_flags = 2u;
        break;
    case 5u:
        ActorStateConditionType5ResourceReset(
            target, 0, selector, (uint32_t)(uintptr_t)resource_context);
        break;
    default:
        break;
    }
    if ((result_flags & 2u) != 0u)
        StatusContextSetFlags((uint8_t *)engine + 0xf98cu,
                              key, 1u);
    if ((result_flags & 1u) != 0u)
        EffectResourceNotify(engine, (uint32_t)(uintptr_t)target);
}
__attribute__((noinline)) int ActorStateSelectFromConditions(void *state, void *arg2, void *arg3,
                                      void *frame_context, float hidden_value)
{
    struct HealthStatusComponent *component =
        (struct HealthStatusComponent *)state;
    struct ActorObjectView *target_object =
        (struct ActorObjectView *)component->target;
    uint8_t *target = (uint8_t *)target_object;
    const struct FrameContextView *frame =
        (const struct FrameContextView *)frame_context;
    uint8_t *descriptor;
    uint8_t *owner;
    uint32_t flags;
    uint32_t events;
    uint32_t local_owner_bit = 0;
    int condition_type_2 = 0;
    int condition_type_3 = 0;
    int owner_flag_40 = 0;
    int owner_flag_80 = 0;
    int allow_secondary_update = 1;
    float live_s0 = 0.0f;
    int8_t next_state = 0x4a;
    int8_t next_secondary_state = 0x4a;
    unsigned channel;
    (void)arg2;
    (void)arg3;
    descriptor = (uint8_t *)target_object->cached_component_descriptor;
    if (descriptor == 0) {
        uint8_t *entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            &target_object->component_tree_anchor,
            ComponentType_GetStatusDescriptor_004DC14C());
        uint8_t *upper = (uint8_t *)target_object->component_tree_upper;
        if (entry != 0 && *(uint8_t **)entry != upper) {
            descriptor = *(uint8_t **)entry;
            if (descriptor != 0) {
                *(void **)(descriptor + 0x1c) = target;
                target_object->cached_component_descriptor = descriptor;
            }
        }
    }
    if (descriptor != 0 && component->status_timer > 0.0f) {
        float remaining = component->status_timer - frame->delta_time;
        component->status_timer = remaining;
        live_s0 = remaining;
        if (remaining <= 0.0f)
            ComponentNotifyStatusChange(
                *(void **)(descriptor + 0x20), 1u);
    }
    flags = component->flags;
    if ((int32_t)component->current_hp.bits < (int32_t)0x37800000u) {
        void *engine = EngineLazySingletonGetter_0054EFA8();
        if ((StatusConditionAdmissionCode(engine, target) & 1u) != 0) {
            ActorStateConditionTransitionDispatch(engine, target, 0u, arg3);
            for (channel = 0; channel < 12; ++channel) {
                component->buildup[channel] = 0.0f;
                if ((component->active_mask & (1u << channel)) == 0)
                    continue;
                if ((flags & 2u) != 0)
                    StatusChannelExpireAlternate(state, target, channel,
                                                 hidden_value);
                else if ((flags & 1u) != 0)
                    StatusChannelExpire(state, target, channel);
            }
        }
    }
    if ((flags & 1u) != 0) {
        void *registry = StatusRegistrySingletonGet();
        if (ActorGenerationHandlePresent(registry)) {
            for (channel = 0; channel < 12; ++channel) {
                component->buildup[channel] = 0.0f;
                if ((component->active_mask & (1u << channel)) == 0)
                    continue;
                if ((flags & 2u) != 0)
                    StatusChannelExpireAlternate(state, target, channel,
                                                 hidden_value);
                else if ((flags & 1u) != 0)
                    StatusChannelExpire(state, target, channel);
            }
            if (component->deferred_state != 0)
                HealthSecondaryReset(component->deferred_state, target);
        }
    }
    if ((flags & 1u) != 0 &&
        ActorStatusHasNonnegativeRelatedValue(target) != 0)
        allow_secondary_update = 0;
    if (allow_secondary_update)
        StatusChannelUpdateTimers(state, target, frame_context);
    live_s0 = 1.0f;
    if (component->deferred_state != 0 && allow_secondary_update) {
        unsigned phase = HealthSecondaryStateClassify(
            component->deferred_state, target, frame_context);
        switch (phase) {
        case 0:
            Health_StatusBitUpdate(state, 0x2000u, 0);
            Health_StatusBitUpdate(state, 0x4000u, 0);
            live_s0 = HealthClampCurrent(component->current_hp.value,
                                             1.0f, component->maximum_hp.value);
            break;
        case 1:
            Health_StatusBitUpdate(state, 0x2000u, 1);
            Health_StatusBitUpdate(state, 0x4000u, 1);
            live_s0 = HealthClampCurrent(component->current_hp.value,
                                             1.0f, component->maximum_hp.value);
            break;
        case 2:
            Health_StatusBitUpdate(state, 0x2000u, 1);
            Health_StatusBitUpdate(state, 0x4000u, 0);
            live_s0 = HealthClampCurrent(component->current_hp.value,
                                             1.0f, component->maximum_hp.value);
            break;
        case 3:
            Health_StatusBitUpdate(state, 0x2000u, 0);
            Health_StatusBitUpdate(state, 0x4000u, 0);
            break;
        default:
            break;
        }
    }
    descriptor = (uint8_t *)target_object->cached_status_descriptor;
    if (descriptor == 0) {
        uint8_t *entry = (uint8_t *)OrderedTreeLowerBoundByPointer(
            &target_object->component_tree_anchor, GetActorStatusDescriptorKey());
        uint8_t *upper = (uint8_t *)target_object->component_tree_upper;
        if (entry != 0 && *(uint8_t **)entry != upper) {
            descriptor = *(uint8_t **)entry;
            if (descriptor != 0) {
                *(void **)(descriptor + 0x1c) = target;
                target_object->cached_status_descriptor = descriptor;
            }
        }
    }
    if (descriptor != 0) {
        uint8_t *status_descriptor = (uint8_t *)
            OrderedTreeLowerBoundByPointer(
                &target_object->component_tree_anchor,
                GetStatusDescriptorRegistry());
        if (status_descriptor != 0 &&
            *(uint8_t **)status_descriptor != target_object->component_tree_upper) {
            status_descriptor = *(uint8_t **)status_descriptor;
            condition_type_2 =
                target_object->active_state != 0 &&
                *(uint32_t *)((uint8_t *)target_object->active_state + 8) ==
                    *(const uint32_t *)(uintptr_t)
                        TARGET_DESCRIPTOR_CONDITION_KEY;
            ActorConditionNoOp();
            condition_type_3 = live_s0 < LIVE_S0_CONDITION_THRESHOLD;
        }
        local_owner_bit = (*(uint32_t *)(descriptor + 0x94) & 0x400u) >> 10;
    }
    owner = (uint8_t *)ComponentLookupStatusOwner(
        StatusRegistrySingletonGet(), target);
    if (owner != 0) {
        owner_flag_40 = (*(uint32_t *)(owner + 0xad8) & 0x40u) != 0;
        owner_flag_80 = (*(uint32_t *)(owner + 0xad8) & 0x80u) != 0;
    }
    events = component->active_mask;
    flags = component->flags;
    for (channel = 0; channel < 11; ++channel) {
        const struct StateCondition *condition =
            &main_state_conditions[channel];
        int matched = 0;
        switch (condition->type) {
        case CONDITION_FLAGS:
            matched = (condition->mask & flags) != 0;
            break;
        case CONDITION_EVENTS:
            matched = (condition->mask & events) != 0;
            break;
        case CONDITION_TARGET_DESCRIPTOR:
            matched = condition_type_2;
            break;
        case CONDITION_LIVE_S0_BELOW_THRESHOLD:
            matched = condition_type_3;
            break;
        case CONDITION_OWNER_FLAG_40:
            matched = owner_flag_40;
            break;
        case CONDITION_OWNER_FLAG_80:
            matched = owner_flag_80;
            break;
        default:
            break;
        }
        if (matched) {
            next_state = (int8_t)condition->state;
            break;
        }
    }
    if ((int8_t)component->primary_condition_state[0] != next_state) {
        if (next_state == 0x4a)
            StatusStateReturnToIdle(component->primary_condition_state);
        else
            StatusStateTransition(component->primary_condition_state);
    }
    for (channel = 0; channel < 2; ++channel) {
        const struct StateCondition *condition =
            &secondary_state_conditions[channel];
        int matched = condition->type == CONDITION_EVENTS
            ? (condition->mask & events) != 0 : 0;
        if (matched) {
            next_secondary_state = (int8_t)condition->state;
            break;
        }
    }
    if ((int8_t)component->secondary_condition_state[0] !=
        next_secondary_state) {
        if (next_secondary_state == 0x4a)
            StatusStateReturnToIdle(component->secondary_condition_state);
        else
            StatusStateTransition(component->secondary_condition_state);
    }
    {
        void *engine = ActorStateEngineGet();
        float dt = frame->delta_time;
        union FloatBits health_ratio;
        uint32_t condition_context[3];
        ActorStateConditionPreUpdate(component->auxiliary_state, target,
                                         frame_context);
        ActorStateClearConditionScratch(condition_context);
        health_ratio.value = component->current_hp.value /
                             component->maximum_hp.value;
        condition_context[0] = component->flags;
        condition_context[1] = component->active_mask;
        condition_context[2] = health_ratio.bits;
        ActorStateConditionResourceUpdate(
            (uint8_t *)state + 0x164u, target, frame_context,
            condition_context);
        ActorStateUpdateActiveChannel(state, target,
                                          (uint8_t *)engine + 0x4924);
        ActorStatePublishHeadN(state, target, (uint8_t *)engine + 0x4924,
                                  local_owner_bit, (unsigned)condition_type_2,
                                  (unsigned)condition_type_3);
        ActorStateConditionEventBatchRefresh(
            (uint8_t *)state + 0x120u, target, frame_context);
        component->elapsed += dt;
        ActorStateHealthStatusUpdate(component->movement_state, target,
                                         frame_context);
    }
    return 0;
}
__attribute__((noinline)) void ActorStateClearConditionScratch(uint32_t scratch[2])
{
    scratch[0] = 0;
    scratch[1] = 0;
}
extern void *ConditionSingletonGet(void);
extern uint32_t ConditionVariantLookup(void *table, uint8_t variant);
extern void ConditionPublishRecord(uint32_t value, void *destination);
void ActorStateConditionPublish(void *unused, void *descriptor,
                                   uint8_t *record, const uint8_t *action)
{
    void *engine;
    (void)unused;
    if ((record[0x1c] & 0x20u) != 0u)
        return;
    engine = ConditionSingletonGet();
    if ((record[0x1d] & 1u) != 0u) {
        uint32_t value = ConditionVariantLookup(
            (uint8_t *)engine + 0x4664u, record[2]);
        ConditionPublishRecord(value, (uint8_t *)descriptor + 0x54u);
    } else if (1.0000152588f < *(const float *)(action + 0x38u)) {
        ConditionPublishRecord(
            *(const uint32_t *)((uint8_t *)engine + 0x4920u),
            (uint8_t *)descriptor + 0x54u);
    }
}
extern void ActorPlayActionByHash(void *action, unsigned mode,
                                      void *parameters, unsigned flags,
                                      unsigned start);
extern void *ActionDataResolve(void *action, void *key);
extern int MovementState_ResetOwnerState_004E6968(void *owner);
extern void *StatusRegistrySingletonGet(void);
extern void *StatusOwnerLookupByHandle(void *registry, uint32_t handle);
extern void StatusOwnerApplyEvent(void *action, unsigned mode,
                                     unsigned flag);
extern void *EngineSingletonGet(void);
extern int DodgeGlobalGate(void);
struct DodgeTransform {
    float words[12];
};
typedef char kiu_sa_actor_state_machine_2[(sizeof(struct DodgeTransform) == 0x30) ? 1 : -1] __attribute__((unused));
void DodgeApplyTransformSideEffect(void *owner_context, void *action)
{
    uint8_t *action_bytes = (uint8_t *)action;
    uint8_t *resolved = (uint8_t *)ResolveStatusDescriptor(action);
    struct DodgeTransform transform;
    uint32_t result = 0;
    void *owner;
    float q1;
    float q2;
    float q3;
    float q4;
    float two_q1;
    float two_q2;
    float two_q3;
    float scale;
    float a;
    float b;
    float c;
    float d;
    float e;
    if (resolved == 0 || (*(uint32_t *)(resolved + 0x20) >> 28) != 1u)
        return;
    owner = StatusOwnerIndexAddress(
        (uint8_t *)owner_context + 0xb3f8,
        *(uint8_t *)(resolved + 0x2c));
    StatusChannelResetOrReplace(owner_context, 0x15u, 0u);
    q1 = *(float *)(action_bytes + 0x64);
    q2 = *(float *)(action_bytes + 0x68);
    q3 = *(float *)(action_bytes + 0x6c);
    q4 = *(float *)(action_bytes + 0x70);
    scale = *(float *)(action_bytes + 0x60);
    two_q1 = q1 * 2.0f;
    two_q2 = q2 * 2.0f;
    two_q3 = q3 * 2.0f;
    a = 1.0f - two_q1 * q1;
    b = q3 * 2.0f * q4;
    c = two_q3 * q3;
    d = q2 * 2.0f * q4;
    e = q2 * 2.0f * q2;
    transform.words[0] = (1.0f - e - c) * scale;
    transform.words[1] = (two_q1 * q2 - b) * scale;
    transform.words[2] = (two_q1 * q3 + d) * scale;
    transform.words[3] = *(float *)(action_bytes + 0x74);
    transform.words[4] = (two_q1 * q2 + b) * scale;
    transform.words[5] = (1.0f - two_q1 * q1 - c) * scale;
    transform.words[6] = (two_q2 * q3 - two_q1 * q4) * scale;
    transform.words[7] = *(float *)(action_bytes + 0x78);
    transform.words[8] = (two_q1 * q3 - d) * scale;
    transform.words[9] = (two_q2 * q3 + two_q1 * q4) * scale;
    transform.words[10] = (a - e) * scale;
    transform.words[11] = *(float *)(action_bytes + 0x7c);
    DodgeTransformDispatch(&result, 0x2ef9u, &transform, 0u, 0u);
    if (--*(int32_t *)((uint8_t *)owner + 0x704) < 1)
        StatusOwner_TightenThreshold((uint8_t *)owner + 0x2d8,
                                        8u, 0.0f);
}
__attribute__((noinline)) int PlayerDodgeStateEnter(void *state, void *context)
{
    uint8_t *state_bytes = (uint8_t *)state;
    uint8_t *context_bytes = (uint8_t *)context;
    void *action = *(void **)(state_bytes + 0x30);
    void *action_data;
    MovementState_ResetOwnerState_004E6968(state);
    ActorPlayActionByHash(action, 1u, context_bytes + 0x28, 1u, 1u);
    action_data = ActionDataResolve(action, (void *)(uintptr_t)0x004bea28u);
    if (action_data != 0) {
        *(uint32_t *)(context_bytes + 0x34) =
            *(uint32_t *)((uint8_t *)action_data + 0x74);
        if (context_bytes[0x3c] != 0) {
            void *registry = StatusRegistrySingletonGet();
            void *target = StatusOwnerLookupByHandle(
                registry, *(uint32_t *)(*(void **)(state_bytes + 0x38) + 0x5c));
            if (target != 0) {
                float dx = *(float *)((uint8_t *)target + 0x74) -
                           *(float *)((uint8_t *)action + 0x74);
                float dz = *(float *)((uint8_t *)target + 0x7c) -
                           *(float *)((uint8_t *)action + 0x7c);
                float distance = __builtin_sqrtf(dx * dx + dz * dz);
                if (distance > 50.0f)
                    *(float *)(context_bytes + 0x34) *= distance * 0.02f;
            }
        }
    }
    if (context_bytes[0x3c] != 0) {
        void *registry = StatusRegistrySingletonGet();
        StatusOwnerApplyEvent(action, 0u, 1u);
        DodgeApplyTransformSideEffect(registry, action);
    }
    if ((*(uint32_t *)((uint8_t *)(*(void **)(state_bytes + 0x38)) + 0x98) &
         0x100u) == 0 &&
        DodgeGlobalGate() == 0) {
        void *engine = EngineSingletonGet();
        uint32_t value = *(uint32_t *)((uint8_t *)engine + 0x1645c) + 1u;
        if (value == 0 || value > 0x3b9ac9ffu)
            value = 0x3b9ac9ffu;
        *(uint32_t *)((uint8_t *)engine + 0x1645c) = value;
    }
    return 0;
}
