#include <stdint.h>
typedef void (*ObjectDispatchFn)(void *object);
__attribute__((noinline)) void Object_DispatchFieldVtableA0_00A33FA8(void *object)
{
    void *field = *(void **)((uint8_t *)object + 0x38);
    ObjectDispatchFn dispatch = *(ObjectDispatchFn *)(*(void **)field + 0xA0);
    dispatch(field);
}
