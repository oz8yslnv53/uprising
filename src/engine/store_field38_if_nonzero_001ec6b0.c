__attribute__((noinline)) void Engine_StoreField38IfNonzero_001EC6B0(void *object, unsigned int value)
{
    if (value != 0)
        *(unsigned int *)((unsigned char *)object + 0x38) = value;
}
