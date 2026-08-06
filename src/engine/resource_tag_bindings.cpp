#include <cstdint>
extern "C" std::uint32_t Platform_MapResourceAddress_003AC86C(
    std::uint32_t address);
extern "C" std::uint32_t ByteString_Length_00425CAC(const char* text);
extern "C" void* ParameterString_FindNode_00498FBC(
    void* root, const char* text, std::uint32_t length);
extern "C" void OrderedTree_CopySearchFrame_00445CF4(
    std::uint32_t* destination, const std::uint32_t* source);
extern "C" std::uint32_t ResourceTagApplyByTable_004B0C4C(
    void** record, void* record_source, void* context);
extern "C" void Tag20000009_RebuildResourceBindings_0041510C(
    void* destination, const void* source);
extern "C" std::uint32_t Tag20000011_Apply_004152F0(
    void* destination, const void* source);
extern "C" void Tag20000021_ConfigureResource_0041544C(
    void* destination, const void* source);
typedef void (*ResourceTagCallback)(void*);
extern "C" ResourceTagCallback
    g_ResourceTagInitCallbacks_00D4DC7C[];
extern "C" void* g_RenderCommand_AllocatorCallback_00D4D45C;
extern "C" void* MemoryCopyEnd_005B4DB0(
    void* destination, const void* source, std::uint32_t size);
extern "C" std::uint32_t Platform_ServiceCall_00188818(
    void* request, std::uint32_t size);
extern "C" std::uint32_t ResourceTag20000021_Initialize_008F4098(
    void* record);
