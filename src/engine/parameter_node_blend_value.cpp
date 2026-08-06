// KIU jp_rev1 parameter-node hidden-float setter at 0x0054ECB0.
#include <cstdint>
extern "C" __attribute__((noinline)) void
ParameterNode_SetBlendValue(void* node, float value) {
    void* nested = *reinterpret_cast<void**>(
        static_cast<std::uint8_t*>(node) + 0x04);
    if (nested != 0)
        *reinterpret_cast<float*>(static_cast<std::uint8_t*>(nested) + 0x3C) =
            value;
}
