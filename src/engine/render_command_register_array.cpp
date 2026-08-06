#include <cstddef>
#include <cstdint>
extern "C" std::uint32_t* g_RenderCommand_Cursor_00D4D134;
extern "C" std::uint32_t* g_RenderCommand_End_00D4D138;
extern "C" std::uint8_t* g_RenderResourceTableOwner_00D4E50C;
extern "C" void Engine_Memmove_003DC528(
    void* destination, const void* source, std::size_t size);
extern "C" __attribute__((noinline)) void PicaCommand_AppendRegisterArray_004747A0(
    std::uint32_t reg, std::uint32_t count,
    const std::uint32_t* parameters) {
    const std::uint32_t required_words =
        (count & ~1u) + (count >> 7) * 2u + 2u;
    if (g_RenderCommand_Cursor_00D4D134 + required_words >=
        g_RenderCommand_End_00D4D138) {
        g_RenderCommand_Cursor_00D4D134 = g_RenderCommand_End_00D4D138;
        return;
    }
    for (std::uint32_t offset = 0; offset < count; offset += 0x80) {
        std::uint32_t packet_count = count - offset;
        if (packet_count > 0x80)
            packet_count = 0x80;
        std::uint32_t* output = g_RenderCommand_Cursor_00D4D134;
        output[0] = parameters[offset];
        output[1] = (0xfff00000u + (packet_count << 20)) |
                    reg | 0x000f0000u;
        const std::uint32_t trailing_words =
            packet_count - 1u + ((packet_count & 1u) == 0);
        Engine_Memmove_003DC528(
            output + 2, parameters + offset + 1,
            static_cast<std::size_t>(trailing_words) * 4u);
        g_RenderCommand_Cursor_00D4D134 = output + 2 + trailing_words;
    }
}
extern "C" __attribute__((noinline)) void PicaCommand_ReserveRegisterRange_0054BF54(
    std::uint32_t header, std::uint32_t count) {
    std::uint32_t* const output = g_RenderCommand_Cursor_00D4D134;
    if (output + count + 2 >= g_RenderCommand_End_00D4D138) {
        g_RenderCommand_Cursor_00D4D134 = g_RenderCommand_End_00D4D138;
        return;
    }
    if (count == 0)
        return;
    const std::uint32_t count_minus_one = count - 1;
    output[0] = 0;
    output[1] = header | (count_minus_one << 20);
    g_RenderCommand_Cursor_00D4D134 = output + 2;
    g_RenderCommand_Cursor_00D4D134 +=
        count_minus_one + (count_minus_one & 1u);
}
extern "C" __attribute__((noinline))  std::uint32_t RenderResourceTable_GetWord_0054C72C(
    std::uint32_t index) {
    if (index < 32) {
        std::uint32_t* const entry =
            *reinterpret_cast<std::uint32_t**>(
                g_RenderResourceTableOwner_00D4E50C + 0x828 + index * 4);
        if (entry != 0)
            return *entry;
    }
    return 0;
}
extern "C" __attribute__((noinline)) void PicaCommand_AppendRepeatedRegisterValue_00576C9C(
    std::uint32_t reg, std::uint32_t count, std::uint32_t value) {
    const std::uint32_t required_words =
        (count & ~1u) + (count >> 7) * 2u + 2u;
    if (g_RenderCommand_Cursor_00D4D134 + required_words >=
        g_RenderCommand_End_00D4D138) {
        g_RenderCommand_Cursor_00D4D134 = g_RenderCommand_End_00D4D138;
        return;
    }
    std::uint32_t* output = g_RenderCommand_Cursor_00D4D134;
    for (std::uint32_t offset = 0; offset < count; offset += 0x80) {
        std::uint32_t packet_count = count - offset;
        if (packet_count > 0x80)
            packet_count = 0x80;
        *output++ = value;
        *output++ = ((packet_count - 1u) << 20) |
                    (reg + offset) | 0x800f0000u;
        for (std::uint32_t pairs = packet_count >> 1; pairs != 0; --pairs) {
            *output++ = value;
            *output++ = value;
        }
    }
    g_RenderCommand_Cursor_00D4D134 = output;
}
extern "C" __attribute__((noinline)) void PicaCommand_AppendRegisterArray_0059351C(
    std::uint32_t reg, std::uint32_t count,
    const std::uint32_t* parameters) {
    const std::uint32_t required_words =
        (count & ~1u) + (count >> 7) * 2u + 2u;
    if (g_RenderCommand_Cursor_00D4D134 + required_words >=
        g_RenderCommand_End_00D4D138) {
        g_RenderCommand_Cursor_00D4D134 = g_RenderCommand_End_00D4D138;
        return;
    }
    std::uint32_t* output = g_RenderCommand_Cursor_00D4D134;
    for (std::uint32_t offset = 0; offset < count; offset += 0x80) {
        std::uint32_t packet_count = count - offset;
        if (packet_count > 0x80)
            packet_count = 0x80;
        const std::uint32_t* source = parameters + offset;
        *output++ = *source++;
        *output++ = ((packet_count - 1u) << 20) |
                    (reg + offset) | 0x800f0000u;
        for (std::uint32_t pairs = packet_count >> 1; pairs != 0; --pairs) {
            *output++ = *source++;
            *output++ = *source++;
        }
    }
    g_RenderCommand_Cursor_00D4D134 = output;
}
