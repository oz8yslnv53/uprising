// 00129074: clear one word at the supplied address.
__attribute__((noinline)) void Engine_ClearWord_00129074(void *target)
{
    *(unsigned int *)target = 0;
}
