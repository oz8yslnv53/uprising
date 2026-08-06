// KIU jp_rev1 shared status-mode predicate at 0x00588E84.
#include <cstdint>
extern "C" void* Engine_LazySingletonGetter_0054EFA8(void);
extern "C" void* Engine_LazySingletonGetter_0049BED0(void);
extern "C" void* g_StatusSelectorSingleton_00D63578;
extern "C" void* g_StatusRegistrySingleton_00D63558;
extern "C" __attribute__((noinline)) bool EngineStatusModeIsType5(void) {
    void* selector = g_StatusSelectorSingleton_00D63578;
    if (selector == 0) {
        selector = Engine_LazySingletonGetter_0054EFA8();
        g_StatusSelectorSingleton_00D63578 = selector;
    }
    std::uint8_t* selector_bytes = static_cast<std::uint8_t*>(selector) + 0x1200;
    if (selector_bytes[0x3C] == 0 || selector_bytes[0x3D] == 0)
        return 0;
    void* registry = g_StatusRegistrySingleton_00D63558;
    if (registry == 0) {
        registry = Engine_LazySingletonGetter_0049BED0();
        g_StatusRegistrySingleton_00D63558 = registry;
    }
    void* record = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(registry) + 0xB4);
    if (record == 0)
        return 0;
    if (registry == 0) {
        registry = Engine_LazySingletonGetter_0049BED0();
        g_StatusRegistrySingleton_00D63558 = registry;
    }
    record = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(registry) + 0xB4);
    return *(static_cast<std::uint8_t*>(record) + 0x14) == 5;
}
