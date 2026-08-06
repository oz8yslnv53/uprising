typedef struct Engine_Float6_0034A364 {
    float values[6];
} Engine_Float6_0034A364;
__attribute__((noinline)) void Engine_CopyFloat6Offset8To20_0034A364(unsigned char *object)
{
    *(Engine_Float6_0034A364 *)(object + 0x20) =
        *(const Engine_Float6_0034A364 *)(object + 8);
}
