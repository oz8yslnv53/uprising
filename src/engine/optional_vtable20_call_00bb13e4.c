typedef void (*Engine_VtableMethod)(void * object);
__attribute__((noinline)) void Engine_OptionalVtable20Call_00BB13E4(void * object)
{
    void * target = *(void **)((char *)object + 4);
    if (target != 0) {
        void ** vtable = *(void ***)target;
        ((Engine_VtableMethod)vtable[8])(target);
    }
}
