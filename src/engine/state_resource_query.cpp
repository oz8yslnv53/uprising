// KIU jp_rev1 state-resource query wrapper at 0x005C86A4.
#include <cstdint>
extern "C" void StateResource_QueryShared_005C7414(
    std::uint32_t* result, void* input, std::uint32_t mode);
extern "C" __attribute__((noinline)) std::uint64_t
StateResource_QueryVariant1_005C86A4(void* input) {
    std::uint32_t result[2];
    StateResource_QueryShared_005C7414(result, input, 1);
    return static_cast<std::uint64_t>(result[0]) |
           (static_cast<std::uint64_t>(result[1]) << 32);
}
