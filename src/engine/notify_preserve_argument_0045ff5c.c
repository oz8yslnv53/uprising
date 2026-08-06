extern void Engine_ClearSixWords_00487FF4(unsigned int *record);
__attribute__((noinline)) void *Engine_NotifyPreserveArgument_0045FF5C(void *value)
{
    Engine_ClearSixWords_00487FF4((unsigned int *)value);
    return value;
}
