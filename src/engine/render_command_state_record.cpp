#include <cstdint>
extern "C" std::uint8_t g_RenderCommand_Context_00DBC490[];
extern "C" std::uint8_t* g_RenderCommand_Cursor_00D4D134;
extern "C" std::uint8_t* g_RenderCommand_End_00D4D138;
extern "C" void* g_RenderCommand_AllocatorCallback_00D4D45C;
extern "C" std::uint8_t g_RenderCommand_TrackedRange_00D4DBE4[];
extern "C" std::uint32_t g_RenderState_GlobalSlots_00DC1CFC[];
extern "C" std::uint32_t g_RenderState_PackedActivationFloat_00D4DC38;
extern "C" void RenderState_ApplyEntry_00910CB4(
    void* target, const void* entry);
extern "C" void FUN_008DBFB8(void* state, std::uint32_t payload,
                              void* descriptor);
extern "C" void RenderState_BuildActivation_00910D74(
    void* target, void* resource, void* state);
extern "C" void* FUN_003DC5D0(void* destination, std::uint32_t size);
extern "C" void RenderCommand_SelectPacket_001ECE50(std::uint32_t key);
extern "C" void RenderCommand_QueryState_001B4F50(
    std::uint32_t selector, std::uint32_t** output);
extern "C" void RenderCommand_AdvanceAllocation_00153868(
    std::uint32_t bytes);
