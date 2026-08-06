#include <stddef.h>
#include <stdint.h>
#include "actor_tap_records.h"
struct ActorInputRecord {
    uint8_t control_mode;
    uint8_t reserved_01[3];
    uint32_t sequence;
    float aim_x;
    float aim_y;
    uint8_t current_2000;
    uint8_t pressed_2000;
    uint8_t dash_or_current_1000000;
    uint8_t pressed_1000;
    uint8_t pressed_800000;
    uint8_t reserved_15[3];
};
struct ActorInputPacketView {
    uint8_t reserved_00[4];
    uint32_t current_flags;
    uint32_t pressed_flags;
    uint32_t released_flags;
    uint8_t reserved_10[0x18];
    int32_t tap_x;
    int32_t tap_y;
    uint32_t packet_x;
    uint32_t packet_y;
    float aim_x;
    float aim_y;
};
struct ActorInputReceiver {
    uint8_t opaque_000[0x34];
    uint32_t next_sequence;
    struct ActorInputRecord records[16];
    uint32_t head;
    uint32_t count;
    struct ActorTapBatch tap_batch;
    uint8_t current_2000;
    uint8_t pressed_20000;
    uint8_t pressed_1000;
    uint8_t pressed_40000;
};
extern void *Engine_DescriptorKey_004FCC08(void);
extern void *OrderedTreeLowerBoundByPointer(void *tree, void *key);
extern struct ActorInputReceiver *ActorInputReceiverFromEntry_00BB3A48(
    void *entry);
extern void *Engine_LazySingletonGetter_00422CC8(void);
extern void ActorInputNeutralNotify_00A422EC(void *manager, void *mode_state,
                                              void *entry, void *packet);
extern void *Engine_LazyStrideRegistry_003B6D84(void);
extern int Engine_OnceGuard_003B4FE4(void *guard);
extern void *Engine_ForEachStrideCallback_00421EA4(
    void *out, void *callback, uint32_t stride, uint32_t count);
