#include <stdint.h>
__attribute__((noinline)) void Engine_CopyField150_009CEC10(uint32_t *destination,
                                  const unsigned char *record)
{
    *destination = *(const uint32_t *)(record + 0x150);
}
