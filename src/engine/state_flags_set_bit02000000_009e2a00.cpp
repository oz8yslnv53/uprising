// KIU jp_rev1: set or clear the runtime-state 0x02000000 flag.
#include <cstdint>
extern "C" __attribute__((noinline)) void StateFlags_SetBit02000000_009E2A00(
    std::uint32_t* word, std::int32_t enabled) {
    if (enabled != 0)
        *word |= 0x02000000u;
    else
        *word &= ~0x02000000u;
}
