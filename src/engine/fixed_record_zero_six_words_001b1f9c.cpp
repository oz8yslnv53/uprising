#include <cstdint>
extern "C" __attribute__((noinline)) void FixedRecord_ZeroSixWordsAndByte_001B1F9C(
    std::uint8_t* record)
{
    *reinterpret_cast<std::uint32_t*>(record + 0x00) = 0;
    *reinterpret_cast<std::uint32_t*>(record + 0x04) = 0;
    *reinterpret_cast<std::uint32_t*>(record + 0x08) = 0;
    *reinterpret_cast<std::uint32_t*>(record + 0x0C) = 0;
    *reinterpret_cast<std::uint32_t*>(record + 0x10) = 0;
    *reinterpret_cast<std::uint32_t*>(record + 0x14) = 0;
    record[0x11] = 0;
}
