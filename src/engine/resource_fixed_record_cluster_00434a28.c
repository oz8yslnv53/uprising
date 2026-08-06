#include <stdint.h>
extern void *Engine_ForEachStrideCallback_00421EA4(
    void *base, void (*callback)(void *), uint32_t stride, uint32_t count);
void ResourceRecord_LinkAndMask_0043192C(void *value)
{
    uint8_t *record = (uint8_t *)value;
    *(void **)(record + 0) = record;
    *(void **)(record + 4) = record;
    *(void **)(record + 8) = record;
    *(uint32_t *)(record + 0x0c) =
        (*(uint32_t *)(record + 0x0c) & 0xfffffe00u) | 0xfffffe00u;
}
void ResourceRecord_Link_00448624(void *value)
{
    uint8_t *record = (uint8_t *)value;
    *(void **)(record + 0) = record;
    *(void **)(record + 4) = record;
    *(void **)(record + 8) = record;
}
void ResourceRecord_Link_00432FE0(void *value)
{
    uint8_t *record = (uint8_t *)value;
    *(void **)(record + 0) = record;
    *(void **)(record + 4) = record;
    *(void **)(record + 8) = record;
}
void ResourceRecord_SetInvalid_00431968(void *value)
{
    *(uint16_t *)value = 0xffffu;
}
static void clear_half_record(void *value)
{
    uint8_t *record = (uint8_t *)value;
    *(uint16_t *)(record + 0) = 0xffffu;
    *(uint32_t *)(record + 4) = 0;
    *(uint32_t *)(record + 8) = 0;
    *(uint32_t *)(record + 0x0c) = 0;
}
static void init_link_record(void *value)
{
    uint8_t *record = (uint8_t *)value;
    *(void **)(record + 0) = record;
    *(void **)(record + 4) = record;
    *(void **)(record + 8) = record;
    record[0x1a] = 0;
    *(uint16_t *)(record + 0x0c) = 0xffffu;
    *(uint16_t *)(record + 0x18) = 0xffffu;
    *(uint32_t *)(record + 0x10) = 0;
    *(float *)(record + 0x14) = 0.0f;
}
static void resource_fixed_record_init(void *value)
{
    uint8_t *base = (uint8_t *)value;
    uint32_t i;
    const uint32_t *defaults = (const uint32_t *)0x00dc261cu;
    for (i = 0; i < 0x0c; ++i)
        clear_half_record(base + i * 0x10 + 8);
    *(uint16_t *)(base + 0x1a0) = 0xffffu;
    *(uint32_t *)(base + 0x1a4) = 0;
    *(uint32_t *)(base + 0x1a8) = 0;
    *(uint32_t *)(base + 0x1ac) = 0;
    for (i = 0; i < 0x3e; ++i) {
        uint8_t *record = base + i * 0x1c;
        record[0x202] = 0;
        *(uint16_t *)(record + 0x1f4) = 0xffffu;
        *(uint16_t *)(record + 0x200) = 0xffffu;
        *(uint32_t *)(record + 0x1f8) = 0;
        *(float *)(record + 0x1fc) = 0.0f;
    }
    base[0x1d8] = 0;
    *(uint32_t *)(base + 0x1b0) = 0;
    *(float *)(base + 0x1b4) = 0.0f;
    *(uint32_t *)(base + 0x1b8) = 0;
    for (i = 0; i < 7; ++i)
        *(uint32_t *)(base + 0x1bc + i * 4) = defaults[i];
    *(float *)(base + 4) = 0.0f;
}
void *ResourceFixedRecord_Build_00434A28(uint8_t *record)
{
    uint8_t *cursor_bytes;
    void *cursor = Engine_ForEachStrideCallback_00421EA4(
        record + 8, clear_half_record, 0x10, 0x0c);
    cursor_bytes = (uint8_t *)cursor;
    *(uint16_t *)(cursor_bytes + 0x198) = 0xffffu;
    *(uint32_t *)(cursor_bytes + 0x19c) = 0;
    *(uint32_t *)(cursor_bytes + 0x1a0) = 0;
    *(uint32_t *)(cursor_bytes + 0x1a4) = 0;
    *(void **)(cursor_bytes + 0x1d4) = cursor_bytes + 0x1dc;
    *(void **)(cursor_bytes + 0x1d8) = cursor_bytes + 0x1dc;
    *(void **)(cursor_bytes + 0x1dc) = cursor_bytes + 0x1dc;
    *(void **)(cursor_bytes + 0x1e0) = cursor_bytes + 0x1dc;
    Engine_ForEachStrideCallback_00421EA4(
        cursor_bytes + 0x1e0, init_link_record, 0x1c, 0x3e);
    resource_fixed_record_init(record - 0x1e8);
    return record - 0x1e8;
}
