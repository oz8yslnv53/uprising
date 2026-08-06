#include <stdint.h>
extern const uint32_t DAT_00CB0C50[];
__attribute__((noinline)) uint32_t Engine_ClampedTableLookup_002A7450(int32_t index) {
    if (index > 5)
        index = 5;
    return DAT_00CB0C50[index];
}
