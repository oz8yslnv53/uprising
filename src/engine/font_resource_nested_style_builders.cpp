#include <cstdint>
extern "C" void *Engine_ForEachStrideCallback_00421EA4(
    void *, void (*)(void *), std::uint32_t, std::uint32_t);
namespace {
typedef std::uint8_t Byte;
typedef std::uint32_t Word;
template <typename T> T load(std::uintptr_t address) {
    return *reinterpret_cast<T *>(address);
}
void fill_mode_table(Byte *out, unsigned a, unsigned b) {
    out[6] = 0x18; out[7] = 0x19;
    if (a > 1 || b > 3 || (a == 0 && b == 0) || (a == 1 && (b == 1))) return;
    if (b == 0 || b == 1) {
        out[0] = out[1] = out[2] = out[3] = 0x1a;
        out[8] = 0x11; out[9] = 0x0e; out[10] = 0x10; out[11] = 0x0f;
    } else if (b == 2) {
        out[0] = out[1] = out[2] = out[8] = 0x0d; out[3] = 0x11;
        out[9] = 0x0e; out[10] = 0x10; out[11] = 0x0f;
    } else {
        out[0] = 0x10; out[1] = 0x0e; out[2] = 0x0d; out[3] = 0x11;
        out[8] = out[9] = out[10] = out[11] = 0x1a;
    }
    if (a == 0) { out[4] = (b == 3) ? 0x12 : 0x0d; out[5] = (b == 3) ? 0x0d : 0x12; }
    else { out[4] = (b == 3) ? 0x0d : 0x12; out[5] = (b == 3) ? 0x12 : 0x0d; }
}
}
extern "C" __attribute__((noinline)) void *FUN_0090e244(Word *p) { p[0] = p[1] = p[2] = 0; return p; }
extern "C" __attribute__((noinline)) void *FUN_0098dabc(Word *p) { p[0] = load<Word>(0x0098dac8); return p; }
extern "C" __attribute__((noinline)) void *FUN_0077ca34(Byte *record) {
    *reinterpret_cast<Word *>(record) = load<Word>(0x0077ca5c);
    FUN_0090e244(reinterpret_cast<Word *>(record + 0x18));
    FUN_0098dabc(reinterpret_cast<Word *>(record + 0x24));
    *reinterpret_cast<Word *>(record + 0x0c) = 0;
    return record;
}
extern "C" __attribute__((noinline)) void FUN_0028ac70(Byte *p) { for (unsigned i = 0; i != 12; ++i) p[i] = 0x1a; }
extern "C" __attribute__((noinline)) void FUN_003a6fbc(unsigned a, unsigned b, Byte *out) {
    fill_mode_table(out, a, b);
}
extern "C" __attribute__((noinline)) void *FUN_00407b0c(Byte *p) {
    FUN_0028ac70(p); FUN_0028ac70(p + 0x0c);
    for (unsigned off = 0x18; off <= 0x24; off += 4) *reinterpret_cast<Word *>(p + off) = 0;
    const Word zero = load<Word>(0x00407c24);
    *reinterpret_cast<Word *>(p + 0x28) = zero;
    for (unsigned off = 0x2c; off <= 0x38; off += 4) *reinterpret_cast<Word *>(p + off) = 0;
    *reinterpret_cast<Word *>(p + 0x3c) = zero;
    for (unsigned off = 0x40; off <= 0x4c; off += 4) *reinterpret_cast<Word *>(p + off) = 0;
    *reinterpret_cast<Word *>(p + 0x50) = zero;
    Byte* first = static_cast<Byte*>(Engine_ForEachStrideCallback_00421EA4(
        p + 0x84, reinterpret_cast<void (*)(void *)>(load<std::uintptr_t>(0x00407c28)), 0x0c, 4));
    *reinterpret_cast<Word *>(first + 0x30) = 0;
    Byte* second = static_cast<Byte*>(Engine_ForEachStrideCallback_00421EA4(
        first + 0x34, reinterpret_cast<void (*)(void *)>(load<std::uintptr_t>(0x00407c2c)), 0x0c, 0x0f));
    *reinterpret_cast<Word *>(second + 0xb4) = 0;
    *reinterpret_cast<Word *>(second + 0xbc) = load<Word>(0x00407c30);
    *reinterpret_cast<Word *>(second + 0xc0) = load<Word>(0x00407c34);
    *reinterpret_cast<Word *>(second + 0xdc) = zero;
    *reinterpret_cast<Word *>(second + 0xe0) = zero;
    *reinterpret_cast<Word *>(second + 0xe4) = load<Word>(0x00407c38);
    *reinterpret_cast<Word *>(second + 0xec) = load<Word>(0x00407c38);
    second[0xf0] = second[0xf1] = 0;
    const Word* constants = load<const Word*>(0x00407c3c);
    *reinterpret_cast<Word *>(second + 0xf4) = zero;
    *reinterpret_cast<Word *>(second + 0xf8) = zero;
    *reinterpret_cast<Word *>(second + 0xfc) = zero;
    *reinterpret_cast<Word *>(second + 0x100) = 0;
    *reinterpret_cast<Word *>(second - 0x64) = constants[0];
    *reinterpret_cast<Word *>(second - 0x60) = constants[1];
    *reinterpret_cast<Word *>(second - 0x5c) = constants[2];
    Byte* out = second - 0xb8;
    FUN_003a6fbc(0, 2, out); FUN_003a6fbc(0, 2, out + 0x0c);
    return out;
}
