#include <stdint.h>
extern uint8_t **FUN_0044C0C0(void);
__attribute__((noinline)) uint8_t Singleton_ByteFlagBitGet_00353B68(unsigned int index)
{
    uint8_t *bytes = *FUN_0044C0C0();
    return (uint8_t)(bytes[index] & 1u);
}
