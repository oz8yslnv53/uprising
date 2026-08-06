#include <stdint.h>
__attribute__((noinline)) void StateResource_SetByte73IfLinked_0075BE2C(void *object, uint32_t value)
{
    uint8_t *linked = *(uint8_t **)((uint8_t *)object + 0x9c);
    if (linked != 0)
        linked[0x73] = (uint8_t)value;
}
