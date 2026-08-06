#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_CompareRecordHeader_00637B98(const void *left,
                                             const void *right)
{
    const int8_t *left_bytes = (const int8_t *)left;
    const int8_t *right_bytes = (const int8_t *)right;
    if (left_bytes[1] != right_bytes[0])
        return 0;
    if (left_bytes[2] != right_bytes[1])
        return 0;
    if (*(const uint32_t *)(left_bytes + 4) !=
        *(const uint32_t *)(right_bytes + 8))
        return 0;
    return *(const uint32_t *)(left_bytes + 8) ==
                   *(const uint32_t *)(right_bytes + 4);
}
