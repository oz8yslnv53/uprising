#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern unsigned int ResourceTree_CheckEntry_0022CF04(void *object,
                                                     void *entry);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *state);
__attribute__((noinline)) int FUN_00242250(
    void *object, void *unused1, void *unused2, void *delta_record)
{
    uint8_t *bytes = (uint8_t *)object;
    void *entry = ResourceTree_ResolveCurrentEntry_002A6268(
        *(void **)(bytes + 0x30u));
    (void)unused1;
    (void)unused2;
    if (ResourceTree_CheckEntry_0022CF04(bytes + 0x34u, bytes + 0x44u) != 0) {
        if (*(float *)(bytes + 0x114u) > 10.0f)
            EngineResource_ActivatePendingStates_0025E9D8(
                *(void **)((uint8_t *)entry + 0x20u));
        *(float *)(bytes + 0x114u) +=
            *(float *)((uint8_t *)delta_record + 0x18u);
    }
    return 0;
}
