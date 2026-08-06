#include <stdint.h>
extern int MappedRegion_Register_0018682C(void *registry, void *region,
                                          uint32_t size, uint32_t flags);
extern void Platform_ReportServiceError_003D1B64(uint32_t result);
void MemoryRegion_RegisterAligned_00129D58(uint8_t *region, uint32_t size)
{
    uint32_t aligned_size;
    if (*(uint8_t *)(uintptr_t)0x00d4d75cu != 0 &&
        *(uint32_t *)(region + 8) == 0) {
        aligned_size = (size + 0xfffu) & 0xfffff000u;
        if (MappedRegion_Register_0018682C(
                (void *)(uintptr_t)0x00dbeaecu, region, aligned_size, 0) == 0)
            Platform_ReportServiceError_003D1B64(0xd8601837u);
        region[0x10] = 0;
    }
}
