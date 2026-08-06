#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include "actor_combat_views.h"
extern void *GetEngineSingleton_003B6CF0(void);
struct DebuffCandidateRecord {
    uint8_t active;
    uint8_t opaque_01[3];
    float contribution;
    float accumulated;
};
typedef char kiu_sa_hit_debuff_1[(offsetof(struct DebuffCandidateRecord, active) == 0x00) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_hit_debuff_2[(offsetof(struct DebuffCandidateRecord, contribution) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_hit_debuff_3[(offsetof(struct DebuffCandidateRecord, accumulated) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_hit_debuff_4[(sizeof(struct DebuffCandidateRecord) == 0x0c) ? 1 : -1] __attribute__((unused));
__attribute__((noinline)) void DebuffCandidateRecord_Initialize(void *record) {
    struct DebuffCandidateRecord *candidate =
        (struct DebuffCandidateRecord *)record;
    candidate->active = 0;
    candidate->contribution = 0.0f;
    candidate->accumulated = 0.0f;
}
uint32_t HitDebuff_HandleSpecial(void *registry, void *descriptor);
int StatusBuildup_AccumulateAndApply(void *status,
                                       StatusChannel channel,
                                       float amount,
                                       float activation_value);
extern void StatusLinkRefreshOrClear(void *target);
extern void *GetStatusEffectRecordKey(void);
extern void *OrderedTreeLowerBoundByPointerAlt(void *tree,
                                                   uint32_t key);
extern int DamageChannelIsOneOrTwo(StatusChannel channel);
extern void *ObjectGetB3F8SubobjectAlt(void *object);
struct DebuffRuntimeDefinition {
    void **vtable;
    float condition_rate;
    uint8_t opaque_08[8];
    float effective_time_rate;
};
typedef char kiu_sa_hit_debuff_5[(offsetof(struct DebuffRuntimeDefinition, condition_rate) == 4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_hit_debuff_6[(offsetof(struct DebuffRuntimeDefinition, effective_time_rate) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_hit_debuff_7[(sizeof(struct DebuffRuntimeDefinition) == 0x14) ? 1 : -1] __attribute__((unused));
struct DebuffRateSourceSelection {
    void *profile;
    uint8_t *owner_scale;
    uint8_t use_owner_scale;
    uint8_t opaque_0d[3];
};
typedef char kiu_sa_hit_debuff_8[(offsetof(struct DebuffRateSourceSelection, profile) == 0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_hit_debuff_9[(offsetof(struct DebuffRateSourceSelection, owner_scale) == 4) ? 1 : -1] __attribute__((unused));
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern void *GetStatusOwnerRegistry(void);
extern void *GetHitDebuffEnumRegistry(void);
uint32_t HitDebuff_ResolveAndAccumulate(void *descriptor,
                                                  void *source_data,
                                                  void *source_effects,
                                                  uint32_t mode,
                                                  uint32_t source_flags,
                                                  uint32_t source_options,
                                                  float hidden_value);
extern void *GetEngineSingleton_003B6CF0(void);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
uint32_t HitDebuff_HandleSpecial(void *registry, void *descriptor);
extern void StatusLinkRefreshOrClear(void *target);
extern void StatusLinkSharedTail(void *component, void *target);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern int DamageChannelIsOneOrTwo(StatusChannel channel);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern void *GetStatusOwnerRegistry(void);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
const char *HitDebuff_ToString(const uint8_t *id);
unsigned OneHotMaskIndex(void *ignored, uint32_t mask);
float Debuff_ApplyResistanceMultiplier(void *table, unsigned channel,
                                          float value);
uint32_t Debuff_ProcRoll(void *state);
int Debuff_ProcChancePassed(void *state, float contribution);
float Debuff_ScaleChannelRate(unsigned channel, float rate, float scalar);
extern uint32_t *GetStatusRandomState(void);
extern void *ObjectGetB3F8Subobject(void *object, int8_t index);
extern int StatusTargetPassesSpecialFilterRetail(void *target);
extern void *ResolveStatusDescriptor(void *object);
extern void *ResolveRelatedComponent(void *object);
extern void *ComponentType_GetGlobalDescriptor(void);
extern void *OrderedTree_LowerBoundByPointer_004C5D3C(void *tree, void *key);
extern float HealthGetResolvedMaximum(void *ignored_context, void *target);
uint32_t HitDebuff_ResolveAndAccumulate(void *descriptor,
                                          void *source_data,
                                          void *source_effects,
                                          uint32_t mode,
                                          uint32_t source_flags,
                                          uint32_t source_options,
                                          float hidden_value);
unsigned StatusOwnerIndexByObject(void *actor, void *owner);
int StatusOwnerTableSignedCode(void *registry, unsigned index);
uint32_t HitDebuff_HandleSpecial(void *registry, void *descriptor);
void StatusLinkRefreshOrClear(void *target);
void *StatusOwnerIndexedBase(void *ignored, unsigned index);
uint32_t HitDebuff_ClassifyOwner(void *object, uint8_t *out_is_default,
                                   int16_t *out_code, int8_t *out_selector,
                                   uint16_t *out_mode);
uint32_t HitDebuff_ClassifyEmbeddedOwner(
    void *actor, uint8_t *out_is_default, int16_t *out_code,
    int8_t *out_selector, uint16_t *out_mode);
int DamageChannelIsOneOrTwo(StatusChannel channel);
extern uint32_t MenuResource_HashBounded_00BAEC74(const char *text);
extern uint32_t MenuResource_HashBounded_00BAF35C(const char *text);
extern uint32_t MenuResource_HashBounded_00BAF328(const char *text);
extern uint32_t MenuResource_HashBounded_00BAEC40(const char *text);
extern int OnceGuard_TestAndSet_003B4FE4(uint32_t *guard);
__attribute__((noinline)) bool HitAttribute_FromHash(const uint32_t *hash, uint8_t *out)
{
    uint8_t *cache = (uint8_t *)(uintptr_t)0x00D3C8B8u;
    const uint32_t value = *hash;
#define HIT_ATTRIBUTE_HASH(guard_off, hash_off, hash_fn, text) \
    do { \
        uint32_t *guard = (uint32_t *)(cache + (guard_off)); \
        if ((*guard & 1u) == 0u && OnceGuard_TestAndSet_003B4FE4(guard) != 0) \
            *(uint32_t *)(cache + (hash_off)) = (hash_fn)(text); \
        if (*(uint32_t *)(cache + (hash_off)) == value) { \
            *out = (uint8_t)((hash_off) / 8u - 6u); \
            return true; \
        } \
    } while (0)
    HIT_ATTRIBUTE_HASH(0x30, 0x34, MenuResource_HashBounded_00BAEC74,
                       "HIT_NORMAL");
    HIT_ATTRIBUTE_HASH(0x38, 0x3c, MenuResource_HashBounded_00BAF35C,
                       "HIT_BLOW");
    HIT_ATTRIBUTE_HASH(0x40, 0x44, MenuResource_HashBounded_00BAF35C,
                       "HIT_STAB");
    HIT_ATTRIBUTE_HASH(0x48, 0x4c, MenuResource_HashBounded_00BAF328,
                       "HIT_CUT");
    HIT_ATTRIBUTE_HASH(0x50, 0x54, MenuResource_HashBounded_00BAEC40,
                       "HIT_SNIPE");
    HIT_ATTRIBUTE_HASH(0x58, 0x5c, MenuResource_HashBounded_00BAF35C,
                       "HIT_FIRE");
    HIT_ATTRIBUTE_HASH(0x60, 0x64, MenuResource_HashBounded_00BAF35C,
                       "HIT_ELEC");
    HIT_ATTRIBUTE_HASH(0x68, 0x6c, MenuResource_HashBounded_00BAF328,
                       "HIT_RAY");
    HIT_ATTRIBUTE_HASH(0x70, 0x74, MenuResource_HashBounded_00BAEC40,
                       "HIT_CURSE");
    HIT_ATTRIBUTE_HASH(0x78, 0x7c, MenuResource_HashBounded_00BAEC40,
                       "HIT_CLEAN");
#undef HIT_ATTRIBUTE_HASH
    return false;
}
__attribute__((noinline)) const char *HitDebuff_ToString(const uint8_t *id)
{
    const char *const *names =
        (const char *const *)(uintptr_t)0x00D3C8B8u;
    switch (*id) {
    case 0: return names[0x45u];
    case 1: return names[0x46u];
    case 2: return names[0x47u];
    case 3: return names[0x48u];
    case 4: return names[0x49u];
    case 5: return names[0x4au];
    case 6: return names[0x4bu];
    case 7: return names[0x4cu];
    case 8: return names[0x4du];
    case 9: return names[0x4eu];
    case 10: return names[0x4fu];
    case 11: return names[0x50u];
    case 12: return names[0x51u];
    case 13: return names[0x52u];
    case 14: return names[0x53u];
    case 15: return names[0x54u];
    case 16: return names[0x55u];
    case 17: return names[0x56u];
    default: return 0;
    }
}
__attribute__((noinline)) unsigned OneHotMaskIndex(void *ignored, uint32_t mask)
{
    (void)ignored;
    switch (mask) {
    case 0x00000001u: return 0;
    case 0x00000002u: return 1;
    case 0x00000004u: return 2;
    case 0x00000008u: return 3;
    case 0x00000010u: return 4;
    case 0x00000020u: return 5;
    case 0x00000040u: return 6;
    case 0x00000080u: return 7;
    case 0x00000100u: return 8;
    case 0x00000200u: return 9;
    case 0x00000400u: return 10;
    case 0x00000800u: return 11;
    case 0x00001000u: return 12;
    case 0x00002000u: return 13;
    case 0x00004000u: return 14;
    case 0x00008000u: return 15;
    case 0x00010000u: return 16;
    case 0x00020000u: return 17;
    case 0x00040000u: return 18;
    case 0x00080000u: return 19;
    case 0x00100000u: return 20;
    case 0x00200000u: return 21;
    case 0x00400000u: return 22;
    case 0x00800000u: return 23;
    case 0x01000000u: return 24;
    case 0x02000000u: return 25;
    case 0x04000000u: return 26;
    case 0x08000000u: return 27;
    case 0x10000000u: return 28;
    case 0x20000000u: return 29;
    case 0x40000000u: return 30;
    case 0x80000000u: return 31;
    default: return 0;
    }
}
static uint32_t Debuff_ChannelResistanceMask(unsigned channel)
{
    static const uint32_t masks[12] = {
        0x00200000u, 0x00100000u, 0x00080000u, 0x00020000u,
        0x00002000u, 0x00040000u, 0x00010000u, 0x00000400u,
        0x00008000u, 0x00000800u, 0x00004000u, 0x00001000u
    };
    return channel < 12 ? masks[channel] : 0;
}
float Debuff_ApplyResistanceMultiplier(void *table, unsigned channel,
                                          float value)
{
    uint32_t mask = Debuff_ChannelResistanceMask(channel);
    if (table == 0 || mask == 0)
        return value;
    return value * *(float *)((uint8_t *)table + 0x12c +
                              OneHotMaskIndex(table, mask) * sizeof(float));
}
uint32_t Debuff_ProcRoll(void *state)
{
    uint8_t *bytes = (uint8_t *)state;
    uint32_t x = *(uint32_t *)(bytes + 0x10);
    uint32_t w = *(uint32_t *)(bytes + 0x1c);
    uint32_t quotient;
    *(uint32_t *)(bytes + 0x10) = *(uint32_t *)(bytes + 0x14);
    *(uint32_t *)(bytes + 0x14) = *(uint32_t *)(bytes + 0x18);
    x ^= x << 11;
    x ^= x >> 8;
    x ^= w ^ (w >> 19);
    *(uint32_t *)(bytes + 0x18) = w;
    *(uint32_t *)(bytes + 0x1c) = x;
    quotient = (uint32_t)(((uint64_t)x * 0x10624dd3u) >> 32) >> 6;
    return x - quotient * 1000u;
}
int Debuff_ProcChancePassed(void *state, float contribution)
{
    return (float)Debuff_ProcRoll(state) * 0.1f < contribution;
}
float Debuff_ScaleChannelRate(unsigned channel, float rate, float scalar)
{
    static const uint8_t buildup_scaled[12] = {
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1
    };
    if (channel < 12 && buildup_scaled[channel] != 0)
        return rate + scalar * rate * 0.02f;
    return rate * 2.0f;
}
static uint8_t *HitDebuff_GetResistanceTable(void *engine, uint8_t *owner)
{
    void *subobject;
    if (owner == 0 || (*(uint32_t *)(owner + 0x20) >> 28) != 1u)
        return 0;
    subobject = ObjectGetB3F8Subobject(engine, *(int8_t *)(owner + 0x2c));
    return subobject != 0 ? (uint8_t *)subobject + 0x2d8 : 0;
}
static void *HitDebuff_ResolveCachedStatus(void *descriptor)
{
    uint8_t *bytes = (uint8_t *)descriptor;
    void *selected = *(void **)(bytes + 0x208);
    void *sentinel;
    void *candidate;
    void *key;
    if (selected != 0)
        return selected;
    key = ComponentType_GetGlobalDescriptor();
    sentinel = bytes + 0x1a4;
    candidate = OrderedTree_LowerBoundByPointer_004C5D3C(bytes + 0x1a8, key);
    if (candidate == (uint8_t *)sentinel + 4 ||
        (candidate != 0 && key < *(void **)((uint8_t *)candidate + 0x14)))
        candidate = (uint8_t *)sentinel + 4;
    selected = candidate != 0 ? *(void **)candidate : 0;
    if (selected == *(void **)(bytes + 0x1a8))
        selected = 0;
    if (selected != 0) {
        *(void **)((uint8_t *)selected + 0x34) = descriptor;
        *(void **)(bytes + 0x208) = selected;
    }
    return selected;
}
static void HitDebuff_SelectRateSources(
    void *engine, uint32_t source_flags, StatusChannel mode,
    uint32_t source_options, struct DebuffRateSourceSelection *out)
{
    void *subobject;
    out->profile = 0;
    out->owner_scale = 0;
    out->use_owner_scale = 0;
    if (engine == 0)
        return;
    if ((source_flags >> 28) == 1u) {
        subobject = ObjectGetB3F8SubobjectAlt(engine);
        if (subobject != 0)
            out->owner_scale = (uint8_t *)subobject + 0x2d8;
    }
    out->profile = OrderedTreeLowerBoundByPointerAlt(
        (uint8_t *)engine + 0x171acu, source_options);
    if (out->profile == 0)
        out->use_owner_scale =
            (uint8_t)DamageChannelIsOneOrTwo(mode);
}
__attribute__((noinline)) uint32_t HitDebuff_ResolveAndAccumulate(void *descriptor,
                                        void *source_data,
                                        void *source_effects,
                                        uint32_t mode,
                                        uint32_t source_flags,
                                        uint32_t source_options,
                                        float hidden_value)
{
    struct DebuffRuntimeDefinition *definition;
    struct DebuffCandidateRecord candidates[16] = {{0}};
    void **source_vtable;
    uint32_t debuff_id;
    uint32_t applied_mask = 0;
    struct DebuffRateSourceSelection rate_sources;
    void *engine;
    void *status;
    uint8_t *resistance_table;
    uint8_t *target_owner;
    float last_loop_s0 = hidden_value;
    unsigned channel;
    if (descriptor == 0)
        return 0;
    engine = GetEngineSingleton_003B6CF0();
    status = HitDebuff_ResolveCachedStatus(descriptor);
    if (status == 0 || source_data == 0)
        return 0;
    source_vtable = *(void ***)source_data;
    definition = (struct DebuffRuntimeDefinition *)
        ((void *(*)(void *))source_vtable[0x24u / sizeof(void *)])(
            source_data);
    debuff_id = 16u;
    if (definition != 0)
        debuff_id = ((uint32_t (*)(void *))
            definition->vtable[0x1cu / sizeof(void *)])(definition);
    if (debuff_id == HIT_DROPOUT)
        return HitDebuff_HandleSpecial(engine, descriptor);
    {
        union FloatBits raw_hidden = { hidden_value };
        if ((int32_t)raw_hidden.bits <= 0x37800000)
            return 0;
    }
    target_owner = 0;
    if (mode < 3u) {
        target_owner = (uint8_t *)ResolveStatusDescriptor(descriptor);
        HitDebuff_SelectRateSources(engine, source_flags,
                                    (StatusChannel)mode, source_options,
                                    &rate_sources);
    } else {
        rate_sources.profile = 0;
        rate_sources.owner_scale = 0;
        rate_sources.use_owner_scale = 0;
    }
    for (channel = 0; mode < 3u && channel < 16u; ++channel) {
        float selected_gate = 0.0f;
        float source_rate = 0.0f;
        float effective_hidden = hidden_value;
        if (rate_sources.use_owner_scale && rate_sources.owner_scale != 0) {
            selected_gate = *(float *)(rate_sources.owner_scale + 0xac +
                                       channel * sizeof(float));
            source_rate = *(float *)(rate_sources.owner_scale + 0xec +
                                     channel * sizeof(float));
        } else if (rate_sources.profile != 0) {
            selected_gate = *(float *)((uint8_t *)rate_sources.profile +
                                       0x48 + channel * sizeof(float));
            source_rate = *(float *)((uint8_t *)rate_sources.profile +
                                     0x88 + channel * sizeof(float));
        }
        last_loop_s0 = source_rate;
        if (channel == 0u && target_owner != 0 &&
            (*(uint32_t *)(target_owner + 0x20) >> 28) == 1u)
            continue;
        if (selected_gate <= 0.0f)
            continue;
        if (source_effects != 0)
            effective_hidden *= *(float *)((uint8_t *)source_effects + 0x4c +
                                           channel * sizeof(float));
        candidates[channel].active = 1;
        candidates[channel].contribution = effective_hidden * selected_gate;
        candidates[channel].accumulated =
            Debuff_ScaleChannelRate(channel, source_rate, hidden_value);
    }
    if (definition != 0 && debuff_id < 16u) {
        float condition_rate = 0.0f;
        float effective_time_rate = 0.0f;
        float effect_scale = 1.0f;
        float condition_sum = 0.0f;
        float effective_time_sum = 0.0f;
        if (source_effects != 0) {
            effect_scale = *(float *)((uint8_t *)source_effects + 0x4c +
                                      debuff_id * sizeof(float));
        }
        if (debuff_id < 12u) {
            condition_rate = definition->condition_rate;
        }
        candidates[debuff_id].active = 1;
        if (debuff_id < 12u) {
            float callback_input = condition_rate;
            float first_scale;
            float second_scale;
            if (debuff_id != 0u) {
                effective_time_rate = definition->effective_time_rate;
                callback_input = effective_time_rate;
                condition_sum += condition_rate;
                effective_time_sum += effective_time_rate;
            } else {
                condition_sum += condition_rate;
            }
            first_scale = ((float (*)(void *, float))
                source_vtable[0x94u / sizeof(void *)])(source_data,
                                                       callback_input);
            second_scale = ((float (*)(void *, float))
                source_vtable[0x98u / sizeof(void *)])(source_data,
                                                       first_scale);
            candidates[debuff_id].contribution +=
                first_scale * condition_sum * effect_scale;
            candidates[debuff_id].accumulated +=
                second_scale * effective_time_sum;
        } else {
            float callback_input = last_loop_s0;
            float first_scale;
            first_scale = ((float (*)(void *, float))
                source_vtable[0x94u / sizeof(void *)])(source_data,
                                                       callback_input);
            candidates[debuff_id].contribution +=
                first_scale * condition_sum * effect_scale;
            candidates[debuff_id].accumulated +=
                ((float (*)(void *, float))
                source_vtable[0x98u / sizeof(void *)])(source_data,
                                                       first_scale) *
                effective_time_sum;
        }
    }
    target_owner = (uint8_t *)ResolveStatusDescriptor(descriptor);
    resistance_table = HitDebuff_GetResistanceTable(engine, target_owner);
    for (channel = 0; channel < 12u; ++channel) {
        float contribution;
        if (candidates[channel].active == 0)
            continue;
        contribution = Debuff_ApplyResistanceMultiplier(
            resistance_table, channel, candidates[channel].contribution);
        if (channel == 0u && (source_flags >> 28) == 1u) {
            float current_maximum = HealthGetResolvedMaximum(engine,
                                                              descriptor);
            float resolved_maximum = *(float *)((uint8_t *)engine + 0x1ee48);
            if (current_maximum < resolved_maximum)
                contribution = (resolved_maximum / current_maximum) *
                               contribution;
        }
        if (channel >= 5u) {
            if (!Debuff_ProcChancePassed(GetStatusRandomState(),
                                         contribution))
                continue;
            contribution = 100.0f;
            if (target_owner != 0 &&
                (*(uint32_t *)((uint8_t *)target_owner + 0x20) >> 28) == 1u &&
                !StatusTargetPassesSpecialFilterRetail(descriptor))
                continue;
        }
        if (StatusBuildup_AccumulateAndApply(
                status, (StatusChannel)channel, contribution,
                candidates[channel].accumulated) != 0)
            applied_mask |= 1u << channel;
    }
    return applied_mask;
}
uint32_t HitDebuff_HandleSpecial(void *registry, void *descriptor)
{
    uint8_t *engine = (uint8_t *)registry;
    uint8_t *selected;
    uint8_t *node;
    uint8_t *upper;
    if (engine == 0 || engine[STATUS_SELECTOR_A] == 0 ||
        engine[STATUS_SELECTOR_B] == 0) {
        StatusLinkRefreshOrClear(descriptor);
        return 0x8000u;
    }
    selected = *(uint8_t **)((uint8_t *)descriptor + 0x1ec);
    if (selected == 0) {
        node = OrderedTreeLowerBoundByPointer(
            (uint8_t *)descriptor + 0x1a4,
            GetStatusEffectRecordKey());
        upper = *(uint8_t **)((uint8_t *)descriptor + 0x1a8);
        selected = node != 0 ? *(uint8_t **)node : 0;
        if (selected == upper)
            selected = 0;
        if (selected != 0) {
            *(void **)(selected + 0x1c) = descriptor;
            *(uint8_t **)((uint8_t *)descriptor + 0x1ec) = selected;
        }
    }
    if (selected != 0)
        *(uint32_t *)(selected + 0x94) |= 0x08000000u;
    StatusLinkSharedTail(engine, descriptor);
    return 0x8000u;
}
__attribute__((noinline)) uint32_t HitDebuff_ClassifyOwner(void *object, uint8_t *out_is_default,
                                   int16_t *out_code, int8_t *out_selector,
                                   uint16_t *out_mode)
{
    uint32_t handle = 0;
    uint8_t *owner_context;
    uint8_t *code_registry;
    unsigned index;
    int code;
    if ((*(uint32_t *)((uint8_t *)object + 0x1e8) & 0x1000u) != 0)
        handle = *(uint32_t *)((uint8_t *)object + 0x1f4);
    if (handle == 0 || (handle >> 28) != 1u)
        return 0;
    code_registry = (uint8_t *)GetHitDebuffEnumRegistry();
    owner_context = (uint8_t *)GetStatusOwnerRegistry();
    index = StatusOwnerIndexByObject(owner_context,
                                         (void *)(uintptr_t)handle);
    code = StatusOwnerTableSignedCode(code_registry, index);
    *out_selector = (int8_t)code;
    *out_mode = code == 0 ? 1u : 2u;
    *out_is_default = *out_selector == 0;
    *out_code = 700;
    if ((*(uint32_t *)((uint8_t *)object + 0x1f0) >> 28) == 1u) {
        unsigned alternate_index = StatusOwnerIndexByObject(
            owner_context,
            (void *)(uintptr_t)*(uint32_t *)((uint8_t *)object + 0x1f0));
        int alternate_code = StatusOwnerTableSignedCode(
            code_registry, alternate_index);
        if (alternate_code != *out_selector)
            *out_code = *(int16_t *)StatusOwnerIndexedBase(
                owner_context, alternate_index);
    }
    if (*out_code != 700) {
        uint32_t required_bit = *out_is_default ? 0x10u : 0x20u;
        if ((*(uint8_t *)((uint8_t *)object + 0x240) & required_bit) == 0)
            *out_code = 700;
    }
    return 1;
}
__attribute__((noinline)) uint32_t HitDebuff_ClassifyEmbeddedOwner(
    void *actor, uint8_t *out_is_default, int16_t *out_code,
    int8_t *out_selector, uint16_t *out_mode)
{
    void *object = *(void **)((uint8_t *)actor + 0x1240 + 0x240);
    return HitDebuff_ClassifyOwner(object, out_is_default, out_code,
                                     out_selector, out_mode);
}
