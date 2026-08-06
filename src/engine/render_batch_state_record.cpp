#include <cstddef>
#include <cstdint>
struct RenderBatchFormatRecordSet {
    std::uint32_t count;
    const std::uint32_t* records;
};
struct RenderBatchStateView {
    std::uint8_t reserved_000[4];
    std::uint32_t active_flags;
    std::uint32_t resource_count;
    void** resources;
    std::uint8_t* resource_descriptors;
    std::uint8_t reserved_014[0x30];
    std::uint32_t* command_words;
    std::uint8_t reserved_048[8];
    std::uint32_t pending_state_flags;
    std::uint8_t reserved_054[0x80];
    std::uint32_t transform_tail_word;
    std::uint8_t reserved_0d8[0x2c];
    std::uint32_t target_width;
    std::uint32_t target_height;
    std::uint8_t packed_texture_format;
    std::uint8_t state_selector;
    std::uint8_t texture_format_a;
    std::uint8_t texture_format_b;
    void* active_resource;
};
typedef char RenderBatchResourcesOffsetCheck[
    offsetof(RenderBatchStateView, resources) == 0x0c ? 1 : -1];
typedef char RenderBatchCommandsOffsetCheck[
    offsetof(RenderBatchStateView, command_words) == 0x44 ? 1 : -1];
typedef char RenderBatchDimensionsOffsetCheck[
    offsetof(RenderBatchStateView, target_width) == 0x104 ? 1 : -1];
typedef char RenderBatchActiveResourceOffsetCheck[
    offsetof(RenderBatchStateView, active_resource) == 0x110 ? 1 : -1];
extern "C" void RenderCommand_QueryState_001B4F50(
    std::uint32_t selector, std::uint32_t** output);
extern "C" void RenderCommand_AdvanceAllocation_00153868(
    std::uint32_t bytes);
extern "C" void RenderBatch_ExpandStateCommand_0092DC88(
    void* renderer, std::uint32_t command, const std::uint32_t* payload);
extern "C" void RenderBatch_ApplyStateSelector_0092E248(
    void* renderer, std::uint32_t selector);
extern "C" int RenderBatch_CompareTextureFormatState_0092F4AC(
    void* renderer, std::uint32_t flags, std::uint32_t command);
extern "C" void RenderBatch_UpdateTextureFormatState_0092EA18(
    void* renderer);
extern "C" std::uint32_t g_RenderCommand_AllocationCursor_00D4D134;
extern "C" const std::uint32_t g_RenderBatch_SelectorStates_00CB1934[16];
extern "C" const std::uint32_t g_RenderBatch_FormatFlags_00CB18DC[16];
extern "C" const std::uint32_t g_RenderBatch_FormatRecords_00CB17D4[2][3];
extern "C" const RenderBatchFormatRecordSet
    g_RenderBatch_FormatRecordSetsA_00CB17EC[64];
extern "C" const RenderBatchFormatRecordSet
    g_RenderBatch_FormatRecordSetsB_00CB1884[64];
extern "C" void FUN_001B4E70(
    void* record, std::uint32_t size, std::uint32_t count);
extern "C" void RenderBatch_AppendStateShared_0090A53C(
    void* batch, std::uint32_t mode);
