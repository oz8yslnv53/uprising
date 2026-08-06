#include <stdint.h>
extern void FUN_003084A0(void *object, void *arg1, void *arg3);
__attribute__((noinline)) void FUN_002C9C3C(
    void *object, void *arg1, void *value, void *arg3)
{
    FUN_003084A0(object, arg1, arg3);
    *(void **)((uint8_t *)object + 0x30u) = value;
}
