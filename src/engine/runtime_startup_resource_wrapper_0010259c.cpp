#include <stdint.h>
extern "C" void StartupPlatform_PrepareModeChange_00414E6C(void);
extern "C" void* CtrSvc_SharedFontIpc_00108A4C(void* context, void* descriptor);
extern "C" void StartupPlatform_FinishModeChange_004150A0(void);
extern "C" __attribute__((noinline)) void*
Runtime_StartupResourceWrapper_0010259C(void* context, void* descriptor) {
    void* result;
    StartupPlatform_PrepareModeChange_00414E6C();
    result = CtrSvc_SharedFontIpc_00108A4C(context, descriptor);
    StartupPlatform_FinishModeChange_004150A0();
    return result;
}
