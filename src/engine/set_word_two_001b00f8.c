// 001B00F8: store the constant word value 2 at the supplied address.
__attribute__((noinline)) void Engine_SetWordTwo_001B00F8(void *target)
{
    *(unsigned int *)target = 2;
}
