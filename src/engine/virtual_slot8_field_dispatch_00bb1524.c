typedef void (*Engine_VirtualSlot8_00BB1524)(void *object);
__attribute__((noinline)) void Engine_VirtualSlot8FieldDispatch_00BB1524(void *object)
{
    void *target = *(void **)((unsigned char *)object + 4);
    if (target != 0) {
        Engine_VirtualSlot8_00BB1524 call = *(Engine_VirtualSlot8_00BB1524 *)
            (*(void **)target + 0x20);
        call(target);
    }
}
