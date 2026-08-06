extern void Engine_VirtualReleaseDispatch_00421DEC(void *object);
__attribute__((noinline)) void FUN_00296C3C(void **records)
{
    void *zero;
    Engine_VirtualReleaseDispatch_00421DEC(records[0]);
    zero = (void *)0;
    records[0] = zero;
    Engine_VirtualReleaseDispatch_00421DEC(records[1]);
    records[1] = zero;
    Engine_VirtualReleaseDispatch_00421DEC(records[2]);
    records[2] = zero;
}
