// Retail 0x008FC780 and its small memory-size helpers.
#include <cstdint>
extern "C" std::uint32_t Platform_MapResourceAddress_003AC86C(
    std::uint32_t address);
extern "C" __attribute__((noinline)) int FUN_0014DAE8() {
    return static_cast<int>(*reinterpret_cast<std::int8_t*>(0x00d4e64du));
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_0051EAD0(std::uint32_t size) {
    if (size == 0x20000u)
        return FUN_0014DAE8() ? 0x1f180000u : 0x1f000000u;
    if (size == 0x30000u)
        return FUN_0014DAE8() ? 0x1f380000u : 0x1f300000u;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_008FC780(std::uint32_t* range,
                                       std::uint8_t* entry,
                                       std::int32_t enabled) {
    std::uint8_t* output = reinterpret_cast<std::uint8_t*>(range[2]);
    std::uint8_t**const cursor_slot = reinterpret_cast<std::uint8_t**>(0x00d4d134u);
    if (output == 0)
        output = *cursor_slot;
    const std::uint32_t* type_table = reinterpret_cast<const std::uint32_t*>(0x00cb026cu);
    std::uint32_t type = type_table[entry[4]];
    if (enabled != 0)
        type = 0x6010u;
    const std::uint32_t allocated = Platform_MapResourceAddress_003AC86C(
        FUN_0051EAD0(0x20000u));
    std::uint32_t resource = *reinterpret_cast<std::uint32_t*>(entry + 0x20);
    if (resource == 0) {
        const std::int32_t offset = *reinterpret_cast<std::int32_t*>(entry + 0x0c);
        resource = offset == 0 ? 0u : reinterpret_cast<std::uintptr_t>(entry + 0x0c) + offset;
    }
    const std::uint32_t mapped = Platform_MapResourceAddress_003AC86C(resource);
    std::uint32_t* out = reinterpret_cast<std::uint32_t*>(output);
    out[0] = mapped - allocated;
    out[1] = 0x000f0228u;
    out[2] = *reinterpret_cast<std::uint32_t*>(entry + 8);
    out[3] = 0x000f0228u;
    if (*reinterpret_cast<std::uint32_t*>(entry) == 0x1403u) {
        out[0] |= 0x80000000u;
        out[2] >>= 1;
    }
    out[4] = 0x00020229u;
    out[5] = 0;
    out[6] = 0;
    out[7] = 0x00020229u;
    out[8] = 1;
    out[9] = 0x000f025fu;
    out[10] = 1;
    out[11] = 0;
    out[12] = 0x000f025fu;
    out[13] = 1;
    out[14] = 0x00020229u;
    out[15] = 0;
    out[16] = 0x000f025fu;
    out[17] = 1;
    out[18] = 0x00020229u;
    out[19] = 0;
    out[20] = 0x000f025fu;
    out[21] = 1;
    out[22] = 0x00020229u;
    out[23] = 0;
    out[24] = 0x000f025fu;
    out[25] = 1;
    out[26] = 0x00020229u;
    out[27] = 0;
    out[4] = (type == 4) ? 0x100u : 0u;
    out[5] = 0x00020229u;
    out[6] = type == 4 ? 0x100u : 0u;
    out[7] = 0x0002025eu;
    out[8] = 1;
    out[9] = 0x000f025fu;
    out[10] = 1;
    out[11] = 0x00010245u;
    out[12] = 0;
    out[13] = 0x000f022fu;
    out[14] = 1;
    out[15] = 0x0008025eu;
    out[16] = 0;
    out[17] = 0x0008025eu;
    out[18] = 1;
    out[19] = 0x000f0111u;
    out[20] = 1;
    out[21] = 0x000f0111u;
    out[22] = 0;
    out[23] = 0x000f0111u;
    out[24] = 1;
    out[25] = 0x000f0111u;
    out[26] = 0;
    out[27] = 0x000f0111u;
    if (range[2] != 0)
        range[2] += 0x70u;
    else
        *cursor_slot += 0x70u;
    return 0x70u;
}
