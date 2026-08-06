#include <stdint.h>
void FUN_003AC8A8(void *destination, const void *source, int record_size,
                  int field_offset, int field_count);
__attribute__((noinline)) void FUN_003743B4(
    void *destination, const void *source)
{
    FUN_003AC8A8(destination, source, 0x70, 0x0c, 10);
}
