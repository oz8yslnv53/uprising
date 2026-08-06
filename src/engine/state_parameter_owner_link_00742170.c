extern void FUN_006C8798(void *object);
__attribute__((noinline)) void StateParameterOwner_LinkBase_00742170(void *object)
{
    FUN_006C8798(object);
    *(void **)((unsigned char *)object + 0x68) =
        *(void **)((unsigned char *)object + 0x2c);
}
