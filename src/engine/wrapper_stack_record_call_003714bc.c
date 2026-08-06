#include <stdint.h>
extern uint32_t FUN_00394750(void *first, void *second, uint32_t *record);
__attribute__((noinline)) uint32_t Wrapper_StackRecordCall_003714BC(void *first, void *second,
                                          uint32_t ignored,
                                          uint32_t value)
{
    uint32_t record[1];
    (void)ignored;
    (void)value;
    return FUN_00394750(first, second, record);
}
