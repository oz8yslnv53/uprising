#include <stdint.h>
extern void *OrderedTree_StatusComponentLookup(void *object);
__attribute__((noinline)) uint32_t Engine_StatusComponentCodeGet_00409678(void *object)
{
    uint32_t result = 0xffffffffu;
    void *component = OrderedTree_StatusComponentLookup(object);
    if (component != 0) {
        void *record = *(void **)((uint8_t *)component + 0x1c);
        result = *(uint32_t *)((uint8_t *)record + 0x68);
    }
    return result;
}
