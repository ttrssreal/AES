#pragma once

#include "keySchedule.h"

class AES {
public:
    unsigned char state[16];
    unsigned char* encrypt(unsigned char plaintext[], unsigned char cipherKey[]);

private:
    unsigned char* encryptBlock(unsigned char block[16], unsigned char cipherKey[16]);
};