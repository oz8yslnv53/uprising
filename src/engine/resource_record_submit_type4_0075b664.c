#include <stdint.h>
extern void FUN_00601F6C(uint32_t arg0, uint32_t arg1, uint32_t arg2,
                        uint32_t type);
__attribute__((noinline)) uint32_t ResourceRecord_SubmitType4_0075B664(void *ignored, void *object)
{
    uint32_t *args = *(uint32_t **)((uint8_t *)object + 0x20);
    (void)ignored;
    FUN_00601F6C(args[0], args[1], args[2], 4u);
    return 0;
}
