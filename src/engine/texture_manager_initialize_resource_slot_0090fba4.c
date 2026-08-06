#include <stdint.h>
extern void FileResource_FindPayload_005AEABC(uint32_t *output,
                                               uint32_t key);
extern void MsgPrjBnHandle_Bind_00927108(void **destination,
                                          const void *raw_resource);
extern uint32_t TextureResource_CalculateSize_0090A4AC(
    uint32_t metadata_pointer, uint32_t metadata_value);
extern void *Engine_AllocateTaggedBlock_0047466C(
    uint32_t element_size, const void *type_tag, uint32_t count);
extern void TextureResource_Initialize_00909B34(
    uint8_t *record, void *allocation, uint8_t *metadata,
    uint32_t metadata_value);
extern void RenderState_MarkDirty_00112A7C(uint32_t mask);
uint32_t TextureManager_InitializeResourceSlot_0090FBA4(
    uint8_t *resource, uint32_t count, uint32_t payload_key,
    uint32_t metadata_key)
{
    uint32_t payload[2];
    uint32_t metadata[2];
    void *allocation;
    FileResource_FindPayload_005AEABC(payload, payload_key);
    MsgPrjBnHandle_Bind_00927108(
        (void **)(resource + 0x740),
        (const void *)(uintptr_t)payload[0]);
    *(uint8_t **)(resource + 0x720) = resource + 0x740;
    *(uint8_t **)(resource + 0x730) = resource + 0x740;
    FileResource_FindPayload_005AEABC(metadata, metadata_key);
    allocation = Engine_AllocateTaggedBlock_0047466C(
        TextureResource_CalculateSize_0090A4AC(
            metadata[0], metadata[1]),
        (const void *)(uintptr_t)0x0090FC28U, count);
    *(void **)(resource + 0x68C) = allocation;
    TextureResource_Initialize_00909B34(
        resource + 4, allocation, (uint8_t *)(uintptr_t)metadata[0],
        metadata[1]);
    RenderState_MarkDirty_00112A7C(0x3FFFU);
    *resource = 1;
    return 1;
}
