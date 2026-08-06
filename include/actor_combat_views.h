#ifndef ACTOR_COMBAT_VIEWS_H
#define ACTOR_COMBAT_VIEWS_H
#include <stddef.h>
#include <stdint.h>
enum { STATUS_CHANNEL_COUNT = 12 };
union FloatBits {
    float value;
    uint32_t bits;
};
struct ActorObjectView {
    uint8_t opaque_000[0x168];
    void *active_state;               
    void *pending_state;              
    void *deferred_state;             
    uint32_t flags;                   
    union FloatBits current_hp;       
    union FloatBits maximum_hp;       
    uint8_t opaque_180[0x24];
    uint32_t component_tree_anchor;   
    void *component_tree_upper;       
    void *component_tree_root;        
    uint8_t opaque_1b0[0x34];
    void *cached_alternate_profile;   
    void *cached_profile_rate;        
    void *cached_status_descriptor;   
    void *cached_component_descriptor;  
    uint8_t opaque_1f4[0x14];
    void *cached_health_component;    
};
struct HealthStatusComponent {
    uint8_t opaque_000[0x30];
    void *target;                     
    void *actor_backref_034;          
    uint8_t opaque_038[0x20];
    union {
        struct {
            uint8_t event_state_058;       
            uint8_t opaque_059[3];
            uint32_t event_values_05c[4];  
            uint8_t opaque_06c[8];
            uint8_t event_flag_074;        
            uint8_t opaque_075[0x13];
            uint32_t threshold_flags_088;  
            uint8_t opaque_08c[0x90];
            uint32_t dispatch_param_11c;   
            uint8_t event_dispatch[0x50];  
            void *secondary;               
        };
        struct {
            uint8_t movement_state[0x20];             
            uint8_t auxiliary_state[0x20];            
            uint8_t primary_condition_state[0x38];    
            uint8_t secondary_condition_state[0x50];  
            uint8_t pose_state[0x44];                 
            uint32_t message_dispatcher;              
            void *active_state;                       
            void *pending_state;                      
            void *deferred_state;                     
        };
    };
    uint32_t flags;                   
    union FloatBits current_hp;       
    union FloatBits maximum_hp;       
    float parameter_scale;            
    float scaled_lanes_184[8];        
    float raw_lanes_1a4[8];           
    float weak_scale;                 
    float weak_rate;                  
    float status_timer;               
    float elapsed;                    
    uint8_t opaque_1d4[8];            
    uint32_t active_mask;             
    float buildup[STATUS_CHANNEL_COUNT];            
    float remaining_time[STATUS_CHANNEL_COUNT];     
    float secondary_buildup[STATUS_CHANNEL_COUNT];  
};
struct StatusOwnerView {
    uint32_t tagged_handle;
    uint8_t opaque_004[0x84];
    uint32_t flags_088;
    uint8_t opaque_08c[4];
    uint32_t value_090;
    uint8_t opaque_094[0x0a];
    uint16_t status_flags;
    uint8_t opaque_0a0[0x34];
    float parameter_d4[3];
    float parameter_e0[2];
    float parameter_e8;
    uint8_t opaque_0ec[0x2c];
    uint32_t counts[16][6];
    float indexed_values_298[6];
    uint8_t opaque_2b0[4];
    uint32_t pending_count;
    uint8_t opaque_2b8[0x14];
    uint32_t field_2cc;
    void *pending_state;
    float pending_value;
    uint8_t opaque_2d8[0x1a0];
    uint32_t flags_478;
    uint8_t opaque_47c[0x278];
    float scale_6f4;
    uint8_t opaque_6f8[8];
    float scale_700;
    int32_t counter_704;
    uint8_t opaque_708[0x1c];
    int8_t notification_gate_724;
    uint8_t opaque_725[0x3b3];
    uint32_t flags_ad8;
    uint8_t opaque_adc[8];
    uint8_t damage_profiles[4][0x1c];
    float field_b54;
    float field_b58;
    uint8_t opaque_b5c[0x0c];
    uint8_t dispatch_active;
    uint8_t opaque_b69[3];
    float dispatch_timer;
    uint8_t opaque_b70[0x28];
};
struct HealthStatusRecordView {
    uint8_t opaque_000[0x64];
    uint32_t payload_064[7];        
    uint8_t opaque_080[0x124];      
    uint8_t ordered_tree_1a4[8];    
};
typedef char kiu_sa_actor_combat_views_1[(offsetof(struct ActorObjectView, active_state) == 0x168) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_2[(offsetof(struct ActorObjectView, current_hp) == 0x178) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_3[(offsetof(struct ActorObjectView, component_tree_anchor) == 0x1a4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_4[(offsetof(struct ActorObjectView, cached_alternate_profile) == 0x1e4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_5[(offsetof(struct ActorObjectView, cached_status_descriptor) == 0x1ec) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_6[(offsetof(struct ActorObjectView, cached_health_component) == 0x208) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_7[(offsetof(struct HealthStatusComponent, target) == 0x30) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_8[(offsetof(struct HealthStatusComponent, actor_backref_034) == 0x34) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_9[(offsetof(struct HealthStatusComponent, event_state_058) == 0x58) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_10[(offsetof(struct HealthStatusComponent, movement_state) == 0x58) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_11[(offsetof(struct HealthStatusComponent, event_values_05c) == 0x5c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_12[(offsetof(struct HealthStatusComponent, event_flag_074) == 0x74) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_13[(offsetof(struct HealthStatusComponent, threshold_flags_088) == 0x88) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_14[(offsetof(struct HealthStatusComponent, dispatch_param_11c) == 0x11c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_15[(offsetof(struct HealthStatusComponent, event_dispatch) == 0x120) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_16[(offsetof(struct HealthStatusComponent, pose_state) == 0x120) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_17[(offsetof(struct HealthStatusComponent, active_state) == 0x168) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_18[(offsetof(struct HealthStatusComponent, secondary) == 0x170) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_19[(offsetof(struct HealthStatusComponent, current_hp) == 0x178) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_20[(offsetof(struct HealthStatusComponent, scaled_lanes_184) == 0x184) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_21[(offsetof(struct HealthStatusComponent, raw_lanes_1a4) == 0x1a4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_22[(offsetof(struct HealthStatusComponent, weak_scale) == 0x1c4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_23[(offsetof(struct HealthStatusComponent, status_timer) == 0x1cc) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_24[(offsetof(struct HealthStatusComponent, elapsed) == 0x1d0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_25[(offsetof(struct HealthStatusComponent, active_mask) == 0x1dc) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_26[(offsetof(struct HealthStatusComponent, buildup) == 0x1e0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_27[(offsetof(struct HealthStatusComponent, remaining_time) == 0x210) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_28[(offsetof(struct HealthStatusComponent, secondary_buildup) == 0x240) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_29[(sizeof(struct HealthStatusComponent) == 0x270) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_30[(offsetof(struct StatusOwnerView, status_flags) == 0x9e) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_31[(offsetof(struct StatusOwnerView, counts) == 0x118) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_32[(offsetof(struct StatusOwnerView, pending_state) == 0x2d0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_33[(offsetof(struct StatusOwnerView, flags_478) == 0x478) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_34[(offsetof(struct StatusOwnerView, flags_ad8) == 0xad8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_35[(offsetof(struct StatusOwnerView, dispatch_active) == 0xb68) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_36[(sizeof(struct StatusOwnerView) == 0xb98) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_37[(offsetof(struct HealthStatusRecordView, payload_064) == 0x64) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_38[(offsetof(struct HealthStatusRecordView, ordered_tree_1a4) == 0x1a4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_39[(sizeof(struct HealthStatusRecordView) == 0x1ac) ? 1 : -1] __attribute__((unused));
enum Debuff {
    HIT_DEATH = 0,
    HIT_TEMPURA,
    HIT_EGGPLANT,
    HIT_FREEZE,
    HIT_PETRIFY,
    HIT_TURN,
    HIT_BURN,
    HIT_POISON,
    HIT_CONFUSE,
    HIT_PARALYZE,
    HIT_SHAKE,
    HIT_WEAK,
    HIT_CATCH,
    HIT_STEAL,
    HIT_MIRACLE,
    HIT_DROPOUT,      
    HIT_DEBUFF_NONE,  
    HIT_RANDOM        
};
enum StatusSelectorOffset {
    STATUS_SELECTOR_A = 0x123c,
    STATUS_SELECTOR_B = 0x123d
};
enum StatusComponentLayout {
    STATUS_ACTIVE_MASK_OFFSET = 0x1dc,
    STATUS_BUILDUP_OFFSET = 0x1e0,
    STATUS_REMAINING_TIME_OFFSET = 0x210
};
enum HealthSecondaryFlag {
    HEALTH_SECONDARY_ACTIVE = 0x2000,
    HEALTH_SECONDARY_PHASE_ONE = 0x4000
};
struct StatusDescriptorView {
    uint8_t opaque_00[0x1c];
    void *owner;
    uint32_t tagged_handle;
    void *resource;
    void *effect;
    uint8_t owner_slot;
    uint8_t opaque_2d[0x67];
    uint32_t flags;
};
struct HealthParameterOwnerView {
    uint8_t opaque_000[0x1a4];
    void *parameter_tree_anchor;
    void *parameter_tree_upper;
    uint8_t opaque_1ac[0x38];
    void *cached_parameter_record;
};
struct StatusParameterDescriptorOptionsView {
    uint8_t opaque_000[0x18];
    int8_t event_byte_018;
    uint8_t scale_gate_019;
    uint8_t flag_01a;
    uint8_t flag_01b;
    uint8_t flag_01c;
    uint8_t flag_01d;
    uint8_t flag_01e;
    uint8_t flag_01f;
    uint8_t component_flag_020;
    uint8_t opaque_021[3];
    union FloatBits value_024;
    float value_028;
    int32_t resource_key_02c;
    uint8_t mode_030;
};
struct StatusParameterRuntimeFieldsView {
    uint8_t opaque_000[0xf0];
    float value_0f0;
    float value_0f4;
    uint8_t opaque_0f8[4];
    uint8_t mode_0fc;
    uint8_t opaque_0fd[3];
    int32_t sentinel_100;
    uint8_t opaque_104[0x26];
    uint8_t mode_12a;
};
struct StatusParameterSelectionRecordView {
    uint8_t opaque_000[0x1e];
    uint16_t flags_01e;
    uint8_t opaque_020[0x18];
    float scale_038;
};
struct CombatStatusEventRecord {
    uint32_t event_id;
    uint32_t payload[12];
    uint8_t opaque_34[0x0c];
    uint32_t state_40;
    uint8_t state_44;
    uint8_t opaque_45[7];
    uint32_t descriptor_value;
    uint8_t mode;
    uint8_t opaque_51[3];
    union FloatBits value;
};
struct HealthSecondaryStateView {
    uint8_t state;
    uint8_t opaque_01[3];
    float accumulator;
    float boundary;
    float phase_two_remaining;
    float phase_one_remaining;
    float rate;
    float overflow;
    uint8_t current_step;
    uint8_t step_limit;
    uint8_t opaque_1e[2];
};
struct TimedEffectRecord {
    uint8_t active;
    uint8_t opaque_01[3];
    float first_value;
    float second_value;
    uint32_t flags;
    float duration;
};
struct EffectQueueVariant {
    struct TimedEffectRecord records[12];
    uint32_t count;
    uint32_t auxiliary_count;
};
struct EffectQueueView {
    uint8_t opaque_00[0x78];
    struct EffectQueueVariant variants[];
};
struct UnitScaleRecordView {
    uint8_t opaque_000[0x0c];
    float scale_00c;
};
struct StatusRandomizedEffectParams {
    float chance;
    float scale;
};
typedef enum Debuff StatusChannel;
typedef char kiu_sa_actor_combat_views_40[(offsetof(struct StatusParameterDescriptorOptionsView, flag_01a) == 0x1a) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_41[(offsetof(struct StatusParameterDescriptorOptionsView, component_flag_020) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_42[(offsetof(struct StatusParameterDescriptorOptionsView, value_024) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_43[(offsetof(struct StatusParameterSelectionRecordView, flags_01e) == 0x1e) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_44[(offsetof(struct StatusParameterSelectionRecordView, scale_038) == 0x38) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_45[(offsetof(struct StatusParameterRuntimeFieldsView, mode_12a) == 0x12a) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_46[(offsetof(struct StatusDescriptorView, owner_slot) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_47[(offsetof(struct StatusDescriptorView, flags) == 0x94) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_48[(offsetof(struct HealthParameterOwnerView, parameter_tree_anchor) == 0x1a4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_49[(offsetof(struct HealthParameterOwnerView, parameter_tree_upper) == 0x1a8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_50[(offsetof(struct HealthParameterOwnerView, cached_parameter_record) == 0x1e4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_51[(offsetof(struct CombatStatusEventRecord, descriptor_value) == 0x4c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_52[(offsetof(struct CombatStatusEventRecord, mode) == 0x50) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_53[(offsetof(struct CombatStatusEventRecord, value) == 0x54) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_54[(sizeof(struct CombatStatusEventRecord) == 0x58) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_55[(offsetof(struct HealthSecondaryStateView, overflow) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_56[(offsetof(struct HealthSecondaryStateView, current_step) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_57[(sizeof(struct HealthSecondaryStateView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_58[(offsetof(struct UnitScaleRecordView, scale_00c) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_59[(sizeof(struct TimedEffectRecord) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_60[(offsetof(struct EffectQueueVariant, count) == 0xf0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_61[(sizeof(struct EffectQueueVariant) == 0xf8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_combat_views_62[(offsetof(struct EffectQueueView, variants) == 0x78) ? 1 : -1] __attribute__((unused));
#endif  
