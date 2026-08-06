#include <stdint.h>
extern void ResourceTree_SetEntryActive_0025EE3C(void *entry, uint8_t active);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *resource);
int FUN_00171B48(void *object, void *unused2, void *unused3,
                 void *step_record)
{
    void *owner = *(void **)((uint8_t *)object + 0x114);
    (void)unused2;
    (void)unused3;
    ResourceTree_SetEntryActive_0025EE3C(
        (uint8_t *)(*(void **)((uint8_t *)owner + 0x20)) + 0x08, 1);
    if (*(uint32_t *)((uint8_t *)object + 0x124) > 0x42A00000u) {
        EngineResource_ActivatePendingStates_0025E9D8(
            *(void **)((uint8_t *)*(void **)((uint8_t *)object + 0x114) + 0x20));
    }
    *(float *)((uint8_t *)object + 0x124) +=
        *(float *)((uint8_t *)step_record + 0x18);
    return 0;
}
