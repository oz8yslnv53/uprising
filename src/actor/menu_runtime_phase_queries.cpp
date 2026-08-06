#include <cstdint>
namespace {
template <typename T>
T& At(void* object, std::uint32_t offset) {
    return *reinterpret_cast<T*>(
        static_cast<std::uint8_t*>(object) + offset);
}
std::uint32_t IsPrimaryPhase(void* runtime, std::uint8_t phase) {
    void* current = At<void*>(runtime, 0x6c);
    return current != 0 &&
           (At<std::uint8_t>(current, 0xa9) == phase ||
            At<std::uint8_t>(runtime, 0x7d) == phase);
}
std::uint32_t IsSecondaryPhase(void* runtime, std::uint8_t phase) {
    void* current = At<void*>(runtime, 0x84);
    return current != 0 && At<std::uint8_t>(current, 0x68) == phase;
}
}  // namespace
extern "C" __attribute__((noinline)) std::uint32_t MenuRuntime_IsPhase1_0028AC18(void* runtime) {
    return IsPrimaryPhase(runtime, 1);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuRuntime_IsPhase2_0028AC44(void* runtime) {
    return IsPrimaryPhase(runtime, 2);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuRuntime_IsPhase3_001D5140(void* runtime) {
    return IsPrimaryPhase(runtime, 3);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuRuntime_IsPhase4_0023F4C4(void* runtime) {
    return IsSecondaryPhase(runtime, 4);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuRuntime_IsPhase5_0023F504(void* runtime) {
    return IsSecondaryPhase(runtime, 5);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuRuntime_IsPhase6_0023F524(void* runtime) {
    return IsSecondaryPhase(runtime, 6);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuRuntime_IsPhase7_0023F4E4(void* runtime) {
    return IsSecondaryPhase(runtime, 7);
}
extern "C" __attribute__((noinline)) std::uint32_t MenuRuntime_IsPhase8_0023F544(void* runtime) {
    return IsSecondaryPhase(runtime, 8);
}
