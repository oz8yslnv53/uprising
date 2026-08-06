#include <stdint.h>
extern int FUN_004EADCC(void *record, int enabled);
__attribute__((noinline)) int CachedRecord_Disable_004802EC(void *object)
{
    FUN_004EADCC(*(void **)((uint8_t *)object + 0x30), 0);
    return 0;
}
