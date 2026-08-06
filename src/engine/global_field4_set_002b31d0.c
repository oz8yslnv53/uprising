#include <stdint.h>
struct GlobalField4BackingRecordView {
    uint32_t mode_000;
    uint32_t mutable_field_004;
    uint32_t lookup_pairs_008[15][2];
};
typedef char kiu_sa_global_field4_backing_record_1[
    (sizeof(struct GlobalField4BackingRecordView) == 0x80) ? 1 : -1] __attribute__((unused));
extern struct GlobalField4BackingRecordView DAT_00D4F020;
__attribute__((noinline)) void Engine_GlobalField4Set_002B31D0(uint32_t value) {
    DAT_00D4F020.mutable_field_004 = value;
}
