#include <stdint.h>
extern "C" void FUN_001B51CC(
    void* binding, const float* values, uint32_t count,
    uint32_t enabled, uint32_t first, uint32_t second);
extern "C" void FUN_00135F64(
    void* binding, const uint32_t* values, uint32_t count,
    uint32_t enabled, void* owner);
extern "C" __attribute__((noinline)) void ShaderBinding_SetFloat_00112858(
    void* binding, float value) {
    FUN_001B51CC(binding, &value, 1, 1, 0, 0);
}
extern "C" __attribute__((noinline)) void ShaderBinding_SetWord_00112888(
    void* binding, uint32_t value) {
    FUN_00135F64(binding, &value, 1, 1, binding);
}
extern "C" __attribute__((noinline)) void ShaderBinding_SetFloat4_001128A4(
    void* binding, float x, float y, float z, float w) {
    const float values[4] = {x, y, z, w};
    FUN_001B51CC(binding, values, 4, 1, 0, 0);
}
