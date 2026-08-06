extern unsigned int AIActGndBase_Singleton_006C93D0(void);
extern unsigned int AIActEnmAirIo_Singleton_006FE6AC(void);
__attribute__((noinline)) void AIActGndBase_GetSingleton_00A755C4(unsigned int *output)
{
    *output = AIActGndBase_Singleton_006C93D0();
}
__attribute__((noinline)) void AIActEnmAirIo_GetSingleton_00A776C4(unsigned int *output)
{
    *output = AIActEnmAirIo_Singleton_006FE6AC();
}
