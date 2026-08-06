extern void Engine_TailDispatch_00474668(void *value);
__attribute__((noinline)) void *Engine_DispatchFirstFieldReturnSelf_00BBB90C(void *object)
{
    Engine_TailDispatch_00474668(*(void **)object);
    return object;
}
