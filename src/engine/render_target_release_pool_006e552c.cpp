// KIU jp_rev1 address reconstructed in this file: 0x006E552C.
#include <cstdint>
extern "C" void* Engine_LazySingletonGetter_003FD6E0();
extern "C" int EffectEvent_ReleasePool(void*, std::uint32_t, std::uint32_t);
extern "C" __attribute__((noinline)) void FUN_006E552C(void* target, std::uint32_t channel) {
    std::int32_t*const entry = reinterpret_cast<std::int32_t*>(
        static_cast<std::uint8_t*>(target) + 0x1ecccu + channel * 4u);
    if (*entry == -1)
        return;
    void**const dispatcher_slot = reinterpret_cast<void**>(0x00d63854u);
    if (*dispatcher_slot == 0)
        *dispatcher_slot = Engine_LazySingletonGetter_003FD6E0();
    EffectEvent_ReleasePool(*dispatcher_slot,
                            static_cast<std::uint32_t>(*entry), 0);
}
