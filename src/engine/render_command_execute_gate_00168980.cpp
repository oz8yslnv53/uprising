#include <cstdint>
extern "C" std::uint8_t g_RenderCommand_Context_00DBC490[];
extern "C" void RenderCommand_Lock_0014DAC8();
extern "C" void RenderCommand_Unlock_0014DAD8();
extern "C" void RenderCommand_ExecutePending_003D8FB0();
extern "C" __attribute__((noinline)) void FUN_00168980() {
    std::uint8_t* const context = g_RenderCommand_Context_00DBC490;
    std::uint8_t* const ring = *reinterpret_cast<std::uint8_t**>(context + 0x9c);
    if (ring == 0 || context[0x11] != 0)
        return;
    *reinterpret_cast<std::uint8_t**>(context + 0xa0) = ring;
    context[0x12] = 1;
    if (*reinterpret_cast<std::uint32_t*>(ring + 0x20) <=
        *reinterpret_cast<std::uint32_t*>(ring + 0x28))
        return;
    context[0x11] = 1;
    if (*reinterpret_cast<std::uint32_t*>(ring + 0x2c) != 0x300)
        return;
    RenderCommand_Lock_0014DAC8();
    RenderCommand_ExecutePending_003D8FB0();
    RenderCommand_Unlock_0014DAD8();
}
