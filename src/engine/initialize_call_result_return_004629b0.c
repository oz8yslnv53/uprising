#include <stdint.h>
extern void *StartupPlatform_PrepareModeChange_00414E6C(void);
extern void *FUN_0048AA58(void *first, uint32_t second);
extern void StartupPlatform_FinishModeChange_004150A0(void *result);
void *Engine_InitializeCallResultReturn_004629B0(void *first,
                                                  uint32_t second)
    __attribute__((noinline));
__attribute__((noinline)) void *Engine_InitializeCallResultReturn_004629B0(void *first,
                                                  uint32_t second)
{
    void *result;
    StartupPlatform_PrepareModeChange_00414E6C();
    result = FUN_0048AA58(first, second);
    StartupPlatform_FinishModeChange_004150A0(result);
    return result;
}
