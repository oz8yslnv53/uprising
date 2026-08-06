// KIU jp_rev1 state-container predicate at 0x001B4C28.
#include <cstdint>
extern "C" __attribute__((noinline)) bool StateContainer_IsUninitialized_001B4C28(void* state) {
    const std::uint32_t* words = static_cast<const std::uint32_t*>(state);
    return words[0x18 / sizeof(*words)] == 0;
}
