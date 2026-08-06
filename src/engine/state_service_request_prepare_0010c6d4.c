#include <stdint.h>
extern int CtrThreadLocalRequest_001296EC(int * value, uint32_t * output);
extern uint32_t Runtime_ServiceValueGet_00257FC4(void);
int FUN_0010C6D4(uint32_t * output) {
    int value = (int)Runtime_ServiceValueGet_00257FC4();
    return CtrThreadLocalRequest_001296EC(&value, output);
}
