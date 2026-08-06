#include <stdint.h>
typedef struct CopySevenFloats_0031A430 {
    float values[7];
} CopySevenFloats_0031A430;
__attribute__((noinline)) void Record_CopySevenFloatsAndFillFlag_0031A430(void *object)
{
    CopySevenFloats_0031A430 *destination =
        (CopySevenFloats_0031A430 *)((uint8_t *)object + 0x1e0);
    const CopySevenFloats_0031A430 *source =
        (const CopySevenFloats_0031A430 *)((uint8_t *)object + 0x1e4);
    *destination = *source;
    *(uint32_t *)((uint8_t *)object + 0x1fc) = ~0u;
}
