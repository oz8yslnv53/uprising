#include <cstdint>
extern "C" int Engine_AdvanceBoundedCursor_0013062C(
    void* attached, void* callback_result, std::uint32_t flags);
// Only the two virtual slots and +0x50/+0x54 tail are established here.
struct RecordApplyFlagsView;
struct RecordApplyFlagsVtableView {
    std::uint8_t unknown_00[0x1c];
    void* (*get_callback_result)(RecordApplyFlagsView* record);
    void (*before_apply)(RecordApplyFlagsView* record);
};
struct RecordApplyFlagsView {
    RecordApplyFlagsVtableView* vtable;
    std::uint8_t unknown_04[0x4c];
    void* attached_50;
    std::uint32_t flags_54;
};
// Reconstructed JP Rev 1: 0x0046352C.
extern "C" __attribute__((noinline)) void Engine_RecordApplyFlags_0046352C(
    void* raw_record, std::uint32_t flags) {
    RecordApplyFlagsView* record = static_cast<RecordApplyFlagsView*>(raw_record);
    record->vtable->before_apply(record);
    if (record->attached_50 != 0 &&
        Engine_AdvanceBoundedCursor_0013062C(
            record->attached_50,
            record->vtable->get_callback_result(record), flags) == 0)
        return;
    record->flags_54 = flags;
}
