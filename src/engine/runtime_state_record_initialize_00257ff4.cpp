#include <cstdint>
extern "C" void *FUN_003DC5D0(void *destination, std::uint32_t size);
extern "C" __attribute__((noinline)) void *
RuntimeStateRecord_Initialize_00257FF4(void *record) {
    std::uint8_t *bytes = static_cast<std::uint8_t *>(record);
    *reinterpret_cast<std::uint32_t *>(bytes + 0x04) = 0xffffffffu;
    *(bytes + 0x298) = 3;
    *reinterpret_cast<std::uint32_t *>(bytes + 0x00) = 0;
    *(bytes + 0x08) = 0;
    *reinterpret_cast<std::uint32_t *>(bytes + 0x90) = 0;
    *reinterpret_cast<std::uint32_t *>(bytes + 0x294) = 0;
    *reinterpret_cast<std::uint32_t *>(bytes + 0x29c) = 0;
    *reinterpret_cast<std::uint32_t *>(bytes + 0x2a0) = 0;
    *reinterpret_cast<std::uint32_t *>(bytes + 0x364) = 0;
    FUN_003DC5D0(bytes + 0x12868, 0x80);
    return record;
}
