// KIU jp_rev1 atomic state-record reset at 0x0036A058.
#include <cstdint>
extern "C" void AtomicWord_StoreOne_0010C9D0(void* word);
extern "C" __attribute__((noinline)) void StateRecord_AtomicReset_0036A058(void* record) {
    std::uint32_t* words = static_cast<std::uint32_t*>(record);
    AtomicWord_StoreOne_0010C9D0(words);
    words[1] = 0;
    words[2] = 0;
}
