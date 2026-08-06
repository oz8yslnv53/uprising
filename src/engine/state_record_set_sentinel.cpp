// KIU jp_rev1 generic state-record finalization leaf at 0x0031E96C.
#include <cstdint>
extern "C" __attribute__((noinline)) void StateRecord_SetSentinelMinusOne_0031E96C(void* record) {
    static_cast<std::uint32_t*>(record)[2] = 0xffffffffu;
}
