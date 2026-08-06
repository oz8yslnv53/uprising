#include <cstdint>
extern "C" std::uint32_t IntrusiveList_Count_00473DB8(void*);
namespace {
struct MemberCallback {
    std::uint32_t target;
    std::int32_t adjustment;
};
typedef char kiu_sa_member_callback_group_1[(sizeof(MemberCallback) == 8) ? 1 : -1] __attribute__((unused));
}  // namespace
extern "C" __attribute__((noinline)) void MemberCallbackGroup_InvokeTen_0064C860(void* group) {
    std::uint8_t* base = static_cast<std::uint8_t*>(group);
    MemberCallback* callbacks = reinterpret_cast<MemberCallback*>(base + 0x27b74);
    for (int i = 0; i < 10; ++i) {
        const MemberCallback callback = callbacks[i];
        void* object = base + (callback.adjustment >> 1);
        std::uintptr_t target = callback.target;
        if ((callback.adjustment & 1) != 0) {
            target += *reinterpret_cast<std::uintptr_t*>(object);
            target = *reinterpret_cast<std::uintptr_t*>(target);
        }
        reinterpret_cast<void (*)(void*)>(target)(object);
    }
}
extern "C" __attribute__((noinline)) bool CallbackGroup_HasQueuedEntries_0064DDA8(void* group) {
    return IntrusiveList_Count_00473DB8(
               static_cast<std::uint8_t*>(group) + 0x60) != 0;
}
