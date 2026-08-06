#include <cstddef>
#include <cstdint>
extern "C" void* MsgStdBnWrapper_Create_005D02B4(const void* raw_resource);
extern "C" void* Engine_AllocateMessageWrapper_005D6E78(std::uint32_t size);
extern "C" void MessageBinaryWrapper_Release_00579B14(void* wrapper);
extern "C" int ByteRange_Equals_00550E34(const void* lhs,
                                           const void* rhs,
                                           std::uint32_t size);
extern "C" std::uint32_t Object_GetAllocatorContext(void* object);
extern "C" void* Engine_AllocateTaggedBlock(std::uint32_t element_size,
                                              void* type_tag,
                                              std::uint32_t count);
extern "C" void Memory_Fill_003DC5D0(void* destination, std::uint32_t size);
extern "C" int Utf16_CountUnits_005509C0(const std::int16_t* text);
extern "C" void FUN_0049CAB0(std::int16_t* destination,
                               std::int16_t* source, int count);
extern "C" std::uint32_t FUN_001E7B64(void* record, std::uint32_t mode);
extern "C" void Engine_ReleaseStorage_0031C704(void* handle);
extern "C" void Engine_ReleaseResource_00186614(void* handle);
// Semantic reconstruction, JP Rev 1: 0x005D6E78.
extern "C" __attribute__((noinline)) void*
Engine_AllocateMessageWrapper_005D6E78(std::uint32_t size) {
    std::uintptr_t* table = *reinterpret_cast<std::uintptr_t**>(0x005D6E84u);
    void* (*allocate)(std::uint32_t) = reinterpret_cast<void* (*)(std::uint32_t)>(table[0]);
    return allocate(size);
}
std::uint32_t SaveUiSelectTextResource(
    std::int32_t mode, std::int32_t variant) {
    if (mode < 1 || mode > 12 || variant <= 1 || variant >= 31) {
        return 0;
    }
    switch (mode) {
    case 1:
        return variant < 19 ? 9u : 10u;
    case 2:
        return variant < 19 ? 10u : 11u;
    case 3:
        return variant < 21 ? 11u : 0u;
    case 4:
        return variant > 19 ? 1u : 0u;
    case 5:
        return variant < 21 ? 1u : 2u;
    case 6:
        return variant > 21 ? 3u : 2u;
    case 7:
        return variant >= 23 ? 4u : 3u;
    case 8:
        return variant > 21 ? 5u : 4u;
    case 9:
        return variant >= 23 ? 6u : 5u;
    case 10:
        return variant >= 24 ? 7u : 6u;
    case 11:
        return variant < 21 ? 7u : 8u;
    case 12:
        return variant >= 21 ? 9u : 8u;
    default:
        return 0;
    }
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_001C1C88(void* unused,
                                       std::int32_t mode,
                                       std::int32_t variant) {
    (void)unused;
    return SaveUiSelectTextResource(mode, variant);
}
extern "C" __attribute__((noinline)) std::int32_t UiRequest_QueryState_001ECA0C(
    const std::uint8_t* state, std::uint32_t* payload, std::uint32_t* units) {
    const std::uint8_t* request = reinterpret_cast<const std::uint8_t*>(0x00DC5000);
    if (state[0x03] == 2 && state[0x01] != 0 && state[0x02] == 0) {
        *payload = 0x00DC7000u +
                   *reinterpret_cast<const std::uint32_t*>(request + 0x144);
        *units = *reinterpret_cast<const std::uint16_t*>(request + 0x148);
        return *reinterpret_cast<const std::int32_t*>(request + 0x138);
    }
    *payload = 0;
    *units = 0;
    return -1;
}
extern "C" __attribute__((noinline)) std::int32_t UiRequest_GetType4Status_00B499BC(
    const std::uint8_t* state) {
    const std::uint8_t* request = reinterpret_cast<const std::uint8_t*>(0x00DC5000);
    return state[0x03] == 4 && state[0x01] != 0 && state[0x02] == 0
               ? *reinterpret_cast<const std::int32_t*>(request + 0xF70)
               : -1;
}
extern "C" __attribute__((noinline)) std::int32_t UiRequest_GetType3Status_00B499F4(
    const std::uint8_t* state) {
    const std::uint8_t* request = reinterpret_cast<const std::uint8_t*>(0x00DC5000);
    return state[0x03] == 3 && state[0x01] != 0 && state[0x02] == 0
               ? *reinterpret_cast<const std::int32_t*>(request + 0xF70)
               : -1;
}
// Semantic reconstruction, JP Rev 1: 0x00919B9C.
extern "C" __attribute__((noinline)) std::int32_t TextRequest_Setup_00919B9C(
    std::uint8_t* state, std::uint32_t placement, std::uint32_t unused_a,
    std::uint32_t unused_b, std::uint32_t mode, std::uint32_t flags) {
    (void)unused_a;
    (void)unused_b;
    std::uint8_t* request = reinterpret_cast<std::uint8_t*>(0x00DC5000);
    if (state[0x01] == 0 || state[0x02] != 0) {
        return 0;
    }
    state[0x02] = 4;
    Memory_Fill_003DC5D0(request, 0xF80);
    *reinterpret_cast<std::uint32_t*>(request + 0x00) = 2;
    *reinterpret_cast<std::uint32_t*>(request + 0x04) = placement;
    *reinterpret_cast<std::uint16_t*>(request + 0x08) = mode;
    *reinterpret_cast<std::uint16_t*>(request + 0x0A) = 0;
    request[0xEE4] = 0;
    request[0xEE5] = 0;
    request[0xEE6] = flags;
    *reinterpret_cast<std::uint16_t*>(request + 0x0C) = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0xF70) = 0xFFFFFFFFu;
    return 1;
}
extern "C" __attribute__((noinline)) std::int32_t TextRequest_SetString_00919C1C(
    std::uint8_t* state, std::int16_t* text, std::uint32_t placement,
    std::uint32_t unused_a, std::uint32_t unused_b, std::uint16_t mode,
    std::uint8_t flags) {
    (void)unused_a;
    (void)unused_b;
    if (state[0x01] == 0 || state[0x02] != 0) {
        return 0;
    }
    state[0x02] = 3;
    std::uint8_t* request = reinterpret_cast<std::uint8_t*>(0x00DC5000);
    Memory_Fill_003DC5D0(request, 0xF80);
    if (text == 0) {
        *reinterpret_cast<std::uint32_t*>(request + 0x00) = 0;
    } else {
        *reinterpret_cast<std::uint32_t*>(request + 0x00) = 1;
        std::uint32_t units = static_cast<std::uint32_t>(Utf16_CountUnits_005509C0(text));
        if (units > 0x76Bu) {
            units = 0x76Bu;
        }
        FUN_0049CAB0(reinterpret_cast<std::int16_t*>(request + 0x0C), text,
                     static_cast<int>(units));
        *reinterpret_cast<std::uint16_t*>(request + 0x0C + units * 2) = 0;
    }
    *reinterpret_cast<std::uint16_t*>(request + 0x0A) = 0;
    request[0xEE4] = 0;
    request[0xEE5] = 0;
    *reinterpret_cast<std::uint32_t*>(request + 0xF70) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(request + 0x04) = placement;
    *reinterpret_cast<std::uint16_t*>(request + 0x08) = mode;
    request[0xEE6] = flags;
    return 1;
}
extern "C" __attribute__((noinline)) std::uint32_t FUN_001B1B80(void* record, void* storage) {
    if (storage == 0) {
        return 0xE0E0EBF6u;
    }
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    if (bytes[0x18] != 0) {
        return 0xE0E0EBEBu;
    }
    *reinterpret_cast<void**>(bytes + 0x1C) = storage;
    *reinterpret_cast<void**>(bytes + 0x20) = storage;
    *reinterpret_cast<std::uint8_t**>(bytes + 0x24) =
        static_cast<std::uint8_t*>(storage) + 0xB000;
    *reinterpret_cast<std::uint8_t**>(bytes + 0x28) =
        static_cast<std::uint8_t*>(storage) + 0xF000;
    *reinterpret_cast<std::uint8_t**>(bytes + 0x2C) =
        static_cast<std::uint8_t*>(storage) + 0xF800;
    const std::uint32_t status = FUN_001E7B64(
        record, reinterpret_cast<std::uintptr_t>(storage) + 0xF800u);
    if ((status & 0x80000000u) == 0) {
        return 0;
    }
    return status;
}
extern "C" __attribute__((noinline)) void FUN_001B1DF8(void* record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x00) = 0x00D145B0u;
    for (std::uint32_t offset = 0x04; offset < 0x38; offset += 4) {
        *reinterpret_cast<std::uint32_t*>(bytes + offset) = 0;
    }
}
extern "C" __attribute__((noinline)) void FUN_001B1D9C(void* record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    if (bytes[0x19] != 0) {
        Engine_ReleaseStorage_0031C704(reinterpret_cast<void*>(0x00CB019Cu));
    }
    if (bytes[0x18] != 0) {
        Engine_ReleaseResource_00186614(bytes + 0x04);
    }
    bytes[0x18] = 0;
    bytes[0x19] = 0;
    bytes[0x1A] = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x1C) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x20) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x24) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2C) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x30) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x34) = 0;
}
// Semantic reconstruction, JP Rev 1: 0x00193E14.
extern "C" __attribute__((noinline)) void* SaveUi_TextNodeCreate_00193E14(void* owner,
                                                  void* resource) {
    (void)owner;
    std::uint8_t* node = static_cast<std::uint8_t*>(Engine_AllocateTaggedBlock(
        0x28, reinterpret_cast<void*>(static_cast<std::uintptr_t>(0x00193EA4)),
        Object_GetAllocatorContext(resource)));
    *reinterpret_cast<std::uint8_t**>(node + 0x00) = node;
    *reinterpret_cast<std::uint8_t**>(node + 0x04) = node;
    *reinterpret_cast<std::uint8_t**>(node + 0x08) = node;
    *reinterpret_cast<std::uint32_t*>(node + 0x0c) = 0;
    *reinterpret_cast<std::uint32_t*>(node + 0x10) = 0;
    node[0x14] = 0;
    node[0x15] = 0;
    *reinterpret_cast<float*>(node + 0x18) = 0.0f;
    *reinterpret_cast<float*>(node + 0x1c) = 0.0f;
    node[0x20] = 0xff;
    node[0x21] = 0xff;
    node[0x22] = 0xff;
    node[0x23] = 0xff;
    node[0x24] &= 0xf0;
    node[0x20] = 0xff;
    node[0x22] = 0xff;
    node[0x21] = 0xff;
    node[0x14] = 0;
    node[0x15] = 1;
    *reinterpret_cast<std::uint32_t*>(node + 0x0c) = 0;
    *reinterpret_cast<std::uint32_t*>(node + 0x10) = 0;
    return node;
}
extern "C" __attribute__((noinline)) void MsgStdBnHandle_Bind_005CDA44(void** destination,
                                              const void* raw_resource) {
    *destination = MsgStdBnWrapper_Create_005D02B4(raw_resource);
}
// Semantic reconstruction, JP Rev 1: 0x005CDA5C.
extern "C" __attribute__((noinline)) void MessageBinaryHandle_Reset_005CDA5C(void** handle) {
    if (*handle != 0) {
        MessageBinaryWrapper_Release_00579B14(*handle);
        *handle = 0;
    }
}
extern "C" __attribute__((noinline)) std::uint32_t
MessageBinary_FindSectionIndex_005D344C(
    const void* wrapper,
    const void* section_tag) {
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(wrapper);
    const std::uint16_t count = *reinterpret_cast<const std::uint16_t*>(bytes + 0x0a);
    const std::uint8_t* sections = *reinterpret_cast<const std::uint8_t* const*>(
        bytes + 0x0c);
    for (std::uint16_t index = 0; index < count; ++index) {
        const void* tag = sections + static_cast<std::size_t>(index) * 0x10 +
                          0x04;
        if (ByteRange_Equals_00550E34(tag, section_tag, 4) != 0) {
            return index;
        }
    }
    return UINT32_MAX;
}
// Semantic reconstruction, JP Rev 1: 0x005D3348.
extern "C" __attribute__((noinline)) void
MessageBinary_ParseSections_005D3348(void* wrapper) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(wrapper);
    std::uint8_t* raw = *reinterpret_cast<std::uint8_t**>(bytes + 0x00);
    bytes[0x02] = raw[0x0c];
    const std::uint16_t count = *reinterpret_cast<const std::uint16_t*>(raw + 0x0e);
    *reinterpret_cast<std::uint16_t*>(bytes + 0x0a) = count;
    const std::uint32_t descriptor_bytes = static_cast<std::uint32_t>(count) << 4;
    std::uint8_t* descriptors = static_cast<std::uint8_t*>(
        Engine_AllocateMessageWrapper_005D6E78(descriptor_bytes));
    *reinterpret_cast<std::uint8_t**>(bytes + 0x0c) = descriptors;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x04) =
        *reinterpret_cast<const std::uint32_t*>(raw + 0x12);
    std::uint32_t offset = 0x20;
    for (std::uint16_t index = 0; index < count; ++index) {
        std::uint8_t* descriptor = descriptors + static_cast<std::uint32_t>(index) * 0x10;
        *reinterpret_cast<std::uint8_t**>(descriptor + 0x00) = raw + offset + 0x10;
        descriptor[0x04] = raw[offset + 0x00];
        descriptor[0x05] = raw[offset + 0x01];
        descriptor[0x06] = raw[offset + 0x02];
        descriptor[0x07] = raw[offset + 0x03];
        *reinterpret_cast<std::uint32_t*>(descriptor + 0x08) =
            *reinterpret_cast<const std::uint32_t*>(raw + offset + 0x04);
        *reinterpret_cast<std::uint16_t*>(descriptor + 0x0c) =
            *reinterpret_cast<const std::uint16_t*>(raw + offset + 0x08);
        const std::uint32_t payload_size =
            *reinterpret_cast<const std::uint32_t*>(raw + offset + 0x04);
        offset = (payload_size + offset + 0x1fu) & ~0x0fu;
    }
}
// Semantic reconstruction, JP Rev 1: 0x005D02B4.
extern "C" __attribute__((noinline)) void* MsgStdBnWrapper_Create_005D02B4(const void* raw_resource) {
    std::uint8_t* wrapper = static_cast<std::uint8_t*>(
        Engine_AllocateMessageWrapper_005D6E78(0x20));
    *reinterpret_cast<const void**>(wrapper + 0x00) = raw_resource;
    MessageBinary_ParseSections_005D3348(wrapper);
    static const char lbl1[] = "LBL1";
    static const char txt2[] = "TXT2";
    static const char atr1[] = "ATR1";
    static const char tsy1[] = "TSY1";
    *reinterpret_cast<std::uint32_t*>(wrapper + 0x10) =
        MessageBinary_FindSectionIndex_005D344C(wrapper, lbl1);
    *reinterpret_cast<std::uint32_t*>(wrapper + 0x14) =
        MessageBinary_FindSectionIndex_005D344C(wrapper, txt2);
    *reinterpret_cast<std::uint32_t*>(wrapper + 0x18) =
        MessageBinary_FindSectionIndex_005D344C(wrapper, atr1);
    *reinterpret_cast<std::uint32_t*>(wrapper + 0x1c) =
        MessageBinary_FindSectionIndex_005D344C(wrapper, tsy1);
    return wrapper;
}
// Semantic reconstruction, JP Rev 1: 0x005F8074.
extern "C" __attribute__((noinline)) void* MsgPrjBnWrapper_Create_005F8074(const void* raw_resource) {
    std::uint8_t* wrapper = static_cast<std::uint8_t*>(
        Engine_AllocateMessageWrapper_005D6E78(0x40));
    *reinterpret_cast<const void**>(wrapper + 0x00) = raw_resource;
    MessageBinary_ParseSections_005D3348(wrapper);
    static const char* const tags[] = {
        "CLR1", "CLB1", "ATI2", "ALB1", "ALI2", "TGG2",
        "TAG2", "TGP2", "TGL2", "SYL3", "SLB1", "CTI1",
    };
    for (std::uint32_t index = 0; index < 12; ++index) {
        *reinterpret_cast<std::uint32_t*>(wrapper + 0x10 + index * 4) =
            MessageBinary_FindSectionIndex_005D344C(wrapper, tags[index]);
    }
    return wrapper;
}
// Semantic reconstruction, JP Rev 1: 0x00927108.
extern "C" __attribute__((noinline)) void MsgPrjBnHandle_Bind_00927108(
    void** destination, const void* raw_resource) {
    *destination = MsgPrjBnWrapper_Create_005F8074(raw_resource);
}
