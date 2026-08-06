#include <stdint.h>
extern void FUN_001D7C60(void *object, uint32_t first, uint32_t second);
int FUN_001AB9D8(void *object, void *unused, void *input)
{
    uint8_t *bytes = (uint8_t *)object;
    uint8_t *input_bytes = (uint8_t *)input;
    uint32_t first = *(uint32_t *)(input_bytes + 0x58);
    (void)unused;
    FUN_001D7C60(object, first, *(uint32_t *)(input_bytes + 0x5c));
    *(uint32_t *)(*(uint8_t **)(bytes + 0x38) + 0x1fc) = first;
    return 0;
}
