#include <stdint.h>
extern int Engine_GlobalSignedByteGet_0010258C(void);
extern int IntrusiveList_InsertHead_00102370(void *node, uint32_t payload);
extern int Startup_InitializeMemory_001025C8(uint32_t kind, uint32_t size,
                                             uint32_t flags);
__attribute__((noinline)) int Startup_InitializeMemory_00100370(uint32_t mode) {
    int result;
    if (Engine_GlobalSignedByteGet_0010258C() != 0)
        return 0;
    mode &= ~7u;
    ((uint8_t *)0x00D4D478u)[3] = 1;
    IntrusiveList_InsertHead_00102370((void *)0x00DBC61Cu, 0x100u);
    result = Startup_InitializeMemory_001025C8(0x300u, mode, 0xFu);
    if ((int32_t)((uint32_t)result & 0x80000000u) < 0)
        return result;
    return 0;
}
