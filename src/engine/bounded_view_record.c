#include <stddef.h>
#include <stdint.h>
struct MessageTemplateGlobalsView {
    uint32_t extra_field;
    uint32_t template_tag;
    void *small_view_data;
    void *extended_view_data;
};
extern struct MessageTemplateGlobalsView DAT_009AB948;
extern void BoundedCursor_Step_009AB784(void *record);
__attribute__((noinline)) void BoundedView_InitEmpty_009ABDC0(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)(bytes + 4) = 0;
    *(uint32_t *)(bytes + 0xc) = 0;
    *(uint32_t *)(bytes + 8) = 0;
    bytes[0x10] = 1;
}
__attribute__((noinline)) void BoundedView_InitEmptyExtended_009AB688(void *record)
{
    uint8_t *bytes = (uint8_t *)record;
    *(uint32_t *)(bytes + 4) = 0;
    *(uint32_t *)(bytes + 8) = 0;
    *(uint32_t *)(bytes + 0xc) = 0;
    bytes[0x10] = 0x8e;
    *(uint32_t *)(bytes + 0x14) = 0;
    bytes[0x18] = 1;
}
__attribute__((noinline)) void BoundedView_InitFromSource_009ABD74(void *record, const void *source,
                                          int32_t start_offset)
{
    uint8_t *bytes = (uint8_t *)record;
    const uint8_t *src = (const uint8_t *)source;
    *(uint32_t *)(bytes + 4) = 0;
    *(uint32_t *)(bytes + 0xc) = 0;
    *(uint32_t *)(bytes + 8) = 0;
    bytes[0x10] = 1;
    if (src != NULL) {
        int32_t data_ptr = *(const int32_t *)(src + 4);
        uint32_t capacity = *(const uint32_t *)(src + 8);
        *(int32_t *)(bytes + 4) = data_ptr;
        *(uint32_t *)(bytes + 8) = capacity;
        *(int32_t *)(bytes + 0xc) = start_offset;
        if (data_ptr != 0 && (uint32_t)start_offset + 2u <= capacity)
            bytes[0x10] = 0;
    }
}
__attribute__((noinline)) void BoundedView_InitFromSourceExtended_009AB438(void *record,
                                                  const void *source,
                                                  int32_t start_offset)
{
    uint8_t *bytes = (uint8_t *)record;
    const uint8_t *src = (const uint8_t *)source;
    *(uint32_t *)(bytes + 4) = 0;
    *(uint32_t *)(bytes + 8) = 0;
    *(uint32_t *)(bytes + 0xc) = 0;
    bytes[0x10] = 0x8e;
    *(uint32_t *)(bytes + 0x14) = 0;
    bytes[0x18] = 1;
    if (src != NULL) {
        int32_t data_ptr = *(const int32_t *)(src + 4);
        uint32_t capacity = *(const uint32_t *)(src + 8);
        *(int32_t *)(bytes + 4) = data_ptr;
        *(uint32_t *)(bytes + 8) = capacity;
        *(int32_t *)(bytes + 0xc) = start_offset;
        if (data_ptr != 0 && (uint32_t)start_offset + 2u <= capacity)
            bytes[0x18] = 0;
        BoundedCursor_Step_009AB784(record);
    }
}
__attribute__((noinline)) void *BoundedView_InitFromRaw_009AB8FC(void *record, uint32_t header1,
                                        uint32_t header2)
{
    uint32_t *words = (uint32_t *)record;
    uint32_t saved_field = DAT_009AB948.extra_field;
    words[0] = DAT_009AB948.template_tag;
    words[1] = header1;
    words[2] = header2;
    words[3] = (uint32_t)(uintptr_t)DAT_009AB948.small_view_data;
    BoundedView_InitEmpty_009ABDC0(words + 3);
    words[9] = 0;
    words[8] = saved_field;
    words[10] = 0;
    words[0xb] = (uint32_t)(uintptr_t)DAT_009AB948.extended_view_data;
    BoundedView_InitEmptyExtended_009AB688(words + 0xb);
    return record;
}
