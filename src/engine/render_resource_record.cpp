#include <cstddef>
#include <cstdint>
extern "C" void RenderCommand_UpdateModeVector_008DEB70(
    void* state, std::int32_t requested);
extern "C" std::uint32_t ByteString_Length_00425CAC(const char* text);
extern "C" void* ParameterString_FindNode_00498FBC(
    void* root, const char* text, std::uint32_t length);
extern "C" void FUN_008DFAF8(
    void* state, void* resource, std::uint32_t index);
extern "C" void FUN_008DC444(
    void* context, void* entry, void* record, std::uint32_t index);
extern "C" __attribute__((noinline)) void* RenderResource_GetIndexedRecord_003AF054(
    void* owner, std::uint32_t index) {
    std::uint8_t* base = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(owner) + 0xE8);
    return base + index * 0x194;
}
extern "C" __attribute__((noinline)) void RenderResource_RecordInitialize_00542598(
    void* destination, const void* source) {
    std::uint8_t* dst = static_cast<std::uint8_t*>(destination);
    std::uint8_t* src = const_cast<std::uint8_t*>(
        static_cast<const std::uint8_t*>(source));
    *reinterpret_cast<void**>(dst + 0x08) = src;
    *reinterpret_cast<std::uint32_t*>(src + 0x10) =
        *reinterpret_cast<std::uint32_t*>(src + 0x0c);
    *reinterpret_cast<std::uint32_t*>(src + 0x20) =
        *reinterpret_cast<std::uint32_t*>(src + 0x1c);
    *reinterpret_cast<std::uint32_t*>(src + 0x30) =
        *reinterpret_cast<std::uint32_t*>(src + 0x2c);
    *reinterpret_cast<std::uint32_t*>(src + 0x40) =
        *reinterpret_cast<std::uint32_t*>(src + 0x3c);
    *reinterpret_cast<std::uint32_t*>(src + 0x70) =
        *reinterpret_cast<std::uint32_t*>(src + 0x6c);
    *reinterpret_cast<std::uint32_t*>(src + 0x80) =
        *reinterpret_cast<std::uint32_t*>(src + 0x7c);
    *reinterpret_cast<std::uint32_t*>(src + 0x90) =
        *reinterpret_cast<std::uint32_t*>(src + 0x8c);
    *reinterpret_cast<std::uint32_t*>(src + 0xa0) =
        *reinterpret_cast<std::uint32_t*>(src + 0x9c);
    *reinterpret_cast<std::uint32_t*>(src + 0xb0) =
        *reinterpret_cast<std::uint32_t*>(src + 0xac);
    *reinterpret_cast<std::uint32_t*>(src + 0x50) =
        *reinterpret_cast<std::uint32_t*>(src + 0x4c);
    *reinterpret_cast<std::uint32_t*>(src + 0x60) =
        *reinterpret_cast<std::uint32_t*>(src + 0x5c);
    *reinterpret_cast<std::uint32_t*>(src + 0xc0) =
        *reinterpret_cast<std::uint32_t*>(src + 0xbc);
    *reinterpret_cast<std::uint32_t*>(src + 0xd0) =
        *reinterpret_cast<std::uint32_t*>(src + 0xcc);
    *reinterpret_cast<std::uint32_t*>(src + 0xe0) =
        *reinterpret_cast<std::uint32_t*>(src + 0xdc);
    *reinterpret_cast<std::uint32_t*>(src + 0xf0) =
        *reinterpret_cast<std::uint32_t*>(src + 0xec);
}
// Retail 0x0054258C: release the source retained by a temporary record.
extern "C" __attribute__((noinline)) void RenderResource_RecordClearSource_0054258C(void* record) {
    std::uint8_t* bytes = static_cast<std::uint8_t*>(record);
    *reinterpret_cast<void**>(bytes + 0x08) = 0;
}
extern "C" __attribute__((noinline)) void RenderResource_RecordInitializeAndNotify_00542558(
    void* record_owner, void* owner) {
    std::uint8_t* record = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(record_owner) + 0x14u);
    RenderResource_RecordInitialize_00542598(
        record, *reinterpret_cast<void**>(
                    static_cast<std::uint8_t*>(record_owner) + 0x18u));
    std::uint8_t* object = *reinterpret_cast<std::uint8_t**>(
        static_cast<std::uint8_t*>(owner) + 0x04u);
    typedef void(*Notify)(void*, void*);
    void** vtable = *reinterpret_cast<void***>(object);
    reinterpret_cast<Notify>(vtable[4])(object, record);
    RenderResource_RecordClearSource_0054258C(record);
}
// Retail 0x00542618: dispatch cleanup for the two recognized resource tags.
extern "C" __attribute__((noinline)) std::uint32_t RenderResource_CleanupDispatch_00542618(
    void** resource) {
    std::uint8_t* object = static_cast<std::uint8_t*>(*resource);
    const std::uint32_t tag = *reinterpret_cast<const std::uint32_t*>(object);
    void** dispatch_table = reinterpret_cast<void**>(0x00D4EF44u);
    typedef std::uint32_t(*Cleanup)(void*);
    if (tag == 0x80000000u) {
        return reinterpret_cast<Cleanup>(dispatch_table[0])(object);
    }
    if (tag == 0x40000000u) {
        return reinterpret_cast<Cleanup>(dispatch_table[1])(object);
    }
    return 0;
}
struct RenderResourceSearchFrame {
    std::uint32_t value;
    std::uint8_t found;
    std::uint8_t reserved[3];
};
extern "C" void RenderResource_FindChild_00564140(
    RenderResourceSearchFrame* result, void* resource, void* context);
