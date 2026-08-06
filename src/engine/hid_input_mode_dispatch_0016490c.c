#include <stdint.h>
extern void HID_InputMode0_001B28F0(void *arg1, void *arg2, void *arg3,
                                    void *arg4, int first, int second);
extern void HID_InputMode1_001B27EC(void *arg1, void *arg2, void *arg3,
                                    void *arg4, int first, int second);
extern void HID_InputMode2_001B29D4(void *arg1, void *arg2, void *arg3,
                                    void *arg4, int first, int second);
void HID_ReadRawInput_0016490C(const int16_t *record, void *arg1, void *arg2,
                               void *arg3, void *arg4)
{
    switch (*(const uint8_t *)((const uint8_t *)record + 0x0c)) {
    case 0:
        HID_InputMode0_001B28F0(arg1, arg2, arg3, arg4, record[0], record[3]);
        break;
    case 1:
        HID_InputMode1_001B27EC(arg1, arg2, arg3, arg4, record[1], record[4]);
        break;
    case 2:
        HID_InputMode2_001B29D4(arg1, arg2, arg3, arg4, record[2], record[5]);
        break;
    default:
        break;
    }
}
