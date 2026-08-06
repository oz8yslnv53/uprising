// 0012917C: store the invalid/sentinel word at the supplied record address.
#include <stdint.h>
__attribute__((noinline)) void Record_StoreMinusOne_0012917C(void *record)
{
    *(volatile uint32_t *)record = 0xffffffffu;
}
