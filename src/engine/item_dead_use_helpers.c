#include <stddef.h>
#include <stdint.h>
#include "item_object_views.h"
extern int32_t FUN_003b4fe4(void *guard);  
extern void *BoundedView_InitFromSourceExtended_009AB438(void *record,
                                                          const void *source,
                                                          int32_t start_offset);
extern void *BoundedView_InitFromSource_009ABD74(void *record,
                                                  const void *source,
                                                  int32_t start_offset);
extern uint32_t PackHandleId_00A2B654(uint32_t index);
extern void *ResourceStatus_LookupHandleValid_00611748(uint32_t handle);
extern void *ComponentInstance_Resolve_005B0E00(void *record);
extern uint32_t GenericGlobalKeyValidator_005B0070(void *candidate);
__attribute__((noinline)) void *Engine_LazyLinkedListSentinel_00520740(void)
{
    extern uint32_t *g_LinkedListGuard_00520790;  
    extern int32_t *g_LinkedListSentinel_00520794;  
    if ((*g_LinkedListGuard_00520790 & 1) == 0 &&
        FUN_003b4fe4(g_LinkedListGuard_00520790) != 0) {
        int32_t *sentinel = g_LinkedListSentinel_00520794;
        *sentinel = (int32_t)(intptr_t)sentinel;
        sentinel[1] = (int32_t)(intptr_t)sentinel;
        sentinel[2] = (int32_t)(intptr_t)sentinel;
    }
    return g_LinkedListSentinel_00520794;
}
__attribute__((noinline)) void *FieldOffset0x218_00521E9C(void *record)
{
    if (record != NULL)
        return (uint8_t *)record + 0x218;
    return NULL;
}
__attribute__((noinline)) void *ItemHandlerOwner_PrepareSlice0x1DC_00A28CA4(struct ItemEffectRecordView *resource)
{
    if (resource->mode_selector_119 != 0) {
        resource->view2_source_field_1d4 = resource->view1_slice_field_1c0;
        resource->view2_source_capacity_1d8 = (uint32_t)resource->view1_slice_cursor_1c8;
        BoundedView_InitFromSourceExtended_009AB438(
            &resource->view2_slice_data_1dc, &resource->view2_source_data_1d0, 0);
        return &resource->view2_slice_data_1dc;
    }
    return NULL;
}
__attribute__((noinline)) void ItemLinkedResource_ClearFields_00A283BC(struct ItemEffectRecordView *resource)
{
    resource->resolved_owner_0bc = NULL;
    resource->has_reaction_0c2 = 0;
    resource->flag_0c0 = 0;
    resource->field_0c4 = 0;
    resource->masked_component_0c8 = NULL;
    resource->resolved_owner_0cc = NULL;
    resource->component_type_index_0d0 = 0;
    resource->cooldown_active_0e0 = 0;
}
__attribute__((noinline)) void ItemRecord_StoreVectorAndFlags_004A4B60(void *record, const uint32_t vector[3])
{
    uint8_t *bytes = (uint8_t *)record;
    void *machine;
    *(uint32_t *)(bytes + 0x38) = vector[0];
    *(uint32_t *)(bytes + 0x3c) = vector[1];
    *(uint32_t *)(bytes + 0x40) = vector[2];
    machine = *(void **)(bytes + 0x30);
    *(uint32_t *)((uint8_t *)machine + 0x74) = *(uint32_t *)(bytes + 0x38);
    *(uint32_t *)((uint8_t *)machine + 0x78) = *(uint32_t *)(bytes + 0x3c);
    *(uint32_t *)((uint8_t *)machine + 0x7c) = *(uint32_t *)(bytes + 0x40);
    bytes[0x35] = (uint8_t)(bytes[0x35] & ~0x2u);
    *(uint32_t *)(bytes + 0xf0) = vector[0];
    *(uint32_t *)(bytes + 0xf4) = vector[1];
    *(uint32_t *)(bytes + 0xf8) = vector[2];
    *(uint32_t *)(bytes + 0x160) = 0;
    bytes[0x34] = (uint8_t)(bytes[0x34] | 0x4u);
}
__attribute__((noinline)) uint32_t ItemLinkedResourceValid_00B5B8BC(struct ItemEffectRecordView *resource)
{
    uint8_t index = resource->component_type_index_0d0;
    if (index != 0) {
        uint32_t handle = PackHandleId_00A2B654(index);
        void *component = ResourceStatus_LookupHandleValid_00611748(handle);
        if (component != NULL) {
            void *resolved = ComponentInstance_Resolve_005B0E00(component);
            if (resolved != NULL)
                return GenericGlobalKeyValidator_005B0070(resolved);
        }
    }
    return 0;
}
__attribute__((noinline)) void *ItemLinkedResource_PrepareSlice0x1BC_00A28E34(struct ItemEffectRecordView *resource)
{
    int flag_clear = resource->message_dispatch_active_118 == 0;
    if (flag_clear && resource->mode_selector_119 == 0) {
        resource->view1_source_field_1b4 =
            (uint32_t)(uintptr_t)((uint8_t *)resource + 0x120);
        resource->view1_source_capacity_1b8 = 0x90;
        BoundedView_InitFromSource_009ABD74(&resource->view1_slice_data_1bc,
                                             &resource->view1_source_data_1b0, 0);
        return &resource->view1_slice_data_1bc;
    }
    return NULL;
}
