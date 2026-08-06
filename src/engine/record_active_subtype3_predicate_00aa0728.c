#include <stdint.h>
__attribute__((noinline)) int Record_IsActiveSubtype3_00AA0728(
    uint8_t *record)
{
    return record[0x15] != 0 &&
           (*(uint8_t *)(*(void **)record + 0xec) == 3);
}
