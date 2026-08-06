#include <stdint.h>
__attribute__((noinline)) void ResourceRecord_SetPhaseMetadata_00908530(
    uint8_t *record, uint32_t metadata, uint8_t mode, float phase)
{
    *(float *)(record + 0xf4U) = phase;
    *(uint32_t *)(record + 0xfcU) = metadata;
    *(uint32_t *)(record + 0xf8U) = 0;
    *(uint8_t *)(record + 0xc8U) = mode;
}
