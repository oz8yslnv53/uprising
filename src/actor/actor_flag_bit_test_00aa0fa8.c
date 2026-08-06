#include <stdint.h>
__attribute__((noinline)) int ActorFlagBit_Test_00AA0FA8(void *object, uint32_t index) {
    if (index >= 6u)
        return 0;
    return (*(uint32_t *)((uint8_t *)object + 0x144u) & (1u << index)) != 0u;
}
