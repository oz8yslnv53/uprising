#include <cstdint>
__attribute__((noinline)) void RenderState_ClearPendingRecords_00A1767C(void *state) {
    std::uint32_t* words = static_cast<std::uint32_t*>(state);
    words[0xcb8 / sizeof(*words)] = 0;
    words[0xefc / sizeof(*words)] = 0;
}
