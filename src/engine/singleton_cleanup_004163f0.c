#include <stdint.h>
typedef void (*DestroyFunction)(void *object);
typedef void (*ReleaseFunction)(void *owner, void *object);
void FUN_004163F0(void)
{
    void **slot;
    void **object;
    void **owner;
    void **vtable;
    slot = (void **)0x00d4f01cu;
    object = (void **)*slot;
    if (object != 0) {
        vtable = (void **)*object;
        ((DestroyFunction)vtable[0])(object);
        owner = (void **)object[1];
        vtable = (void **)*owner;
        ((ReleaseFunction)vtable[3])(owner, object);
        *slot = 0;
    }
    slot = (void **)0x00d4f018u;
    object = (void **)*slot;
    if (object != 0) {
        vtable = (void **)*object;
        ((DestroyFunction)vtable[0])(object);
        owner = (void **)object[1];
        vtable = (void **)*owner;
        ((ReleaseFunction)vtable[3])(owner, object);
        *slot = 0;
    }
    slot = (void **)0x00d4f014u;
    object = (void **)*slot;
    if (object != 0) {
        vtable = (void **)*object;
        ((DestroyFunction)vtable[0])(object);
        owner = (void **)object[1];
        vtable = (void **)*owner;
        ((ReleaseFunction)vtable[3])(owner, object);
        *slot = 0;
    }
    slot = (void **)0x00d4f010u;
    object = (void **)*slot;
    if (object != 0) {
        vtable = (void **)*object;
        ((DestroyFunction)vtable[0])(object);
        owner = (void **)object[1];
        vtable = (void **)*owner;
        ((ReleaseFunction)vtable[3])(owner, object);
        *slot = 0;
    }
}
