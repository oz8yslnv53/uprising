#include <cstdint>
extern "C" void StateResource_Finalize_00579720(void);
extern "C" __attribute__((noinline)) std::uint32_t *StateResource_WrapFinalize_00579794(
    std::uint32_t *value) {
    StateResource_Finalize_00579720();
    return value;
}
