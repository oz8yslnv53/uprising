// 001F52FC: store a halfword at base[index], ignoring the first argument.
#include <stdint.h>
__attribute__((noinline)) void IndexedHalfwordStore_001F52FC(
    void *unused, uint16_t *base, int index, uint16_t value)
{
    (void)unused;
    base[index] = value;
}
