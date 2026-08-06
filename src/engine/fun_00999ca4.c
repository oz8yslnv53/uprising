#include <stdint.h>
typedef void (*RecordRelease)(void *record);
__attribute__((noinline)) void FUN_00999CA4(unsigned char *object, void *unused)
{
    unsigned char *record;
    void **vtable;
    (void)unused;
    record = *(unsigned char **)(object + 4);
    if (record != 0 && *(uint32_t *)(object + 8) != 0) {
        vtable = *(void ***)record;
        ((RecordRelease)vtable[4])(record);
    }
    *(uint32_t *)(object + 4) = 0;
    *(uint32_t *)(object + 8) = 0;
    *(uint32_t *)(object + 0x0c) = 0;
    *(uint32_t *)(object + 0x10) = 0;
    *(unsigned char *)(object + 0x14) = 0;
}
