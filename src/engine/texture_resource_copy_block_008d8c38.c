#include <stdint.h>
extern void Engine_CopyBytes_0044C108(void *destination,
                                      const void *source,
                                      uint32_t length);
void TextureResource_CopyBlock(uint32_t *cursor, const void *source,
                               uint32_t length)
{
    Engine_CopyBytes_0044C108(
        (void *)(uintptr_t)(cursor[0] + cursor[1]), source, length);
    cursor[1] += length;
}
