// KIU jp_rev1 NUL-terminated byte-string search at 0x00262F94.
#include <cstdint>
extern "C" __attribute__((noinline)) const char* ByteString_FindChar_00262F94(const char* text,
                                                     int needle) {
    const std::uint8_t wanted = static_cast<std::uint8_t>(needle);
    const char* cursor = text;
    for (;;) {
        const std::uint8_t value = static_cast<std::uint8_t>(*cursor);
        if (wanted == value)
            return cursor;
        if (value == 0)
            return 0;
        ++cursor;
    }
}
extern "C" __attribute__((noinline)) int ByteString_FindCharOffset_00601534(
    const std::int8_t* text, int needle) {
    int index = 0;
    while (text[index] != 0 && text[index] != needle)
        ++index;
    return index;
}
