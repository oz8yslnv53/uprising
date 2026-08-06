extern "C" bool MenuRuntime_IsPhase1_0028AC18(void *runtime);
extern "C" bool MenuRuntime_IsPhase2_0028AC44(void *runtime);
extern "C" bool MenuRuntime_IsPhase3_001D5140(void *runtime);
extern "C" bool MenuRuntime_IsPhase4_0023F4C4(void *runtime);
extern "C" bool MenuRuntime_IsPhase5_0023F504(void *runtime);
extern "C" bool MenuRuntime_IsPhase6_0023F524(void *runtime);
extern "C" bool MenuRuntime_IsPhase7_0023F4E4(void *runtime);
extern "C" bool MenuRuntime_IsPhase8_0023F544(void *runtime);
extern "C" __attribute__((noinline)) bool Engine_MenuRuntime_IsAnyPhase_0010B6E4(void *runtime)
{
    return MenuRuntime_IsPhase1_0028AC18(runtime) ||
           MenuRuntime_IsPhase2_0028AC44(runtime) ||
           MenuRuntime_IsPhase3_001D5140(runtime) ||
           MenuRuntime_IsPhase4_0023F4C4(runtime) ||
           MenuRuntime_IsPhase5_0023F504(runtime) ||
           MenuRuntime_IsPhase6_0023F524(runtime) ||
           MenuRuntime_IsPhase7_0023F4E4(runtime) ||
           MenuRuntime_IsPhase8_0023F544(runtime);
}
