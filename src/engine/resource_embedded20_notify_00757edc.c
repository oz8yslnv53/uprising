#include <stdint.h>
extern void ResourceEmbedded20Notify_0077629C(void *value);
__attribute__((noinline)) int ResourceEmbedded20Notify_00757EDC(void *unused, void *resource) {
    (void)unused;
    ResourceEmbedded20Notify_0077629C(
        *(void **)((uint8_t *)resource + 0x20));
    return 0;
}
