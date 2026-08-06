#include <stdint.h>
extern void Engine_ResetSharedState_006C58FC(void);
__attribute__((noinline)) void Engine_ResetCopyField2CTo50_0073EDD4(
    void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    Engine_ResetSharedState_006C58FC();
    *(uint32_t *)(bytes + 0x50u) = *(uint32_t *)(bytes + 0x2cu);
}
