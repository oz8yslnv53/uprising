// 00129610: clear one word at the supplied address.
__attribute__((noinline)) void Engine_ClearWord_00129610(void *target)
{
    *(unsigned int *)target = 0;
}
