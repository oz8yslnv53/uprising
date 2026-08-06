#include <stdint.h>
extern void *DAT_00D4A2A8;
typedef int (*ResourceStatePredicate)(void *object);
__attribute__((noinline)) int ResourceState_GlobalPredicateAndFlags_00A9C808(void *object)
{
    void *global_object = DAT_00D4A2A8;
    if (global_object != 0) {
        void **vtable = *(void ***)global_object;
        ResourceStatePredicate predicate =
            (ResourceStatePredicate)vtable[0x8cu / sizeof(void *)];
        if (predicate(global_object) != 0) {
            return 0;
        }
    }
    if ((*(uint32_t *)((uint8_t *)object + 0x68u) & 8u) != 0u &&
        (*(uint32_t *)((uint8_t *)object + 0x68u) & 4u) != 0u) {
        return 0;
    }
    return 1;
}
