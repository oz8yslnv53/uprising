#include <cstdint>
extern "C" std::uint32_t GpuCommandRing_CurrentContext_001B268C();
extern "C" std::uint32_t GpuCommandRing_Append_001E84C4(
    std::uint32_t* producer, const std::uint32_t* request);
extern "C" __attribute__((noinline)) std::uint32_t
GpuCommandRing_CurrentContext_001B268C() {
    return *reinterpret_cast<volatile std::uint32_t*>(0x00d4e64c + 0x1c);
}
extern "C" __attribute__((noinline)) void GpuCommand_BuildType0_001B213C(
    std::uint32_t address, std::uint32_t value, std::uint32_t command,
    std::uint32_t flags, std::uint32_t enabled) {
    if (enabled != 0 && address + 0xe1000000u >= 0x600000u)
        return;
    const std::uint32_t root =
        *reinterpret_cast<volatile std::uint32_t*>(0x00d5b0b0);
    const std::uint32_t state =
        *reinterpret_cast<volatile std::uint32_t*>(root + 4);
    std::uint32_t request[8];
    request[0] = (*reinterpret_cast<volatile std::uint32_t*>(state) &
                  0x00ffff00u) |
                 (static_cast<std::uint32_t>(
                      *reinterpret_cast<volatile std::uint8_t*>(root)) <<
                  24);
    request[1] = value;
    request[2] = address;
    request[3] = command;
    request[4] = *reinterpret_cast<volatile std::uint32_t*>(state + 0x10);
    request[5] = *reinterpret_cast<volatile std::uint32_t*>(state + 0x14);
    request[6] = *reinterpret_cast<volatile std::uint32_t*>(state + 0x18);
    request[7] = flags;
    const std::uint32_t context = GpuCommandRing_CurrentContext_001B268C();
    GpuCommandRing_Append_001E84C4(
        reinterpret_cast<std::uint32_t*>(context + 0x58), request);
}
extern "C" __attribute__((noinline)) void RenderCommand_ExecuteType0_0018BEE0(
    std::uint32_t address, std::uint32_t value, std::uint32_t command,
    std::uint32_t flags) {
    GpuCommand_BuildType0_001B213C(address, value, command, flags, 1);
}
