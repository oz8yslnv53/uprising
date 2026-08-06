extern void StateResourceDestroyThunk_00474668(void *object);
__attribute__((noinline)) void **Engine_OwnedPointerDestroyClear_0098FB4C(void **slot)
{
    StateResourceDestroyThunk_00474668(*slot);
    *slot = 0;
    return slot;
}
