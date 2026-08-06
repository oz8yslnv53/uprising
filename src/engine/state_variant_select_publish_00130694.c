#include <stdint.h>
extern void StateVariant_Select_0012CCDC(void *storage, int mode);
extern void StateVariant_SelectAndPublish_00130694(void *storage, int mode);
__attribute__((noinline)) void FUN_0013068C(void *owner, int mode)
{
    StateVariant_SelectAndPublish_00130694(
        *(void **)((uint8_t *)owner + 0x68), mode);
}
__attribute__((noinline)) void StateVariant_SelectAndPublish_00130694(
    void *storage, int mode)
{
    uint8_t *bytes = (uint8_t *)storage;
    uint32_t selected;
    StateVariant_Select_0012CCDC(storage, mode);
    selected = *(uint32_t *)(bytes + 0x80);
    *(uint32_t *)(*(uint32_t **)(bytes + 0x190) + 1) = selected;
}
