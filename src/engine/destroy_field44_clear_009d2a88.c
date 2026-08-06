typedef void (*Engine_Field44Destroy_009D2A88)(void *object);
__attribute__((noinline)) void *Engine_DestroyField44Clear_009D2A88(void *object)
{
    void *old = *(void **)((unsigned char *)object + 0x44);
    if (old != 0) {
        void **vtable = *(void ***)old;
        ((Engine_Field44Destroy_009D2A88)vtable[1])(old);
    }
    *(void **)((unsigned char *)object + 0x44) = 0;
    return 0;
}
