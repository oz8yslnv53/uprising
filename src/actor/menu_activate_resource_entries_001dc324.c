#include <stdint.h>
extern void ResourceTree_SetEntryActive_0025EE3C(void *entry,
                                                  uint8_t active);
extern void *MenuResource_FindNamedObject_00274FE8(void *resource,
                                                   char *name);
extern uint32_t ResourceTree_CheckEntry_0022CF04(void *left, void *right);
extern void EngineResource_ActivatePendingStates_0025E9D8(void *resource);
uint32_t Menu_ActivateResourceEntries_001DC324(uint8_t *object)
{
 static char name[] = "MN_B0002";
 void *named;
 int i;
 ResourceTree_SetEntryActive_0025EE3C(
     (uint8_t *)*(void **)(*(void **)(object + 0x39c) + 0x20) + 8, 1);
 for (i = 0; i < 9; ++i) {
  named = MenuResource_FindNamedObject_00274FE8(
      *(void **)(object + 0x30c + i * 4), name);
  *(uint32_t *)((uint8_t *)named + 0xc0) &= ~0x10u;
 }
 if (ResourceTree_CheckEntry_0022CF04(object + 0x26c, object + 0x27c) != 0)
  EngineResource_ActivatePendingStates_0025E9D8(
      *(void **)(*(void **)(object + 0x39c) + 0x20));
 return 0;
}
