#include <stdint.h>
extern void StateFramework_ReleaseOwnedField_00421DEC(void *value);
__attribute__((noinline)) void *StateFramework_Record50_ClearOwnedField_006FB340(void *object)
{
    StateFramework_ReleaseOwnedField_00421DEC(
        *(void **)((uint8_t *)object + 0x0c));
    *(void **)((uint8_t *)object + 0x0c) = 0;
    return object;
}
