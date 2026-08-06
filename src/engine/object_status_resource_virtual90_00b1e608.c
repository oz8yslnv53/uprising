#include <stdint.h>
extern void *Object_StatusResource_Get_00575E04(void *ignored);
__attribute__((noinline)) int Object_StatusResource_Virtual90_00B1E608(
    void *object)
{
    void *resource;
    void **vtable;
    int (*call)(void *resource);
    int result = 0;
    if (*(uint8_t *)((uint8_t *)object + 0xecu) == 1u) {
        resource = Object_StatusResource_Get_00575E04((uint8_t *)object + 0xe0u);
        if (resource != 0) {
            vtable = *(void ***)resource;
            call = (int (*)(void *))vtable[0x90u / sizeof(void *)];
            result = call(resource);
        }
    }
    return result;
}
