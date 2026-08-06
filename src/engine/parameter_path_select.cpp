// KIU jp_rev1: parameter-path selector family
#include <stddef.h>
#include <stdint.h>
namespace {
template <typename T>
T& At(void* base, size_t offset) {
    return *reinterpret_cast<T*>(static_cast<uint8_t*>(base) + offset);
}
template <typename T>
T& Global(uintptr_t address) {
    return *reinterpret_cast<T*>(address);
}
extern "C" int Engine_CharacterClassTableGet_004C5F38();
uint16_t FoldPathCharacter(uint16_t value) {
    int* table = reinterpret_cast<int*>(
        static_cast<uintptr_t>(Engine_CharacterClassTableGet_004C5F38()));
    if (table != 0 && (static_cast<uint8_t>(table[value]) & 0x10u))
        value = static_cast<uint16_t>(value + 0x20u);
    return value;
}
}  // namespace
extern "C" __attribute__((noinline)) int Engine_CharacterClassTableGet_004C5F38() {
    return *reinterpret_cast<int*>(0x004c5f40u);
}
extern "C" __attribute__((noinline)) int ParameterPath_FoldCharacter_001BA840(int value) {
    return FoldPathCharacter(static_cast<uint16_t>(value));
}
extern "C" __attribute__((noinline)) uint32_t ParameterPath_SelectIndex_001B2D98(
    void* object, const int16_t* path) {
    uint8_t* records = static_cast<uint8_t*>(At<void*>(object, 4));
    uint32_t index = At<uint32_t>(object, 0x18);
    for (;;) {
        while (*path == 0 || *path == '/') {
            if (*path == 0)
                return index;
            index = 0;
            ++path;
        }
        if (*path == '.') {
            const uint16_t second = static_cast<uint16_t>(path[1]);
            if (second == '/') {
                path += 2;
                continue;
            }
            if (second == '.') {
                const uint16_t third = static_cast<uint16_t>(path[2]);
                if (third == '/') {
                    index = At<uint32_t>(records + index * 0xc, 4);
                    path += 3;
                    continue;
                }
                if (third == 0)
                    return At<uint32_t>(records + index * 0xc, 4);
            } else if (second == 0) {
                return index;
            }
        }
        const int16_t* end = path;
        while (*end != 0 && *end != '/')
            ++end;
        bool has_slash = *end == '/';
        uint8_t* limit_record = records + index * 0xc;
        uint8_t* record = limit_record;
        ++index;
        if (At<uint32_t>(limit_record, 8) <= index)
            return 0xffffffffu;
        for (;;) {
            record = records + index * 0xc;
            uint32_t name_offset = At<uint32_t>(record, 0);
            while ((name_offset & 0xff000000u) == 0 && has_slash) {
                ++index;
                if (At<uint32_t>(limit_record, 8) <= index)
                    return 0xffffffffu;
                record = records + index * 0xc;
                name_offset = At<uint32_t>(record, 0);
            }
            const int16_t* name = reinterpret_cast<const int16_t*>(
                At<uintptr_t>(object, 0x10) + (name_offset & 0xffffffu));
            uint16_t first = static_cast<uint16_t>(*name);
            if (first == '.') {
                uint16_t second = static_cast<uint16_t>(name[1]);
                if (second == 0) {
                    ++index;
                    continue;
                }
            }
            const int16_t* candidate = path;
            while (first != 0) {
                if (ParameterPath_FoldCharacter_001BA840(*candidate) !=
                    ParameterPath_FoldCharacter_001BA840(*name))
                    break;
                first = static_cast<uint16_t>(name[1]);
                ++name;
                ++candidate;
            }
            if (first != 0 || (*candidate != '/' && *candidate != 0)) {
                if ((At<uint32_t>(records + index * 0xc, 0) &
                     0xff000000u) == 0) {
                    ++index;
                    continue;
                }
                index = At<uint32_t>(records + index * 0xc, 8);
                continue;
            }
            if (!has_slash)
                return index;
            path = path + (end - path) + 1;
            break;
        }
    }
}
extern "C" __attribute__((noinline)) int ParameterRecord_Select_003ACA10(
    void* object, void* path, uint32_t* output) {
    uint8_t* records = static_cast<uint8_t*>(At<void*>(object, 4));
    uint32_t index = ParameterPath_SelectIndex_001B2D98(
        object, static_cast<const int16_t*>(path));
    if (static_cast<int32_t>(index) >= 0 &&
        (At<uint32_t>(records + index * 0xc, 0) & 0xff000000u) == 0) {
        uint8_t* record = records + index * 0xc;
        output[0] = reinterpret_cast<uintptr_t>(object);
        output[1] = At<uint32_t>(record, 4);
        output[2] = At<uint32_t>(record, 8);
        return 1;
    }
    return 0;
}
