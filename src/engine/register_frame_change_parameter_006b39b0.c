#include <stdint.h>
extern void ParameterDescriptor_BuildStringAlt_00BACBB4(void *descriptor,
                                                          void *name,
                                                          void *value);
typedef void (*ParameterVisitor)(void *visitor, void *descriptor);
__attribute__((noinline)) void Engine_RegisterFrameChangeParameter_006B39B0(
    void *object, void *visitor)
{
    uint8_t descriptor[24];
    static char const name[] = "FrameChange_";
    void **vtable;
    ParameterVisitor visit;
    ParameterDescriptor_BuildStringAlt_00BACBB4(
        descriptor, (void *)name, (uint8_t *)object + 0x18u);
    vtable = *(void ***)visitor;
    visit = (ParameterVisitor)vtable[2];
    visit(visitor, descriptor);
}
