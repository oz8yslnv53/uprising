#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_NestedPointerValueGet_00B4132C(void *object) {
    uint32_t *nested = *(uint32_t **)((uint8_t *)object + 0x8u);
    if (nested != 0)
        return nested[0];
    return 0u;
}
