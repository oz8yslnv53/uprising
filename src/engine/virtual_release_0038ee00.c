typedef void (*VirtualReleaseFunction)(void *object);
__attribute__((noinline)) void VirtualRelease_0038EE00(void *object)
{
    if (object != 0) {
        void **vtable = *(void ***)object;
        ((VirtualReleaseFunction)vtable[1])(object);
    }
}
