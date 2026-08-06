#include <stdint.h>
__attribute__((noinline)) void ResourceRecord_ClearChainState_00908470(
    uint8_t *node)
{
    if (node != 0) {
        *(uint32_t *)(node + 0x12cU) = 0;
        *(uint32_t *)(node + 0x130U) = 0;
    }
}
