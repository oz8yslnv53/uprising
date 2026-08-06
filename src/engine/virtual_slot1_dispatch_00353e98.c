typedef void (*Engine_VirtualSlot1Callback_00353E98)(void *object);
__attribute__((noinline)) void Engine_VirtualSlot1Dispatch_00353E98(void *object)
{
    void **vtable = *(void ***)object;
    ((Engine_VirtualSlot1Callback_00353E98)vtable[1])(object);
}
