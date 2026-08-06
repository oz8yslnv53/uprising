#include <stdint.h>
extern void StateRecord_AtomicReset_0036A058(void *record);
__attribute__((noinline)) void FUN_0014D5F0(uint8_t *object)
{
    if (object[0] == 0) {
        StateRecord_AtomicReset_0036A058(object + 0x34);
        object[0] = 1;
    }
}
