#include <stdint.h>
__attribute__((noinline)) int Engine_RecordModeByte_Get_0010AD18(void *object) {
    uint8_t *bytes = (uint8_t *)object;
    if (bytes[0xb0] == 0)
        return 0;
    return *(int8_t *)(*(uint8_t **)(bytes + 0x168) + 0xef);
}
