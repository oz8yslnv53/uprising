#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_Bit28Get_00B52860(const uint32_t *word) {
    return (*word & 0x10000000u) >> 28;
}
