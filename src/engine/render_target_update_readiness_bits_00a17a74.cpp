// KIU jp_rev1 address reconstructed in this file: 0x00A17A74.
#include <cstdint>
extern "C" void* Engine_LazyStateManager_00475D18();
extern "C" int FUN_004C37BC(void* manager, int mode, int query_kind);
// Shared retail slot at 00D635B8; callers give it incompatible roles.
extern "C" void* DAT_00D635B8;
extern "C" __attribute__((noinline)) void RenderTarget_UpdateReadinessBits_00A17A74(
    std::uint32_t* target_flags) {
    void* manager = DAT_00D635B8;
    if (manager == 0) {
        manager = Engine_LazyStateManager_00475D18();
        DAT_00D635B8 = manager;
    }
    if (FUN_004C37BC(manager, 1, 1) != 0)
        *target_flags = (*target_flags & ~1u) | 2u;
    else
        *target_flags &= ~2u;
}
