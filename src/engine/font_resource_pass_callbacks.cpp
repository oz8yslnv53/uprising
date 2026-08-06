#include <cstdint>
extern "C" void FontResourcePass_Render_00A35770(void* pass,
                                                  std::uint32_t mode);
extern "C" void EngineResource_ActivatePendingStates_0025E9D8(void* pass);
extern "C" int EngineResource_IsActive_00B60960(void* pass);
extern "C" void* Engine_LazyFactoryRegistryGetter_0049BF28();
extern "C" void MemberCallbackGroup_InvokeTen_0064C860(
    void* callback_group);
namespace {
struct FontResourcePassWrapper {
    void* callbacks;
    std::uint32_t reserved;
    std::uint8_t ready;
    std::uint8_t padding_09[3];
    void* pass;
};
typedef char kiu_sa_font_resource_pass_callbacks_1[(sizeof(FontResourcePassWrapper) == 0x10) ? 1 : -1] __attribute__((unused));
}  // namespace
extern "C" __attribute__((noinline)) void FontResourcePass_RenderCallback_00A3BA10(
    FontResourcePassWrapper* wrapper, std::uint32_t mode) {
    if (wrapper->pass != 0) {
        FontResourcePass_Render_00A35770(wrapper->pass, mode);
    }
}
extern "C" __attribute__((noinline)) void FontResourcePass_ActivateCallback_00A3BA24(
    FontResourcePassWrapper* wrapper) {
    if (wrapper->pass != 0) {
        EngineResource_ActivatePendingStates_0025E9D8(wrapper->pass);
    }
}
extern "C" __attribute__((noinline)) void FontResourcePass_PollReadyCallback_00A3BA38(
    FontResourcePassWrapper* wrapper) {
    if (wrapper->pass != 0) {
        void** vtable = *reinterpret_cast<void***>(wrapper->pass);
        reinterpret_cast<void (*)(void*)>(vtable[7])(wrapper->pass);
        if (wrapper->pass != 0 &&
            EngineResource_IsActive_00B60960(wrapper->pass) != 0) {
            wrapper->ready = 1;
        }
    }
    void** callback_group = reinterpret_cast<void**>(0x00d63560);
    if (*callback_group == 0) {
        *callback_group = Engine_LazyFactoryRegistryGetter_0049BF28();
    }
    MemberCallbackGroup_InvokeTen_0064C860(*callback_group);
}
extern "C" __attribute__((noinline)) void FontResourcePass_SetReady_00A383F0(void* pass,
                                                    std::uint8_t ready) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(pass);
    if (*reinterpret_cast<void**>(bytes + 0x1ec) != 0) {
        *reinterpret_cast<std::uint8_t*>(0x00d48e78) = ready;
    }
    bytes[0x644] = ready;
    bytes[0x0b0] = ready;
}
