#include <stddef.h>
#include <stdint.h>
#include "actor_combat_views.h"
extern void *GetEngineSingleton_003B6CF0(void);
extern void StatusHandleReleaseThroughRegistry(void *dispatcher,
                                                   uint32_t *handle,
                                                   unsigned mode);
extern int EngineStatusModeIsType5(void);
extern uint32_t DamagePacketBuildFlags(void *context);
int DamageChannelPolicy_B(StatusChannel channel);
extern int DamageChannelIsOneOrTwo(StatusChannel channel);
struct DamageProfileEntryView {
    uint8_t opaque_00[0x2c];
    float baseline;
    uint8_t opaque_030[0x14];
    void *curve_policy;
};
struct DamageProfilePolicyView {
    uint8_t opaque_00[0x30];
    float slope_a;
    float slope_b;
};
enum DamageFlags {
    DAMAGE_FLAG_FAMILY_STANDARD = 0x10000000,
    DAMAGE_FLAG_FAMILY_REACTION = 0x20000000,
    DAMAGE_SOURCE_SLOT_MASK = 0x00ff0000
};
typedef char kiu_sa_damage_packet_1[(offsetof(struct DamageProfileEntryView, baseline) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_2[(offsetof(struct DamageProfileEntryView, curve_policy) == 0x44) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_3[(offsetof(struct DamageProfilePolicyView, slope_a) == 0x30) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_4[(offsetof(struct DamageProfilePolicyView, slope_b) == 0x34) ? 1 : -1] __attribute__((unused));
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
enum DamageProfileMode {
    DAMAGE_PROFILE_RATE = 1,
    DAMAGE_PROFILE_ALTERNATE_CURVE = 2,
    DAMAGE_PROFILE_POLICY = 3,
    DAMAGE_PROFILE_CURVE = 4,
    DAMAGE_PROFILE_POLICY_OR_ZERO = 5
};
extern void *GetStatusOwnerRegistry(void);
extern void *EngineLazySingleton0054EFA8(void);
extern void *EngineSharedRegistrySingleton_00593E20(void);
extern void *EngineLazySingleton00498828(void);
extern void EffectParameterRecordInitialize(void *record);
extern void EffectParameterRecordRandomize(void *record, void *target,
                                               uint32_t selector,
                                               unsigned mode);
extern void EffectParameterBuild(float *output, int selector, void *record,
                                    unsigned arg3, unsigned arg4,
                                    unsigned arg5, unsigned arg6);
extern void *StatusDescriptorOwnerBase(void *descriptor);
extern uint32_t StatusEffectCreateOrRelease(void *context, int effect_type,
                                               unsigned create);
extern void HealthNotifyModeZero(void *component, float reset_value);
extern void *GetEngineSingleton_003B6CF0(void);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
struct DamageProfileRecord {
    float damage;
    uint32_t repeat_count;
    uint32_t source_config_bits;
    uint32_t source_config_bits_copy;
    uint32_t resolved_value_bits;
    uint8_t source_kind;
    uint8_t _padding[3];
    uint32_t auxiliary_value_bits;
};
typedef char kiu_sa_damage_packet_5[(offsetof(struct DamageProfileRecord, damage) == 0x00) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_6[(offsetof(struct DamageProfileRecord, repeat_count) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_7[(offsetof(struct DamageProfileRecord, source_config_bits) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_8[(offsetof(struct DamageProfileRecord, source_config_bits_copy) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_9[(offsetof(struct DamageProfileRecord, resolved_value_bits) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_10[(offsetof(struct DamageProfileRecord, source_kind) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_11[(offsetof(struct DamageProfileRecord, auxiliary_value_bits) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_damage_packet_12[(sizeof(struct DamageProfileRecord) == 0x1c) ? 1 : -1] __attribute__((unused));
void HealthApplySignedDelta(void *context, void *target, unsigned mode,
                               unsigned extra, float delta);
extern void *ComponentLookupStatusOwner(void *registry, void *target);
extern void *Engine_ClassNibbleComponentSelect(void *registry,
                                                void *context);
extern void *EngineLazySingleton00422CC8(void);
extern void *EngineLazySingleton004C59C0(void);
extern void *ResourceStatus_LookupByHandle(void *registry, uint32_t handle);
extern void *GetDamageOwnerTableRegistry(void);
extern void *ComponentType_GetGlobalDescriptor(void);
extern void *GetDamageProfileKey(void);
extern void *GetProfileRateKey(void);
extern void *GetAlternateProfileKey(void);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern int DamageChannelIsOneOrTwo(StatusChannel channel);
extern void *ObjectGetB3F8Subobject(void *object, int8_t index);
extern void DamageChannelPolicy_Apply(const float *policy,
                                        StatusChannel channel,
                                        unsigned index,
                                        float *indexed_value,
                                        float *common_value);
extern float DamagePacket_ApplyProfileRate(void *context, unsigned profile,
                                       unsigned channel, const float *policy,
                                       float input);
extern float DamagePacket_ApplyAlternateCurve(void *context, unsigned profile,
                                             unsigned channel,
                                             const float *policy,
                                             unsigned exception,
                                             float input);
extern float DamagePacket_ApplyProfileCurve(void *context, unsigned profile,
                                         unsigned channel, const float *policy,
                                         float input);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern void *GetStatusOwnerRegistry(void);
extern float Powf(float value, float exponent);
enum DamageChannelPolicy {
    DAMAGE_CHANNEL_POLICY_NONE = 0,
    DAMAGE_CHANNEL_POLICY_A,
    DAMAGE_CHANNEL_POLICY_B,
    DAMAGE_CHANNEL_POLICY_C
};
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
uint32_t DamagePacketBuildFlags(void *context);
unsigned StatusOwnerIndexByHandle(void *base, uint32_t handle);
unsigned StatusOwnerIndexByObject(void *actor, void *owner);
struct DamageProfileRecord *DamageEffectSelectProfileRecord(
    uint8_t *owner, uint32_t count);
void DamageEffectStoreProfileRecord(
    struct DamageProfileRecord *record, float damage,
    uint32_t source_config_bits,
    uint32_t resolved_value_bits, uint32_t source_kind,
    uint32_t auxiliary_value_bits,
    uint32_t count);
void DamageOwner_AccumulateIndexedValues(struct StatusOwnerView *owner,
                                           uint32_t first_index,
                                           uint32_t second_index,
                                           float hidden_value);
void DamagePacketFinalizeOwner(void *context, void *target, void *owner,
                                  void *descriptor, uint32_t packet_flags,
                                  unsigned channel, float final_amount);
void StatusConfigClearSelectedChannels(void *registry, void *target,
                                          uint8_t *config, uint32_t param4,
                                          uint32_t param5,
                                          float damage_amount);
void DamageStatusConfig_Dispatch(void *target, uint8_t *config,
                                    uint32_t selector);
int DamageMode2UsesAlternateException(uint32_t source_flags,
                                          unsigned owner_index,
                                          const void *registry_table,
                                          unsigned channel);
float DamagePacket_ComputeScale(void *context, uint32_t source_flags,
                                  unsigned profile, unsigned channel,
                                  const float *policy, float input);
void DamageOwner_ResetFourRecords(void *owner);
float DamagePowerCurve(float a, float b, float c);
void HealthApplySignedDelta(void *context, void *target, unsigned mode,
                               unsigned extra, float delta);
uint8_t DamageChannelPolicyFor(StatusChannel channel);
int DamageChannelPolicy_A(StatusChannel channel);
int DamageChannelPolicy_B(StatusChannel channel);
int DamageChannelPolicy_C(StatusChannel channel);
int DamageChannelIsOneOrTwo(StatusChannel channel);
int DamageChannelIsStatusTick(unsigned channel);
int DamageChannelIsSpecialSet(unsigned channel);
void DamageChannelPolicy_Apply(const float *policy,
                                 StatusChannel channel,
                                 unsigned index,
                                 float *indexed_value,
                                 float *common_value);
float ApplyDamageProfileRate(float value,
                                unsigned channel,
                                int adjustment_enabled,
                                float divisor);
float DamagePacket_ApplyProfileCurve(void *context, unsigned profile,
                                  unsigned channel, const float *policy,
                                  float input);
float DamagePacket_ApplyAlternateCurve(void *context, unsigned profile,
                                      unsigned channel, const float *policy,
                                      unsigned exception, float input);
float DamagePacket_ApplyProfileRate(void *context, unsigned profile,
                                unsigned channel, const float *policy,
                                float input);
float ApplyDamageProfileCurve(float input, float baseline, float slope);
float ApplyDamageProfileEntryCurve(float input, unsigned channel,
                                      const uint8_t *entry);
void Damage_AccumulateBoundedMeter(void *object, float delta);
__attribute__((noinline)) uint32_t DamagePacketBuildFlags(void *context)
{
    uint8_t *bytes = (uint8_t *)context;
    static void **const engine_slot =
        (void **)(uintptr_t)0x00d6364cu;
    uint8_t *engine = (uint8_t *)*engine_slot;
    uint32_t flags = DAMAGE_FLAG_FAMILY_STANDARD;
    if (bytes[STATUS_SELECTOR_B] == 0)
        return flags;
    if (engine == 0) {
        engine = (uint8_t *)EngineLazySingleton00422CC8();
        *engine_slot = engine;
    }
    return flags | (((uint32_t)(engine[0x1f4c] - 1u) & 0xffu) << 16);
}
__attribute__((noinline)) int DamageEffect_ApplyAndQueue(void *owner, void *target, void *component,
                               void *config, uint32_t param4,
                               uint32_t param5, float hidden_amount)
{
    static void **const engine_slot = (void **)(uintptr_t)0x00d63578u;
    uint8_t *config_bytes = (uint8_t *)config;
    struct ActorObjectView *target_view =
        (struct ActorObjectView *)target;
    struct HealthStatusComponent *component_view =
        (struct HealthStatusComponent *)component;
    struct DamageProfileRecord *profile;
    uint8_t *entry;
    uint8_t *tree_node;
    int32_t configured_count = *(int32_t *)(config_bytes + 0x50);
    uint32_t count;
    uint32_t selector;
    uint32_t effect_type;
    float effect_value = 0.0f;
    float final_amount;
    void *engine;
    union {
        float value;
        uint32_t bits;
    } effect_result;
    count = configured_count <= 0 ? 1u : (uint32_t)configured_count;
    profile = DamageEffectSelectProfileRecord((uint8_t *)owner, count);
    if (count > 1u && profile == 0)
        return 0;
    selector = *(uint32_t *)(config_bytes + 0x5c);
    if ((int32_t)selector >= 0) {
        entry = (uint8_t *)target_view->cached_alternate_profile;
        if (entry == 0) {
            tree_node = OrderedTreeLowerBoundByPointer(
                &target_view->component_tree_anchor,
                EngineLazySingleton00498828());
            entry = tree_node != 0 ? *(uint8_t **)tree_node : 0;
            if (entry == target_view->component_tree_upper)
                entry = 0;
            if (entry != 0) {
                *(void **)(entry + 0x1c) = target;
                target_view->cached_alternate_profile = entry;
            }
        }
        if (entry != 0) {
            uint8_t record[0xc4];
            float output[8];
            EffectParameterRecordInitialize(record);
            EffectParameterRecordRandomize(
                record, target, *(uint32_t *)(entry + 0x24), 0u);
            EffectParameterBuild(output, (int)selector, record,
                                 0u, 0u, 0u, 1u);
            effect_value = output[0];
        }
    }
    effect_type = *(uint32_t *)(config_bytes + 0x60);
    if ((int32_t)effect_type >= 0) {
        engine = *engine_slot;
        if (engine == 0) {
            engine = EngineLazySingleton0054EFA8();
            *engine_slot = engine;
        }
        (void)StatusEffectCreateOrRelease(engine, (int)effect_type, 1u);
    }
    final_amount = *(float *)(config_bytes + 0x4c) * hidden_amount;
    if (config_bytes[0x49] == 1u) {
        float current = component_view->current_hp.value;
        float maximum = component_view->maximum_hp.value;
        struct HealthSecondaryStateView *secondary =
            (struct HealthSecondaryStateView *)component_view->secondary;
        float count_float = (float)count;
        if (secondary != 0 && secondary->state != 0)
            current += secondary->overflow;
        (void)StatusDescriptorOwnerBase(target);
        union {
            float value;
            uint32_t bits;
        } maximum_bits = { maximum };
        if ((int32_t)maximum_bits.bits <= (int32_t)0x37800000u)
            maximum = 1.0f;
        {
            static void **const curve_slot =
                (void **)(uintptr_t)0x00d63654u;
            void *curve_engine = *curve_slot;
            if (curve_engine == 0) {
                curve_engine = EngineSharedRegistrySingleton_00593E20();
                *curve_slot = curve_engine;
            }
        }
        final_amount = DamagePowerCurve(
            maximum, current, final_amount / maximum);
        final_amount /= count_float;
    }
    if (param4 == 0u && param5 == 0x21u)
        HealthNotifyModeZero(component, 0.0f);
    engine = *engine_slot;
    if (engine == 0) {
        engine = EngineLazySingleton0054EFA8();
        *engine_slot = engine;
    }
    HealthApplySignedDelta(engine, target, 1u, 0u, final_amount);
    if (count > 1u)
        effect_result.value = effect_value;
    if (count > 1u)
        DamageEffectStoreProfileRecord(
            profile, final_amount, *(uint32_t *)(config_bytes + 0x54),
            effect_result.bits, param4, param5, count);
    return 1;
}
struct DamageProfileRecord *DamageEffectSelectProfileRecord(
    uint8_t *owner, uint32_t count)
{
    struct StatusOwnerView *record = (struct StatusOwnerView *)owner;
    struct DamageProfileRecord *profiles =
        (struct DamageProfileRecord *)record->damage_profiles;
    if (count <= 1u)
        return 0;
    if (profiles[0].repeat_count == 0)
        return &profiles[0];
    if (profiles[1].repeat_count == 0)
        return &profiles[1];
    if (profiles[2].repeat_count == 0)
        return &profiles[2];
    if (profiles[3].repeat_count != 0)
        return 0;
    return &profiles[3];
}
void DamageEffectStoreProfileRecord(
    struct DamageProfileRecord *record, float damage,
    uint32_t source_config_bits,
    uint32_t resolved_value_bits, uint32_t source_kind,
    uint32_t auxiliary_value_bits,
    uint32_t count)
{
    record->damage = damage;
    record->repeat_count = count - 1u;
    record->source_config_bits = source_config_bits;
    record->source_config_bits_copy = source_config_bits;
    record->resolved_value_bits = resolved_value_bits;
    record->source_kind = (uint8_t)source_kind;
    record->auxiliary_value_bits = auxiliary_value_bits;
}
__attribute__((noinline)) void DamageOwner_AccumulateIndexedValues(struct StatusOwnerView *owner,
                                           uint32_t first_index,
                                           uint32_t second_index,
                                           float hidden_value)
{
    if (EngineStatusModeIsType5())
        return;
    *(float *)((uint8_t *)owner + 0xd4u + first_index * 4u) += hidden_value;
    owner->indexed_values_298[second_index] += hidden_value;
}
void DamagePacketFinalizeOwner(void *context, void *target, void *owner,
                                  void *descriptor, uint32_t packet_flags,
                                  unsigned channel, float final_amount)
{
    struct StatusOwnerView *record = (struct StatusOwnerView *)owner;
    struct StatusDescriptorView *resolved =
        (struct StatusDescriptorView *)descriptor;
    uint32_t second_index = resolved->owner_slot;
    if ((packet_flags >> 28) == 1u)
        second_index = StatusOwnerIndexByHandle(
            (uint8_t *)context + 0xb3f8u, packet_flags);
    DamageOwner_AccumulateIndexedValues(record, channel,
                                          second_index, final_amount);
    if ((record->flags_ad8 & 0x20u) != 0)
        HealthApplySignedDelta(context, target, 0u, 0u, final_amount);
}
__attribute__((noinline)) void DamageStatusConfig_Dispatch(void *target, uint8_t *config,
                                    uint32_t selector)
{
    void *registry = GetStatusOwnerRegistry();
    (void)ComponentLookupStatusOwner(registry, target);
    registry = GetStatusOwnerRegistry();
    StatusConfigClearSelectedChannels(registry, target, config, 0,
                                         selector, 1.0f);
}
int DamageMode2UsesAlternateException(uint32_t source_flags,
                                          unsigned owner_index,
                                          const void *registry_table,
                                          unsigned channel)
{
    uint16_t entry_id;
    if ((source_flags >> 28) != 1u ||
        (channel != 0u && channel != 4u) || registry_table == 0)
        return 0;
    entry_id = *(const uint16_t *)((const uint8_t *)registry_table +
                                  owner_index * 0x370u);
    return entry_id == 0x328u || entry_id == 0x329u;
}
static uint8_t *DamagePacket_ResolveScaleComponent(uint8_t *object)
{
    uint8_t *selected = *(uint8_t **)(object + 0x208u);
    uint8_t *node;
    uint8_t *sentinel = object + 0x1a4u;
    void *key;
    if (selected != 0)
        return selected;
    key = ComponentType_GetGlobalDescriptor();
    node = OrderedTreeLowerBoundByPointer(object + 0x1a8u, key);
    if (node == sentinel + 4u ||
        (node != 0 && key < *(void **)(node + 0x14u)))
        node = sentinel + 4u;
    selected = node != 0 ? *(uint8_t **)node : 0;
    if (selected == *(uint8_t **)(object + 0x1a8u))
        selected = 0;
    if (selected != 0) {
        *(void **)(selected + 0x34u) = object;
        *(uint8_t **)(object + 0x208u) = selected;
    }
    return selected;
}
__attribute__((noinline)) float DamagePacket_ComputeScale(void *context, uint32_t source_flags,
                                  unsigned profile, unsigned channel,
                                  const float *policy, float input)
{
    struct ActorObjectView *object =
        (struct ActorObjectView *)context;
    static void **const engine_slot =
        (void **)(uintptr_t)0x00d63578u;
    void *engine = *engine_slot;
    uint8_t *entry = (uint8_t *)object->cached_profile_rate;
    uint32_t entry_word = 0;
    float result = 0.0f;
    if (engine == 0) {
        engine = EngineLazySingleton0054EFA8();
        *engine_slot = engine;
    }
    if (engine != 0 && *(uint8_t *)((uint8_t *)engine + 0x123c) != 0 &&
        *(uint8_t *)((uint8_t *)engine + 0x123d) != 0) {
        void *gate = Engine_ClassNibbleComponentSelect(engine, context);
        if (gate != 0 && (*(uint8_t *)((uint8_t *)gate + 0x58) & 1u) == 0)
            return result;
    }
    if (entry == 0) {
        void *key = ComponentType_GetGlobalDescriptor();
        uint8_t *sentinel = (uint8_t *)object + 0x1a4u;
        uint8_t *node = OrderedTreeLowerBoundByPointer(
            (uint8_t *)object + 0x1a8u, key);
        if (node == sentinel + 4u ||
            (node != 0 && key < *(void **)(node + 0x14u)))
            node = sentinel + 4u;
        entry = node != 0 ? *(uint8_t **)node : 0;
        if (entry == *(uint8_t **)((uint8_t *)object + 0x1a8u))
            entry = 0;
        if (entry != 0) {
            *(void **)(entry + 0x1c) = context;
            object->cached_profile_rate = entry;
        }
    }
    if (entry != 0)
        entry_word = *(uint32_t *)(entry + 0x20);
    if (engine != 0 && source_flags == DamagePacketBuildFlags(engine) &&
        DamageChannelIsOneOrTwo((StatusChannel)channel)) {
        uint8_t *variant = (uint8_t *)ResourceStatus_LookupByHandle(
            engine, source_flags);
        uint8_t *selected = variant != 0
            ? DamagePacket_ResolveScaleComponent(variant) : 0;
        uint8_t *active = selected != 0
            ? *(uint8_t **)(selected + 0x170u) : 0;
        if (active != 0 && *active != 0) {
            static void **const factor_slot =
                (void **)(uintptr_t)0x00d63600u;
            void *factor_object = *factor_slot;
            if (factor_object == 0) {
                factor_object = EngineLazySingleton004C59C0();
                *factor_slot = factor_object;
            }
            if (factor_object != 0)
                input *= *(float *)((uint8_t *)factor_object + 0x130u);
        }
    }
    switch (entry_word >> 28) {
    case DAMAGE_PROFILE_RATE:
        return DamagePacket_ApplyProfileRate(context, profile, channel, policy,
                                         input);
    case DAMAGE_PROFILE_ALTERNATE_CURVE: {
        unsigned exception = 0;
        if ((source_flags >> 28) == 1u && engine != 0) {
            unsigned owner = StatusOwnerIndexByObject(
                engine, (void *)(uintptr_t)source_flags);
            static void **const owner_table_slot =
                (void **)(uintptr_t)0x00d6364cu;
            void *table_object = *owner_table_slot;
            if (table_object == 0) {
                table_object = EngineLazySingleton00422CC8();
                *owner_table_slot = table_object;
            }
            const uint8_t *table = (const uint8_t *)table_object;
            exception = (unsigned)DamageMode2UsesAlternateException(
                source_flags, owner, table, channel);
        }
        return DamagePacket_ApplyAlternateCurve(context, profile, channel,
                                              policy, exception, input);
    }
    case DAMAGE_PROFILE_POLICY:
    case DAMAGE_PROFILE_POLICY_OR_ZERO: {
        float indexed = 1.0f;
        float common = 0.0f;
        if (policy != 0)
            DamageChannelPolicy_Apply(policy, (StatusChannel)channel, profile,
                                      &indexed, &common);
        result = (input - indexed) * common;
        return result > 0.0f ? result : 0.0f;
    }
    case DAMAGE_PROFILE_CURVE:
        return DamagePacket_ApplyProfileCurve(context, profile, channel, policy,
                                          input);
    default:
        return result;
    }
}
__attribute__((noinline)) void DamageOwner_ResetFourRecords(void *owner)
{
    static void **dispatcher_slot = (void **)(uintptr_t)0x00d6385cu;
    uint8_t *base = (uint8_t *)owner;
    void *dispatcher = *dispatcher_slot;
    unsigned index;
    if (dispatcher == 0) {
        dispatcher = GetEngineSingleton_003B6CF0();
        *dispatcher_slot = dispatcher;
    }
    for (index = 0; index < 4; ++index) {
        uint8_t *record = base + index * 0x1cu;
        uint32_t handle = *(uint32_t *)(record + 0xaf4u);
        *(uint32_t *)(record + 0xae8u) = 0;
        StatusHandleReleaseThroughRegistry(dispatcher, &handle, 0);
        *(uint32_t *)(record + 0xaf4u) = 0;
    }
}
__attribute__((noinline)) float DamagePowerCurve(float a, float b, float c)
{
    float blend = 0.0f;
    if (a > 0.0f) {
        if (b > 0.0f)
            blend = Powf(b / a, 1.5f) + c;
        if (blend < 0.0f)
            blend = 0.0f;
        if (blend > 1.0f)
            blend = 1.0f;
    }
    return Powf(blend, 2.0f / 3.0f) * a - b;
}
uint8_t DamageChannelPolicyFor(StatusChannel channel)
{
    switch (channel) {
    case 1: case 2: case 6: case 9:  return DAMAGE_CHANNEL_POLICY_A;
    case 0: case 5: case 8:          return DAMAGE_CHANNEL_POLICY_B;
    case 4: case 7: case 10:         return DAMAGE_CHANNEL_POLICY_C;
    default:                         return DAMAGE_CHANNEL_POLICY_NONE;
    }
}
__attribute__((noinline)) int DamageChannelPolicy_A(StatusChannel channel)
{
    return channel == 1 || channel == 2 || channel == 6 || channel == 9;
}
__attribute__((noinline)) int DamageChannelPolicy_B(StatusChannel channel)
{
    return channel == 0 || channel == 5 || channel == 8;
}
__attribute__((noinline)) int DamageChannelPolicy_C(StatusChannel channel)
{
    return channel == 4 || channel == 7 || channel == 10;
}
__attribute__((noinline)) int DamageChannelIsOneOrTwo(StatusChannel channel)
{
    return channel == 1 || channel == 2;
}
__attribute__((noinline)) int DamageChannelIsStatusTick(unsigned channel)
{
    return channel == 0x0bu || channel == 0x0cu;
}
__attribute__((noinline)) int DamageChannelIsSpecialSet(unsigned channel)
{
    return channel == 3u || channel == 0x0du || channel == 0x0eu ||
           channel == 0x0fu || channel == 0x10u;
}
__attribute__((noinline)) void DamageChannelPolicy_Apply(const float *policy,
                                 StatusChannel channel,
                                 unsigned index,
                                 float *indexed_value,
                                 float *common_value)
{
    *common_value *= policy[5];
    *indexed_value *= policy[9 + index];
    switch (DamageChannelPolicyFor(channel)) {
    case DAMAGE_CHANNEL_POLICY_A: *indexed_value *= policy[7]; break;
    case DAMAGE_CHANNEL_POLICY_B: *indexed_value *= policy[6]; break;
    case DAMAGE_CHANNEL_POLICY_C: *indexed_value *= policy[8]; break;
    default: break;
    }
}
float ApplyDamageProfileRate(float value,
                                unsigned channel,
                                int adjustment_enabled,
                                float divisor)
{
    if (adjustment_enabled && channel != 13)
        value /= divisor;
    return value;
}
__attribute__((noinline)) float DamagePacket_ApplyProfileCurve(void *context, unsigned profile,
                                  unsigned channel, const float *policy,
                                  float input)
{
    struct ActorObjectView *object =
        (struct ActorObjectView *)context;
    uint8_t *node = OrderedTreeLowerBoundByPointer(
        &object->component_tree_anchor, GetDamageProfileKey());
    uint8_t *upper = (uint8_t *)object->component_tree_upper;
    uint8_t *entry = node != 0 ? *(uint8_t **)node : 0;
    float baseline = 0.0f;
    float slope = 1.0f;
    if (entry == upper)
        entry = 0;
    if (entry != 0) {
        struct DamageProfileEntryView *profile_entry =
            (struct DamageProfileEntryView *)entry;
        struct DamageProfilePolicyView *entry_policy =
            (struct DamageProfilePolicyView *)profile_entry->curve_policy;
        baseline = profile_entry->baseline;
        if (entry_policy != 0) {
            if (channel == 0u || channel == 5u || channel == 8u)
                slope = entry_policy->slope_a;
            else if (channel == 1u || channel == 2u ||
                     channel == 6u || channel == 9u)
                slope = entry_policy->slope_b;
        }
    }
    if (policy != 0)
        DamageChannelPolicy_Apply(policy, (StatusChannel)channel,
                                    profile, &slope, &baseline);
    {
        float result = (input - baseline) * slope;
        return result > 0.0f ? result : 0.0f;
    }
}
__attribute__((noinline)) float DamagePacket_ApplyAlternateCurve(void *context, unsigned profile,
                                      unsigned channel, const float *policy,
                                      unsigned exception, float input)
{
    struct ActorObjectView *object =
        (struct ActorObjectView *)context;
    uint8_t *entry = 0;
    int skip_policy = 0;
    float baseline = 0.0f;
    float slope = 1.0f;
    {
        static void **const singleton_slot = (void **)(uintptr_t)0x00d63578u;
        void *singleton = *singleton_slot;
        if (singleton == 0) {
            singleton = EngineLazySingleton0054EFA8();
            *singleton_slot = singleton;
        }
    }
    if (exception != 0) {
        entry = (uint8_t *)object->cached_alternate_profile;
        if (entry == 0) {
            uint8_t *node = OrderedTreeLowerBoundByPointer(
                &object->component_tree_anchor, GetAlternateProfileKey());
            uint8_t *upper = (uint8_t *)object->component_tree_upper;
            entry = node != 0 ? *(uint8_t **)node : 0;
            if (entry == upper)
                entry = 0;
            if (entry != 0) {
                *(void **)(entry + 0x1c) = context;
                object->cached_alternate_profile = entry;
            }
        }
        if (entry != 0 && *(uint16_t *)(entry + 0x20) == 0x77u)
            skip_policy = 1;
    }
    if (!skip_policy && policy != 0)
        DamageChannelPolicy_Apply(policy, (StatusChannel)channel,
                                    profile, &slope, &baseline);
    {
        float result = (input - baseline) * slope;
        return result > 0.0f ? result : 0.0f;
    }
}
__attribute__((noinline)) float DamagePacket_ApplyProfileRate(void *context, unsigned profile,
                                unsigned channel, const float *policy,
                                float input)
{
    static void **const registry_slot = (void **)(uintptr_t)0x00d63578u;
    struct ActorObjectView *object =
        (struct ActorObjectView *)context;
    uint8_t *registry = (uint8_t *)*registry_slot;
    uint8_t *entry = (uint8_t *)object->cached_profile_rate;
    unsigned owner_index = 0;
    (void)profile;
    (void)policy;
    if (registry == 0) {
        registry = (uint8_t *)EngineLazySingleton0054EFA8();
        *registry_slot = registry;
    }
    if (registry[0x123c] == 0 || registry[0x123d] == 0 || channel == 13u)
        return input;
    if (entry == 0) {
        uint8_t *node = OrderedTreeLowerBoundByPointer(
            &object->component_tree_anchor, GetProfileRateKey());
        uint8_t *upper = (uint8_t *)object->component_tree_upper;
        entry = node != 0 ? *(uint8_t **)node : 0;
        if (entry == upper)
            entry = 0;
        if (entry != 0) {
            *(void **)(entry + 0x1c) = context;
            object->cached_profile_rate = entry;
        }
    }
    if (entry != 0)
        owner_index = *(uint8_t *)(entry + 0x2c);
    {
        uint8_t *subobject = (uint8_t *)ObjectGetB3F8Subobject(
            registry, owner_index);
        if (subobject != 0)
            input /= *(float *)(subobject + 0x800u + 0x2a8u);
    }
    return input;
}
float ApplyDamageProfileCurve(float input, float baseline, float slope)
{
    float result = (input - baseline) * slope;
    return result > 0.0f ? result : 0.0f;
}
float ApplyDamageProfileEntryCurve(float input, unsigned channel,
                                      const uint8_t *entry)
{
    float baseline = *(const float *)(entry + 0x2c);
    float slope = 1.0f;
    const uint8_t *policy = *(const uint8_t *const *)(entry + 0x44);
    if (policy != 0) {
        if (channel == 0u || channel == 5u || channel == 8u)
            slope = *(const float *)(policy + 0x30);
        else if (channel == 1u || channel == 2u ||
                 channel == 6u || channel == 9u)
            slope = *(const float *)(policy + 0x34);
    }
    return ApplyDamageProfileCurve(input, baseline, slope);
}
__attribute__((noinline)) void Damage_AccumulateBoundedMeter(void *object, float delta)
{
    uint8_t *meter = (uint8_t *)object + 0x400;
    float candidate = *(float *)(meter + 0x1c) +
                      delta * *(float *)(meter + 0x14);
    float lower_bounded = candidate > 0.0f ? candidate : 0.0f;
    float ceiling = *(float *)(meter + 0x18);
    *(float *)(meter + 0x1c) = lower_bounded <= ceiling
        ? lower_bounded : ceiling;
}
