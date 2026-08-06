// 001AC1E0: clear one word at the supplied address.
__attribute__((noinline)) void Engine_ClearWord_001AC1E0(void *target)
{
    *(unsigned int *)target = 0;
}
