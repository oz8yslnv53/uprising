#include <stdint.h>
extern void *ResourceTree_ResolveCurrentEntry_002A6268(void *owner);
extern void ResourceTransform_PrepareUpdate_0025F180(void *output_pair,
                                                      void *state,
                                                      float frame_step);
extern void ResourceTransform_Advance_0025EED0(void *state,
                                                float frame_step);
extern void FUN_002514B8(void *object);
extern void FUN_00218518(void *object);
uint32_t Menu_AdvanceTransformAndRefresh_001E0E28(uint8_t *object,
                                                   uint32_t unused1,
                                                   uint32_t unused2,
                                                   uint8_t *update)
{
 uint8_t pair[8];
 void *entry;
 void *state;
 (void)unused1;
 (void)unused2;
 entry = ResourceTree_ResolveCurrentEntry_002A6268(*(void **)(object + 0x30));
 state = *(void **)((uint8_t *)entry + 0x20);
 ResourceTransform_PrepareUpdate_0025F180(pair, (uint8_t *)state + 8,
                                           *(float *)(update + 0xc));
 ResourceTransform_Advance_0025EED0((uint8_t *)state + 8,
                                     *(float *)(update + 0xc));
 FUN_002514B8(object);
 FUN_00218518(object);
 return 0;
}
