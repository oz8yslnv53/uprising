#include <stdint.h>
extern void *ParameterRecord_RegistryGet_003D9540(void);
extern void *StateResourceContext_Publish_0010FCD4(
    void *shared, void *resource_a, void *resource_b, void *resource_c,
    void *resource_d, void *resource_e, uint32_t selected);
void StateResourceContext_Apply_001094B0(
    void *shared, void *resource_a, void *resource_b, void *resource_c,
    void *resource_d, void *resource_e, uint32_t selected)
{
    uint32_t *cache = (uint32_t *)(uintptr_t)0x00D637E4u;
    uint32_t state = *cache;
    (void)shared;
    if (state == 0) {
        state = (uint32_t)(uintptr_t)ParameterRecord_RegistryGet_003D9540();
        *cache = state;
    }
    StateResourceContext_Publish_0010FCD4(
        (void *)(uintptr_t)state, resource_a, resource_b, resource_c,
        resource_d, resource_e, selected);
}
