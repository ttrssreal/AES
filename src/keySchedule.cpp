#include "aes.h"
#include "keySchedule.h"
#include "util.h"

keySchedule::keySchedule(byte key[]) {
    m_key = batb(key, 4);
}

keySchedule::~keySchedule() {
    deAllocateKeySchedule(m_keySchedule, 10);
}

/* g encapsulates some of the logic detailed in page 19 of 
https://csrc.nist.gov/csrc/media/publications/fips/197/final/documents/fips-197.pdf */
byte* keySchedule::g(byte* in, int round) {
    byte* result = new byte[4];
    // copy the word
    for (int i = 0; i < 4; i++)
    {
        result[i] = in[i];
    }
    rotWord(result);
    subBytes(result);
    doRcon(result, round);
    return result;
}

byte*** keySchedule::generateKeySchedule(int numKeys) {
    m_keySchedule = allocateKeySchedule(numKeys);
    // the first round key is always the original key
    m_keySchedule[0] = m_key;
    // for each key we need to generate
    for (int i = 1; i <= 10; i++)
    {
        byte* gOfPrevLast = g(m_keySchedule[i-1][3], i);
        // set the initial word of the new key
        m_keySchedule[i][0] = xorWords(gOfPrevLast, m_keySchedule[i-1][0]);

        // used temporarily
        byte* prevWord = new byte[4];
        // j starts at 1 becaue above we have already set the first value
        for (int j = 1; j < 4; j++)
        {
            // copy the word of the previous at the same position
            /*
                for example 
                 pos: 2     pos: 2
                    ------------
                    ↓          ↓
                0 0 3 0    0 0 0 0
                0 0 4 0    0 0 0 0
                0 0 2 0    0 0 0 0
                0 0 4 0    0 0 0 0
            */
            for (int k = 0; k < 4; k++)
            {
                prevWord[k] = m_keySchedule[i-1][j][k];
            }

            // xor that with the previous word is the current key
            byte* xoredvalues = xorWords(prevWord, m_keySchedule[i][j-1]);
            // set that as the current word then move on to the next one
            m_keySchedule[i][j] = xoredvalues;
        }
        // trying to avoid memory leaks :)
        delete[] prevWord;
    }
    return m_keySchedule;
}