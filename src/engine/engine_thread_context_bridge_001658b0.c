#include <stdint.h>
extern void Engine_ThreadContextUpdate_0034BFCC(void *context,
                                                uint32_t value,
                                                void *value_address);
void *Engine_ThreadContextBridge_001658B0(void *context)
{
    uint8_t *bytes = (uint8_t *)context;
    Engine_ThreadContextUpdate_0034BFCC(context,
                                        *(uint32_t *)(bytes + 4), bytes + 4);
    return context;
}
