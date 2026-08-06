#include <cstdint>
extern "C" int ResourceStatus_GetKind_0054A2A4(void *status);
extern "C" __attribute__((noinline)) std::uint32_t ResourceTable_GetWord_005761D0(
    const std::uint8_t *table, std::int16_t index) {
    return *reinterpret_cast<const std::uint32_t *>(
        table + static_cast<std::int32_t>(index) * 0x173 * 8);
}
extern "C" __attribute__((noinline)) std::int32_t ResourceRecord_GetSignedByte_00576428(
    const std::uint8_t *record) {
    std::uint8_t*resource = *reinterpret_cast<std::uint8_t *const *>(record + 0x3c);
    return *reinterpret_cast<const std::int8_t *>(resource + 0x40);
}
extern "C" __attribute__((noinline)) std::uint32_t ResourceRecord_GetNestedWord_00576520(
    const std::uint8_t *record) {
    std::uint8_t*nested = *reinterpret_cast<std::uint8_t *const *>(record + 0x94);
    return *reinterpret_cast<const std::uint32_t *>(nested + 0xb4);
}
extern "C" __attribute__((noinline)) std::uint32_t ResourceRecord_IsEligible_005763E0(
    const std::uint8_t *record) {
    void*status = *reinterpret_cast<void *const *>(record + 0x30);
    std::uint8_t* nested = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t *>(status) + 0x168);
    if (ResourceStatus_GetKind_0054A2A4(nested) != 2)
        return 0;
    return *reinterpret_cast<const float *>(nested + 0x2c) <= 0.0f ? 1u : 0u;
}
