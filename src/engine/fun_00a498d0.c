typedef void (*ResourceRelease)(void *resource);
__attribute__((noinline)) void FUN_00A498D0(unsigned char *object)
{
    unsigned char *resource;
    void **vtable;
    resource = *(unsigned char **)(object + 0x7a4);
    if (resource != 0) {
        vtable = *(void ***)resource;
        ((ResourceRelease)vtable[1])(resource);
        *(void **)(object + 0x7a4) = 0;
    }
}
