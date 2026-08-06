extern void *Engine_LazySingletonGetter_003B6C98(void);
extern int Engine_ObjectStatePredicate(void *object);
__attribute__((noinline)) float FUN_00AA0370(void *record)
{
    void **cache = (void **)0x00d63588u;
    void *object = *cache;
    if (object == 0) {
        object = Engine_LazySingletonGetter_003B6C98();
        *cache = object;
    }
    if (Engine_ObjectStatePredicate(object) != 0)
        return *(float *)((unsigned char *)record + 0xa8);
    return *(float *)((unsigned char *)record + 0xa4);
}
