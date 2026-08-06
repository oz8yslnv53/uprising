extern void *Engine_RuntimeObjectGet_00B363D4(void);
__attribute__((noinline)) unsigned int Engine_NestedWord4IfPresent_00B36490(void)
{
    void *object = Engine_RuntimeObjectGet_00B363D4();
    if (object != 0)
        return *(unsigned int *)((unsigned char *)object + 4);
    return 0;
}
