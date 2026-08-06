// KIU jp_rev1 transition-lane configuration wrapper at 0x006F4410.
extern "C" void* Engine_LazyStateManager_00475D18();
extern "C" void Engine_TransitionLane_ApplyInverse_00460F58(
    void* manager, int row, int group, int lane, float scale, int mode,
    int negate);
extern "C" void* DAT_006F446C;
extern "C" __attribute__((noinline)) void Engine_TransitionLane_Configure_006F4410(
    void* unused, int mode, int negate, int group, float timer, int row) {
    (void)unused;
    if (DAT_006F446C == 0)
        DAT_006F446C = Engine_LazyStateManager_00475D18();
    Engine_TransitionLane_ApplyInverse_00460F58(
        DAT_006F446C, row, group, 1, timer, mode, negate);
}
