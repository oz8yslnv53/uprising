#include <stdint.h>
__attribute__((noinline)) uint32_t Engine_InvertedVirtualPredicate_008419D4(void *object)
{
    void *inner = *(void **)((uint8_t *)object + 8);
    void **vtable = *(void ***)inner;
    uint32_t (*predicate)(void *) =
        (uint32_t (*)(void *))vtable[2];
    return predicate(inner) ^ 1u;
}