namespace {
inline const std::uint8_t* resolve_relative(
    const std::uint8_t* field) {
    const std::int32_t offset =
        *reinterpret_cast<const std::int32_t*>(field);
    return offset == 0 ? 0 : field + offset;
}
inline std::uint32_t float_bits(float value) {
    union {
        float as_float;
        std::uint32_t as_uint;
    } bits;
    bits.as_float = value;
    return bits.as_uint;
}
struct ResourceLookupResult {
    std::uint8_t* resolved;
    std::uint8_t success;
};
inline void store_relative(
    std::uint8_t* field, const std::uint8_t* target) {
    *reinterpret_cast<std::int32_t*>(field) =
        target == 0 ? 0 : target - field;
}
}  // namespace
extern "C" __attribute__((noinline)) void ResourceRecord_FindByName_008F44AC(
    ResourceLookupResult* result, void* record_pointer,
    void* context_pointer) {
    std::uint8_t* record = static_cast<std::uint8_t*>(record_pointer);
    std::uint8_t* context = static_cast<std::uint8_t*>(context_pointer);
    const char* name =
        reinterpret_cast<const char*>(resolve_relative(record + 0x18));
    void* root =
        const_cast<std::uint8_t*>(resolve_relative(context + 0x28));
    std::uint8_t* found = 0;
    std::uint8_t success = 0;
    if (root != 0 && name != 0) {
        std::uint8_t* node = static_cast<std::uint8_t*>(
            ParameterString_FindNode_00498FBC(
                &root, name, ByteString_Length_00425CAC(name)));
        if (node != 0)
            found = const_cast<std::uint8_t*>(
                resolve_relative(node + 0x0c));
    }
    if (found != 0) {
        if ((*reinterpret_cast<std::uint32_t*>(found) & 0x20000004u) ==
            0x20000004u) {
            ResourceLookupResult nested = {0, 0};
            ResourceLookupResult copied = {0, 0};
            ResourceRecord_FindByName_008F44AC(
                &nested, found, context);
            OrderedTree_CopySearchFrame_00445CF4(
                reinterpret_cast<std::uint32_t*>(&copied),
                reinterpret_cast<const std::uint32_t*>(&nested));
            if (copied.success != 0) {
                store_relative(record + 0x1c, copied.resolved);
                success = 1;
            }
        } else {
            store_relative(record + 0x1c, found);
            success = 1;
        }
    }
    result->resolved = const_cast<std::uint8_t*>(
        resolve_relative(record + 0x1c));
    result->success = success;
}
extern "C" __attribute__((noinline))  std::uint32_t ResourceRecord_Prepare_008F27B0(
    void* record_source, void* record_pointer, void* context) {
    std::uint8_t* record = static_cast<std::uint8_t*>(record_pointer);
    void* selected = 0;
    std::uint32_t status = 0;
    if (record == 0)
        return status;
    if ((*reinterpret_cast<std::uint32_t*>(record) & 0x20000004u) ==
        0x20000004u) {
        selected = const_cast<std::uint8_t*>(
            resolve_relative(record + 0x1c));
        if (selected == 0) {
            ResourceLookupResult found = {0, 0};
            ResourceLookupResult copied = {0, 0};
            ResourceRecord_FindByName_008F44AC(
                &found, record, context);
            OrderedTree_CopySearchFrame_00445CF4(
                reinterpret_cast<std::uint32_t*>(&copied),
                reinterpret_cast<const std::uint32_t*>(&found));
            if (copied.success == 0)
                return status | 0x80000001u;
            selected = copied.resolved;
        }
    } else {
        selected = record;
    }
    status |= ResourceTagApplyByTable_004B0C4C(
        &selected, record_source, context);
    return status;
}
extern "C" __attribute__((noinline))  std::uint32_t ResourceTagDispatchWrapper_008F4E98(
    void* destination_pointer, void* record_source, void* context) {
    std::uint8_t* destination =
        static_cast<std::uint8_t*>(destination_pointer);
    std::uint8_t* record = const_cast<std::uint8_t*>(
        resolve_relative(destination + 8));
    const std::uint32_t status =
        ResourceRecord_Prepare_008F27B0(
            record_source, record, context);
    if ((status & 0x80000000u) != 0)
        return status;
    std::uint8_t* source = record;
    if (*reinterpret_cast<std::uint32_t*>(record) == 0x20000004u)
        source = const_cast<std::uint8_t*>(
            resolve_relative(record + 0x1c));
    const std::uint32_t tag =
        *reinterpret_cast<std::uint32_t*>(source);
    if (tag == 0x20000009u)
        Tag20000009_RebuildResourceBindings_0041510C(
            destination, source);
    else if (tag == 0x20000011u)
        Tag20000011_Apply_004152F0(destination, source);
    else if (tag == 0x20000021u)
        Tag20000021_ConfigureResource_0041544C(
            destination, source);
    return status;
}
extern "C" __attribute__((noinline))  std::uint32_t ResourceTagApplyByTable_004B0C4C(
    void** record_pointer, void*, void*) {
    void* record = *record_pointer;
    const std::uint32_t tag =
        *static_cast<std::uint32_t*>(record);
    int callback = -1;
    if (tag == 0x20000011u)
        callback = 0;
    else if (tag == 0x20000009u)
        callback = 1;
    else if (tag == 0x20000004u)
        callback = 2;
    else if (tag == 0x20000002u)
        callback = 3;
    else if (tag == 0x20000021u)
        callback = 4;
    if (callback >= 0)
        g_ResourceTagInitCallbacks_00D4DC7C[callback](record);
    return 0;
}
extern "C" __attribute__((noinline))  std::uint32_t ResourceTag20000011_Initialize_008F3EB0(
    void* record_pointer) {
    std::uint8_t* record = static_cast<std::uint8_t*>(record_pointer);
    std::uint8_t* validated = 0;
    if (record != 0 &&
        (*reinterpret_cast<std::uint32_t*>(record) & 0x20000011u) ==
            0x20000011u)
        validated = record;
    if (*reinterpret_cast<void**>(validated + 0x2c) != 0)
        return static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(record));
    *reinterpret_cast<void**>(validated + 0x2c) = record;
    std::uint8_t* child = const_cast<std::uint8_t*>(
        resolve_relative(validated + 0x38));
    if (*reinterpret_cast<void**>(child + 0x18) != 0) {
        *reinterpret_cast<std::uint32_t*>(child + 0x1c) = 0;
        return 0;
    }
    std::uint32_t version =
        *reinterpret_cast<std::uint32_t*>(validated + 0x30);
    if (version == 0)
        version = 0x02010000u;
    version = (version >> 16) << 16;
    std::uint32_t size =
        *reinterpret_cast<std::uint32_t*>(child + 8);
    if (size == 0) {
        size = *reinterpret_cast<std::uint32_t*>(child) *
            *reinterpret_cast<std::uint32_t*>(child + 4);
        size *= *reinterpret_cast<std::uint32_t*>(child + 0x14);
        size >>= 3;
    }
    if (version == 0x02010000u) {
        return Platform_ServiceCall_00188818(
            const_cast<std::uint8_t*>(
                resolve_relative(child + 0x0c)),
            size);
    }
    if (static_cast<std::int32_t>(version) >=
        static_cast<std::int32_t>(0x02010000u))
        return 0;
    const std::uint32_t difference =
        version - 0x01010000u;
    if (difference != 0)
        return difference;
    typedef void* (*Allocate)(
        std::uint32_t, std::uint32_t, void*, std::uint32_t);
    void* allocated = reinterpret_cast<Allocate>(
        g_RenderCommand_AllocatorCallback_00D4D45C)(
            0x10000u, 0x101u, record, size);
    const void* source = resolve_relative(child + 0x0c);
    if (source != 0) {
        MemoryCopyEnd_005B4DB0(allocated, source, size);
        Platform_ServiceCall_00188818(allocated, size);
    }
    *reinterpret_cast<void**>(child + 0x18) = allocated;
    *reinterpret_cast<std::uint32_t*>(child + 0x1c) = 0x10000u;
    return 0x10000u;
}
extern "C" __attribute__((noinline))  std::uint32_t ResourceTag20000021_Initialize_008F4098(
    void* record_pointer) {
    std::uint8_t* record = static_cast<std::uint8_t*>(record_pointer);
    std::uint8_t* validated = 0;
    if (record != 0 &&
        (*reinterpret_cast<std::uint32_t*>(record) & 0x20000021u) ==
            0x20000021u)
        validated = record;
    if (*reinterpret_cast<void**>(validated + 0x2c) != 0)
        return static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(record));
    *reinterpret_cast<void**>(validated + 0x2c) = record;
    std::uint8_t* child = const_cast<std::uint8_t*>(
        resolve_relative(validated + 0x38));
    if (*reinterpret_cast<void**>(child + 0x18) != 0) {
        *reinterpret_cast<std::uint32_t*>(child + 0x1c) = 0;
        return 0;
    }
    std::uint32_t version =
        *reinterpret_cast<std::uint32_t*>(validated + 0x30);
    if (version == 0)
        version = 0x02010000u;
    version = (version >> 16) << 16;
    std::uint32_t size =
        *reinterpret_cast<std::uint32_t*>(child + 8);
    if (size == 0) {
        size = *reinterpret_cast<std::uint32_t*>(child) *
            *reinterpret_cast<std::uint32_t*>(child + 4);
        size *= *reinterpret_cast<std::uint32_t*>(child + 0x14);
        size >>= 3;
    }
    if (version == 0x02010000u) {
        return Platform_ServiceCall_00188818(
            const_cast<std::uint8_t*>(
                resolve_relative(child + 0x0c)),
            size);
    }
    if (static_cast<std::int32_t>(version) >=
        static_cast<std::int32_t>(0x02010000u))
        return 0;
    const std::uint32_t difference =
        version - 0x01010000u;
    if (difference != 0)
        return difference;
    typedef void* (*Allocate)(
        std::uint32_t, std::uint32_t, void*, std::uint32_t);
    void* allocated = reinterpret_cast<Allocate>(
        g_RenderCommand_AllocatorCallback_00D4D45C)(
            0x10000u, 0x101u, record, size);
    const void* source = resolve_relative(child + 0x0c);
    if (source != 0) {
        MemoryCopyEnd_005B4DB0(allocated, source, size);
        Platform_ServiceCall_00188818(allocated, size);
    }
    *reinterpret_cast<void**>(child + 0x18) = allocated;
    *reinterpret_cast<std::uint32_t*>(child + 0x1c) = 0x10000u;
    return 0x10000u;
}
extern "C" __attribute__((noinline)) void ResourceTag20000009_InitializeBatch_008F39CC(
    void* record_pointer) {
    std::uint8_t* record = static_cast<std::uint8_t*>(record_pointer);
    std::uint8_t* validated = 0;
    if (record != 0 &&
        (*reinterpret_cast<std::uint32_t*>(record) & 0x20000009u) ==
            0x20000009u)
        validated = record;
    if (*reinterpret_cast<void**>(validated + 0x2c) != 0)
        return;
    *reinterpret_cast<void**>(validated + 0x2c) = record;
    const std::uint32_t record_version =
        *reinterpret_cast<std::uint32_t*>(validated + 0x30);
    for (std::uint32_t index = 0; index < 6; ++index) {
        std::uint8_t* child = const_cast<std::uint8_t*>(
            resolve_relative(validated + 0x38 + index * 4));
        if (*reinterpret_cast<void**>(child + 0x18) != 0) {
            *reinterpret_cast<std::uint32_t*>(child + 0x1c) = 0;
            continue;
        }
        std::uint32_t version =
            record_version == 0 ? 0x02010000u : record_version;
        version = (version >> 16) << 16;
        std::uint32_t size =
            *reinterpret_cast<std::uint32_t*>(child + 8);
        if (size == 0) {
            size = *reinterpret_cast<std::uint32_t*>(child) *
                *reinterpret_cast<std::uint32_t*>(child + 4);
            size *= *reinterpret_cast<std::uint32_t*>(
                child + 0x14);
            size >>= 3;
        }
        if (version == 0x02010000u) {
            Platform_ServiceCall_00188818(
                const_cast<std::uint8_t*>(
                    resolve_relative(child + 0x0c)),
                size);
            continue;
        }
        if (static_cast<std::int32_t>(version) >=
                static_cast<std::int32_t>(0x02010000u) ||
            version != 0x01010000u)
            continue;
        typedef void* (*Allocate)(
            std::uint32_t, std::uint32_t, void*, std::uint32_t);
        void* allocated = reinterpret_cast<Allocate>(
            g_RenderCommand_AllocatorCallback_00D4D45C)(
                0x10000u, 0x101u, record, size);
        const void* source = resolve_relative(child + 0x0c);
        if (source != 0) {
            MemoryCopyEnd_005B4DB0(allocated, source, size);
            Platform_ServiceCall_00188818(allocated, size);
        }
        *reinterpret_cast<void**>(child + 0x18) = allocated;
        *reinterpret_cast<std::uint32_t*>(child + 0x1c) =
            0x10000u;
    }
}
extern "C" __attribute__((noinline)) void ResourceTagChainDispatch_008F45D4(
    void* record_pointer) {
    std::uint8_t* record =
        static_cast<std::uint8_t*>(record_pointer);
    for (;;) {
        std::uint8_t* target = const_cast<std::uint8_t*>(
            resolve_relative(record + 0x1c));
        const std::uint32_t tag =
            *reinterpret_cast<std::uint32_t*>(target);
        if (tag == 0x20000009u) {
            ResourceTag20000009_InitializeBatch_008F39CC(target);
            return;
        }
        if (tag == 0x20000002u)
            return;
        if (tag == 0x20000004u) {
            record = target;
            continue;
        }
        if (tag == 0x20000011u) {
            ResourceTag20000011_Initialize_008F3EB0(target);
            return;
        }
        if (tag == 0x20000021u)
            ResourceTag20000021_Initialize_008F4098(target);
        return;
    }
}
extern "C" __attribute__((noinline)) void ResourceTag20000002_NoOp_008F47D0(void*) {
}
extern "C" __attribute__((noinline)) void Tag20000009_RebuildResourceBindings_0041510C(
    void* destination_pointer, const void* source_pointer) {
    std::uint8_t* destination =
        static_cast<std::uint8_t*>(destination_pointer);
    const std::uint8_t* source =
        static_cast<const std::uint8_t*>(source_pointer);
    const std::uint32_t source_kind =
        *reinterpret_cast<const std::uint32_t*>(source + 0x34);
    *reinterpret_cast<std::uint32_t*>(destination + 0x48) = 0x38;
    std::uint32_t& field10 =
        *reinterpret_cast<std::uint32_t*>(destination + 0x10);
    field10 = (field10 & ~0x0fu) | (source_kind & 0x0fu);
    *reinterpret_cast<std::uint32_t*>(destination + 0x1c) &=
        ~0x0ff00000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x20) &=
        0xf800f800u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x24) &= ~0x30u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x28) &=
        ~0x000f0000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x2c) &=
        0xf0000000u;
    for (int offset = 0x30; offset <= 0x40; offset += 4)
        *reinterpret_cast<std::uint32_t*>(destination + offset) &=
            0xffc00000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x1c) |=
        0x00900000u;
    std::uint32_t& field20 =
        *reinterpret_cast<std::uint32_t*>(destination + 0x20);
    field20 |=
        *reinterpret_cast<const std::uint32_t*>(source + 0x18) & 0x7ffu;
    field20 |=
        (*reinterpret_cast<const std::uint32_t*>(source + 0x1c) &
         0x7ffu) << 16;
    if (source_kind == 0x0c)
        *reinterpret_cast<std::uint32_t*>(destination + 0x24) |= 0x20u;
    const std::uint8_t* linked =
        resolve_relative(destination + 0x0c);
    const std::uint32_t linked_kind =
        *reinterpret_cast<const std::uint32_t*>(linked + 8) & 0xffu;
    if (linked_kind != 0 && linked_kind != 1) {
        *reinterpret_cast<std::uint32_t*>(destination + 0x28) |=
            ((*reinterpret_cast<const std::uint32_t*>(source + 0x28) -
              1u) & 0x0fu) << 16;
    }
    for (std::uint32_t index = 0; index < 6; ++index) {
        const std::uint8_t* entry =
            resolve_relative(source + 0x38 + index * 4);
        std::uint32_t address =
            *reinterpret_cast<const std::uint32_t*>(entry + 0x18);
        if (address == 0) {
            address = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(
                    resolve_relative(entry + 0x0c)));
        }
        const std::uint32_t physical =
            Platform_MapResourceAddress_003AC86C(address);
        std::uint32_t& packed =
            *reinterpret_cast<std::uint32_t*>(
                destination + 0x2c + index * 4);
        if (index == 0)
            packed |= physical >> 4;
        else
            packed |= (physical >> 3) & 0xe03fffffu;
    }
}
extern "C" __attribute__((noinline))  std::uint32_t Tag20000011_Apply_004152F0(
    void* destination_pointer, const void* source_pointer) {
    std::uint8_t* destination =
        static_cast<std::uint8_t*>(destination_pointer);
    const std::uint8_t* source =
        static_cast<const std::uint8_t*>(source_pointer);
    const std::uint32_t source_kind =
        *reinterpret_cast<const std::uint32_t*>(source + 0x34);
    *reinterpret_cast<std::uint32_t*>(destination + 0x48) = 0x20;
    *reinterpret_cast<std::uint32_t*>(destination + 0x10) &= ~0x0fu;
    *reinterpret_cast<std::uint32_t*>(destination + 0x1c) &=
        ~0x0ff00000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x20) &=
        0xf800f800u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x24) &= ~0x30u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x28) &=
        ~0x000f0000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x2c) &=
        0xf0000000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x10) |=
        source_kind & 0x0fu;
    *reinterpret_cast<std::uint32_t*>(destination + 0x1c) |=
        0x00400000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x14) |=
        0x000f0000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x20) |=
        *reinterpret_cast<const std::uint32_t*>(source + 0x18) & 0x7ffu;
    *reinterpret_cast<std::uint32_t*>(destination + 0x20) |=
        (*reinterpret_cast<const std::uint32_t*>(source + 0x1c) &
         0x7ffu) << 16;
    if (source_kind == 0x0c)
        *reinterpret_cast<std::uint32_t*>(destination + 0x24) |= 0x20u;
    const std::uint8_t* destination_descriptor =
        resolve_relative(destination + 0x0c);
    const std::uint32_t descriptor_kind =
        *reinterpret_cast<const std::uint32_t*>(
            destination_descriptor + 8) & 0xffu;
    if (descriptor_kind != 0 && descriptor_kind != 1) {
        *reinterpret_cast<std::uint32_t*>(destination + 0x28) |=
            ((*reinterpret_cast<const std::uint32_t*>(source + 0x28) -
              1u) & 0x0fu) << 16;
    }
    const std::uint8_t* source_record =
        resolve_relative(source + 0x38);
    std::uint32_t address =
        *reinterpret_cast<const std::uint32_t*>(source_record + 0x18);
    if (address == 0) {
        address = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(
                resolve_relative(source_record + 0x0c)));
    }
    const std::uint32_t physical =
        Platform_MapResourceAddress_003AC86C(address);
    std::uint32_t& packed =
        *reinterpret_cast<std::uint32_t*>(destination + 0x2c);
    packed |= (physical & 0x7fffffffu) >> 3;
    return packed;
}
extern "C" __attribute__((noinline)) void Tag20000021_ConfigureResource_0041544C(
    void* destination_pointer, const void* source_pointer) {
    std::uint8_t* destination =
        static_cast<std::uint8_t*>(destination_pointer);
    const std::uint8_t* source =
        static_cast<const std::uint8_t*>(source_pointer);
    *reinterpret_cast<std::uint32_t*>(destination + 0x48) = 0x38;
    *reinterpret_cast<std::uint32_t*>(destination + 0x10) &= ~0x0fu;
    *reinterpret_cast<std::uint32_t*>(destination + 0x1c) &=
        ~0x0ff00000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x20) &=
        0xf800f800u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x24) &=
        0x8fffffcfu;
    *reinterpret_cast<std::uint32_t*>(destination + 0x28) &=
        ~0x000f0000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x2c) &=
        0xf0000000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x44) = 0;
    const std::uint8_t* entry =
        resolve_relative(source + 0x38);
    std::uint32_t address =
        *reinterpret_cast<const std::uint32_t*>(entry + 0x18);
    if (address == 0) {
        address = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(
                resolve_relative(entry + 0x0c)));
    }
    *reinterpret_cast<std::uint32_t*>(destination + 0x10) |=
        *reinterpret_cast<const std::uint32_t*>(source + 0x34) & 0x0fu;
    *reinterpret_cast<std::uint32_t*>(destination + 0x1c) |=
        0x00a00000u;
    *reinterpret_cast<std::uint32_t*>(destination + 0x14) |=
        0x000f0000u;
    std::uint32_t& field20 =
        *reinterpret_cast<std::uint32_t*>(destination + 0x20);
    field20 |=
        *reinterpret_cast<const std::uint32_t*>(source + 0x18) & 0x7ffu;
    field20 |=
        (*reinterpret_cast<const std::uint32_t*>(source + 0x1c) &
         0x7ffu) << 16;
    *reinterpret_cast<std::uint32_t*>(destination + 0x24) |=
        0x20000000u;
    const std::uint8_t* linked =
        resolve_relative(destination + 0x0c);
    const std::uint32_t linked_kind =
        *reinterpret_cast<const std::uint32_t*>(linked + 8) & 0xffu;
    if (linked_kind != 0 && linked_kind != 1) {
        *reinterpret_cast<std::uint32_t*>(destination + 0x28) |=
            ((*reinterpret_cast<const std::uint32_t*>(source + 0x28) -
              1u) & 0x0fu) << 16;
    }
    const std::uint32_t physical =
        Platform_MapResourceAddress_003AC86C(address);
    *reinterpret_cast<std::uint32_t*>(destination + 0x2c) |=
        (physical >> 3) & 0x0fffffffu;
    const std::uint32_t flags =
        source[0x3c] == 0 ? 1u : 0u;
    const float value =
        *reinterpret_cast<const float*>(source + 0x40);
    std::uint32_t encoded = 0;
    if (value > 0.0f &&
        (float_bits(value) & 0x7f800000u) != 0x7f800000u) {
        const float scaled = value * 16777216.0f;
        encoded = value < 1.0f
            ? static_cast<std::uint32_t>(scaled)
            : 0x00ffffffu;
    }
    *reinterpret_cast<std::uint32_t*>(destination + 0x44) =
        (encoded & 0x00fffffeu) | flags;
}
extern "C" __attribute__((noinline)) void RelativePointerRecord_Assign_003AC8F4(
    void* destination_pointer, void* source_pointer) {
    std::uint8_t* destination_root =
        *static_cast<std::uint8_t**>(destination_pointer);
    std::uint8_t* destination_record =
        const_cast<std::uint8_t*>(
            resolve_relative(destination_root + 8));
    std::uint8_t* destination_slot = destination_record + 0x1c;
    std::uint8_t* source =
        static_cast<std::uint8_t*>(source_pointer);
    std::uint8_t* resolved_source = source;
    if (*reinterpret_cast<std::uint32_t*>(source) == 0x20000004u) {
        resolved_source = const_cast<std::uint8_t*>(
            resolve_relative(source + 0x1c));
    }
    *reinterpret_cast<std::int32_t*>(destination_slot) =
        resolved_source == 0
            ? 0
            : static_cast<std::int32_t>(
                  reinterpret_cast<std::uintptr_t>(resolved_source) -
                  reinterpret_cast<std::uintptr_t>(destination_slot));
    if (*reinterpret_cast<std::uint32_t*>(destination_root) !=
        0x80000000u)
        return;
    std::uint8_t* dispatch_source = source;
    if (*reinterpret_cast<std::uint32_t*>(source) == 0x20000004u) {
        dispatch_source = const_cast<std::uint8_t*>(
            resolve_relative(source + 0x1c));
    }
    const std::uint32_t tag =
        *reinterpret_cast<std::uint32_t*>(dispatch_source);
    if (tag == 0x20000009u)
        Tag20000009_RebuildResourceBindings_0041510C(
            destination_root, dispatch_source);
    else if (tag == 0x20000011u)
        Tag20000011_Apply_004152F0(
            destination_root, dispatch_source);
    else if (tag == 0x20000021u)
        Tag20000021_ConfigureResource_0041544C(
            destination_root, dispatch_source);
}
