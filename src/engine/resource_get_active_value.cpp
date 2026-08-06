// KIU jp_rev1 active resource-value accessor at 0x00203148.
#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t Resource_GetActiveValue_00203148(void* object) {
    const std::uint32_t* words = static_cast<const std::uint32_t*>(object);
    const std::uint32_t child = words[2];
    if (child == 0)
        return 0;
    const std::uint32_t* child_words = reinterpret_cast<const std::uint32_t*>(
        static_cast<std::uintptr_t>(child));
    return static_cast<std::int32_t>(child_words[0x50 / 4]) > 0
               ? child_words[0x40 / 4]
               : 0;
}
