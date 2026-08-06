#include <stdint.h>
extern void FUN_0076f15c(
    void *object, uint32_t selector, const void *data, int mode,
    uint32_t value);
__attribute__((noinline)) void FUN_00a9d468(const uint32_t *selector, void *object,
                 const uint32_t *value)
{
    uint32_t selector_value = *selector;
    uint32_t selected = value == 0 ? 0xffffffffu : *value;
    FUN_0076f15c(object, selector_value, (const void *)0x00dc2588u, 1, selected);
}
