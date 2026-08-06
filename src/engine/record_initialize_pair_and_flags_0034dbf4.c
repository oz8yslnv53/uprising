#include <stdint.h>
__attribute__((noinline)) void Record_InitializePairAndFlags_0034DBF4(void *object)
{
    void *base = (void *)(uintptr_t)0x00D23064u;
    void **words = (void **)object;
    words[0] = base;
    words[1] = (uint8_t *)base + 0x20;
    ((uint8_t *)object)[8] = 0u;
    ((uint8_t *)object)[9] = 0u;
}
