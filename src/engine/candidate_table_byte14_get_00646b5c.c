#include <stdint.h>
extern void *Engine_CandidateTableGet_005A8990(void);
__attribute__((noinline)) uint32_t Engine_CandidateTableByte14Get_00646B5C(void) {
    uint8_t *table = (uint8_t *)Engine_CandidateTableGet_005A8990();
    return *(volatile uint32_t *)(table + 0x14) & 0xffu;
}
