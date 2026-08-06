#include <stdint.h>
extern int FUN_00320404(void *object, int mode, float value);
__attribute__((noinline)) int Resource_RefreshCallThenZero_002EB8DC(void *object, int unused,
                                           int mode, void *record)
{
    float value = *(float *)((uint8_t *)record + 0xCu);
    (void)unused;
    FUN_00320404(object, mode, value);
    return 0;
}
