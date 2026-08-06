#include <stdint.h>
extern uint32_t Engine_SystemConfigWord40Get_00101DE0(void);
uint32_t Runtime_CacheConfigCapability_00102C2C(uint8_t *cache)
{
    uint32_t value;
    if (cache[0] != 0)
        return (uint32_t)(int32_t)(int8_t)cache[1];
    value = Engine_SystemConfigWord40Get_00101DE0();
    cache[1] = (uint8_t)(value <= 0x05000000u);
    cache[0] = 1;
    return (uint32_t)cache[1];
}
