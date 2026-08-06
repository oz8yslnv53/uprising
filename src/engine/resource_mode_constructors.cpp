#include <cstddef>
#include <cstdint>
extern "C" void* Engine_AllocateTaggedBlock_0047466C(
    std::uint32_t size, const void* tag, std::uint32_t context);
extern "C" void* Engine_ResourceSourceResolve_0046303C(
    std::uint32_t context, void* entry, void** source_slot,
    void* selector);
extern "C" void* Engine_ResourceProductCreate_0045D884(
    void** source_slot, std::uint32_t flags, std::uint32_t context,
    void* holder, std::uint32_t mode);
extern "C" void* Engine_LazySingletonGetter_0049BE78();
extern "C" void* Engine_StateEntryOffset_0042F42C(
    void* base, std::uint32_t mode, std::uint32_t index);
extern "C" void* Engine_ResourceWrapperCreate_00462F94(
    std::uint32_t context, void* work);
extern "C" void* Engine_ResourceRuntimeConstruct_00463EA0(
    void* block, void* work);
namespace {
template <typename T>
T& At(void* base, std::size_t offset) {
    return *reinterpret_cast<T*>(static_cast<std::uint8_t*>(base) + offset);
}
template <typename T>
T& Global(std::uintptr_t address) {
    return *reinterpret_cast<T*>(address);
}
struct ResourceConstructionWork {
    void* owner;
    void* source_fields;
    void* holder;
    std::uint8_t option;
    std::uint8_t padding[3];
    void* product;
    void* state_entry;
};
typedef char kiu_sa_resource_mode_constructors_1[(sizeof(ResourceConstructionWork) == 0x18) ? 1 : -1] __attribute__((unused));
typedef char kiu_sa_resource_mode_constructors_2[(offsetof(ResourceConstructionWork, product) == 0x10) ? 1 : -1] __attribute__((unused));
void CallVirtual(void* object, std::size_t slot) {
    void** vtable = At<void**>(object, 0);
    reinterpret_cast<void (*)(void*)>(vtable[slot])(object);
}
void CallVirtualWithContext(
    void* object, std::size_t slot, std::uint32_t context) {
    void** vtable = At<void**>(object, 0);
    reinterpret_cast<void (*)(void*, std::uint32_t)>(
        vtable[slot])(object, context);
}
void CleanupProduct(void* product) {
    if (product == 0)
        return;
    CallVirtual(product, 0);
    void* owner = At<void*>(product, 4);
    void** vtable = At<void**>(owner, 0);
    reinterpret_cast<void (*)(void*, void*)>(
        vtable[3])(owner, product);
}
void* ResolveSourceEntry(void* source, std::uint32_t index) {
    void* table_record = At<void*>(source, 0x1c);
    if (table_record == 0)
        return 0;
    std::uint8_t* offset_word = static_cast<std::uint8_t*>(table_record) + 0x20;
    const std::uint32_t table_offset =
        At<std::uint32_t>(offset_word, 0);
    if (table_offset == 0)
        return 0;
    std::uint8_t* entry_word = offset_word + table_offset + index * 0x10 + 0x28;
    const std::uint32_t entry_offset =
        At<std::uint32_t>(entry_word, 0);
    return entry_offset == 0 ? 0 : entry_word + entry_offset;
}
std::uint32_t BuildResourceFlags(void* source, std::uint32_t flags) {
    std::uint32_t result = 0;
    if (At<std::uint8_t>(At<void*>(source, 0x44), 0x10) != 0 ||
        (flags & 4u) != 0)
        result = 4;
    if (At<std::uint8_t>(At<void*>(source, 0x74), 0x10) != 0 ||
        (flags & 8u) != 0)
        result |= 0x10;
    if (At<std::uint8_t>(At<void*>(source, 0x5c), 0x10) != 0)
        result |= 0x20;
    if ((flags & 1u) != 0)
        result |= 0x804;
    if ((flags & 2u) != 0)
        result |= 0x20;
    return result;
}
void* ConstructResource(
    std::uint32_t context, void* source, void* owner,
    std::uint32_t flags, std::uint32_t index, void* selector,
    const void* holder_tag, bool require_product) {
    void* source_slot = At<void*>(source, 0x1c);
    if (source_slot == 0)
        return 0;
    void* resolved = Engine_ResourceSourceResolve_0046303C(
        context, ResolveSourceEntry(source, index), &source_slot,
        selector);
    if (resolved == 0) {
        CallVirtual(owner, 2);
        return 0;
    }
    void* holder = Engine_AllocateTaggedBlock_0047466C(
        0x10, holder_tag, context);
    if (holder != 0) {
        At<std::uint32_t>(holder, 0) = 0x00d15f20u;
        At<std::uint32_t>(holder, 4) = 0;
        At<std::uint32_t>(holder, 8) = 0;
        At<std::uint32_t>(holder, 0x0c) = 0;
    }
    void* product = Engine_ResourceProductCreate_0045D884(
        &resolved, BuildResourceFlags(source, flags), context,
        holder, 0);
    if (require_product && product == 0) {
        CallVirtual(owner, 2);
        if (holder != 0)
            CallVirtual(holder, 1);
        return 0;
    }
    void*& singleton = Global<void*>(0x00d63530u);
    if (singleton == 0)
        singleton = Engine_LazySingletonGetter_0049BE78();
    ResourceConstructionWork work = {
        owner,
        static_cast<std::uint8_t*>(source) + 0x24,
        holder,
        0,
        {},
        product,
        static_cast<std::uint8_t*>(
            Engine_StateEntryOffset_0042F42C(singleton, 0, 1)) +
            0x64,
    };
    void* wrapper =
        Engine_ResourceWrapperCreate_00462F94(context, &work);
    void* object = 0;
    if (wrapper != 0) {
        void* block = Engine_AllocateTaggedBlock_0047466C(
            0xf4, reinterpret_cast<const void*>(0x00ca5970u),
            context);
        if (block != 0)
            object =
                Engine_ResourceRuntimeConstruct_00463EA0(block, &work);
        if (object != 0) {
            At<void*>(wrapper, 4) = object;
            void* previous = At<void*>(object, 0xb0);
            if (previous != wrapper) {
                if (previous != 0)
                    CallVirtual(previous, 1);
                At<void*>(object, 0xb0) = wrapper;
            }
            CallVirtualWithContext(
                static_cast<std::uint8_t*>(object) + 0xac, 2,
                context);
            CallVirtualWithContext(wrapper, 2, context);
        } else {
            CallVirtual(wrapper, 1);
        }
    }
    if (object != 0) {
        CleanupProduct(product);
        return object;
    }
    if (require_product)
        CleanupProduct(product);
    CallVirtual(owner, 2);
    if (holder != 0)
        CallVirtual(holder, 1);
    if (!require_product)
        CleanupProduct(product);
    return 0;
}
}  // namespace
extern "C" __attribute__((noinline)) void* Engine_ConstructResourceMode0_00435C6C(
    void*, std::uint32_t, void* source, void* owner,
    std::uint32_t flags, std::uint32_t, std::uint32_t index,
    void* selector) {
    return ConstructResource(
        At<std::uint32_t>(owner, 0x10), source, owner, flags, index,
        selector, reinterpret_cast<const void*>(0x00435f8cu), false);
}
extern "C" __attribute__((noinline)) void* Engine_ConstructResourceMode1_00436648(
    void*, std::uint32_t context, void* source, void* owner,
    std::uint32_t flags, std::uint32_t, std::uint32_t index,
    void* selector) {
    return ConstructResource(
        context, source, owner, flags, index, selector,
        reinterpret_cast<const void*>(0x00436944u), true);
}
extern "C" __attribute__((noinline)) void* Engine_ConstructResourceByMode_004128A4(
    void* unused0, std::uint32_t context, void* source, void* owner,
    std::uint32_t mode, std::uint32_t flags, std::uint32_t unused6,
    std::uint32_t index, void* selector) {
    if (mode != 0) {
        return Engine_ConstructResourceMode1_00436648(
            unused0, context, source, owner, flags, unused6, index,
            selector);
    }
    return Engine_ConstructResourceMode0_00435C6C(
        unused0, context, source, owner, flags, unused6, index,
        selector);
}
