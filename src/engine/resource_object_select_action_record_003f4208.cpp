extern "C" void* ActionGroup_SelectActionRecord_004216A0(void* group,
                                                            void* key);
extern "C" __attribute__((noinline)) void
ResourceObject_SelectActionRecord_003F4208(void* object, void* key) {
    void* selected = ActionGroup_SelectActionRecord_004216A0(
        *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x18),
        key);
    *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x28) =
        selected;
}
