#include <cstdint>
extern "C" __attribute__((noinline)) void
ResourceDescriptor_SetLayerFlags_005AF8E0(std::uint32_t* word,
                                          std::uint32_t layer,
                                          std::uint32_t mode) {
    if (layer > 3)
        layer = 0;
    if (mode > 3)
        mode = 0;
    *word = (*word & 0xFFFF00FFu) | (mode << 8) | (layer << 12);
}
