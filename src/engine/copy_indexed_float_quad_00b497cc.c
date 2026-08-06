typedef struct Engine_FloatQuad_00B497CC {
    float values[4];
} Engine_FloatQuad_00B497CC;
__attribute__((noinline)) void Engine_CopyIndexedFloatQuad_00B497CC(
    float *destination, const unsigned char *base, unsigned int index)
{
    const Engine_FloatQuad_00B497CC *source =
        (const Engine_FloatQuad_00B497CC *)(base + index * 0x30u + 0x150u);
    *(Engine_FloatQuad_00B497CC *)destination = *source;
}
