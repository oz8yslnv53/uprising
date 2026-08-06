#include <stdint.h>
extern void *Engine_FindStatusDescriptorNode(void *object);
__attribute__((noinline)) void *StatusDescriptor_GetVector48OrDefault_004704A8(void *object)
{
    void *node = Engine_FindStatusDescriptorNode(object);
    if (node == 0)
        return (void *)(uintptr_t)0x00dc249c;
    return (void *)((uint8_t *)node + 0x48);
}
