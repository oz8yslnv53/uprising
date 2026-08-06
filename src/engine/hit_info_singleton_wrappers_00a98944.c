extern unsigned int HitInfoGetter_Singleton_006C141C(void);
extern unsigned int HitInfoOfAvatar_Singleton_006C1840(void);
__attribute__((noinline)) void HitInfoGetter_GetSingleton_00A98944(unsigned int *output)
{
    *output = HitInfoGetter_Singleton_006C141C();
}
__attribute__((noinline)) void HitInfoOfAvatar_GetSingleton_00A990C8(unsigned int *output)
{
    *output = HitInfoOfAvatar_Singleton_006C1840();
}
