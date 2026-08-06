#include <cstdint>
extern "C" __attribute__((noinline)) std::uint8_t
GlobalTransitionFlags_GetByteC_004389C8() {
    return *reinterpret_cast<volatile std::uint8_t*>(0x00d4d4a4);
}
extern "C" __attribute__((noinline)) std::int32_t
GlobalTransitionFlags_GetSignedByteD_004389E8() {
    return *reinterpret_cast<volatile std::int8_t*>(0x00d4d4a5);
}
extern "C" __attribute__((noinline)) bool GlobalTransitionFlags_AnySet_00414DD8() {
    return GlobalTransitionFlags_GetSignedByteD_004389E8() != 0 ||
           GlobalTransitionFlags_GetByteC_004389C8() != 0;
}
