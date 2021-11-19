#pragma once
#include "aes.h"

class keySchedule
{
public:
    keySchedule(byte key[]);
    ~keySchedule();

    byte*** generateKeySchedule(int numKeys);
    byte* g(byte* in, int round);

private:
    byte** m_key;
    byte*** m_keySchedule;
};
