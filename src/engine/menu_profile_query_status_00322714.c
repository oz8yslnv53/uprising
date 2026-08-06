#include <stdint.h>
uint8_t MenuProfile_QueryStatus_00322714(const uint8_t *manager, int32_t key)
{
    uint32_t index;
    if (key == -1) {
        index = manager[0x370];
        if (index != 0)
            return manager[0x168 + index * 8];
        return manager[0x368];
    }
    for (index = 0; index < 0x40; index += 2) {
        if (*(const int32_t *)(manager + 0x174 + index * 8) == key)
            return manager[0x170 + index * 8];
        if (*(const int32_t *)(manager + 0x17c + index * 8) == key)
            return manager[0x178 + index * 8];
    }
    return 0;
}
