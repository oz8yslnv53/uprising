#include <cstdarg>
#include <cstdint>
namespace actor_param {
void* MenuSelnameParam_Factory_00174968(void);
}
extern "C" void String_FormatV_00328400(
    char* output, std::uint32_t capacity, const char* format,
    std::va_list arguments);
extern "C" void ParameterString_FormatUtf16_002A47D0(
    std::uint16_t* output, const std::uint16_t* format, ...);
extern "C" void* Engine_LazySingletonGetter_00498828();
extern "C" std::uint32_t ByteString_Length_00425CAC(const char* text);
extern "C" void* ParameterString_FindNode_00498FBC(
    void* root, const char* text, std::uint32_t length);
extern "C" void RelativePointerRecord_Assign_003AC8F4(
    void* destination, void* source);
namespace {
template <typename T>
T& At(void* object, std::uint32_t offset) {
    return *reinterpret_cast<T*>(
        static_cast<std::uint8_t*>(object) + offset);
}
void* ResolveRelative(void* field) {
    const std::uint32_t relative = At<std::uint32_t>(field, 0);
    return relative == 0
        ? 0
        : static_cast<std::uint8_t*>(field) + relative;
}
}  // namespace
extern "C" __attribute__((noinline)) void SaveUi_FormatOptionName_001ED0C0(
    char* output, const char* format, ...) {
    std::va_list arguments;
    va_start(arguments, format);
    String_FormatV_00328400(output, 0x20, format, arguments);
    va_end(arguments);
}
extern "C" __attribute__((noinline)) void SaveUi_FormatOptionValues_001C1DF8(void* object) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(object);
    const std::uint16_t* const format = reinterpret_cast<const std::uint16_t*>(0x00CA2414u);
    ParameterString_FormatUtf16_002A47D0(
        reinterpret_cast<std::uint16_t*>(bytes + 0x154), format,
        At<std::uint32_t>(object, 0x180));
    ParameterString_FormatUtf16_002A47D0(
        reinterpret_cast<std::uint16_t*>(bytes + 0x15c), format,
        At<std::uint32_t>(object, 0x184));
}
extern "C" __attribute__((noinline)) bool FUN_001F50EC(void*) {
    return false;
}
extern "C" __attribute__((noinline)) void* ResourceTree_FindCurrentEntry_001ED44C(void* tree) {
    const std::uint32_t key = reinterpret_cast<std::uintptr_t>(
        actor_param::MenuSelnameParam_Factory_00174968());
    std::uint8_t* const end = static_cast<std::uint8_t*>(tree) + 0x1a8;
    std::uint8_t* node = static_cast<std::uint8_t*>(At<void*>(tree, 0x1ac));
    std::uint8_t* candidate = end;
    while (At<std::uint8_t>(node, 0x10) != 0) {
        if (At<std::uint32_t>(node, 0x14) < key) {
            node = static_cast<std::uint8_t*>(At<void*>(node, 0x0c));
        } else {
            candidate = node;
            node = static_cast<std::uint8_t*>(At<void*>(node, 0x08));
        }
    }
    if (candidate == end || At<std::uint32_t>(candidate, 0x14) <= key)
        candidate = end;
    void* value = At<void*>(candidate, 0);
    if (value == At<void*>(end, 0))
        return 0;
    return value == 0 ? 0 : At<void*>(value, 0x1c);
}
extern "C" __attribute__((noinline)) void SaveUi_BindMiiDynamicResource_001EBE20(
    void* output_records, void* resource, std::uint32_t selection) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
    std::uint8_t* active = static_cast<std::uint8_t*>(At<void*>(resource, 0x1e4));
    if (active == 0) {
        const std::uint32_t key = reinterpret_cast<std::uintptr_t>(
            Engine_LazySingletonGetter_00498828());
        std::uint8_t* const end = bytes + 0x1a8;
        std::uint8_t* node = static_cast<std::uint8_t*>(At<void*>(resource, 0x1ac));
        std::uint8_t* candidate = end;
        while (At<std::uint8_t>(node, 0x10) != 0) {
            if (At<std::uint32_t>(node, 0x14) < key) {
                node = static_cast<std::uint8_t*>(At<void*>(node, 0x0c));
            } else {
                candidate = node;
                node = static_cast<std::uint8_t*>(At<void*>(node, 0x08));
            }
        }
        if (candidate == end || At<std::uint32_t>(candidate, 0x14) <= key)
            candidate = end;
        void* value = At<void*>(candidate, 0);
        if (value != At<void*>(end, 0) && value != 0) {
            At<void*>(value, 0x1c) = resource;
            At<void*>(resource, 0x1e4) = value;
            active = static_cast<std::uint8_t*>(value);
        }
    }
    std::uint8_t* owner = static_cast<std::uint8_t*>(
        At<void*>(At<void*>(active, 0x24), 0xb0));
    std::uint8_t* table = static_cast<std::uint8_t*>(
        At<void*>(At<void*>(owner, 0x08), 0x10c));
    std::uint8_t* root_field = static_cast<std::uint8_t*>(
        At<void*>(table, 0x08)) + 0xc0;
    void* root = ResolveRelative(root_field);
    std::int32_t index = -1;
    if (root != 0) {
        const char kName[] = "MiiDynamic0001";
        void* found = ParameterString_FindNode_00498FBC(
            &root, kName, ByteString_Length_00425CAC(kName));
        if (found != 0) {
            index = (static_cast<std::uint8_t*>(found) -
                     static_cast<std::uint8_t*>(root) - 0x1c) >> 4;
        }
    }
    std::uint8_t* entries = static_cast<std::uint8_t*>(At<void*>(table, 0x164));
    std::uint8_t* entry = static_cast<std::uint8_t*>(
        At<void*>(entries + index * 4, 0));
    std::uint8_t* relative = static_cast<std::uint8_t*>(
        At<void*>(entry, 0x3c)) + 0x274;
    void* dynamic_record = ResolveRelative(relative);
    RelativePointerRecord_Assign_003AC8F4(
        &dynamic_record,
        At<void*>(output_records, selection * 0x20 + 4));
}
