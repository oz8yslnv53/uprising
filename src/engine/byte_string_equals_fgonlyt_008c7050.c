#include <stdint.h>
extern const char DAT_008C7084[];
extern uint32_t ByteString_Length_00425CAC(const char *text);
extern int ByteString_CompareBounded_00396158(const char *left,
                                              const char *right,
                                              uint32_t count);
uint32_t ByteString_EqualsFgOnlyt_008C7050(const char *text)
{
    uint32_t result = 0;
    const uint32_t count = ByteString_Length_00425CAC(DAT_008C7084);
    if (ByteString_CompareBounded_00396158(text, DAT_008C7084, count) == 0)
        result = 1;
    return result;
}
