#include <stddef.h>
#include <stdint.h>
extern "C" int OnceGuard_TestAndSet_003B4FE4(uint32_t*);
extern "C" void* Engine_ForEachStrideCallback_00421EA4(
    void*, void (*)(void*), uint32_t, uint32_t);
extern "C" void FUN_003DC5D0(void*, uint32_t);
extern "C" void* DAT_00d638d4;
extern "C" uint32_t DAT_00d638d8;
extern "C" uint8_t DAT_00f3572c[];
namespace {
template <typename T>
T& at(void* object, size_t offset) {
    return *reinterpret_cast<T*>(
        static_cast<uint8_t*>(object) + offset);
}
}  // namespace
extern "C" __attribute__((noinline)) void
FUN_00150344(void* record) {
    at<uint32_t>(record, 0) = 0;
    at<uint32_t>(record, 4) = 0;
}
extern "C" __attribute__((noinline)) void
FUN_00150354(void* record) {
    at<uint32_t>(record, 0) = 0;
    at<float>(record, 4) = 10.0f;
    at<float>(record, 8) = 10.0f;
}
extern "C" __attribute__((noinline)) void
FUN_00150370(void* record) {
    uint32_t* words = static_cast<uint32_t*>(record);
    words[0] = 0;
    at<uint8_t>(record, 0x2c) = 0;
    for (uint32_t i = 1; i != 9; ++i)
        words[i] = 0xffffffffu;
}
extern "C" __attribute__((noinline)) void
FUN_0012B5BC(
    void* record, uint32_t, uint32_t,
    uint8_t total_count) {
    at<uint32_t>(record, 0) = 0x00d15ae0u;
    at<uint32_t>(record, 4) = 0;
    at<uint8_t>(record, 0x10) = total_count;
    void* sentinel = static_cast<uint8_t*>(record) + 0x14;
    at<void*>(record, 0x14) = sentinel;
    at<void*>(record, 0x18) = sentinel;
    at<void*>(record, 0x1c) = sentinel;
    at<void*>(record, 0x20) = sentinel;
    at<uint8_t>(record, 0x24) = 0;
}
extern "C" __attribute__((noinline)) void*
FUN_0012B804(void* record) {
    at<uint32_t>(record, 4) = 0;
    at<uint32_t>(record, 0x88) = 0;
    at<uint32_t>(record, 0x8c) = 0;
    at<uint32_t>(record, 0x90) = 0;
    at<uint32_t>(record, 0x94) = 0;
    Engine_ForEachStrideCallback_00421EA4(
        static_cast<uint8_t*>(record) + 0xb8,
        FUN_00150354, 0x0c, 0x10);
    at<uint32_t>(record, 0x178) = 0;
    at<float>(record, 0x17c) = 10.0f;
    at<uint8_t>(record, 0x180) = 0;
    at<uint32_t>(record, 0x184) = 0;
    at<uint32_t>(record, 0x188) = 0;
    at<uint32_t>(record, 0x18c) = 0;
    at<uint8_t>(record, 0x190) = 0;
    at<uint8_t>(record, 0x191) = 0;
    FUN_003DC5D0(static_cast<uint8_t*>(record) + 8, 0x80);
    for (uint32_t offset = 0x98; offset != 0xb8; offset += 4)
        at<uint32_t>(record, offset) = 0;
    return record;
}
extern "C" __attribute__((noinline)) void*
FUN_0013B290() {
    if ((DAT_00d638d8 & 1u) == 0 &&
        OnceGuard_TestAndSet_003B4FE4(&DAT_00d638d8) != 0) {
        at<void*>(DAT_00f3572c, 0) = DAT_00f3572c;
        at<void*>(DAT_00f3572c, 4) = DAT_00f3572c;
        at<void*>(DAT_00f3572c, 8) = DAT_00f3572c;
    }
    return DAT_00f3572c;
}
