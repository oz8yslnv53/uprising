#include <stdint.h>
void Resource_CflRecordInitialize_00372FB0(void *record,
                                            const char *path,
                                            uint32_t size);
struct ResourceCflFactory {
    void *(*create)(void);
};
__attribute__((noinline)) void *Resource_CflRecordCreate_003542C4(
    void *unused_first, void *unused_second, const char *path,
    struct ResourceCflFactory *factory)
{
    void *record = factory->create();
    (void)unused_first;
    (void)unused_second;
    *(struct ResourceCflFactory **)record = factory;
    Resource_CflRecordInitialize_00372FB0(
        (uint8_t *)record + 0x2c, path, 0x104);
    return record;
}
