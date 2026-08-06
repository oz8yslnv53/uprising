#include <stdint.h>
__attribute__((noinline)) void Engine_IndexedByteSet_002752A0(uint8_t *base, int index, uint8_t value) {
    base[((index << 3) - index) * 4 + 0x0d] = value;
}
