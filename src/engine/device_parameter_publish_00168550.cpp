#include <cstdint>
extern "C" void FUN_0018B928(std::uint32_t* value);
extern "C" void FUN_0018AFA0(std::int32_t* value);
extern "C" void FUN_00445D08(void* value);
extern "C" void GraphicsParameterStateBuilder_0018AFB4(void* value);
extern "C" __attribute__((noinline)) std::int32_t Device_PublishParameters_00168550(
    void* parameter) {
    void** const selected = reinterpret_cast<void**>(0x00D4D458u);
    *selected = parameter;
    FUN_0018B928(reinterpret_cast<std::uint32_t*>(*selected));
    FUN_0018AFA0(reinterpret_cast<std::int32_t*>(
        static_cast<std::uint8_t*>(*selected) + 4));
    FUN_00445D08(static_cast<std::uint8_t*>(*selected) + 8);
    GraphicsParameterStateBuilder_0018AFB4(static_cast<std::uint8_t*>(*selected) + 0xC);
    return 0;
}