extern "C" void OrderedTree_CopySearchFrame_00445CF4(
    std::uint32_t* destination, std::uint32_t* source);
extern "C" __attribute__((noinline)) std::uint32_t RenderResource_ResolveChild_00542668(
    void* resource, void* context) {
    std::uint32_t result = 0;
    if (resource != 0) {
        std::uint8_t* bytes = static_cast<std::uint8_t*>(resource);
        const std::int32_t relative =
            *reinterpret_cast<const std::int32_t*>(bytes + 0x0cu);
        std::uint32_t* child = relative == 0
                          ? static_cast<std::uint32_t*>(0)
                          : reinterpret_cast<std::uint32_t*>(
                                bytes + 0x0cu + relative);
        if (child != 0 && (*child & 0x80000000u) == 0)
            child = 0;
        if (child == 0) {
            RenderResourceSearchFrame search_result;
            RenderResourceSearchFrame copied_result = {};
            RenderResource_FindChild_00564140(
                &search_result, resource, context);
            OrderedTree_CopySearchFrame_00445CF4(
                &copied_result.value, &search_result.value);
            if (copied_result.found == 0)
                result = 0x80000004u;
        }
    }
    return result;
}
extern "C" __attribute__((noinline)) void RenderResource_Rebuild_008DC2E8(
    void* context, void* entry) {
    std::uint8_t* context_bytes = static_cast<std::uint8_t*>(context);
    std::uint8_t* entry_bytes = static_cast<std::uint8_t*>(entry);
    RenderCommand_UpdateModeVector_008DEB70(
        *reinterpret_cast<void**>(context_bytes + 8),
        *reinterpret_cast<std::int8_t*>(entry_bytes + 0x228));
    std::uint8_t* resource = *reinterpret_cast<std::uint8_t**>(entry_bytes + 8);
    if (resource != 0 &&
        (0x40000112u & ~*reinterpret_cast<std::uint32_t*>(resource)) != 0)
        resource = 0;
    std::uint8_t* order_field = resource + 0x14;
    const std::uint32_t order_offset =
        *reinterpret_cast<std::uint32_t*>(order_field);
    void* order_root =
        order_offset == 0 ? 0 : order_field + order_offset;
    void* node = order_root == 0
                     ? 0
                     : ParameterString_FindNode_00498FBC(
                           &order_root, "Order",
                           ByteString_Length_00425CAC("Order"));
    std::uint8_t* order = static_cast<std::uint8_t*>(node);
    if (order != 0) {
        order += 0x0c;
        const std::uint32_t offset = *reinterpret_cast<std::uint32_t*>(order);
        order = offset == 0 ? 0 : order + offset;
    }
    if (order == 0)
        return;
    const std::uint32_t count =
        *reinterpret_cast<std::uint32_t*>(entry_bytes + 0x230);
    for (std::uint32_t i = 0; i != count; ++i) {
        const std::uint32_t index =
            *reinterpret_cast<std::uint32_t*>(order + 0x10 + i * 4);
        std::uint8_t* table_field = resource + 0xc8;
        const std::uint32_t table_offset =
            *reinterpret_cast<std::uint32_t*>(table_field);
        std::uint8_t* table =
            table_offset == 0 ? 0 : table_field + table_offset;
        std::uint8_t* record_field = table + index * 4;
        const std::uint32_t record_offset =
            *reinterpret_cast<std::uint32_t*>(record_field);
        void* record =
            record_offset == 0 ? 0 : record_field + record_offset;
        std::uint8_t** owners = *reinterpret_cast<std::uint8_t***>(entry_bytes + 0x238);
        std::uint8_t* owner = owners[index];
        std::uint8_t* nested = *reinterpret_cast<std::uint8_t**>(owner + 0x4c);
        if (*reinterpret_cast<void**>(nested + 0xcc) != 0) {
            FUN_008DFAF8(
                *reinterpret_cast<void**>(context_bytes + 8),
                resource, index);
            FUN_008DC444(context, entry, record, index);
        }
    }
}
extern "C" void RenderCommand_SubmitPacket_001689E0(
    std::uint32_t key, std::uint32_t offset, std::uint32_t size,
    std::uint32_t record_index, std::uint32_t record_count,
    std::uint32_t flags, std::uint32_t finalize);
