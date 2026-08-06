#include <stdint.h>
extern void *FUN_0039FA98(void);
__attribute__((noinline)) void Singleton_FieldD8Store_003283A0(void *value)
{
    uint8_t *object = (uint8_t *)FUN_0039FA98();
    *(void **)(object + 0xd8) = value;
}
