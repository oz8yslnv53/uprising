#include <cstdint>
struct RecordKeyView {
    std::uint8_t padding[8];
    std::uint32_t key;
};
typedef char kiu_sa_release_matching_record_key_1[(sizeof(RecordKeyView) == 0x0c) ? 1 : -1] __attribute__((unused));
extern "C" int FUN_005337AC(void* record);
extern "C" __attribute__((noinline)) int ReleaseMatchingRecordKey_00A52638(
    RecordKeyView* records, std::uint32_t key) {
    for (std::uint32_t index = 0; index < 10; ++index) {
        if (records[index].key == key) {
            return FUN_005337AC(&records[index]) != 0;
        }
    }
    return 1;
}
