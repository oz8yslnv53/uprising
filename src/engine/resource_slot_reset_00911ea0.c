#include <stdint.h>
extern void VirtualCallSlot2CIfNonNull_00369EF4(void *object);
__attribute__((noinline)) void ResourceSlot_Reset_00911EA0(uint8_t *slot) {
    uintptr_t object = *(uintptr_t *)(slot + 0x18);
    if ((object & ~(uintptr_t)1) != 0) {
        VirtualCallSlot2CIfNonNull_00369EF4((void *)(object & ~(uintptr_t)1));
        *(uintptr_t *)(slot + 0x18) = 0;
    }
    slot[0x2c] = 0;
}
