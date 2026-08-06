// Retail 0x00B40254. Applies three component updates in fixed order.
#include <cstdint>
extern "C" void FUN_00B3EDCC(
    void* target, void* state, void* descriptor, float component);
extern "C" void FUN_00B3ECEC(
    void* target, void* state, void* descriptor, float component);
extern "C" void FUN_00B3EC5C(
    void* target, void* state, void* descriptor, float component);
extern "C" __attribute__((noinline)) std::uint32_t
SceneTransform_ApplyThreeComponentsAlt_00B40254(
    void* target, void* state, void* unused, void* descriptor,
    const float* components)
{
    (void)unused;
    FUN_00B3EDCC(target, state, descriptor, components[0]);
    FUN_00B3ECEC(target, state, descriptor, components[1]);
    FUN_00B3EC5C(target, state, descriptor, components[2]);
    return 1;
}
