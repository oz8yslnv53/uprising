#include <stdint.h>
typedef uint32_t (*ReadValue)(void *object);
extern int FUN_004d2330(uint32_t key, int object);
__attribute__((noinline)) void FUN_00a3f230(void *object)
{
    void *provider = *(void **)((uint8_t *)object + 0x40);
    if (provider != 0) {
        ReadValue read_value = (ReadValue)(*(void ***)provider)[0x1c / sizeof(void *)];
        *(uint32_t *)((uint8_t *)object + 0x34) = ~read_value(provider);
    }
    *(uint32_t *)((uint8_t *)object + 0x38) =
        (uint32_t)FUN_004d2330(
            *(uint32_t *)((uint8_t *)object + 0x3c),
            (int)(uintptr_t)object);
}
