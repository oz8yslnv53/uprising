#include <cstdint>
#include "engine_common_views.h"
extern "C" void Engine_Free_00421DEC(void* allocation);
extern "C" std::uint32_t ResourceTree_GetPendingEntry_002F30F0(void* owner);
extern "C" std::uint32_t ResourceTree_CheckEntry_0022CF04(void* object,
                                                            void* entry);
extern "C" void* ResourceTree_ResolveCurrentEntry_002A6268(void* owner);
extern "C" void ResourceTree_SetEntryActive_0025EE3C(
    void* entry, int active);
extern "C" void EngineResource_ActivatePendingStates_0025E9D8(void* resource);
extern "C" void* Engine_SharedResourceSingleton_00422D20();
extern "C" void EngineResource_SetRefreshFlags_003EE0D8(
    void* resource, std::uint8_t enabled);
extern "C" void* StateResourceManager_Shutdown_004A9C8C(void* manager);
extern "C" void VideoRenderBuffers_Destroy_00461BA0();
extern void* DAT_0021B6A8;
extern void* DAT_00D49494;
extern StateResourceGlobalSlotView DAT_00D49450;
extern std::uint32_t DAT_00DB7318[7];
extern "C" __attribute__((noinline)) std::uint32_t
VideoResource_ActivatePending_0021B620(
    void* object) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    ResourceTree_GetPendingEntry_002F30F0(
        *reinterpret_cast<void**>(bytes + 0x30));
    const std::uint32_t entry = ResourceTree_CheckEntry_0022CF04(
        bytes + 0x34,
        bytes + 0x34 + *static_cast<std::uint8_t*>(bytes + 0x60) * 0x2c +
            0x18);
    if (entry != 0) {
        void* current = ResourceTree_ResolveCurrentEntry_002A6268(
            *reinterpret_cast<void**>(bytes + 0x30));
        void* resource = *reinterpret_cast<void**>(
            static_cast<std::uint8_t*>(current) + 0x20);
        ResourceTree_SetEntryActive_0025EE3C(
            static_cast<std::uint8_t*>(resource) + 8, 1);
        EngineResource_ActivatePendingStates_0025E9D8(
            *reinterpret_cast<void**>(
                static_cast<std::uint8_t*>(current) + 0x20));
        VideoRenderBuffers_Destroy_00461BA0();
        if (DAT_0021B6A8 == 0)
            DAT_0021B6A8 = Engine_SharedResourceSingleton_00422D20();
        EngineResource_SetRefreshFlags_003EE0D8(
            *reinterpret_cast<void**>(
                static_cast<std::uint8_t*>(DAT_0021B6A8) + 0x48),
            0);
    }
    return 0;
}
extern "C" __attribute__((noinline)) void EngineResource_SetRefreshFlags_003EE0D8(
    void* resource, std::uint8_t enabled) {
    std::uint8_t* inner = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(resource) + 8);
    if (inner != 0 && *reinterpret_cast<int*>(inner + 0x50) > 0) {
        volatile std::uint8_t* target = *reinterpret_cast<std::uint8_t**>(inner + 0x40);
        if (target != 0) {
            target[0x364] = enabled;
            target[0x365] = enabled;
        }
    }
}
extern "C" __attribute__((noinline)) void VideoRenderBuffers_Destroy_00461BA0() {
    void** buffers = static_cast<void**>(DAT_00D49494);
    if (buffers != 0) {
        Engine_Free_00421DEC(buffers[0]);
        buffers[0] = 0;
        Engine_Free_00421DEC(buffers[1]);
        buffers[1] = 0;
        Engine_Free_00421DEC(buffers);
    }
    DAT_00D49494 = 0;
}
extern "C" __attribute__((noinline)) void StateResourceManager_Destroy_00486C14() {
    StateResourceGlobalSlotView* globals = &DAT_00D49450;
    if (globals->manager_000 != 0) {
        Engine_Free_00421DEC(
            StateResourceManager_Shutdown_004A9C8C(globals->manager_000));
        globals->manager_000 = 0;
        DAT_00DB7318[0] = 0;
        DAT_00DB7318[1] = 0;
        DAT_00DB7318[2] = 0;
        DAT_00DB7318[3] = 0;
        DAT_00DB7318[4] = 0;
        DAT_00DB7318[5] = 0;
        DAT_00DB7318[6] = 0;
    }
}
