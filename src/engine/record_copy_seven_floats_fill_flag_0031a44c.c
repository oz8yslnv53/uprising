#include <stdint.h>
typedef struct CopySevenFloats_0031A44C {
    float values[7];
} CopySevenFloats_0031A44C;
__attribute__((noinline)) void Record_CopySevenFloatsFillFlag_0031A44C(void *object)
{
    CopySevenFloats_0031A44C *destination =
        (CopySevenFloats_0031A44C *)((uint8_t *)object + 0x180);
    const CopySevenFloats_0031A44C *source =
        (const CopySevenFloats_0031A44C *)((uint8_t *)object + 0x184);
    *destination = *source;
    *(uint32_t *)((uint8_t *)object + 0x19c) = ~0u;
}
