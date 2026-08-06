#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTree_SetTransitionMode_0025F13C(void *resource,
                                                     uint32_t mode);
extern void *MenuResource_FindNamedObject_00274FE8(void *resource,
                                                   char *name);
uint32_t Menu_ResetTransitionFlags_001DBD08(uint8_t *object)
{
 static char name[] = "MN_B0002";
 uint8_t *entry;
 void *named;
 int i;
 entry = (uint8_t *)ResourceTree_ResolveCurrentEntry_002A6268(
     *(void **)(object + 0x30));
 ResourceTree_SetTransitionMode_0025F13C(
     (uint8_t *)*(void **)(entry + 0x20) + 8, 2);
 for (i = 0; i < 9; ++i) {
  named = MenuResource_FindNamedObject_00274FE8(
      *(void **)(object + 0x30c + i * 4), name);
  *(uint32_t *)((uint8_t *)named + 0xc0) &= ~4u;
 }
 return 0;
}
