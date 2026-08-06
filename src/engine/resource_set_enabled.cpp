// KIU jp_rev1 resource enabled-state setter at 0x00203168.
#include <cstdint>
extern "C" __attribute__((noinline)) void Resource_SetEnabled_00203168(void* resource, int enabled) {
    const std::uint32_t* resource_words = static_cast<const std::uint32_t*>(resource);
    const std::uint32_t child = resource_words[2];
    if (child == 0)
        return;
    const std::int32_t* child_words = reinterpret_cast<const std::int32_t*>(
        static_cast<std::uintptr_t>(child));
    if (child_words[0x50 / 4] <= 0 || child_words[0x40 / 4] == 0)
        return;
    std::uint8_t* flags = reinterpret_cast<std::uint8_t*>(
        static_cast<std::uintptr_t>(child_words[0x40 / 4]));
    flags[0x365] = static_cast<std::uint8_t>(enabled);
}
