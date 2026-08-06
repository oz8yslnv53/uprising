#include <stdint.h>
extern void *Engine_CandidateTableGet_005A8990(void);
__attribute__((noinline)) uint32_t Engine_CandidateTableField14Get_0058FAAC(void)
{
    return *(uint32_t *)((uint8_t *)Engine_CandidateTableGet_005A8990() + 0x14);
}
