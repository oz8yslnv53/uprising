#include <cstdint>
extern "C" void RenderDraw_SubmitPacket_00113294(
    void*, void*, std::uint32_t, const std::uint16_t*);
extern "C" void* FUN_00353C6C();
extern "C" void* FUN_0039FA98();
extern "C" void FUN_002F3864(
    void*, void*, void*, std::uint32_t);
extern "C" void FUN_0013B944(void*);
extern "C" void* FUN_0022B868(std::uint32_t, std::uint32_t);
extern "C" void FUN_002A74C4(void*, void*, std::uint32_t, void*);
extern "C" std::uint32_t FUN_002F3FE0(void*, std::uint32_t);
extern "C" std::uint32_t FUN_00328204(void*);
extern "C" std::uint32_t FUN_0039FA2C(
    std::uint32_t, void*, std::uint32_t);
extern "C" std::uint32_t FUN_002A7224(std::uint16_t*, void*);
extern "C" std::uint32_t FUN_002A7468(void*);
extern "C" std::uint32_t FUN_00225CE4(void*);
extern "C" std::uint32_t FUN_001BA89C(void*);
extern "C" void FUN_003FCB34(std::uint32_t*, const void*);
extern "C" std::uint32_t FUN_0021FD1C(
    std::uint32_t, std::uint32_t, std::uint32_t);
extern "C" std::uint32_t FUN_0025809C();
extern "C" void FUN_002FACE8(void*, const void*, std::uint32_t);
extern "C" void FUN_002A3FDC(void*, const void*);
extern "C" std::uint8_t g_RenderDraw_PrepareGate_00D4DCF0;
extern "C" unsigned char g_RenderDraw_DirectState_00CB047C[];
extern "C" unsigned char g_RenderDraw_AlternateState_00CB0484[];
extern "C" void RenderDraw_SerializeDescriptor_00263270(
    void*, const void*, std::uint32_t);
extern "C" const std::uint16_t* FUN_0026D5AC();
extern "C" std::int32_t FUN_0026D5B8(std::int32_t);
extern "C" std::uint32_t FUN_002A7450(std::int32_t);
extern "C" const std::uint16_t* g_RenderDraw_DefaultLabel_00D4EFC0;
extern "C" void Engine_BulkCopy_00425DF8(
    void*, const void*, std::uint32_t);