extern "C" void RenderCommand_FinalizeCurrentPacket_002A4618();
extern "C" void RenderCommand_FinalizeTrackedRange_008DD2A0();
extern "C" void RenderCommand_CaptureCurrentRange_0018BE38(
    std::uint32_t* byte_offset, std::uint32_t* byte_size,
    std::uint32_t* record_offset, std::uint32_t* record_count);
extern "C" void RenderCommand_SelectPacket_001ECE50(std::uint32_t key);
struct RenderResourcePacketView {
    std::uint8_t reserved[0x64];
    std::uint32_t keys[2];
    std::uint32_t active;
    std::uint32_t offset;
    std::uint32_t size;
    std::uint32_t record_index;
    std::uint32_t record_count;
    std::uint8_t copy_payload;
};
typedef char RenderResourcePacketView_active_at_6c[
    offsetof(RenderResourcePacketView, active) == 0x6c ? 1 : -1];
typedef char RenderResourcePacketView_copy_payload_at_80[
    offsetof(RenderResourcePacketView, copy_payload) == 0x80 ? 1 : -1];
struct RenderResourceSelectionView {
    std::uint8_t reserved[0x5c];
    std::uint32_t keys[4];
    std::uint32_t active;
    std::uint32_t byte_offset;
    std::uint32_t byte_size;
    std::uint32_t record_offset;
    std::uint32_t record_count;
};
typedef char RenderResourceSelectionView_active_at_6c[
    offsetof(RenderResourceSelectionView, active) == 0x6c ? 1 : -1];
typedef char RenderResourceSelectionView_record_count_at_7c[
    offsetof(RenderResourceSelectionView, record_count) == 0x7c ? 1 : -1];
// Retail 0x009164DC: submit the packet selected by a resource's active index.
extern "C" __attribute__((noinline)) void RenderResource_SubmitActivePacket_009164DC(void* resource) {
    RenderResourcePacketView* packet =
        static_cast<RenderResourcePacketView*>(resource);
    RenderCommand_SubmitPacket_001689E0(
        packet->keys[packet->active], packet->offset, packet->size,
        packet->record_index, packet->record_count, 0,
        packet->copy_payload);
}
extern "C" __attribute__((noinline)) void RenderResource_SelectActivePacket_001ECE18(void* resource) {
    RenderResourceSelectionView* selection =
        static_cast<RenderResourceSelectionView*>(resource);
    RenderCommand_FinalizeCurrentPacket_002A4618();
    RenderCommand_FinalizeTrackedRange_008DD2A0();
    RenderCommand_CaptureCurrentRange_0018BE38(
        &selection->byte_offset, &selection->byte_size,
        &selection->record_offset, &selection->record_count);
    RenderCommand_SelectPacket_001ECE50(selection->keys[selection->active]);
}
