#include <stdint.h>
extern void *ResolveRelatedComponent(void *component);
__attribute__((noinline)) float Engine_RelatedComponentFloat178_00485198(void *unused,
                                               void *component)
{
    uint8_t *object = (uint8_t *)ResolveRelatedComponent(component);
    (void)unused;
    return *(float *)(object + 0x178u);
}
