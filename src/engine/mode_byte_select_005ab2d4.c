#include <stdint.h>
__attribute__((noinline)) int Engine_ModeByteSelect_005AB2D4(
    uint8_t *record, int mode)
{
    if (mode == 2)
        return (int8_t)record[0x230u];
    if (mode == 3)
        return (int8_t)record[0x231u];
    if (mode == 4)
        return (int8_t)record[0x232u];
    if (mode == 5)
        return (int8_t)record[0x233u];
    return 0;
}
