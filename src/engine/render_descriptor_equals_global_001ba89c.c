#include <stdint.h>
extern void *Engine_GlobalDescriptorGetter_0026D5AC(void);
__attribute__((noinline)) int RenderDescriptor_EqualsGlobal_001BA89C(
    const uint16_t *descriptor)
{
    const uint16_t *global =
        (const uint16_t *)Engine_GlobalDescriptorGetter_0026D5AC();
    return descriptor[0] == global[0] && descriptor[1] == global[1] &&
           descriptor[2] == global[2] && descriptor[3] == global[3];
}
