#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetEntryActive_0025EE3C(void *entry,
                                                  uint8_t active);
extern uint32_t ResourceTree_CheckEntry_0022CF04(void *object, void *entry);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *resource);
uint32_t Menu_AdvanceTimedActivation_001E2620(uint8_t *object,
                                               uint32_t unused1,
                                               uint32_t unused2,
                                               uint8_t *update)
{
 void *entry;
 (void)unused1;
 (void)unused2;
 entry = ResourceTree_ResolveCurrentEntry_002A6268(*(void **)(object + 0x30));
 ResourceTree_SetEntryActive_0025EE3C(
     (uint8_t *)*(void **)((uint8_t *)entry + 0x20) + 8, 1);
 if (ResourceTree_CheckEntry_0022CF04(object + 0x34, object + 0x44) != 0 &&
     *(float *)(object + 0xe0) > 10.0f)
  EngineResource_ActivatePendingStates_0025E9D8(
      *(void **)((uint8_t *)entry + 0x20));
 *(float *)(object + 0xe0) += *(float *)(update + 0x18);
 return 0;
}
