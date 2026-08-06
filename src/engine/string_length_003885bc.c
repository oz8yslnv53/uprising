#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_StringLength_003885BC(const char *text) {
    uint32_t length = 0;
    for (;;) {
        if (text[length] == '\0')
            return length;
        ++length;
    }
}
