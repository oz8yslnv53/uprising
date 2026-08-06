typedef void (*VirtualCallSlot2C)(void *object);
__attribute__((noinline)) void VirtualCallSlot2CIfNonNull_00369EF4(void *object)
{
    if (object != 0) {
        void **vtable = *(void ***)object;
        ((VirtualCallSlot2C)vtable[0x2c / sizeof(void *)])(object);
    }
}
