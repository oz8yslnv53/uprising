// Small render-target state predicates used by the mode-0 backend.
#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B524F8(const void* state) {
    return (*static_cast<const std::uint32_t*>(state) >> 1) & 1u;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B52508(const void* state) {
    return *static_cast<const std::uint32_t*>(state) & 1u;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B52558(const void* state) {
    return (static_cast<const std::uint32_t*>(state)[1] >> 2) & 1u;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B525A4(const void* state) {
    const std::uint8_t* const bytes =
        static_cast<const std::uint8_t*>(state);
    const std::int32_t index =
        *reinterpret_cast<const std::int32_t*>(bytes + 0x678);
    return *reinterpret_cast<const std::int32_t*>(bytes + 4) == 7 &&
                   index > 2 && index < 7 &&
                   index == *reinterpret_cast<const std::int32_t*>(
                                bytes + 0x6ec)
               ? 1u
               : 0u;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B525DC(const void* state) {
    const std::uint32_t* words =
        static_cast<const std::uint32_t*>(state);
    return (words[0] & 0x801u) != 0 && words[1] - 5u <= 2u;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B527C8(const void* state) {
    return (*static_cast<const std::uint32_t*>(state) & 0x801u) != 0;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B527E0(const void* state) {
    const std::uint32_t* words =
        static_cast<const std::uint32_t*>(state);
    return (words[12] & 8u) != 0 || (words[0] & 0x4000u) != 0;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B52800(const void* state) {
    const std::uint8_t* const bytes =
        static_cast<const std::uint8_t*>(state);
    const std::int32_t threshold = 0x3f000001;
    return *reinterpret_cast<const std::int32_t*>(bytes + 0x298) <= threshold
               ? *reinterpret_cast<const std::uint32_t*>(bytes + 0x1fc)
               : 0u;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B5282C(const void* state) {
    return *static_cast<const std::uint32_t*>(state) & 1u;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00B52838(const void* state) {
    const std::uint8_t* bytes =
        static_cast<const std::uint8_t*>(state);
    return *reinterpret_cast<const std::uint32_t*>(bytes + 0xcb8) != 0 ||
           *reinterpret_cast<const std::uint32_t*>(bytes + 0xefc) != 0 ||
           (*reinterpret_cast<const std::uint32_t*>(bytes) & 0x400u) != 0;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_00A0E420(const void* state) {
    const std::uint32_t value =
        *static_cast<const std::uint32_t*>(state);
    return (value & 0x801u) == 0 ? (value >> 11) & 1u
                                : (value >> 30) & 1u;
}
