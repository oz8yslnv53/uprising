#include <stdint.h>
extern "C" __attribute__((noinline)) void Engine_SetPairedResources_00718008(void *record, void *first,
                                                    void *second) {
  void **record_words = static_cast<void **>(record);
  if (record_words[0x60 / 4] != first) {
    void *old = record_words[0x60 / 4];
    if (old != 0) {
      void ***object = static_cast<void ***>(old);
      typedef void(*Release)(void *);
      Release release = reinterpret_cast<Release>((*object)[1]);
      release(old);
    }
    record_words[0x60 / 4] = first;
  }
  if (record_words[0x64 / 4] != second) {
    void *old = record_words[0x64 / 4];
    if (old != 0) {
      void ***object = static_cast<void ***>(old);
      typedef void(*Release)(void *);
      Release release = reinterpret_cast<Release>((*object)[1]);
      release(old);
    }
    record_words[0x64 / 4] = second;
  }
  uint8_t *state = static_cast<uint8_t *>(record) + 0x68;
  *state = static_cast<uint8_t>(*state & 0xfeu);
}
