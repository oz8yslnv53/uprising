#include <stdint.h>
extern void Engine_StateRecordApply_00490890(void *first, void *second, float value);
__attribute__((noinline)) uint32_t Engine_ForwardPairRecordFloat_ReturnZero_004691F0(
    void *first,
    void *unused,
    void *second,
    void *record)
{
    (void)unused;
    Engine_StateRecordApply_00490890(first, second,
                                     *(float *)((uint8_t *)record + 0x14u));
    return 0u;
}
