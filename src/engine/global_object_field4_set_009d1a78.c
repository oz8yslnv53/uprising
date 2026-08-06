#include <stdint.h>
#include <stddef.h>
typedef struct GlobalObjectDescriptorCacheRecord {
    uint8_t key_000;
    uint8_t opaque_001_to_003[3];
    uint32_t field_004;
    uint32_t value_008;
    uint32_t value_00c;
    uint32_t value_010;
    uint32_t value_014;
    uint32_t match_count_018;
} GlobalObjectDescriptorCacheRecord;
typedef char kiu_sa_global_object_descriptor_cache_1[
    (offsetof(GlobalObjectDescriptorCacheRecord, field_004) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_global_object_descriptor_cache_2[
    (sizeof(GlobalObjectDescriptorCacheRecord) == 0x1c) ? 1 : -1] __attribute__((unused));
__attribute__((noinline)) void Engine_GlobalObjectField4Set_009D1A78(uint32_t value) {
    GlobalObjectDescriptorCacheRecord *object =
        (GlobalObjectDescriptorCacheRecord *)0x00d4a350;
    object->field_004 = value;
}
