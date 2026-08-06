#include <stdint.h>
extern uint32_t Engine_GlobalCapability_00B3F0D4(void);
extern uint32_t Engine_QueryCapability_008E6484(void *value);
__attribute__((noinline)) uint32_t Engine_CombinedCapabilityQuery_00B402A4(void *unused,
                                                  void *value)
{
    uint32_t global_capability = Engine_GlobalCapability_00B3F0D4();
    (void)unused;
    return Engine_QueryCapability_008E6484(value) & global_capability;
}
