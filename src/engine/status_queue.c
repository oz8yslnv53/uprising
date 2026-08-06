#include <stddef.h>
#include <stdint.h>
extern uint32_t *StatusQueue_ApplyOrCreate(void *context, unsigned owner,
                                             int channel, int mode, int amount);
extern void *EngineIndexedTableEntry(int channel);
extern uint32_t StatusQueueSelectFallbackValue(void *record);
extern int StatusChannelIndexMap(int identifier);
extern void *StatusFallbackStateSingleton(void);
extern int EngineObjectStatePredicate(void *object);
void StatusQueue_ApplyMode(void *queue, void *destination,
                            const uint8_t *subrecord, uint32_t mode);
extern void StatusQueueAttachSubrecord(void *queue, void *subrecord);
extern const uint8_t StatusQueueModeMaskTable[4];
extern uint32_t StatusQueueSpecialSubrecordValue;
extern uint32_t StatusQueueResolveSpecialControl(void *queue);
struct StatusQueueModeZeroSubrecordView {
    uint8_t opaque_000[4];
    uint16_t lane_mask_004;
    uint8_t opaque_006[2];
    float lane_delta_008;
};
struct StatusQueueThreeScalarSubrecordView {
    uint8_t opaque_000[4];
    float value_004;
    float value_008;
    float value_00c;
};
typedef char kiu_sa_status_queue_1[(offsetof(struct StatusQueueModeZeroSubrecordView, lane_mask_004) == 4) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_queue_2[(offsetof(struct StatusQueueModeZeroSubrecordView, lane_delta_008) == 8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_queue_3[(offsetof(struct StatusQueueThreeScalarSubrecordView, value_00c) == 0xc) ? 1 : -1] __attribute__((unused));
extern void *GetSharedRegistrySingleton(void);
extern void *Engine_LazySingletonGetter_0054EFA8(void);
extern void *ResourceStatus_LookupByHandle(void *registry, uint32_t handle);
extern void *ResolveCachedComponent_1EC(void *object);
struct StatusQueueEntryView {
    int8_t value;
    uint8_t canonical_index;
    int16_t channel;
    uint8_t opaque_004[4];
};
struct StatusQueueRegistryStateView {
    uint8_t opaque_000[0xb64];
    uint32_t queue_flags_b64;
    uint8_t opaque_b68[0x110];
    uint32_t active_count_c78;
    uint8_t opaque_c7c[4];
    struct StatusQueueEntryView entries_c80[13];
};
typedef char kiu_sa_status_queue_4[(offsetof(struct StatusQueueRegistryStateView, queue_flags_b64) == 0xb64) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_queue_5[(offsetof(struct StatusQueueRegistryStateView, active_count_c78) == 0xc78) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_status_queue_6[(offsetof(struct StatusQueueRegistryStateView, entries_c80) == 0xc80) ? 1 : -1] __attribute__((unused));
extern void *GetSharedRegistrySingleton(void);
void StatusQueueApplyRecordMode(void *queue, void *sentinel, void *record,
                                   uint32_t mode);
void StatusQueueApplyModeZero(float lanes[12],
                                 const struct StatusQueueModeZeroSubrecordView *subrecord);
void StatusQueueApplyModeOne(float values[3],
                                const struct StatusQueueThreeScalarSubrecordView *subrecord,
                                uint32_t mode);
void StatusQueueApplyModeThree(float values[3],
                                  const struct StatusQueueThreeScalarSubrecordView *subrecord,
                                  uint32_t mode);
void StatusQueueApplyModeTwo(void *destination,
                                const uint8_t *subrecord, uint32_t mode);
void StatusQueueApplyModeFour(void *destination,
                                 const uint8_t *subrecord, uint32_t mode);
void StatusQueueApplyModeFive(void *destination,
                                 const uint8_t *subrecord, uint32_t mode);
void StatusQueueApplyModeSix(void *destination,
                                const uint8_t *subrecord, uint32_t mode);
void StatusQueueApplyModeSeven(void *destination,
                                  const uint8_t *subrecord);
void StatusQueueApplyModeEight(void *destination,
                                  const uint8_t *subrecord);
void StatusQueueApplyModeNine(void *queue, void *destination,
                                 const uint8_t *subrecord);
void StatusQueueApplyModeTen(void *destination,
                                const uint8_t *subrecord, uint32_t mode);
void StatusQueueApplyModeEleven(void *destination,
                                  const uint8_t *subrecord);
void StatusQueueApplyModeTwelve(void *destination);
void StatusQueueApplyModeFourteen(void *queue, void *destination,
                                     const uint8_t *subrecord, uint32_t mode);
void StatusQueueApplyModeTwenty(void *destination,
                                     const uint8_t *subrecord);
void StatusQueueApplyModeTwentyTwo(void *destination,
                                      const uint8_t *subrecord, uint32_t mode);
void StatusQueueApplyModeTwentyFour(void *destination,
                                        const uint8_t *subrecord,
                                        uint32_t mode);
void StatusQueueApplyModeTwentyFive(void *destination,
                                       const uint8_t *subrecord, uint32_t mode);
void StatusQueueApplyModeTwentyNine(void *destination,
                                        const uint8_t *subrecord);
void StatusQueueApplyModeThirty(void *destination,
                                       const uint8_t *subrecord);
void StatusQueueApplyModeThirtyOne(void *destination,
                                   const uint8_t *subrecord);
void StatusQueueAttachParameterRecord(void *queue, void *record,
                                         uint32_t mode);
void StatusQueueApplySubrecord(void *queue, const uint8_t *subrecord);
void StatusQueue_InitializeRecord(void *record, uint16_t channel,
                                    int priority);
void StatusQueue_Advance(void *table, unsigned channel, int delta);
void StatusQueueCompact(void *queue);
uint32_t StatusQueueSelectFallbackValue(void *record);
uint32_t *StatusQueue_ApplyOrCreate(void *context, unsigned owner,
                                      int channel, int mode, int amount);
int StatusChannelIndexMap(int identifier);
void StatusQueueClearMatchingChannel(void *table, int channel);
__attribute__((noinline)) void StatusQueueApplyRecordMode(
    void *queue, void *sentinel, void *record, uint32_t mode)
{
    uint8_t *record_bytes = (uint8_t *)record;
    StatusQueue_ApplyMode(queue, sentinel, record_bytes + 0x78u, mode);
    StatusQueue_ApplyMode(queue, sentinel, record_bytes + 0x88u, mode);
    StatusQueue_ApplyMode(queue, sentinel, record_bytes + 0x98u, mode);
    StatusQueue_ApplyMode(queue, sentinel, record_bytes + 0xa8u, mode);
    StatusQueue_ApplyMode(queue, sentinel, record_bytes + 0xb8u, mode);
    StatusQueue_ApplyMode(queue, sentinel, record_bytes + 0xc8u, mode);
    StatusQueue_ApplyMode(queue, sentinel, record_bytes + 0xd8u, mode);
    StatusQueue_ApplyMode(queue, sentinel, record_bytes + 0xe8u, mode);
}
void StatusQueueApplyModeZero(float lanes[12],
                                 const struct StatusQueueModeZeroSubrecordView *subrecord)
{
    float delta = subrecord->lane_delta_008 - 1.0f;
    for (unsigned lane = 0; lane < 12u; ++lane) {
        if ((subrecord->lane_mask_004 & (uint16_t)(1u << lane)) != 0)
            lanes[lane] += delta;
    }
}
void StatusQueueApplyModeOne(float values[3],
                                const struct StatusQueueThreeScalarSubrecordView *subrecord,
                                uint32_t mode)
{
    const float source[3] = {
        subrecord->value_004, subrecord->value_008, subrecord->value_00c
    };
    for (unsigned lane = 0; lane < 3u; ++lane)
        values[lane] = mode == 0 ? values[lane] + source[lane] - 1.0f
                                 : values[lane] * source[lane];
}
void StatusQueueApplyModeThree(float values[3],
                                  const struct StatusQueueThreeScalarSubrecordView *subrecord,
                                  uint32_t mode)
{
    values[0] = mode == 0 ? values[0] + subrecord->value_004 - 1.0f
                          : values[0] * subrecord->value_004;
    values[1] += subrecord->value_008;
    values[2] += subrecord->value_00c;
}
static void StatusQueueApplyMaskedLanes(
    uint8_t *destination, size_t lane_offset, unsigned lane_count,
    uint32_t mask, float source, uint32_t mode)
{
    float value = mode == 0 ? source - 1.0f : source;
    for (unsigned lane = 0; lane < lane_count; ++lane) {
        if ((mask & (1u << lane)) != 0) {
            float *slot = (float *)(destination + lane_offset + lane * 4u);
            *slot = mode == 0 ? *slot + value : *slot * value;
        }
    }
}
void StatusQueueApplyModeTwo(void *destination,
                                const uint8_t *subrecord, uint32_t mode)
{
    StatusQueueApplyMaskedLanes(
        (uint8_t *)destination, 0x3cu, 12u,
        *(const uint16_t *)(subrecord + 4),
        *(const float *)(subrecord + 8), mode);
}
void StatusQueueApplyModeFour(void *destination,
                                 const uint8_t *subrecord, uint32_t mode)
{
    StatusQueueApplyMaskedLanes(
        (uint8_t *)destination, 0x78u, 2u, subrecord[4],
        *(const float *)(subrecord + 8), mode);
}
void StatusQueueApplyModeFive(void *destination,
                                 const uint8_t *subrecord, uint32_t mode)
{
    StatusQueueApplyMaskedLanes(
        (uint8_t *)destination, 0x88u, 4u, subrecord[4],
        *(const float *)(subrecord + 8), mode);
}
void StatusQueueApplyModeSix(void *destination,
                                const uint8_t *subrecord, uint32_t mode)
{
    StatusQueueApplyMaskedLanes(
        (uint8_t *)destination, 0x98u, 4u, subrecord[4],
        *(const float *)(subrecord + 8), mode);
}
void StatusQueueApplyModeSeven(void *destination,
                                  const uint8_t *subrecord)
{
    uint8_t *bytes = (uint8_t *)destination;
    bytes[0xa8] = subrecord[4];
    bytes[0xa9] = subrecord[5];
}
void StatusQueueApplyModeEight(void *destination,
                                  const uint8_t *subrecord)
{
    ((uint8_t *)destination)[0xaa] = subrecord[4];
}
void StatusQueueApplyModeNine(void *queue, void *destination,
                                 const uint8_t *subrecord)
{
    uint8_t index = subrecord[4];
    uint8_t *queue_bytes = (uint8_t *)queue;
    uint8_t *slot;
    if (index == 0x11u)
        index = queue_bytes[0x444];
    slot = (uint8_t *)destination + (unsigned)index * 4u;
    *(float *)(slot + 0xacu) += *(const float *)(subrecord + 8);
    *(uint32_t *)(slot + 0xecu) = *(const uint32_t *)(subrecord + 0xc);
}
void StatusQueueApplyModeTen(void *destination,
                                const uint8_t *subrecord, uint32_t mode)
{
    StatusQueueApplyMaskedLanes(
        (uint8_t *)destination, 0x12cu, 22u,
        *(const uint32_t *)(subrecord + 4),
        *(const float *)(subrecord + 8), mode);
}
void StatusQueueApplyModeEleven(void *destination,
                                  const uint8_t *subrecord)
{
    uint8_t *slot = (uint8_t *)destination + (unsigned)subrecord[4] * 4u;
    *(uint32_t *)(slot + 0x184u) += *(const uint32_t *)(subrecord + 8);
}
void StatusQueueApplyModeTwelve(void *destination)
{
    ((uint8_t *)destination)[0x194] = 1;
}
void StatusQueueApplyModeFourteen(void *queue, void *destination,
                                     const uint8_t *subrecord, uint32_t mode)
{
    float source = *(const float *)(subrecord + 4);
    float *destination_value = (float *)((uint8_t *)destination + 0x198u);
    (void)queue;
    *destination_value = mode == 0 ? *destination_value + source - 1.0f
                                   : *destination_value * source;
}
void StatusQueueApplyModeSixteen(void *queue, void *destination)
{
    static void **registry_slot = (void **)(uintptr_t)0x00d63578u;
    void *registry = *registry_slot;
    void *resource;
    void *component;
    if (registry == 0) {
        registry = Engine_LazySingletonGetter_0054EFA8();
        *registry_slot = registry;
    }
    resource = ResourceStatus_LookupByHandle(
        registry, *(uint32_t *)((uint8_t *)queue + 0x7c4u));
    if (resource == 0)
        return;
    component = ResolveCachedComponent_1EC(resource);
    if (component == 0)
        return;
    *(uint32_t *)((uint8_t *)component + 0x98u) |= 0x40u;
    *(uint8_t *)((uint8_t *)destination + 0x1c4u) = 1;
}
static void StatusQueueApplyModeFloat(float *destination, float source,
                                         uint32_t mode)
{
    *destination = mode == 0 ? *destination + source - 1.0f
                             : *destination * source;
}
void StatusQueueApplyModeTwenty(void *destination,
                                     const uint8_t *subrecord)
{
    uint8_t *bytes = (uint8_t *)destination;
    uint32_t mask = *(const uint32_t *)(subrecord + 4);
    *(uint32_t *)(bytes + 0x1a0u) |= mask;
    if (mask == 0x800u)
        *(uint32_t *)(bytes + 0x1bcu) = *(const uint32_t *)(subrecord + 8);
}
void StatusQueueApplyModeTwentyTwo(void *destination,
                                      const uint8_t *subrecord, uint32_t mode)
{
    StatusQueueApplyModeFloat(
        (float *)((uint8_t *)destination + 0x1a4u),
        *(const float *)(subrecord + 4), mode);
}
void StatusQueueApplyModeTwentyFour(void *destination,
                                        const uint8_t *subrecord,
                                        uint32_t mode)
{
    uint8_t *bytes = (uint8_t *)destination;
    StatusQueueApplyModeFloat((float *)(bytes + 0x1a8u),
                                 *(const float *)(subrecord + 4), mode);
    StatusQueueApplyModeFloat((float *)(bytes + 0x1acu),
                                 *(const float *)(subrecord + 8), mode);
}
void StatusQueueApplyModeTwentyFive(void *destination,
                                       const uint8_t *subrecord, uint32_t mode)
{
    StatusQueueApplyModeFloat(
        (float *)((uint8_t *)destination + 0x1b0u),
        *(const float *)(subrecord + 4), mode);
}
void StatusQueueApplyModeTwentyNine(void *destination,
                                        const uint8_t *subrecord)
{
    uint8_t *bytes = (uint8_t *)destination;
    *(uint32_t *)(bytes + 0x1b4u) += *(const uint32_t *)(subrecord + 4);
}
void StatusQueueApplyModeThirty(void *destination,
                                       const uint8_t *subrecord)
{
    uint8_t *bytes = (uint8_t *)destination;
    *(uint32_t *)(bytes + 0x1b8u) += *(const uint32_t *)(subrecord + 4);
}
void StatusQueueApplyModeThirtyOne(void *destination,
                                   const uint8_t *subrecord)
{
    uint8_t *bytes = (uint8_t *)destination;
    *(float *)(bytes + 0x1c0u) *= *(const float *)(subrecord + 4);
}
__attribute__((noinline)) void StatusQueue_ApplyMode(void *queue, void *destination,
                            const uint8_t *subrecord, uint32_t mode)
{
    switch (subrecord[0]) {
    case 0:
        StatusQueueApplyModeZero((float *)destination,
                                 (const struct StatusQueueModeZeroSubrecordView *)subrecord);
        return;
    case 1:
        StatusQueueApplyModeOne((float *)((uint8_t *)destination + 0x30u),
                                (const struct StatusQueueThreeScalarSubrecordView *)subrecord,
                                mode);
        return;
    case 2:
        StatusQueueApplyModeTwo(destination, subrecord, mode);
        return;
    case 3:
        StatusQueueApplyModeThree((float *)((uint8_t *)destination + 0x6cu),
                                  (const struct StatusQueueThreeScalarSubrecordView *)subrecord,
                                  mode);
        return;
    case 4:
        StatusQueueApplyModeFour(destination, subrecord, mode);
        return;
    case 5:
        StatusQueueApplyModeFive(destination, subrecord, mode);
        return;
    case 6:
        StatusQueueApplyModeSix(destination, subrecord, mode);
        return;
    case 7:
        StatusQueueApplyModeSeven(destination, subrecord);
        return;
    case 8:
        StatusQueueApplyModeEight(destination, subrecord);
        return;
    case 9:
        StatusQueueApplyModeNine(queue, destination, subrecord);
        return;
    case 10:
        StatusQueueApplyModeTen(destination, subrecord, mode);
        return;
    case 11:
        StatusQueueApplyModeEleven(destination, subrecord);
        return;
    case 12:
        StatusQueueApplyModeTwelve(destination);
        return;
    case 14:
        StatusQueueApplyModeFourteen(queue, destination, subrecord, mode);
        return;
    case 16:
        StatusQueueApplyModeSixteen(queue, destination);
        return;
    case 20:
        StatusQueueApplyModeTwenty(destination, subrecord);
        return;
    case 22:
        StatusQueueApplyModeTwentyTwo(destination, subrecord, mode);
        return;
    case 24:
        StatusQueueApplyModeTwentyFour(destination, subrecord, mode);
        return;
    case 25:
        StatusQueueApplyModeTwentyFive(destination, subrecord, mode);
        return;
    case 29:
        StatusQueueApplyModeTwentyNine(destination, subrecord);
        return;
    case 30:
        StatusQueueApplyModeThirty(destination, subrecord);
        return;
    case 31:
        StatusQueueApplyModeThirtyOne(destination, subrecord);
        return;
    default:
        return;
    }
}
__attribute__((noinline)) void StatusQueueAttachParameterRecord(void *queue, void *record,
                                         uint32_t mode)
{
    uint8_t *queue_bytes = (uint8_t *)queue;
    uint8_t *record_bytes = (uint8_t *)record;
    if (mode == 0) {
        StatusQueueApplyRecordMode(queue, queue_bytes + 0x1c8u, record, 0);
    } else {
        int32_t count = *(int32_t *)(queue_bytes + 0x78cu);
        if (count < 4) {
            uint8_t mask = mode < 4u ? StatusQueueModeMaskTable[mode] : 0;
            uint8_t *entry = queue_bytes + 0x76cu + (uint32_t)count * 8u;
            *(void **)(entry + 0) = record;
            entry[4] = mask;
            queue_bytes[0x790] |= mask;
            *(int32_t *)(queue_bytes + 0x78cu) =
                *(int32_t *)(queue_bytes + 0x78cu) + 1;
        }
    }
    StatusQueueAttachSubrecord(queue, record_bytes + 0x78u);
    StatusQueueAttachSubrecord(queue, record_bytes + 0x88u);
    StatusQueueAttachSubrecord(queue, record_bytes + 0x98u);
    StatusQueueAttachSubrecord(queue, record_bytes + 0xa8u);
    StatusQueueAttachSubrecord(queue, record_bytes + 0xb8u);
    StatusQueueAttachSubrecord(queue, record_bytes + 0xc8u);
    StatusQueueAttachSubrecord(queue, record_bytes + 0xd8u);
    StatusQueueAttachSubrecord(queue, record_bytes + 0xe8u);
    queue_bytes[0x45c] = 1;
}
__attribute__((noinline)) void StatusQueueApplySubrecord(void *queue, const uint8_t *subrecord)
{
    uint8_t *queue_bytes = (uint8_t *)queue;
    if (subrecord[0] == 0x0du) {
        uint32_t value = *(const uint32_t *)(subrecord + 0x0cu);
        if ((value == 0x01010000u ||
             value == StatusQueueSpecialSubrecordValue) &&
            *(int32_t *)(queue_bytes + 0x448u) == -1) {
            *(uint32_t *)(queue_bytes + 0x448u) =
                StatusQueueResolveSpecialControl(queue);
        }
    } else if (subrecord[0] == 0x15u) {
        *(uint32_t *)(queue_bytes + 0x430u) =
            *(const uint32_t *)(subrecord + 4);
    } else if (subrecord[0] == 0x17u) {
        *(uint32_t *)(queue_bytes + 0x434u) =
            *(const uint32_t *)(subrecord + 4);
    }
}
__attribute__((noinline)) void StatusQueue_InitializeRecord(void *record, uint16_t channel,
                                  int priority)
{
    int clamped = priority;
    *(uint16_t *)((uint8_t *)record + 0x1a0u) = channel;
    *(uint32_t *)((uint8_t *)record + 0x1acu) = 1;
    if (clamped < -1)
        clamped = 0;
    if (clamped >= 2)
        clamped = 1;
    *(int32_t *)((uint8_t *)record + 0x1a4u) = clamped;
    *(uint32_t *)((uint8_t *)record + 0x1a8u) = 0;
}
__attribute__((noinline)) void StatusQueue_Advance(void *table, unsigned channel, int delta)
{
    uint8_t *bytes = (uint8_t *)table;
    unsigned entry_index = bytes[channel + 0xc8u];
    int32_t total;
    int32_t limit;
    int32_t quotient;
    if (entry_index == 0xffu) {
        if (*(int16_t *)(bytes + 0x1a0u) != (int16_t)channel)
            return;
        total = *(int32_t *)(bytes + 0x1a8u) +
                *(int32_t *)(bytes + 0x1a4u) * 100 + delta;
        limit = *(int32_t *)(bytes + 0x1acu) * 100 + 0x5a;
        if (total > limit)
            total = limit;
        quotient = total / 100;
        *(int32_t *)(bytes + 0x1a4u) = quotient;
        *(int32_t *)(bytes + 0x1a8u) = total - quotient * 100;
        return;
    }
    bytes += entry_index * 0x10u;
    total = *(int32_t *)(bytes + 0x10u) +
            *(int32_t *)(bytes + 0x0cu) * 100 + delta;
    limit = *(int32_t *)(bytes + 0x14u) * 100 + 0x5a;
    if (total > limit)
        total = limit;
    quotient = total / 100;
    *(int32_t *)(bytes + 0x0cu) = quotient;
    *(int32_t *)(bytes + 0x10u) = total - quotient * 100;
}
__attribute__((noinline)) void StatusQueueCompact(void *queue)
{
    uint8_t *bytes = (uint8_t *)queue;
    unsigned entry_count = *(uint32_t *)(bytes + 0x114u);
    unsigned read_index;
    unsigned write_index = 0;
    for (read_index = 0; read_index < entry_count; ++read_index) {
        uint8_t *entry = bytes + 0x11cu + read_index * 8u;
        if (*(int8_t *)entry < 1) {
            *(int8_t *)(entry + 6) = -1;
        } else {
            bytes[0x188u + write_index] = (uint8_t)read_index;
            *(uint8_t *)(entry + 6) = (uint8_t)write_index;
            ++write_index;
        }
    }
    if (*(int32_t *)(bytes + 0x184u) == 0 && write_index != 0) {
        uint32_t flags = *(uint32_t *)(bytes + 4);
        *(uint32_t *)(bytes + 4) = (flags & ~0x10000u) | 0x8000u;
    }
    *(uint32_t *)(bytes + 0x184u) = write_index;
}
__attribute__((noinline)) uint32_t StatusQueueSelectFallbackValue(void *record)
{
    static void **singleton_slot = (void **)(uintptr_t)0x00d63588u;
    void *object = *singleton_slot;
    if (object == 0) {
        object = StatusFallbackStateSingleton();
        *singleton_slot = object;
    }
    return *(uint32_t *)((uint8_t *)record +
                         (EngineObjectStatePredicate(object) ? 0xa0u :
                                                                    0x9cu));
}
__attribute__((noinline)) static uint32_t *StatusQueueAppendMissingRecord(
    void *shared, int channel, int priority)
{
    struct StatusQueueRegistryStateView *state;
    struct StatusQueueEntryView *entry;
    int canonical = StatusChannelIndexMap((int16_t)channel);
    if (shared == 0 || *(void **)((uint8_t *)shared + 0x140u) == 0)
        return 0;
    state = (struct StatusQueueRegistryStateView *)
        *(void **)((uint8_t *)shared + 0x140u);
    if (channel < 0 || canonical < 0 || priority < 1)
        return &state->queue_flags_b64;
    if ((state->queue_flags_b64 & 0x04000000u) == 0) {
        if (state->active_count_c78 >= 13u)
            return &state->queue_flags_b64;
        state->queue_flags_b64 |= 0x04000000u;
        ++state->active_count_c78;
    }
    if (state->active_count_c78 == 0)
        return &state->queue_flags_b64;
    entry = &state->entries_c80[state->active_count_c78 - 1u];
    entry->value = (int8_t)priority;
    entry->canonical_index = (uint8_t)canonical;
    entry->channel = (int16_t)channel;
    StatusQueueCompact(&state->queue_flags_b64);
    return &state->queue_flags_b64;
}
__attribute__((noinline)) static uint32_t StatusQueueApplyOwnerTransition(void *shared,
                                                    int channel,
                                                    int priority)
{
    uint8_t *state;
    uint8_t *queue;
    uint32_t count;
    uint32_t index;
    if (shared == 0 || *(void **)((uint8_t *)shared + 0x140u) == 0)
        return 0;
    state = (uint8_t *)*(void **)((uint8_t *)shared + 0x140u);
    queue = state + 0xb64u;
    if (priority < 0)
        priority = 0;
    else if (priority > 99)
        priority = 99;
    count = *(uint32_t *)(queue + 0x114u);
    for (index = 0; index < count; ++index) {
        uint8_t *entry = queue + 0x11cu + index * 8u;
        int old_priority;
        if (*(int16_t *)(entry + 2u) != channel)
            continue;
        old_priority = *(int8_t *)entry;
        *(int8_t *)entry = (int8_t)priority;
        if (priority <= 0 && old_priority > 0) {
            int8_t selection = *(int8_t *)(queue + 0x198u);
            if (selection >= 0) {
                uint32_t compact_count = *(uint32_t *)(queue + 0x184u);
                *(int8_t *)(queue + 0x198u) = -1;
                *(int8_t *)(queue + 0x19au) = -1;
                if ((uint32_t)selection < compact_count) {
                    uint8_t mapped = *(uint8_t *)(queue + 0x188u +
                                                   (uint8_t)selection);
                    uint8_t *selected = queue + 0x11cu + mapped * 8u;
                    uint32_t current = *(uint32_t *)(queue + 0x118u);
                    uint16_t transition;
                    *(uint8_t *)(queue + 0x1c9u) = (uint8_t)selection;
                    *(uint32_t *)(queue + 0x1ccu) = (uintptr_t)selected;
                    *(uint32_t *)(queue + 0x1d4u) = 0;
                    *(uint32_t *)(queue + 4u) =
                        (*(uint32_t *)(queue + 4u) & 0x3fffffffu) |
                        0x20000000u;
                    if (current == (uint32_t)(uint8_t)selection) {
                        if (compact_count > 1u)
                            transition = (uint32_t)selection <
                                         compact_count - 1u ? 4u : 8u;
                        else
                            transition = 0;
                    } else if ((uint32_t)(uint8_t)selection < current) {
                        transition = selection > 0 ? 9u : 1u;
                    } else {
                        transition = (uint32_t)(uint8_t)selection <
                                     compact_count - 1u ? 6u : 2u;
                    }
                    *(uint16_t *)(queue + 0x1cau) = transition;
                    if (current > 0 && (transition & 6u) == 0) {
                        --current;
                        *(uint32_t *)(queue + 0x118u) = current;
                        *(float *)(queue + 0x1b0u) = 0.0f;
                        *(float *)(queue + 0x1a4u) = (float)current;
                    }
                }
                StatusQueueCompact(queue);
                *(int8_t *)entry = (int8_t)priority;
            } else {
                *(int8_t *)(queue + 0x198u) = *(int8_t *)(entry + 6u);
            }
            return 1;
        }
        StatusQueueCompact(queue);
        return 1;
    }
    return 0;
}
__attribute__((noinline)) uint32_t *StatusQueue_ApplyOrCreate(void *context, unsigned owner,
                                      int channel, int mode, int amount)
{
    uint8_t *table;
    uint8_t selector;
    int priority;
    int updated_priority;
    void *indexed_record;
    if (mode == 0 && amount == 0)
        return 0;
    indexed_record = EngineIndexedTableEntry(channel);
    if (indexed_record == 0)
        return 0;
    table = (uint8_t *)context + owner * 0x8b8u + 0x1250u;
    selector = table[channel + 0xc8u];
    if (selector == 0xffu) {
        uint8_t *owner_base = (uint8_t *)context + owner * 0x8b8u;
        if (*(int16_t *)(owner_base + 0x13f0u) == channel)
            priority = *(int32_t *)(owner_base + 0x13f4u);
        else
            priority = -1;
    } else {
        priority = *(int32_t *)(table + selector * 0x10u + 0x0cu);
    }
    if (priority >= 0) {
        uint8_t *owner_base = (uint8_t *)context + owner * 0x8b8u;
        StatusQueue_Advance(table, (unsigned)channel,
                              amount + mode * 100);
        if (selector == 0xffu) {
            if (*(int16_t *)(owner_base + 0x13f0u) == channel)
                updated_priority = *(int32_t *)(owner_base + 0x13f4u);
            else
                updated_priority = -1;
        } else {
            updated_priority = *(int32_t *)(table + selector * 0x10u +
                                             0x0cu);
        }
        if (owner == 0u && priority != updated_priority) {
            static void **shared_slot = (void **)(uintptr_t)0x00d63654u;
            void *shared = *shared_slot;
            if (shared == 0) {
                shared = GetSharedRegistrySingleton();
                *shared_slot = shared;
            }
            return (uint32_t *)(uintptr_t)
                StatusQueueApplyOwnerTransition(shared, channel,
                                                   updated_priority);
        }
        if (selector == 0xffu) {
            return (uint32_t *)(uintptr_t)0xffu;
        }
        return (uint32_t *)(table + selector * 0x10u);
    }
    priority = mode >= -1 ? mode : 0;
    {
        uint32_t fallback = StatusQueueSelectFallbackValue(indexed_record);
        if ((int32_t)fallback < priority)
            priority = (int)fallback;
    }
    StatusQueue_InitializeRecord(table, (uint16_t)channel, priority);
    {
        static void **shared_slot = (void **)(uintptr_t)0x00d63654u;
        void *shared = *shared_slot;
        if (shared == 0) {
            shared = GetSharedRegistrySingleton();
            *shared_slot = shared;
        }
        return StatusQueueAppendMissingRecord(shared, channel, priority);
    }
}
__attribute__((noinline)) void StatusQueueClearMatchingChannel(void *table, int channel)
{
    uint8_t *bytes = (uint8_t *)table;
    uint8_t *head = *(uint8_t **)(bytes + 0x460u);
    uint8_t **cursor = *(uint8_t ***)(bytes + 0x464u);
    if (*cursor != head) {
        do {
            uint8_t *entry = *cursor;
            uint32_t tag = *(uint32_t *)(entry + 0x0cu);
            if ((tag >> 24) == 1u &&
                StatusChannelIndexMap((int16_t)tag) == channel)
                *(float *)(entry + 0x14u) = 0.0f;
            cursor = (uint8_t **)(cursor[1]);
        } while (*cursor != head);
    }
}
