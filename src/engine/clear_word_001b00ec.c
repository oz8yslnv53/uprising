// 001B00EC: clear one word at the supplied address.
__attribute__((noinline)) void Engine_ClearWord_001B00EC(void *target)
{
    *(unsigned int *)target = 0;
}