extern "C" void FUN_0033233C(std::uint32_t, void*, std::uint32_t);
extern "C" void FUN_002A78D4(void*, const void*);
extern "C" void* MemoryFillEnd_003FDCAC(void*, std::uint32_t);
extern "C" void* FUN_003DC5D0(void*, std::uint32_t);
typedef void* (*RenderDrawMode2Lookup)(void*, std::uint32_t);
extern "C" unsigned char g_RenderDraw_Mode2Owner_00DC1DEC[];
extern "C" RenderDrawMode2Lookup g_RenderDraw_Mode2Table_00CB0414[];
namespace {
void BindDrawResource(void* packet, void* resource) {
    FUN_002A74C4(
        packet, resource, 1,
        static_cast<std::uint8_t*>(resource) + 0x48);
}
std::uint32_t FinishDrawPacket(void* packet) {
    if (FUN_00328204(static_cast<std::uint8_t*>(packet) + 0x108) != 0)
        return 6;
    return FUN_002F3FE0(packet, 1) == 0 ? 6 : 0;
}
}  // namespace
extern "C" __attribute__((noinline)) std::uint32_t
RenderDraw_BuildPacket_00225CF4(
    void* packet,
    std::uint32_t mode,
    const std::int32_t* source,
    std::uint32_t source_index) {
    if (FUN_00353C6C() == 0)
        return 1;
    const std::uint32_t source_magic = source == 0
        ? 0
        : static_cast<std::uint32_t>(source[0]);
    void* resource;
    switch (mode) {
    case 0:
        if (packet == 0 || source_index >= 100)
            return 2;
        resource = FUN_0022B868(source_index, 1);
        if (resource == 0)
            return 6;
        BindDrawResource(packet, resource);
        if (FUN_002F3FE0(packet, 1) == 0)
            return 6;
        return FinishDrawPacket(packet);
    case 2:
        if (source_index >= 6)
            return 2;
        resource = g_RenderDraw_Mode2Table_00CB0414[1](
            g_RenderDraw_Mode2Owner_00DC1DEC, source_index);
        BindDrawResource(packet, resource);
        return FinishDrawPacket(packet);
    case 3: {
        if (source == 0 || source_magic != 0x444d4643)
            return 2;
        const std::uint16_t count =
            *reinterpret_cast<const std::uint16_t*>(
                reinterpret_cast<const std::uint8_t*>(source) + 0x10);
        const std::uint16_t enabled =
            *reinterpret_cast<const std::uint16_t*>(
                reinterpret_cast<const std::uint8_t*>(source) + 0x12);
        if (source_index >= count || enabled == 0)
            return 6;
        resource = const_cast<std::uint8_t*>(
            reinterpret_cast<const std::uint8_t*>(source) +
            0x0c + source_index * 0x5c);
        if (FUN_00328204(static_cast<std::uint8_t*>(resource) + 0x0c) != 0)
            return 6;
        BindDrawResource(packet, resource);
        return FinishDrawPacket(packet);
    }
    case 4:
    case 5: {
        if (source == 0 || source_magic == 0x444d4643)
            return 2;
        resource = const_cast<std::uint8_t*>(
            reinterpret_cast<const std::uint8_t*>(source) +
            source_index * 0x60);
        if (FUN_0039FA2C(0, resource, 0x60) != 0)
            return 6;
        if (mode == 4) {
            std::uint16_t derived_index = 0;
            if (FUN_002A7224(
                    &derived_index,
                    static_cast<std::uint8_t*>(resource) + 0x0c) != 0) {
                if (packet == 0 || derived_index >= 100)
                    return 2;
                resource = FUN_0022B868(derived_index, 1);
                if (resource == 0)
                    return 6;
                BindDrawResource(packet, resource);
                if (FUN_002F3FE0(packet, 1) == 0)
                    return 6;
                return FinishDrawPacket(packet);
            }
        }
        BindDrawResource(packet, resource);
        return FinishDrawPacket(packet);
    }
    default:
        return 1;
    }
}
extern "C" __attribute__((noinline)) std::uint32_t
RenderDraw_InitRecordOwner_002630E8(
    void* owner, std::uint32_t count) {
    if (owner == 0 || count == 0 || count > 0x80)
        return 2;
    if (FUN_00353C6C() == 0)
        return 1;
    std::uint8_t* const bytes = static_cast<std::uint8_t*>(owner);
    MemoryFillEnd_003FDCAC(bytes, 0x18 + count * 0x70);
    *reinterpret_cast<std::uint32_t*>(bytes) = 0x42504643;
    *reinterpret_cast<std::uint16_t*>(bytes + 0x14) =
        static_cast<std::uint16_t>(count);
    *reinterpret_cast<std::uint16_t*>(bytes + 0x16) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 4) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 8) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x0c) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x10) = 0;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t
