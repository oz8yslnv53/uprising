#include <stdint.h>
typedef void (*Engine_RegisterDescriptor_006693DC)(void *, const uint32_t *);
extern void ParameterDescriptor_BuildStringAlt_00BACBB4(
    uint32_t *, const void *, void *);
__attribute__((noinline)) void Engine_AnmLoopParameterVisit_006693DC(void *parameters, void *visitor) {
    uint32_t descriptor[5];
    Engine_RegisterDescriptor_006693DC *vtable;
    ParameterDescriptor_BuildStringAlt_00BACBB4(
        descriptor, (const void *)0x00669414, (uint8_t *)parameters + 0x18);
    vtable = *(Engine_RegisterDescriptor_006693DC **)visitor;
    vtable[2](visitor, descriptor);
}
