#include <stdint.h>
__attribute__((noinline)) void Record_SelfLinkInitialize_00258570(void *record)
{
    uint32_t address = (uint32_t)(uintptr_t)record;
    uint32_t *words = (uint32_t *)record;
    words[2] = 0;
    words[0] = address;
    words[3] = 0;
    words[4] = 0;
    words[5] = 0;
    words[6] = 0;
    words[1] = address;
}
