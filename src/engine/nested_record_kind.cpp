// KIU jp_rev1 nested-record signed-kind accessor at 0x0051B7A0.
#include <cstdint>
extern "C" __attribute__((noinline)) int
NestedRecord_GetSignedKind_0051B7A0(void* object) {
    void* nested = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(object) + 0xF8);
    if (nested == 0)
        return 0;
    return *reinterpret_cast<const std::int8_t*>(
        static_cast<const std::uint8_t*>(nested) + 0x04);
}
