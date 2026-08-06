#include <stdint.h>
extern void *Engine_ResourceHandleLookup_00B5E45C(void *handle);
extern void FUN_006C58FC(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                      void *factory_slot);
extern int Engine_RuntimeGate_006C6FE0(void *handle);
extern void *StateDescriptorGet_004949C0(void);
extern void *StateDescriptorGet_00419E80(void);
__attribute__((noinline)) void *ResourceHandle_Lookup_00786A04(void *handle)
{
    return Engine_ResourceHandleLookup_00B5E45C(handle);
}
__attribute__((noinline)) __attribute__((noreturn))
void ResourceHandle_LookupNoReturn_007B2B60(void *handle)
{
    Engine_ResourceHandleLookup_00B5E45C(handle);
    __builtin_unreachable();
}
__attribute__((noinline)) __attribute__((noreturn))
void ResourceHandle_LookupNoReturn_00741884(void *handle)
{
    Engine_ResourceHandleLookup_00B5E45C(handle);
    __builtin_unreachable();
}
__attribute__((noinline)) __attribute__((noreturn))
void ResourceHandle_PrepareLookup_00761648(void *object)
{
    FUN_006C58FC();
    *(uint32_t *)((uint8_t *)object + 0x50) =
        *(uint32_t *)((uint8_t *)object + 0x2c);
    Engine_ResourceHandleLookup_00B5E45C(object);
    __builtin_unreachable();
}
__attribute__((noinline))
void ResourceHandle_RequestStateIfChanged_0078767C(void *handle)
{
    void *resource = Engine_ResourceHandleLookup_00B5E45C(handle);
    void *owner = *(void **)((uint8_t *)resource + 0x168);
    if (*(void **)((uint8_t *)owner + 8) == *(void **)(uintptr_t)0x00c9b9a0u)
        return;
    if (Engine_RuntimeGate_006C6FE0(handle) == 0)
        return;
    {
        void *descriptor = StateDescriptorGet_00419E80();
        (void)ActorStateMachine_RequestStateByFactory(resource, &descriptor);
    }
}
__attribute__((noinline))
void ResourceHandle_RequestStateAndFlag_007C00B0(void *handle)
{
    void *resource = Engine_ResourceHandleLookup_00B5E45C(handle);
    void *descriptor = StateDescriptorGet_004949C0();
    void *state = ActorStateMachine_RequestStateByFactory(resource, &descriptor);
    *((uint8_t *)state + 0x60) = 1;
}
