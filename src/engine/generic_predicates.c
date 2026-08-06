#include <stddef.h>
#include <stdint.h>
typedef void (*ChannelNotify_00C86674)(void *object);
__attribute__((noinline)) void AnimeCommand_Channel_Notify_00C86674(
    uint8_t *record)
{
    void *object = *(void **)(record + 4);
    if (object != 0) {
        ChannelNotify_00C86674 callback =
            (ChannelNotify_00C86674)(*(uintptr_t *)(*(uintptr_t *)object +
                                                    0x38u));
        callback(object);
    }
}
extern uint32_t GenericModeePredicate_00513330(void);
extern uint32_t GenericGlobalKeyValidator_005B0070(void *candidate);
extern void DebugTrap_004B0440(void);
extern void NoOpTaggedHook_009B155C(void *object, const uint32_t tag_pair[2]);
extern void GenericSortedTableUpsert_00BD6F58(void *record, int32_t slot_key,
                                               uint32_t value_lo,
                                               uint32_t value_hi);
__attribute__((noinline)) uint32_t GenericBuildVariantPredicate_005723C4(void)
{
    static int32_t *const context_root_slot = (int32_t *)(uintptr_t)0x00572414u;
    static uint32_t *const flag_a_slot = (uint32_t *)(uintptr_t)0x00572418u;
    static uint32_t *const flag_b_slot = (uint32_t *)(uintptr_t)0x0057241cu;
    int32_t *context = *(int32_t **)((uint8_t *)context_root_slot + 4);
    int32_t record_count;
    if (context == NULL)
        return 0;
    record_count = *(int32_t *)((uint8_t *)context + 4);
    if (record_count < 0 || *((uint8_t *)context + 0x11) != 2)
        return 0;
    if (*flag_a_slot == 0)
        return 0;
    return *flag_a_slot == *flag_b_slot;
}
__attribute__((noinline)) uint32_t PackedFlags_TestModeBit_008815C0(uint32_t flags)
{
    if ((flags & 0x3fc00u) == 0xc000u)
        return (flags & 0x40u) >> 6;
    return 0u;
}
__attribute__((noinline)) void ZeroPairOrDebugTrap_004DE248(uint32_t out_pair[2])
{
    static const uint32_t *const debug_flag_slot =
        (const uint32_t *)(uintptr_t)0x004de26cu;
    if (*debug_flag_slot != 0) {
        DebugTrap_004B0440();
        return;
    }
    out_pair[0] = 0;
    out_pair[1] = 0;
}
__attribute__((noinline)) int32_t *CachedFieldGet_009C5334(int32_t *out_param)
{
    static int32_t *const cache_slot = (int32_t *)(uintptr_t)0x009c5388u;
    int32_t value = *cache_slot;
    *out_param = 0;
    if (value == 0) {
        uint32_t pair[2];
        ZeroPairOrDebugTrap_004DE248(pair);
        value = (int32_t)pair[0];
        *cache_slot = value;
    }
    *out_param = value;
    return out_param;
}
__attribute__((noinline)) void SlotEnableMask_Set_00830128(void *record, uint32_t slot)
{
    uint16_t nibble_mask;
    if (GenericModeePredicate_00513330() == 0)
        return;
    if (GenericGlobalKeyValidator_005B0070(record) == 0)
        return;
    nibble_mask = (uint16_t)(0xfu << ((slot & 0x3fu) << 2));
    *(uint32_t *)((uint8_t *)record + 0x128) = 0;
    *(uint16_t *)((uint8_t *)record + 0x84) =
        (uint16_t)(nibble_mask | (*(uint16_t *)((uint8_t *)record + 0x84) & ~nibble_mask));
}
