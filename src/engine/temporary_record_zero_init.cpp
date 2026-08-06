#include <stdint.h>
extern "C" __attribute__((noinline)) void TemporaryRecord_ZeroInit(uint32_t *record) {
  record[0] = 0;
}
