#ifndef ACTOR_TAP_RECORDS_H
#define ACTOR_TAP_RECORDS_H
#include <stddef.h>
#include <stdint.h>
struct ActorTapRecord {
    uint8_t pressed;
    uint8_t current;
    uint8_t released;
    uint8_t reserved;
    float tap_x;
    float tap_y;
    float packet_x;
    float packet_y;
};
struct ActorTapBatch {
    uint8_t control_mode;
    uint8_t reserved_01[3];
    struct ActorTapRecord records[16];
    uint32_t count;
};
typedef char kiu_sa_actor_tap_records_1[(sizeof(struct ActorTapRecord) == 0x14) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_tap_records_2[(offsetof(struct ActorTapBatch, records) == 0x04) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_actor_tap_records_3[(offsetof(struct ActorTapBatch, count) == 0x144) ? 1 : -1] __attribute__((unused));
#endif  