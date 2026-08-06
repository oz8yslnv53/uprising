#include <stdint.h>
void Engine_ResourceReadyService_006C9298(void);
__attribute__((noinline)) uint32_t Engine_MarkResourceReady_00740FD0(void *object)
{
    Engine_ResourceReadyService_006C9298();
    *(uint8_t *)((uint8_t *)object + 0x6c) = 1;
    return 1;
}
