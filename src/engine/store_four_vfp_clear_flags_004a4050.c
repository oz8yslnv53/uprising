__attribute__((noinline)) void Engine_StoreFourVfpClearFlags_004A4050(void *record,
                                             float value0,
                                             float value1,
                                             float value2,
                                             float value3)
{
    float *values = (float *)record + 0x54 / sizeof(float);
    values[0] = value0;
    values[1] = value1;
    values[2] = value2;
    values[3] = value3;
    *(unsigned int *)((char *)record + 0x6c) &= ~0x5cu;
}
