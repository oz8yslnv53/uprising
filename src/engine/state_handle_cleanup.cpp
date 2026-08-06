#include <cstdint>
extern "C" void* Engine_StateDefault_004EE6EC(void);
extern "C" void StateSelection_FindLowerBound(
    std::uint32_t out_descriptor[3], void* selection, std::uint32_t mode);
extern "C" void StateHandle_ReleasePayload(
    std::uint32_t handle[2], const std::uint32_t descriptor[3]);
extern "C" int StateHandle_IsLive(const std::uint32_t handle[2]);
extern "C" void StateHandle_Clear(std::uint32_t handle[2]);
extern "C" void StatePayload_Release(const std::uint32_t descriptor[3],
                                      float unused_frame);
extern "C" void StatePayload_Finalize(const std::uint32_t descriptor[3]);
extern "C" __attribute__((noinline)) void Engine_StateHandle_ClearIfPresent(
    void* unused, void* selection) {
    (void)unused;
    if (selection == 0) {
        std::uint8_t* defaults = reinterpret_cast<std::uint8_t*>(
            Engine_StateDefault_004EE6EC());
        selection = *reinterpret_cast<void**>(defaults + 0x24);
        if (selection == 0)
            return;
    }
    std::uint32_t descriptor[3];
    std::uint32_t handle[2];
    StateSelection_FindLowerBound(descriptor, selection, 0);
    const bool has_handle = descriptor[1] != 0;
    bool live = false;
    if (has_handle) {
        StateHandle_ReleasePayload(handle, descriptor);
        live = StateHandle_IsLive(handle) != 0;
    }
    if (has_handle)
        StateHandle_Clear(handle);
    if (live) {
        StatePayload_Release(descriptor, 0.0f);
        StatePayload_Finalize(descriptor);
    }
}
extern "C" __attribute__((noinline)) void StateHandle_Clear(std::uint32_t handle[2]) {
    if (handle[1] != 0)
        handle[1] = 0;
}
