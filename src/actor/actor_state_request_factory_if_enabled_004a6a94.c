extern void *FUN_004DB394(void);
extern void *ActorStateMachine_RequestStateByFactory(void *machine,
                                                      void *factorySlot);
__attribute__((noinline)) int ActorState_RequestFactoryIfEnabled_004A6A94(void *object,
                                                 void *unused,
                                                 void *context,
                                                 void *unused2)
{
    (void)unused;
    (void)unused2;
    if (*(unsigned char *)(*(void **)((char *)context + 0x2c) + 0x148)) {
        void *machine = *(void **)((char *)object + 0x30);
        void *factory = FUN_004DB394();
        ActorStateMachine_RequestStateByFactory(machine, &factory);
    }
    return 0;
}