extern "C" void RenderCommand_Lock_0014DAC8();
extern "C" void RenderCommand_Unlock_0014DAD8();
extern "C" void RenderCommand_ExecutePending_003D8FB0();
namespace {
union FloatBits {
    float value;
    std::uint32_t bits;
};
__attribute__((always_inline)) inline std::uint32_t PackPicaFloat24(
    float value) {
    FloatBits converted = {value};
    const std::uint32_t sign = (converted.bits >> 31) << 23;
    const std::uint32_t magnitude = converted.bits & 0x7fffffffu;
    if (magnitude == 0)
        return sign;
    const std::int32_t exponent =
        static_cast<std::int32_t>(magnitude >> 23) - 0x40;
    if (exponent < 0)
        return sign;
    if (exponent > 0x7f)
        return 0x007f0000u;
    return sign | (static_cast<std::uint32_t>(exponent) << 16) |
           ((converted.bits & 0x007fffffu) >> 7);
}
__attribute__((always_inline)) inline std::uint32_t PackPicaFloat31(
    float value) {
    FloatBits converted = {value};
    const std::uint32_t sign = (converted.bits >> 31) << 30;
    const std::uint32_t magnitude = converted.bits & 0x7fffffffu;
    if (magnitude == 0)
        return sign << 1;
    const std::int32_t exponent =
        static_cast<std::int32_t>(magnitude >> 23) - 0x40;
    if (exponent < 0)
        return sign << 1;
    if (exponent > 0x7f)
        return 0x7f000000u;
    return (sign | (static_cast<std::uint32_t>(exponent) << 23) |
            (converted.bits & 0x007fffffu))
           << 1;
}
template <typename T>
T& RenderField(void* object, std::uint32_t offset) {
    return *reinterpret_cast<T*>(
        static_cast<std::uint8_t*>(object) + offset);
}
inline std::uint32_t PackFillSize(
    std::uint32_t old_value, std::uint32_t size, std::uint32_t bits) {
    std::uint32_t packed =
        (old_value & 0xff800000u) | (size & 0x007fffffu);
    if (bits == 16)
        packed &= ~0x01800000u;
    else if (bits == 24)
        packed = (packed & ~0x01800000u) | 0x00800000u;
    else if (bits == 32)
        packed = (packed & ~0x01800000u) | 0x01000000u;
    return packed;
}
}  // namespace
extern "C" __attribute__((noinline)) std::uint32_t* PicaCommand_EncodeViewport_00150890(
    std::uint32_t* output, std::uint32_t x, std::uint32_t y,
    std::int32_t width, std::int32_t height) {
    output[0] = PackPicaFloat24(static_cast<float>(width) * 0.5f);
    output[1] = 0x803f0041u;
    output[2] = PackPicaFloat31(2.0f / static_cast<float>(width));
    output[3] = PackPicaFloat24(static_cast<float>(height) * 0.5f);
    output[4] = PackPicaFloat31(2.0f / static_cast<float>(height));
    output[5] = 0;
    output[6] = (x & 0xffffu) | ((y & 0xffffu) << 16);
    output[7] = 0x000f0068u;
    return output + 8;
}
extern "C" __attribute__((noinline)) void PicaCommand_EmitViewport_0012BC44(
    void*, std::uint32_t x, std::uint32_t y,
    std::int32_t width, std::int32_t height) {
    std::uint32_t* output;
    RenderCommand_QueryState_001B4F50(0x208, &output);
    std::uint32_t* end =
        PicaCommand_EncodeViewport_00150890(output, x, y, width, height);
    RenderCommand_AdvanceAllocation_00153868(
        static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(end) -
            reinterpret_cast<std::uintptr_t>(output)) &
        ~3u);
}
extern "C" __attribute__((noinline)) void RenderCommand_ResetAllocation_001688F0() {
    std::uint8_t* context = g_RenderCommand_Context_00DBC490;
    std::uint8_t* packet = *reinterpret_cast<std::uint8_t**>(context + 0x9c);
    if (packet == 0 ||
        (*reinterpret_cast<void**>(packet + 4) == 0 &&
         *reinterpret_cast<void**>(packet + 0x18) == 0))
        return;
    FUN_003DC5D0(*reinterpret_cast<void**>(packet + 0x18),
                 *reinterpret_cast<std::uint32_t*>(packet + 0x20) * 4);
    *reinterpret_cast<std::uint32_t*>(packet + 0x0c) = 0;
    *reinterpret_cast<std::uint32_t*>(packet + 0x10) = 0;
    *reinterpret_cast<std::uint32_t*>(packet + 0x20) = 0;
    *reinterpret_cast<std::uint32_t*>(packet + 0x28) = 0;
    *reinterpret_cast<std::uint32_t*>(packet + 0x14) = 0;
    *reinterpret_cast<std::uint32_t*>(packet + 0x24) = 0;
    *reinterpret_cast<std::uint32_t*>(packet + 0x34) = 0;
    *reinterpret_cast<std::uint32_t*>(packet + 0x30) = 0;
    g_RenderCommand_Cursor_00D4D134 =
        *reinterpret_cast<std::uint8_t**>(packet + 4);
    g_RenderCommand_End_00D4D138 =
        g_RenderCommand_Cursor_00D4D134 +
        *reinterpret_cast<std::uint32_t*>(packet + 8);
}
extern "C" __attribute__((noinline)) void RenderCommand_FinalizeSelection_0018BDAC() {
    std::uint8_t* context = g_RenderCommand_Context_00DBC490;
    std::uint8_t* packet = *reinterpret_cast<std::uint8_t**>(context + 0x9c);
    std::uint8_t* base = *reinterpret_cast<std::uint8_t**>(packet + 4);
    const std::uint32_t byte_count = static_cast<std::uint32_t>(
        g_RenderCommand_Cursor_00D4D134 - base);
    *reinterpret_cast<std::uint32_t*>(packet + 0x0c) = byte_count;
    if ((byte_count & 8) != 0 &&
        g_RenderCommand_Cursor_00D4D134 < g_RenderCommand_End_00D4D138) {
        std::uint32_t* output = reinterpret_cast<std::uint32_t*>(
            g_RenderCommand_Cursor_00D4D134);
        output[0] = 0;
        output[1] = 0x0008025e;
        g_RenderCommand_Cursor_00D4D134 += 8;
    }
    context[0x13] = 1;
    *reinterpret_cast<std::uint32_t*>(context + 0x168) =
        static_cast<std::uint32_t>(g_RenderCommand_Cursor_00D4D134 - base);
    *reinterpret_cast<std::uint32_t*>(context + 0x16c) =
        *reinterpret_cast<std::uint32_t*>(packet + 0x20);
}
extern "C" __attribute__((noinline)) void RenderResource_SelectPacketAndFinalize_0018BD80(
    void* resource) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    const std::uint32_t active = *reinterpret_cast<std::uint32_t*>(bytes + 0x6c);
    RenderCommand_SelectPacket_001ECE50(
        *reinterpret_cast<std::uint32_t*>(bytes + 0x64 + active * 4));
    if (bytes[0x80] == 1)
        RenderCommand_ResetAllocation_001688F0();
    RenderCommand_FinalizeSelection_0018BDAC();
}
extern "C" __attribute__((noinline)) void RenderCommand_AppendMemoryFillRecord_001687B0(
    std::uint32_t first_address, std::uint32_t first_size,
    std::uint32_t first_value, std::uint32_t first_bits,
    std::uint32_t second_address, std::uint32_t second_size,
    std::uint32_t second_value, std::uint32_t second_bits) {
    std::uint8_t* context = g_RenderCommand_Context_00DBC490;
    std::uint8_t* ring =
        *reinterpret_cast<std::uint8_t**>(context + 0x9c);
    const std::uint32_t index =
        *reinterpret_cast<std::uint32_t*>(ring + 0x20);
    std::uint8_t* record =
        *reinterpret_cast<std::uint8_t**>(ring + 0x18) + index * 0x1c;
    record[0] = 2;
    *reinterpret_cast<std::uint32_t*>(record + 0x04) = first_address;
    *reinterpret_cast<std::uint32_t*>(record + 0x08) = first_value;
    *reinterpret_cast<std::uint32_t*>(record + 0x0c) = PackFillSize(
        *reinterpret_cast<std::uint32_t*>(record + 0x0c),
        first_size, first_bits);
    *reinterpret_cast<std::uint32_t*>(record + 0x10) = second_address;
    *reinterpret_cast<std::uint32_t*>(record + 0x14) = second_value;
    *reinterpret_cast<std::uint32_t*>(record + 0x18) = PackFillSize(
        *reinterpret_cast<std::uint32_t*>(record + 0x18),
        second_size, second_bits);
    RenderCommand_Lock_0014DAC8();
    *reinterpret_cast<std::uint32_t*>(ring + 0x20) = index + 1;
    if (*reinterpret_cast<std::uint8_t**>(context + 0xa0) == ring &&
        context[0x12] != 0 && context[0x11] == 0) {
        context[0x11] = 1;
        RenderCommand_ExecutePending_003D8FB0();
    }
    RenderCommand_Unlock_0014DAD8();
}
extern "C" __attribute__((noinline)) void RenderState_EmitMemoryFillCommand_00150684(
    void* target, std::uint32_t flags,
    std::int32_t red, std::int32_t green,
    std::int32_t blue, std::int32_t alpha,
    float depth, std::uint32_t stencil) {
    std::uint32_t first_address = 0;
    std::uint32_t first_size = 0;
    std::uint32_t first_value = 0;
    std::uint32_t first_bits = 0;
    std::uint32_t second_address = 0;
    std::uint32_t second_size = 0;
    std::uint32_t second_value = 0;
    std::uint32_t second_bits = 0;
    if ((flags & 1u) != 0) {
        first_address = RenderField<std::uint32_t>(target, 0x08);
        const std::uint32_t format =
            RenderField<std::uint32_t>(target, 0x10);
        if (format == 0x8058u || format == 0x6050u) {
            first_bits = 32;
            first_value =
                (static_cast<std::uint32_t>(red) << 24) |
                (static_cast<std::uint32_t>(green) << 16) |
                (static_cast<std::uint32_t>(blue) << 8) |
                static_cast<std::uint32_t>(alpha);
        } else if (format == 0x8057u) {
            first_bits = 16;
            const std::uint32_t value =
                (static_cast<std::uint32_t>(red >> 3) << 11) |
                (static_cast<std::uint32_t>(green >> 3) << 6) |
                (static_cast<std::uint32_t>(blue >> 3) << 1) |
                static_cast<std::uint32_t>(alpha > 0x7f);
            first_value = (value & 0xffffu) | (value << 16);
        } else if (format == 0x8d62u) {
            first_bits = 16;
            const std::uint32_t value =
                (static_cast<std::uint32_t>(red >> 3) << 11) |
                (static_cast<std::uint32_t>(green >> 2) << 6) |
                static_cast<std::uint32_t>(blue >> 3);
            first_value = (value & 0xffffu) | (value << 16);
        } else if (format == 0x8056u) {
            first_bits = 16;
            const std::uint32_t value =
                (static_cast<std::uint32_t>(red >> 4) << 12) |
                (static_cast<std::uint32_t>(green >> 4) << 8) |
                (static_cast<std::uint32_t>(blue) & 0xf0u) |
                static_cast<std::uint32_t>(alpha >> 4);
            first_value = (value & 0xffffu) | (value << 16);
        }
        first_size =
            (RenderField<std::uint32_t>(target, 0x18) *
             RenderField<std::uint32_t>(target, 0x1c) * first_bits) >> 3;
    }
    if ((flags & 2u) != 0) {
        second_address = RenderField<std::uint32_t>(target, 0x0c);
        if (second_address != 0) {
            const std::uint32_t format =
                RenderField<std::uint32_t>(target, 0x14);
            if (format == 0x81a5u) {
                second_bits = 16;
                const std::uint32_t value =
                    static_cast<std::uint32_t>(depth * 65535.0f);
                second_value = (value & 0xffffu) | (value << 16);
            } else if (format == 0x81a6u) {
                second_bits = 24;
                second_value =
                    static_cast<std::uint32_t>(depth * 16777215.0f);
            } else if (format == 0x88f0u) {
                second_bits = 32;
                second_value =
                    static_cast<std::uint32_t>(depth * 16777215.0f) |
                    (stencil << 24);
            }
            second_size =
                (RenderField<std::uint32_t>(target, 0x18) *
                 RenderField<std::uint32_t>(target, 0x1c) * second_bits) >> 3;
        }
    }
    if (first_address != 0 || second_address != 0) {
        RenderCommand_AppendMemoryFillRecord_001687B0(
            first_address, first_size, first_value, first_bits,
            second_address, second_size, second_value, second_bits);
    }
}
extern "C" __attribute__((noinline)) void RenderState_EmitScissorCommand_00916320(
    void* targets, std::uint32_t enabled,
    const std::int32_t* rectangle, std::uint32_t slot) {
    std::uint8_t* target = RenderField<std::uint8_t*>(
        targets, 0x10 + slot * 0x10);
    const std::int32_t target_height =
        RenderField<std::int32_t>(target, 0x18);
    const std::int32_t target_width =
        RenderField<std::int32_t>(target, 0x1c);
    std::uint32_t* output = 0;
    RenderCommand_QueryState_001B4F50(0x208u, &output);
    output[0] = enabled != 0 ? 3u : 0u;
    output[1] = 0x802f0065u;
    std::int32_t x = rectangle[0];
    if (x < 0)
        x = 0;
    else if (x >= target_width)
        x = target_width - 1;
    std::int32_t y = rectangle[1];
    if (y < 0)
        y = 0;
    else if (y >= target_height)
        y = target_height - 1;
    output[2] = static_cast<std::uint32_t>(x) |
                (static_cast<std::uint32_t>(y) << 16);
    const std::int32_t end_x = rectangle[0] + rectangle[2] - 1;
    const std::int32_t end_y = rectangle[1] + rectangle[3] - 1;
    output[3] = end_x < 0 ? 0u :
        static_cast<std::uint32_t>(end_x) |
        (static_cast<std::uint32_t>(end_y < 0 ? 0 : end_y) << 16);
    RenderCommand_AdvanceAllocation_00153868(16);
}
extern "C" __attribute__((noinline)) void RenderState_EmitPassScissor_009100D8(
    void* pass, std::int32_t x, std::int32_t y,
    std::int32_t width, std::int32_t height) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(pass);
    const std::uint32_t slot =
        *reinterpret_cast<std::uint32_t*>(bytes + 0x210);
    std::uint8_t* target = bytes + 0x150 + slot * 0x30;
    const std::int32_t target_width =
        *reinterpret_cast<std::int32_t*>(target + 0x08);
    const std::int32_t target_height =
        *reinterpret_cast<std::int32_t*>(target + 0x0c);
    const std::int32_t vertical_trim =
        target_height - (y + height) < 0 ? 0 :
        target_height - (y + height);
    const std::int32_t horizontal_trim =
        target_width - (x + width) < 0 ? 0 :
        target_width - (x + width);
    const std::int32_t rectangle[4] = {
        vertical_trim,
        horizontal_trim,
        target_height - y - vertical_trim,
        target_width - x - horizontal_trim,
    };
    RenderState_EmitScissorCommand_00916320(pass, 1, rectangle, slot);
}
extern "C" __attribute__((noinline)) void RenderCommand_CopyState_001131F4(
    std::uint32_t* dst_words, const std::uint32_t* src_words,
    std::uint32_t header) {
    struct StateBlock { float value[16]; };
    const StateBlock src = *reinterpret_cast<const StateBlock*>(src_words);
    float* const dst = reinterpret_cast<float*>(dst_words);
    dst_words[1] = header;
    dst[4] = src.value[0];
    dst[3] = src.value[1];
    dst[2] = src.value[2];
    dst[0] = src.value[3];
    dst[8] = src.value[4];
    dst[7] = src.value[5];
    dst[6] = src.value[6];
    dst[5] = src.value[7];
    dst[12] = src.value[8];
    dst[11] = src.value[9];
    dst[10] = src.value[10];
    dst[9] = src.value[11];
    dst[16] = src.value[12];
    dst[15] = src.value[13];
    dst[14] = src.value[14];
    dst[13] = src.value[15];
}
// Retail 0x008DD2A0: publish and clear one tracked command-word range.
extern "C" __attribute__((noinline)) void RenderCommand_FinalizeTrackedRange_008DD2A0() {
    std::uint8_t* state = g_RenderCommand_TrackedRange_00D4DBE4;
    std::uint32_t* output =
        *reinterpret_cast<std::uint32_t**>(state + 0x08);
    if (output != 0) {
        std::uint8_t* begin = *reinterpret_cast<std::uint8_t**>(state + 0x04);
        *output = static_cast<std::uint32_t>(
            (reinterpret_cast<std::uintptr_t>(
                 g_RenderCommand_Cursor_00D4D134) -
             reinterpret_cast<std::uintptr_t>(begin)) >> 3);
    }
    *reinterpret_cast<std::uint8_t**>(state + 0x04) = 0;
    *reinterpret_cast<std::uint32_t**>(state + 0x08) = 0;
}
// Retail 0x0018BE38: snapshot the current packet's byte/record ranges.
extern "C" __attribute__((noinline)) void RenderCommand_CaptureCurrentRange_0018BE38(
    std::uint32_t* byte_offset, std::uint32_t* byte_size,
    std::uint32_t* record_offset, std::uint32_t* record_count) {
    std::uint8_t* context = g_RenderCommand_Context_00DBC490;
    context[0x13] = 0;
    std::uint8_t* packet = *reinterpret_cast<std::uint8_t**>(context + 0x9c);
    std::uint8_t* base = *reinterpret_cast<std::uint8_t**>(packet + 0x04);
    std::uint32_t size = static_cast<std::uint32_t>(
        g_RenderCommand_Cursor_00D4D134 - base);
    *reinterpret_cast<std::uint32_t*>(packet + 0x0c) = size;
    if ((size & 8u) != 0 &&
        g_RenderCommand_Cursor_00D4D134 < g_RenderCommand_End_00D4D138) {
        std::uint32_t* cursor = reinterpret_cast<std::uint32_t*>(
            g_RenderCommand_Cursor_00D4D134);
        cursor[0] = 0;
        cursor[1] = 0x0008025e;
        g_RenderCommand_Cursor_00D4D134 += 8;
    }
    const std::uint32_t byte_begin =
        *reinterpret_cast<std::uint32_t*>(context + 0x168);
    *byte_offset = byte_begin;
    *byte_size = static_cast<std::uint32_t>(
        g_RenderCommand_Cursor_00D4D134 - base) - byte_begin;
    const std::uint32_t record_begin =
        *reinterpret_cast<std::uint32_t*>(context + 0x16c);
    *record_offset = record_begin;
    *record_count =
        *reinterpret_cast<std::uint32_t*>(packet + 0x20) - record_begin;
}
// Retail 0x001ECE50: select or create one keyed command packet.
extern "C" __attribute__((noinline)) void RenderCommand_SelectPacket_001ECE50(std::uint32_t key) {
    typedef void* (*Allocate)(std::uint32_t, std::uint32_t, std::uint32_t,
                              std::uint32_t);
    std::uint8_t* context = g_RenderCommand_Context_00DBC490;
    std::uint8_t** head = reinterpret_cast<std::uint8_t**>(
        context + 0x1c + (key & 0x1fu) * sizeof(void*));
    std::uint8_t* packet = *head;
    while (packet != 0 &&
           *reinterpret_cast<std::uint32_t*>(packet) != key) {
        packet = *reinterpret_cast<std::uint8_t**>(packet + 0x40);
    }
    if (packet == 0 && key != 0) {
        Allocate allocate = reinterpret_cast<Allocate>(
            g_RenderCommand_AllocatorCallback_00D4D45C);
        if (allocate != 0)
            packet = static_cast<std::uint8_t*>(
                allocate(0x10000, 0x100, 0, 0x44));
        FUN_003DC5D0(packet, 0x44);
        *reinterpret_cast<std::uint32_t*>(packet + 0x2c) = 0x300;
        *reinterpret_cast<std::uint32_t*>(packet) = key;
        std::uint8_t** link = head;
        while (*link != 0 &&
               *reinterpret_cast<std::uint32_t*>(*link) <= key) {
            link = reinterpret_cast<std::uint8_t**>(*link + 0x40);
        }
        *reinterpret_cast<std::uint8_t**>(packet + 0x40) = *link;
        *link = packet;
    }
    std::uint8_t* previous =
        *reinterpret_cast<std::uint8_t**>(context + 0x9c);
    if (previous != 0) {
        std::uint8_t* previous_base =
            *reinterpret_cast<std::uint8_t**>(previous + 0x04);
        *reinterpret_cast<std::uint32_t*>(previous + 0x0c) =
            static_cast<std::uint32_t>(g_RenderCommand_Cursor_00D4D134 -
                                       previous_base);
    }
    *reinterpret_cast<std::uint8_t**>(context + 0x9c) = packet;
    if (packet != 0 &&
        *reinterpret_cast<std::uint8_t**>(packet + 0x04) != 0) {
        std::uint8_t* base =
            *reinterpret_cast<std::uint8_t**>(packet + 0x04);
        g_RenderCommand_Cursor_00D4D134 =
            base + *reinterpret_cast<std::uint32_t*>(packet + 0x0c);
        g_RenderCommand_End_00D4D138 =
            base + *reinterpret_cast<std::uint32_t*>(packet + 0x08);
    } else {
        g_RenderCommand_Cursor_00D4D134 = 0;
        g_RenderCommand_End_00D4D138 = 0;
    }
}
// Retail 0x008E141C: clear the shared 24-word render-state slot table.
extern "C" __attribute__((noinline)) void RenderState_ClearGlobalSlots_008E141C() {
    int i = 0;
    do {
        g_RenderState_GlobalSlots_00DC1CFC[i] = 0;
        ++i;
    } while (i < 24);
}
// Retail 0x00188EF0: invalidate the slots selected by the packed mask.
extern "C" __attribute__((noinline)) void RenderState_InvalidateMaskedSlots_00188EF0(
    std::uint32_t* slots, std::uint32_t mask) {
    if ((mask & 0x001) == 0) slots[0] = 0xffffffffu;
    if ((mask & 0x002) == 0) slots[1] = 0xffffffffu;
    if ((mask & 0x004) == 0) slots[2] = 0xffffffffu;
    if ((mask & 0x008) == 0) slots[3] = 0xffffffffu;
    if ((mask & 0x010) == 0) slots[4] = 0xffffffffu;
    if ((mask & 0x020) == 0) slots[5] = 0xffffffffu;
    if ((mask & 0x080) == 0) slots[6] = 0xffffffffu;
    if ((mask & 0x100) == 0) slots[7] = 0xffffffffu;
    if ((mask & 0x200) == 0) slots[8] = 0xffffffffu;
    if ((mask & 0x800) == 0) slots[9] = 0xffffffffu;
    if ((mask & 0x400) == 0) slots[10] = 0xffffffffu;
}
// Retail 0x008E3E78: restore one nested render-state record to defaults.
extern "C" __attribute__((noinline)) void RenderState_ResetNested_008E3E78(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x9c) = 0xffffffffu;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x00) = 0;
    bytes[0xa9] = 1;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x04) = 0;
    bytes[0xab] = 1;
    std::uint32_t count = *reinterpret_cast<std::uint32_t*>(bytes + 0xa4);
    std::uint32_t* entries =
        *reinterpret_cast<std::uint32_t**>(bytes + 0x24);
    for (std::uint32_t i = 0; i < count; ++i)
        entries[i] = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0xa4) = 0;
    bytes[0xa8] = 1;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x60) = 0;
    bytes[0xac] = 1;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x64) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x78) = 0xffffffffu;
}
// Retail body entry 0x008DE5AC, reached by the public wrapper at 0x00911340.
extern "C" __attribute__((noinline)) void RenderState_DeactivateBody_008DE5AC(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x20) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x24) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x38) = 0;
    bytes[0x3c] = 0;
    RenderState_ResetNested_008E3E78(bytes + 0x40);
    bytes[0x12] = 1;
    std::uint8_t* child = *reinterpret_cast<std::uint8_t**>(bytes + 0x08);
    child[0x14] = 0;
    *reinterpret_cast<std::uint32_t*>(child + 0x0c) = 0;
    *reinterpret_cast<std::uint32_t*>(child + 0x10) = 0;
    *reinterpret_cast<std::uint32_t*>(child + 0x08) = 0;
    RenderState_ClearGlobalSlots_008E141C();
    RenderState_InvalidateMaskedSlots_00188EF0(
        reinterpret_cast<std::uint32_t*>(bytes + 0x100), 0x1fffu);
    bytes[0x150] = 0;
    bytes[0x14] = 0;
}
// Retail 0x008DE7B4: clear a released resource state and mark its caches dirty.
extern "C" __attribute__((noinline)) void RenderResource_Release_008DE7B4(void* state) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(state);
    *reinterpret_cast<std::uint32_t*>(bytes + 0x20) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x24) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x28) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x2c) = 0;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x38) = 0;
    bytes[0x3c] = 0;
    bytes[0xec] = 1;
    bytes[0xe9] = 1;
    bytes[0xe8] = 1;
    bytes[0xeb] = 1;
    bytes[0x12] = 1;
    std::uint8_t* child = *reinterpret_cast<std::uint8_t**>(bytes + 0x08);
    child[0x14] = 0;
    *reinterpret_cast<std::uint32_t*>(child + 0x0c) = 0;
    *reinterpret_cast<std::uint32_t*>(child + 0x10) = 0;
    *reinterpret_cast<std::uint32_t*>(child + 0x08) = 0;
    RenderState_ClearGlobalSlots_008E141C();
    RenderState_InvalidateMaskedSlots_00188EF0(
        reinterpret_cast<std::uint32_t*>(bytes + 0x100), 0x1fffu);
    bytes[0x150] = 0;
    bytes[0x14] = 0;
}
// Retail 0x00910CB4: dispatch one packed render-state entry.
extern "C" __attribute__((noinline)) void RenderState_ApplyEntry_00910CB4(
    void* target, const void* entry) {
    typedef void (*DirectDispatch)(void*, void*);
    typedef void (*CallbackDispatch)(void*, void*, std::uint32_t, void*);
    std::uint8_t* target_bytes = static_cast<std::uint8_t*>(target);
    const std::uint8_t* entry_bytes = static_cast<const std::uint8_t*>(entry);
    void* context = *reinterpret_cast<void**>(target_bytes + 0x28);
    std::uint32_t flags =
        *reinterpret_cast<const std::uint32_t*>(entry_bytes + 0x04);
    if ((flags & 0x00200000u) != 0) {
        void* object = *reinterpret_cast<void* const*>(entry_bytes + 0x00);
        void** vtable = *reinterpret_cast<void***>(object);
        reinterpret_cast<DirectDispatch>(vtable[0])(object, context);
        return;
    }
    std::uint32_t payload =
        *reinterpret_cast<const std::uint32_t*>(entry_bytes + 0x08);
    void* descriptor =
        *reinterpret_cast<void* const*>(entry_bytes + 0x0c);
    std::uint8_t* descriptor_bytes = static_cast<std::uint8_t*>(descriptor);
    void* callback_list =
        *reinterpret_cast<void**>(descriptor_bytes + 0x158);
    void** callback = *reinterpret_cast<void***>(
        static_cast<std::uint8_t*>(callback_list) + 0x08);
    void** callback_end = *reinterpret_cast<void***>(
        static_cast<std::uint8_t*>(callback_list) + 0x0c);
    for (; callback != callback_end; ++callback) {
        void** vtable = *reinterpret_cast<void***>(*callback);
        reinterpret_cast<CallbackDispatch>(vtable[0])(
            *callback, descriptor, payload, context);
    }
    FUN_008DBFB8(*reinterpret_cast<void**>(target_bytes + 0x30), payload,
                  descriptor);
    callback_list = *reinterpret_cast<void**>(descriptor_bytes + 0x15c);
    callback = *reinterpret_cast<void***>(
        static_cast<std::uint8_t*>(callback_list) + 0x08);
    callback_end = *reinterpret_cast<void***>(
        static_cast<std::uint8_t*>(callback_list) + 0x0c);
    context = *reinterpret_cast<void**>(target_bytes + 0x28);
    for (; callback != callback_end; ++callback) {
        void** vtable = *reinterpret_cast<void***>(*callback);
        reinterpret_cast<CallbackDispatch>(vtable[0])(
            *callback, descriptor, payload, context);
    }
}
// Retail 0x00910D74: rebuild the nested activation-record arrays.
extern "C" __attribute__((noinline)) void RenderState_BuildActivation_00910D74(
    void* target, void* resource, void* state) {
    typedef void* (*Allocate)(void*, std::uint32_t, std::uint32_t);
    typedef void (*Release)(void*, void*);
    std::uint8_t* target_bytes = static_cast<std::uint8_t*>(target);
    std::uint8_t* resource_bytes = static_cast<std::uint8_t*>(resource);
    std::uint8_t* state_bytes = static_cast<std::uint8_t*>(state);
    std::uint32_t entry_count =
        *reinterpret_cast<std::uint32_t*>(target_bytes + 0x4c);
    std::uint8_t* entries =
        *reinterpret_cast<std::uint8_t**>(resource_bytes + 0x8c);
    void** output = *reinterpret_cast<void***>(state_bytes + 0x90);
    for (std::uint32_t entry_index = 0; entry_index < entry_count;
         ++entry_index) {
        std::uint8_t* entry = entries + entry_index * 0x30;
        std::uint8_t* record = *reinterpret_cast<std::uint8_t**>(entry);
        if (entry[0x2c] != 0) {
            *reinterpret_cast<std::uint32_t*>(record + 0x0c) = 0;
            *reinterpret_cast<std::uint32_t*>(record + 0x10) = 0;
            *reinterpret_cast<std::uint32_t*>(record + 0x1c) =
                *reinterpret_cast<std::uint32_t*>(record + 0x18);
            *reinterpret_cast<std::uint32_t**>(record + 0x48) =
                *reinterpret_cast<std::uint32_t**>(record + 0x44);
            std::int32_t aux_index =
                *reinterpret_cast<std::int32_t*>(entry + 0x24);
            if (aux_index >= 0)
                *reinterpret_cast<std::uint32_t*>(record + 0x0c) =
                    *reinterpret_cast<std::uint32_t*>(
                        resource_bytes + 0x98 + aux_index * 4);
            aux_index = *reinterpret_cast<std::int32_t*>(entry + 0x28);
            if (aux_index >= 0)
                *reinterpret_cast<std::uint32_t*>(record + 0x10) =
                    *reinterpret_cast<std::uint32_t*>(
                        resource_bytes + 0xa8 + aux_index * 4);
            for (int pair_slot = 0; pair_slot < 8; ++pair_slot) {
                std::int32_t pair_index =
                    *reinterpret_cast<std::int32_t*>(
                        entry + 0x04 + pair_slot * 4);
                if (pair_index < 0)
                    continue;
                std::uint32_t* pair =
                    *reinterpret_cast<std::uint32_t**>(resource_bytes + 0x94) +
                    pair_index * 2;
                std::uint32_t value = pair[0] != 0 ? pair[0] : pair[1];
                void* allocator = *reinterpret_cast<void**>(record + 0x40);
                std::uint32_t* begin =
                    *reinterpret_cast<std::uint32_t**>(record + 0x44);
                std::uint32_t* end =
                    *reinterpret_cast<std::uint32_t**>(record + 0x48);
                std::uint32_t capacity_flags =
                    *reinterpret_cast<std::uint32_t*>(record + 0x4c);
                std::uint32_t capacity = capacity_flags & 0x3fffffffu;
                if (static_cast<std::int32_t>(capacity) <= end - begin) {
                    std::uint32_t requested =
                        capacity == 0 ? 1u : capacity << 1;
                    if (static_cast<std::int32_t>(capacity) <
                        static_cast<std::int32_t>(requested)) {
                        if (allocator == 0 ||
                            (capacity_flags & 0xc0000000u) != 0x40000000u)
                            continue;
                        void** vtable = *reinterpret_cast<void***>(allocator);
                        Allocate allocate =
                            reinterpret_cast<Allocate>(vtable[2]);
                        Release release =
                            reinterpret_cast<Release>(vtable[3]);
                        std::uint32_t* replacement =
                            static_cast<std::uint32_t*>(
                                allocate(allocator, requested * 4, 4));
                        std::int32_t old_count = 0;
                        if (begin != end) {
                            std::uint32_t* destination = replacement;
                            for (std::uint32_t* source = begin; source != end;
                                 ++source, ++destination) {
                                if (destination != 0)
                                    *destination = *source;
                            }
                            old_count = static_cast<std::int32_t>(end - begin);
                        }
                        if (begin != 0)
                            release(allocator, begin);
                        begin = replacement;
                        end = replacement + old_count;
                        capacity_flags =
                            (capacity_flags & 0xc0000000u) | requested;
                        *reinterpret_cast<std::uint32_t**>(record + 0x44) =
                            begin;
                        *reinterpret_cast<std::uint32_t**>(record + 0x48) = end;
                        *reinterpret_cast<std::uint32_t*>(record + 0x4c) =
                            capacity_flags;
                    }
                }
                if (end != 0)
                    *end = value;
                *reinterpret_cast<std::uint32_t**>(record + 0x48) = end + 1;
            }
            entry[0x2c] = 0;
        }
        output[entry_index] = record;
    }
    std::uint32_t* final_state =
        *reinterpret_cast<std::uint32_t**>(state_bytes + 0x80);
    for (std::uint32_t index = 0; index < 16; ++index)
        final_state[index] =
            *reinterpret_cast<std::uint32_t*>(resource_bytes + 0xb8 +
                                              index * 0x0c);
}
// Retail 0x00911348: build and select an active resource state.
extern "C" __attribute__((noinline)) void RenderState_Activate_00911348(void* target, void* resource) {
    std::uint8_t* target_bytes = static_cast<std::uint8_t*>(target);
    std::uint8_t* resource_bytes = static_cast<std::uint8_t*>(resource);
    std::uint8_t* state =
        *reinterpret_cast<std::uint8_t**>(target_bytes + 0x28);
    std::uint8_t* nested = state + 0x40;
    RenderState_BuildActivation_00910D74(target, resource, nested);
    std::uint32_t* selection =
        *reinterpret_cast<std::uint32_t**>(nested + 0x6c);
    selection[0] = *reinterpret_cast<std::uint32_t*>(resource_bytes + 0x08);
    selection[1] = *reinterpret_cast<std::uint32_t*>(resource_bytes + 0x178);
    state = *reinterpret_cast<std::uint8_t**>(target_bytes + 0x28);
    std::uint8_t* selected = **reinterpret_cast<std::uint8_t***>(state + 0xac);
    *reinterpret_cast<std::uint32_t*>(state + 0xb8) = 0;
    if (*reinterpret_cast<std::uint8_t**>(state + 0xa4) == selected)
        return;
    *reinterpret_cast<std::uint8_t**>(state + 0xa4) = selected;
    float value = *reinterpret_cast<float*>(selected + 0x2c4);
    if (value == 0.0f) {
        g_RenderState_PackedActivationFloat_00D4DC38 = 0;
        return;
    }
    union {
        float as_float;
        std::uint32_t as_uint;
    } bits;
    bits.as_float = -value;
    std::uint32_t sign =
        (bits.as_uint & 0x80000000u) != 0 ? 0x800000u : 0;
    int exponent = static_cast<int>((bits.as_uint >> 23) & 0xffu) - 0x40;
    if (exponent < 0) {
        g_RenderState_PackedActivationFloat_00D4DC38 = sign;
    } else if (exponent > 0x7f) {
        g_RenderState_PackedActivationFloat_00D4DC38 = 0x7f0000u;
    } else {
        g_RenderState_PackedActivationFloat_00D4DC38 =
            sign | (static_cast<std::uint32_t>(exponent) << 16) |
            ((bits.as_uint & 0x7fffffu) >> 7);
    }
}
// Retail 0x00911340: tail wrapper selecting the embedded state at +0x28.
extern "C" __attribute__((noinline)) void RenderState_Deactivate_00911340(void* target) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(target);
    RenderState_DeactivateBody_008DE5AC(
        *reinterpret_cast<void**>(bytes + 0x28));
}
// Retail 0x00911424: apply each 0x10-byte entry while the target is active.
extern "C" __attribute__((noinline)) void RenderState_Commit_00911424(void* target, void* list) {
    std::uint8_t* target_bytes = static_cast<std::uint8_t*>(target);
    std::uint8_t* state =
        *reinterpret_cast<std::uint8_t**>(target_bytes + 0x28);
    state[0x151] = target_bytes[0x4e1];
    std::uint8_t* list_bytes = static_cast<std::uint8_t*>(list);
    std::uint8_t* entry = *reinterpret_cast<std::uint8_t**>(list_bytes + 0x0c);
    std::uint8_t* end = *reinterpret_cast<std::uint8_t**>(list_bytes + 0x10);
    for (; entry != end; entry += 0x10)
        RenderState_ApplyEntry_00910CB4(target, entry);
    state = *reinterpret_cast<std::uint8_t**>(target_bytes + 0x28);
    state[0x151] = 0;
}
