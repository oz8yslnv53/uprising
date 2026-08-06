#include <cstdint>
extern "C" void* ResourceTable_Lookup(void* table);
extern "C" void ActorStateMachine_DispatchMessage(void* machine,
                                                   void* message,
                                                   void* context);
namespace {
__attribute__((always_inline)) inline std::uint32_t Dispatch(
    void* owner, void* message, void* context) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(owner);
    if ((bytes[0x38] & 1) != 0 &&
        ResourceTable_Lookup(bytes + 0x34) != 0 &&
        (bytes[0x38] & 2) == 0) {
        void* machine = ResourceTable_Lookup(bytes + 0x34);
        if (machine != 0) {
            ActorStateMachine_DispatchMessage(machine, message, context);
        }
    }
    return 0;
}
}  // namespace
extern "C" __attribute__((noinline)) std::uint32_t
ActorStateMachine_DispatchMessageWrapper_A_0033A3CC(
    void* owner, void* unused, void* message, void* context) {
    (void)unused;
    return Dispatch(owner, message, context);
}
extern "C" __attribute__((noinline)) std::uint32_t
ActorStateMachine_DispatchMessageWrapper_B_0033A430(
    void* owner, void* unused, void* message, void* context) {
    (void)unused;
    return Dispatch(owner, message, context);
}
