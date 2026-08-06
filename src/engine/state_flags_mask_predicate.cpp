// KIU jp_rev1 state-flag mask predicate at 0x0011C330.
#include <cstdint>
extern "C" __attribute__((noinline)) std::uint8_t Engine_StateFlags_HasMask4B_0011C330(void* state) {
    const std::uint8_t flags = *reinterpret_cast<const std::uint8_t*>(
        static_cast<const std::uint8_t*>(state) + 0x80);
    return (flags & 0x4b) != 0 ? 1 : 0;
}
