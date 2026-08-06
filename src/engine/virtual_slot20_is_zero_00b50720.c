#include <stdint.h>
typedef int (*Engine_Slot20Predicate)(void *object);
__attribute__((noinline)) int Engine_VirtualSlot20IsZero_00B50720(void *object)
{
    Engine_Slot20Predicate predicate = *(Engine_Slot20Predicate *)
        (*(uint32_t **)(uintptr_t)object + 8u);
    return predicate(object) == 0;
}
