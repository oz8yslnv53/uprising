#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_RuntimeGate_006C6FE0(void *object)
{
    void *inner = *(void **)((unsigned char *)object + 4);
    if (inner == 0) {
        return 0;
    }
    inner = *(void **)((unsigned char *)inner + 0x1C);
    if (inner == 0) {
        return 0;
    }
    return (uint32_t)(1u & (uint32_t)~*(uint16_t *)
        ((unsigned char *)inner + 0x1C));
}
