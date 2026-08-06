#include <stdint.h>
extern void Engine_ResourceHandlePrepare_006C58FC(void *object);
__attribute__((noinline)) void Engine_PrepareCopyField_0078741C(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    Engine_ResourceHandlePrepare_006C58FC(object);
    *(uint32_t *)(bytes + 0x50u) = *(uint32_t *)(bytes + 0x2cu);
}
