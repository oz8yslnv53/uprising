#include <cstdint>
extern "C" void* g_StatusAdmissionContext_00D63578;
extern "C" void* Engine_LazySingletonGetter_0054EFA8();
extern "C" std::uint32_t StatusCondition_AdmissionCode_004868EC(
    void* context, void* object);
extern "C" __attribute__((noinline)) bool Engine_StatusAdmissionMask_004EAF58(void* object) {
    if (g_StatusAdmissionContext_00D63578 == 0)
        g_StatusAdmissionContext_00D63578 =
            Engine_LazySingletonGetter_0054EFA8();
    return (StatusCondition_AdmissionCode_004868EC(
                g_StatusAdmissionContext_00D63578, object) & 0x12u) != 0;
}
