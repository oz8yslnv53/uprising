#include <stdint.h>
extern void FUN_006C8798(void);
void Record_RefreshAndCopy_007A0B2C(void *record) __attribute__((noinline));
__attribute__((noinline)) void Record_RefreshAndCopy_007A0B2C(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    FUN_006C8798();
    *(uint32_t *)(bytes + 0x68) = *(uint32_t *)(bytes + 0x2c);
}
