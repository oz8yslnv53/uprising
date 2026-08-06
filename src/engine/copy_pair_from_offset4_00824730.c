#include <stdint.h>
struct Engine_WordPair_00824730 {
    uint32_t first;
    uint32_t second;
};
__attribute__((noinline)) void Engine_CopyPairFromOffset4_00824730(
    uint32_t *destination, const uint32_t *source) {
    *(struct Engine_WordPair_00824730 *)destination =
        *(const struct Engine_WordPair_00824730 *)(source + 1);
}
