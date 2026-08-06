#include <stdint.h>
extern void Record_ApplyWordPair_005CC6B8(void *object, uint32_t *pair);
__attribute__((noinline)) void Record_CallWithLiteralPair_008A48E8(void *object)
{
    uint32_t pair;
    pair = 0x00010001u;
    Record_ApplyWordPair_005CC6B8(object, &pair);
}
