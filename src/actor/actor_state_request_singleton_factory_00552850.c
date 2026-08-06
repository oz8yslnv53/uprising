extern void *ActorStateFactory_GetSingleton_004E9D70(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                      void *factorySlot);
__attribute__((noinline)) int ActorState_RequestSingletonFactory_00552850(void *object,
                                                 void *unused1,
                                                 void *unused2,
                                                 void *unused3)
{
    void *machine = *(void **)((char *)object + 0x30);
    void *factory = ActorStateFactory_GetSingleton_004E9D70();
    (void)unused1;
    (void)unused2;
    (void)unused3;
    ActorStateMachine_RequestStateByFactory(machine, &factory);
    return 0;
}
