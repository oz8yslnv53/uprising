#include <stdint.h>
__attribute__((noinline)) void Engine_RecordFieldsInit_002A0FA0(uint8_t *record, uint32_t first,
                                      uint32_t second, uint32_t third,
                                      uint8_t flag) {
    *(uint32_t *)(record + 0x1c) = first;
    *(uint32_t *)(record + 0x20) = second;
    *(uint32_t *)(record + 0x24) = third;
    record[0x28] = flag;
}
