#include <stdint.h>
extern int StateService_QueryValue_0010DACC(uint32_t * value);
uint32_t FUN_0010CDB4(void) {
    uint32_t value = 0;
    StateService_QueryValue_0010DACC(&value);
    return value;
}
