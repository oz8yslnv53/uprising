#include <cstdint>
extern "C" void Memory_Fill_003DC5D0(
    void* destination, std::uint32_t size);
extern "C" void Engine_BulkCopy_00425DF8(
    void* destination, const void* source, std::uint32_t size);
extern "C" void Memory_FillByte_0044C190(
    void* destination, std::uint32_t size, std::uint8_t value);
extern "C" void Engine_CopyBytes_0044C108(
    void* destination, const void* source, std::uint32_t size);
extern "C" std::int32_t Utf16_CountUnits_005509C0(
    const std::int16_t* text);
extern "C" void FUN_0049CAB0(
    std::int16_t* destination, const std::int16_t* source,
    std::int32_t count);
extern "C" void FUN_003D8A68(void* destination, std::uint32_t value);
extern "C" void FUN_0054BF40(void* destination, const void* source);
extern "C" void* MemoryFillEnd_003FDCAC(
    void* destination, std::uint32_t size);
extern "C" __attribute__((noinline)) void UiTextRequest_Reset_0021FDBC(std::uint8_t* request) {
    *reinterpret_cast<std::uint32_t*>(request + 0x00) = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x04) = 1;
    *reinterpret_cast<std::uint32_t*>(request + 0x08) = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x0C) = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x10) = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x14) = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x18) = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x1C) = 0;
    *reinterpret_cast<std::uint16_t*>(request + 0x20) = 0xFDE8u;
    *reinterpret_cast<std::uint16_t*>(request + 0x22) = 0;
    *reinterpret_cast<std::uint16_t*>(request + 0x24) = 0;
    MemoryFillEnd_003FDCAC(request + 0x26, 0x66);
    *reinterpret_cast<std::uint32_t*>(request + 0x8C) = 0;
    Memory_Fill_003DC5D0(request + 0x90, 0x82);
    request[0x112] = 0;
    request[0x113] = 1;
    request[0x114] = 0;
    request[0x115] = 1;
    request[0x116] = 0;
    request[0x117] = 1;
    request[0x118] = 0;
    request[0x119] = 0;
    request[0x11A] = 0;
    request[0x11B] = 0;
    request[0x11C] = 1;
    request[0x11D] = 0;
    request[0x354] = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x120) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(request + 0x124) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(request + 0x128) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(request + 0x12C) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(request + 0x130) = 0;
    *reinterpret_cast<std::uint16_t*>(request + 0x134) = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x138) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(request + 0x13C) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(request + 0x140) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(request + 0x144) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint16_t*>(request + 0x148) = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x14C) = 0;
    Memory_Fill_003DC5D0(request + 0x150, 0x202);
}
extern "C" __attribute__((noinline)) std::int32_t UiTextRequest_Build_001EB7DC(
    std::uint8_t* state, const std::int16_t* text,
    std::uint32_t unused_a, std::uint32_t unused_b,
    std::uint32_t field_14,
    const std::int16_t* const* auxiliary_text,
    const std::uint8_t* auxiliary_flags, const std::int16_t* label,
    std::uint32_t field_00, std::uint32_t field_04,
    std::uint32_t field_08, std::uint32_t field_0C,
    std::uint32_t field_10, std::uint32_t field_18,
    std::uint16_t field_20, std::uint8_t field_114) {
    (void)unused_a;
    (void)unused_b;
    if (state[1] == 0 || state[2] != 0) {
        return 0;
    }
    state[2] = 2;
    std::uint8_t* request = reinterpret_cast<std::uint8_t*>(0x00DC5000u);
    Memory_Fill_003DC5D0(request, 0x400);
    UiTextRequest_Reset_0021FDBC(request);
    if (text != 0) {
        std::uint32_t units = static_cast<std::uint32_t>(
            Utf16_CountUnits_005509C0(text));
        if (units > 0x40u) {
            units = 0x40u;
        }
        FUN_0049CAB0(
            reinterpret_cast<std::int16_t*>(request + 0x90), text,
            static_cast<std::int32_t>(units));
        *reinterpret_cast<std::uint16_t*>(
            request + 0x90 + units * 2) = 0;
    }
    request[0x115] = 0;
    request[0x116] = 0;
    request[0x118] = 0;
    *reinterpret_cast<std::uint16_t*>(request + 0x24) = 5;
    *reinterpret_cast<std::uint32_t*>(request + 0x14) = field_14;
    *reinterpret_cast<std::uint32_t*>(request + 0x18) = field_18;
    *reinterpret_cast<std::uint32_t*>(request + 0x00) = field_00;
    *reinterpret_cast<std::uint32_t*>(request + 0x04) = field_04;
    *reinterpret_cast<std::uint32_t*>(request + 0x08) = field_08;
    *reinterpret_cast<std::uint32_t*>(request + 0x0C) = field_0C;
    *reinterpret_cast<std::uint32_t*>(request + 0x10) = field_10;
    *reinterpret_cast<std::uint16_t*>(request + 0x20) = field_20;
    request[0x114] = field_114;
    if (auxiliary_text != 0 && auxiliary_flags != 0) {
        for (std::uint32_t i = 0; i < 3; ++i) {
            const std::int16_t* const part = auxiliary_text[i];
            std::uint32_t units = static_cast<std::uint32_t>(
                Utf16_CountUnits_005509C0(part));
            if (units > 0x10u) {
                units = 0x10u;
            }
            std::int16_t* destination = reinterpret_cast<std::int16_t*>(
                request + 0x26 + i * 0x22);
            FUN_0049CAB0(destination, part,
                         static_cast<std::int32_t>(units));
            destination[units] = 0;
            request[0x11A + i] = auxiliary_flags[i];
        }
    }
    std::uint32_t label_units = static_cast<std::uint32_t>(
        Utf16_CountUnits_005509C0(label));
    if (label_units > 8u) {
        label_units = 8u;
    }
    std::int16_t* label_output = reinterpret_cast<std::int16_t*>(0x00DC8000u);
    FUN_0049CAB0(label_output, label,
                 static_cast<std::int32_t>(label_units));
    label_output[label_units] = 0;
    return 1;
}
extern "C" __attribute__((noinline)) std::int32_t UiActionTextRequest_Build_001EB690(
    std::uint8_t* state, const std::int16_t* text,
    std::uint32_t unused_a, std::uint32_t unused_b,
    std::uint8_t type, std::uint8_t subtype, std::uint8_t mode,
    std::uint16_t selection, const void* record,
    const void* payload, std::uint8_t flags_a,
    std::uint8_t flags_b, std::uint8_t flags_c) {
    (void)unused_a;
    (void)unused_b;
    if (state[1] == 0 || state[2] != 0) {
        return 0;
    }
    state[2] = 5;
    std::uint8_t* request = reinterpret_cast<std::uint8_t*>(0x00DC5000u);
    Memory_Fill_003DC5D0(request, 0x104);
    *reinterpret_cast<std::uint16_t*>(request + 0x90) = 0xFFFFu;
    request[0] = 1;
    request[3] = 1;
    request[4] = 1;
    request[0xFE] = 1;
    request[0xFF] = 1;
    request[1] = 0;
    request[2] = 0;
    request[0x8C] = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0x100) = 0;
    *reinterpret_cast<std::uint16_t*>(request + 8) = 0;
    FUN_003D8A68(request + 0x94, 1);
    Memory_FillByte_0044C190(request + 0x9A, 100, 1);
    request[0] = type;
    request[1] = subtype;
    request[0xFF] = 0;
    request[2] = flags_c;
    request[3] = flags_a;
    request[4] = flags_b;
    std::uint32_t units = static_cast<std::uint32_t>(
        Utf16_CountUnits_005509C0(text));
    if (units > 0x40u) {
        units = 0x40u;
    }
    FUN_0049CAB0(reinterpret_cast<std::int16_t*>(request + 8), text,
                 static_cast<std::int32_t>(units));
    *reinterpret_cast<std::uint16_t*>(request + 8 + units * 2) = 0;
    request[0x8C] = mode;
    *reinterpret_cast<std::uint16_t*>(request + 0x90) = selection;
    if (record != 0) {
        FUN_0054BF40(request + 0x94, record);
    }
    if (payload != 0) {
        Engine_CopyBytes_0044C108(request + 0x9A, payload, 100);
    }
    request[0xFE] = 0;
    return 1;
}
extern "C" __attribute__((noinline)) std::int32_t UiActionTextRequest_Query_001EC96C(
    const std::uint8_t* state, std::uint8_t* has_value,
    std::uint32_t* value, void* payload, std::uint32_t* metadata) {
    if (state[3] != 5 || state[1] == 0 || state[2] != 0) {
        *has_value = 0;
        *value = 0;
        Memory_Fill_003DC5D0(payload, 0x60);
        *metadata = 0;
        return -100;
    }
    const std::uint8_t* request = reinterpret_cast<const std::uint8_t*>(0x00DC5F80u);
    if (request[4] == 0) {
        *has_value = 0;
        *value = 0;
    } else {
        *has_value = 1;
        *value = *reinterpret_cast<const std::uint32_t*>(request + 8);
    }
    *metadata = *reinterpret_cast<const std::uint32_t*>(0x00DC5FECu);
    Engine_BulkCopy_00425DF8(payload, request + 0x0c, 0x60);
    return *reinterpret_cast<const std::int32_t*>(request);
}
