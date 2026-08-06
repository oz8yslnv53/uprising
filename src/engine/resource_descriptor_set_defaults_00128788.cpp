// Retail 0x00128788: write the fixed fourteen-byte descriptor schema.
#include <cstdint>
extern "C" __attribute__((noinline)) void ResourceDescriptor_SetDefaults_00128788(
    void* unused, std::uint8_t* descriptor) {
    (void)unused;
    descriptor[0x0b] = 2;
    descriptor[0x05] = 4;
    descriptor[0x07] = 2;
    descriptor[0x0a] = 2;
    descriptor[0x08] = 3;
    descriptor[0x09] = 3;
    descriptor[0x0c] = 1;
    descriptor[0x0d] = 1;
    descriptor[0x04] = 2;
    descriptor[0x02] = 1;
    descriptor[0x03] = 2;
    descriptor[0x06] = 1;
}
