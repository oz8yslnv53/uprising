#include <stdint.h>
extern void ResourceState_ReleaseC_003523EC(int mode, void *value);
extern void ResourceState_ReleaseB_0051E3DC(int mode, void *value);
extern void ResourceState_ReleaseA_00352210(int mode, void *value);
__attribute__((noinline)) void ResourceState_ReleaseReferences_00918314(
    uint8_t *state) {
    if (*(uintptr_t *)(state + 0x0c) != 0) {
        ResourceState_ReleaseC_003523EC(1, state + 0x0c);
    }
    if (*(uintptr_t *)(state + 0x08) != 0) {
        ResourceState_ReleaseB_0051E3DC(1, state + 0x08);
    }
    if (*(uintptr_t *)(state + 0x04) != 0) {
        ResourceState_ReleaseA_00352210(1, state + 0x04);
    }
    *(uint32_t *)(state + 0x0c) = 0;
    *(uint32_t *)(state + 0x08) = 0;
    *(uint32_t *)(state + 0x04) = 0;
}
