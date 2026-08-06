#include <stdint.h>
extern void *ResourceTree_FindMenuEquip01AParam_002253E4(void *object);
void ResourceTree_ApplySelectedParamLinks_001FA824(void *object,
                                                   uint32_t index)
{
    uint8_t *base;
    uint8_t *record;
    uint32_t group;
    base = (uint8_t *)object;
    record = (uint8_t *)ResourceTree_FindMenuEquip01AParam_002253E4(
        *(void **)(base + 0x30u));
    if (*(void **)(base + 0xf4u) != 0)
        *(uint32_t *)(*(uint8_t **)(base + 0xf4u) + 0x0cu) =
            *(uint32_t *)(record + index * 0x2cu + 0x6fcu);
    if (*(void **)(base + 0xfcu) != 0)
        *(uint32_t *)(*(uint8_t **)(base + 0xfcu) + 0x0cu) =
            *(uint32_t *)(record + index * 0x2cu + 0x8e0u);
    if (*(void **)(base + 0xf8u) != 0) {
        group = *(uint32_t *)(base + 0x1c0u);
        *(uint32_t *)(*(uint8_t **)(base + 0xf8u) + 0x0cu) =
            *(uint32_t *)(record + group * 0x1e4u +
                          index * 0x2cu + 0xac4u);
    }
}
