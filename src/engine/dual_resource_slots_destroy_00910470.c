#include <stdint.h>
extern void Engine_VirtualReleaseDispatch_00421DEC(void *resource);
__attribute__((noinline)) void DualResourceSlots_Destroy_00910470(void *object)
{
    uint8_t *bytes = (uint8_t *)object;
    void **slots = (void **)object;
    unsigned int index;
    for (index = 0; index < 2u; ++index) {
        Engine_VirtualReleaseDispatch_00421DEC(slots[index]);
        slots[index] = 0;
    }
    *(void **)(bytes + 0x08) = 0;
    *(void **)(bytes + 0x0c) = 0;
}
