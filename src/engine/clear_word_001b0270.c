// 001B0270: clear one word at the supplied address.
__attribute__((noinline)) void Engine_ClearWord_001B0270(void *target)
{
    *(unsigned int *)target = 0;
}
