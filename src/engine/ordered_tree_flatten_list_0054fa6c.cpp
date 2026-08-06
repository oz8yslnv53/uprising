#include <cstdint>
extern "C" __attribute__((noinline)) void OrderedTree_FlattenToList_0054FA6C(
    std::uint8_t *tree, std::uint8_t *node) {
    if (!node)
        return;
    do {
        OrderedTree_FlattenToList_0054FA6C(
            tree, *reinterpret_cast<std::uint8_t **>(node + 0xc));
        std::uint8_t* left = *reinterpret_cast<std::uint8_t**>(node + 8);
        *reinterpret_cast<std::uint8_t **>(node + 0xc) =
            *reinterpret_cast<std::uint8_t **>(tree + 4);
        *reinterpret_cast<std::uint8_t **>(tree + 4) = node;
        node = left;
    } while (node);
}