RenderDraw_PreparePacket_001BA8F4(void* packet) {
    std::uint8_t* const bytes = static_cast<std::uint8_t*>(packet);
    bool direct = false;
    if (FUN_002A7468(bytes + 0x108) != 0 &&
        FUN_00225CE4(bytes + 0x108) == 0) {
        direct = true;
        if (g_RenderDraw_PrepareGate_00D4DCF0 != 0) {
            const std::uint32_t requested_mode =
                *reinterpret_cast<std::uint32_t*>(bytes + 0xf4);
            if (requested_mode == 0)
                return 0;
            const std::uint32_t active_mode = FUN_0025809C();
            if ((requested_mode == 1 && active_mode == 0) ||
                (requested_mode == 2 && active_mode == 1) ||
                (requested_mode == 3 && active_mode == 2) ||
                requested_mode > 3)
                return 0;
        }
    } else {
        if (FUN_001BA89C(bytes + 0x118) != 0)
            return 0;
        std::uint32_t source[2];
        FUN_003FCB34(source, bytes + 0x118);
        if (FUN_0021FD1C(source[0], source[1], 0) == 0)
            return 0;
    }
    std::uint32_t saved_108[3] = {
        *reinterpret_cast<std::uint32_t*>(bytes + 0x108),
        *reinterpret_cast<std::uint32_t*>(bytes + 0x10c),
        *reinterpret_cast<std::uint32_t*>(bytes + 0x110),
    };
    const std::uint8_t saved_f0 = bytes[0xf0];
    const std::uint32_t saved_fc[2] = {
        *reinterpret_cast<std::uint32_t*>(bytes + 0xfc),
        *reinterpret_cast<std::uint32_t*>(bytes + 0x100),
    };
    const std::uint32_t saved_118[2] = {
        *reinterpret_cast<std::uint32_t*>(bytes + 0x118),
        *reinterpret_cast<std::uint32_t*>(bytes + 0x11c),
    };
    std::uint32_t resource_index = bytes[0x10b] % 3;
    if (*reinterpret_cast<std::uint32_t*>(bytes + 0xe0) == 1)
        resource_index += 3;
    void* const resource = g_RenderDraw_Mode2Table_00CB0414[1](
        g_RenderDraw_Mode2Owner_00DC1DEC, resource_index);
    BindDrawResource(packet, resource);
    const void* const state = direct
        ? static_cast<const void*>(g_RenderDraw_DirectState_00CB047C)
        : static_cast<const void*>(g_RenderDraw_AlternateState_00CB0484);
    FUN_002FACE8(bytes + 0xb4, state, 0x0b);
    if (!direct)
        FUN_002FACE8(bytes + 0xca, state, 0x0b);
    bytes[0xf0] = saved_f0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0xfc) = saved_fc[0];
    *reinterpret_cast<std::uint32_t*>(bytes + 0x100) = saved_fc[1];
    FUN_002A3FDC(bytes + 0x108, saved_108);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x118) = saved_118[0];
    *reinterpret_cast<std::uint32_t*>(bytes + 0x11c) = saved_118[1];
    return 1;
}
extern "C" __attribute__((noinline)) std::uint32_t
RenderDraw_BuildPreparedDescriptor_002630A4(
    void* destination,
    std::uint32_t mode,
    const std::int32_t* source,
    std::uint32_t source_index,
    std::uint32_t options) {
    std::uint32_t packet[0x48];
    const std::uint32_t status = RenderDraw_BuildPacket_00225CF4(
        packet, mode, source, source_index);
    if (status == 0) {
        RenderDraw_PreparePacket_001BA8F4(packet);
        RenderDraw_SerializeDescriptor_00263270(
            destination, packet, options);
    }
    return status;
}
extern "C" __attribute__((noinline)) std::uint32_t
RenderDraw_StorePacketRecord_00263158(
    void* owner,
    std::uint32_t index,
    std::uint32_t mode,
    const std::int32_t* source,
    std::uint32_t source_index) {
    if (owner == 0 ||
        index >= *reinterpret_cast<const std::uint16_t*>(
            static_cast<const std::uint8_t*>(owner) + 0x14) ||
        (mode != 0 && mode != 2 && mode != 4 && mode != 5)) {
        return 2;
    }
    std::uint8_t* const bytes = static_cast<std::uint8_t*>(owner);
    std::uint32_t* const occupancy =
        reinterpret_cast<std::uint32_t*>(bytes + 4) + index / 32;
    const std::uint32_t bit = 1u << (index % 32);
    *occupancy &= ~bit;
    if (FUN_00353C6C() == 0)
        return 1;
    std::uint32_t packet[0x49];
    const std::uint32_t status = RenderDraw_BuildPacket_00225CF4(
        packet, mode, source, source_index);
    if (status != 0)
        return status;
    std::uint8_t converted[0x5c];
    std::uint8_t scratch[0x18];
    FUN_002F3864(converted, scratch, packet, 1);
    *reinterpret_cast<std::uint16_t*>(converted + 0x18) &= ~0x4000u;
    std::uint8_t record[0x60];
    Engine_BulkCopy_00425DF8(record, converted, 0x5c);
    *reinterpret_cast<std::uint16_t*>(record + 0x5c) = 0;
    FUN_0033233C(0, record, 0x60);
    FUN_002A78D4(bytes + 0x18 + index * 0x70, record);
    *occupancy |= bit;
    return 0;
}
extern "C" __attribute__((noinline)) std::uint32_t
RenderDraw_InstallSingleRecord_0025F640(
    void* context, const std::int32_t* source) {
    std::uint8_t owner[0x88];
    FUN_003DC5D0(owner, sizeof(owner));
    if (RenderDraw_InitRecordOwner_002630E8(owner, 1) != 0)
        return 0;
    if (RenderDraw_StorePacketRecord_00263158(
            owner, 0, 4, source, 0) != 0) {
        return 0;
    }
    Engine_BulkCopy_00425DF8(
        static_cast<std::uint8_t*>(context) + 0x16604,
        owner,
        sizeof(owner));
    return 1;
}
extern "C" __attribute__((noinline)) void
RenderDraw_SerializeDescriptor_00263270(
    void* destination, const void* packet, std::uint32_t options) {
    std::uint8_t* const out = static_cast<std::uint8_t*>(destination);
    const std::uint8_t* const in = static_cast<const std::uint8_t*>(packet);
    std::uint16_t* const first = reinterpret_cast<std::uint16_t*>(out);
    std::uint16_t* const second =
        reinterpret_cast<std::uint16_t*>(out + 0x16);
    bool use_packet_labels = in[0xf2] == 0;
    if (!use_packet_labels) {
        const std::uint16_t* const alternate = FUN_0026D5AC();
        use_packet_labels = true;
        for (std::uint32_t i = 0; i < 4; ++i) {
            if (*reinterpret_cast<const std::uint16_t*>(
                    in + 0x118 + i * 2) != alternate[i]) {
                use_packet_labels = false;
                break;
            }
        }
    }
    if (use_packet_labels) {
        for (std::uint32_t i = 0; i < 10; ++i) {
            first[i] = *reinterpret_cast<const std::uint16_t*>(
                in + 0xb4 + i * 2);
            second[i] = *reinterpret_cast<const std::uint16_t*>(
                in + 0xca + i * 2);
        }
        first[10] = 0;
        second[10] = 0;
        for (std::uint32_t i = 0; i < 10 && first[i] != 0; ++i) {
            if (first[i] < 0x20 || first[i] == 0x7f)
                first[i] = '?';
        }
        for (std::uint32_t i = 0; i < 10 && second[i] != 0; ++i) {
            if (second[i] < 0x20 || second[i] == 0x7f)
                second[i] = '?';
        }
        if (options != 0) {
            const std::int32_t requested =
                *reinterpret_cast<const std::int32_t*>(in + 0xf8);
            const std::uint32_t active = FUN_0025809C();
            const bool compatible =
                (requested == 0 && active <= 3) ||
                (requested == 1 && active == 4) ||
                (requested == 2 && active == 5) ||
                (requested == 3 && active == 6);
            if (!compatible) {
                for (std::uint32_t i = 0; i < 10 && first[i] != 0; ++i) {
                    if (first[i] >= 0x80)
                        first[i] = '?';
                }
                for (std::uint32_t i = 0;
                     i < 10 && second[i] != 0;
                     ++i) {
                    if (second[i] >= 0x80)
                        second[i] = '?';
                }
            }
        }
    } else {
        FUN_002FACE8(first, g_RenderDraw_DefaultLabel_00D4EFC0, 0x0b);
        FUN_002FACE8(second, g_RenderDraw_DefaultLabel_00D4EFC0, 0x0b);
    }
    FUN_002A3FDC(out + 0x2c, in + 0x108);
    std::uint32_t packed =
        *reinterpret_cast<std::uint32_t*>(out + 0x38);
    packed = (packed & ~1u) |
        (*reinterpret_cast<const std::uint32_t*>(in + 0xe0) & 1u);
    const std::int32_t range =
        *reinterpret_cast<const std::int32_t*>(in + 0xe4);
    const std::int32_t value =
        *reinterpret_cast<const std::int32_t*>(in + 0xe8);
    const bool valid_range =
        (range == 0 && value == 0) ||
        (range != 0 && value != 0 &&
         static_cast<std::uint32_t>(range) - 1 < 12 &&
         value <= FUN_0026D5B8(range));
    if (valid_range) {
        packed = (packed & ~0x1eu) |
            ((static_cast<std::uint32_t>(range) & 0x0f) << 1);
        packed = (packed & ~0x3e0u) |
            ((static_cast<std::uint32_t>(value) & 0x1f) << 5);
    } else {
        packed &= ~0x3feu;
    }
    packed = (packed & ~0x3c00u) |
        ((*reinterpret_cast<const std::uint32_t*>(in + 0xec) & 0x0f)
         << 10);
    packed = (packed & ~0x4000u) |
        ((static_cast<std::uint32_t>(in[0xf0]) & 1) << 14);
    std::uint32_t first_scale =
        *reinterpret_cast<const std::uint32_t*>(in + 0xac) & 0xff;
    std::uint32_t second_scale =
        *reinterpret_cast<const std::uint32_t*>(in + 0xb0) & 0xff;
    if (first_scale > 0x7f)
        first_scale = 0x7f;
    if (second_scale > 0x7f)
        second_scale = 0x7f;
    packed = (packed & ~0x1fff8000u) |
        (first_scale << 15) | (second_scale << 22);
    if (in[0xf2] == 0)
        packed &= ~0x20000000u;
    else
        packed |= 0x20000000u;
    packed = (packed & 0x3fffffffu) |
        (*reinterpret_cast<const std::uint32_t*>(in + 0xf8) << 30);
    *reinterpret_cast<std::uint32_t*>(out + 0x38) = packed;
    std::uint16_t flags =
        *reinterpret_cast<std::uint16_t*>(out + 0x36);
    flags = (flags & 0xfff0u) |
        (*reinterpret_cast<const std::uint32_t*>(in + 0xfc) & 0x0f);
    flags = (flags & 0xff0fu) |
        ((*reinterpret_cast<const std::uint32_t*>(in + 0x100) & 0x0f)
         << 4);
    *reinterpret_cast<std::uint16_t*>(out + 0x36) = flags & 0x00ffu;
    std::uint32_t style =
        *reinterpret_cast<std::uint32_t*>(out + 0x3c);
    style = (style & ~0x0fu) |
        (*reinterpret_cast<const std::uint32_t*>(in + 4) & 0x0f);
    style = (style & ~0xff0u) |
        ((*reinterpret_cast<const std::uint32_t*>(in + 0x14) & 0xff)
         << 4);
    style = (style & ~0x1000u) |
        ((*reinterpret_cast<const std::uint32_t*>(in + 0x1c) & 1) << 12);
    *reinterpret_cast<std::uint32_t*>(out + 0x3c) = style & 0x1fffu;
    *reinterpret_cast<std::uint32_t*>(out + 0x40) = FUN_002A7450(
        *reinterpret_cast<const std::int32_t*>(in + 8));
}
extern "C" __attribute__((noinline)) std::uint8_t
RenderDraw_IsSubmissionAvailable_002A7080() {
    if (FUN_00353C6C() == 0 || FUN_00353C6C() == 0)
        return 0;
    const std::uintptr_t state =
        reinterpret_cast<std::uintptr_t>(FUN_0039FA98()) + 4;
    if (state == 0)
        return 0;
    return *reinterpret_cast<const std::uint8_t*>(state + 0xa8);
}
extern "C" __attribute__((noinline)) void
RenderDraw_CommitFallbackPacket_00113268(void* packet) {
    std::uint32_t fallback[0x13];
    FUN_002F3864(fallback, 0, packet, 0);
    FUN_0013B944(fallback);
}
extern "C" __attribute__((noinline))  std::uint32_t RenderDraw_BuildAndSubmit_0010B21C(
    void* context,
    std::uint32_t mode,
    const std::int32_t* source,
    std::uint32_t source_index,
    std::uint32_t view_index,
    const std::uint16_t* target_extent) {
    std::uint32_t packet[0x49];
    const std::uint32_t status = RenderDraw_BuildPacket_00225CF4(
        packet, mode, source, source_index);
    if (status != 0)
        return status;
    if (RenderDraw_IsSubmissionAvailable_002A7080() == 0)
        return 1;
    const std::uint32_t prepared = RenderDraw_PreparePacket_001BA8F4(packet);
    RenderDraw_SubmitPacket_00113294(
        context, packet, view_index, target_extent);
    if (prepared == 0 && mode != 0 && mode != 2)
        RenderDraw_CommitFallbackPacket_00113268(packet);
    return 0;
}
