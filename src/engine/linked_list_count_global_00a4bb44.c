#include <stdint.h>
__attribute__((noinline)) int FUN_00A4BB44(void)
{
    uint8_t* node = *(uint8_t**)(uintptr_t)(0x00d48e70u + 4u);
    int count = 0;
    while (node != 0) {
        ++count;
        node = *(uint8_t**)(node + 0x10u);
    }
    return count;
}
