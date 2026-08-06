#include <stdint.h>
uint32_t FUN_0039FA2C(uint32_t mode, const void *source, uint32_t size);
void FUN_002A74C4(uint32_t *output, const uint32_t *source, int mode,
                  const uint32_t *auxiliary);
uint32_t FUN_00328204(const int16_t *record);
uint32_t ByteFlag_Bit5Get_0032824C(const void *object);
int RenderDescriptor_Validate_002F3FE0(const int *record, int check_strings);
__attribute__((noinline)) uint32_t RenderDescriptor_BuildAndValidate_00373D94(
    const uint32_t *source)
{
    uint8_t descriptor[0x124];
    uint32_t result = 0;
    if (FUN_0039FA2C(0, source, 0x60) == 0) {
        FUN_002A74C4((uint32_t *)descriptor, source, 1,
                     (const uint32_t *)((const uint8_t *)source + 0x48));
        if (FUN_00328204((const int16_t *)(descriptor + 0x108)) == 0 &&
            ByteFlag_Bit5Get_0032824C(descriptor + 0x108) == 0) {
            result = (uint32_t)RenderDescriptor_Validate_002F3FE0(
                (const int *)descriptor, 1);
        }
    }
    return result;
}
