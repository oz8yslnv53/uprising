#include <stdint.h>
__attribute__((noinline)) void Engine_UpdateTripleIfFlagAtA_009AE918(void *record,
                                            uint8_t byte_value,
                                            uint32_t first,
                                            uint32_t second)
{
    unsigned char *bytes = (unsigned char *)record;
    if (bytes[0xa] != 0) {
        bytes[0x9] = byte_value;
        *(uint32_t *)(bytes + 0xc) = first;
        *(uint32_t *)(bytes + 0x10) = second;
    }
}
