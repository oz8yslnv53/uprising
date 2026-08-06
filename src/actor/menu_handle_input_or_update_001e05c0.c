#include <stdint.h>
extern void MenuAction_HandleInput_00240F88(void *state, void *input);
extern void FUN_002179D8(void *object, float frame_step);
extern void FUN_00215438(void *object);
uint32_t Menu_HandleInputOrUpdate_001E05C0(uint8_t *object,
                                            uint32_t unused1,
                                            void *input,
                                            uint8_t *update)
{
 (void)unused1;
 if ((*(uint8_t *)(object + 0x35) & 0x10) != 0) {
  MenuAction_HandleInput_00240F88(*(void **)(object + 0x4f4), input);
 } else {
  *(uint32_t *)(object + 0x2e0) |= *(uint32_t *)((uint8_t *)input + 0x2c);
  *(uint32_t *)(object + 0x2e4) = *(uint32_t *)((uint8_t *)input + 0x38);
  if ((*(uint8_t *)(object + 0x34) & 0x10) != 0) {
   if ((*(uint32_t *)((uint8_t *)input + 0x38) & 0xd00) == 0)
    *(uint8_t *)(object + 0x34) &= (uint8_t)~0x10;
  } else {
   FUN_002179D8(object, *(float *)(update + 0xc));
  }
  FUN_00215438(object);
 }
 return 0;
}
