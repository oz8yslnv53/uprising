// Retail 0x00B40324. Applies a three-float component record in fixed order.
#include <cstdint>
extern "C" void FUN_00B3EDCC(
    void* target, void* state, void* descriptor, float component);
extern "C" void FUN_00B3EF38(
    void* target, void* state, void* descriptor, float component);
extern "C" void FUN_00B3EC5C(
    void* target, void* state, void* descriptor, float component);
extern "C" __attribute__((noinline)) std::uint32_t SceneTransform_ApplyThreeComponents_00B40324(
    void* target, void* state, void* unused, void* descriptor,
    const float* components) {
    (void)unused;
    FUN_00B3EDCC(target, state, descriptor, components[0]);
    FUN_00B3EF38(target, state, descriptor, components[1]);
    FUN_00B3EC5C(target, state, descriptor, components[2]);
    return 1;
}
