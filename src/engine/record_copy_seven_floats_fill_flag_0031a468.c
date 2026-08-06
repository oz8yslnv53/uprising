#include <stdint.h>
typedef struct CopySevenFloats_0031A468 {
    float values[7];
} CopySevenFloats_0031A468;
__attribute__((noinline)) void Record_CopySevenFloatsFillFlag_0031A468(void *object)
{
    CopySevenFloats_0031A468 *destination =
        (CopySevenFloats_0031A468 *)((uint8_t *)object + 0x1c0);
    const CopySevenFloats_0031A468 *source =
        (const CopySevenFloats_0031A468 *)((uint8_t *)object + 0x1c4);
    *destination = *source;
    *(uint32_t *)((uint8_t *)object + 0x1dc) = ~0u;
}
