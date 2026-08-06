#ifndef ENGINE_COMMON_VIEWS_H
#define ENGINE_COMMON_VIEWS_H
#include <stddef.h>
#include <stdint.h>
struct PslNameSpan {
    const char *data;
    int32_t length;  
};
struct PslMutableSpan {
    char *data;
    int32_t capacity;
};
struct PslStringSpan {
    char *data;
    int32_t length;
};
struct EngineResourceHandleEntryView {
    void *object;
    uint32_t generation;
};
struct EngineOpaqueSpanView {
    void *owner;
    void *begin;
    void *end;
    uint32_t capacity_flags;
};
struct EngineResourceObjectView {
    uint32_t implementation;
    void *allocator;
    const void *context;
    struct EngineOpaqueSpanView descriptor_span_00c;
    void *animation_record;
    struct EngineOpaqueSpanView opaque_span_020;
    struct EngineOpaqueSpanView opaque_span_030;
    struct EngineOpaqueSpanView opaque_span_040;
    struct EngineOpaqueSpanView opaque_span_050;
    uint32_t opaque_060;
    uint8_t opaque_064;
    uint8_t opaque_065[3];
};
struct EngineRelativeResourceSourceView {
    uint32_t flags_000;
    uint8_t opaque_004[0x28];
    int32_t relative_intermediate_02c;
};
struct EngineRelativeResourceIntermediateView {
    uint8_t opaque_000[0x28];
    int32_t relative_context_028;
};
struct EngineRelativeResourceContextView {
    uint8_t opaque_000[0x10];
    int32_t entry_count_010;
    int32_t relative_entry_table_014;
    int32_t descriptor_count_018;
    int32_t relative_descriptor_indices_01c;
};
struct EngineRelativeResourceEntryLinkView {
    int32_t relative_entry;
    uint8_t opaque_004[0x0c];
};
struct EngineRelativeResourceEntryTableView {
    uint8_t opaque_000[0x28];
    struct EngineRelativeResourceEntryLinkView entries_028[1];
};
struct EngineRelativeResourceEntryView {
    uint8_t opaque_000[0x08];
    uint32_t byte_offset_008;
    uint8_t opaque_00c[0x04];
    uint32_t kind_010;
    uint32_t field_014;
};
struct EngineOwnedOpaqueSpanView {
    void *object_owner;
    void *range_owner;
    void *begin;
    void *end;
    uint32_t capacity_flags;
};
struct EngineEmbeddedRecordView {
    uint32_t field_000;
    uint32_t field_004;
    uint8_t opaque_008[0x38];
    void *field_040;
    uint8_t opaque_044[4];
    uint32_t field_048;
    uint32_t field_04c;
    void *field_050;
    uint32_t field_054;
    uint32_t field_058;
    void *field_05c;
    void *field_060;
    void *field_064;
    void *field_068;
    uint8_t field_06c;
    uint8_t opaque_06d[3];
    void *field_070;
    void *field_074;
    void *field_078;
    void *field_07c;
    uint8_t field_080;
    uint8_t opaque_081[3];
    uint32_t field_084;
};
struct EngineRecordOwnerDescriptorView {
    uint8_t opaque_000[4];
    uint32_t field_004;
    uint8_t opaque_008[0x40];
    uint32_t field_048;
    uint32_t field_04c;
};
struct EngineRecordOwnerView {
    uint8_t opaque_000[0x88];
    uint8_t field_088[0x108];
    struct EngineRecordOwnerDescriptorView *descriptor_190;
};
struct ParameterRegistryNodeView {
    uint32_t tag_000;
    void *tree_payload_004;
    void *tree_parent_008;
    void *tree_left_00c;
    void *tree_right_010;
    uint8_t tree_active_014;
    uint8_t opaque_015[3];
    uint32_t name_hash_018;
    const char *name_01c;
};
struct ParameterRegistryRecordView {
    struct ParameterRegistryNodeView node;
    uint8_t opaque_020;
    uint8_t registration_state_021;
    uint8_t opaque_022[2];
    void *initializer_or_class_name_024;
    uint32_t record_size_028;
};
struct EngineGlobalStateRecordView {
    union {
        void *object_000;
        uint32_t word_000;
        uint8_t bytes_000[4];
    } first_word;
    uint8_t byte_004;
    uint8_t byte_005;
    uint8_t byte_006;
    uint8_t byte_007;
    uint8_t byte_008;
    uint8_t byte_009;
    uint8_t byte_00a;
    uint8_t byte_00b;
    uint8_t byte_00c;
    int8_t signed_byte_00d;
    uint8_t opaque_00e[2];
    uint32_t field_010;
    uint32_t field_014;
    uint32_t mode_flags_018;
};
struct EngineGlobalRecordD4D4C8View {
    uint8_t byte_000;
    uint8_t opaque_001[0x13];
    uint32_t field_014;
    uint8_t opaque_018[8];
    uint32_t field_020;
    uint32_t field_024;
    uint8_t opaque_028[4];
    uint32_t field_02c;
    uint8_t opaque_030[0x10];
    void *callback_040;
    void *callback_044;
    uint8_t opaque_048[0x0c];
    uint32_t field_054;
    uint8_t opaque_058[8];
    uint32_t field_060;
    uint8_t opaque_064[8];
    uint32_t field_06c;
    uint8_t opaque_070[0x10];
    uint32_t callback_argument_080;
    uint32_t callback_argument_084;
};
struct StateResourceGlobalSlotView {
    void *manager_000;
    uint32_t request_mode_004;
};
struct CflResourceGlobalStateView {
    uint8_t loaded_000;
    uint8_t opaque_001[3];
    uint32_t field_004;
    void *resource_008;
    uint32_t field_00c;
    uint32_t field_010;
};
struct D4D0F8GlobalPrefixView {
    int8_t signed_byte_000;
    uint8_t opaque_001[3];
    void *pointer_004;
};
struct TaggedBlockConstructorGlobalsView {
    uint8_t type_tag_000;
    uint8_t opaque_001[3];
    uint32_t marker_004;
    uint32_t *serial_value_008;
    uint32_t *once_guard_00c;
    uint32_t *serial_counter_010;
    void **stride_registry_014;
    uint32_t *auxiliary_value_018;
    uint32_t final_marker_01c;
    uint32_t post_marker_020;
    uint32_t *tail_pair_024;
};
struct TaggedBlockCloneGlobalsView {
    uint32_t *once_guard_000;
    void **list_sentinel_004;
    uint8_t type_tag_008;
    uint8_t opaque_009[3];
    uint32_t initial_marker_00c;
    uint32_t final_marker_010;
};
struct EngineOnceGuardValuePairView {
    uint32_t once_guard_000;
    void *value_004;
};
struct EngineTimestampPairView {
    uint32_t timestamp_000;
    uint32_t value_004;
};
struct EngineHashCachePairView {
    uint32_t once_guard;
    uint32_t hash;
};
struct BulletTypeModelHashCacheStateView {
    uint8_t opaque_000[0x68];
    struct EngineHashCachePairView bullet_type_pairs[53];
    uint8_t opaque_210[0x0c];
    struct EngineHashCachePairView bullet_model_pairs[26];
};
struct DemoIdHashCacheRegionView {
    uint8_t opaque_000[0xdc];
    struct EngineHashCachePairView demo_pairs[144];
};
struct DmtTypeHashCacheRegionView {
    uint8_t opaque_000[0x3a0];
    struct EngineHashCachePairView dmt_pairs[4];
};
struct AiStateHashCacheRegionView {
    uint8_t opaque_000[0x7c];
    struct EngineHashCachePairView pairs[80];
    uint8_t opaque_2fc[4];
};
struct CmQuakeHashCacheRegionView {
    uint8_t opaque_000[0x264];
    struct EngineHashCachePairView pairs[8];
};
struct IkPartHashCacheRegionView {
    uint8_t opaque_000[0x38c];
    struct EngineHashCachePairView pairs[4];
};
struct MrclTypeHashCacheRegionView {
    uint8_t opaque_000[0x258];
    struct EngineHashCachePairView pairs[53];
};
struct CharacterAnimationHashCacheRegionView {
    struct EngineHashCachePairView pairs[128];
    uint8_t opaque_400[0x3c0];
};
struct SpBoostStatusHashCacheRegionView {
    struct EngineHashCachePairView pairs_000[10];
    uint8_t opaque_050[0x1e4];
    struct EngineHashCachePairView pairs_234[29];
    uint8_t opaque_31c[4];
    struct EngineHashCachePairView pairs_320[4];
};
struct ConditionStateHashCacheRegionView {
    uint8_t opaque_000[0x300];
    struct EngineHashCachePairView pair_300;
    uint8_t opaque_308[4];
    struct EngineHashCachePairView pairs_30c[9];
    uint8_t opaque_354[4];
    struct EngineHashCachePairView pairs_358[19];
};
struct EnumLookupHashCacheRegionView {
    uint8_t opaque_000[0x8c];
    struct EngineHashCachePairView pairs_08c[3];
    uint8_t opaque_0a4[0x80];
    struct EngineHashCachePairView pairs_124[4];
    uint8_t opaque_144[0x38];
    struct EngineHashCachePairView pairs_17c[3];
    uint8_t opaque_194[4];
    struct EngineHashCachePairView pairs_198[9];
    uint8_t opaque_1e0[0x16c];
    struct EngineHashCachePairView pairs_34c[32];
};
struct HealMrclActionHashCacheRegionView {
    uint8_t opaque_000[0x50];
    struct EngineHashCachePairView pairs_050[6];
    uint8_t opaque_080[0x28];
    struct EngineHashCachePairView pairs_0a8[4];
    uint8_t opaque_0c8[4];
    struct EngineHashCachePairView pairs_0cc[4];
    uint8_t opaque_0ec[0x1a0];
    struct EngineHashCachePairView pairs_28c[3];
    uint8_t opaque_2a4[0x28];
    struct EngineHashCachePairView pairs_2cc[3];
    uint8_t opaque_2e4[0x3c];
    struct EngineHashCachePairView pairs_320[12];
    uint8_t opaque_380[4];
    struct EngineHashCachePairView pairs_384[7];
};
struct HitAttributeDebuffCacheView {
    uint8_t opaque_000[0x30];
    struct EngineHashCachePairView attribute_pairs[10];
    uint8_t opaque_080[0x94];
    const char *name_pointers[18];
    uint8_t opaque_15c[0x1c0];
    uint32_t mode_words[3];
};
struct EffectModeHashCacheRegionView {
    uint8_t opaque_000[0x0c];
    struct EngineHashCachePairView pairs[6];
};
struct MenuResourceHashCacheRecordView {
    uint8_t marker_000;
    uint8_t opaque_001[3];
    struct EngineHashCachePairView pairs[4];
};
struct EngineOnceGuardValuePairTable2View {
    struct EngineOnceGuardValuePairView entries[2];
};
struct EngineOnceGuardValuePairTable3View {
    struct EngineOnceGuardValuePairView entries[3];
};
struct EngineOnceGuardValuePairTable4View {
    struct EngineOnceGuardValuePairView entries[4];
};
struct ParameterMetadataRecordView {
    uint32_t zero_000;
    void *implementation_004;
    uint32_t zero_008;
    uint32_t zero_00c;
};
struct ParameterMetadataRecordTableView {
    struct ParameterMetadataRecordView entries[7];
};
struct ParameterMetadataRecordPairView {
    struct ParameterMetadataRecordView entries[2];
};
struct StateFactoryRecordView {
    const void *factory_vtable_00;
    uint8_t opaque_004[0x14];
    uint32_t identifier_018;
    const char *name_01c;
    uint32_t opaque_020;
    const char *name_024;
    uint32_t state_size_028;
};
struct LifecycleTypeRecordView {
    uint8_t opaque_000[0x10];
    void *lifecycle_callback_010;
    uint8_t opaque_014[0x14];
};
struct StateLifecycleMetadataRecordView {
    uint8_t opaque_000[0x08];
    uint32_t zero_008;
    uint8_t opaque_00c[0x0c];
    uint32_t zero_018;
    uint8_t opaque_01c[0x04];
};
struct StateLifecycleCallbackRecordView {
    uint8_t opaque_000[0x08];
    uint32_t zero_008;
    uint8_t opaque_00c[0x04];
    void *lifecycle_callback_010;
    uint8_t opaque_014[0x04];
    uint32_t zero_018;
    uint8_t opaque_01c[0x04];
};
struct CommandClassCallbackRecordView {
    uint32_t null_000;
    void *pointer_004;
    void *pointer_008;
    void *pointer_00c;
    uint8_t opaque_010[0x0c];
    void *pointer_01c;
};
struct TypeIdentityRecordVariantView {
    uint8_t opaque_000[0x20];
};
struct CommandClassDataVariantView {
    void *pointer_000;
    void *pointer_004;
    uint32_t zero_008;
    void *pointer_00c;
    void *pointer_010;
    void *pointer_014;
    uint32_t zero_018;
    uint32_t zero_01c;
};
struct CommandClassDataVariantSpecialView {
    void *pointer_000;
    void *pointer_004;
    uint32_t zero_008;
    void *pointer_00c;
    void *pointer_010;
    void *pointer_014;
    uint32_t zero_018;
    int32_t field_01c;
};
struct CommandClassDataShortVariantView {
    void *pointer_000;
    void *pointer_004;
    void *pointer_008;
    uint8_t opaque_00c[0x14];
};
struct ResourceDescriptorDefaultsView {
    uint8_t opaque_000[0x08];
    void *pointer_008;
    void *pointer_00c;
};
struct AllocatorDispatchRecordView {
    uint8_t opaque_000[0x08];
    void *callback_008;
    void *context_00c;
};
struct SingletonStateOnceGuardView {
    uint32_t opaque_000;
    uint32_t once_guard_004;
};
struct OnceGuardHalfwordSlotView {
    uint32_t once_guard_000;
    uint8_t opaque_004[2];
    uint16_t value_006;
};
struct CounterHighWaterPairView {
    uint32_t high_water_000;
    uint32_t incremented_count_004;
};
struct OpaqueTwoWordPairView {
    uint32_t word_000;
    uint32_t word_004;
};
struct ResourceFactoryGuardPoolView {
    uint8_t opaque_000[0x20];
    uint32_t guard_020;
    uint32_t guard_024;
    uint32_t guard_028;
    uint32_t guard_02c;
    uint32_t guard_030;
    uint32_t guard_034;
};
struct MenuParameterFactoryGuardSpanView {
    uint8_t opaque_000[0x04];
    uint32_t guard_004;
    uint32_t guard_008;
    uint8_t opaque_00c[0x18];
};
struct MenuFactoryGuardSpanView {
    uint8_t opaque_000[0x08];
    uint32_t guard_008;
    uint8_t opaque_00c[0x20];
    uint32_t guard_02c;
};
struct StageFactoryReadinessRecordView {
    uint8_t opaque_000[0x08];
    uint32_t ready_008;
    uint32_t ready_00c;
    uint8_t opaque_010[0x08];
    uint32_t ready_018;
    uint8_t opaque_01c[0x04];
    uint32_t ready_020;
};
struct TaggedBlockTypeMarkerView {
    uint8_t type_tag_000;
    uint8_t opaque_001[3];
    uint32_t marker_004;
};
struct RunnerCollisionProfileView {
    uint8_t opaque_000[0x5c];
    uint32_t field_05c;
    uint16_t field_060;
    uint16_t field_062;
    uint32_t fields_064[11];
};
struct FringRunnerParamView {
    struct RunnerCollisionProfileView collision_profile;
    uint8_t opaque_090[0x108];
    uint32_t field_198;
    uint32_t field_19c;
    uint8_t opaque_1a0[0x3c];
};
struct BeetleRunnerParamView {
    struct RunnerCollisionProfileView collision_profile;
    uint8_t opaque_090[0x208];
    uint32_t field_298;
    uint32_t field_29c;
    uint32_t field_2a0;
    uint32_t field_2a4;
    uint32_t field_2a8;
    uint8_t opaque_2ac[0x20];
};
#if defined(__cplusplus)
typedef char kiu_sa_engine_common_views_1[(sizeof(PslNameSpan) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_2[(sizeof(PslMutableSpan) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_71[(sizeof(PslStringSpan) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_3[(offsetof(EngineResourceHandleEntryView, generation) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_4[(sizeof(EngineResourceHandleEntryView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_5[(offsetof(EngineOpaqueSpanView, capacity_flags) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_6[(sizeof(EngineOpaqueSpanView) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_7[(offsetof(EngineResourceObjectView, descriptor_span_00c) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_8[(offsetof(EngineResourceObjectView, animation_record) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_9[(offsetof(EngineResourceObjectView, opaque_span_020) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_10[(offsetof(EngineResourceObjectView, opaque_span_050) == 0x50) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_11[(offsetof(EngineResourceObjectView, opaque_064) == 0x64) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_12[(sizeof(EngineResourceObjectView) == 0x68) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_13[(offsetof(EngineRelativeResourceSourceView, relative_intermediate_02c) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_14[(offsetof(EngineRelativeResourceIntermediateView, relative_context_028) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_15[(offsetof(EngineRelativeResourceContextView, entry_count_010) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_16[(offsetof(EngineRelativeResourceContextView, relative_descriptor_indices_01c) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_17[(sizeof(EngineRelativeResourceEntryLinkView) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_18[(offsetof(EngineRelativeResourceEntryTableView, entries_028) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_19[(offsetof(EngineRelativeResourceEntryView, kind_010) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_20[(offsetof(EngineOwnedOpaqueSpanView, range_owner) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_21[(offsetof(EngineOwnedOpaqueSpanView, capacity_flags) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_22[(sizeof(EngineOwnedOpaqueSpanView) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_23[(offsetof(EngineEmbeddedRecordView, field_040) == 0x40) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_24[(offsetof(EngineEmbeddedRecordView, field_048) == 0x48) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_25[(offsetof(EngineEmbeddedRecordView, field_050) == 0x50) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_26[(offsetof(EngineEmbeddedRecordView, field_05c) == 0x5c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_27[(offsetof(EngineEmbeddedRecordView, field_068) == 0x68) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_28[(offsetof(EngineEmbeddedRecordView, field_06c) == 0x6c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_29[(offsetof(EngineEmbeddedRecordView, field_070) == 0x70) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_30[(offsetof(EngineEmbeddedRecordView, field_080) == 0x80) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_31[(sizeof(EngineEmbeddedRecordView) == 0x88) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_32[(offsetof(EngineRecordOwnerDescriptorView, field_048) == 0x48) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_33[(sizeof(EngineRecordOwnerDescriptorView) == 0x50) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_34[(offsetof(EngineRecordOwnerView, field_088) == 0x88) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_35[(offsetof(EngineRecordOwnerView, descriptor_190) == 0x190) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_1[(offsetof(ParameterRegistryNodeView, tree_payload_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_2[(offsetof(ParameterRegistryNodeView, tree_active_014) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_3[(offsetof(ParameterRegistryNodeView, name_hash_018) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_4[(sizeof(ParameterRegistryNodeView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_9[(offsetof(ParameterRegistryRecordView, registration_state_021) == 0x21) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_10[(offsetof(ParameterRegistryRecordView, initializer_or_class_name_024) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_11[(sizeof(ParameterRegistryRecordView) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_state_1[(offsetof(EngineGlobalStateRecordView, field_010) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_state_2[(offsetof(EngineGlobalStateRecordView, mode_flags_018) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_state_3[(sizeof(EngineGlobalStateRecordView) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_record_1[(offsetof(EngineGlobalRecordD4D4C8View, field_014) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_record_2[(offsetof(EngineGlobalRecordD4D4C8View, callback_040) == 0x40) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_record_3[(offsetof(EngineGlobalRecordD4D4C8View, callback_argument_080) == 0x80) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_record_4[(sizeof(EngineGlobalRecordD4D4C8View) == 0x88) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_state_resource_slot_1[(offsetof(StateResourceGlobalSlotView, request_mode_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_state_resource_slot_2[(sizeof(StateResourceGlobalSlotView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_cfl_1[(offsetof(CflResourceGlobalStateView, field_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_cfl_2[(offsetof(CflResourceGlobalStateView, resource_008) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_cfl_3[(offsetof(CflResourceGlobalStateView, field_010) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_cfl_4[(sizeof(CflResourceGlobalStateView) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_d4d0f8_1[(offsetof(D4D0F8GlobalPrefixView, pointer_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_d4d0f8_2[(sizeof(D4D0F8GlobalPrefixView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_tagged_globals_1[(offsetof(TaggedBlockConstructorGlobalsView, marker_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_tagged_globals_2[(offsetof(TaggedBlockConstructorGlobalsView, stride_registry_014) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_tagged_globals_3[(sizeof(TaggedBlockConstructorGlobalsView) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_clone_globals_1[(offsetof(TaggedBlockCloneGlobalsView, type_tag_008) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_clone_globals_2[(sizeof(TaggedBlockCloneGlobalsView) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_guard_value_pair_1[(sizeof(EngineOnceGuardValuePairView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_guard_value_pair_table2[(sizeof(EngineOnceGuardValuePairTable2View) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_guard_value_pair_table3[(sizeof(EngineOnceGuardValuePairTable3View) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_guard_value_pair_table4[(sizeof(EngineOnceGuardValuePairTable4View) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_type_marker_1[(offsetof(TaggedBlockTypeMarkerView, marker_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_type_marker_2[(sizeof(TaggedBlockTypeMarkerView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_command_class_record_1[(offsetof(struct CommandClassCallbackRecordView, pointer_01c) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_command_class_record_2[(sizeof(struct CommandClassCallbackRecordView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_type_identity_variant[(sizeof(struct TypeIdentityRecordVariantView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_command_class_variant[(sizeof(struct CommandClassDataVariantView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_command_class_variant_special[(sizeof(struct CommandClassDataVariantSpecialView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_command_class_variant_short[(sizeof(struct CommandClassDataShortVariantView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_resource_descriptor_defaults[(sizeof(struct ResourceDescriptorDefaultsView) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_allocator_dispatch_record[(sizeof(struct AllocatorDispatchRecordView) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_singleton_state_once_guard[(sizeof(struct SingletonStateOnceGuardView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_once_guard_halfword_slot[(sizeof(struct OnceGuardHalfwordSlotView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_counter_high_water_pair[(sizeof(struct CounterHighWaterPairView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_opaque_two_word_pair[(sizeof(struct OpaqueTwoWordPairView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_resource_factory_guard_pool[(sizeof(struct ResourceFactoryGuardPoolView) == 0x38) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_menu_parameter_factory_guard_span[(sizeof(struct MenuParameterFactoryGuardSpanView) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_menu_factory_guard_span[(sizeof(struct MenuFactoryGuardSpanView) == 0x30) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_stage_factory_readiness[(sizeof(struct StageFactoryReadinessRecordView) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_timestamp_pair[(sizeof(struct EngineTimestampPairView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_hash_cache_pair[(sizeof(struct EngineHashCachePairView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_bullet_type_model_hash_cache[(sizeof(struct BulletTypeModelHashCacheStateView) == 0x2ec) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_demo_id_hash_cache[(sizeof(struct DemoIdHashCacheRegionView) == 0x55c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_dmt_type_hash_cache[(sizeof(struct DmtTypeHashCacheRegionView) == 0x3c0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_ai_state_hash_cache[(sizeof(struct AiStateHashCacheRegionView) == 0x300) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_cm_quake_hash_cache[(sizeof(struct CmQuakeHashCacheRegionView) == 0x2a4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_ik_part_hash_cache[(sizeof(struct IkPartHashCacheRegionView) == 0x3ac) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_mrcl_type_hash_cache[(sizeof(struct MrclTypeHashCacheRegionView) == 0x400) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_character_animation_hash_cache[(sizeof(struct CharacterAnimationHashCacheRegionView) == 0x7c0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_spboost_status_hash_cache[(sizeof(struct SpBoostStatusHashCacheRegionView) == 0x340) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_condition_state_hash_cache[(sizeof(struct ConditionStateHashCacheRegionView) == 0x3f0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_enum_lookup_hash_cache[(sizeof(struct EnumLookupHashCacheRegionView) == 0x44c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_heal_mrcl_action_hash_cache[(sizeof(struct HealMrclActionHashCacheRegionView) == 0x3bc) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_hit_attribute_debuff_cache[(sizeof(struct HitAttributeDebuffCacheView) == 0x328) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_effect_mode_hash_cache[(sizeof(struct EffectModeHashCacheRegionView) == 0x3c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_menu_resource_hash_cache[(sizeof(struct MenuResourceHashCacheRecordView) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_parameter_metadata_record[(sizeof(struct ParameterMetadataRecordView) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_parameter_metadata_table[(sizeof(struct ParameterMetadataRecordTableView) == 0x70) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_parameter_metadata_pair[(sizeof(struct ParameterMetadataRecordPairView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_state_factory_record[(sizeof(struct StateFactoryRecordView) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_lifecycle_type_record[(sizeof(struct LifecycleTypeRecordView) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_state_lifecycle_record[(sizeof(struct StateLifecycleMetadataRecordView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_state_lifecycle_callback_record[(sizeof(struct StateLifecycleCallbackRecordView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_73[(sizeof(RunnerCollisionProfileView) == 0x90) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_74[(offsetof(FringRunnerParamView, field_198) == 0x198) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_75[(sizeof(FringRunnerParamView) == 0x1dc) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_76[(offsetof(BeetleRunnerParamView, field_298) == 0x298) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_77[(sizeof(BeetleRunnerParamView) == 0x2cc) ? 1 : -1] __attribute__((unused));
#else
typedef char kiu_sa_engine_common_views_36[(sizeof(struct PslNameSpan) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_37[(sizeof(struct PslMutableSpan) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_72[(sizeof(struct PslStringSpan) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_38[(offsetof(struct EngineResourceHandleEntryView, generation) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_39[(sizeof(struct EngineResourceHandleEntryView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_40[(offsetof(struct EngineOpaqueSpanView, capacity_flags) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_41[(sizeof(struct EngineOpaqueSpanView) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_42[(offsetof(struct EngineResourceObjectView, descriptor_span_00c) == 0x0c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_43[(offsetof(struct EngineResourceObjectView, animation_record) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_44[(offsetof(struct EngineResourceObjectView, opaque_span_020) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_45[(offsetof(struct EngineResourceObjectView, opaque_span_050) == 0x50) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_46[(offsetof(struct EngineResourceObjectView, opaque_064) == 0x64) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_47[(sizeof(struct EngineResourceObjectView) == 0x68) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_48[(offsetof(struct EngineRelativeResourceSourceView, relative_intermediate_02c) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_49[(offsetof(struct EngineRelativeResourceIntermediateView, relative_context_028) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_50[(offsetof(struct EngineRelativeResourceContextView, entry_count_010) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_51[(offsetof(struct EngineRelativeResourceContextView, relative_descriptor_indices_01c) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_52[(sizeof(struct EngineRelativeResourceEntryLinkView) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_53[(offsetof(struct EngineRelativeResourceEntryTableView, entries_028) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_54[(offsetof(struct EngineRelativeResourceEntryView, kind_010) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_55[(offsetof(struct EngineOwnedOpaqueSpanView, range_owner) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_56[(offsetof(struct EngineOwnedOpaqueSpanView, capacity_flags) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_57[(sizeof(struct EngineOwnedOpaqueSpanView) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_58[(offsetof(struct EngineEmbeddedRecordView, field_040) == 0x40) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_59[(offsetof(struct EngineEmbeddedRecordView, field_048) == 0x48) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_60[(offsetof(struct EngineEmbeddedRecordView, field_050) == 0x50) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_61[(offsetof(struct EngineEmbeddedRecordView, field_05c) == 0x5c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_62[(offsetof(struct EngineEmbeddedRecordView, field_068) == 0x68) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_63[(offsetof(struct EngineEmbeddedRecordView, field_06c) == 0x6c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_64[(offsetof(struct EngineEmbeddedRecordView, field_070) == 0x70) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_65[(offsetof(struct EngineEmbeddedRecordView, field_080) == 0x80) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_66[(sizeof(struct EngineEmbeddedRecordView) == 0x88) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_67[(offsetof(struct EngineRecordOwnerDescriptorView, field_048) == 0x48) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_68[(sizeof(struct EngineRecordOwnerDescriptorView) == 0x50) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_69[(offsetof(struct EngineRecordOwnerView, field_088) == 0x88) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_70[(offsetof(struct EngineRecordOwnerView, descriptor_190) == 0x190) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_5[(offsetof(struct ParameterRegistryNodeView, tree_payload_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_6[(offsetof(struct ParameterRegistryNodeView, tree_active_014) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_7[(offsetof(struct ParameterRegistryNodeView, name_hash_018) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_8[(sizeof(struct ParameterRegistryNodeView) == 0x20) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_12[(offsetof(struct ParameterRegistryRecordView, registration_state_021) == 0x21) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_13[(offsetof(struct ParameterRegistryRecordView, initializer_or_class_name_024) == 0x24) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_param_registry_14[(sizeof(struct ParameterRegistryRecordView) == 0x2c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_state_4[(offsetof(struct EngineGlobalStateRecordView, field_010) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_state_5[(offsetof(struct EngineGlobalStateRecordView, mode_flags_018) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_state_6[(sizeof(struct EngineGlobalStateRecordView) == 0x1c) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_record_5[(offsetof(struct EngineGlobalRecordD4D4C8View, field_014) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_record_6[(offsetof(struct EngineGlobalRecordD4D4C8View, callback_040) == 0x40) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_record_7[(offsetof(struct EngineGlobalRecordD4D4C8View, callback_argument_080) == 0x80) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_global_record_8[(sizeof(struct EngineGlobalRecordD4D4C8View) == 0x88) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_state_resource_slot_3[(offsetof(struct StateResourceGlobalSlotView, request_mode_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_state_resource_slot_4[(sizeof(struct StateResourceGlobalSlotView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_cfl_5[(offsetof(struct CflResourceGlobalStateView, field_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_cfl_6[(offsetof(struct CflResourceGlobalStateView, resource_008) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_cfl_7[(offsetof(struct CflResourceGlobalStateView, field_010) == 0x10) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_cfl_8[(sizeof(struct CflResourceGlobalStateView) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_d4d0f8_3[(offsetof(struct D4D0F8GlobalPrefixView, pointer_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_d4d0f8_4[(sizeof(struct D4D0F8GlobalPrefixView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_tagged_globals_4[(offsetof(struct TaggedBlockConstructorGlobalsView, marker_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_tagged_globals_5[(offsetof(struct TaggedBlockConstructorGlobalsView, stride_registry_014) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_tagged_globals_6[(sizeof(struct TaggedBlockConstructorGlobalsView) == 0x28) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_clone_globals_3[(offsetof(struct TaggedBlockCloneGlobalsView, type_tag_008) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_clone_globals_4[(sizeof(struct TaggedBlockCloneGlobalsView) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_type_marker_3[(offsetof(struct TaggedBlockTypeMarkerView, marker_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_type_marker_4[(sizeof(struct TaggedBlockTypeMarkerView) == 0x08) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_78[(sizeof(struct RunnerCollisionProfileView) == 0x90) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_79[(offsetof(struct FringRunnerParamView, field_198) == 0x198) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_80[(sizeof(struct FringRunnerParamView) == 0x1dc) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_81[(offsetof(struct BeetleRunnerParamView, field_298) == 0x298) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_engine_common_views_82[(sizeof(struct BeetleRunnerParamView) == 0x2cc) ? 1 : -1] __attribute__((unused));
#endif
struct ResourceRecordInit {
    uint32_t value10;
    uint32_t value04;
    uint32_t value08;
    uint32_t value14;
    uint32_t flags;
    uint32_t value1c;
    uint32_t value20;
    uint32_t flag_shift;
};
#endif  
