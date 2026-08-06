__attribute__((noinline)) void Engine_NestedField72SetIfPresent_005AA6EC(void *object, unsigned char value)
{
    void *nested = *(void **)((char *)object + 0x9c);
    if (nested != 0)
        *(unsigned char *)((char *)nested + 0x72) = value;
}
