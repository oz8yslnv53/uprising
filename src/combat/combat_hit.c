#include <stddef.h>
#include <stdint.h>
#include "actor_combat_views.h"
extern void *GetEngineSingleton_003B6CF0(void);
extern void *EngineSharedObjectSingleton004C5BA4(void);
extern int EngineOnceGuard(uint32_t *guard);
extern uint32_t OwnerHandleBuildOther(void *source, uint32_t key);
extern uint32_t FUN_00562D00(void *source);
extern uint32_t ResourceTableLookup(uint32_t *handle);
extern void *CachedDescriptorResolve(void *object);
int Status_ResetSharedEligibility(void *registry);
extern int Status_ResetModeGate(void *status);
extern int Status_AccumulateChannelValue(void *status, float hidden_value);
extern void *EngineLazySingleton00422CC8(void);
extern void *EngineLazySingleton0054EFA8(void);
extern void CombatHit_DispatchPositiveStatusScale(void *context, uint32_t hit_flags,
                                   uint32_t source_flags);
extern void *Engine_LazySingletonGetter_004EEF34(void);
extern void *CachedComponentResolveClass1(void *object, void *descriptor);
extern uint32_t *StatusQueue_ApplyOrCreate(void *context, unsigned owner,
                                             int channel, int mode, int amount);
extern void EngineStatusEventSubmit(void *dispatcher, const uint32_t *payload);
extern void *Engine_LazySingletonGetter_0049BED0(void);
extern void StatusEventBuildCombatRecord(void *record, void *descriptor,
                                            const uint32_t payload[12],
                                            uint8_t mode,
                                            uint32_t event_value_bits);
extern uint32_t DamagePacketBuildFlags(void *context);
extern int StatusChannel_IndexMap(int identifier);
extern void *StatusSharedBaseGet(void);
extern void CombatHit_PrepareStatusChannel(void *status, float hidden_value);
extern void *ThresholdCounterSingleton(void);
extern float HealthThresholdEnsureAuxBuffer(int counter);
extern void *ThresholdResourceRegistrySingleton(void);
extern void *ResolveRelatedComponent(void *object);
extern void *OrderedTreeStatusComponentLookup(void *object);
extern void *ResolveStatusDescriptor(void *descriptor);
extern float DamagePacket_DispatchThresholdRaw(
    void *context, void *target, uint32_t packet_flags, uint32_t channel,
    uint32_t stack0, uint32_t stack1, uint32_t stack2, uint32_t stack3,
    uint32_t stack4, uint32_t stack5, uint32_t stack6,
    float amount, float hidden_threshold);
