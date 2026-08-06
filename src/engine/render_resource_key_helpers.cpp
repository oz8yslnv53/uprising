#include <stdint.h>
typedef void *(*ResourceAllocate)(uint32_t, uint32_t, uint32_t, uint32_t);
typedef void (*ResourceRelease)(uint32_t, uint32_t, uint32_t);
extern "C" uint8_t g_RenderCommand_Context_00DBC490[];
static uint8_t *const g_allocator = (uint8_t *)0x00D4D45Cu;
extern "C" __attribute__((noinline)) void FUN_00152948(uint32_t key) {
    if (key == 0x400u)
        *(uint32_t *)(g_RenderCommand_Context_00DBC490 + 0x124) = 0;
    else if (key == 0x401u)
        *(uint32_t *)(g_RenderCommand_Context_00DBC490 + 0x124) = 1;
    else if (key == 0x410u)
        *(uint32_t *)(g_RenderCommand_Context_00DBC490 + 0x124) = 2;
}
extern "C" __attribute__((noinline)) void RenderResource_ReserveUniqueKeys_00152AC4(
    int32_t count, uint32_t *output) {
    ResourceAllocate allocate = *(ResourceAllocate *)g_allocator;
    int32_t index;
    if (count <= 0)
        return;
    for (index = 0; index < count; ++index) {
        uint32_t key = *(uint32_t *)(g_allocator + 0x0c);
        uint8_t *record = allocate == 0 ? (uint8_t *)0 :
            (uint8_t *)allocate(0x10000u, 0x100u, 0, 0x1cu);
        uint32_t word;
        for (word = 0; word != 7; ++word)
            *(uint32_t *)(record + word * 4) = 0;
        for (;;) {
            uint8_t **bucket = (uint8_t **)(
                g_RenderCommand_Context_00DBC490 + 0xa4 + (key & 0x1fu) * 4);
            {
                uint8_t *head = *bucket;
                if (head == 0) {
                    *(uint32_t *)record = key;
                    *(uint8_t **)(record + 0x18) = (uint8_t *)0;
                    *bucket = record;
                    output[index] = key;
                    *(uint32_t *)(g_allocator + 0x0c) = *(uint32_t *)(g_allocator + 0x0c) + 1;
                    break;
                }
                if (*(uint32_t *)head == key) {
                    ++key;
                    continue;
                }
                if (*(uint32_t *)head > key) {
                    *(uint32_t *)record = key;
                    *(uint8_t **)(record + 0x18) = head;
                    *bucket = record;
                    output[index] = key;
                    *(uint32_t *)(g_allocator + 0x0c) = *(uint32_t *)(g_allocator + 0x0c) + 1;
                    break;
                }
                for (;;) {
                    uint8_t *next = *(uint8_t **)(head + 0x18);
                    if (next == 0) {
                        *(uint32_t *)record = key;
                        *(uint8_t **)(record + 0x18) = (uint8_t *)0;
                        *(uint8_t **)(head + 0x18) = record;
                        output[index] = key;
                        *(uint32_t *)(g_allocator + 0x0c) = *(uint32_t *)(g_allocator + 0x0c) + 1;
                        break;
                    }
                    if (*(uint32_t *)next == key) {
                        ++key;
                        break;
                    }
                    if (*(uint32_t *)next > key) {
                        *(uint32_t *)record = key;
                        *(uint8_t **)(record + 0x18) = next;
                        *(uint8_t **)(head + 0x18) = record;
                        output[index] = key;
                        *(uint32_t *)(g_allocator + 0x0c) = *(uint32_t *)(g_allocator + 0x0c) + 1;
                        head = (uint8_t *)0;
                        break;
                    }
                    head = next;
                }
                if (head == 0)
                    break;
            }
        }
    }
}
extern "C" __attribute__((noinline)) void FUN_001529B4(uint32_t value, uint32_t auxiliary) {
    uint32_t bucket = *(uint32_t *)(g_RenderCommand_Context_00DBC490 + 0x124);
    uint8_t *slot = g_RenderCommand_Context_00DBC490 + bucket * 4;
    *(uint32_t *)(slot + 0x134) = value;
    bucket = *(uint32_t *)(g_RenderCommand_Context_00DBC490 + 0x124);
    slot = g_RenderCommand_Context_00DBC490 + bucket * 4;
    *(uint32_t *)(slot + 0x140) = auxiliary;
}
extern "C" __attribute__((noinline)) void RenderResource_ReplaceBacking_001529D8(uint32_t key,
                              uint32_t dimension_a, uint32_t dimension_b,
                              uint32_t selector) {
    const uint32_t base_key = 0x8057u;
    uint32_t type;
    const uint32_t bucket = *(uint32_t *)(g_RenderCommand_Context_00DBC490 + 0x124);
    uint8_t *record = *(uint8_t **)(g_RenderCommand_Context_00DBC490 + 0x128 + bucket * 4);
    if (key == base_key) {
        type = 2;
    } else if (key < base_key) {
        if (key == 0x8051u)
            type = 3;
        else if (key == 0x8056u)
            type = 2;
        else
            return;
    } else if (key - base_key == 1u) {
        type = 4;
    } else if (key - base_key == 0xd0bu) {
        type = 2;
    } else {
        return;
    }
    if (selector != 0x10000u && selector != 0x20000u &&
        selector != 0x30000u)
        return;
    {
        ResourceRelease release = *(ResourceRelease *)(g_allocator + 4);
        ResourceAllocate allocate = *(ResourceAllocate *)g_allocator;
        uint32_t old_handle = *(uint32_t *)(record + 4);
        if (old_handle != 0 && release != 0)
            release(*(uint32_t *)(record + 0x14), 0x104u,
                    *(uint32_t *)record);
        uint32_t new_handle = allocate == 0 ? 0 :
            (uint32_t)(uintptr_t)allocate(selector, 0x104u,
                                          *(uint32_t *)record,
                                          type * dimension_a * dimension_b);
        *(uint32_t *)(record + 0x14) = selector;
        *(uint32_t *)(record + 4) = new_handle;
        *(uint32_t *)(record + 8) = key;
        *(uint32_t *)(record + 0x0c) = dimension_a;
        *(uint32_t *)(record + 0x10) = dimension_b;
    }
}
