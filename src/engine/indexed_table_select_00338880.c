#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_SelectIndexedTableValue_00338880(void *unused,
                                                  uint32_t index,
                                                  int alternate) {
    (void)unused;
    if (index > 11u)
        return 0;
    if (alternate == 0)
        return ((const uint32_t *)0x00D47860u)[index];
    return ((const uint32_t *)0x00D47890u)[index];
}