int DamageChannelPolicy_B(int channel);
struct CombatTransformRecordView {
    float quaternion[4];
    uint8_t opaque_010[0x44];
    float translation[3];
};
enum HealthThresholdGateMask {
    HEALTH_THRESHOLD_SUPPRESSION_MASK = 0x000841c0u
};
enum HealthThresholdComponentFlag {
    HEALTH_THRESHOLD_ENABLED = 0x08000000u,
    HEALTH_THRESHOLD_HANDLED = 0x04000000u
};
extern void *ResolveStatusDescriptor(void *descriptor);
extern uint32_t StatusLookupKey(void);
extern void *StatusTreeLookup(void *target, const uint32_t *key);
struct DamageSourceObject {
    uint32_t vtable;
    uint32_t kind;              
    uint8_t opaque_08[0x18];
    uint32_t source_class;      
    uint32_t action_or_weapon;  
    void *source_context;       
    void *source_data;          
    float profile_value;        
    float damage_value;         
    float damage_multiplier;    
    float damage_value_copy;    
    uint32_t opaque_40[8];
    uint32_t effect_flags;        
    uint32_t effect_options;      
    uint32_t opaque_68;
    void *effect_data;           
};
typedef char kiu_sa_combat_hit_1[(offsetof(struct DamageSourceObject, effect_flags) == 0x60) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_combat_hit_2[(offsetof(struct DamageSourceObject, source_data) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_combat_hit_3[(offsetof(struct DamageSourceObject, effect_options) == 0x64) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_combat_hit_4[(offsetof(struct DamageSourceObject, effect_data) == 0x6c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_combat_hit_5[(sizeof(struct DamageSourceObject) == 0x70) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_combat_hit_6[(offsetof(struct CombatTransformRecordView, translation) == 0x54) ? 1 : -1] __attribute__((unused));
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
uint32_t OwnerHandle_BuildVariant6(void *tree, uint32_t key);
extern void *GetSharedRegistrySingleton(void);
extern void StatusChannelResetOrReplace(void *status,
                                           StatusChannel channel,
                                           unsigned keep_replacement);
typedef void *(*ResourceFirstEntry)(void *resource);
uintptr_t HitSource_InvokeVtable74(void *source);
extern float DamagePacket_Dispatch(void *context, void *target,
                                    uint32_t packet_flags, uint32_t mode,
                                    int *descriptor_record, void *policy,
                                    int *source_record,
                                    float *out_auxiliary,
                                    float *out_damage,
                                    uint32_t delivery_flags,
                                    int delivery_mode, float amount,
                                    float scale);
extern void StatusOwnerStorePendingStateIfNotType5(void *owner,
                                                    uint32_t packet_flags,
                                                    float hidden_value);
extern void *StatusOwnerFindByHandle(void *base, uint32_t handle);
extern int CombatHit_ApplyOwnerScales(void *context, uint32_t hit_flags,
                                       uint32_t source_flags, int mode,
                                       float *primary, float *secondary);
extern int CombatHit_ThresholdGateAndDispatch(void *context, void *target,
                                               int mode);
extern int DamageShouldUpdateHitState(void *context, void *target,
                                       uint32_t packet_flags,
                                       uint32_t delivery_kind);
extern void CombatHit_ApplyPostDamageStatus(
    void *target, void *descriptor, struct DamageSourceObject *source,
    uint32_t mode, float hidden_value);
extern void *ResolveCachedComponent_1EC(void *object);
extern int DamageChannelPolicy_A(int channel);
extern int DamageChannelPolicy_C(int channel);
extern uint32_t CombatPacket_UpdateFamily1Counters(void *singleton,
                                                    uint32_t *record);
extern uint32_t StatusEvent_ResultCode_0059276C(void);
extern uint16_t StatusOwner_IndexByHandle(void *base, uint32_t handle);
extern int FUN_005c1acc(uint32_t index);
extern float Engine_StatusAccumulateIndexedDelta_005A970C(
    void *owner, uint8_t channel, float delta);
extern void *StatusOwner_IndexAddress(void *base, uint32_t index);
extern void FUN_005a5920(void *context, void *resource);
extern void ActorActionRecord_Initialize(void *record);
extern void *Engine_LazySingletonGetter_00498828(void);
extern void *Engine_LazySingletonGetter_004C59C0(void);
extern void *Engine_StatusVariantKey(void);
extern void FUN_005ba184(void *destination, void *owner, uint32_t *record);
extern int FUN_004edac8(void);
extern void FUN_005bba00(void *entry);
extern void FUN_00550ec4(void *destination, void *manager, uint8_t index,
                         void *owner_record);
extern void FUN_00550ee4(void *event, void *manager, void *owner_record);
static void ActorStatusCombatEvent_Continue_0057DC98(void *context,
                                                      uint32_t *record,
                                                      unsigned mode);
static void ActorStatusCombatEvent_ActionTail_005B12D4(void *resource,
                                                        uint32_t *record);
static const uint32_t *const kResourceIdentityB8B0 =
    (const uint32_t *)(uintptr_t)0x00c9b8b0u;
static const uint32_t *const kResourceIdentityB960 =
    (const uint32_t *)(uintptr_t)0x00c9b960u;
__attribute__((noinline)) int CombatHit_BuildAndDispatch(void *context, void *target,
                                struct DamageSourceObject *source)
{
    uint8_t *source_bytes = (uint8_t *)source;
    uint8_t *descriptor = (uint8_t *)ResolveStatusDescriptor(target);
    uint32_t descriptor_flags = *(uint32_t *)(descriptor + 0x20u);
    uint32_t packet_flags = *(uint32_t *)(source_bytes + 0x60u);
    uint32_t effect_options = *(uint32_t *)(source_bytes + 0x64u);
    uintptr_t source_mode = HitSource_InvokeVtable74(source);
    int *source_record = *(int **)(source_bytes + 0x2cu);
    int *descriptor_record = 0;
    void *policy = *(void **)(source_bytes + 0x6cu);
    void *entry;
    void *packet_owner = 0;
    void *owner = 0;
    void *pre_dispatch_component = 0;
    void *component = 0;
    float primary = 1.0f;
    float scale = 1.0f;
    float amount = source->profile_value;
    int owner_scale_changed = 0;
    int threshold_recorded = 0;
    *(float *)(source_bytes + 0x34u) = amount;
    *(float *)(source_bytes + 0x3cu) = amount;
    if (source_record != 0) {
        uintptr_t vtable = *(uintptr_t *)source_record;
        descriptor_record = (int *)(uintptr_t)
            ((uintptr_t (*)(void *))(*(uintptr_t *)(vtable + 0x20u)))
                (source_record);
    }
    entry = OrderedTreeLowerBoundByPointer(
        (uint8_t *)context + 0x171acu, (void *)(uintptr_t)effect_options);
    if ((packet_flags >> 28) == 1u) {
        static void **const singleton_slot =
            (void **)(uintptr_t)0x00d63578u;
        void *singleton = *singleton_slot;
        if (singleton == 0) {
            singleton = EngineLazySingleton0054EFA8();
            *singleton_slot = singleton;
        }
        packet_owner = StatusOwnerFindByHandle(
            (uint8_t *)singleton + 0xb3f8u, packet_flags);
        if (packet_owner != 0) {
            uint8_t threshold = *(uint8_t *)((uint8_t *)packet_owner + 0x382u);
            if (threshold != 0x0au)
                descriptor_record = (int *)(uintptr_t)threshold;
        }
    } else if (entry != 0) {
        uint8_t threshold = *(uint8_t *)((uint8_t *)entry + 0xd4u);
        if (threshold != 0x0au)
            descriptor_record = (int *)(uintptr_t)threshold;
    }
    pre_dispatch_component = ResolveRelatedComponent(target);
    if (entry == 0 && (packet_flags >> 28) == 1u) {
        owner_scale_changed = CombatHit_ApplyOwnerScales(
            context, packet_flags, descriptor_flags, (int)source_mode,
            &primary, &scale);
    } else if (entry != 0) {
        primary = *(float *)((uint8_t *)entry + 0x2cu);
        scale = *(float *)((uint8_t *)entry + 0x30u);
        if ((*(uint32_t *)((uint8_t *)entry + 0xc8u) & 2u) != 0u &&
            (descriptor_flags >> 28) == 2u &&
            CombatHit_ThresholdGateAndDispatch(context, target, 0) != 0)
            return 1;
        if ((descriptor_flags >> 28) == 1u) {
            static void **const singleton_slot =
                (void **)(uintptr_t)0x00d63578u;
            void *singleton = *singleton_slot;
            uint32_t handle;
            uint32_t resource;
            if (singleton == 0) {
                singleton = EngineLazySingleton0054EFA8();
                *singleton_slot = singleton;
            }
            owner = StatusOwnerFindByHandle(
                (uint8_t *)singleton + 0xb3f8u, descriptor_flags);
            threshold_recorded =
                *(float *)((uint8_t *)entry + 0xccu) > 0.0f;
            if ((effect_options >> 28) == 6u)
                handle = OwnerHandle_BuildVariant6(
                    (uint8_t *)context + 0x171acu, effect_options);
            else
                handle = FUN_00562D00(
                    (uint8_t *)context + 0xf98cu);
            resource = ResourceTableLookup(&handle);
            if (resource != 0) {
                uint8_t *resource_bytes = (uint8_t *)(uintptr_t)resource;
                uint32_t linked = *(uint32_t *)(resource_bytes + 0x168u);
                if (linked != 0 &&
                    *(uint32_t *)((uint8_t *)(uintptr_t)linked + 8u) ==
                        *kResourceIdentityB8B0) {
                    if (*(float *)((uint8_t *)entry + 0xccu) > 0.0f) {
                        *(float *)((uint8_t *)owner + 0x800u + 0x354u) =
                            *(float *)((uint8_t *)entry + 0xccu);
                        *(uint32_t *)((uint8_t *)owner + 0xad8u) |= 0x40u;
                    }
                    if (*(float *)((uint8_t *)entry + 0xd0u) > 0.0f) {
                        *(float *)((uint8_t *)owner + 0x804u + 0x354u) =
                            *(float *)((uint8_t *)entry + 0xd0u);
                        *(uint32_t *)((uint8_t *)owner + 0xad8u) |= 0x80u;
                    }
                }
            }
        }
        if (*(float *)((uint8_t *)entry + 0xd0u) > 0.0f ||
            threshold_recorded != 0)
            amount = 0.0f;
    } else if ((packet_flags >> 28) == 1u &&
               (descriptor_flags >> 28) == 1u) {
        static void **const singleton_slot =
            (void **)(uintptr_t)0x00d63578u;
        void *singleton = *singleton_slot;
        if (singleton == 0) {
            singleton = EngineLazySingleton0054EFA8();
            *singleton_slot = singleton;
        }
        owner = StatusOwnerFindByHandle(
            (uint8_t *)singleton + 0xb3f8u, descriptor_flags);
    }
    if (owner != 0 && *(uint32_t *)(source_bytes + 0x5cu) != 0) {
        if ((*(uint32_t *)((uint8_t *)owner + 0x478u) & 8u) != 0u &&
            0x3a85126fu < (uint32_t)source->profile_value &&
            *(uint32_t *)((uint8_t *)target + 0x168u) ==
                *kResourceIdentityB960)
            amount = 0.0f;
    }
    const uint32_t built_flags = DamagePacketBuildFlags(context);
    {
        float dispatch_result = DamagePacket_Dispatch(
            context, target, packet_flags, (uint32_t)source_mode,
            descriptor_record, policy, source_record,
            (float *)(source_bytes + 0x38u),
            (float *)(source_bytes + 0x3cu), 0, 1, amount, primary);
        if (dispatch_result >= 0.0f) {
            float output_scale = *(float *)(source_bytes + 0x38u) * scale;
            *(float *)(source_bytes + 0x38u) = output_scale;
            *(float *)(source_bytes + 0x34u) *= output_scale;
            if (owner_scale_changed && built_flags == packet_flags &&
                DamageShouldUpdateHitState(context, target, descriptor_flags,
                                            (uint32_t)source_mode) != 0)
                *((uint8_t *)context + 0xa73u) = 1;
            component = ResolveRelatedComponent(target);
            if (component != 0 && *(float *)((uint8_t *)component + 0x178u) > 0.0f)
                CombatHit_ApplyPostDamageStatus(
                    context, target, source, (uint32_t)source_mode,
                    dispatch_result);
            void *shared = StatusSharedBaseGet();
            float cap = *(float *)((uint8_t *)shared + 0xe4u);
            float amount_floor = *(float *)(source_bytes + 0x34u);
            if (amount_floor < 0.0f)
                amount_floor = 0.0f;
            if (amount_floor < cap)
                cap = amount_floor;
            *(float *)(source_bytes + 0x34u) = cap;
            if ((descriptor_flags >> 28) == 1u &&
                0x3a85126fu < (uint32_t)cap && owner != 0 &&
                (packet_flags >> 28) == 1u &&
                (*(uint32_t *)((uint8_t *)owner + 0x2d0u) == 0u ||
                 (pre_dispatch_component != 0 &&
                  (*(uint32_t *)((uint8_t *)pre_dispatch_component + 0x1dcu) & 8u) != 0u)))
                StatusOwnerStorePendingStateIfNotType5(owner, packet_flags, 1.0f);
            return 1;
        }
    }
    return 0;
}
__attribute__((noinline)) void ActorStatusCombatEvent_Build(void *context, void *target,
                                   struct DamageSourceObject *source,
                                   uint32_t *record)
{
    static const uint32_t *const global_limit =
        (const uint32_t *)(uintptr_t)0x00557400u;
    static void **const random_slot = (void **)(uintptr_t)0x00d63548u;
    static const uint32_t *const random_divisor =
        (const uint32_t *)(uintptr_t)0x0055740cu;
    uint8_t *record_bytes = (uint8_t *)record;
    uint32_t component_mask;
    uintptr_t mode;
    if (((record[6] & 2u) != 0u || record[3] == UINT32_MAX) &&
        (int32_t)record[2] <= (int32_t)*global_limit)
        return;
    void *descriptor = ResolveStatusDescriptor(target);
    if ((*(uint32_t *)((uint8_t *)descriptor + 0x20u) >> 28) != 1u)
        return;
    if ((int32_t)record[2] > (int32_t)*global_limit) {
        void *component = ResolveCachedComponent_1EC(target);
        component_mask = *(uint32_t *)((uint8_t *)component + 0x94u) &
                         0xe00000u;
        if (component_mask != 0u) {
            mode = HitSource_InvokeVtable74(source);
            if ((record_bytes[0x18] & 1u) == 0u &&
                (DamageChannelPolicy_B((int)mode) != 0 ||
                 DamageChannelPolicy_A((int)mode) != 0 ||
                 DamageChannelPolicy_C((int)mode) != 0) &&
                component_mask != 0xe00000u) {
                void *random = *random_slot;
                if (random == 0) {
                    random = Engine_LazySingletonGetter_004EEF34();
                    *random_slot = random;
                }
                uint32_t state0 = *(uint32_t *)((uint8_t *)random + 0x70u);
                uint32_t state1 = *(uint32_t *)((uint8_t *)random + 0x74u);
                uint32_t state2 = *(uint32_t *)((uint8_t *)random + 0x78u);
                uint32_t state3 = *(uint32_t *)((uint8_t *)random + 0x7cu);
                uint32_t mixed = state0 ^ (state0 << 11);
                mixed = mixed ^ (mixed >> 8) ^
                    (state3 ^ (state3 >> 19));
                *(uint32_t *)((uint8_t *)random + 0x70u) = state1;
                *(uint32_t *)((uint8_t *)random + 0x74u) = state2;
                *(uint32_t *)((uint8_t *)random + 0x78u) = state3;
                *(uint32_t *)((uint8_t *)random + 0x7cu) = mixed;
                uint32_t quotient = (uint32_t)(((uint64_t)mixed *
                    (uint64_t)*random_divisor) >> 37);
                uint32_t remainder = mixed - quotient * 100u;
                int32_t chance = (int32_t)(source->profile_value * 0.75f);
                if ((int32_t)remainder < chance)
                    record_bytes[0x18] |= 0x20u;
            }
        }
    }
    record[0] = *(uint32_t *)((uint8_t *)descriptor + 0x20u);
    record[1] = source->effect_flags;
    (void)OrderedTreeLowerBoundByPointer(
        (uint8_t *)context + 0x171acu,
        (void *)(uintptr_t)source->effect_options);
    mode = HitSource_InvokeVtable74(source);
    record_bytes[0x17] = (uint8_t)mode;
    {
        static void **const event_slot =
            (void **)(uintptr_t)0x00d63558u;
        void *event = *event_slot;
        if (event == 0) {
            event = Engine_LazySingletonGetter_0049BED0();
            *event_slot = event;
        }
        record[4] = StatusEvent_ResultCode_0059276C();
        event = *event_slot;
        if (event == 0) {
            event = Engine_LazySingletonGetter_0049BED0();
            *event_slot = event;
        }
        (void)CombatPacket_UpdateFamily1Counters(event, record);
    }
    ActorStatusCombatEvent_Continue_0057DC98(context, record, 1u);
}
static void ActorStatusCombatEvent_Continue_0057DC98(void *context,
                                                      uint32_t *record,
                                                      unsigned mode)
{
    uint8_t *context_bytes = (uint8_t *)context;
    uint32_t resource_value;
    void *resource;
    uint32_t handle;
    if ((record[0] >> 28) == 6u)
        handle = OwnerHandle_BuildVariant6(
            context_bytes + 0x171acu, record[0]);
    else
        handle = FUN_00562D00(context_bytes + 0xf98cu);
    resource_value = ResourceTableLookup(&handle);
    resource = (void *)(uintptr_t)resource_value;
    if ((record[1] >> 28) == 1u) {
        void *owner_base = context_bytes + 0xb3f8u;
        uint16_t index = StatusOwner_IndexByHandle(owner_base, record[1]);
        uint8_t mapped_index;
        void *owner;
        if (*(uint8_t *)(context_bytes + 0x123du) == 0)
            mapped_index = (uint8_t)(index + 1u);
        else
            mapped_index = *(uint8_t *)(*(uint32_t *)(context_bytes + 0xe4u) +
                                        (uint32_t)index * 4u + 0x0cu);
        if (FUN_005c1acc(mapped_index) != 0) {
            owner = StatusOwnerFindByHandle(owner_base, record[1]);
            Engine_StatusAccumulateIndexedDelta_005A970C(
                owner, ((uint8_t *)record)[0x17],
                *(float *)((uint8_t *)record + 0x08u));
            if (DamagePacketBuildFlags(context) == record[1]) {
                if (resource != 0)
                    FUN_005a5920(context, resource);
                index = StatusOwner_IndexByHandle(owner_base, record[0]);
                if (index != 0u) {
                    void *status = StatusOwner_IndexAddress(owner_base, index);
                    static void **const status_table_slot =
                        (void **)(uintptr_t)0x00d6364cu;
                    void *status_table = *status_table_slot;
                    if (status_table == 0) {
                        status_table = EngineLazySingleton00422CC8();
                        *status_table_slot = status_table;
                    }
                    uint8_t *status_bytes = (uint8_t *)status;
                    uint32_t *actor_state =
                        *(uint32_t **)(context_bytes + 0x1240u);
                    float rate = *(float *)((uint8_t *)status_table +
                                             index * 0x370u + 0x364u);
                    int32_t amount = *(int32_t *)(actor_state +
                                                  0x270u / 4u + index * 4u);
                    *(float *)(status_bytes + 0x708u) +=
                        (*(float *)((uint8_t *)record + 0x08u) /
                         rate) * (float)amount;
                }
            }
        }
    }
    if (resource != 0 && mode == 0u)
        ActorStatusCombatEvent_ActionTail_005B12D4(resource, record);
}
static void ActorStatusCombatEvent_ActionTail_005B12D4(void *resource,
                                                        uint32_t *record)
{
    uint8_t *resource_bytes = (uint8_t *)resource;
    uint8_t *record_bytes = (uint8_t *)record;
    uint8_t *base = resource_bytes + 0x30u;
    void *entry = 0;
    void *manager;
    static void **const manager_slot = (void **)(uintptr_t)0x00d63600u;
    ActorActionRecord_Initialize(base + 0x8u);
    resource_bytes[0x54] = (uint8_t)((resource_bytes[0x54] & 0xf9u) | 1u |
                                     ((record[6] & 2u) << 2));
    resource_bytes[0x54] = (uint8_t)((resource_bytes[0x54] & 0xefu) |
                                     ((record[6] & 4u) << 3));
    resource_bytes[0x54] &= (uint8_t)~0x40u;
    resource_bytes[0x54] &= (uint8_t)~0x80u;
    resource_bytes[0x55] = (uint8_t)((resource_bytes[0x55] & 0xdfu) |
                                     ((record_bytes[0x18] >> 3) & 1u));
    resource_bytes[0x55] &= (uint8_t)~0x16u;
    resource_bytes[0x55] &= (uint8_t)~0x8u;
    resource_bytes[0x3b] = 3u;
    resource_bytes[0x3a] = record_bytes[0x15];
    resource_bytes[0x39] = record_bytes[0x16];
    resource_bytes[0x38] = record_bytes[0x17];
    resource_bytes[0x3c] = record_bytes[0x14];
    *(float *)(resource_bytes + 0x40u) = 1.0f;
    *(uint32_t *)(resource_bytes + 0x44u) = *(uint32_t *)(base + 0x54u);
    *(uint32_t *)(resource_bytes + 0x48u) = *(uint32_t *)(base + 0x58u);
    *(uint32_t *)(resource_bytes + 0x4cu) = *(uint32_t *)(base + 0x5cu);
    entry = *(void **)(base + 0x1e4u);
    if (entry == 0) {
        void *key = Engine_LazySingletonGetter_00498828();
        uint8_t *node = OrderedTreeLowerBoundByPointer(
            base + 0x1a4u, key);
        void *head = node != 0 ? *(void **)node : (void *)0;
        void *next = *(void **)(base + 0x1a8u);
        if (head != next) {
            entry = head;
            if (entry != 0) {
                *(void **)((uint8_t *)entry + 0x1cu) = base;
                *(void **)(base + 0x1e4u) = entry;
            }
        }
    }
    if (entry != 0 && *(void **)((uint8_t *)entry + 0x38u) != 0 &&
        FUN_004edac8() != 0)
        return;
    if (resource_bytes[0x38] == 0x0eu)
        return;
    FUN_005ba184(resource_bytes + 0x120u, base, record);
    {
        void *key = Engine_StatusVariantKey();
        uint8_t *node = OrderedTreeLowerBoundByPointer(base + 0x1a4u, key);
        void *head = node != 0 ? *(void **)node : (void *)0;
        void *next = *(void **)(base + 0x1a8u);
        if (head != next && head != 0)
            FUN_005bba00(head);
    }
    if ((resource_bytes[0x54] & 0x20u) != 0)
        return;
    manager = *manager_slot;
    if (manager == 0) {
        manager = Engine_LazySingletonGetter_004C59C0();
        *manager_slot = manager;
    }
    {
        void *manager_record = (uint8_t *)manager + 0x4664u;
        if ((resource_bytes[0x55] & 1u) != 0)
            FUN_00550ec4(resource_bytes + 0x164u, manager_record,
                         resource_bytes[0x3a], base + 0x54u);
        if ((record[6] & 0x10u) != 0)
            FUN_00550ee4(*(void **)((uint8_t *)manager_record + 0x2bcu),
                         manager_record, base + 0x54u);
    }
}
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *ResolveRelatedComponent(void *object);
extern uint32_t ResourceTableLookup(uint32_t *handle);
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
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
extern void *ResolveRelatedComponent(void *object);
extern void *ResolveStatusDescriptor(void *descriptor);
extern void *GetSharedRegistrySingleton(void);
extern uint32_t ResourceTableLookup(uint32_t *handle);
extern void StatusChannelResetOrReplace(void *actor,
                                           StatusChannel channel,
                                           unsigned keep_replacement);
extern uint32_t StatusDescriptorReadWord(void *object, unsigned field,
                                             unsigned mode);
extern void *StatusRelatedRecordResolve(void *object, unsigned mode);
extern void *GetStatusCapabilityKey(void);
extern void *GetStatusBacklinkKey(void);
extern uint8_t *OrderedTreeLowerBoundByPointer(void *tree,
                                                   void *descriptor);
void StatusOwnerIncrementPendingCountIfNotType5(void *owner);
unsigned OneHotMaskIndex(void *ignored, uint32_t mask);
uint32_t HitDebuff_ResolveAndAccumulate(void *descriptor,
                                          void *source_data,
                                          void *source_effects,
                                          uint32_t mode,
                                          uint32_t source_flags,
                                          uint32_t source_options,
                                          float hidden_value);
uint32_t DamagePacketBuildFlags(void *context);
uint32_t StatusContextGetFlags(void *status_context, uint32_t key);
int DamageShouldUpdateHitState(void *context, void *target,
                                  uint32_t packet_flags,
                                  uint32_t unused_delivery_kind);
void *StatusOwnerIndexAddress(void *base, int8_t index);
void *StatusOwnerFindByHandle(void *base, uint32_t handle);
unsigned StatusOwnerIndexByHandle(void *base, uint32_t handle);
void CombatHit_DispatchPositiveStatusScale(void *context, uint32_t hit_flags,
                            uint32_t source_flags);
int CombatHit_ThresholdGateAndDispatch(void *context, void *target,
                                         int mode);
int CombatHit_ApplyOwnerScales(void *context, uint32_t hit_flags,
                                 uint32_t source_flags, int mode,
                                 float *primary, float *secondary);
void CombatHit_PrepareStatusChannel(void *status, float hidden_value);
int Status_ResetModeGate(void *ignored_status);
int Status_AccumulateChannelValue(void *status, float hidden_value);
uint32_t *StatusQueue_ApplyOrCreate(void *context, unsigned owner,
                                      int channel, int mode, int amount);
void StatusEventBuildCombatRecord(void *record, void *descriptor,
                                     const uint32_t payload[12],
                                     uint8_t mode,
                                     uint32_t event_value_bits);
int StatusComponentHasBit00800000(void *object);
int DamageTargetPassesSpecialResourceFilter(void *target);
int DamageTargetEvaluateResourceChannelGate(void *target, unsigned channel);
void StatusHitIncrementOwnerChannel(void *counter_table,
                                        unsigned channel,
                                        void *descriptor);
void StatusChannelResetOrReplace(void *status, StatusChannel channel,
                                    unsigned store_replacement);
void DamageOwner_AccumulateIndexedValues(struct StatusOwnerView *owner,
                                           uint32_t first_index,
                                           uint32_t second_index,
                                           float hidden_value);
int StatusDescriptorClassNibble(void *descriptor);
void CombatHit_ApplyPostDamageStatus(void *target,
                                       void *descriptor,
                                       struct DamageSourceObject *source,
                                       uint32_t mode,
                                       float hidden_value);
int DamageChannelPolicy_B(int channel);
int DamageTargetHasOwnerCapability(void *target);
void *DamageTargetGetOwnerBacklink(void *target);
extern void *ResolveCachedComponent_1EC(void *object);
extern uint8_t SharedRegistryGetIndexedValue(unsigned index);
extern void BoundedIntSetInsert(void *set, int value);
extern uint32_t PackedHandleBuild(int kind, unsigned index, int active);
extern uint32_t PackedHandleBuildSubtype(unsigned index);
extern void StatusEventTemporaryRecordBuild(
    void *output, int mode, int key, const uint32_t *vector_a,
    const uint32_t *vector_b, uint32_t scalar, void *source,
    uint32_t auxiliary, uint32_t hidden);
extern int StatusEventSubmitRecord(void *context, void *record,
                                    uint32_t flags, void **accepted);
extern void StatusEventForwardAcceptedRecord(void *dispatcher,
                                               const void *payload);
extern void *FUN_004EEB08(void *accepted);
__attribute__((noinline)) void CombatEvent_RouteResourceEffect(void *context, void *target)
{
    uint8_t *bytes = (uint8_t *)context;
    uint8_t *descriptor;
    uint8_t selected_class;
    uint8_t descriptor_class;
    uint8_t *class_table;
    const int16_t *slot_keys = (const int16_t *)(uintptr_t)0x00ca8850u;
    const uint32_t *generation_table =
        (const uint32_t *)(uintptr_t)0x00e11614u;
    (void)ResolveCachedComponent_1EC(target);
    descriptor = (uint8_t *)ResolveStatusDescriptor(target);
    descriptor_class = *(uint8_t *)(descriptor + 0x2cu);
    class_table = *(uint8_t **)(bytes + 0xe4u);
    selected_class = class_table[0x0cu + descriptor_class * 0x1cu];
    for (unsigned slot = 0; slot < 3u; ++slot) {
        uint32_t packed;
        uint32_t generation;
        uint32_t index;
        uint32_t table_value;
        uint32_t table_generation;
        uint32_t owner_handle;
        uint8_t *resource;
        int16_t key;
        uint8_t record[0x80];
        void *accepted = 0;
        if (SharedRegistryGetIndexedValue(slot) != selected_class)
            continue;
        packed = *(uint32_t *)(bytes + 0xbf4u + slot * 4u);
        generation = packed >> 9;
        index = packed & 0x1ffu;
        table_value = generation_table[index * 2u];
        table_generation = generation_table[index * 2u + 1u];
        if ((generation != 0x7fffffu &&
             (table_generation != generation || table_value != 0)) ||
            *(int32_t *)(bytes + 0xbe8u + slot * 4u) >= 1)
            continue;
        key = slot_keys[slot];
        if ((*(uint32_t *)(descriptor + 0x20u) >> 28) == 6u)
            owner_handle = OwnerHandle_BuildVariant6(
                bytes + 0x171acu, *(uint32_t *)(descriptor + 0x20u));
        else
            owner_handle = FUN_00562D00(bytes + 0xf98cu);
        resource = (uint8_t *)(uintptr_t)ResourceTableLookup(&owner_handle);
        if (resource == 0)
            continue;
        BoundedIntSetInsert(bytes + 0x1ec70u, (int)key);
        {
            static void **engine_slot = (void **)(uintptr_t)0x00d63578u;
            void *engine = *engine_slot;
            uint32_t event_handle;
            if (engine == 0) {
                engine = EngineLazySingleton0054EFA8();
                *engine_slot = engine;
            }
            if (engine == 0 || *(uint8_t *)((uint8_t *)engine + 0x123cu) == 0 ||
                *(uint8_t *)((uint8_t *)engine + 0x123du) == 0)
                event_handle = PackedHandleBuild(3, 0xa00u, 1);
            else
                event_handle = PackedHandleBuildSubtype(0xfeu);
            StatusEventTemporaryRecordBuild(
                record, 3, (int)key, (const uint32_t *)(resource + 0x74u),
                (const uint32_t *)(resource + 0x64u), 2u, 0, 0, 0);
            record[0x60u] = 5u;
            record[0x61u] = 1u;
            *(uint32_t *)(record + 0x64u) = event_handle;
            record[0x74u] = 0;
        }
        (void)StatusEventSubmitRecord(context, record, 0, &accepted);
        if (accepted != 0 && *(uint8_t *)(bytes + 0x123du) != 0) {
            uint8_t payload[0x44] = {0};
            void *resolved_accepted = FUN_004EEB08(accepted);
            uint8_t *accepted_bytes = (uint8_t *)resolved_accepted;
            uint8_t *accepted_descriptor;
            uint32_t class_word = 0;
            *(uint16_t *)(payload + 0x00u) = key;
            *(uint32_t *)(payload + 0x08u) =
                *(uint32_t *)(accepted_bytes + 0x74u);
            *(uint32_t *)(payload + 0x0cu) =
                *(uint32_t *)(accepted_bytes + 0x78u);
            *(uint32_t *)(payload + 0x10u) =
                *(uint32_t *)(accepted_bytes + 0x7cu);
            *(uint32_t *)(payload + 0x14u) =
                *(uint32_t *)(accepted_bytes + 0x64u);
            *(uint32_t *)(payload + 0x18u) =
                *(uint32_t *)(accepted_bytes + 0x68u);
            *(uint32_t *)(payload + 0x1cu) =
                *(uint32_t *)(accepted_bytes + 0x6cu);
            *(uint32_t *)(payload + 0x20u) =
                *(uint32_t *)(accepted_bytes + 0x70u);
            *(uint32_t *)(payload + 0x28u) = 5u;
            accepted_descriptor =
                (uint8_t *)ResolveStatusDescriptor(resolved_accepted);
            if (accepted_descriptor != 0)
                class_word = *(uint32_t *)(accepted_descriptor + 0x20u);
            *(uint32_t *)(payload + 0x2cu) = class_word;
            *(uint32_t *)(payload + 0x34u) =
                *(uint32_t *)(resource + 0x68u);
            *(uint32_t *)(payload + 0x38u) =
                *(uint32_t *)(resource + 0x6cu);
            *(uint32_t *)(payload + 0x3cu) =
                *(uint32_t *)(resource + 0x70u);
            StatusEventForwardAcceptedRecord(
                *(void **)(bytes + 0x1240u), payload);
        }
    }
}
__attribute__((noinline)) uintptr_t HitSource_InvokeVtable74(void *source)
{
    void *object = *(void **)((uint8_t *)source + 0x2c);
    if (object == 0)
        return 0;
    return ((uintptr_t (*)(void *))(*(void ***)object)
        [0x74u / sizeof(void *)])(object);
}
__attribute__((noinline)) int DamageShouldUpdateHitState(void *context, void *target,
                                  uint32_t packet_flags,
                                  uint32_t unused_delivery_kind)
{
    uint8_t *bytes = (uint8_t *)context;
    uint32_t family;
    (void)unused_delivery_kind;
    if (bytes[STATUS_SELECTOR_A] != 0 &&
        bytes[STATUS_SELECTOR_B] != 0)
        return 0;
    family = packet_flags >> 28;
    if (family == 1u)
        return (StatusContextGetFlags(bytes + 0xf98c, packet_flags) &
                0x10000u) != 0;
    if (family == 2u) {
        uint8_t *descriptor =
            (uint8_t *)ResolveStatusDescriptor(target);
        uint16_t id;
        uint32_t key;
        uint8_t *record;
        if (descriptor == 0)
            return 0;
        id = *(const uint16_t *)(descriptor + 0x20);
        if (id < 0x1f4u || id >= 0x21cu || id != 0x1fdu)
            return 0;
        key = StatusLookupKey();
        record = (uint8_t *)StatusTreeLookup(target, &key);
        return record != 0 && *(uint32_t *)(record + 0x1c) != 0 &&
               *(uint8_t *)(*(uint32_t *)(record + 0x1c) + 0x7c) == 1;
    }
    return 0;
}
__attribute__((noinline)) void CombatHit_DispatchPositiveStatusScale(void *context, uint32_t hit_flags,
                            uint32_t source_flags)
{
    uint8_t *bytes = (uint8_t *)context;
    uint8_t *owners = bytes + 0xb3f8u;
    uint32_t handle;
    uint8_t *descriptor;
    uint8_t *component;
    uint8_t *source_owner;
    uint8_t *dispatch_slot;
    uint8_t *list;
    uint8_t *selected = 0;
    uint8_t *resource;
    uint8_t *dispatcher;
    uint32_t *queue_record;
    uint32_t event[4];
    uint32_t payload[12];
    unsigned source_owner_index;
    unsigned owner_index;
    unsigned count;
    unsigned active_count = 0;
    unsigned selected_index;
    uint32_t random_word;
    float q0;
    float q1;
    float q2;
    float q3;
    float matrix[12];
    const float *q = (const float *)(uintptr_t)0x00dc2538u;
    if ((hit_flags >> 28) == 6u)
        handle = OwnerHandle_BuildVariant6(bytes + 0x171acu, hit_flags);
    else
        handle = FUN_00562D00(bytes + 0xf98cu);
    descriptor = (uint8_t *)(uintptr_t)ResourceTableLookup(&handle);
    if (descriptor == 0)
        return;
    source_owner_index = StatusOwnerIndexByHandle(owners, source_flags);
    component = (uint8_t *)CachedComponentResolveClass1(context, descriptor);
    if (component == 0 || (*(uint32_t *)(component + 0x60u) & 0x20000u) == 0)
        return;
    owner_index = StatusOwnerIndexByHandle(owners, hit_flags);
    source_owner = (uint8_t *)StatusOwnerIndexAddress(
        owners, (int8_t)source_owner_index);
    dispatch_slot = source_owner + owner_index * 8u;
    if (dispatch_slot[0xb68u] != 0)
        return;
    dispatch_slot[0xb68u] = 1;
    *(float *)(dispatch_slot + 0xb6cu) = 5.0f;
    list = bytes + source_owner_index * 0x8b8u + 0x1258u;
    count = *(uint32_t *)(bytes + source_owner_index * 0x8b8u + 0x13ecu);
    for (selected_index = 0; selected_index < count; ++selected_index) {
        if (*(int32_t *)(list + selected_index * 0x10u + 4u) > 0)
            ++active_count;
    }
    if (active_count == 0)
        return;
    {
        static void **const prng_slot =
            (void **)(uintptr_t)0x00d63548u;
        uint8_t *prng = (uint8_t *)*prng_slot;
        if (prng == 0) {
            prng = (uint8_t *)Engine_LazySingletonGetter_004EEF34();
            *prng_slot = prng;
        }
        uint32_t x = *(uint32_t *)(prng + 0x70u);
        uint32_t w = *(uint32_t *)(prng + 0x7cu);
        *(uint32_t *)(prng + 0x70u) = *(uint32_t *)(prng + 0x74u);
        *(uint32_t *)(prng + 0x74u) = *(uint32_t *)(prng + 0x78u);
        x ^= x << 11;
        x ^= x >> 8;
        x ^= w ^ (w >> 19);
        *(uint32_t *)(prng + 0x78u) = w;
        *(uint32_t *)(prng + 0x7cu) = x;
        random_word = x;
    }
    selected_index = random_word % active_count;
    for (unsigned index = 0; index < count; ++index) {
        uint8_t *candidate = list + index * 0x10u;
        if (*(int32_t *)(candidate + 4u) > 0) {
            if (selected_index == 0) {
                selected = candidate;
                break;
            }
            --selected_index;
        }
    }
    if (selected == 0)
        return;
    queue_record = StatusQueue_ApplyOrCreate(
        context, source_owner_index, *(int16_t *)selected, -1, 0);
    (void)queue_record;
    event[0] = 0x10u;
    event[1] = source_flags;
    event[2] = hit_flags;
    event[3] = (uint32_t)(int32_t)*(int16_t *)selected;
    {
        static void **event_slot = (void **)(uintptr_t)0x00d63558u;
        void *event_dispatcher = *event_slot;
        if (event_dispatcher == 0) {
            event_dispatcher = Engine_LazySingletonGetter_0049BED0();
            *event_slot = event_dispatcher;
        }
        EngineStatusEventSubmit(event_dispatcher, event);
    }
    resource = (uint8_t *)(uintptr_t)ResourceTableLookup(
        (uint32_t *)(bytes + 0xb278u));
    if (source_owner_index != 0 || resource == 0)
        return;
    dispatcher = *(uint8_t **)(uintptr_t)0x00d6385cu;
    if (dispatcher == 0) {
        dispatcher = (uint8_t *)EngineSharedObjectSingleton004C5BA4();
        *(uint8_t **)(uintptr_t)0x00d6385cu = dispatcher;
    }
    if (*(uint32_t *)(dispatcher +
                      (((*(uint32_t *)(bytes + 0x80u) & 0xffffu) >> 8) *
                       0xcu) + 0x324u) ==
        *(uint32_t *)(bytes + 0x80u))
        return;
    q0 = q[0];
    q1 = q[1];
    q2 = q[2];
    q3 = q[3];
    matrix[0] = 1.0f - 2.0f * (q1 * q1 + q2 * q2);
    matrix[1] = 2.0f * (q0 * q1 - q2 * q3);
    matrix[2] = 2.0f * (q0 * q2 + q1 * q3);
    matrix[3] = *(float *)(resource + 0x54u);
    matrix[4] = 2.0f * (q0 * q1 + q2 * q3);
    matrix[5] = 1.0f - 2.0f * (q0 * q0 + q2 * q2);
    matrix[6] = 2.0f * (q1 * q2 - q0 * q3);
    matrix[7] = *(float *)(resource + 0x58u);
    matrix[8] = 2.0f * (q0 * q2 - q1 * q3);
    matrix[9] = 2.0f * (q1 * q2 + q0 * q3);
    matrix[10] = 1.0f - 2.0f * (q0 * q0 + q1 * q1);
    matrix[11] = *(float *)(resource + 0x5cu);
    for (unsigned index = 0; index < 12; ++index) {
        union { float f; uint32_t u; } bits;
        bits.f = matrix[index];
        payload[index] = bits.u;
    }
    StatusEventBuildCombatRecord(bytes + 0x80u, descriptor, payload, 3u, 0u);
}
__attribute__((noinline)) void StatusEffect_QueueAndBuildTransform_005A6274(
    void *context, uint32_t hit_flags, uint32_t packet_flags,
    int channel, int mode)
{
    uint8_t *bytes = (uint8_t *)context;
    uint32_t packet_mask = DamagePacketBuildFlags(context);
    int requested_index;
    int selected_index;
    int count;
    int queued_channel = channel;
    int queue_mode = mode;
    uint32_t handle;
    uint8_t *descriptor;
    uint8_t *resource;
    uint32_t payload[12];
    float matrix[12];
    int mapped_channel;
    if (packet_flags != packet_mask || channel >= 0xd1)
        return;
    requested_index = StatusChannel_IndexMap(channel);
    count = *(int32_t *)(bytes + 0x13ecu);
    for (selected_index = 0; selected_index < count; ++selected_index) {
        uint8_t *candidate = bytes + 0x1258u + selected_index * 0x10u;
        if (StatusChannel_IndexMap(*(int16_t *)candidate) ==
            requested_index) {
            queued_channel = *(int16_t *)candidate;
            queue_mode = 100;
            break;
        }
    }
    if (queue_mode != 100) {
        int16_t inline_channel = *(int16_t *)(bytes + 0x13f0u);
        if (inline_channel != -1 &&
            StatusChannel_IndexMap(inline_channel) == requested_index) {
            queued_channel = inline_channel;
            queue_mode = 100;
        }
    }
    StatusQueue_ApplyOrCreate(context, 0u, queued_channel, queue_mode, 0);
    descriptor = (uint8_t *)(uintptr_t)ResourceTableLookup(
        (uint32_t *)(bytes + 0xb278u));
    if ((hit_flags >> 28) == 6u)
        handle = OwnerHandle_BuildVariant6(bytes + 0x171acu, hit_flags);
    else
        handle = FUN_00562D00(bytes + 0xf98cu);
    resource = (uint8_t *)(uintptr_t)ResourceTableLookup(&handle);
    if (descriptor == 0 || resource == 0)
        return;
    mapped_channel = requested_index;
    {
        const float *q = (const float *)(uintptr_t)0x00dc2538u;
        matrix[0] = 1.0f - 2.0f * (q[1] * q[1] + q[2] * q[2]);
        matrix[1] = 2.0f * (q[0] * q[1] - q[2] * q[3]);
        matrix[2] = 2.0f * (q[0] * q[2] + q[1] * q[3]);
        matrix[3] = *(float *)(resource + 0x54u);
        matrix[4] = 2.0f * (q[0] * q[1] + q[2] * q[3]);
        matrix[5] = 1.0f - 2.0f * (q[0] * q[0] + q[2] * q[2]);
        matrix[6] = 2.0f * (q[1] * q[2] - q[0] * q[3]);
        matrix[7] = *(float *)(resource + 0x58u);
        matrix[8] = 2.0f * (q[0] * q[2] - q[1] * q[3]);
        matrix[9] = 2.0f * (q[1] * q[2] + q[0] * q[3]);
        matrix[10] = 1.0f - 2.0f * (q[0] * q[0] + q[1] * q[1]);
        matrix[11] = *(float *)(resource + 0x5cu);
    }
    for (unsigned index = 0; index < 12u; ++index) {
        union { float f; uint32_t u; } bits;
        bits.f = matrix[index];
        payload[index] = bits.u;
    }
    StatusEventBuildCombatRecord(bytes + 0x80u, descriptor, payload, 2u,
                                 (uint32_t)mapped_channel);
}
__attribute__((noinline)) int CombatHit_ThresholdGateAndDispatch(void *context, void *target,
                                         int mode)
{
    static void **parameter_slot = (void **)(uintptr_t)0x00d6364cu;
    static void **counter_slot = (void **)(uintptr_t)0x00d635f8u;
    static void **engine_slot = (void **)(uintptr_t)0x00d6365cu;
    uint8_t *parameters = (uint8_t *)*parameter_slot;
    struct HealthStatusComponent *threshold_component;
    struct HealthStatusComponent *health_component;
    uint8_t *descriptor;
    uint8_t *cached_descriptor;
    uint8_t *engine;
    uint32_t flags;
    uint32_t delivery_marker = 1u;
    int16_t descriptor_id;
    uint32_t resource_id;
    uint32_t table_value;
    const uint32_t *table;
    unsigned index;
    float q0;
    float q1;
    float q2;
    float q3;
    float matrix[12];
    uint32_t payload[12];
    if (parameters == 0) {
        parameters = (uint8_t *)EngineLazySingleton00422CC8();
        *parameter_slot = parameters;
    }
    if (parameters == 0 || (*(uint32_t *)(parameters + 0x1f18u) & 0x1eu) != 0)
        return 0;
    engine = (uint8_t *)*counter_slot;
    if (engine == 0) {
        engine = (uint8_t *)ThresholdCounterSingleton();
        *counter_slot = engine;
    }
    if (engine == 0 || *(int32_t *)engine < 0x14)
        return 0;
    resource_id = (uint32_t)*(int32_t *)engine;
    threshold_component = (struct HealthStatusComponent *)
        OrderedTreeStatusComponentLookup(target);
    if (threshold_component == 0 ||
        (threshold_component->threshold_flags_088 & HEALTH_THRESHOLD_ENABLED) == 0)
        return 0;
    health_component = (struct HealthStatusComponent *)
        ResolveRelatedComponent(target);
    if (health_component == 0)
        return 0;
    if (HealthThresholdEnsureAuxBuffer(*(int32_t *)engine) <=
        health_component->current_hp.value)
        return 0;
    flags = health_component->flags;
    if (mode == 0 && (flags & 4u) != 0) {
        if ((flags & HEALTH_THRESHOLD_SUPPRESSION_MASK) != 0)
            return 0;
        delivery_marker = 0u;
    }
    cached_descriptor = (uint8_t *)CachedDescriptorResolve(target);
    descriptor = (uint8_t *)(uintptr_t)ResourceTableLookup(
        (uint32_t *)((uint8_t *)context + 0xb278u));
    if (descriptor == 0)
        goto mark_threshold;
    descriptor_id = *(int16_t *)(cached_descriptor + 0x20u);
    resource_id = (uint32_t)(int32_t)descriptor_id;
    if ((unsigned)(descriptor_id - 100) < 0x9du) {
        table = (const uint32_t *)(uintptr_t)0x00ca88a4u;
        index = (unsigned)descriptor_id - 100u;
    } else if ((unsigned)(descriptor_id - 500) < 0x28u) {
        table = (const uint32_t *)(uintptr_t)0x00ca8b18u;
        index = (unsigned)descriptor_id - 500u;
    } else {
        goto mark_threshold;
    }
    table_value = table[index];
    if (table_value == 0x19cu)
        goto mark_threshold;
    resource_id = table_value;
    {
        const float *quaternion = (const float *)(uintptr_t)0x00dc2538u;
        q0 = quaternion[0];
        q1 = quaternion[1];
        q2 = quaternion[2];
        q3 = quaternion[3];
    }
    matrix[0] = 1.0f - 2.0f * (q1 * q1 + q2 * q2);
    matrix[1] = 2.0f * (q0 * q1 - q2 * q3);
    matrix[2] = 2.0f * (q0 * q2 + q1 * q3);
    matrix[3] = *(float *)((uint8_t *)target + 0x54u);
    matrix[4] = 2.0f * (q0 * q1 + q2 * q3);
    matrix[5] = 1.0f - 2.0f * (q0 * q0 + q2 * q2);
    matrix[6] = 2.0f * (q1 * q2 - q0 * q3);
    matrix[7] = *(float *)((uint8_t *)target + 0x58u);
    matrix[8] = 2.0f * (q0 * q2 - q1 * q3);
    matrix[9] = 2.0f * (q1 * q2 + q0 * q3);
    matrix[10] = 1.0f - 2.0f * (q0 * q0 + q1 * q1);
    matrix[11] = *(float *)((uint8_t *)target + 0x5cu);
    for (index = 0; index < 12u; ++index) {
        union { float f; uint32_t u; } bits;
        bits.f = matrix[index];
        payload[index] = bits.u;
    }
    StatusEventBuildCombatRecord((uint8_t *)context + 0x80u, descriptor,
                                 payload, 1u, resource_id);
    engine = (uint8_t *)*engine_slot;
    if (engine == 0) {
        engine = (uint8_t *)ThresholdResourceRegistrySingleton();
        *engine_slot = engine;
    }
    if (engine != 0) {
        uint8_t *counter = engine + 0x6278u + resource_id;
        unsigned value = (unsigned)counter[0x46cu] + 1u;
        counter[0x46cu] = (uint8_t)(value > 100u ? 100u : value);
    }
mark_threshold:
    threshold_component->threshold_flags_088 |= HEALTH_THRESHOLD_HANDLED;
    if (mode == 0) {
        uint32_t class_word = 0u;
        (void)DamagePacket_DispatchThresholdRaw(
            context, target, 0, 0x10u,
            0u, 0u, 0u, 0u, 0u, delivery_marker, 1u,
            10.0f * health_component->maximum_hp.value, 1.0f);
        {
            void *resolved = ResolveStatusDescriptor(target);
            if (resolved != 0)
                class_word = *(uint32_t *)((uint8_t *)resolved + 0x20u);
        }
        if (DamageShouldUpdateHitState(context, target, class_word, 0x10u))
            *((uint8_t *)context + 0xa73u) = 0u;
    }
    return 1;
}
__attribute__((noinline)) int CombatHit_ApplyOwnerScales(void *context, uint32_t hit_flags,
                                 uint32_t source_flags, int mode,
                                 float *primary, float *secondary)
{
    struct StatusOwnerView *owner =
        (struct StatusOwnerView *)StatusOwnerFindByHandle(
            (uint8_t *)context + 0xb3f8, hit_flags);
    uint32_t handle;
    uint8_t *resource;
    uint32_t mask;
    unsigned index;
    int linked_scale = 0;
    if ((hit_flags >> 28) == 6u)
        handle = OwnerHandle_BuildVariant6((uint8_t *)context + 0x171ac,
                                           hit_flags);
    else
        handle = FUN_00562D00((uint8_t *)context + 0xf98c);
    resource = (uint8_t *)(uintptr_t)ResourceTableLookup(&handle);
    if ((mode == 1 || mode == 2) && resource != 0) {
        uint8_t *linked = *(uint8_t **)(resource + 0x168);
        if (linked != 0) {
            void *(*first_entry)(void *) =
                (void *(*)(void *))(*(void ***)linked)[0];
            void *node = first_entry(linked);
            void *sentinel = (void *)(uintptr_t)0x00d63984u;
            if (node == sentinel) {
                if (DamagePacketBuildFlags(context) == hit_flags) {
                    StatusOwnerIncrementPendingCountIfNotType5(owner);
                    void *shared = StatusSharedBaseGet();
                    CombatHit_PrepareStatusChannel(
                        context, *(float *)((uint8_t *)shared + 0xd8u));
                }
                linked_scale =
                    (*(uint8_t *)((uint8_t *)linked + 0xa4u) & 2u) != 0;
            }
        }
    }
    mask = linked_scale ? 0x200u : 0x100u;
    if (mode == 6 || mode == 7)
        mask = 0x400u;
    if (mode == 1 || mode == 2) {
        uint8_t *scale_table = (uint8_t *)owner + 0x2d8;
        index = OneHotMaskIndex(scale_table, mask);
        *primary *= *(float *)(scale_table + index * sizeof(float));
        *secondary *= *(float *)(scale_table + 0x3c + index * sizeof(float));
        if ((owner->flags_478 & 4u) != 0)
            *primary *= owner->scale_6f4 + 1.0f;
        if ((owner->flags_478 & 0x100u) != 0)
            *primary *= owner->scale_700 + 1.0f;
        if (*(uint8_t *)((uint8_t *)context + 0x123du) != 0 &&
            (source_flags >> 28) == 1u)
            CombatHit_DispatchPositiveStatusScale(context, hit_flags,
                                                   source_flags);
    } else if (mode == 6 || mode == 7) {
        uint8_t *scale_table = (uint8_t *)owner + 0x2d8;
        index = OneHotMaskIndex(scale_table, 0x400u);
        *primary *= *(float *)(scale_table + index * sizeof(float));
        *secondary *= *(float *)(scale_table + 0x3cu + index * sizeof(float));
    }
    return linked_scale;
}
__attribute__((noinline)) void CombatHit_PrepareStatusChannel(void *status, float hidden_value)
{
    static void **shared_slot = (void **)(uintptr_t)0x00d63654u;
    static void **parameter_slot = (void **)(uintptr_t)0x00d6364cu;
    void *shared = *shared_slot;
    void *parameters;
    if (shared == 0) {
        shared = GetSharedRegistrySingleton();
        *shared_slot = shared;
    }
    if (!Status_ResetSharedEligibility(shared))
        return;
    parameters = *parameter_slot;
    if (parameters == 0) {
        parameters = EngineLazySingleton00422CC8();
        *parameter_slot = parameters;
    }
    if (*(uint8_t *)((uint8_t *)parameters + 0x1efdu) != 0)
        return;
    if (!Status_ResetModeGate(status))
        return;
    if (!Status_AccumulateChannelValue(status, hidden_value))
        return;
    StatusChannelResetOrReplace(status, 0xCu, 0);
}
__attribute__((noinline)) int Status_ResetSharedEligibilityCounters_005CACD4(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    const uint32_t threshold = 0x3b808081u;
    uint32_t active;
    if ((*(uint32_t *)bytes & 0x4000u) == 0)
        return 0;
    active = *(uint32_t *)(bytes + 0x30u) & 1u;
    if ((!active || *(int32_t *)(bytes + 0x34u) <= (int32_t)threshold) &&
        *(int32_t *)(bytes + 0x2b0u) <= (int32_t)threshold)
        return 1;
    return 0;
}
__attribute__((noinline)) int Status_ResetSharedEligibility(void *registry)
{
    uint8_t *state = *(uint8_t **)((uint8_t *)registry + 0x140u);
    if (state == 0 || *(uint8_t *)(state + 0x31c4u) != 0)
        return 0;
    return Status_ResetSharedEligibilityCounters_005CACD4(state + 0xb64u);
}
__attribute__((noinline)) int DamageTargetPassesSpecialResourceFilter(void *target)
{
    uint8_t *resource = *(uint8_t **)((uint8_t *)target + 0x168u);
    uint32_t identity = *(uint32_t *)(resource + 8u);
    if (identity != *(const uint32_t *)(uintptr_t)0x005c0910u &&
        identity != *(const uint32_t *)(uintptr_t)0x005c0914u)
        return 0;
    return StatusComponentHasBit00800000(target);
}
__attribute__((noinline)) uint32_t OwnerHandle_BuildVariant6(void *tree, uint32_t key)
{
    uint8_t *bytes = (uint8_t *)tree;
    uint8_t *sentinel = bytes + 4u;
    uint8_t *candidate = sentinel;
    uint8_t *node = *(uint8_t **)(bytes + 8u);
    while (node != 0 && *(uint8_t *)(node + 0x10u) != 0) {
        if (*(uint32_t *)(node + 0x14u) < key) {
            node = *(uint8_t **)(node + 0x0cu);
            candidate = node;
        } else {
            node = *(uint8_t **)(node + 8u);
        }
    }
    if (candidate == sentinel || key < *(uint32_t *)(candidate + 0x14u))
        candidate = sentinel;
    {
        uint32_t selected = *(uint32_t *)candidate;
        uint32_t sentinel_value = *(uint32_t *)sentinel;
        if (selected == sentinel_value)
            return 0xfffffe00u;
        return *(uint32_t *)((uint8_t *)(uintptr_t)selected + 0x20u);
    }
}
static void *DamageResourceSentinelA(void)
{
    uint32_t *shared_guard = (uint32_t *)(uintptr_t)0x00d627c4u;
    uint32_t *shared_value = (uint32_t *)(uintptr_t)0x00d627c8u;
    uint32_t *list_guard = (uint32_t *)(uintptr_t)0x00d619c8u;
    uint32_t *list_value = (uint32_t *)(uintptr_t)0x00d619ccu;
    uint32_t *gate_guard = (uint32_t *)(uintptr_t)0x00d63b98u;
    uint32_t *sentinel_slot = (uint32_t *)(uintptr_t)0x00d63b9cu;
    (void)EngineOnceGuard(gate_guard);
    if (EngineOnceGuard(shared_guard)) {
        if (EngineOnceGuard(list_guard))
            *list_value = 0;
        *shared_guard = (uint32_t)(uintptr_t)list_value;
        *sentinel_slot = (uint32_t)(uintptr_t)shared_value;
    }
    return (void *)(uintptr_t)*sentinel_slot;
}
static void *DamageResourceSentinelB(void)
{
    uint32_t *shared_guard = (uint32_t *)(uintptr_t)0x00d627c4u;
    uint32_t *shared_value = (uint32_t *)(uintptr_t)0x00d627c8u;
    uint32_t *list_guard = (uint32_t *)(uintptr_t)0x00d619c8u;
    uint32_t *list_value = (uint32_t *)(uintptr_t)0x00d619ccu;
    uint32_t *gate_guard = (uint32_t *)(uintptr_t)0x00d63bb0u;
    uint32_t *sentinel_value = (uint32_t *)(uintptr_t)0x00d612e4u;
    uint32_t *sentinel_slot = (uint32_t *)(uintptr_t)0x00d612e8u;
    uint32_t *outer_value = (uint32_t *)(uintptr_t)0x00d63bb4u;
    (void)EngineOnceGuard(gate_guard);
    if (EngineOnceGuard(sentinel_value)) {
        if (EngineOnceGuard(shared_guard)) {
            if (EngineOnceGuard(list_guard))
                *list_value = 0;
            *shared_guard = (uint32_t)(uintptr_t)list_value;
        }
        *sentinel_slot = (uint32_t)(uintptr_t)shared_value;
        *outer_value = (uint32_t)(uintptr_t)sentinel_slot;
    }
    return (void *)(uintptr_t)*outer_value;
}
static int DamageResourceThresholdPasses(void *resource, void *sentinel,
                                            unsigned channel, int type2)
{
    void *node = ((ResourceFirstEntry)(*(uintptr_t **)resource)[0])(resource);
    while (node != 0 && node != sentinel)
        node = *(void **)node;
    if (node != sentinel)
        return 0;
    if (type2 != 0) {
        if (*(uint8_t *)((uint8_t *)resource + 0x54u) != 2u)
            return 0;
        if (DamageChannelPolicy_B(channel & 0xffu) != 0 || channel == 4u)
            return *(float *)((uint8_t *)resource + 0x58u) > 0.0666666701f;
        return *(float *)((uint8_t *)resource + 0x58u) > 0.416666687f;
    }
    return (*(uint8_t *)((uint8_t *)resource + 0x54u) & 4u) != 0;
}
__attribute__((noinline)) int DamageTargetEvaluateResourceChannelGate(void *target, unsigned channel)
{
    uint8_t *resource = *(uint8_t **)((uint8_t *)target + 0x168u);
    uint32_t identity = *(uint32_t *)(resource + 8u);
    if (identity == 0x1eu || identity == 0x1fu)
        return 1;
    if (identity == 0x34u)
        return DamageResourceThresholdPasses(
            resource, DamageResourceSentinelA(), channel, 1);
    if (identity == 0x19u)
        return DamageResourceThresholdPasses(
            resource, DamageResourceSentinelB(), channel, 0);
    return 0;
}
__attribute__((noinline)) void CombatHit_ApplyPostDamageStatus(void *target,
                                       void *descriptor,
                                       struct DamageSourceObject *source,
                                       uint32_t mode,
                                       float hidden_value)
{
    struct ActorObjectView *target_object =
        (struct ActorObjectView *)target;
    struct StatusDescriptorView *resolved =
        (struct StatusDescriptorView *)ResolveStatusDescriptor(descriptor);
    struct StatusOwnerView *counter_base = 0;
    uint32_t previous_mask;
    uint32_t applied_mask;
    uint32_t limit = 0x3b9ac9ffu;
    unsigned channel;
    if (StatusDescriptorClassNibble(descriptor) == 1 && resolved != 0) {
        if ((resolved->tagged_handle >> 28) == 1u) {
            uint8_t owner_slot = resolved->owner_slot;
            counter_base = (struct StatusOwnerView *)StatusOwnerIndexAddress(
                (uint8_t *)target + 0xb3f8, (int8_t)owner_slot);
        }
        if ((counter_base->flags_ad8 & 0x10u) != 0)
            return;
    }
    struct HealthStatusComponent *component =
        (struct HealthStatusComponent *)ResolveRelatedComponent(descriptor);
    previous_mask = component->active_mask;
    applied_mask = HitDebuff_ResolveAndAccumulate(
        descriptor, source->source_data, source->effect_data, mode,
        source->effect_flags, source->effect_options, hidden_value);
    if (counter_base == 0)
        return;
    uint32_t selected = ResourceTableLookup(
        (uint32_t *)((uint8_t *)target_object + 0xb278));
    int selected_is_descriptor = (selected == (uint32_t)(uintptr_t)descriptor);
    for (channel = 0; channel < 16; ++channel) {
        uint32_t bit;
        if (applied_mask == 0)
            return;
        bit = 1u << channel;
        if ((applied_mask & bit) == 0)
            continue;
        applied_mask &= ~bit;
        if ((previous_mask & bit) != 0)
            continue;
        if ((source->effect_flags >> 28) == 1u)
            StatusHitIncrementOwnerChannel(counter_base, channel,
                (void *)(uintptr_t)source->effect_flags);
        if (selected_is_descriptor) {
            void **engine_slot = (void **)(uintptr_t)0x00d6365cu;
            void *engine = *engine_slot;
            if (engine == 0) {
                engine = GetEngineSingleton_003B6CF0();
                *engine_slot = engine;
            }
            if (engine == 0)
                continue;
            if (channel == 1) {
                uint32_t value = *(uint32_t *)((uint8_t *)engine + 0x1647c) + 1u;
                if (value == 0 || limit < value)
                    value = limit;
                *(uint32_t *)((uint8_t *)engine + 0x1647c) = value;
            } else if (channel == 2) {
                uint32_t value = *(uint32_t *)((uint8_t *)engine + 0x16478) + 1u;
                if (value == 0 || limit < value)
                    value = limit;
                *(uint32_t *)((uint8_t *)engine + 0x16478) = value;
            }
        }
    }
}
__attribute__((noinline)) int DamageTargetHasOwnerCapability(void *target)
{
    uint32_t descriptor = StatusDescriptorReadWord(target, 0x20u, 0);
    uint8_t *record;
    uint8_t *node;
    uint8_t *upper;
    uint8_t *selected;
    if ((descriptor >> 28) != 1u ||
        ((descriptor & 0x0fffffffu) >> 16) == 0)
        return 0;
    record = (uint8_t *)StatusRelatedRecordResolve(target, 0);
    if (record == 0)
        return 0;
    node = OrderedTreeLowerBoundByPointer(
        record + 0x1a4, GetStatusCapabilityKey());
    upper = *(uint8_t **)(record + 0x1a8);
    selected = node != 0 ? *(uint8_t **)node : 0;
    if (selected == upper)
        selected = 0;
    return selected != 0 && ((*(uint16_t *)(selected + 0x1e) & 0x10u) != 0);
}
__attribute__((noinline)) void *DamageTargetGetOwnerBacklink(void *target)
{
    uint32_t descriptor = StatusDescriptorReadWord(target, 0x20u, 0);
    uint8_t *record;
    uint8_t *node;
    uint8_t *upper;
    uint8_t *selected;
    if ((descriptor >> 28) != 1u ||
        ((descriptor & 0x0fffffffu) >> 16) == 0)
        return 0;
    record = (uint8_t *)StatusRelatedRecordResolve(target, 0);
    if (record == 0)
        return 0;
    node = OrderedTreeLowerBoundByPointer(
        record + 0x1a4, GetStatusBacklinkKey());
    upper = *(uint8_t **)(record + 0x1a8);
    selected = node != 0 ? *(uint8_t **)node : 0;
    if (selected == upper || selected == 0)
        return 0;
    return *(void **)(selected + 0x1c);
}
