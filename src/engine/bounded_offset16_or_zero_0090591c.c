#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_BoundedOffset16OrZero_0090591C(const unsigned char *base,
                                               int32_t index)
{
    if (index < 0x10)
        return (uint32_t)(base + index * 2 + 0xa0);
    return 0;
}
