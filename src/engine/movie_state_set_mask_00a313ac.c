#include <stdint.h>
extern void FUN_009F85B4(uint32_t *state, int mode, int row);
extern void FUN_00A001B8(uint32_t *state);
extern void *Engine_LazySingletonGetter_0054EFA8(void);
extern void StatusEffect_ReleaseSelected(void *target, int selector);
__attribute__((noinline)) static void
MovieState_ApplyMaskRows_00A0001C(uint8_t *state, uint8_t *base,
                                  unsigned int row_index,
                                  unsigned int mode)
{
    uint32_t mask;
    uint32_t changed = 0;
    uint32_t completed = 0;
    uint32_t first_changed = 0;
    unsigned int index;
    if (mode > 2)
        return;
    mask = 0x1000u << mode;
    for (index = 0; index < 6; ++index) {
        int row = *(int8_t *)(state + 0x60 + index);
        uint32_t *record;
        uint32_t value;
        if (row < 0)
            continue;
        record = (uint32_t *)(state + row * 0x18);
        value = record[0x68 / 4];
        if (index == row_index) {
            if ((value & mask) == 0) {
                value |= mask;
                record[0x68 / 4] = value;
                changed = 1;
                if (index == 0)
                    first_changed = 1;
                if ((value & 0x7000u) == 0x7000u) {
                    completed = 1;
                    if (row_index < 6) {
                        *(uint32_t *)state =
                            (*(uint32_t *)state & ~0x2000u) | 0x4000u;
                        *(uint32_t *)(base + 0x2044) = row_index;
                        *(float *)(base + 0x2040) = 0.0f;
                        {
                            static void **const cache =
                                (void **)(uintptr_t)0x00a001b4u;
                            void *target = *cache;
                            if (target == 0) {
                                target = Engine_LazySingletonGetter_0054EFA8();
                                *cache = target;
                            }
                            StatusEffect_ReleaseSelected(target, 2);
                        }
                    }
                    *(uint32_t *)state |= 0x70000000u;
                }
            }
        } else if ((value & mask) != 0) {
            record[0x68 / 4] = value & ~mask;
            changed = 1;
            if (index == 0)
                first_changed = 1;
        }
    }
    if (changed != 0 && *(uint32_t *)(base + 0x1f44) == 2 &&
        completed == 0)
        FUN_00A001B8((uint32_t *)state);
    if (first_changed != 0 && *(int8_t *)(state + 0x60) >= 0) {
        void *linked = *(void **)(state + 0x298);
        int row = *(int8_t *)(state + 0x60);
        if (linked != 0 && row >= 0) {
            uint32_t value =
                (*(uint32_t *)(state + row * 0x18 + 0x68) & 0x7fff) >> 12;
            int32_t derived = (int32_t)(value & 1u) -
                               (int32_t)((value >> 1) & 1u) -
                               (int32_t)((value >> 2) & 1u);
            *(uint32_t *)((uint8_t *)linked + 0x79c) = derived;
        }
    }
}
__attribute__((noinline)) void
MovieState_SetMask_00A313AC(void *owner, unsigned int mode,
                            int callback_mode, unsigned int row_index)
{
    uint8_t *owner_bytes = (uint8_t *)owner;
    uint8_t *state = *(uint8_t **)(owner_bytes + 0x140);
    if (state == 0)
        return;
    FUN_009F85B4((uint32_t *)(state + 0x1ef0), callback_mode, (int)mode);
    state = *(uint8_t **)(owner_bytes + 0x140);
    MovieState_ApplyMaskRows_00A0001C(state + 0x1ef0, state, row_index, mode);
}
