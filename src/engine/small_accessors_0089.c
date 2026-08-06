#include "engine_common_views.h"
extern struct D4D0F8GlobalPrefixView DAT_00D4D0F8;
__attribute__((noinline)) void Engine_SetPointerD12808_00891F84(unsigned int *target)
{
    *target = 0x00D12808u;
}
__attribute__((noinline)) void Engine_ClearField3C_0089208C(unsigned int *record)
{
    *(unsigned int *)((char *)record + 0x3c) = 0;
}
__attribute__((noinline)) void Engine_SetField20ByteTwo_00894458(unsigned int *record)
{
    *(unsigned char *)((char *)record + 0x20) = 2;
}
__attribute__((noinline)) void Engine_SetPointerD12B70_0089559C(unsigned int *target)
{
    *target = 0x00D12B70u;
}
__attribute__((noinline)) int Engine_GlobalSignedByteGetD4D0F8_0089AD0C(void)
{
    return DAT_00D4D0F8.signed_byte_000;
}
__attribute__((noinline)) void Engine_ClearWord_0089DB00(unsigned int *target)
{
    *target = 0;
}
