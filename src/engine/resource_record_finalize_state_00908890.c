#include <stdint.h>
extern void ResourceRecord_SetState_0090832C(
    void *subrecord, uint32_t state);
__attribute__((noinline)) void ResourceRecord_FinalizeState_00908890(
    uint8_t *record)
{
    if (*(uint8_t *)(record + 0x90U) != 4U) {
        void *subrecord = *(void **)(record + 0x134U);
        if (subrecord != 0) {
            uint32_t state = *(uint8_t *)(record + 0xc9U);
            if (state == 0)
                state = 1;
            ResourceRecord_SetState_0090832C(subrecord, state);
        }
        *(uint8_t *)(record + 0x90U) = 4;
    }
    *(uint8_t *)(record + 0xc5U) = 0;
}
