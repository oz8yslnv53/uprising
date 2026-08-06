#include <stdint.h>
extern void FUN_0014FA38(void *record);
__attribute__((noinline)) void FUN_00151718(uint8_t *object)
{
    if (object[0x14] != 0) {
        FUN_0014FA38(object + 0x54);
        object[0x14] = 0;
    }
}
