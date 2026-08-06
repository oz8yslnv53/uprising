#include <stdint.h>
extern "C" void *FontTextManager_Get_003532F0(void);
extern "C" void Engine_MarkSharedStateDirty_004988B0(
    void *manager, uint32_t request);
extern "C" __attribute__((noinline)) void *FontTextManager_EnsureOwnerReady_00A0E45C(void *object) {
    uint8_t *bytes = static_cast<uint8_t *>(object);
    static volatile void **const manager_cache =
        (volatile void **)0x00d6366cu;
    if (*reinterpret_cast<int32_t *>(bytes + 0x74c) != -2) {
        if (*manager_cache == 0)
            *manager_cache = FontTextManager_Get_003532F0();
        Engine_MarkSharedStateDirty_004988B0(
            const_cast<void *>(*manager_cache),
            *reinterpret_cast<uint32_t *>(bytes + 0x74c));
        *reinterpret_cast<int32_t *>(bytes + 0x74c) = -2;
    }
    return object;
}
