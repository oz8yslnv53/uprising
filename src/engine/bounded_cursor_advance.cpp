#include <cstdint>
// Confirmed three-word layout used by 0013062C.
struct BoundedCursorView {
    std::uint32_t unknown_00;
    std::uint32_t limit_04;
    std::uint32_t cursor_08;
};
// Reconstructed JP Rev 1: 0x0013062C.
extern "C" __attribute__((noinline)) bool Engine_AdvanceBoundedCursor_0013062C(
    void* raw_cursor, std::uint32_t base, std::uint32_t amount) {
    BoundedCursorView* cursor = static_cast<BoundedCursorView*>(raw_cursor);
    const std::uint32_t next = cursor->cursor_08 - base + amount;
    if (next > cursor->limit_04)
        return false;
    cursor->cursor_08 = next;
    return true;
}
