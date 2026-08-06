#include <stdint.h>
extern int Object_StatusProbe_00575E04(void *record);
extern int Object_StatusConsumeCurrent_003D82C0(void);
__attribute__((noinline)) int Object_StatusGate_00B1E704(void *object)
{
    int result = 0;
    if ((*(uint8_t *)((uint8_t *)object + 0xec) == 1) &&
        (Object_StatusProbe_00575E04((uint8_t *)object + 0xe0) != 0))
        result = Object_StatusConsumeCurrent_003D82C0();
    return result;
}
