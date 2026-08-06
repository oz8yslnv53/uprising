#include <stdint.h>
extern int ResourceLookup_Resolve_002606B4(void * object, void * key,
                                           int32_t * result);
extern int ResourceRecord_GetOffset_00B41688(void * record);
__attribute__((noinline)) int ResourceLookup_Offset_00B40A5C(void * object, void * key)
{
    int32_t result[3];
    int base;
    result[0] = -1;
    result[1] = -1;
    result[2] = 0;
    if (ResourceLookup_Resolve_002606B4(object, key, result) == 0)
        return 0;
    base = *(int32_t *)((uint8_t *)object + 0x10c);
    return ResourceRecord_GetOffset_00B41688((uint8_t *)object + 0x110) +
           result[1] + base;
}