typedef char kiu_sa_actor_input_1[(sizeof(struct ActorInputRecord) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_input_2[(sizeof(struct ActorInputPacketView) == 0x40) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_input_3[(offsetof(struct ActorInputReceiver, records) == 0x38) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_input_4[(offsetof(struct ActorInputReceiver, head) == 0x1b8) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_input_5[(offsetof(struct ActorInputReceiver, tap_batch) == 0x1c0) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_input_6[(offsetof(struct ActorInputReceiver, current_2000) == 0x308) ? 1 : -1] __attribute__((unused));
void EncodeActorInputRecord(struct ActorInputRecord *record,
                               const struct ActorInputPacketView *packet,
                               uint32_t sequence, uint8_t control_mode);
__attribute__((noinline)) void ActorInputReceiverResetTapBatch(struct ActorTapBatch *batch,
                                        uint8_t control_mode)
{
    batch->control_mode = control_mode;
    batch->count = 0;
}
__attribute__((noinline)) void *ActorInputReceiver_Construct(void *object)
{
    uint8_t *receiver = (uint8_t *)object;
    uint32_t *sequence_slot = (uint32_t *)(uintptr_t)0x00d62a7cu;
    uint32_t *once_guard = (uint32_t *)(uintptr_t)0x00d62a78u;
    uint32_t *once_value = (uint32_t *)(uintptr_t)0x00d63518u;
    uint32_t sequence = *sequence_slot;
    *(void **)(receiver + 0x00u) =
        *(void **)(uintptr_t)0x0060a1dcu;
    *(void **)(receiver + 0x04u) = receiver;
    *(void **)(receiver + 0x08u) = receiver + 0x04u;
    *(void **)(receiver + 0x0cu) = receiver + 0x04u;
    *(void **)(receiver + 0x10u) = receiver + 0x04u;
    *(uint8_t *)(receiver + 0x14u) = 0;
    *(void **)(receiver + 0x1cu) = receiver;
    *(void **)(receiver + 0x20u) = receiver + 0x1cu;
    *(void **)(receiver + 0x24u) = receiver + 0x1cu;
    if ((*once_guard & 1u) == 0u &&
        Engine_OnceGuard_003B4FE4(once_guard) != 0) {
        sequence = *once_value;
        *once_value = *once_value + 1u;
        *sequence_slot = sequence;
    }
    *(uint32_t *)(receiver + 0x28u) = sequence;
    *(uint32_t *)(receiver + 0x2cu) =
        **(uint32_t **)(uintptr_t)0x0060a1f0u;
    *(uint32_t *)(receiver + 0x30u) = 0;
    *(uint32_t *)(receiver + 0x34u) = 0;
    if (*(void **)(uintptr_t)0x0060a1ecu == 0)
        *(void **)(uintptr_t)0x0060a1ecu =
            Engine_LazyStrideRegistry_003B6D84();
    Engine_ForEachStrideCallback_00421EA4(
        receiver + 0x38u, *(void **)(uintptr_t)0x0060a1f8u, 0x18u, 0x10u);
    *(uint32_t *)(receiver + 0x1b8u) = 0;
    *(uint32_t *)(receiver + 0x1bcu) = 0;
    *(uint8_t *)(receiver + 0x1c0u) = 0xffu;
    Engine_ForEachStrideCallback_00421EA4(
        receiver + 0x1c4u, *(void **)(uintptr_t)0x0060a1fcu, 0x14u, 0x10u);
    *(uint32_t *)(receiver + 0x304u) = 0;
    return object;
}
__attribute__((noinline)) void ActorInputReceiverEnqueuePacket(
    struct ActorInputReceiver *receiver,
    const struct ActorInputPacketView *packet,
    uint32_t control_mode)
{
    if (receiver->count > 0xfu) {
        receiver->count = receiver->count - 1u;
        receiver->head = (receiver->head + 1u) & 0xfu;
    }
    uint32_t index = (receiver->count + receiver->head) & 0xfu;
    uint32_t sequence = receiver->next_sequence++;
    EncodeActorInputRecord(&receiver->records[index], packet, sequence,
                              (uint8_t)control_mode);
    receiver->count = receiver->count + 1u;
}
__attribute__((noinline)) void ActorInputReceiverPushTapRecord(
    struct ActorInputReceiver *receiver,
    const struct ActorInputPacketView *packet, uint8_t control_mode)
{
    struct ActorTapBatch *batch = &receiver->tap_batch;
    uint32_t count;
    ActorInputReceiverResetTapBatch(batch, control_mode);
    count = batch->count;
    if (count >= 0x10u)
        return;
    struct ActorTapRecord *record = &batch->records[count];
    record->pressed = (uint8_t)(packet->pressed_flags & 1u);
    record->current = (uint8_t)(packet->current_flags & 1u);
    record->released = (uint8_t)(packet->released_flags & 1u);
    record->tap_x = (float)packet->tap_x;
    record->tap_y = (float)packet->tap_y;
    record->packet_x = packet->packet_x;
    record->packet_y = packet->packet_y;
    batch->count = count + 1u;
    receiver->current_2000 =
        (uint8_t)((packet->current_flags >> 13) & 1u);
    if (batch->control_mode == 0)
        receiver->pressed_20000 =
            (uint8_t)((packet->pressed_flags >> 17) & 1u);
    receiver->pressed_1000 =
        (uint8_t)((packet->pressed_flags >> 12) & 1u);
    receiver->pressed_40000 =
        (uint8_t)((packet->pressed_flags >> 18) & 1u);
}
__attribute__((noinline)) unsigned ActorInput_SubmitNeutralPacketIfSuspended(void *manager,
                                                    void *entry,
                                                    unsigned force)
{
    uint8_t *entry_bytes = (uint8_t *)entry;
    uint8_t *bound = *(uint8_t **)(entry_bytes + 0x1ecu);
    if (force == 0u && bound == 0) {
        void *key = Engine_DescriptorKey_004FCC08();
        uint8_t *node = *(uint8_t **)(entry_bytes + 0x1acu);
        uint8_t *candidate = entry_bytes + 0x1a8u;
        while (node != 0 && node[0x10] != 0) {
            if (*(uint32_t *)(node + 0x14u) < (uint32_t)(uintptr_t)key) {
                node = *(uint8_t **)(node + 0x0cu);
            } else {
                candidate = node;
                node = *(uint8_t **)(node + 0x08u);
            }
        }
        if (candidate == entry_bytes + 0x1a8u ||
            (uint32_t)(uintptr_t)key < *(uint32_t *)(candidate + 0x14u))
            candidate = entry_bytes + 0x1a8u;
        bound = *(uint8_t **)candidate;
        if (bound != 0 && bound != *(uint8_t **)(entry_bytes + 0x1a8u)) {
            *(uint8_t **)(bound + 0x1cu) = entry;
            *(uint8_t **)(entry_bytes + 0x1ecu) = bound;
        } else {
            bound = 0;
        }
    }
    if (force == 0u) {
        if (bound == 0)
            return 0;
        uint32_t flags = *(uint32_t *)(bound + 0x94u);
        unsigned suspended = ((flags & 0x80u) != 0u) ||
                             ((*(uint32_t *)(bound + 0x98u) & 4u) != 0u);
        *(uint32_t *)(bound + 0x94u) = flags & ~0x80u;
        if (!suspended)
            return 0;
    }
    static void **singleton_slot = (void **)(uintptr_t)0x00d6364cu;
    void *singleton = *singleton_slot;
    if (singleton == 0) {
        singleton = Engine_LazySingletonGetter_00422CC8();
        *singleton_slot = singleton;
    }
    const struct ActorInputPacketView *neutral =
        *(const struct ActorInputPacketView **)(uintptr_t)0x00a422e0u;
    unsigned control =
        *(int8_t *)((uint8_t *)singleton +
                    *(uint32_t *)(uintptr_t)0x00a422e8u) != 0;
    struct ActorInputReceiver *receiver =
        ActorInputReceiverFromEntry_00BB3A48(entry);
    ActorInputReceiverEnqueuePacket(receiver, neutral, control);
    ActorInputReceiverPushTapRecord(receiver, neutral, control);
    ActorInputNeutralNotify_00A422EC(manager, 0u, entry, (void *)neutral);
    return 1;
}
uint32_t PromoteDashBits(uint32_t mask)
{
    if ((mask & 0x800u) == 0)
        return mask;
    if ((mask & 0x1eu) == 0)
        return mask & ~0x800u;
    if ((mask & 0x04u) != 0) mask |= 0x040u;
    if ((mask & 0x02u) != 0) mask |= 0x020u;
    if ((mask & 0x08u) != 0) mask |= 0x080u;
    if ((mask & 0x10u) != 0) mask |= 0x100u;
    return mask;
}
__attribute__((noinline)) void EncodeActorInputRecord(struct ActorInputRecord *record,
                               const struct ActorInputPacketView *packet,
                               uint32_t sequence,
                               uint8_t control_mode)
{
    record->control_mode = control_mode;
    record->sequence = sequence;
    record->aim_x = packet->aim_x;
    record->aim_y = packet->aim_y;
    record->current_2000 = (uint8_t)((packet->current_flags >> 13) & 1u);
    record->pressed_2000 = (uint8_t)((packet->pressed_flags >> 13) & 1u);
    if (control_mode != 0) {
        record->dash_or_current_1000000 =
            (uint8_t)((packet->pressed_flags >> 11) & 1u);
        record->pressed_1000 =
            (uint8_t)((packet->pressed_flags >> 12) & 1u);
        record->pressed_800000 =
            (uint8_t)((packet->pressed_flags >> 23) & 1u);
    } else {
        record->dash_or_current_1000000 =
            (uint8_t)((packet->current_flags >> 24) & 1u);
    }
}