namespace {
template <typename T>
T& Field(void* object, std::uint32_t offset) {
    return *reinterpret_cast<T*>(
        static_cast<unsigned char*>(object) + offset);
}
}  // namespace
extern "C" __attribute__((noinline)) void RenderCommand_AdvanceAllocation_00153868(
    std::uint32_t bytes) {
    g_RenderCommand_AllocationCursor_00D4D134 += bytes;
}
extern "C" __attribute__((noinline)) void RenderBatch_AppendPrimitiveState_0090FE18(void* renderer) {
    FUN_001B4E70(reinterpret_cast<void*>(0x00cb1c48u), 0x40, 1);
    RenderBatch_AppendStateShared_0090A53C(
        static_cast<std::uint8_t*>(renderer) + 4, 0);
}
extern "C" __attribute__((noinline)) std::uint32_t* RenderBatch_BuildStateRecord_0091940C(
    std::uint32_t* dst,
    const std::uint32_t* first,
    const std::uint32_t* second,
    const std::uint32_t* tail) {
    dst[0] = 0x80000000u;
    dst[1] = 0x000F02C0u;
    dst[2] = first[3];
    dst[3] = 0x023F02C1u;
    dst[4] = first[2];
    dst[5] = first[1];
    dst[6] = first[0];
    dst[7] = first[7];
    dst[8] = first[6];
    dst[9] = first[5];
    dst[10] = first[4];
    dst[11] = first[11];
    dst[12] = first[10];
    dst[13] = first[9];
    dst[14] = first[8];
    dst[15] = first[15];
    dst[16] = first[14];
    dst[17] = first[13];
    dst[18] = first[12];
    dst[19] = second[3];
    dst[20] = second[2];
    dst[21] = second[1];
    dst[22] = second[0];
    dst[23] = second[7];
    dst[24] = second[6];
    dst[25] = second[5];
    dst[26] = second[4];
    dst[27] = second[11];
    dst[28] = second[10];
    dst[29] = second[9];
    dst[30] = second[8];
    dst[31] = second[15];
    dst[32] = second[14];
    dst[33] = second[13];
    dst[34] = second[12];
    dst[35] = tail[0];
    dst[36] = 0;
    dst[37] = tail[1];
    dst[38] = tail[2];
    dst[39] = 0;
    return dst + 40;
}
extern "C" __attribute__((noinline)) void RenderBatch_DecodeCommandRange_0092E08C(
    void* renderer, std::uint32_t begin_word, std::uint32_t end_word) {
    RenderBatchStateView& state =
        *static_cast<RenderBatchStateView*>(renderer);
    if ((state.active_flags & 1u) == 0 || begin_word >= end_word)
        return;
    const std::uint32_t fixed_header = 0x000F0082u;
    const std::uint32_t format_header = 0x000F0083u;
    std::uint32_t* input = state.command_words + begin_word;
    while (begin_word < end_word) {
        const std::uint32_t command = *input;
        std::uint32_t advance = 1;
        if ((command & 0x80000000u) == 0) {
            RenderBatch_ExpandStateCommand_0092DC88(
                renderer, command, input + 1);
            advance += (command & 0x00FFFFFFu) >> 18;
        } else {
            const std::uint32_t flags = command & 0x7C000000u;
            if ((flags & 0x08000000u) != 0) {
                const std::uint32_t index = (command & 0x3FFFu) >> 4;
                if (index < state.resource_count) {
                    void* resource = state.resources[index];
                    if (resource != 0 && resource != state.active_resource) {
                        state.active_resource = resource;
                        state.pending_state_flags |= 0x01000000u;
                    const std::uint32_t* descriptor =
                            reinterpret_cast<const std::uint32_t*>(
                                state.resource_descriptors + index * 12);
                        std::uint32_t* available = 0;
                        RenderCommand_QueryState_001B4F50(
                            0x207u, &available);
                        std::uint32_t* output = available;
                        if (available != 0)
                            RenderCommand_QueryState_001B4F50(
                                0x208u, &output);
                        const std::uint32_t packed = descriptor[0];
                        std::uint32_t state =
                            (packed & 0xFF00u) |
                            ((packed & 0x30u) >> 3) |
                            ((packed & 0x40u) << 18);
                        if ((packed & 0x0Fu) == 0x0Cu)
                            state |= 0x20u;
                        std::uint32_t* start = output;
                        output[0] = descriptor[2];
                        output[1] = fixed_header;
                        output[2] = state;
                        output[3] = format_header;
                        output[4] = descriptor[1];
                        output[5] = format_header + 2u;
                        output[6] = packed & 0x0Fu;
                        output[7] = format_header + 0x0Bu;
                        output += 8;
                        if (start != 0 && start != output)
                            RenderCommand_AdvanceAllocation_00153868(0x20u);
                    }
                }
            }
            if ((flags & 0x04000000u) != 0)
                RenderBatch_ApplyStateSelector_0092E248(
                    renderer, command & 0x0Fu);
            if ((flags & 0x60000000u) != 0 &&
                RenderBatch_CompareTextureFormatState_0092F4AC(
                    renderer, flags & 0x60000000u, command) != 0)
                RenderBatch_UpdateTextureFormatState_0092EA18(renderer);
        }
        begin_word += advance;
        input += advance;
    }
}
extern "C" __attribute__((noinline)) void RenderBatch_ApplyStateSelector_0092E248(
    void* renderer, std::uint32_t selector) {
    const std::uint8_t previous = Field<std::uint8_t>(renderer, 0x10d);
    if (previous == selector)
        return;
    Field<std::uint8_t>(renderer, 0x10d) = selector;
    const std::uint32_t state = g_RenderBatch_SelectorStates_00CB1934[selector];
    const std::uint32_t changed =
        g_RenderBatch_SelectorStates_00CB1934[previous] ^ state;
    std::uint32_t* available = 0;
    RenderCommand_QueryState_001B4F50(0x207u, &available);
    std::uint32_t* output = 0;
    if (available != 0)
        RenderCommand_QueryState_001B4F50(0x208u, &output);
    std::uint32_t* const start = output;
    if ((changed & 0x0fu) != 0) {
        *output++ = (state & 0x0fu) << 8;
        *output++ = 0x00020107u;
    }
    if ((changed & 0x002ffff0u) != 0) {
        *output++ = ((state & 0xfffffff0u) << 12) |
                    ((state & 0x00200000u) >> 20);
        *output++ = 0x000f0101u;
    }
    if ((changed & 0x00c00000u) != 0) {
        if ((changed & 0x00400000u) != 0) {
            *output++ = (state & 0x00400000u) != 0 ? 0x0fu : 0u;
            *output++ = 0x000f0112u;
        }
        if ((changed & 0x00800000u) != 0) {
            *output++ = (state & 0x00800000u) != 0 ? 0x0fu : 0u;
            *output++ = 0x000f0113u;
        }
        *output++ = 1;
        *output++ = 0x000f0111u;
        *output++ = 1;
        *output++ = 0x000f0110u;
    }
    if (start != 0 && start != output)
        RenderCommand_AdvanceAllocation_00153868(
            reinterpret_cast<unsigned char*>(output) -
            reinterpret_cast<unsigned char*>(start));
}
extern "C" __attribute__((noinline)) void RenderBatch_ExpandStateCommand_0092DC88(
    void* renderer, std::uint32_t command, const std::uint32_t* payload) {
    std::uint32_t* available = 0;
    RenderCommand_QueryState_001B4F50(0x207u, &available);
    std::uint32_t* output = 0;
    if (available != 0)
        RenderCommand_QueryState_001B4F50(0x208u, &output);
    std::uint32_t* const start = output;
    const std::uint32_t high_flags = command & 0x7f000000u;
    if (high_flags != 0) {
        if ((high_flags & 0x07000000u) != 0) {
            if ((high_flags & 0x07000000u) == 0x07000000u) {
                const std::uint32_t tail[3] = {
                    Field<std::uint32_t>(renderer, 0xd4),
                    payload[32],
                    payload[33],
                };
                output = RenderBatch_BuildStateRecord_0091940C(
                    output, payload, payload + 16, tail);
                payload += 34;
            } else {
                if ((high_flags & 0x01000000u) != 0) {
                    output[0] = 0x80000000u;
                    output[1] = 0x000f02c0u;
                    output[2] = payload[3];
                    output[3] = 0x00ff02c1u;
                    output[4] = payload[2];
                    output[5] = payload[1];
                    output[6] = payload[0];
                    output[7] = payload[7];
                    output[8] = payload[6];
                    output[9] = payload[5];
                    output[10] = payload[4];
                    output[11] = payload[11];
                    output[12] = payload[10];
                    output[13] = payload[9];
                    output[14] = payload[8];
                    output[15] = payload[15];
                    output[16] = payload[14];
                    output[17] = payload[13];
                    output[18] = payload[12];
                    output[19] = 0;
                    output += 20;
                    payload += 16;
                }
                if ((high_flags & 0x02000000u) != 0) {
                    output[0] = 0x80000004u;
                    output[1] = 0x000f02c0u;
                    output[2] = payload[3];
                    output[3] = 0x00ff02c1u;
                    output[4] = payload[2];
                    output[5] = payload[1];
                    output[6] = payload[0];
                    output[7] = payload[7];
                    output[8] = payload[6];
                    output[9] = payload[5];
                    output[10] = payload[4];
                    output[11] = payload[11];
                    output[12] = payload[10];
                    output[13] = payload[9];
                    output[14] = payload[8];
                    output[15] = payload[15];
                    output[16] = payload[14];
                    output[17] = payload[13];
                    output[18] = payload[12];
                    output[19] = 0;
                    output += 20;
                    payload += 16;
                }
                if ((high_flags & 0x04000000u) != 0) {
                    output[0] = 0x80000008u;
                    output[1] = 0x000f02c0u;
                    output[2] = Field<std::uint32_t>(renderer, 0xd4);
                    output[3] = 0x003f02c1u;
                    output[4] = 0;
                    output[5] = payload[0];
                    output[6] = payload[1];
                    output[7] = 0;
                    output += 8;
                    payload += 2;
                }
            }
        }
        if ((high_flags & 0x08000000u) != 0) {
            std::uint32_t first = payload[0];
            std::uint32_t second = payload[1];
            payload += 2;
            if ((first | second) == 0) {
                first = 0;
                second =
                    ((Field<std::uint32_t>(renderer, 0x108) - 1u) & 0x3ffu) |
                    (((Field<std::uint32_t>(renderer, 0x104) - 1u) & 0x3ffu)
                     << 16);
            }
            *output++ = 3;
            *output++ = 0x802f0065u;
            *output++ = first;
            *output++ = second;
        }
        if ((high_flags & 0x10000000u) != 0) {
            *output++ = *payload++;
            *output++ = 0x000f00c3u;
        }
        if ((high_flags & 0x20000000u) != 0) {
            *output++ = *payload++;
            *output++ = 0x000f00cbu;
        }
        if ((high_flags & 0x40000000u) != 0) {
            *output++ = *payload;
            *output++ = 0x000f00d3u;
        }
    }
    const std::uint32_t count = command & 0xffu;
    if (count != 0) {
        *output++ = 0x100u;
        *output++ = 0x00020229u;
        *output++ = 0x100u;
        *output++ = 0x00030253u;
        *output++ = 0x300u;
        *output++ = 0x0002025eu;
        *output++ = 1;
        *output++ = 0x000f025fu;
        const std::uint32_t format_index =
            (Field<std::uint8_t>(renderer, 0x10c) >> 2) & 1u;
        if (format_index != 0) {
            *output++ = format_index;
            *output++ = 0x00010080u;
            if ((Field<std::uint32_t>(renderer, 0x50) & 0x01000000u) != 0) {
                *output++ = 0x10000u;
                *output++ = 0x00040080u;
                Field<std::uint32_t>(renderer, 0x50) &= 0xfeffffffu;
            }
        }
        *output++ =
            (Field<std::uint32_t>(renderer, 0x28) +
             (((command >> 8) & 0x3ffffu) * 12u)) |
            0x80000000u;
        *output++ = 0x000f0227u;
        *output++ = count * 6u;
        *output++ = 0x000f0228u;
        *output++ = 0;
        *output++ = 0x00010245u;
        *output++ = 1;
        *output++ = 0x000f022fu;
        *output++ = 1;
        *output++ = 0x00010245u;
        *output++ = 1;
        *output++ = 0x000f0231u;
        *output++ = 0;
        *output++ = 0x0008025eu;
        *output++ = 0;
        *output++ = 0x0008025eu;
        *output++ = 1;
        *output++ = 0x000f0111u;
        *output++ = 0;
        *output++ = 0x00020229u;
        *output++ = 0;
        *output++ = 0x00020253u;
        *output++ = 0;
        *output++ = 0x0002025eu;
        if (format_index != 0) {
            *output++ = 0;
            *output++ = 0x00010080u;
        }
        *output++ = 0x7fff0000u;
        *output++ = 0x000c02bau;
    }
    if (start != 0 && start != output)
        RenderCommand_AdvanceAllocation_00153868(
            reinterpret_cast<unsigned char*>(output) -
            reinterpret_cast<unsigned char*>(start));
}
extern "C" __attribute__((noinline))  int RenderBatch_CompareTextureFormatState_0092F4AC(
    void* renderer, std::uint32_t flags, std::uint32_t command) {
    std::uint32_t transition = 0;
    std::uint32_t selector_a = Field<std::uint8_t>(renderer, 0x10e);
    std::uint32_t selector_b = Field<std::uint8_t>(renderer, 0x10f);
    bool changed = false;
    if ((flags & 0x20000000u) != 0) {
        const std::uint32_t next = (command >> 20) & 0x3fu;
        if (selector_a != next) {
            if (selector_a == 8 || selector_a == 9)
                transition = 1;
            else if (selector_a == 0x12)
                transition = 2;
            if (next == 8 || next == 9)
                transition = (transition & ~1u) | 4u;
            else if (next == 0x12)
                transition = (transition & ~2u) | 0x10u;
            else if (next == 10 || next == 11)
                transition |= 8u;
            selector_a = next;
            changed = true;
            Field<std::uint8_t>(renderer, 0x10e) = next;
        }
    }
    if ((flags & 0x40000000u) != 0) {
        const std::uint32_t next = (command >> 14) & 0x3fu;
        if (selector_b != next) {
            selector_b = next;
            changed = true;
            Field<std::uint8_t>(renderer, 0x10f) = next;
        }
    }
    if (!changed)
        return 0;
    const RenderBatchFormatRecordSet& set_a =
        g_RenderBatch_FormatRecordSetsA_00CB17EC[selector_a];
    const RenderBatchFormatRecordSet& set_b =
        g_RenderBatch_FormatRecordSetsB_00CB1884[selector_b];
    const int leading = 3 - static_cast<int>(set_a.count);
    if (leading >= 3)
        return 1;
    std::uint32_t* available = 0;
    RenderCommand_QueryState_001B4F50(0x207u, &available);
    std::uint32_t* output = 0;
    if (available != 0)
        RenderCommand_QueryState_001B4F50(0x208u, &output);
    std::uint32_t* const start = output;
    if ((transition & 1u) != 0) {
        *output++ = 0;
        *output++ = 0x000f00ccu;
    }
    if ((transition & 2u) != 0) {
        *output++ = 0;
        *output++ = 0x000f00ccu;
        *output++ = 0;
        *output++ = 0x000200e0u;
    }
    if ((transition & 0x10u) != 0) {
        *output++ = 2;
        *output++ = 0x000f00ccu;
        *output++ = 0x100u;
        *output++ = 0x000200e0u;
    }
    const std::uint32_t* records_a = set_a.records;
    const std::uint32_t* records_b = set_b.records;
    if ((transition & 0x0cu) != 0) {
        if ((transition & 4u) != 0) {
            *output++ = 1;
            *output++ = 0x000200e0u;
        } else {
            *output++ = records_a[0] | records_b[0];
            *output++ = 0x802f00c0u;
            *output++ = records_a[1] | records_b[1];
            *output++ = records_a[2] | records_b[2];
            records_a += 3;
            records_b += 3;
        }
        *output++ = records_a[0] | records_b[0];
        *output++ = 0x802f00c8u;
        *output++ = records_a[1] | records_b[1];
        *output++ = records_a[2] | records_b[2];
        *output++ = records_a[3] | records_b[3];
        *output++ = 0x802f00d0u;
        *output++ = records_a[4] | records_b[4];
        *output++ = records_a[5] | records_b[5];
    } else {
        const int copy_count = 2 - leading;
        for (int i = 0; i < copy_count; ++i) {
            *output++ = records_a[0];
            *output++ = 0x802f00c0u + (leading + i) * 8u;
            *output++ = records_a[1];
            *output++ = records_a[2];
            records_a += 3;
        }
        *output++ = records_a[0] | records_b[0];
        *output++ = 0x802f00d0u;
        *output++ = records_a[1] | records_b[1];
        *output++ = records_a[2] | records_b[2];
    }
    if (start != 0 && start != output)
        RenderCommand_AdvanceAllocation_00153868(
            reinterpret_cast<unsigned char*>(output) -
            reinterpret_cast<unsigned char*>(start));
    return 1;
}
extern "C" __attribute__((noinline)) void RenderBatch_UpdateTextureFormatState_0092EA18(
    void* renderer) {
    const std::uint32_t previous = Field<std::uint8_t>(renderer, 0x10c);
    const std::uint32_t state =
        g_RenderBatch_FormatFlags_00CB18DC[
            Field<std::uint8_t>(renderer, 0x10e)] |
        g_RenderBatch_FormatFlags_00CB18DC[
            Field<std::uint8_t>(renderer, 0x10f)];
    if (previous == state)
        return;
    Field<std::uint8_t>(renderer, 0x10c) = state;
    std::uint32_t* available = 0;
    RenderCommand_QueryState_001B4F50(0x207u, &available);
    std::uint32_t* output = 0;
    if (available != 0)
        RenderCommand_QueryState_001B4F50(0x208u, &output);
    std::uint32_t* const start = output;
    const std::uint32_t format_index = (state >> 2) & 1u;
    const std::uint32_t format_count = format_index + 1u;
    const std::uint32_t resource_state = Field<std::uint32_t>(
        renderer, 0x20u + Field<std::uint32_t>(renderer, 0x14) * 4u);
    const std::uint32_t* const record =
        g_RenderBatch_FormatRecords_00CB17D4[format_index];
    *output++ = format_count;
    *output++ = 0x000102b9u;
    *output++ = format_count;
    *output++ = 0x000f0242u;
    *output++ = record[0];
    *output++ = 0x804f0201u;
    *output++ = format_count << 28;
    *output++ = resource_state & 0x00ffffffu;
    *output++ = record[1];
    *output++ = 0x30180000u;
    *output++ = record[2];
    *output++ = 0x000f02bbu;
    if (((previous >> 2) & 1u) != format_index) {
        *output++ = format_index;
        *output++ = 0x000f0064u;
    }
    *output++ = (state & 3u) | ((state & 0x0cu) << 6);
    *output++ = 0x000f006fu;
    if (start != 0 && start != output)
        RenderCommand_AdvanceAllocation_00153868(
            reinterpret_cast<unsigned char*>(output) -
            reinterpret_cast<unsigned char*>(start));
}
