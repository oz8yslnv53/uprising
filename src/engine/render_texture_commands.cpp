#include <cstdint>
extern "C" __attribute__((noinline)) std::uint32_t*
TextureState_AppendExtendedRecord_00152284(
    std::uint8_t* record, std::uint32_t* out, int prepend_header);
extern "C" __attribute__((noinline)) void TextureDescriptor_InitRecord_0014BCB4(void* record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    *reinterpret_cast<std::uint32_t*>(bytes) = 0;
    *reinterpret_cast<std::uint16_t*>(bytes + 4) = 0;
    *reinterpret_cast<std::uint16_t*>(bytes + 6) = 0;
    bytes[8] = 12;
    bytes[9] = 2;
    bytes[10] = 2;
    bytes[11] = 0;
    bytes[12] = 0;
    *reinterpret_cast<float*>(bytes + 0x10) = 0.0f;
    bytes[0x14] = 0;
    bytes[0x15] = 0;
    bytes[0x16] = 0;
    bytes[0x17] = 0;
    bytes[0x18] = 0;
    bytes[0x19] = 0;
}
extern "C" __attribute__((noinline)) void* TextureDescriptor_InitUnitSet_00129828(void* descriptor) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(descriptor);
    TextureDescriptor_InitRecord_0014BCB4(bytes);
    bytes[0x1C] = 5;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x20) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x24) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2C) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x30) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x34) = 0;
    *reinterpret_cast<void**>(bytes + 0x38) = descriptor;
    TextureDescriptor_InitRecord_0014BCB4(bytes + 0x3C);
    bytes[0x58] = 0;
    *reinterpret_cast<void**>(bytes + 0x5C) = descriptor;
    TextureDescriptor_InitRecord_0014BCB4(bytes + 0x60);
    bytes[0x7C] = 0;
    bytes[0x7D] = 0;
    *reinterpret_cast<void**>(bytes + 0x80) = descriptor;
    TextureDescriptor_InitRecord_0014BCB4(bytes + 0x84);
    bytes[0xA0] = 0;
    bytes[0xA1] = 0;
    *reinterpret_cast<void**>(bytes + 0xA4) = descriptor;
    return descriptor;
}
extern "C" __attribute__((noinline))  std::uint32_t* TextureState_AppendFlags_00167314(
    const std::uint8_t* state, std::uint32_t* out, int prepend_header) {
    if (prepend_header != 0) {
        *out++ = 0;
        *out++ = 0x00200080;
        *out++ = 0;
        *out++ = 0;
    }
    const std::uint32_t flag0 = state[0x1C] != 5;
    const std::uint32_t flag1 = state[0x58] != 0;
    const std::uint32_t flag2 = state[0x7C] != 0;
    const std::uint32_t flag10 = state[0xA0] != 0;
    const std::uint32_t flag13 = state[0x7D] != 0;
    const std::uint32_t field8 = state[0xA1];
    const std::uint32_t flags = flag0 | (flag1 << 1) |
                                (flag2 << 2) | (field8 << 8) |
                                (flag10 << 10) | (flag13 << 13);
    *out++ = flags | 0x11000;
    *out++ = 0x000F0080;
    return out;
}
static inline std::uint32_t TextureState_QuantizeFloat(float value) {
    union FloatBits {
        float value;
        std::uint32_t bits;
    } value_bits;
    value_bits.value = value;
    if (value == 0.0f || ((value_bits.bits >> 23) & 0xFF) == 0xFF)
        return 0;
    float scaled = (value + 16.0f) * 256.0f;
    if (scaled < 0.0f)
        scaled = 0.0f;
    else if (scaled >= 8192.0f)
        scaled = 8191.0f;
    if (scaled < 4096.0f)
        scaled += 4096.0f;
    else
        scaled -= 4096.0f;
    return static_cast<std::uint32_t>(scaled);
}
static inline std::uint32_t* TextureState_AppendCompactBody(
    const std::uint8_t* descriptor, std::uint32_t* out,
    std::uint32_t command_base) {
    const std::uint8_t mode = descriptor[0x0C];
    const std::uint32_t dimensions =
        *reinterpret_cast<const std::uint32_t*>(descriptor + 4);
    std::uint32_t packed =
        static_cast<std::uint32_t>(mode == 3 || mode == 4 || mode == 5) << 2;
    packed |= static_cast<std::uint32_t>(descriptor[0x0B]) << 1;
    packed |= static_cast<std::uint32_t>(descriptor[8] == 12) << 5;
    packed |= static_cast<std::uint32_t>(descriptor[9]) << 8;
    packed |= static_cast<std::uint32_t>(descriptor[0x0A]) << 12;
    packed |= static_cast<std::uint32_t>(mode == 2 || mode == 5) << 24;
    packed |= static_cast<std::uint32_t>(descriptor[0x1C]) << 28;
    *out++ =
        (*reinterpret_cast<const std::uint32_t*>(descriptor + 0x16) &
         0x00FFFFFF) |
        (static_cast<std::uint32_t>(descriptor[0x19]) << 24);
    *out++ = 0x000F0000 | command_base;
    *out++ = (dimensions >> 16) | (dimensions << 16);
    *out++ = 0x000F0000 | (command_base + 1);
    *out++ = packed;
    *out++ = 0x000F0000 | (command_base + 2);
    std::uint32_t quantized = 0;
    if (mode != 0 && mode != 3) {
        quantized = TextureState_QuantizeFloat(
            *reinterpret_cast<const float*>(descriptor + 0x10));
        quantized |= static_cast<std::uint32_t>(descriptor[0x15]) << 16;
        quantized |= static_cast<std::uint32_t>(descriptor[0x14]) << 24;
    }
    *out++ = quantized;
    *out++ = 0x000F0000 | (command_base + 3);
    *out++ = *reinterpret_cast<const std::uint32_t*>(descriptor) >> 3;
    *out++ = 0x000F0000 | (command_base + 4);
    *out++ = descriptor[8];
    *out++ = 0x000F0000 | (command_base + 5);
    return out;
}
extern "C" __attribute__((noinline)) std::uint32_t*
TextureState_AppendExtendedRecord_00152284(
    std::uint8_t* record, std::uint32_t* out, int prepend_header) {
    if (prepend_header != 0) {
        out = TextureState_AppendFlags_00167314(
            *reinterpret_cast<std::uint8_t**>(record + 0x38), out, 1);
    }
    const std::uint8_t mode = record[0x0C];
    const std::uint8_t address_mode = record[0x1C];
    const std::uint32_t dimensions =
        *reinterpret_cast<const std::uint32_t*>(record + 4);
    std::uint32_t packed =
        static_cast<std::uint32_t>(mode == 3 || mode == 4 || mode == 5) << 2;
    packed |= static_cast<std::uint32_t>(record[0x0B]) << 1;
    packed |= static_cast<std::uint32_t>(record[8] == 12) << 5;
    packed |= static_cast<std::uint32_t>(record[9]) << 8;
    packed |= static_cast<std::uint32_t>(record[0x0A]) << 12;
    packed |=
        static_cast<std::uint32_t>(address_mode == 2 || address_mode == 4)
        << 20;
    packed |= static_cast<std::uint32_t>(mode == 2 || mode == 5) << 24;
    packed |= static_cast<std::uint32_t>(address_mode) << 28;
    *out++ =
        (*reinterpret_cast<const std::uint32_t*>(record + 0x16) &
         0x00FFFFFF) |
        (static_cast<std::uint32_t>(record[0x19]) << 24);
    *out++ = 0x000F0081;
    *out++ = (dimensions >> 16) | (dimensions << 16);
    *out++ = 0x000F0082;
    *out++ = packed;
    *out++ = 0x000F0083;
    std::uint32_t quantized = 0;
    if (mode != 0 && mode != 3) {
        quantized = TextureState_QuantizeFloat(
            *reinterpret_cast<const float*>(record + 0x10));
        quantized |= static_cast<std::uint32_t>(record[0x15]) << 16;
        quantized |= static_cast<std::uint32_t>(record[0x14]) << 24;
    }
    *out++ = quantized;
    *out++ = 0x000F0084;
    if (address_mode == 0 || address_mode == 2 || address_mode == 3) {
        *out++ = *reinterpret_cast<const std::uint32_t*>(record) >> 3;
        *out++ = 0x000F0085;
    } else if (address_mode == 1 || address_mode == 4) {
        *out++ =
            *reinterpret_cast<const std::uint32_t*>(record + 0x20) >> 3;
        *out++ = 0x000F0085;
        const std::uint32_t address_mask = 0xE03FFFFF;
        *out++ =
            (*reinterpret_cast<const std::uint32_t*>(record + 0x24) >> 3) &
            address_mask;
        *out++ = 0x000F0086;
        *out++ =
            (*reinterpret_cast<const std::uint32_t*>(record + 0x28) >> 3) &
            address_mask;
        *out++ = 0x000F0087;
        *out++ =
            (*reinterpret_cast<const std::uint32_t*>(record + 0x2C) >> 3) &
            address_mask;
        *out++ = 0x000F0088;
        *out++ =
            (*reinterpret_cast<const std::uint32_t*>(record + 0x30) >> 3) &
            address_mask;
        *out++ = 0x000F0089;
        *out++ =
            (*reinterpret_cast<const std::uint32_t*>(record + 0x34) >> 3) &
            address_mask;
        *out++ = 0x000F008A;
    }
    *out++ = record[8];
    *out++ = 0x000F008E;
    return out;
}
extern "C" __attribute__((noinline)) std::uint32_t*
TextureState_AppendCompactRecord_00152520(
    std::uint8_t* descriptor, std::uint32_t* out, int prepend_header) {
    if (prepend_header != 0) {
        out = TextureState_AppendFlags_00167314(
            *reinterpret_cast<std::uint8_t**>(descriptor + 0x20), out, 1);
    }
    return TextureState_AppendCompactBody(descriptor, out, 0x91);
}
extern "C" __attribute__((noinline))  std::uint32_t* TextureState_AppendUnitSet_001526F0(
    std::uint8_t* descriptor, std::uint32_t* out, int prepend_header) {
    out = TextureState_AppendFlags_00167314(descriptor, out, prepend_header);
    out = TextureState_AppendExtendedRecord_00152284(descriptor, out, 0);
    out = TextureState_AppendCompactRecord_00152520(
        descriptor + 0x3C, out, 0);
    return TextureState_AppendCompactBody(descriptor + 0x60, out, 0x99);
}
