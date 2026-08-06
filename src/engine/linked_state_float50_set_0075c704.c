__attribute__((noinline)) void StateResource_SetFloat50IfLinked_0075C704(void *object, float value)
{
    unsigned char *linked = *(unsigned char **)((unsigned char *)object + 0x9c);
    if (linked != 0)
        *(float *)(linked + 0x50) = value;
}
