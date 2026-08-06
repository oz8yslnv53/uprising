#include <cstdint>
extern "C" void* Engine_ForEachStrideCallback_00421EA4(
    void* base, void* callback, std::uint32_t stride, std::uint32_t count);
extern "C" void* FUN_0050E090(
    const void* descriptor, void* allocator);
extern "C" __attribute__((noinline)) void
RenderPass_TopRecord_NoOp_00729FAC(void*) {}
extern "C" __attribute__((noinline)) void*
RenderPass_TopConstruct_0072AA9C(
    void* object, std::uint32_t mode, void* context,
    const std::uint32_t* configuration) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    *reinterpret_cast<void**>(bytes + 0x04) = bytes;
    *reinterpret_cast<void**>(bytes + 0x08) = bytes + 0x04;
    *reinterpret_cast<void**>(bytes + 0x0c) = bytes + 0x04;
    *reinterpret_cast<void**>(bytes + 0x10) = bytes + 0x18;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x14) = 0x20;
    bytes[0x18] = 0;
    bytes[0x38] = 1;
    bytes[0x1c] = 1;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x3c) = mode;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x00) = 0x00CEF080u;
    for (std::uint32_t index = 0; index < 9; ++index)
        *reinterpret_cast<std::uint32_t*>(bytes + 0x40 + index * 4) =
            configuration[index];
    *reinterpret_cast<float*>(bytes + 0x6c) = 1.0f;
    *reinterpret_cast<float*>(bytes + 0x64) = 0.0f;
    *reinterpret_cast<float*>(bytes + 0x68) = 0.35f;
    *reinterpret_cast<float*>(bytes + 0x80) = 0.0f;
    *reinterpret_cast<float*>(bytes + 0x84) = 0.0f;
    *reinterpret_cast<float*>(bytes + 0x88) = 0.0f;
    *reinterpret_cast<float*>(bytes + 0x8c) = 0.0f;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x90) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x94) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x98) = 1;
    bytes[0x9c] = 0;
    std::uint8_t* records = static_cast<std::uint8_t*>(
        Engine_ForEachStrideCallback_00421EA4(
            bytes + 0xa0,
            reinterpret_cast<void*>(
                &RenderPass_TopRecord_NoOp_00729FAC),
            0x90u, 4u));
    *reinterpret_cast<float*>(records + 0x2c0) = 20.0f;
    bytes[0x2c4] = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c8) = 0;
    const std::uint8_t* table = reinterpret_cast<const std::uint8_t*>(0x00CA7B64u);
    void* allocator = *reinterpret_cast<void* const*>(
        static_cast<const std::uint8_t*>(context) + 0x40);
    const std::uint8_t* callback_table = table;
    for (std::uint32_t index = 0; index < 4; ++index) {
        std::uint8_t descriptor[0x40] = {};
        descriptor[0x00] = 1;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x04) =
            *reinterpret_cast<const std::uint32_t*>(callback_table + 0x08 + index * 4);
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x0c) = 0x40;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x10) = 0x40;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x14) = 4;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x18) = 8;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x1c) = 4;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x20) = 8;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x24) = 4;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x28) = 8;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x2c) = 4;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x30) = 8;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x34) = 0x40;
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x38) =
            *reinterpret_cast<const std::uint32_t*>(table + 0x18 + index * 4);
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x3c) = 0x40;
        *reinterpret_cast<void**>(bytes + 0x70 + index * 4) =
            FUN_0050E090(descriptor, allocator);
    }
    return bytes;
}
