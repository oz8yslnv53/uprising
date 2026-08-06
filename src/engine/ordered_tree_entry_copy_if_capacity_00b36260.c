#include <stdint.h>
extern void OrderedTree_CopySearchFrame_00445CF4(uint32_t *destination,
                                                  uint32_t *source);
extern void Engine_CopyBytes_0044C108(void *destination, const void *source,
                                      uint32_t size);
__attribute__((noinline)) int OrderedTree_EntryCopyIfCapacity_00B36260(
    void *source, void *destination, uint32_t *written_size, uint32_t capacity)
{
    if (*(uint16_t *)((uint8_t *)source + 8u) + 5u > capacity)
        return 0;
    OrderedTree_CopySearchFrame_00445CF4(
        (uint32_t *)((uint8_t *)destination + 5u),
        (uint32_t *)((uint8_t *)source + 5u));
    Engine_CopyBytes_0044C108((uint8_t *)destination + 5u,
                              *(void **)((uint8_t *)source + 0xcu),
                              *(uint16_t *)((uint8_t *)source + 8u));
    if (written_size != 0)
        *written_size = *(uint16_t *)((uint8_t *)source + 8u) + 5u;
    return 1;
}
